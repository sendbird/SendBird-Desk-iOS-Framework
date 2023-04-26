# Change Log

### v1.1.3 (Apr 26, 2023) with Chat SDK **v4.6.7**
* Update iOS deployment target to 11.0 for Xcode 14.1+

### v1.1.2 (Feb 3, 2023)
* Added status2 features
    * Added `SBDSKTicket.Constants.Status2` constants
    * Added `status2` property in `SBDSKTicket` class
    * Added `getAllTicketList(offset:customFieldFilter:completionHandler:)` function in `SBDSKTicket` class
    * Added `getTicketList(offset:customFieldFilter:status2:completionHandler:)` function in `SBDSKTicket` class

### v1.1.1 (Nov 11, 2022)
* Fixed bug that refreshed ticket has no channel
* Improved stabilities

### v1.1.0 (Sep 2, 2022) with Chat SDK **v4.0.9**
* Raised minimum dependency version of `SendbirdChatSDK` to `4.0.9`
  * Modified handlers' error parameter type to `SBError`
  * (*Swift only*) Modified channel parameter type to `BaseChannel` in `SBDSKMain isDeskChannel(_:)`
  * (*Swift only*) Modified user message parameter type to `UserMessage` in `SBDSKTicket submitFeedback(with:score:)`
  * (*Swift only*) Modified message parameter type to `BaseMessage` in `SBDSKAdminMessage isAdminMesasge(_:)`
  
### v1.0.18 (Jun 30, 2022)
* Updated podspec to set dependency to SendbirdChatSDK as “up to next major version”

### v1.0.17 (Apr 28, 2022)
* Raised minimum target of iOS to `9.0`.
* Raised minimum dependency version of `SendBirdSDK` to `3.0.221`. 
* Deprecated interfaces
  * Renamed `SBDSKMain.getSdkVersion()` to `SBDSKMain.getSDKVersion()`
  * (*Swift only*) Renamed first parameters of public interfaces in `SBDSKTicket`
* Stability improvements.

### v1.0.16 (Jun 1, 2021)
* `SBDSKTicket.cancel(transferGroupKey:completionHandler:)` has been replaced by `SBDSKTicket.cancel(groupKeyForTransfer:completionHandler:)`.

### v1.0.15 (May 21, 2021)
* Migrated SDK language to Swift.
* Added support for XCFramework
* Raised minimum dependency version of `SendBirdSDK` to `3.0.200`.

### v1.0.14 (May 21, 2021)
* Added supports for BotKey.
    * Added option to specify botKey when creating `SBDSKTicket`.
* Added `SBDSKTicket.cancel(transferGroupKey:completionHandler:)`.
* Added support for FAQ.
    * Added `SBDSKTicket.selectQuestion(faqFileId:question:completionHandler:)`.
    * Added `SBDSKFAQData` and `SBDSKFAQResult`.

### v1.0.13 (Feb 26, 2021) 
* Improved handling of error code. 

### v1.0.12 (Dec 2, 2020) 
* Stability improvements 

### v1.0.11 (Nov 25, 2020)
* Added `closeWithComment:completionHandler:` to `SBDSKTicket`. 

### v1.0.10 (Oct 22, 2020)
* Minor bugfix

### v1.0.9 (Aug 20, 2020)
* Improved handling of error code and error messages on API failure.

### v1.0.8 (Jul 13, 2020)
* Fixed - Problems adding null pointers to an array object.

### v1.0.7 (Apr 28, 2020)
* Added `relatedChannels` in `SBDSKTicket`.
    * Added `createTicketWithTitle:userName:relatedChannels:completionHandler:` and `createTicketWithTitle:userName:groupKey:customFields:priority:relatedChannels:completionHandler:`. 
* Added `SBDSKRelatedChannel` type.
* Added `setRelatedChannels:completionHandler:` in `SBDSKTicket`.

### v1.0.6 (Jan 3, 2020)
* Added `setCustomFields:completionHandler:` in `SBDSKTicket` class.
* Added `priority` type in Ticket
  * Added `createTicketWithTitle:userName:priority:completionHandler:` and `createTicketWithTitle:userName:groupKey:customFields:priority:completionHandler:` in `SBDSKTicket` class.
  * Added `setPriority:completionHandler:` in `SBDSKTicket` class.

### v1.0.5 (Aug 27, 2019)
* Added a method to set custom fields of the current customer.
* Added a method to submit feedback.

### v1.0.4 (Jul 11, 2019)
* Added `customFields` in `SBDSKTicket`.

### v1.0.3(May 13, 2019)
* Added `reopenWithCompletionHandler:` in `SBDSKTicket` class.
* Added `createTicketWithTitle:userName:groupKey:customField:completionHandler:` in `SBDSKTicket` class.
* Added `getOpenedListWithOffset:customFieldFilter:completionHandler:` in `SBDSKTicket` class.
* Added `getClosedListWithOffset:customFieldFilter:completionHandler:` in `SBDSKTicket` class.

### v1.0.2(Mar 30, 2018)
* Support SendBird Desk standalone.

### v1.0.1(Mar 20, 2018)
* Minor bug fix.

### v0.9.9(Aug 1, 2017)
* First release.
