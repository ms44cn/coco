//
//  MyCocoaObject.m
//  TestCocoaCenter
//
//  Created by fuqifacai on 7/27/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "MyCocoaObject.h"


@implementation MyCocoaObject

-(void)TestMethod1:(id)sender:(int)order
{
	
}


-(void)TestMethod1:(id)sender
{
		
}

-(int)TestHowToUseCollectionObjects:(int)order
{
	NSString* object1=@"1";
	NSString* object2=@"2";
	NSString* object3=@"3";
	
	NSArray* myArrayObject = [NSArray arrayWithObjects:object1, object2, object3, nil];
	NSEnumerator* myEnumator = [myArrayObject objectEnumerator];
	
	NSString* aString = @"foo";
	id anObject = nil;
	//traditional way
	while ((anObject = [myEnumator nextObject])) 
	{
		
		//[anObject doSomethingWithString:aString];
		NSLog("%@",anObject);
	}
	//like C#,the easiest way
	for(id item in myEnumator)
	{
		NSLog("Second time : %@",anObject);
	}
	return 3;
}


+(void)TestHowToUseString
{
	NSString* string = @"Hello world";
	
	NSString* notHandy = [[NSString alloc] initWithUTF8String:"helloWorld"];
	NSString* stillNotHandy = // initWithFormat 类似 sprintf()
	[[NSString alloc] initWithFormat:@"%s", "helloWorld"];
	
	
	int size = [@"hello" length];
	NSString* hello2 = [@"hello" uppercaseString];
	
	NSLog("%@",string);
	
}

-(void) f:(id)parameter // 等价于 C 函数 void f(id self, SEL _cmd, id parameter)
{
    id currentObject = self;
    SEL currentMethod = _cmd;
    [currentObject performSelector:currentMethod
                        withObject:parameter]; // 递归调用
	
    [self performSelector:_cmd withObject:parameter]; // 也是递归调用
}

@end
