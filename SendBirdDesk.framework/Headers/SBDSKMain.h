//
//  SBDSKMain.h
//  SendBirdDesk
//
//  Created by Jed Gyeong on 4/17/17.
//  Copyright © 2017 SendBird. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SendBirdSDK/SendBirdSDK.h>

#import "SBDSKTypes.h"
#import "SBDSKTicket.h"

@protocol SBDSKEventDelegate <NSObject>

@optional
- (void)onEventWithActionKey:(NSString * _Nonnull)actionKey metaData:(NSDictionary<NSString *, NSString *> * _Nullable)metaData;

@end

@interface SBDSKMain : NSObject<SBDChannelDelegate>

@property (atomic) SBDSKLogLevel logLevel;

// DefaultAgent
@property (strong, nonatomic, readonly, nullable) UIImage *defaultAgentImage;
@property (strong, nonatomic, readonly, nullable) NSString *defaultAgentName;

// NavigationBar
@property (strong, nonatomic, readonly, nullable) UIColor *navigationBarBottomLineColor;
@property (strong, nonatomic, readonly, nullable) UIColor *navigationBarBackgroundColor;
@property (strong, nonatomic, readonly, nullable) NSDictionary *navigationBarTitleAttribute;
@property (strong, nonatomic, readonly, nullable) NSDictionary *navigationBarButtonAttribute;
@property (strong, nonatomic, readonly, nullable) UIImage *navigationBarBackButtonImage;
@property (strong, nonatomic, readonly, nullable) UIImage *navigationBarCloseButtonImage;
@property (strong, nonatomic, readonly, nullable) UIImage *navigationBarSettingsButtonImage;
@property (strong, nonatomic, readonly, nullable) UIImage *navigationBarInboxButtonImage;

// ChatMessage
@property (strong, nonatomic, readonly, nullable) UIColor *messageInputTextViewCursorColor;
@property (strong, nonatomic, readonly, nullable) UIColor *messageInputAreaTopLineColor;
@property (atomic, readonly) CGFloat messageInputAreaTopLineWidth;
@property (strong, nonatomic, readonly, nullable) UIColor *messageInputAreaBackgroundColor;
@property (atomic, readonly) CGFloat messageInputTextViewActiveBorderWidth;
@property (strong, nonatomic, readonly, nullable) UIColor *messageInputTextViewActiveBorderColor;
@property (strong, nonatomic, readonly, nullable) UIColor *messageInputTextViewActiveBackgroundColor;
@property (atomic, readonly) CGFloat messageInputTextViewStandbyBorderWidth;
@property (strong, nonatomic, readonly, nullable) UIColor *messageInputTextViewStandbyBorderColor;
@property (strong, nonatomic, readonly, nullable) UIColor *messageInputTextViewStandbyBackgroundColor;
@property (strong, nonatomic, readonly, nullable) NSDictionary *messageInputTextViewPlaceholderAttribute;
@property (strong, nonatomic, readonly, nullable) UIFont *messageInputTextViewFont;
@property (strong, nonatomic, readonly, nullable) UIColor *messageInputTextViewFontColor;
@property (atomic, readonly) CGFloat messageInputTextViewTopPadding;
@property (atomic, readonly) CGFloat messageInputTextViewBottomPadding;
@property (strong, nonatomic, readonly, nullable) UIImage *messageSendButtonOnImage;
@property (strong, nonatomic, readonly, nullable) UIImage *messageSendButtonOffImage;
@property (strong, nonatomic, readonly, nullable) UIImage *messageFileAttachButtonImage;

@property (strong, nonatomic, readonly, nullable) UIColor *chattingViewBackgroundColor;
@property (strong, nonatomic, readonly, nullable) UIImage *chattingViewBackgroundImage;
@property (strong, nonatomic, readonly, nullable) UIColor *chattingMessageLoadingIndicatorColor;
@property (strong, nonatomic, readonly, nullable) NSDictionary *dateDividerLabelAttribute;
@property (atomic, readonly) CGFloat dateDividerLabelHeight;

