//
//  SBDSKAgent.h
//  SendBirdDesk
//
//  Created by SendBird on 3/13/18.
//  Copyright © 2018 SendBird All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 <#Description#>
 */
@interface SBDSKAgent : NSObject

@property (strong, nonatomic, readonly, nullable) NSString *sendBirdId;
@property (strong, nonatomic, readonly, nullable) NSString *name;
@property (strong, nonatomic, readonly, nullable) NSString *profileUrl;

@end
