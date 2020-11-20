# [Sendbird](https://sendbird.com) Desk SDK for iOS

![Platform](https://img.shields.io/badge/platform-iOS-orange.svg)
![Languages](https://img.shields.io/badge/language-Objective--C-orange.svg)

## Table of Contents

  1. [Introduction](#introduction)
  1. [Before getting started](#before-getting-started)
  1. [Getting started](#getting-started)
  1. [Create your first ticket](#create-your-first-ticket)
  
  
<br />

## Introduction

Sendbird Desk enables strong customer engagement through live, in-app support. The Desk SDK lets you easily initialize, configure, and build customer support-related functionality into your iOS applications.

### How it works

Sendbird Desk is a plugin of the [Sendbird Chat Platform](https://sendbird.com/docs/chat) for managing tickets, and thus Desk events are handled by event handlers through the [Chat SDK](https://github.com/sendbird/sendbird-ios-framework). 

Every ticket is assigned appropriate agents and will be directed to a Sendbird SDK channel, which implements real-time messaging on tickets with Sendbird SDK. 

### Concepts

These are a few of the main components of Desk SDK. 

- **Channels**: The various ways through which support can be requested e.g. in-app chats from different OS platforms or social media like Facebook and Instagram.
- **Tickets**: A ticket is created when a customer and agent start a conversation and is seen as a unit of customer’s inquiry. There are five types of tickets.
- **Agents**: An agent receives the requests and also handles the conversation in the [Sendbird Dashboard](https://dashboard.sendbird.com/auth/signin). 
- **Admins**: Admins are agents who are granted the additional privileges of managing the overall dashboard settings and the tickets. 
- **Messages**: Desk has two types of messages that fall into further subtypes. The following table shows the hierarchical structure of messages. 

||Sender|Subtypes|
|---|---|---|
| User message| Agent or customer|Rich messages |
| ADmin message |Sent from the Desk server without a specific sender |Notification messages and System messages |


### More about Sendbird Desk SDK for iOS

Find out more about Sendbird Desk SDK for iOS on [Desk SDK for iOS doc](https://sendbird.com/docs/desk/v1/ios/getting-started/about-desk-sdk). If you have any comments or questions regarding bugs and feature requests, visit [Sendbird community](https://community.sendbird.com).

<br />

## Before getting started

This section shows the prerequisites you need to check to use Sendbird Desk SDK for iOS.

### Requirements

The requirements of Desk SDK for iOS are:

- `iOS 8.0 or higher`
- `Sendbird iOS SDK 3.0.90 or higher`

<br />

## Getting started

This section gives you information you need to get started with Sendbird Desk SDK for iOS. 

### Try the sample app

Our sample app demonstrates the core features of Sendbird Desk SDK. Download the app from our GitHub repository to get an idea of what you can do with the actual SDK and to get started building your own project.
 
- https://github.com/sendbird/quickstart-desk-ios

### Step 1: Create a Sendbird application from your dashboard

A Sendbird application comprises everything required in a chat service including users, message, and channels. To create an application:

1. Go to the Sendbird Dashboard and enter your email and password, and create a new account. You can also sign up with a Google account.
2. When prompted by the setup wizard, enter your organization information to manage Sendbird applications.
3. Lastly, when your dashboard home appears after completing setup, click **Create +** at the top-right corner.

Regardless of the platform, only one Sendbird application can be integrated per app; however, the application supports communication across all Sendbird’s provided platforms without any additional setup. 

> **Note**: All the data is limited to the scope of a single application, thus users in different Sendbird applications are unable to chat with each other. 

### Step 2: Download and install the Desk SDK

Installing the Desk SDK is simple if you’re familiar with using external libraries or SDK’s in your projects. You can install Desk SDK using the two following methods: 

1. Create or edit your `Podfile` file.
```bash
# Uncomment the next line to define a global platform for your project
platform :ios, '9.0'

target 'YourTarget' do
    # Uncomment the next line if you're using Swift or would like to use dynamic frameworks
    use_frameworks!
    
    # Pods for YourTarget
    pod 'SendBirdDesk', :git => 'https://github.com/sendbird/SendBird-Desk-iOS-Framework', :tag => 'v1.0.7'

end
```
2. Run `pod install`.
3. Open `YOUR_PROJECT.xcworkspace`.

Alternatively, you can download the latest Desk SDK for iOS. Copy the Desk SDK, which can be found in the Github Repository, into your project directory, and make sure you include the library in your working file as well.

<br />

## Create your first ticket

After installation has been completed, a ticket can be created for communication between an agent and customer. Follow the step-by-step instructions below to create your first ticket.

### Step 1: Initialize the Desk SDK 

A ‘SBDSKMain’ instance must be initialized when launching a client app. Call the `SBDMain.initWithApplicationId()` and `SBDSKMain.initializeDesk()` methods within the `applicationDidFinishLaunching()`. The `initWithApplicationId()` should be called first by the `APP_ID` of your Sendbird application in the dashboard. 

```swift
class AppDelegate: UIApplicationDelegate {
    func applicationDidFinishLaunching(_ application: UIApplication) {
        SBDMain.initWithApplicationId(APP_ID)
        SBDSKMain.initializeDesk()
    }
}
```

> **Note**: Built with Sendbird Chat SDK, Sendbird Desk SDK is a plugin that handles customer inquiries through tickets. Messages within tickets are dealt with by Sendbird Chat platform, and every ticket is mapped to a group channel in Sendbird Chat. Because of this interaction, the same `APP_ID` should be used for both Desk and Chat SDKs.

### Step 2: Authenticate a customer

Customers can request support from various types of channels: in-app chats or social media such as Facebook, Instagram and Twitter. To use these support features of Desk SDK, the SendBirdDesk instance should be connected with Sendbird server depending on which channel the request is from: 

- **Sendbird Chat Platform**: Authenticate using the `SBDMain.connect()` and `SBDSKMain.authenticate()` method with their user IDs. 
- **Social media platforms**: No authentication needed as customers are automatically registered in the [dashboard](https://dashboard.sendbird.com/auth/signin) with their social media accounts.

Once authenticated, customers can live-chat with agents based on Sendbird Chat platform.

```swift
SBDMain.connect(withUserId: USER_ID, accessToken: ACCESS_TOKEN) { (user, error) in
    guard error == nil else {   // Error.
        return
    }
    
    // Use the same user ID and access token used in the SBDMain.connect()
    SBDSKMain.authenticate(withUserId: USER_ID, accessToken: ACCESS_TOKEN) { (error) in
        guard error == nil else {   // Error.
            return
        }
        
        // SendBirdDesk is now initialized, and the customer is authenticated.
    }
}
```

> **Note**: **Customers from Sendbird Chat platform** signifies users who are already authenticated with the Chat SDK. If you’re implementing Chat SDK and Desk SDK at the same time, [connect a user to Sendbird server with their user ID and access token](https://sendbird.com/docs/chat/v3/ios/guides/authentication) first.

### Step 3: Create a ticket

Implement the `SBDSKTicket.createTicket()` method to create a new ticket either before or after the customer’s initial message. The returned ticket will have a channel instance which can be accessed by ticket.channel. So you can send messages to the channel using SendBird SDK.

```swift
SBDSKTicket.createTicket(withTitle: TITLE, userName: USER_NAME) { (ticket, error) in
    guard error == nil else {   // Error.
        return
    }
    
    // The ticket is created. Agents and customers can chat with each other by sending a message through the ticket.channel.sendUserMessage() or sendFileMessage().
}
```

Once a ticket is successfully created on the Sendbird server, you can access the ticket and its channel through the callback from the server.  

Before a customer sends the first message, agents can’t see the ticket in the dashboard and ticket assignment does not occur. When conversation starts, the ticket is assigned to an available agent by the Desk Dashboard while messages are sent and received through the Chat SDK.

You can use the following arguments for parameters in the method when creating a ticket.

|Argument|Type|Description|
|---|---|---|
|TICKET_TITLE|string |Specifies the title of the ticket.|
|USER_NAME|string |Specifies the name of the user who submits or receives the ticket.|
|GROUP_KEY|string | Specifies the identifier of a specific team.|
|customFields| [String:String]|Specifies additional information of the ticket that consists of **key-value** custom items. Only custom fields already registered in **Settings** > **Ticket** fields in your dashboard can be used as a key. |
|PRIORITY |string |Specifies the priority value of the ticket. Higher values stand for higher priority. Valid values are **LOW**, **MEDIUM**, **HIGH** and **URGENT**. |
|RELATED_CHANNEL_URLS|array | Specifies group channels in Sendbird Chat platform that are related to this ticket and consists of channel URLs and channel names. Up to 3 related channels can be added.|

```swift
var customFields = [String: String]()
customFields["product"] = "desk"
customFields["line"] = "14"
customFields["select"] = "option2"

SBDSKTicket.createTicket(withTitle: TICKET_TITLE, userName: USER_NAME, groupKey: "cs-team-1", customFields: customFields, priority: PRIORITY, relatedChannels: RELATED_CHANNEL_URLS) { (ticket, error) in
    guard error == nil else {   // Error.
        return 
    }
    
    // The ticket is created with parameters.
}
```
