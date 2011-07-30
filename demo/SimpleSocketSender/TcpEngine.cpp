#include "TcpEngine.h"
#include <stdio.h>   
#include <stdlib.h>   
#include <string.h>

#if defined WindowPlatform
#include "StdAfx.h"
#include <winsock.h>
#include <windows.h>
#else
	#if defined MacOSPlatform
	#include <unistd.h>
	#include <netinet/in.h>
	#include <arpa/inet.h>
	#include <netdb.h>
	#else
	#endif
#endif

#include <iostream>
#include <iomanip>
#include <assert.h>

using namespace std;
#pragma comment (lib,"ws2_32.lib")

CTcpEngine::CTcpEngine(void)
{
	m_SendContentMaxLength=4096;
	m_ReceiveContentMaxLength=4096;
}


CTcpEngine::~CTcpEngine(void)
{
}

char* CTcpEngine::GetLocalIpAddress()
{
	char* myIpAddress=NULL;
	char name[32]="";
	
	#if defined WindowPlatform
	PHOSTENT hostInfo;
	
	if(gethostname (name, sizeof(name)) == 0)
	{ 
		if((hostInfo = gethostbyname(name)) != NULL) 
		{ 
			myIpAddress = inet_ntoa (*(struct in_addr *)*hostInfo->h_addr_list);
		}
	}
	#else
	hostent* hostInfo;
	if(gethostname (name, sizeof(name)) == 0)
	{ 
		hostInfo = gethostbyname(name);
		if(NULL!=hostInfo) 
		{ 
			myIpAddress = inet_ntoa (*(struct in_addr *)*hostInfo->h_addr_list);
		}
	}
	#endif
	
	return myIpAddress;
}


//Return a valid SOCKET handle, if failed return a SOCKET_ERROR (-1)
SOCKET CTcpEngine::ConnectToHost(char ipAddress[], int port)
{
#ifdef WindowPlatform
	WSADATA wsd; 
	if (WSAStartup(MAKEWORD(2,2), &wsd) != 0)
	{
		printf("WSAStartup failed!\r\n");
	}
#endif

	SOCKET mySocket = socket(AF_INET, SOCK_STREAM, 0);
	if(INVALID_SOCKET == mySocket)
	{
		cout << "socket failed!" << endl;
		
		#ifdef WindowPlatform
		WSACleanup();
		#endif
		return SOCKET_ERROR;
	}


	struct sockaddr_in servAddr; 
	
	servAddr.sin_family =AF_INET;
	inet_pton(AF_INET,ipAddress,&servAddr.sin_addr);
	servAddr.sin_port = htons((short)port);
	int serverAddressSize  = sizeof(servAddr);
	if(SOCKET_ERROR == connect(mySocket,(struct sockaddr*)&servAddr, serverAddressSize))
	{

		cout << "connect failed!" << endl;		
		#ifdef WindowPlatform
		WSACleanup();
		#endif
		return SOCKET_ERROR;
	}
	printf("Start connect to %s on port %d \r\n" ,ipAddress,port);

	return mySocket;
}

bool CTcpEngine::Send(SOCKET mySocket,char* sendingBuffer,int length)
{
	int ret=send(mySocket, sendingBuffer, length, 0);
	if (SOCKET_ERROR == ret)
	{
		#if defined WindowPlatform
		int errorCode=WSAGetLastError(); 
		cout << "sent failure .Error code : "<< errorCode << endl;
		#else
		cout <<"sent failure"<<endl;
		#endif
		
		return false;
	}

	return true;
}

char* CTcpEngine::SendAndReceive(SOCKET mySocket,char* data ,int length )
{
	char* receivedData=NULL;
	
	receivedData=new char[m_ReceiveContentMaxLength];
	memset(receivedData,0,m_ReceiveContentMaxLength);
	
	if(Send(mySocket,data,length))
	{
		int receivedLength=recv(mySocket,receivedData,m_ReceiveContentMaxLength,0);
		//printf("received length %d \r\n",receivedLength);
	}
	
	
	return receivedData;
}

char* CTcpEngine::GetHostNameFromAddress(const char* ipAddress)
{
	struct in_addr ip;
	struct hostent *hp;
	
	if (!inet_aton(ipAddress, &ip))
	{
		//errx(1, "can't parse IP address %s", ipAddress);
	}
	
	if ((hp = gethostbyaddr((const void *)&ip,
							sizeof ip, AF_INET)) == NULL)
	{
		//errx(1, "no name associated with %s", ipstr);
	}
	
	return  hp->h_name;
}

void CTcpEngine::SetSendMaxLength(int length)
{
	m_SendContentMaxLength=length;
}


void CTcpEngine::SetReceiveMaxLength(int length)
{
	m_ReceiveContentMaxLength=length;
}

int CTcpEngine::GetSendMaxLength()
{
	return m_SendContentMaxLength;
}


int CTcpEngine::GetReceiveMaxLength()
{
	return m_ReceiveContentMaxLength;
}


///Close socket connection
void CTcpEngine::Close(SOCKET socket)
{
	

#if defined WindowPlatform
	WSACleanup();
	closesocket(socket);
#else
	
	#if defined	MacOSPlatform
	close(socket);
	#else 
	close(socket);
	#endif
#endif
}
