//
//  NetworkUI.m
//  MyFirstIphoneApp
//
//  Created by fuqifacai on 8/1/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "NetworkUI.h"


@implementation NetworkUI

-(id)init
{
	[super init];
	engine=new CTcpEngine();
	myCommon =[[Common alloc]init];
    
	return self;
}


-(void)dealloc
{
	if(myCommon!=nil)
	{
		[myCommon release];		
	}
    
	if(engine!=NULL)
	{
		delete engine;
	}
	[super dealloc];
}

-(IBAction)TestClick:(id)sender
{
    NSLog(@"Test click received");
}

-(IBAction)ConnectToHost:(id)sender
{
	NSString* server=txtServer.text;
    int port=[txtPort.text intValue];
	const char* temp=[myCommon GetCharArrary:server];
	
	//int port=
	char myServer[50];
	strcpy(myServer,temp);
	
	SOCKET socket=engine->ConnectToHost(myServer, port);
	if(SOCKET_ERROR ==socket)
	{
		NSLog(@"Create connection error");
		return;
	}
}
@end
