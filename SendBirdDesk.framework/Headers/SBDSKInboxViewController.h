//
//  SBDSKInboxViewController.h
//  SendBirdDesk
//
//  Created by Jed Gyeong on 4/17/17.
//  Copyright © 2017 SendBird. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <SendBirdSDK/SendBirdSDK.h>

#import "SBDSKViewControllerDelegate.h"

@interface SBDSKInboxViewController : UIViewController<UITableViewDataSource, UITableViewDelegate, SBDConnectionDelegate, SBDChannelDelegate, SBDSKViewControllerDelegate>

@property (weak, nonatomic) id<SBDSKViewControllerDelegate> delegate;
@property (strong, nonatomic) UIViewController *previousViewController;

@end