//// AdminMessage
@property (atomic, readonly) CGFloat adminMessageBorderWidth;
@property (strong, nonatomic, readonly, nullable) UIColor *adminMessageBackgroundColor;
@property (strong, nonatomic, readonly, nullable) UIColor *adminMessageBorderColor;
@property (strong, nonatomic, readonly, nullable) NSDictionary *adminMessageTextViewAttribute;
@property (strong, nonatomic, readonly, nullable) NSDictionary *adminMessageDateLabelAttribute;
@property (atomic, readonly) CGFloat adminMessageDateLabelHeight;

//// AdminCannedMessage
@property (atomic, readonly) CGFloat incomingInquireCloseTicketMessageBorderWidth;
@property (strong, nonatomic, readonly, nullable) UIColor *incomingInquireCloseTicketMessageBackgroundColor;
@property (strong, nonatomic, readonly, nullable) UIColor *incomingInquireCloseTicketMessageBorderColor;
@property (strong, nonatomic, readonly, nullable) NSDictionary *incomingInquireCloseTicketMessageTextViewAttribute;
@property (atomic, readonly) CGFloat incomingInquireCloseTicketMessageYesButtonBorderWidth;
@property (strong, nonatomic, readonly, nullable) UIColor *incomingInquireCloseTicketMessageYesButtonBorderColor;
@property (strong, nonatomic, readonly, nullable) UIColor *incomingInquireCloseTicketMessageYesButtonBackgroundColor;
@property (strong, nonatomic, readonly, nullable) UIColor *incomingInquireCloseTicketMessageYesButtonDisableBackgroundColor;
@property (strong, nonatomic, readonly, nullable) UIColor *incomingInquireCloseTicketMessageYesButtonFontColor;
@property (strong, nonatomic, readonly, nullable) UIFont *incomingInquireCloseTicketMessageYesButtonFont;
@property (atomic, readonly) CGFloat incomingInquireCloseTicketMessageNoButtonBorderWidth;
@property (strong, nonatomic, readonly, nullable) UIColor *incomingInquireCloseTicketMessageNoButtonBorderColor;
@property (strong, nonatomic, readonly, nullable) UIColor *incomingInquireCloseTicketMessageNoButtonBackgroundColor;
@property (strong, nonatomic, readonly, nullable) UIColor *incomingInquireCloseTicketMessageNoButtonDisableBackgroundColor;
@property (strong, nonatomic, readonly, nullable) UIColor *incomingInquireCloseTicketMessageNoButtonFontColor;
@property (strong, nonatomic, readonly, nullable) UIFont *incomingInquireCloseTicketMessageNoButtonFont;

//// OutgoingUserMessage
@property (atomic, readonly) CGFloat outgoingUserMessageBorderWidth;
@property (strong, nonatomic, readonly, nullable) UIColor *outgoingUserMessageBackgroundColor;
@property (strong, nonatomic, readonly, nullable) UIColor *outgoingUserMessageBorderColor;
@property (strong, nonatomic, readonly, nullable) NSDictionary *outgoingUserMessageTextViewAttribute;
@property (strong, nonatomic, readonly, nullable) UIColor *outgoingUserMessageTextViewLinkFontColor;
@property (strong, nonatomic, readonly, nullable) NSDictionary *outgoingUserMessageDateLabelAttribute;
@property (atomic, readonly) CGFloat outgoingUserMessageDateLabelHeight;
@property (strong, nonatomic, readonly, nullable) NSDictionary *outgoingUserMessageStatusLabelAttribute;

//// Outgoing URL Preview
@property (strong, nonatomic, readonly, nullable) NSDictionary *outgoingUrlPreviewTitleLabelAttribute;
@property (strong, nonatomic, readonly, nullable) NSDictionary *outgoingUrlPreviewDomainLabelAttribute;

//// OutgoingImageFileMessage
@property (atomic, readonly) CGFloat outgoingImageFileMessageBorderWidth;
@property (strong, nonatomic, readonly, nullable) UIColor *outgoingImageFileMessageBorderColor;
@property (strong, nonatomic, readonly, nullable) UIColor *outgoingImageFileMessageDateBackgroundColor;
@property (atomic, readonly) CGFloat outgoingImageFileMessageDateBackgroundOpacity;
@property (strong, nonatomic, readonly, nullable) NSDictionary *outgoingImageFileMessageDateLabelAttribute;
@property (atomic, readonly) CGFloat outgoingImageFileMessageDateLabelHeight;
@property (strong, nonatomic, readonly, nullable) NSDictionary *outgoingImageFileMessageStatusLabelAttribute;

