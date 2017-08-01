SendBird Desk SDK Integration Guide for iOS
===========
SendBird Desk is the Zendesk-integrated chat customer service platform built on SendBird SDK and API.

Desk iOS SDK provides customer-side integration on your own application, so you can easily implement customers' **chat inquiry, inquiries inbox with UI theming**. Desk iOS SDK requires devices running **iOS 8.0 or higher** and **SendBird iOS SDK 3.0.61 or higher**.

## Table of Contents

  1. [Installation](#installation)
  1. [Initialization](#initialization)
  1. [Creating a new ticket](#creating-a-new-ticket)
  1. [Loading inbox](#loading-inbox)
  1. [Receiving events](#receiving-events)
  
## Installation

First of all, you need SendBird App ID to start (It can be created on [SendBird Dashboard](https://dashboard.sendbird.com), but for Desk usage, you may need upgrade.), so please contact [desk@sendbird.com](mailto:desk@sendbird.com) if you want one.

1. Create or edit your `Podfile`

```
# Uncomment the next line to define a global platform for your project
platform :ios, '8.0'

target 'YOUR_PROJECT' do
  # Uncomment the next line if you're using Swift or would like to use dynamic frameworks
  use_frameworks!

  # Pods for SendBird Desk
  pod 'SendBirdDesk', :git => 'https://github.com/smilefam/SendBird-Desk-iOS-Framework.git'
end
```
2. Run `pod install`.
3. Open `YOUR_PROJECT.xcworkspace`.

## Initialization

Invoke `+ (void)initWithApplicationId:(NSString * _Nonnull)applicationId` of `SBDSKMain` with your SendBird App ID before you use other features on SendBird Desk SDK.
```objc
#import <SendBirdDesk/SendBirdDesk.h>

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // ...

    [SBDSKMain initWithApplicationId:@"APP_ID"];

    // ...
}
```

> Calling `+ (void)initWithApplicationId:(NSString * _Nonnull)applicationId` on `- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(nullable NSDictionary *)launchOptions` is highly recommended.

> You can use SendBird SDK with SendBird Desk SDK (for example, when you want to build your own messenger and also use Desk service together on your application.). In that case, you must use **the same APP_ID** for both SDK (`+ (void)initWithApplicationId:(NSString * _Nonnull)applicationId` is not necessary, `+ (void)initWithApplicationId:(NSString * _Nonnull)applicationId` is sufficient because it calls `+ (void)initWithApplicationId:(NSString * _Nonnull)applicationId` inside). And please note that SendBird SDK version must be 3.0.61 or higher to work with Desk SDK.

You should prepare APNS and local notification settings too. On your `AppDelegate`, add the following lines.
```objc
#import <SendBirdDesk/SendBirdDesk.h>

- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken {
    // ...

    [SBDMain registerDevicePushToken:deviceToken unique:YES completionHandler:^(SBDPushTokenRegistrationStatus status, SBDError * _Nullable error) {
        if (error == nil) {
            if (status == SBDPushTokenRegistrationStatusPending) {
                NSLog(@"Push registration is pending.");
            }
            else {
                NSLog(@"APNS Token is registered.");
            }
        }
        else {
            NSLog(@"APNS registration failed.");
        }
    }];

    // ...
}

- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo {
    // iOS 9 and earlier for remote notification
    if (userInfo[@"sendbird"] != nil) {
        [SBDSKMain startChattingByPushNotification:response.notification.request.content.userInfo userId:USER_ID nickname:USER_NAME accessToken:nil];
    }
}

- (void)userNotificationCenter:(UNUserNotificationCenter *)center willPresentNotification:(UNNotification *)notification withCompletionHandler:(void (^)(UNNotificationPresentationOptions options))completionHandler{
    // iOS 10 and later for local notification.
    completionHandler(UNNotificationPresentationOptionAlert | UNNotificationPresentationOptionSound);
}

- (void)userNotificationCenter:(UNUserNotificationCenter *)center didReceiveNotificationResponse:(UNNotificationResponse *)response withCompletionHandler:(void(^)())completionHandler {
    // iOS 10 and later for remote and local notification
    if ([response.notification.request.content.categoryIdentifier isEqualToString:@"SBDSK_NEW_MESSAGE"]) {
        // For local notification
        [SBDSKMain startChattingByPushNotification:response.notification.request.content.userInfo userId:USER_ID nickname:USER_NAME accessToken:nil];
    }
    else {
        // For remote notification
        if (response.notification.request.content.userInfo[@"sendbird"] != nil) {
            [SBDSKMain startChattingByPushNotification:response.notification.request.content.userInfo userId:USER_ID nickname:USER_NAME accessToken:nil];
        }
    }
    completionHandler();
}
```

By just calling `+ (void)startChattingByPushNotification:(NSDictionary * _Nonnull)pushInfo userId:(NSString * _Nonnull)userId nickname:(NSString * _Nullable)nickname accessToken:(NSString * _Nullable)accessToken`, Desk SDK will build and pop-up notification from Desk messages for you.

After init, connect a user to SendBird's server using **User ID**. This part is fully described on [SendBird SDK guide docs](https://docs.sendbird.com/ios#authentication_3_connecting_with_userid), and you can think of this process as a pre-step for Desk SDK, for it is built on SendBird SDK. Below is the code snippet which can be found on Desk sample to show you what can be done after connection.
```objc
[SBDMain connectWithUserId:USER_ID accessToken:nil completionHandler:^(SBDUser * _Nullable user, SBDError * _Nullable error) {
    if (error != nil) {    
        return;
    }
    
    [SBDMain updateCurrentUserInfoWithNickname:USER_NAME profileUrl:@"" completionHandler:^(SBDError * _Nullable error) {
        if (error != nil) {
            return;
        }
    }];
    
    if ([SBDMain getPendingPushToken] != nil) {
        [SBDMain registerDevicePushToken:[SBDMain getPendingPushToken] unique:YES completionHandler:^(SBDPushTokenRegistrationStatus status, SBDError * _Nullable error) {
            if (error != nil) {
                return;
            }
        }];
    }
}]; 
```
  
Now your customers are ready to create chat tickets and start inquiry with your agents!

## Creating a new ticket

Creating a new ticket is as simple as just calling `+ (void)startChattingWithTitle:(NSString * _Nullable)title info:(NSString * _Nullable)info`. Ticket title and custom information can be passed at the same time.
Currently, at this Zendesk integration version, you can set custom information as Zendesk ticket object you want to create at agent side.
```objc
NSDictionary *info = @{
                       @"ticket": @{
                               @"requester": @{
                                       @"name": USER_NAME,
                                       @"email": USER_ID,
                                       },
                               @"subject": YOUR_TICKET_TITLE,
                               @"comment": @{
                                       @"body": COMMENT_TO_DISPLAY_ON_ZENDESK_TICKET,
                                       },
                               @"tags": @[@"sendbird"],
                               },
                       @"priority": @"urgent",
                       };

[SBDSKMain startChattingWithTitle:subject info:info];
```

## Loading inbox
Inbox displays all the open tickets and closed ticket history for the customer.
Customers can move to inbox from chat screen by touching menu on top bar, but you can also directly let customers go to inbox in your application by calling
```objc
[SBDSKMain startInbox];
```

## Receiving events
You may want to gather your customers action to your own funnel analysis tools.
All customers action like text sending, file sending or menu touching will be called back on `SendBirdDesk.EventListener` so you can utilize it.
```objc
// In ViewController.h
#import <SendBirdDesk/SendBirdDesk.h>

@interface ViewController : UIViewController<SBDSKEventDelegate>

// ...

@end
```

```objc
// In ViewController.m

@implementation ViewController

#pragma mark - SBDSKEventDelegate
- (void)onEventWithActionKey:(NSString *)actionKey metaData:(NSDictionary *)metaData {
    // Send to your own funnel analysis tools.
}
```

@end

The actions and data you can track at the moment are belows.

|Action|Data|Description|
| -- | -- | -- |
|CHAT_ENTER|title, status, ticket_id|User enters chat screen|
|CHAT_SEND_USER_MESSAGE|message|User sends text message|
|CHAT_ATTACH_FILE|file_name, file_size, mime_type|User attaches file message|
|CHAT_DOWNLOAD_AGENT_FILE|file_name, url|User downloads file message from agents|
|CHAT_CONFIRM_END_OF_CHAT|choice|User confirms end of chat from agents inquiry|
|CHAT_CLOSE_ALL|-|User closes screen by touching X button on toolbar of chat|
|CHAT_EXIT|-|User exits chat screen|
|WEB_VIEWER_ENTER|url|User enters web viewer|
|WEB_VIEWER_RELOAD|-|User touches reload button of web viewer|
|WEB_VIEWER_EXIT|-|User exits web viewer|
|PHOTO_VIEWER_ENTER|file_name, file_size, mime_type|User enters photo viewer|
|PHOTO_VIEWER_DOWNLOAD_FILE|file_name, url|User downloads file from photo viewer|
|PHOTO_VIEWER_EXIT|-|User exits photo viewer|
|VIDEO_PLAYER_ENTER|file_name, file_size, mime_type|User enters video player|
|OPEN_GENERAL_FILE_VIEWER|file_name, file_size, mime_type|User opens general file|
|INBOX_ENTER|-|User enters inbox|
|INBOX_OPEN_TAB_SELECTED|-|User selects open tickets tab|
|INBOX_CLOSE_TAB_SELECTED|-|User selects closed tickets tab|
|INBOX_OPEN_TICKET_SELECTED|title, status, ticket_id|User selects an open ticket|
|INBOX_CLOSE_TICKET_SELECTED|title, status, ticket_id|User selects a closed ticket|
|INBOX_MOVE_TO_SETTINGS|-|User touches settings button on toolbar of inbox|
|INBOX_CLOSE_ALL|-|User closes screen by touching X button on toolbar of inbox|
|SETTINGS_ENTER|-|User enters settings|
|SETTINGS_PUSH_ON|-|User sets on push notification|
|SETTINGS_PUSH_OFF|-|User sets off push notification|
|SETTINGS_CLOSE_ALL|-|User closes screen by touching X button on toolbar of settings|
|SETTINGS_EXIT|-|User exits settings|
|SETTINGS_CLEAR_ALL_FILE|-|User removes all downloaded files|

















## 1. Install required frameworks via CocoaPods.
1. Create or edit your `Podfile`

```
# Uncomment the next line to define a global platform for your project
platform :ios, '8.0'

target 'SendBirdDeskSample' do
  # Uncomment the next line if you're using Swift or would like to use dynamic frameworks
  use_frameworks!

  # Pods for SendBirdDeskSample
  pod 'SendBirdSDK'
  pod 'AFNetworking'
  pod 'FLAnimatedImage'
  pod 'NYTPhotoViewer'
  pod 'TOCropViewController'

end
```
2. Run `pod install`.
3. Open `YOUR_PROJECT.xcworkspace`.


## 2. Install SendBirdDesk framework manually
* Add `UserNotifications.framework` to `Linked Frameworks and Libraries`.
* Add `SendBirdDesk.framework` to `Embedded Binaries`.

## 3. Add script to Build Phases for AppStore.
1. Click `+` button.
2. Select `New Run Script Phase`
3. Enter `/usr/local/bin/carthage copy-frameworks` in text box.


**[`Carthage`](https://github.com/Carthage/Carthage) is required. Refer to [a guide for universal framework](https://github.com/Carthage/Carthage#if-youre-building-for-ios-tvos-or-watchos).**

## 4. Info.plist
* Add `App Transport Security Settings` and `Allow Arbitary Loads` as `YES`.
* Add `Privacy - Camera Usage Description` and write description to value field.
* Add `Privacy - Photo Library Usage Description` and write description to value field.
* Add `Privacy - Microphone Usage Description` and write description to value field.

## 5. Set default agent image and name.
1. Open `SBDSKTheme.plist`.
2. Set the default image asset name to `Root > DefaultAgent > DefaultAgentImage`. The image asset has to be accessed by bundle that `+ (void)setTheme:(NSString * _Nonnull)themeFile bundle:(NSBundle * _Nonnull)bundle` of `SBDSKMain` method has.
3. Set the default agent name to `Root > DefaultAgent > DefaultAgentName`.
