SendBird Desk SDK Integration Guide for iOS
===========
SendBird Desk is a chat customer service platform built on SendBird SDK and API.

Desk iOS SDK provides customer-side integration on your own application, so you can easily implement **ticketing system with chat inquiry**.  
Desk iOS SDK requires devices running **iOS 8.0 or higher** and **SendBird iOS SDK 3.0.90 or higher**.

## Table of Contents

  1. [Installation](#installation)
  1. [Initialization](#initialization)
  1. [Authentication](#authentication)
  1. [Setting customer customFields](#setting-customer-customfields)
  1. [Creating a new ticket](#creating-a-new-ticket)
  1. [Count of opened tickets](#count-of-opened-tickets)
  1. [Loading ticket list](#loading-ticket-list)
  1. [Confirming end of chat](#confirming-end-of-chat)
  1. [Ticket Feedback](#ticket-feedback)
  1. [Handling ticket event](#handling-ticket-event)
  1. [Rich messages](#rich-messages)
  
## Installation

First of all, you need SendBird App ID to start (It can be created on [SendBird Dashboard](https://dashboard.sendbird.com), but for Desk usage, you may need upgrade.),
so please contact [desk@sendbird.com](mailto:desk@sendbird.com) if you want to try Desk.

Installing the Desk SDK is a straightforward process if you're familiar with using external libraries or SDKs in your projects.
To install the Desk SDK using CocoaPods, add the following lines to your `Podfile` file.

1. Create or edit your `Podfile`.
```
# Uncomment the next line to define a global platform for your project
platform :ios, '9.0'

target 'YourTarget' do
  # Uncomment the next line if you're using Swift or would like to use dynamic frameworks
  use_frameworks!

  # Pods for YourTarget
  pod 'SendBirdDesk', :git => 'https://github.com/sendbird/SendBird-Desk-iOS-Framework', :tag => 'v1.0.5'

end
```
2. Run `pod install`.
3. Open `YOUR_PROJECT.xcworkspace`.

## Initialization

Invoke `initWithApplicationId:` of `SBDMain` with your SendBird App ID just like when you initialize SendBird SDK and then
call `initializeDesk` of `SBDSKMain` to use SendBird Desk SDK's features. Please be sure to initialize SendBird SDK before SendBirdDesk SDK.
```obj-c
// AppDelegate.m

#import <SendBirdDesk/SendBirdDesk.h>

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // ...

    [SBDMain initWithApplicationId:APP_ID];
    [SBDSKMain initializeDesk];

    // ...

    return YES;
}

```

> Calling `initWithApplicationId:` of `SBDMain` and `initializeDesk` of `SBDSKMain` on `application:didFinishLaunchingWithOptions:` of `AppDelegate.m` is highly recommended.

> Even you use SendBird Desk SDK, you have to handle chat messages thru SendBird SDK. SendBird Desk SDK provides add-on features like chat ticket creation and loading chat tickets.
Ticket is the concept that does not exist on SendBird SDK and newly introduced on SendBird Desk SDK to support customer service ticketing system.
Every ticket created will be assigned to the appropriate agents and it will have a mapping channel of SendBird SDK, so you can implement real-time messaging on tickets with SendBird SDK.
> While using SendBird Desk SDK, it is also possible that you implement your own chat service using SendBird SDK.
For example, if you are operating an on-demand service, you can add an in-app messenger (for your platform users) as well as customer service chat (between users and agents)
into your application or website by combination of SendBird SDK and SendBird Desk SDK.


## Authentication

After initialization, connecting to SendBird's server by SendBird SDK is required for real-time messaging. 
This part is fully described on [SendBird SDK guide docs](https://docs.sendbird.com/ios#authentication_2_authentication).
Authentication of SendBird Desk `authenticateWithUserId:accessToken:completionHandler:` of `SBDSKMain` is also a mandatory for you to use ticket related features.
Below is an example for SendBird SDK connection and SendBird Desk SDK authentication.
```obj-c
- (void)connect {
    [SBDMain connectWithUserId:USER_ID accessToken:ACCESS_TOKEN completionHandler:^(SBDUser * _Nullable user, SBDError * _Nullable error) {
            // Error handling.
            
            return;
        }
        
        
        // Use the same user ID and access token used on connectWithUserId: of SBDMain.
        [SBDSKMain authenticateWithUserId:USER_ID accessToken:ACCESS_TOKEN completionHandler:^(SBDError * _Nullable error) {
            if (error != nil) {
                // Error handling.
                
                return;
            }
            
            // Now you can create a ticket, get open ticket count and load tickets.
        }];
    }];
}
```
  
Now your customers are ready to create chat tickets and start inquiry with your agents!

## Setting customer customFields



Customer information could be kept in `customFields`. `setCustomerCustomFields:completionHandler:` in `SBDSKMain` lets the SDK set the `customFields` of the current customer. The `customFields` columns should be defined in SendBird Dashboard beforehand. Otherwise, the setting would be ignored.
```obj-c
NSDictionary *customerCustomFields = @{
                                       @"gender": @"male",
                                       @"age": @"20",
                                       };

[SBDSKMain setCustomerCustomFields:customerCustomFields completionHandler:^(SBDError * _Nullable error) {
    if (error != nil) {
        // customer's customFields is rightly set
        // (or a certain key could get ignored if the key is not defined yet)
    }
}];
```

## Creating a new ticket

Creating a new ticket is as simple as just calling `createTicketWithTitle:userName:completionHandler:` of `SBDSKTicket`. Ticket title and user name can be passed at the same time.
The returned ticket will have a channel instance which can be accessed by `ticket.channel`. So you can send messages to the channel using SendBird SDK.
For more detail of sending messages to channel, please refer to [SendBird SDK guide docs](https://docs.sendbird.com/ios#group_channel_3_sending_messages).
Please notice that only after customers sending at least one message to the ticket, the ticket will be routed to the online agents so they can answer it.
```obj-c
- (void)createTicket {
    [SBDSKTicket createTicketWithTitle:TICKET_TITLE userName:USER_NAME completionHandler:^(SBDSKTicket * _Nullable ticket, SBDError * _Nullable error) {
        if (error != nil) {
            // Error handling.
            return;
        }
        
        // Now you can send messages to the ticket by `[self.ticket.channel sendUserMessage:]` or `[self.ticket.channel sendFileMessage:]`.
    }];  
}
```

> To create a ticket, you can use `createTicketWithTitle:userName:groupKey:customField:completionHandler:` method. The `groupKey` and `customField` could be evaluated when a ticket is created though it's used only in Dashboard currently. `groupKey` is the key of an agent group so that the ticket is assigned to the agents in that group. `customField` holds customizable data for the individual ticket.

## Count of opened tickets
When you need to display opened ticket count somewhere on your application, `[SBDSKTicket getOpenCountWithCompletionHandler:]` is useful.
```obj-c
- (void)getOpenCount {
    [SBDSKTicket getOpenCountWithCompletionHandler:^(int count, SBDError * _Nullable error) {
        if (error != nil) {
            // Error handling.
            return;
        }
    }];
}
```

## Loading ticket list
Usually you will design `Inbox` activity for open tickets and closed tickets history for your customer.
Open tickets and closed tickets can be loaded from `getOpenedListWithOffset:completionHandler:` of `SBDSKTicket` and `getClosedListWithOffset:completionHandler:` of `SBDSKTicket`.
Zero is a good start value of the offset, then the maximum 10 tickets will be returned for each call by last message creation time descending order.
Open ticket list and closed ticket list can be loaded like below:
```obj-c
- (void)getOpenedList {
    [SBDSKTicket getOpenedListWithOffset:offset completionHandler:^(NSArray<SBDSKTicket *> * _Nonnull tickets, BOOL hasNext, SBDError * _Nullable error) {
        if (error != nil) {
            // Error handling.
            return;
        }
        
        // offset += tickets.count; for the next tickets.
        // This is the best place you display tickets on inbox.
    }];
}
```

```obj-c
- (void)getClosedList {
    [SBDSKTicket getClosedListWithOffset:offset completionHandler:^(NSArray<SBDSKTicket *> * _Nonnull tickets, BOOL hasNext, SBDError * _Nullable error) {
        if (error != nil) {
            // Error handling.
            return;
        }
        
        // offset += tickets.count; for the next tickets.
        // This is the best place you display tickets on inbox.
    }];
}
```

> To get opened ticket list or closed ticket list, you can use `getOpenedListWithOffset:customFieldFilter:completionHandler:` method or `getClosedListWithOffset:customFieldFilter:completionHandler:` method respectively. Once you set `customField` to tickets, you can put `customFieldFilter` to `getOpenedListWithOffset:customFieldFilter:completionHandler:` and `getClosedListWithOffset:customFieldFilter:completionHandler:` in order to filter the tickets by `customField` values.

## Confirming end of chat
There are predefined rich messages on SendBird Desk and `Confirm end of chat` is one of them. For other rich messages, please refer to [Handling messages](#handling-messages).
All rich messages have message custom type (can be accessed by `SBDUserMessage.customType` on SendBird SDK) as `SENDBIRD_DESK_RICH_MESSAGE`,
and `Confirm end of chat` message has custom data (can be accessed by `SBDUserMessage.data` on SendBird SDK) as below:
```js
{
    "type": "SENDBIRD_DESK_INQUIRE_TICKET_CLOSURE",
    "body": {
        "state": "WAITING" // also can have "CONFIRMED", "DECLINED"
    }
}
```

This `Confirm end of chat` massage is initiated from agents to inquire closure of ticket to customers.
The initial `state` will be `WAITING` and you have to implement of updating the `state` according to customers action.
Usually, you can display `YES` or `NO` button like sample and update to `CONFIRMED` when customers touch `YES` button. Updating to `DECLINED` is also possible when customers touch `NO`.
For update the `state` of `Confirm end of chat`, please use `confirmEndOfChatWithMessage:confirm:completionHandler:` of `SBDSKTicket`.
```obj-c
[SBDSKTicket confirmEndOfChatWithMessage:(SBDUserMessage *)message confirm:confirm_or_decline completionHandler:^(SBDSKTicket * _Nullable ticket, SBDError * _Nullable error) {
    if (error != nil) {
        // Error handling.
        return;
    }
    
    // You can update message UI like hiding YES NO buttons.
}];

```
At the moment, tickets will be closed (ticket close event will be sent to customers) only after customers confirming end of chat,  

## Handling ticket event
SendBird Desk SDK uses some predefined AdminMessage custom type (`SBDAdminMessage.customType` on SendBird SDK) for ticket update notification.
This reserved custom type value is `SENDBIRD_DESK_ADMIN_MESSAGE_CUSTOM_TYPE` and at the moment there are 3 kinds of ticket event, which are `Ticket assign`, `Ticket transfer` and `Ticket close`.
Each event has the following `AdminMessage.getData()`:
```js
{
    "type": "TICKET_ASSIGN" // "TICKET_TRANSFER", "TICKET_CLOSE"
}
```
You can check these messages from `channel:didReceiveMessage:` delegate of `SBDChannelDelegate` on SendBird SDK.
SendBird Desk SDK internally tracks these events and update ticket status automatically. So when you see these events, you can directly get ticket object by `getByChannelUrl:completionHandler:` of `SBDSKTicket` and then use it for e.g. 
rendering assigned agent's profile or moving ticket from open list to closed list.

### Ticket Feedback

If Desk satisfaction feature is on, a message would come after closing the ticket. The message is for getting customer feedback including score and comment. The data of satisfaction form message looks like below.

```js
{
    "type": "SENDBIRD_DESK_CUSTOMER_SATISFACTION",
    "body": {
        "state": "WAITING" // also can have "CONFIRMED",
        "customerSatisfactionScore": null, // or a number ranged in [1, 5]
        "customerSatisfactionComment": null // or a string (optional)
    }
}
```

Once the customer inputs the score and the comment, the data could be submitted by calling `submitFeedbackWithMessage:score:comment:completionHandler:` in `SBDSKTicket`. Then updated message is going to be sent in `channel:didUpdateMessage:`.


```obj-c
[SBDSKTicket getByChannelUrl:sender.channelUrl completionHandler:^(SBDSKTicket * _Nullable ticket, SBDError * _Nullable error) {
    if (error != nil) {
        return;
    }
    
    NSDictionary *result = nil;
    NSError *parsingError = nil;
    @autoreleasepool {
        result = [NSJSONSerialization JSONObjectWithData:[message.data dataUsingEncoding:NSUTF8StringEncoding] options:NSJSONReadingMutableContainers error:&parsingError];
    }
    if (parsingError == nil) {
        if ([result[@"type"] isEqualToString:@"SENDBIRD_DESK_CUSTOMER_SATISFACTION"]) {
            NSString *state = result[@"body"][@"state"];
            if ([state isEqualToString:@"WAITING"]) {
                // do something on WAITING
            }
            else if ([state isEqualToString:@"CONFIRMED"]) {
                // do something on CONFIRMED
            }
        }
    }
}];
```

## Rich messages
Besides, `Confirm end of chat` message, URL preview is available as one of rich messages. (We are adding more very fast.)
URL preview message's `SBDUserMessage.customType` is also the same as `Confirm end of chat`, so it is `SENDBIRD_DESK_RICH_MESSAGE`.
Its `UserMessage.getData()` has the following format:
```js
{
    "type": "SENDBIRD_DESK_URL_PREVIEW",
    "body": {
        "url": "string",
        "site_name": "string",
        "title": "string",
        "description": "string",
        "image": "string (image url)"
    }
}
```
Therefore, when this type of message is received on `channel:didReceiveMessage:` delegate of `SBDChannelDelegate` or `getPreviousMessagesByTimestamp:limit:reverse:messageType:customType:completionHandler:` of channel, you can parse the data and use it for URL preview rendering.
Also if you extract URL information from customers text, build above JSON, stringify it and then send it as custom data by `sendUserMessage:` of channel, agents can also see URL preview.