//// OutgoingVideoFileMessage
@property (atomic, readonly) CGFloat outgoingVideoFileMessageBorderWidth;
@property (strong, nonatomic, readonly, nullable) UIColor *outgoingVideoFileMessageBorderColor;
@property (strong, nonatomic, readonly, nullable) UIColor *outgoingVideoFileMessageDateBackgroundColor;
@property (atomic, readonly) CGFloat outgoingVideoFileMessageDateBackgroundOpacity;
@property (strong, nonatomic, readonly, nullable) NSDictionary *outgoingVideoFileMessageDateLabelAttribute;
@property (atomic, readonly) CGFloat outgoingVideoFileMessageDateLabelHeight;
@property (strong, nonatomic, readonly, nullable) NSDictionary *outgoingVideoFileMessageStatusLabelAttribute;

//// OutgoingGeneralFileMessage
@property (atomic, readonly) CGFloat outgoingGeneralFileMessageBorderWidth;
@property (strong, nonatomic, readonly, nullable) UIColor *outgoingGeneralFileMessageBorderColor;
@property (strong, nonatomic, readonly, nullable) UIColor *outgoingGeneralFileMessageBackgroundColor;
@property (strong, nonatomic, readonly, nullable) NSDictionary *outgoingGeneralFileMessageFileNameLabelAttribute;
@property (strong, nonatomic, readonly, nullable) NSDictionary *outgoingGeneralFileMessageDateLabelAttribute;
@property (atomic, readonly) CGFloat outgoingGeneralFileMessageDateLabelHeight;
@property (strong, nonatomic, readonly, nullable) NSDictionary *outgoingGeneralFileMessageFileSizeLabelAttribute;
@property (strong, nonatomic, readonly, nullable) UIFont *outgoingGeneralFileMessageActionButtonFont;
@property (strong, nonatomic, readonly, nullable) UIColor *outgoingGeneralFileMessageActionButtonFontColor;
@property (strong, nonatomic, readonly, nullable) UIColor *outgoingGeneralFileMessageSeperatorLineViewColor;
@property (atomic, readonly) CGFloat outgoingGeneralFileMessageSeperatorLineViewHeight;
@property (strong, nonatomic, readonly, nullable) NSDictionary *outgoingGeneralFileMessageStatusLabelAttribute;
@property (strong, nonatomic, readonly, nullable) UIColor *outgoingGeneralFileMessageDownloadProgressBarColor;

//// IncomingUserMessage
@property (strong, nonatomic, readonly, nullable) NSDictionary *incomingUserMessageNicknameLabelAttribute;
@property (atomic, readonly) CGFloat incomingUserMessageNicknameLabelHeight;
@property (atomic, readonly) CGFloat incomingUserMessageBorderWidth;
@property (strong, nonatomic, readonly, nullable) UIColor *incomingUserMessageBorderColor;
@property (strong, nonatomic, readonly, nullable) UIColor *incomingUserMessageBackgroundColor;
@property (strong, nonatomic, readonly, nullable) NSDictionary *incomingUserMessageTextViewAttribute;
@property (strong, nonatomic, readonly, nullable) UIColor *incomingUserMessageTextViewLinkFontColor;
@property (strong, nonatomic, readonly, nullable) NSDictionary *incomingUserMessageDateLabelAttribute;
@property (atomic, readonly) CGFloat incomingUserMessageDateLabelHeight;

//// Incoming URL Preview
@property (strong, nonatomic, readonly, nullable) NSDictionary *incomingUrlPreviewTitleLabelAttribute;
@property (strong, nonatomic, readonly, nullable) NSDictionary *incomingUrlPreviewDomainLabelAttribute;

