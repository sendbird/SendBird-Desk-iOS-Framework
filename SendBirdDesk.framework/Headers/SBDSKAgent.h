//
//  SBDSKAgent.h
//  SendBird Desk
//
//  Created by SendBird on 3/13/18.
//  Copyright © 2019 SendBird. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 This class represents an agent who chats with a customer. It is not a subclass of [SBDUser](https://docs.sendbird.com/ref/ios/Classes/SBDUser.html) of SendBird, but this class and [SBDUser](https://docs.sendbird.com/ref/ios/Classes/SBDUser.html) class share the same identification.
 */
@interface SBDSKAgent : NSObject

/**
 The identification of the agent. There is the same user in SendBird who has the same identification.
 */
@property (strong, nonatomic, readonly, nullable) NSString *sendBirdId;

/**
 The name of the agent.
 */
@property (strong, nonatomic, readonly, nullable) NSString *name;

/**
 The profile image's URL of the agent.
 */
@property (strong, nonatomic, readonly, nullable) NSString *profileUrl;

@end
