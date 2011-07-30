#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "TcpEngine.h"

using namespace std;

int main (int argc, char * const argv[])
{

	char remoteServer[50];
	int port;
		
	bool isJustSendingMode=false;
	
	
Start:
    // enter the ip and port
    cout << "Please input the remote server address : ";
	cin>>remoteServer;
	
	cout <<"Please input the port : ";
	cin >> port;

	CTcpEngine myEngine;
	int maxBufferLength=myEngine.GetSendMaxLength();
	char* myData=new char[maxBufferLength];
	
	SOCKET mySocket=myEngine.ConnectToHost(remoteServer, port);
	if(SOCKET_ERROR==mySocket)
	{
		cout <<"Create socket error"<<endl;
		goto Start;
	}
	
	printf("Create Socket %d (Port:%d) \r\n",mySocket,port);;
	//cycle to sending data
	while (true)
	{
		memset(myData, 0, maxBufferLength);
		
		cout << "Sending :";
		cin>>myData;
		
		if(isJustSendingMode)
		{		
			
			bool sendStatus=myEngine.Send(mySocket,myData,maxBufferLength);
	    if(sendStatus)
		{
			cout<<"Sent successful"<<endl;
		}
		else
		{
			cout << "Sent failure"<<endl;
			goto Start;
		}

		}
		else {
			char* backData=myEngine.SendAndReceive(mySocket, myData, maxBufferLength);
			if(NULL!=backData)
			{
				cout<<"Sent successful and received :  "<<backData<<endl;
				
			}
			else
			{
				cout << "Sent failure"<<endl;
				goto Start;
			}

		}


	}
	
	
	myEngine.Close(mySocket);
	
	delete[] myData;
	cout << "Completed"<<endl;

	
    return 0;
}
