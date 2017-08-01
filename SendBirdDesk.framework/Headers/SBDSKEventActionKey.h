//
//  SBDSKEventActionKey.h
//  SendBirdDesk
//
//  Created by Jed Gyeong on 7/11/17.
//  Copyright © 2017 SendBird. All rights reserved.
//

#ifndef SBDSKEventActionKey_h
#define SBDSKEventActionKey_h

#define SBDSK_CHAT_ENTER @"CHAT_ENTER" // { title: NSString, status: NSString, ticket_id: NSString }
#define SBDSK_CHAT_SEND_USER_MESSAGE @"CHAT_SEND_USER_MESSAGE"   // { message: NSString }
#define SBDSK_CHAT_ATTACH_FILE @"CHAT_ATTACH_FILE"   // { file_name: NSString, file_size: NSString, mime_type: NSString }
#define SBDSK_CHAT_DOWNLOAD_AGENT_FILE @"CHAT_DOWNLOAD_AGENT_FILE"   // { file_name: NSString, url: NSString }
#define SBDSK_CHAT_CONFIRM_END_OF_CHAT @"CHAT_CONFIRM_END_OF_CHAT"   // { choice: @"yes" or @"no" }
#define SBDSK_CHAT_CLOSE_ALL @"CHAT_CLOSE_ALL"
#define SBDSK_CHAT_EXIT @"CHAT_EXIT"

#define SBDSK_WEB_VIEWER_ENTER @"WEB_VIEWER_ENTER"   // { url: NSString }
#define SBDSK_WEB_VIEWER_RELOAD @"WEB_VIEWER_RELOAD"
#define SBDSK_WEB_VIEWER_EXIT @"WEB_VIEWER_EXIT"

#define SBDSK_PHOTO_VIEWER_ENTER @"PHOTO_VIEWER_ENTER"   // { file_name: NSString, file_size: NSString, mime_type: NSString }
#define SBDSK_PHOTO_VIEWER_DOWNLOAD_FILE @"PHOTO_VIEWER_DOWNLOAD_FILE"   // { file_name: NSString, url: NSString }
#define SBDSK_PHOTO_VIEWER_EXIT @"PHOTO_VIEWER_EXIT"

#define SBDSK_VIDEO_PLAYER_ENTER @"VIDEO_PLAYER_ENTER"  // { file_name: NSString, file_size: NSString, mime_type: NSString }

#define SBDSK_OPEN_GENERAL_FILE_VIEWER @"OPEN_GENERAL_FILE_VIEWER" // { file_name: NSString, file_size: NSString, mime_type: NSString }

#define SBDSK_INBOX_ENTER @"INBOX_ENTER"
#define SBDSK_INBOX_OPEN_TAB_SELECTED @"INBOX_OPEN_TAB_SELECTED"
#define SBDSK_INBOX_CLOSE_TAB_SELECTED @"INBOX_CLOSE_TAB_SELECTED"
#define SBDSK_INBOX_OPEN_TICKET_SELECTED @"INBOX_OPEN_TICKET_SELECTED"  // { title: NSString, status: NSString, ticket_id: NSString }
#define SBDSK_INBOX_CLOSE_TICKET_SELECTED @"INBOX_CLOSE_TICKET_SELECTED"   // { title: NSString, status: NSString, ticket_id: NSString }
#define SBDSK_INBOX_MOVE_TO_SETTINGS @"INBOX_MOVE_TO_SETTINGS"
#define SBDSK_INBOX_CLOSE_ALL @"INBOX_CLOSE_ALL"

#define SBDSK_SETTINGS_ENTER @"SETTINGS_ENTER"
#define SBDSK_SETTINGS_PUSH_ON @"SETTINGS_PUSH_ON"
#define SBDSK_SETTINGS_PUSH_OFF @"SETTINGS_PUSH_OFF"
#define SBDSK_SETTINGS_CLOSE_ALL @"SETTINGS_CLOSE_ALL"
#define SBDSK_SETTINGS_EXIT @"SETTINGS_EXIT"
#define SBDSK_SETTINGS_CLEAR_ALL_FILE @"SETTINGS_CLEAR_ALL_FILE"

#endif /* SBDSKEventActionKey_h */
