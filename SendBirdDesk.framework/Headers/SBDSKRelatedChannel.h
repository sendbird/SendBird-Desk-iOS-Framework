//
//  SBDSKRelatedChannel.h
//  SendBirdDesk
//
//  Created by Minhyuk Kim on 2020/04/22.
//  Copyright © 2020 Sendbird. All rights reserved.
//

#ifndef SBDSKRelatedChannel_h
#define SBDSKRelatedChannel_h

/**
This class represents a channel that is related to a `SBDSKTicket`. It contains a string `name` and string `channelUrl` of the related channel.

@since 1.0.7
*/
@interface SBDSKRelatedChannel: NSObject

/**
 The name of the related channel.
 
 @since 1.0.7
 */
@property (strong, nonatomic, nonnull) NSString *name;

/**
 The channel url of the related channel.
 
 @since 1.0.7
 */
@property (strong, nonatomic, nonnull) NSString *channelUrl;

@end

#endif /* SBDSKRelatedChannel_h */
