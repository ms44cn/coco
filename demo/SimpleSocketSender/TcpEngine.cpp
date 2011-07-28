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
}


CTcpEngine::~CTcpEngine(void)
{
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
	if (SOCKET_ERROR == send(mySocket, sendingBuffer, length, 0))
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
