//
//  Common.h
//  TestCocoaCenter
//
//  Created by fuqifacai on 7/29/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface Common : NSObject {

}
-(void)MessageBox:(NSString*) text;

-(NSString*)GetNStringFromChar:(const char*)src;
-(char*)GetCharArrary:(NSString*)src;

@end
