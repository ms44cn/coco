//
//  Foo.m
//  Helloworld
//
//  Created by fuqifacai on 7/25/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "Foo.h"
#include "TestCClass.h"

@implementation Foo

-(IBAction)ShowHelloWorld:(id)sender
{
	//[alert show:@"Hello world"] ;
	
	TestCClass	*myTestClass = [[TestCClass alloc] init];
	
	
	[myTestClass release];
}


- (IBAction)generate:(id)sender
{
    // Generate a number between 1 and 100 inclusive
    int  generated = (random() % 100) + 1;
	
    NSLog(@"generated = %d", generated);
	
    // Ask the text field to change what it is displaying
    [myTextField setIntValue:generated];
}

- (IBAction)seed:(id)sender
{
    // Seed the random number generator with the time
    srandom(time(NULL));
    [myTextField setStringValue:@"Generator seeded"];
}
@end
