#include <vcl.h>
#include <windows.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include <shellapi.h>
#include "Unit2.h"

#pragma hdrstop
#pragma argsused

#include "C:\SDK_GEN\SDK\network.hpp"
#define NT_NETWORK_PTR 0x00696304
#define NT_NETWORK_SEND_FUNCTION 0x005187F0
#define NT_NETWORK_RECV_FUNCTION 0x00508E00
#define RECV 1
#define SEND 2
TForm2 *DllForm;
std::vector<std::string> Split(const std::string str, char delim) {
 std::vector<std::string> tmp;
 std::stringstream ss(str);
 std::string item;
 while (std::getline(ss, item, delim)) { tmp.push_back(item); }
 return tmp;
}
//---------------------------------------------------------------------------
void got_Packet(char* packet,int art)
{
   std::vector<std::string> vPacket = Split(packet, ' ');
   UnicodeString check = AnsiString(vPacket[0].c_str() );
   UnicodeString CheckID = AnsiString(vPacket[1].c_str());
   switch(art)
   {
	   case RECV:
	   {
			if(vPacket[0] == "c_info")
			{
				std::string userid = vPacket[6];
				DllForm->userid = userid;
				std::string label = "UserID: ";
				label += userid;
				DllForm->Label3->Caption = AnsiString(label.c_str());
			}
			if(vPacket[0] == "lev")
			{
				DllForm->lev = vPacket[1];
			}
			if(DllForm->CheckBox2->Checked && (DllForm->ListBox2->Items->IndexOf(check) < 0))
			{
				std::string AS = "[Recv Packet] ";
				AS += packet;
				UnicodeString US = AnsiString(AS.c_str());
				DllForm->Memo1->Lines->Add(US);
				break;
			}
			break;
	   }
	   case SEND:
	   {
            if(vPacket[0] == "game_start")
			{
                Nostale::Network::RecvPacket("say 0 0 12 Packetlogger by Flow");
            }
			if(DllForm->CheckBox1->Checked && (DllForm->ListBox1->Items->IndexOf(check) < 0))
			{
				std::string AS = "[Send Packet] ";
				AS += packet;
				UnicodeString US = AnsiString(AS.c_str());
				DllForm->Memo1->Lines->Add(US);
				break;
			}
			break;
	   }
   }

}
//---------------------------------------------------------------------------
void hkSend()
{
	char* packet;
	_asm
	{
		pushad
		pushfd
		MOV packet, EDX
	}
	got_Packet(packet,SEND);
	 _asm
	{
		popfd
		popad
	}
}
//---------------------------------------------------------------------------
void HookedRecv()
{
	char* packet;
	__asm
	{
		pushad
		pushfd
		MOV packet,edx
	}
	got_Packet(packet,RECV);
	 _asm
	{
		popfd
		popad
	}
}
//---------------------------------------------------------------------------
bool DetourFunc(BYTE *oldFunc, BYTE *newFunc, DWORD len)
{
	BYTE* newMem4base = NULL;
	DWORD dwOld;

	newMem4base = ( BYTE* )malloc( 5+len );

	if( newMem4base == NULL )
		return false;

	for( DWORD i = 0; i < ( len+5 ); i++ )
		newMem4base[i] = 0x90;

	VirtualProtect( oldFunc, len, PAGE_READWRITE, &dwOld );

	memcpy( newMem4base, oldFunc, len );
	oldFunc[0] = 0xE8;
	*( DWORD* )( oldFunc+0x01 ) = DWORD( newFunc-oldFunc-5 );
	oldFunc[5] = 0xE9;
	*( DWORD* )( oldFunc+0x06 ) = DWORD( newMem4base-( oldFunc+0x5 )-5 );
	newMem4base += len;
	newMem4base[0] = 0xE9;
	*( DWORD* )( newMem4base+0x01 ) = DWORD( ( oldFunc+10 )-newMem4base-5 );

	for( DWORD i = 10; i <len; i++ )
		oldFunc[i] = 0x90;

	return true;
}
//---------------------------------------------------------------------------
DWORD WINAPI ShowForm(LPVOID param)
{
	ShowMessage("Injected");
	ShellExecute(NULL,
	 "open",
	  "http://www.elitepvpers.com/forum/nostale/4065765-release-nostale-packetlogger.html",
	NULL,
	NULL,
	SW_SHOW);
	DWORD dRecv = NT_NETWORK_RECV_FUNCTION;
	DWORD dSend = NT_NETWORK_SEND_FUNCTION;
	DetourFunc((BYTE*)dSend, (BYTE*)&hkSend, 6);
	DetourFunc((BYTE*)dRecv, ( BYTE*)&HookedRecv, 14);
	DllForm = new TForm2(NULL);
	DllForm->Memo1->Clear();
	DllForm->ShowModal();
	return 0x0;
}
//---------------------------------------------------------------------------
int WINAPI DllMain(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
	switch(reason)
	{
	case 1:
		 DisableThreadLibraryCalls(hinst);
		 CreateThread(NULL, 0, ShowForm, NULL, 0, NULL);

		 break;
	}
	return 1;
}