//// IncomingImageFileMessage
@property (atomic, readonly) CGFloat incomingImageFileMessageBorderWidth;
@property (strong, nonatomic, readonly, nullable) UIColor *incomingImageFileMessageBorderColor;
@property (strong, nonatomic, readonly, nullable) UIColor *incomingImageFileMessageDateBackgroundColor;
@property (atomic, readonly) CGFloat incomingImageFileMessageDateBackgroundOpacity;
@property (strong, nonatomic, readonly, nullable) NSDictionary *incomingImageFileMessageDateLabelAttribute;
@property (atomic, readonly) CGFloat incomingImageFileMessageDateLabelHeight;

//// IncomingVideoFileMessage
@property (atomic, readonly) CGFloat incomingVideoFileMessageBorderWidth;
@property (strong, nonatomic, readonly, nullable) UIColor *incomingVideoFileMessageBorderColor;
@property (strong, nonatomic, readonly, nullable) UIColor *incomingVideoFileMessageDateBackgroundColor;
@property (atomic, readonly) CGFloat incomingVideoFileMessageDateBackgroundOpacity;
@property (strong, nonatomic, readonly, nullable) NSDictionary *incomingVideoFileMessageDateLabelAttribute;
@property (atomic, readonly) CGFloat incomingVideoFileMessageDateLabelHeight;

//// IncomingGeneralFileMessage
@property (strong, nonatomic, readonly, nullable) NSDictionary *incomingGeneralFileMessageNicknameLabelAttribute;
@property (atomic, readonly) CGFloat incomingGeneralFileMessageNicknameLabelHeight;
@property (atomic, readonly) CGFloat incomingGeneralFileMessageBorderWidth;
@property (strong, nonatomic, readonly, nullable) UIColor *incomingGeneralFileMessageBorderColor;
@property (strong, nonatomic, readonly, nullable) UIColor *incomingGeneralFileMessageBackgroundColor;
@property (strong, nonatomic, readonly, nullable) NSDictionary *incomingGeneralFileMessageFileNameLabelAttribute;
@property (strong, nonatomic, readonly, nullable) NSDictionary *incomingGeneralFileMessageDateLabelAttribute;
@property (atomic, readonly) CGFloat incomingGeneralFileMessageDateLabelHeight;
@property (strong, nonatomic, readonly, nullable) NSDictionary *incomingGeneralFileMessageFileSizeLabelAttribute;
@property (strong, nonatomic, readonly, nullable) UIFont *incomingGeneralFileMessageActionButtonFont;
@property (strong, nonatomic, readonly, nullable) UIColor *incomingGeneralFileMessageActionButtonFontColor;
@property (strong, nonatomic, readonly, nullable) UIColor *incomingGeneralFileMessageSeperatorLineViewColor;
@property (atomic, readonly) CGFloat incomingGeneralFileMessageSeperatorLineViewHeight;
@property (strong, nonatomic, readonly, nullable) UIColor *incomingGeneralFileMessageDownloadProgressBarColor;

//// Image Viewer
@property (strong, nonatomic, readonly, nullable) UIFont *imageViewerSaveButtonTextFont;
@property (strong, nonatomic, readonly, nullable) UIFont *imageViewerSaveResultLabelFont;

