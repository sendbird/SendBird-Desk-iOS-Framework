//
//  SBDSKTicket.h
//  SendBirdDesk
//
//  Created by Jed Gyeong on 4/17/17.
//  Copyright © 2017 SendBird. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SBDSKAgent : NSObject

@property (strong, nonatomic, readonly, nullable) NSString *sendBirdId;
@property (strong, nonatomic, readonly, nullable) NSString *name;
@property (strong, nonatomic, readonly, nullable) NSString *status;
@property (strong, nonatomic, readonly, nullable) NSString *profileUrl;

- (nullable instancetype)initWithDictionary:(NSDictionary * _Nonnull)dict;

@end

@interface SBDSKTicket : NSObject

@property (atomic, readonly) long long ticketId;
@property (strong, nonatomic, readonly, nullable) NSString *title;
@property (strong, nonatomic, readonly, nullable) NSString *status;
@property (strong, nonatomic, readonly, nullable) NSString *channelUrl;
@property (strong, nonatomic, readonly, nullable) NSString *lastMessage;
@property (atomic, readonly) long long unreadMessageCount;
@property (strong, nonatomic, nullable) SBDSKAgent *agent;

- (nullable instancetype)initWithDictionary:(NSDictionary * _Nonnull)dict;
- (BOOL)isClosed;

@end
