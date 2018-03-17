//
//  SBDSKAdminMessage.h
//  SendBirdDesk
//
//  Created by SendBird on 3/15/18.
//  Copyright © 2018 SendBird All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SendBirdSDK/SendBirdSDK.h>

@interface SBDSKAdminMessage : NSObject

+ (BOOL)isAdminMessage:(SBDBaseMessage * _Nonnull)message;

@end
