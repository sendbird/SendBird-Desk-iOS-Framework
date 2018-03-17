//
//  SBDSKMain.h
//  SendBirdDesk
//
//  Created by SendBird on 11/21/17.
//  Copyright © 2018 SendBird All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SendBirdSDK/SendBirdSDK.h>

#import "SBDSKTypes.h"
#import "SBDSKTicket.h"
#import "SBDSKAdminMessage.h"

/**
 This class is a main class of SendBirdDesk.
 */
@interface SBDSKMain : NSObject<SBDChannelDelegate>

+ (BOOL)initializeDesk;

/**
 Returns the version of SendBirdDesk.

 @return The version of SendBirdDesk.
 */
+ (nullable NSString *)getSdkVersion;

/**
 Sets the log level.

 @param logLevel The log level.
 */
+ (void)setLogLevel:(SBDSKLogLevel)logLevel;

/**
 Sets a dispatch queue for every completion handler in SendBirdDesk.

 @param queue A dispatch queue that will be used for every completion handler.
 */
+ (void)setCompletionHandlerDelegateQueue:(dispatch_queue_t _Nonnull)queue;


/**
 Gets an authentication with a user ID and an access token.

 @param userId User ID
 @param accessToken Access Token
 @param completionHandler The handler block to execute. If the method updates this ticket successfully, the `error` will be nil.
 */
+ (void)authenticateWithUserId:(NSString * _Nonnull)userId accessToken:(NSString * _Nullable)accessToken completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/**
 Checks whether the `channel` is a desk channel or not.

 @param channel The channel instance that is necessary to check.
 @return If YES, the `channel` is a desk channel.
 */
+ (BOOL)isDeskChannel:(SBDBaseChannel * _Nonnull)channel;

@end
