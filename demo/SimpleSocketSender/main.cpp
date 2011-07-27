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
	int MyDataBufferLength=4096;
	char remoteServer[50];
	int port;
		
	char* myData=new char[MyDataBufferLength];
	
	
Start:
    // enter the ip and port
    cout << "Please input the remote server address : ";
	cin>>remoteServer;
	
	cout <<"Please input the port : ";
	cin >> port;

	CTcpEngine myEngine;
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
		memset(myData, 0, MyDataBufferLength);
		
		cout << "Sending :";
		cin>>myData;
		
		bool sendStatus=myEngine.Send(mySocket,myData,MyDataBufferLength);
	    if(sendStatus)
		{
			cout<<"Sent successful"<<endl;
		}
		else {
			cout << "Sent failure"<<endl;
		}
		if(sendStatus==false)
		{
			goto Start;
		}
	}
	
	
	myEngine.Close(mySocket);
	
	delete[] myData;
	cout << "Completed"<<endl;
	/*
	mySocket=socket(AF_INET,SOCK_STREAM,0);
	if(-1==mySocket)
	{
		cout <<" Create socket error"<<endl;
		return -1;
	}
	struct sockaddr_in myAddress;
	myAddress.sin_family=AF_INET;
	
	myAddress.sin_port=htons(port);
	//Convert ip address from string to IPv4/v6 binary format
	inet_pton(AF_INET,remoteServer,&myAddress.sin_addr);
	
	//connect
	int connectStatus=0;
	connectStatus =connect(mySocket,(struct sockaddr*)&myAddress, sizeof(myAddress)); 
	if( -1 == connectStatus)
	{
		cout<<"connect error"<<endl;
		return -1;
		goto Start;
	}
	
	
	while (true)
	{
		memset(myData, 0, sizeof(myData));
		
		cout << "Sending :"<<endl;
		cin>>myData;
		
		int sendDataCount=send(mySocket,myData,sizeof(myData),0);
		cout << "Sent "<<sendDataCount<<endl;
	}
	
	
	close(mySocket);
	delete[] myData;
	cout << "Completed"<<endl;
*/
	
    return 0;
}
