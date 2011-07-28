//
//  MyChildCocoaObject.h
//  TestCocoaCenter
//
//  Created by fuqifacai on 7/28/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "MyCocoaObject.h"

@interface MyChildCocoaObject : MyCocoaObject {
}

	-(int)TestMethod3:(int)order;

-(void)dealloc;//Default dector 
-(void)init;//default ctor

@end
