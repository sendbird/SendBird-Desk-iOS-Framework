//
//  SBDSKTicket.h
//  SendBirdDesk
//
//  Created by SendBird on 4/17/17.
//  Copyright © 2017 SendBird. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SendBirdSDK/SendBirdSDK.h>
#import "SBDSKAgent.h"

/**
 This class represents a ticket that identifies a chat between an agent and a customer.
 */
@interface SBDSKTicket : NSObject

/**
 The identification for a ticket. This property has a unique value.
 */
@property (atomic, readonly) long long ticketId;

/**
 The title of this ticket.
 */
@property (strong, nonatomic, nullable, readonly) NSString *title;

/**
 The status of this ticket.
 */
@property (strong, nonatomic, nullable, readonly) NSString *status;

/**
 The agent who is in charge of this ticket.
 */
@property (strong, nonatomic, nullable, readonly) SBDSKAgent *agent;

/**
 The channel where the agent and the customer are chatting.
 */
@property (strong, nonatomic, nullable, readonly) SBDGroupChannel *channel;

/**
 Refreshes this ticket. After invoking this method, this ticket is updated with the latest data.

 @param completionHandler The handler block to execute. If the method updates this ticket successfully, the `error` will be nil.
 */
- (void)refreshWithCompletionHandler:(nullable void (^)(SBDSKTicket * _Nullable ticket, SBDError * _Nullable error))completionHandler;

/**
 Confirms the end of the chat.
 
 @param message The message object.
 @param confirm The value that a customer uses in order to represent the confirmation of this ticket.
 @param completionHandler The handler block to execute. If the method confirms the end of this ticket, the `error` will be nil.
 */
+ (void)confirmEndOfChatWithMessage:(SBDUserMessage * _Nonnull)message confirm:(BOOL)confirm completionHandler:(nullable void (^)(SBDSKTicket * _Nullable ticket, SBDError * _Nullable error))completionHandler;

/**
 Creates a new ticket with information.

 @param title The title of a new ticket.
 @param userName The customer's name.
 @param completionHandler The handler block to execute. If the method creates a ticket successfully, the `ticket` object will be valid and the `error` will be nil.
 */
+ (void)createTicketWithTitle:(NSString * _Nullable)title userName:(NSString * _Nullable)userName completionHandler:(nullable void (^)(SBDSKTicket * _Nullable ticket, SBDError * _Nullable error))completionHandler;

/**
 Gets the count of the opened tickets.

 @param completionHandler The handler block to execute. The `count` is the count of the opened tickets. If the method gets the count successfully, the `error` will be nil.
 */
+ (void)getOpenCountWithCompletionHandler:(nullable void (^)(int count, SBDError * _Nullable error))completionHandler;

/**
 Gets the list of the opened tickets with the offset.

 @param offset The offset that represents the position of the full list. It must be 0 in order to get the latest list.
 @param completionHandler The handler block to execute. The `tickets` is the array of the opened tickets. The array can be empty, but it doesn't mean that there is an error. If there is the next page of the list, the `hasNext` will be YES. If the method gets the list successfully, the `error` will be nil.
 */
+ (void)getOpenedListWithOffset:(long)offset completionHandler:(nullable void (^)(NSArray<SBDSKTicket *> * _Nonnull tickets, BOOL hasNext, SBDError * _Nullable error))completionHandler;

/**
 Gets the list of the closed tickets with the offset.
 
 @param offset The offset that represents the position of the full list.
 @param completionHandler The handler block to execute. The `tickets` is the array of the closed tickets. The array can be empty, but it doesn't mean that there is an error. If there is the next page of the list, the `hasNext` will be YES. If the method gets the list successfully, the `error` will be nil.
 */
+ (void)getClosedListWithOffset:(long)offset completionHandler:(nullable void (^)(NSArray<SBDSKTicket *> * _Nonnull tickets, BOOL hasNext, SBDError * _Nullable error))completionHandler;

/**
 Gets a ticket by the group channel URL.

 @param channelUrl The group channel URL that is connected with a ticket.
 @param completionHandler The handler block to execute. If the method gets a ticket successfully, the `error` will be nil.
 */
+ (void)getByChannelUrl:(NSString * _Nonnull)channelUrl completionHandler:(nullable void (^)(SBDSKTicket * _Nullable ticket, SBDError * _Nullable error))completionHandler;

@end
