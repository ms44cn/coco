#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "MySocketStruct.h"


using namespace std;


int m_maxBufferLength=4096;

void* DoDetail(void*  param)
{
	FSocketStruct* myDetailData=(FSocketStruct*) param;
	
	int receivedLength;
	char* tempBuffer=new char[m_maxBufferLength];
	
	while(true)
	{
		//memset(tempBuffer, 0, sizeof(tempBuffer));
		
		receivedLength = recv(myDetailData->socketHandle,tempBuffer,m_maxBufferLength,0);
		if(receivedLength<1)
		{
			cout <<"Error data received"<<endl;
			break;
		}
		
		tempBuffer[receivedLength]='\0';
		cout <<"Received : "<<tempBuffer << " . Length is "<<receivedLength<<endl;
		
	}
}

int main (int argc, char * const argv[]) {
    

	int mySocket;
	struct sockaddr_in localAddress;
	int m_port=2345;
	
	
	mySocket=socket(AF_INET, SOCK_STREAM, 0);
	if(-1==mySocket)
	{
		cout << "Create socket error"<<endl;
		return -1;
	}
	
	char* remoteServer="127.0.0.1";
	
	localAddress.sin_port=htons(m_port);
	localAddress.sin_family=AF_INET;
	//localAddress.sin_addr.s_addr=htonl(0x00000000);
	inet_pton(AF_INET,remoteServer,&localAddress.sin_addr);
	
	if(-1 == bind(mySocket, (struct sockaddr*)&localAddress, sizeof(localAddress)))
	{
		cout<<"bind error"<<endl;
		return -1;
	}
	cout<<"Bind ok"<<endl;
	
	listen(mySocket,SOMAXCONN);
	
	cout << "Start to listening on Server :"<<remoteServer<<" Port : "<<m_port<<endl;
	
	int addressSize=sizeof(struct sockaddr_in);
	int sendSocket;
	while(true)
	{
		sendSocket=accept(mySocket, (struct sockaddr*)&localAddress, (socklen_t*)&addressSize);
		if(-1==sendSocket)
		{
			cout << "Accept new socket error" <<endl;
			
			continue;
		}
		cout<<"Accepted OK"<<endl;
		
		FSocketStruct mySendingData;
		mySendingData.socketHandle=sendSocket;
		mySendingData.port=m_port;
		
		pthread_t ntid;
		int ret=pthread_create(&ntid, NULL,DoDetail, &mySendingData);
		if(-1 == ret)
		{
			cout <<"Create thread to listening error occurred"<<endl;
		}
		
			
	}
	
    return 0;
}