//
//  TUPIOSSDK.h
//  TUPIOSSDK
//
//  Created on 3/25/17.
//  Copyright © 2017 Huawei Tech. Co., Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for TUPIOSSDK.
FOUNDATION_EXPORT double TUPIOSSDKVersionNumber;

//! Project version string for TUPIOSSDK.
FOUNDATION_EXPORT const unsigned char TUPIOSSDKVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <TUPIOSSDK/PublicHeader.h>

#pragma mark- public headers
#import <TUPIOSSDK/TUPIOSSDK.h>
#import <TUPIOSSDK/ESpaceLocalDataManager.h>
#import <TUPIOSSDK/ESpaceUMResource.h>
#import <TUPIOSSDK/ESpaceMediaService.h>
#import <TUPIOSSDK/ESpaceRichTextBaseParser.h>
#import <TUPIOSSDK/ESpaceDetailMessagParser.h>
#import <TUPIOSSDK/ECSRichTextView.h>
#import <TUPIOSSDK/ECSAppConfig.h>
#import <TUPIOSSDK/ECSUserConfig.h>
#import <TUPIOSSDK/ECSUserMAAInfo.h>
#import <TUPIOSSDK/ECSServerAbility.h>
#import <TUPIOSSDK/TupErrorCode.h>
#import <TUPIOSSDK/ECSDefines.h>
#import <TUPIOSSDK/TUPIOSSDKService.h>
#import <TUPIOSSDK/ESpaceContactHeadImageService.h>
#import <TUPIOSSDK/ECSLoginService.h>
#import <TUPIOSSDK/TUPUserSettingService.h>
#import <TUPIOSSDK/NSManagedObjectContext+Persistent.h>
#import <TUPIOSSDK/NSString+ESpaceMD5.h>
#import <TUPIOSSDK/NSString+Transform.h>
#import <TUPIOSSDK/ECSSandboxHelper.h>
#import <TUPIOSSDK/TUPMAALoginService.h>
#import <TUPIOSSDK/eSpaceDBService.h>
#import <TUPIOSSDK/AssistantMessageEntity.h>
#import <TUPIOSSDK/AssistantSessionEntity.h>
#import <TUPIOSSDK/ChatMessageEntity.h>
#import <TUPIOSSDK/ChatSessionEntity.h>
#import <TUPIOSSDK/ContactEntity.h>
#import <TUPIOSSDK/CustomContactEntity.h>
#import <TUPIOSSDK/EmployeeCategoryEntity.h>
#import <TUPIOSSDK/EmployeeEntity.h>
#import <TUPIOSSDK/GroupEntity.h>
#import <TUPIOSSDK/MessageEntity.h>
#import <TUPIOSSDK/PersonEntity.h>
#import <TUPIOSSDK/SessionEntity.h>
#import <TUPIOSSDK/SessionGroupEntity.h>



#pragma mark- inner use headers
#import <TUPIOSSDK/ECSUtils.h>
#import <TUPIOSSDK/ESpaceEmotions.h>
#import <TUPIOSSDK/ECSUMService.h>
#import <TUPIOSSDK/ESpaceImageCache.h>
#import <TUPIOSSDK/ECSFileManager.h>
#import <TUPIOSSDK/ESpaceAddressBookManager.h>
#import <TUPIOSSDK/ECSafeMutableDictionary.h>
#import <TUPIOSSDK/ESpaceImage.h>
#import <TUPIOSSDK/NSDate+LocalString.h>
#import <TUPIOSSDK/NSManagedObject+ECS_Utility.h>
#import <TUPIOSSDK/NSObject+Hook.h>
#import <TUPIOSSDK/NSString+FileType.h>
#import <TUPIOSSDK/NSString+PhoneNumber.h>
#import <TUPIOSSDK/NSThread+ABIdentifier.h>
#import <TUPIOSSDK/NSURL+Export.h>
#import <TUPIOSSDK/PhoneticContacts.h>
#import <TUPIOSSDK/NSObject+DataExchange.h>
#import <TUPIOSSDK/SpecialChatSessionEntity.h>
#import <TUPIOSSDK/ESpaceVersionSwitchHelper.h>
#import <TUPIOSSDK/AttendeeEntity.h>
#import <TUPIOSSDK/BulletinEntity.h>
#import <TUPIOSSDK/DeptMessageEntity.h>
#import <TUPIOSSDK/ESpaceMutipleTerminalRemindSessionEntity+CoreDataProperties.h>
#import <TUPIOSSDK/ESpaceMutipleTerminalRemindSessionEntity.h>
#import <TUPIOSSDK/GroupFileEntity.h>
#import <TUPIOSSDK/LocalContactEntity.h>
#import <TUPIOSSDK/MsgLogEntity.h>
#import <TUPIOSSDK/MsgLogSessionEntity.h>
#import <TUPIOSSDK/SpecialChatSessionEntity+CoreDataProperties.h>
#import <TUPIOSSDK/SpecialChatSessionEntity.h>
#import <TUPIOSSDK/ThirdPartSysEntity+CoreDataProperties.h>
#import <TUPIOSSDK/ThirdPartSysEntity.h>
#import <TUPIOSSDK/UmEntity.h>
#import <TUPIOSSDK/DeptSessionEntity.h>
#import <TUPIOSSDK/CallContactEntity.h>
#import <TUPIOSSDK/CallSessionEntity.h>
