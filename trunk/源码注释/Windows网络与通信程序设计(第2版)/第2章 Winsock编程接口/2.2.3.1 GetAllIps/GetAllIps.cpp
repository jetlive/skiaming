//////////////////////////////////////////////////
// GetAllIps.cpp�ļ�


#include "../common/InitSock.h"


#include <stdio.h>
CInitSock initSock;		// ��ʼ��Winsock��

void main()
{
	char szHost[256];	
	::gethostname(szHost, 256);// ȡ�ñ�����������	
	hostent *pHost = ::gethostbyname(szHost);// ͨ���������õ���ַ��Ϣ
	// ��ӡ������IP��ַ
	in_addr addr;	//�洢IP��ַ
	for(int i = 0; ; i++)
	{
		char *p = pHost->h_addr_list[i];
		if(p == NULL)
			break;

		memcpy(&addr.S_un.S_addr, p, pHost->h_length);
		char *szIp = ::inet_ntoa(addr);	//�������ֽڵ�32λIP��ַת��Ϊ�ַ���
		printf(" ����IP��ַ��%s  \n ", szIp);
	}
}