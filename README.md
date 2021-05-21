# [Sendbird](https://sendbird.com) Desk SDK for iOS

## Table of contents

  1. [Introduction](#introduction)
  1. [Before getting started](#before-getting-started)
  1. [Getting started](#getting-started)
  1. [Creating your first ticket](#creating-your-first-ticket)
  1. [Implementation guide](#implementation-guide)

<br />

## Introduction

**Sendbird Desk** enables strong customer engagement through live, in-app support. The Desk SDK lets you easily initialize, configure, and build customer support-related functionality into your iOS applications.

### How it works

Sendbird Desk is a plugin of the [Sendbird Chat Platform](https://sendbird.com/docs/chat) for managing tickets, and thus Desk events are handled by event handlers through the [Chat SDK](https://github.com/sendbird/sendbird-ios-framework). 

Every ticket is assigned appropriate agents and will be directed to a chat's group channel, which implements real-time messaging on tickets with Sendbird Chat SDK. 

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
| Admin message |Sent from the Desk server without a specific sender |Notification messages and System messages |

> **Note**: Rich messages are further classified into [URL preview](#add-url-previews), [confirmation request for ticket closing](#request-confirmation-to-close-a-ticket), and [feedback request](#request-customer-feedback) messages. 

### More about Sendbird Desk SDK for iOS

Find out more about Sendbird Desk SDK for iOS on [Desk SDK for iOS doc](https://sendbird.com/docs/desk/v1/ios/getting-started/about-desk-sdk). If you have any comments or questions regarding bugs and feature requests, visit [Sendbird community](https://community.sendbird.com).

<br />

## Before getting started

This section shows the prerequisites you need to check to use Sendbird Desk SDK for iOS.

### Requirements

The requirements of Desk SDK for iOS are:

- `iOS 8.0 or higher`
- `Sendbird iOS SDK 3.0.200 or higher`

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
    pod 'SendBirdDesk'

end
```
2. Run `pod install`.
3. Open `YOUR_PROJECT.xcworkspace`.

Alternatively, you can download the latest Desk SDK for iOS. Copy the Desk SDK, which can be found in the Github Repository, into your project directory, and make sure you include the library in your working file as well.

<br />

## Creating your first ticket

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

<br />

## Implementation guide

This section details the procedure to handle and close a ticket from your client app. 

### Add custom information to a ticket

Use the `ticket.setCustomFields()` method to add additional information about a ticket.

```swift
var customFields = [String: String]()
customFields["product"] = "Desk"
customFields["line"] = "\(30)"

ticket.setCustomFields(customFields) { (error) in
    guard error == nil else {   // Error.
        return 
    }
    
    // Custom fields for the ticket are set.
    // Some fields can be ignored if their keys aren't registered in the dashboard.
}
```

> **Note**: Only custom fields registered in **Desk** > **Settings** > **Ticket fields** of your dashboard can be used as a key.

### Add custom information to a customer

Use the `setCustomerCustomFields()` method of the `SBDSKMain` to make your customers add additional information about themselves.

```swift
var customFields = [String: String]()
customFields["gender"] = "Female"
customFields["age"] = "\(30)"

SBDSKMain.setCustomerCustomFields(customFields) { (error) in
    guard error == nil else {   // Error.
        return 
    }
}

// Custom fields for the customer are set.
// Some fields can be ignored if their keys aren't registered in the dashboard.
```

> **Note**: Only custom fields registered in **Desk** > **Settings** > **Customer fields** of your dashboard can be used as a key.

### Add related channels

Related channels indicate group channels in Sendbird Chat platform that are related to a ticket. When creating a ticket, pass the `channel_url`s of the related group channels as an argument to the `relatedChannels` parameter in the `SBDSKTicket.createTicket()` method. To update the related channels, use the `SBDSKTicket.setRelatedChannels()` instead. The `SBDSKTicket.relatedChannels` property in the callback indicates the group channel object of related channels and it contains channel names and their URLs.

```swift
SBDSKTicket.createTicket(withTitle: TITLE, userName: USER_NAME) { (ticket, error) in
    guard error == nil else {   // Error.
        return
    }
    
    // The ticket is created. Agents and customers can chat with each other by sending a message through the ticket.channel.sendUserMessage() or sendFileMessage().
   ...

   ticket.setRelatedChannels(RELATED_CHANNEL_URLS) { (error) in
        guard error == nil else {   // Error.
           return 
       }
            
    // The ticket.relatedChannels property has been updated.
   }
}
```

> **Note**: Up to 3 related channels can be added per ticket.

### Add URL previews

With URL previews, your application users can meet their expectations of what they’re going to get before they open the link during the conversations.

To use URL previews, every text message should be checked if it includes any URLs. Second, parse the HTML source of the URL to look for OpenGraph meta tags. Then, set the extracted OG meta data as a `JSON` object and stringify the object to pass it as an argument to a data parameter in the `SBDGroupChannel.update(userMessage, messageText, data, customType, completionHandler)` method. The updated message with URL preview is delivered to the client app through the `channel(_ sender: SBDBaseChannel, didUpdate message:SBDBaseMessage)` delegate method of the `SBDChannelDelegate`.

```swift
ticket.channel?.sendUserMessage(TEXT, completionHandler: { userMessage, error in
    guard let userMessage = userMessage, error == nil else {    // Error
        return 
    }
            
    let detector = try? NSDataDetector(types: NSTextCheckingResult.CheckingType.link.rawValue)
    let match = detector?.firstMatch(in: userMessage.message, options: [], range: NSMakeRange(0, userMessage.message.count))
    guard let url = match?.url else {   // No matching URL 
        return 
    }
         
    URLSession().dataTask(with: url) { (data, response, error) in
        guard error == nil, let data = data else {  // Error.
            return 
        }
                
        guard let httpResponse = response as? HTTPURLResponse,
        let contentType = httpResponse.allHeaderFields["Content-Type"] as? String,
            contentType.contains("text/html") else { return }
        let htmlBody = String(data: data, encoding: .utf8)

        // Extract ogTitle, ogImage, ogUrl, ogSiteName, ogDescription from htmlBody.
        // Refer to Open Graph Protocol(https://ogp.me/), and other open source implementations of OG tag parsing for further details. 

        let urlPreview = ["type": "SENDBIRD_DESK_URL_PREVIEW",
            "body": [
                "title": ogTitle,
                "image": ogImage,
                "url": ogUrl,
                "site_name": ogSiteName,
                "description": ogDescription
            ]
        ] as [String: Any]
        // Stringified JSON object let jsonData = try? JSONSerialization.data(withJSONObject: urlPreview, options: [])

        ticket.channel?.update(userMessage, messageText: userMessage.message, data: jsonData?.base64EncodedString(), customType: "SENDBIRD_DESK_RICH_MESSAGE", completionHandler: { (userMessage, error) in
            guard error == nil else {   // Error.
                return 
            }
            ...
            // Pass data to SBDGroupChannel.update(userMessage, messageText, data, customType, completionHandler) method. 
        })
    }
})
```

There are various methods to extract OG meta data from the html body. You can also refer to our Github repository for the method we're using. 

In the `SBDChannelDelegate`s’ `channel(_ sender: SBDBaseChannel, didUpdate message: SBDBaseMessage)` delegate method, you can find the data for URL preview in the `UserMessage.data` property as below.

```json
{
    "type": "SENDBIRD_DESK_URL_PREVIEW",
    "body": {
        "url": "https://sendbird.com/",
        "site_name": "Sendbird",
        "title": "A Complete Chat Platform, Messaging and Chat SDK and API",
        "description": "Sendbird's chat, voice and video APIs and SDKs connect users through immersive, modern communication solutions...",
        "image": "https://6cro14eml0v2yuvyx3v5j11j-wpengine.netdna-ssl.com/wp-content/uploads/sendbird_thumbnail.png"
    }
}
```

### Receive system messages

Admin messages are customizable messages that are sent by the system, and there are 2 types of admin messages. **Notifications** are messages that are sent and displayed to both customers and agents, such as welcome messages or delay messages. **System messages** are messages sent and displayed to agents in the **Ticket details view** when a ticket has some changes, such as changes in ticket status and assignee.

> **Note**: You can customize notifications in **Desk** > **Settings** > **Triggers**, and system messages in **Desk** > **Settings** > **System messages** in your dashboard.

When the client app receives the message through the `channel(_ sender:SBDBaseChannel, didReceive message: SBDBaseMessage)` method of the `SBDChannelDelegate`, system messages are distinguished from notification messages by the value of the `message.custom_type`, and their subtype is specified in the `message.data` as below.

```json
{
    "message_id": 40620745,
    "type": "ADMM",
    "custom_type": "SENDBIRD_DESK_ADMIN_MESSAGE_CUSTOM_TYPE",
    "data": "{\"type\": \"SYSTEM_MESSAGE_TICKET_ASSIGNED_BY_SYSTEM\", \"ticket\": <Ticket Object>}",
    "message": "The ticket is automatically assigned to Cindy."
}
```

> **Note**: The `transfer` appears only when the `data` has `SYSTEM_MESSAGE_TICKET_TRANSFERRED_BY_AGENT`.

System messages are intended to be displayed for agents only. Refer to the following sample code to avoid displaying them to your customers.

```swift
public static func isVisible(message: SBDBaseMessage) -> Bool {
    if let message = message as? SBDAdminMessage, let data = Data(base64Encoded: message.data), data.isEmpty == false {
        let isSystemMessage = (message.customType == "ADMIN_MESSAGE_CUSTOM_TYPE")
            
        let dataObject = try? JSONSerialization.jsonObject(with: data, options: []) as? [String: Any]
        let type = dataObject?["type"] as? String
        return !isSystemMessage && 
            type != EVENT_TYPE_ASSIGN &&
            type != EVENT_TYPE_TRANSFER &&
            type != EVENT_TYPE_CLOSE
    }
    
    return true
}
```

### Request confirmation to close a ticket

While admins have permission to directly close a ticket, agents can either close a ticket as admins do or ask customers whether to close a ticket, depending on the agent permission setting. The confirmation request message can have 3 types of state as below.

|State|Description|
|---|---|
|WAITING |Set when an agent sends a confirmation request message. |
|CONFIRMED| Set when a customer agrees to close the ticket. (Default: **true**)|
|DECLINED |Set when a customer declines to close the ticket. (Default: **false**)|

When a customer replies to the message, the response true (agree) or false (decline) is sent to the Desk server as `CONFIRMED` or `DECLINED` by calling the `SBDSKTicket.confirmEndOfChat()` method.

```swift
SBDSKTicket.confirmEndOfChat(with: USER_MESSAGE, confirm: true|false) { (ticket, error) in
    guard error == nil else {   // Error.
        return 
    }
            
    // You can update the UI of the message. For example, you can hide YES and NO buttons. 
}
```

Sendbird server notifies the customer’s client app of updates through the `channel(_ sender: SBDBaseChannel, didUpdate message: SBDBaseMessage)` method of `SBDChannelDelegate`.

```swift
func channel(_ sender: SBDBaseChannel, didUpdate message: SBDBaseMessage) {
    SBDSKTicket.getByChannelUrl(sender.channelUrl) { (ticket, error) in
        guard error == nil else {   // Error
            return 
        }
        
        if let data = Data(base64Encoded: message.data), data.isEmpty == false {
            let dataObject = try? JSONSerialization.jsonObject(with: data, options: []) as? [String: Any]
            let type = dataObject?["type"] as? String
            
            let isClosureInquired = (type == "SENDBIRD_DESK_INQUIRE_TICKET_CLOSURE")
            if isClosureInquired {
                let closureInquiry = dataObject?["body"] as? [String: Any]
                let state = closureInquiry?["state"] as? String
                
                switch state {
                    case "CONFIRMED":
                    // TODO: Implement your code for the UI when the customer confirms to close the ticket.
                    case "DECLINED":
                    // TODO: Implement your code for the UI when the customer declines to close the ticket.
                    case "WAITING":
                    // TODO: Implement your code for the UI when there is no response from the customer.
                    default: break
                }
            }
        }
    }
}
```

> **Note**: You can find the stringified `JSON` object of the following in the `message.data` property within the `channel(_ sender: SBDBaseChannel, didUpdate message: SBDBaseMessage)` delegate method of the `SBDChannelDelegate`.

```json
{
    "type": "SENDBIRD_DESK_INQUIRE_TICKET_CLOSURE",
    "body": {
        "state": "CONFIRMED"
    }
}
```
 
### Request customer feedback

You can send a message to customers right after closing a ticket to ask whether they are satisfied with the support provided through the ticket. When the **Customer satisfaction rating** feature is turned on in your dashboard, customers will get a message asking to give a score and leave a comment as feedback. The message can have 2 states as below.

|State|Description|
|---|---|
|WAITING|Set when an agent sends a customer feedback request message.|
|CONFIRMED|Set when a customer sends a response.|

When a customer replies to the message, the score and comment are sent to the Desk server by calling the `ticket.submitFeedback()` method. Then, the state of the confirmation request message is changed to `CONFIRMED`.

```swift
ticket.submitFeedback(with: USER_MESSAGE, score: SCORE, comment: COMMENT) { (ticket, error) in
    guard error == nil else {   // Error.
        return 
    }
    ...
}
```

Sendbird Desk server notifies the customer’s client app of updates through the `channel(_ sender: SBDBaseChannel, didUpdate message: SBDBaseMessage)` delegate method of the `SBDChannelDelegate`.

```swift
func channel(_ sender: SBDBaseChannel, didUpdate message: SBDBaseMessage) {
    SBDSKTicket.getByChannelUrl(sender.channelUrl) { (ticket, error) in
        guard error == nil else {   // Error.
            return 
        }
                
        if let data = Data(base64Encoded: message.data), data.isEmpty == false {
            let dataObject = try? JSONSerialization.jsonObject(with: data, options: []) as? [String: Any]
            let type = dataObject?["type"] as? String
                    
            let isFeedbackMessage = (type == "SENDBIRD_DESK_CUSTOMER_SATISFACTION")
            if isFeedbackMessage {
                let closureInquiry = dataObject?["body"] as? [String: Any]
                let state = closureInquiry?["state"] as? String
                        
                switch state {
                    case "CONFIRMED":
                    // TODO: Implement your code for the UI when there is a response from the customer.
                    case "WAITING":
                    // TODO: Implement your code for the UI when there is no response from the customer.
                    default: break
                }
            }
        }
    }
}
```

> **Note**: You can find the stringified `JSON` object of the following in the `message.data` property within the `channel(_ sender: SBDBaseChannel, didUpdate message: SBDBaseMessage)` delegate method of `SBDChannelDelegate`.

```json
{
    "type": "SENDBIRD_DESK_CUSTOMER_SATISFACTION",
    "body": {
        "state": "CONFIRMED",
        "customerSatisfactionScore": 3,
        "customerSatisfactionComment": "It was really helpful :)"
    }
}
```

### Reopen a closed ticket

A closed ticket can be reopened by using the ‘ticket.reopen()’ method.

```swift
ticket.reopen { (ticket, error) in
    guard error == nil else {   // Error.
        return 
    }
    ...

}
```

### Retrieve a list of tickets

You can retrieve a list of the current customer’s open and closed tickets by using the `SBDSKTicket.getOpenedList()` and `SBDSKTicket.getClosedList()`.

> **Note**: Only 10 tickets can be retrieved per request by message creation time in descending order.

```swift
// getOpenedList()
SBDSKTicket.getOpenedList(withOffset: OFFSET) { (tickets, hasNext, error) in
    guard error == nil else {   // Error. 
        return 
    }
            
    // offset += tickets.size(); for the next tickets.
    // TODO: Implement your code to display the ticket list.
}
```

```swift
// getClosedList() 
SBDSKTicket.getClosedList(withOffset: OFFSET) { (tickets, hasNext, error) in
    guard error == nil else {   // Error.
        return 
    }
            
    // offset += tickets.size(); for the next tickets.
    // TODO: Implement your code to display the ticket list.
}
```

For tickets set with custom fields, you can add a filter to the `getOpenList()` and `getClosedList()` to sort tickets by keys and values of custom fields.

```swift
let customFieldFilter = ["subject": "doggy_doggy"]

SBDSKTicket.getOpenedList(withOffset: OFFSET, customFieldFilter: CUSTOM_FIELD_FILTER) { (tickets, hasNext, error) in
    guard error == nil else {   // Error.
        return
    }

    // offset += tickets.length; for the next tickets.
    // TODO: Implement your code to display the ticket list.
}
```

### Retrieve a ticket

You can retrieve a specific ticket with its channel URL.

```swift
SBDSKTicket.getByChannelUrl(channel.channelUrl) { (ticket, error) in
    guard error == nil else {   // Error.
        return
    }
    ...
}
```

### Display open ticket count

You can display the number of open tickets on your client app by using the `SBDSKTicket.getOpenCount()`.

```swift
SBDSKTicket.getOpenCount { (count, error) in
    guard error == nil else {   // Error.
        return 
    }
            
    // TODO: Implement your code with the result vale.
}
```
