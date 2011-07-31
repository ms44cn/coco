//
//  MyCocoaObject.h
//  TestCocoaCenter
//
//  Created by fuqifacai on 7/27/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface MyCocoaObject : NSObject {
	double Count;//default is protected
	
	
	@public
	int a;
	id myRunTimeVars;
	
	NSString* myTestProperty;
	
	@protected	
	int b;
	
	
	@private
	int c;
	

	
}

@property(retain) NSString*	myTestProperty;


-(void)TestStaticLibraryMethods;
-(void)TestMethod1:(id)sender;
-(void)TestMethod1:(id)sender:(int)order;//override method
+(void)TestHowToUseString;

-(int)TestHowToUseCollectionObjects:(int)order;




@end
