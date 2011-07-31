//
//  Test1.m
//  TestCocoaCenter
//
//  Created by fuqifacai on 7/26/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "Test1.h"
#import "MyCocoaObject.h"
#import	"FDataStruct.h"
#import <objc/objc-runtime.h>

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
	//Declare oc object
	MyCocoaObject* myData=[[MyCocoaObject alloc]init];
	NSLog(@"Enter\r\n");
	
	if(nil==myData)
	{
		assert(FALSE);
	}
    //Check is that type (like is/as in C#)
	if([myData isKindOfClass:[MyCocoaObject class]])
	{
		NSLog(@"yes it's my kind class\r\n");
	}
	
	[myData TestHowToUseCollectionObjects:3];
	
	@try {
		NSLog(@"A is %d",myData->a);
	}
	@catch (NSException * e) {
		NSLog(@"Detail Error is : %s",e.description);
	}
	@finally {
		
	}
	
	
	
	
	[myData release];
	
	//Declare native C++ object
//	FDataStruct* myNativeObject =new FDataStruct();
//	int a= myNativeObject.TestMethod();
//	assert(a==100);
}

-(IBAction)TestStaticLibrary:(id)sender
{
	MyCocoaObject* myData=[[MyCocoaObject alloc]init];
	
	[myData TestStaticLibraryMethods];
	
	[myData release];
}

-(IBAction)TestSEH:(id)sender
{
	int a=100;
	@try {
		a=300;
	}
	@catch (NSException * e)//NSException* is the super class of exception .so this like(catch(...))
	{
		NSLog(@"catched");
	}
	@finally {	
		a=20;
	}
	
}
@end
