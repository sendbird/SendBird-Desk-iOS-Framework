//
//  SBDSKChattingViewController.h
//  SendBirdDesk
//
//  Created by Jed Gyeong on 4/24/17.
//  Copyright © 2017 SendBird. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <SendBirdSDK/SendBirdSDK.h>
#import <TOCropViewController/TOCropViewController.h>
#import <NYTPhotoViewer/NYTPhotosViewController.h>

#import "SBDSKTicket.h"
#import "SBDSKMessageCellDelegate.h"
#import "SBDSKViewControllerDelegate.h"

@interface SBDSKChattingViewController : UIViewController<UITableViewDataSource, UITableViewDelegate, UITextViewDelegate, SBDConnectionDelegate, SBDChannelDelegate, UIImagePickerControllerDelegate, UINavigationControllerDelegate, SBDSKMessageCellDelegate, SBDSKViewControllerDelegate, TOCropViewControllerDelegate, NSURLSessionTaskDelegate, NSURLSessionDataDelegate, NYTPhotosViewControllerDelegate>

@property (strong, nonatomic) UIViewController *previousViewController;

@property (weak, nonatomic) id<SBDSKViewControllerDelegate> delegate;

@property (strong, nonatomic) SBDSKTicket *ticket;
@property (strong, nonatomic) SBDGroupChannel *channel;
@property (strong, nonatomic) NSString *channelUrl;
@property (strong, nonatomic) NSString *userId;
@property (strong, nonatomic) NSString *accessToken;

@property (strong, nonatomic) NSString *ticketTitle;
@property (strong, nonatomic) NSString *ticketInfo;
@property (atomic) BOOL isClosedTicket;

@end
