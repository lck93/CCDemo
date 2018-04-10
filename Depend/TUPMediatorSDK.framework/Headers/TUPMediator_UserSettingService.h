//
//  TUPMediator_UserSettingService.h
//  TUPMediatorSDK
//
//  Created on 3/24/17.
//  Copyright © 2017 Huawei Tech. Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

#define ESPACE_USERSETTING_SERVICE   @"ESpaceUserSettingServiceAdapter"

@interface TUPMediator_UserSettingService : NSObject

+ (void)M_showOrHideMultiTerminalRemind:(BOOL)isShow andTime:(NSDate *)time completion:(void(^)(NSError* error))completionBlock;

+ (void)M_setUserOnlineStatusWhenLogin:(NSInteger)status;

+ (NSInteger)M_userOnlineStatusWhenLogin;

+ (void)M_setSelfStatus:(NSInteger)status completion:(void(^)(NSError* error))completionBlock;

@end