// Inbox
@property (strong, nonatomic, readonly, nullable) UIColor *refreshControlColor;
@property (strong, nonatomic, readonly, nullable) UIColor *inboxLoadingIndicatorColor;
@property (atomic, readonly) CGFloat ticketCellViewHeight;
@property (strong, nonatomic, readonly, nullable) NSDictionary *ticketTitleLabelAttribute;
@property (strong, nonatomic, readonly, nullable) NSDictionary *ticketAgentNicknameLabelAttribute;
@property (strong, nonatomic, readonly, nullable) NSDictionary *ticketLastMessageLabelAttribute;
@property (strong, nonatomic, readonly, nullable) NSDictionary *ticketDateLabelAttribute;
@property (strong, nonatomic, readonly, nullable) UIColor *ticketUnreadCountBadgeColor;
@property (atomic, readonly) CGFloat ticketUnreadCountBadgeHeight;
@property (atomic, readonly) NSInteger ticketUnreadCountMaxValue;
@property (strong, nonatomic, readonly, nullable) NSDictionary *ticketUnreadCountLabelAttribute;
@property (strong, nonatomic, readonly, nullable) UIColor *ticketBackgroundColor;
@property (strong, nonatomic, readonly, nullable) UIColor *ticketDividerColor;
@property (atomic, readonly) CGFloat ticketDivderHeight;
@property (atomic, readonly) CGFloat closedTicketOpacity;
@property (strong, nonatomic, readonly, nullable) UIColor *selectedTabBottomLineColor;
@property (atomic, readonly) CGFloat selectedTabBottomLineHeight;
@property (strong, nonatomic, readonly, nullable) UIFont *selectedTabFont;
@property (strong, nonatomic, readonly, nullable) UIColor *selectedTabFontColor;
@property (strong, nonatomic, readonly, nullable) UIFont *unselectedTabFont;
@property (strong, nonatomic, readonly, nullable) UIColor *unselectedTabFontColor;
@property (strong, nonatomic, readonly, nullable) NSDictionary *emptyTicketTitleLabelAttribute;
@property (strong, nonatomic, readonly, nullable) NSDictionary *emptyTicketDescriptionLabelAttribute;
@property (strong, nonatomic, readonly, nullable) UIImage *emptyTicketImage;

// Settings
@property (strong, nonatomic, readonly, nullable) NSDictionary *settingCategoryLabelAttribute;
@property (strong, nonatomic, readonly, nullable) UIColor *settingSwitchOnTintColor;
@property (strong, nonatomic, readonly, nullable) UIColor *settingSaveIndicatorColor;

// WebView
@property (strong, nonatomic, readonly, nullable) UIImage *webViewBackButtonOffImage;
@property (strong, nonatomic, readonly, nullable) UIImage *webViewBackButtonOnImage;
@property (strong, nonatomic, readonly, nullable) UIImage *webViewForwardButtonOffImage;
@property (strong, nonatomic, readonly, nullable) UIImage *webViewForwardButtonOnImage;
@property (strong, nonatomic, readonly, nullable) UIColor *webViewUrlBackgroundColor;
@property (strong, nonatomic, readonly, nullable) NSDictionary *webViewUrlLabelAttribute;

// LocalizedString
@property (strong, nonatomic, readonly, nullable) NSString *localizedInboxTitle;
@property (strong, nonatomic, readonly, nullable) NSString *localizedInboxOpenTabText;
@property (strong, nonatomic, readonly, nullable) NSString *localizedInboxClosedTabText;

@property (strong, nonatomic, readonly, nullable) NSString *localizedInboxImageLastMessage;
@property (strong, nonatomic, readonly, nullable) NSString *localizedInboxVideoLastMessage;
@property (strong, nonatomic, readonly, nullable) NSString *localizedInboxAudioLastMessage;
@property (strong, nonatomic, readonly, nullable) NSString *localizedInboxFileLastMessage;

@property (strong, nonatomic, readonly, nullable) NSString *localizedSettingsTitle;
@property (strong, nonatomic, readonly, nullable) NSString *localizedSettingsBackButton;
@property (strong, nonatomic, readonly, nullable) NSString *localizedSettingsPushNotificationLabel;

@property (strong, nonatomic, readonly, nullable) NSString *localizedChattingUploadPhoto;
@property (strong, nonatomic, readonly, nullable) NSString *localizedChattingTakePhoto;
@property (strong, nonatomic, readonly, nullable) NSString *localizedChattingUploadVideo;
@property (strong, nonatomic, readonly, nullable) NSString *localizedChattingTakeVideo;
@property (strong, nonatomic, readonly, nullable) NSString *localizedChattingCloseUpload;

@property (strong, nonatomic, readonly, nullable) NSString *localizedResendFailedMessageAlertTitle;
@property (strong, nonatomic, readonly, nullable) NSString *localizedResendFailedMessageAlertDescription;
@property (strong, nonatomic, readonly, nullable) NSString *localizedResendFailedMessageAlertCloseButton;
@property (strong, nonatomic, readonly, nullable) NSString *localizedResendFailedMessageAlertResendButton;

