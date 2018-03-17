//
//  SBDSKMessageCellDelegate.h
//  SendBirdDesk
//
//  Created by Jebeom Gyeong on 27/04/2017.
//  Copyright © 2017 SendBird. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <SendBirdSDK/SendBirdSDK.h>

@protocol SBDSKMessageCellDelegate <NSObject>

- (void)clickMessage:(UIView *)view message:(SBDBaseMessage *)message;
- (void)clickResendFailedMessage:(UIView *)view message:(SBDBaseMessage *)message;
- (void)clickDeleteFailedMessage:(UIView *)view message:(SBDBaseMessage *)message;
- (void)clickViewMessage:(UIView *)view message:(SBDBaseMessage *)message;
- (void)clickInquireCloseMessageYes:(UIView *)view message:(SBDBaseMessage *)message;
- (void)clickInquireCloseMessageNo:(UIView *)view message:(SBDBaseMessage *)message;
- (void)clickUrlInMessage:(UIView *)view message:(SBDBaseMessage *)message url:(NSURL *)url;

@end
