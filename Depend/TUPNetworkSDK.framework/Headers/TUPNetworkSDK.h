//
//  TUPNetworkSDK.h
//  TUPNetworkSDK
//
//  Created by wangxiangyang on 3/24/17.
//  Copyright © 2017 Huawei Tech. Co., Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for TUPNetworkSDK.
FOUNDATION_EXPORT double TUPNetworkSDKVersionNumber;

//! Project version string for TUPNetworkSDK.
FOUNDATION_EXPORT const unsigned char TUPNetworkSDKVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <TUPNetworkSDK/PublicHeader.h>

#import <TUPNetworkSDK/TUPNetworkSDK.h>

#pragma mark --Login


#pragma mark --Contact
#import <TUPNetworkSDK/ECSContactService.h>
#import <TUPNetworkSDK/ECSContactServiceMessage.h>
#import <TUPNetworkSDK/ECSGroupManageService.h>
#import <TUPNetworkSDK/ECSGroupManageServiceMessage.h>

#pragma mark --IM
#import <TUPNetworkSDK/ECSIMessagingService.h>
#import <TUPNetworkSDK/ECSIMessagingServiceMessage.h>
#import <TUPNetworkSDK/ECSRecentSessionService.h>
#import <TUPNetworkSDK/ECSRecentSessionServiceMessage.h>
#import <TUPNetworkSDK/ECSOprCommandService.h>

#pragma mark --Setting
#import <TUPNetworkSDK/ECSUserSettingService.h>
#import <TUPNetworkSDK/ECSUserSettingServiceMessage.h>

#pragma mark --Circle
#import <TUPNetworkSDK/ECSCircleService.h>
#import <TUPNetworkSDK/ECSCircleServiceMessage.h>

#pragma mark --PublicNO
#import <TUPNetworkSDK/ECSPublicAccountService.h>
#import <TUPNetworkSDK/ECSPublicAccountServiceMessage.h>
#import <TUPNetworkSDK/ECSPublicAccountStructure.h>

#pragma mark --Common
#import <TUPNetworkSDK/ECSLogCofig.h>
#import <TUPNetworkSDK/ECSErrorCode.h>


//#import <TUPNetworkSDK/ECSMIPRequestOperation.h>
#import <TUPNetworkSDK/ECSNetworkService.h>
