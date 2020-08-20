# Change Log

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
