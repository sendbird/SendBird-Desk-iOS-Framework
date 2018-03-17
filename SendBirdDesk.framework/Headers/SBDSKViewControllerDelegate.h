//
//  SBDSKViewControllerDelegate.h
//  SendBirdDesk
//
//  Created by Jed Gyeong on 4/28/17.
//  Copyright © 2017 SendBird. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol SBDSKViewControllerDelegate<NSObject>

- (void)closeSendBirdDesk;
- (void)updateOpenTicket:(long long)ticketId;

@end
