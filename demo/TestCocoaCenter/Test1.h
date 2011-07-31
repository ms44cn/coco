//
//  Test1.h
//  TestCocoaCenter
//
//  Created by fuqifacai on 7/26/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface Test1 : NSObject 
{
	IBOutlet NSTextField	*myTextField;
	id myRuntimeVar; //dynamic object
	
}

-(IBAction)TestStaticLibrary:(id)sender;
- (IBAction) ShowInt:(id)sender;
- (IBAction) ShowString:(id)sender;
- (IBAction) ShowMessageBox:(id)sender;
-(IBAction)TestSEH:(id)sender;
@end
