//
//  MyFirstIphoneAppAppDelegate.h
//  MyFirstIphoneApp
//
//  Created by fuqifacai on 8/1/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface MyFirstIphoneAppAppDelegate : NSObject <UIApplicationDelegate> {
    UIWindow *window;
}

@property (nonatomic, retain) IBOutlet UIWindow *window;

-(IBAction)JustTest:(id)sender;

@end

