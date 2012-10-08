//////////////////////////////////////////////////////////
// initsock.h�ļ�

#include <winsock2.h>		//����ͷ�ļ�
#pragma comment(lib, "WS2_32")	// ��ӿ�WS2_32.lib

class CInitSock		
{
public:
	CInitSock(BYTE minorVer = 2, BYTE majorVer = 2)
	{
		// ��ʼ��WS2_32.dll
		WSADATA wsaData;
		WORD sockVersion = MAKEWORD(minorVer, majorVer);
		if(::WSAStartup(sockVersion, &wsaData) != 0)	//����Winsock_DLL��,���óɹ�����0
		{
			exit(0);
		}
	}
	~CInitSock()
	{	
		::WSACleanup();		//�ͷ�Winsock��
	}
};

// int
// WSAAPI
// WSAStartup(		//����Winsock_DLL��
// 		   WORD wVersionRequested,
// 		   LPWSADATA lpWSAData
//     );