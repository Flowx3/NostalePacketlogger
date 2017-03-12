#ifndef NT_NETWORK_HPP
#define NT_NETWORK_HPP

#define NT_NETWORK_PTR 0x005F7764
#define NT_NETWORK_SEND_FUNCTION 0x00592918
#define NT_NETWORK_RECV_FUNCTION 0x00591B44

namespace Packet
{
	void SendPacket(char* szPacket)
	{
		DWORD dwSendFunction
			= NT_NETWORK_SEND_FUNCTION;

		__asm
		{
			MOV EAX,DWORD PTR DS:[NT_NETWORK_PTR]
			MOV EAX,DWORD PTR DS:[EAX]
			MOV EDX, szPacket
			CALL dwSendFunction
		}
	}

	void RecvPacket(char* szPacket)
	{
		DWORD dwRecvFunction
			= NT_NETWORK_RECV_FUNCTION;

		__asm
		{
			MOV EAX,DWORD PTR DS:[NT_NETWORK_PTR]
			MOV EAX,DWORD PTR DS:[EAX]
			MOV EAX,DWORD PTR DS:[EAX + 0x34]
			MOV EDX, szPacket
			CALL dwRecvFunction
		}
	}
}

#endif // NT_NETWORK_HPP

