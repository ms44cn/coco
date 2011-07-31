//
//  MyCocoaObject.m
//  TestCocoaCenter
//
//  Created by fuqifacai on 7/27/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "MyCocoaObject.h"
#import "Common.h"

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
	NSLog(@"Test string is : %@",aString);
	id anObject = nil;
	
	//like C#,the easiest way
	for(id item in myEnumator)
	{
		NSLog(@"First time : %@",item);
	}
	
	//Another way to eunm the array
	//
	for ( int i=0;i<[myArrayObject count];i++)
	{
		//NSNumber *numberToPrint = [array objectAtIndex:i];
        NSLog(@"The value at index %d is %@", i, [myArrayObject objectAtIndex:i]);
	}
	//traditional way
	while ((anObject = [myEnumator nextObject])) 
	{
		
		//[anObject doSomethingWithString:aString];
		NSLog(@"Second is %@",anObject);
	}

	
	//Test mutableArray

	NSMutableArray* myMutableArray=[[NSMutableArray alloc]initWithCapacity:4];
	[myMutableArray addObject:@"3"];
	for(int j=0;j<[myMutableArray count];j++)
	{
		NSLog(@"Each value is %@" ,[myMutableArray objectAtIndex:j]);
	}
									//[myArrayObject addObject:@"4"]; //add object to array object
									//[myArrayObject insertObject:@"5" atIndex:5]; //insert object
	
	
	//Test bool
	bool ba=false;
	bool bc=true;
	if(ba==bc)
	{
		NSLog(@"OK");
	}
	
	NSString* tempStrign = [[NSString alloc]initWithFormat:@"Hello %s ,Number is %d",aString,23];
	NSLog(@"string length is %d",[tempStrign length]);
	
//	if([ba isEqual:bc])
//	{
//		NSLOg(@"OK2");
//	}
	
	return 3;
}

-(void)TestStaticLibraryMethods
{
	//Common common;
	Common* myUtility=[[Common alloc]init];
	
	char* src="Hello world";
	
	NSLog(@"subclass data %@",[myUtility GetNStringFromChar:src]);
}

+(void)TestHowToUseString
{
	NSString* string = @"Hello world";
	
	NSString* notHandy = [[NSString alloc] initWithUTF8String:"helloWorld"];
	NSString* stillNotHandy = // initWithFormat 类似 sprintf()
	[[NSString alloc] initWithFormat:@"%s", "helloWorld"];
	
	
	int size = [@"hello" length];
	NSString* hello2 = [@"hello" uppercaseString];
	
	NSLog(@"%@ and %@ and %d ,%@,%@",string,hello2,size,stillNotHandy,notHandy);
	
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
