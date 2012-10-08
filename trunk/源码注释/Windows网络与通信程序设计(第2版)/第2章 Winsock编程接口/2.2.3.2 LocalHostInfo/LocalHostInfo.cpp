////////////////////////////////////////////////
// LocalHostInfo.cpp�ļ�

#include <windows.h>
#include <stdio.h>

#include "Iphlpapi.h"		//������IP���������Ķ���(�赥�����ػ��߸���SDK)
#pragma comment(lib, "Iphlpapi.lib")
#pragma comment(lib, "WS2_32.lib")

/////////////////////////////////////////
// ȫ������
u_char	g_ucLocalMac[6];	// ����MAC��ַ
DWORD	g_dwGatewayIP;		// ����IP��ַ
DWORD	g_dwLocalIP;		// ����IP��ַ
DWORD	g_dwMask;			// ��������

BOOL GetGlobalData()
{
	PIP_ADAPTER_INFO pAdapterInfo = NULL;
	ULONG ulLen = 0;

	// Ϊ�������ṹ�����ڴ�
	::GetAdaptersInfo(pAdapterInfo,&ulLen);		//��ȡ���ػ�������������Ϣ,���óɹ�����ERROR_SUCCESS
	pAdapterInfo = (PIP_ADAPTER_INFO)::GlobalAlloc(GPTR, ulLen);

	// ȡ�ñ����������ṹ��Ϣ
	if(::GetAdaptersInfo(pAdapterInfo,&ulLen) ==  ERROR_SUCCESS)
	{
		if(pAdapterInfo != NULL)
		{
			memcpy(g_ucLocalMac, pAdapterInfo->Address, 6);
			g_dwGatewayIP = ::inet_addr(pAdapterInfo->GatewayList.IpAddress.String);	//
			g_dwLocalIP = ::inet_addr(pAdapterInfo->IpAddressList.IpAddress.String);
			g_dwMask = ::inet_addr(pAdapterInfo->IpAddressList.IpMask.String);
		}
	}

	printf(" \n -------------------- ����������Ϣ -----------------------\n\n");
	in_addr in;
	in.S_un.S_addr = g_dwLocalIP;
	printf("      IP Address : %s \n", ::inet_ntoa(in));	//inet_ntoa��32λ��������ת��Ϊ�ַ���

	in.S_un.S_addr = g_dwMask;
	printf("     Subnet Mask : %s \n", ::inet_ntoa(in));

	in.S_un.S_addr = g_dwGatewayIP;
	printf(" Default Gateway : %s \n", ::inet_ntoa(in));

	u_char *p = g_ucLocalMac;
	printf("     MAC Address : %02X-%02X-%02X-%02X-%02X-%02X \n", p[0], p[1], p[2], p[3], p[4], p[5]);

	printf(" \n \n ");

	return TRUE;
}

int main()
{
	// ��ȡȫ������
	GetGlobalData();

	getchar();		//����س���
	return 0;
}

// typedef struct _IP_ADAPTER_INFO {
//     struct _IP_ADAPTER_INFO* Next;
//     DWORD ComboIndex;
//     char AdapterName[MAX_ADAPTER_NAME_LENGTH + 4];
//     char Description[MAX_ADAPTER_DESCRIPTION_LENGTH + 4];
//     UINT AddressLength;
//     BYTE Address[MAX_ADAPTER_ADDRESS_LENGTH];
//     DWORD Index;
//     UINT Type;
//     UINT DhcpEnabled;
//     PIP_ADDR_STRING CurrentIpAddress;
//     IP_ADDR_STRING IpAddressList;
//     IP_ADDR_STRING GatewayList;
//     IP_ADDR_STRING DhcpServer;
//     BOOL HaveWins;
//     IP_ADDR_STRING PrimaryWinsServer;
//     IP_ADDR_STRING SecondaryWinsServer;
//     time_t LeaseObtained;
//     time_t LeaseExpires;
// } IP_ADAPTER_INFO, *PIP_ADAPTER_INFO;

// typedef struct _IP_ADDR_STRING {
//     struct _IP_ADDR_STRING* Next;
//     IP_ADDRESS_STRING IpAddress;
//     IP_MASK_STRING IpMask;
//     DWORD Context;
// } IP_ADDR_STRING, *PIP_ADDR_STRING;