#pragma once
//#define WindowPlatform
#define MacOSPlatform

#if defined WindowPlatform
#include <winsock.h>
#else
	#if defined MacOSPlatform
	#include <sys/socket.h>
	typedef unsigned int SOCKET;
	#define INVALID_SOCKET (SOCKET)(~0)
	#define SOCKET_ERROR (-1)
	#endif
#endif

class CTcpEngine
{
public:
	CTcpEngine(void);
	~CTcpEngine(void);

	void SetSendMaxLength(int length);
	void SetReceiveMaxLength(int length);
	
	int GetSendMaxLength();
	int GetReceiveMaxLength();	
	
	SOCKET ConnectToHost(char ipAddress[], int port);
	SOCKET GetLastSOCKET();
	bool IsConnected();
	//Just send data
	bool Send(SOCKET mySocket,char* sendingBuffer,int length);
	
	//Send data and received immediately
	char* SendAndReceive(SOCKET mySocket,char* data ,int length );
	
	//Get the host name from ip address
	char* GetHostNameFromAddress(const char* ipAddress);
	
	void Close(SOCKET socket);
	char* GetLocalIpAddress();

private :
	int m_SendContentMaxLength;
	int m_ReceiveContentMaxLength;
	SOCKET m_latestSOCKET;
};

