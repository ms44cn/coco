//
//  SimpleUI.h
//  NetworkUtility
//
//  Created by fuqifacai on 7/31/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "TcpEngine.h"
#import "Common.h"

@interface SimpleUI : NSObject {
	IBOutlet	NSTextField* txtServer;
	IBOutlet NSTextField* txtPort;
	IBOutlet NSTextField* txtSendDataContent;
	IBOutlet NSButton* butSendData;
	
	bool isConnected;
	CTcpEngine* engine;
	Common* myCommon;
}

-(IBAction)butConnectToHost:(id)sender;
-(IBAction)butSendData:(id)sender;
@end
