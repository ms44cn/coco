//
//  SimpleUI.m
//  NetworkUtility
//
//  Created by fuqifacai on 7/31/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "SimpleUI.h"


@implementation SimpleUI

- (id)init
{
    self = [super init];
	isConnected=false;
	[butSendData setEnabled:false];
	
	engine=new CTcpEngine();
	
	myCommon=[[Common alloc]init];
	return self;

}

-(IBAction)butConnectToHost:(id)sender
{
	NSString* server=[txtServer stringValue];

	char* temp=[myCommon GetCharArrary:server];
	char myServer[50];
	strcpy(myServer,temp);
	myServer[strlen(temp)]='\0';
	
	int myPort =[txtPort intValue];
	
	SOCKET socketHandle = engine->ConnectToHost(myServer,myPort);
	if(SOCKET_ERROR==socketHandle)
	{
		[myCommon MessageBox:@"Create Connection Error"];
		NSLog(@"Create connection error");
		return;
	}
	
	isConnected=true;
	[butSendData setEnabled:isConnected];
}

-(IBAction)butSendData:(id)sender
{
	if((!isConnected)||(NULL==engine))
	{
		//please connect first.
		return;
	}
	NSString* data=[txtSendDataContent stringValue];
	
	char* temp=[myCommon GetCharArrary:data];
	
	bool ret= engine->Send(engine->GetLastSOCKET(), temp, strlen(temp));
	
	if(ret)
	{
		NSLog(@"Sent ok");
	}
	else
	{
		NSLog(@"Sent failure");
	}

		
}
@end
