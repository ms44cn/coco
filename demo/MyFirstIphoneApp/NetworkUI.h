//
//  NetworkUI.h
//  MyFirstIphoneApp
//
//  Created by fuqifacai on 8/1/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TcpEngine.h"
#import "Common.h"
	
@interface NetworkUI : NSObject {
	
	IBOutlet UITextField* txtServer;
	IBOutlet	UIButton* butConnect;
	IBOutlet UITextField* txtPort;
	
	CTcpEngine* engine;
	Common* myCommon;
	
}

-(IBAction)ConnectToHost:(id)sender;

-(IBAction)TestClick:(id)sender;

@end
