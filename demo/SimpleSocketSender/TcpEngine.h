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

	void SetMaxBufferLength(int length);
	SOCKET ConnectToHost(char ipAddress[], int port);
	bool Send(SOCKET mySocket,char* sendingBuffer,int length);
	void Close(SOCKET socket);

private :
	int m_SendContentMaxLength;
};

