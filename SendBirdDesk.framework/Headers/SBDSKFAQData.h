//
//  SBDSKFAQData.h
//  SendBirdDesk
//
//  Created by Minhyuk Kim on 2021/05/20.
//  Copyright © 2021 Jed Gyeong. All rights reserved.
//

#ifndef SBDSKFAQData_h
#define SBDSKFAQData_h

#import <Foundation/Foundation.h>
#import <SendBirdSDK/SendBirdSDK.h>
#import "SBDSKFAQResult.h"

@interface SBDSKFAQData : NSObject

@property (atomic, readonly) long long faqFileId;
@property (atomic, strong, readonly, nonnull) NSString *type;
@property (atomic, strong, readonly, nonnull) NSArray<SBDSKFAQResult *> *faqResults;

- (nullable instancetype)initWithMesage:(nonnull SBDBaseMessage *)message;

@end

#endif /* SBDSKFAQData_h */