@property (strong, nonatomic, readonly, nullable) NSString *localizedDeleteFailedMessageAlertTitle;
@property (strong, nonatomic, readonly, nullable) NSString *localizedDeleteFailedMessageAlertDescription;
@property (strong, nonatomic, readonly, nullable) NSString *localizedDeleteFailedMessageAlertCloseButton;
@property (strong, nonatomic, readonly, nullable) NSString *localizedDeleteFailedMessageAlertResendButton;

@property (strong, nonatomic, readonly, nullable) NSString *localizedImageViewerSaveButtonText;
@property (strong, nonatomic, readonly, nullable) NSString *localizedImageViewerSaveSucceedText;
@property (strong, nonatomic, readonly, nullable) NSString *localizedImageViewerSaveFailedText;

@property (strong, nonatomic, readonly, nullable) NSString *localizedInputTextViewPlaceholder;

@property (strong, nonatomic, readonly, nullable) NSString *localizedEmptyOpenTicketTitle;
@property (strong, nonatomic, readonly, nullable) NSString *localizedEmptyOpenTicketDescription;
@property (strong, nonatomic, readonly, nullable) NSString *localizedEmptyClosedTicketTitle;
@property (strong, nonatomic, readonly, nullable) NSString *localizedEmptyClosedTicketDescription;

@property (strong, nonatomic, readonly, nullable) NSString *localizedMessageStatusSending;

@property (strong, nonatomic, readonly, nullable) NSString *localizedGeneralFileMessageView;
@property (strong, nonatomic, readonly, nullable) NSString *localizedGeneralFileMessageDownload;

@property (strong, nonatomic, readonly, nullable) NSString *localizedSettingsClearDownloadedFilesButton;
@property (strong, nonatomic, readonly, nullable) NSString *localizedSettingsOpenSourceLicenseButton;
@property (strong, nonatomic, readonly, nullable) NSString *localizedClearDownloadedFilesAlertTitleText;
@property (strong, nonatomic, readonly, nullable) NSString *localizedClearDownloadedFilesAlertDescriptionText;
@property (strong, nonatomic, readonly, nullable) NSString *localizedClearDownloadedFilesAlertCloseButton;
@property (strong, nonatomic, readonly, nullable) NSString *localizedClearDownloadedFilesAlertConfirmButton;

@property (strong, nonatomic, readonly, nullable) NSString *localizedOpenSourceLicenseTitle;
@property (strong, nonatomic, readonly, nullable) NSString *localizedOpenSourceLicenseBackButton;

@property (strong, nonatomic, readonly, nullable) NSString *localizedWebViewDoneButton;

// ServiceErrorCommon
@property (strong, nonatomic, readonly, nullable) NSString *localizedCustomerServiceStartErrorAlertTitle;
@property (strong, nonatomic, readonly, nullable) NSString *localizedCustomerServiceStartErrorAlertDescription;
@property (strong, nonatomic, readonly, nullable) NSString *localizedCustomerServiceStartErrorAlertCloseButton;
@property (strong, nonatomic, readonly, nullable) NSString *localizedCustomerServiceCreateTicketErrorAlertTitle;
@property (strong, nonatomic, readonly, nullable) NSString *localizedCustomerServiceCreateTicketErrorAlertDescription;
@property (strong, nonatomic, readonly, nullable) NSString *localizedCustomerServiceCreateTicketErrorAlertCloseButton;
@property (strong, nonatomic, readonly, nullable) NSString *localizedCustomerServiceOpenChannelErrorAlertTitle;
@property (strong, nonatomic, readonly, nullable) NSString *localizedCustomerServiceOpenChannelErrorAlertDescription;
@property (strong, nonatomic, readonly, nullable) NSString *localizedCustomerServiceOpenChannelErrorAlertCloseButton;
@property (strong, nonatomic, readonly, nullable) NSString *localizedCustomerServiceLoadMessageErrorAlertTitle;
@property (strong, nonatomic, readonly, nullable) NSString *localizedCustomerServiceLoadMessageErrorAlertDescription;
@property (strong, nonatomic, readonly, nullable) NSString *localizedCustomerServiceLoadMessageErrorAlertCloseButton;
@property (strong, nonatomic, readonly, nullable) NSString *localizedCustomerServiceLoadOpenTicketErrorAlertTitle;
@property (strong, nonatomic, readonly, nullable) NSString *localizedCustomerServiceLoadOpenTicketErrorAlertDescription;
@property (strong, nonatomic, readonly, nullable) NSString *localizedCustomerServiceLoadOpenTicketErrorAlertCloseButton;
@property (strong, nonatomic, readonly, nullable) NSString *localizedCustomerServiceLoadClosedTicketErrorAlertTitle;
@property (strong, nonatomic, readonly, nullable) NSString *localizedCustomerServiceLoadClosedTicketErrorAlertDescription;
@property (strong, nonatomic, readonly, nullable) NSString *localizedCustomerServiceLoadClosedTicketErrorAlertCloseButton;


