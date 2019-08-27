//
//  SBDSKMain.h
//  SendBird Desk
//
//  Created by SendBird on 11/21/17.
//  Copyright © 2019 SendBird. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SendBirdSDK/SendBirdSDK.h>

#import "SBDSKTicket.h"

/**
 This class is a main class of SendBird Desk.
 */
@interface SBDSKMain : NSObject<SBDChannelDelegate>

/**
 Initializes SendBird Desk. 

 @return If YES, the initialization is successful. This method has to be called after [initializing SendBird SDK](https://docs.sendbird.com/ref/ios/Classes/SBDMain.html#//api/name/initWithApplicationId:).
 */
+ (BOOL)initializeDesk;

/**
 Returns the version of SendBird Desk.

 @return The version of SendBird Desk.
 */
+ (nullable NSString *)getSdkVersion;

/**
 Sets a dispatch queue for every completion handler in SendBird Desk.

 @param queue A dispatch queue that will be used for every completion handler.
 */
+ (void)setCompletionHandlerDelegateQueue:(nonnull dispatch_queue_t)queue;


/**
 Gets an authentication with a user ID and an access token.

 @param userId User ID
 @param accessToken Access Token
 @param completionHandler The handler block to execute. If the method updates this ticket successfully, the `error` will be nil.
 */
+ (void)authenticateWithUserId:(nonnull NSString *)userId
                   accessToken:(nullable NSString *)accessToken
             completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

/**
 Checks whether the `channel` is a desk channel or not.

 @param channel The channel instance that is necessary to check.
 @return If YES, the `channel` is a desk channel.
 */
+ (BOOL)isDeskChannel:(nonnull SBDBaseChannel *)channel;

/**
 Sets the current customer's custom fields. The custom fields has a key and a value in string type.

 @param customFields The current customer's custom fields.
 @param completionHandler The handler block to execute. If the method sets successfully, the `error` will be nil.
 
 @since 1.0.5
 */
+ (void)setCustomerCustomFields:(nonnull NSDictionary<NSString *, NSString *> *)customFields
              completionHandler:(nullable void (^)(SBDError * _Nullable error))completionHandler;

@end
