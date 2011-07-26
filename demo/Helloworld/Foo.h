//
//  Foo.h
//  Helloworld
//
//  Created by fuqifacai on 7/25/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface Foo : NSObject {
	IBOutlet NSTextField	*myTextField;
}

-(IBAction)seed:(id)sender;
-(IBAction)generate:(id)sender;
-(IBAction)ShowHelloWorld:(id)sender;

@end
