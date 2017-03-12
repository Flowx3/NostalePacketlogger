//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#include <process.h>
#include "C:\SDK_GEN\SDK\network.hpp"
#pragma hdrstop
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	 Nostale::Network::SendPacket(Edit2->Text);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{
	 Nostale::Network::RecvPacket(Edit3->Text);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::AddClick(TObject *Sender)
{
	 ListBox1->Items->Add(Edit1->Text);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button5Click(TObject *Sender)
{
	 ListBox2->Items->Add(Edit4->Text);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button6Click(TObject *Sender)
{
	 ListBox2->DeleteSelected();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::RemoveClick(TObject *Sender)
{
	 ListBox1->DeleteSelected();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button3Click(TObject *Sender)
{
	 Memo1->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button4Click(TObject *Sender)
{
	std::string packet = ("n_run 16 0 1 " + userid);
	AnsiString SendPacket = AnsiString(packet.c_str());
	Nostale::Network::SendPacket(SendPacket);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button7Click(TObject *Sender)
{
	std::string packet = ("n_run 16 1 1 " + userid);
	AnsiString SendPacket = AnsiString(packet.c_str());
	Nostale::Network::SendPacket(SendPacket);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button8Click(TObject *Sender)
{
	std::string packet = ("n_run 16 2 1 " + userid);
	AnsiString SendPacket = AnsiString(packet.c_str());
	Nostale::Network::SendPacket(SendPacket);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button9Click(TObject *Sender)
{
	std::string packet = ("n_run 5005 1 1 " + userid);
	AnsiString SendPacket = AnsiString(packet.c_str());
	Nostale::Network::SendPacket(SendPacket);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button10Click(TObject *Sender)
{
	std::string packet = ("n_run 26 1 1 " + userid);
	AnsiString SendPacket = AnsiString(packet.c_str());
	Nostale::Network::SendPacket(SendPacket);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button11Click(TObject *Sender)
{

	std::string packet = ("info You are Higher as Level 1! Your Level is " + lev);
	AnsiString RecvPacket = AnsiString(packet.c_str());
	std::string packet2 = "script 1 5";
	AnsiString SendPacket = AnsiString(packet2.c_str());
	if(lev == "1")
	{
		Nostale::Network::SendPacket(SendPacket);

	}
	else
	{
		Nostale::Network::RecvPacket(RecvPacket);
	}

}
//---------------------------------------------------------------------------


void __fastcall TForm2::Button12Click(TObject *Sender)
{
	Nostale::Network::RecvPacket("wopen 32 0 0");
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button13Click(TObject *Sender)
{
	Nostale::Network::SendPacket("script 1 201");
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button14Click(TObject *Sender)
{
	Nostale::Network::SendPacket("script 1 202");
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button15Click(TObject *Sender)
{
	Nostale::Network::SendPacket("script 1 203");
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button16Click(TObject *Sender)
{
	Nostale::Network::SendPacket("script 1 204");
}
//---------------------------------------------------------------------------