+ (nonnull SBDSKMain *)sharedInstance;
+ (nonnull NSString *)getSDKVersion;
+ (nullable NSString *)getApplicationId;
+ (void)setLogLevel:(SBDSKLogLevel)logLevel;
+ (void)logWithLevel:(SBDSKLogLevel)logLevel format:(NSString * _Nonnull)format, ...;

+ (void)initWithApplicationId:(NSString * _Nonnull)applicationId;
+ (void)setUserInfoWithUserId:(NSString * _Nonnull)userId accessToken:(NSString * _Nullable)accessToken;

+ (void)setTheme:(NSString * _Nonnull)themeFile bundle:(NSBundle * _Nonnull)bundle;

+ (void)startChattingWithTitle:(NSString * _Nullable)title info:(NSDictionary * _Nonnull)info;
+ (void)startChattingByPushNotification:(NSDictionary * _Nonnull)pushInfo userId:(NSString * _Nonnull)userId nickname:(NSString * _Nullable)nickname accessToken:(NSString * _Nullable)accessToken;
+ (void)startInbox;
+ (void)startInboxWithTransition:(BOOL)transition;

+ (void)getOpenTicketCountWithCompletionHandler:(nullable void (^)(int count, NSError * _Nullable error))completionHandler;
+ (void)getOpenTicketsWithOffset:(long)offset completionHandler:(nullable void (^)(NSArray<SBDSKTicket *> * _Nullable tickets, NSError * _Nullable error))completionHandler;
+ (void)getClosedTicketsWithOffset:(long)offset completionHandler:(nullable void (^)(NSArray<SBDSKTicket *> * _Nullable tickets, NSError * _Nullable error))completionHandler;
+ (void)createTicketWithChannelName:(NSString * _Nullable)channelName info:(NSString * _Nullable)info completionHandler:(nullable void (^)(SBDSKTicket * _Nullable ticket, NSError * _Nullable error))completionHandler;
+ (void)getTicketWithTicketId:(long long)ticketId completionHandler:(nullable void (^)(SBDSKTicket * _Nullable ticket, NSError * _Nullable error))completionHandler;
+ (void)updateTicketWithTicketId:(long long)ticketId status:(NSString * _Nonnull)status completionHandler:(nullable void (^)(SBDSKTicket * _Nullable ticket, NSError * _Nullable error))completionHandler;
+ (void)editMessageWithTicketId:(long long)ticketId message:(SBDBaseMessage * _Nonnull)message messageData:(NSDictionary * _Nonnull)messageData completionHandler:(nullable void (^)(SBDBaseMessage * _Nullable message, NSError * _Nullable error))completionHandler;
+ (void)checkDowntimeMessageWithMessageId:(long long)ticketId completionHandler:(nullable void (^)(SBDSKTicket * _Nullable ticket, NSError * _Nullable error))completionHandler;
+ (void)setEventDelegate:(id<SBDSKEventDelegate> _Nonnull)delegate;
+ (void)triggerEvent:(NSString * _Nonnull)eventKey metaData:(NSDictionary<NSString *, NSString *> * _Nullable)metaData;
+ (BOOL)isDeskChannel:(SBDBaseChannel * _Nonnull)channel;

@end
