//
//  Test1.m
//  TestCocoaCenter
//
//  Created by fuqifacai on 7/26/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "Test1.h"


@implementation Test1
- (IBAction) ShowInt:(id)sender
{
	int generated;
    generated = (random() % 100) + 1;
	
    NSLog(@"generated = %d", generated);
	
    // Ask the text field to change what it is displaying
    [myTextField setIntValue:generated];
}

- (IBAction) ShowString:(id)sender
{
	[myTextField setStringValue:@"Hello world"];
}

- (IBAction) ShowMessageBox:(id)sender
{
	
}

@end
