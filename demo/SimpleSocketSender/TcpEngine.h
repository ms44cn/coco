#pragma once
//#define WindowPlatform
#define MacOSPlatform

#ifdef WindowPlatform
#include <winsock.h>
#endif

#ifdef MacOSPlatform
#include <sys/socket.h>
typedef unsigned int SOCKET;
#define INVALID_SOCKET (SOCKET)(~0)
#define SOCKET_ERROR (-1)
#endif

class CTcpEngine
{
public:
	CTcpEngine(void);
	~CTcpEngine(void);

	void SetMaxBufferLength(int length);
	SOCKET ConnectToHost(char ipAddress[], int port);
	bool Send(SOCKET mySocket,char* sendingBuffer,int length);
	void Close(SOCKET socket);

private :
	int m_SendContentMaxLength;
};

