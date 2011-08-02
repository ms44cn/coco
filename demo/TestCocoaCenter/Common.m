//
//  Common.m
//  TestCocoaCenter
//
//  Created by fuqifacai on 7/29/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

//#define MAC_OS 

#import "Common.h"
#define MAX_PATH 4096

@implementation Common

-(NSString*)GetNStringFromChar:(const char*) src
{

	NSString *ret = [NSString stringWithUTF8String:src];
	[ret autorelease];
	
	return ret;
}

-(void)MessageBox:(NSString*) text
{
#if defined MAC_OS
	
	NSAlert *alert = [[[NSAlert alloc] init] autorelease];
	[alert setMessageText:text];
	
#else
#endif
}

-(void)dealloc
{
	[super dealloc];
	
}


-(const char*)GetCharArrary:(NSString*)src
{
	const char* temp=[src UTF8String];
	//return const_cast<char*>(temp);
	return temp;
}
//
//-（void)QuietLog(NSString* data,...)
//{
//	va_list	argList;
//	va_start (argList,data);
//	NSString* msg=[[[NSString alloc	]initWithFormat:data
//										  arguments:argList autorelease];
//				   
//				   printf("%s",[msg UTF8String);
//								va_end(argList);
//}


@end
