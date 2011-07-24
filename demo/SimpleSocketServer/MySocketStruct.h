/*
 *  MySockStruct.h
 *  SimpleSocketServer
 *
 *  Created by fuqifacai on 7/19/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

struct FSocketStruct
{
	int socketHandle;
	
	int port;
	
	char clientID[255];
};