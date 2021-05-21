//
//  SBDSKFAQResult.h
//  SendBirdDesk
//
//  Created by Minhyuk Kim on 2021/05/20.
//  Copyright © 2021 Jed Gyeong. All rights reserved.
//

#ifndef SBDSKFAQResult_h
#define SBDSKFAQResult_h

#import <Foundation/Foundation.h>

@interface SBDSKFAQResult : NSObject

@property (atomic, strong, readonly, nullable) NSString *category;
@property (atomic, strong, readonly, nullable) NSString *question;
@property (atomic, strong, readonly, nullable) NSString *answer;
@property (atomic, strong, readonly, nullable) NSString *keyword;
@property (atomic, strong, readonly, nullable) NSString *url;
@property (atomic, strong, readonly, nullable) NSString *imageURL;

- (nullable instancetype)initWithDictionary:(nonnull NSDictionary *)dict;

@end

#endif /* SBDSKFAQResult_h */
