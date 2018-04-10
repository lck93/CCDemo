/**
 * @file TupGroupService.h
 *
 * Copyright © 2017 Huawei Tech. Co., Ltd. All rights reserved. \n
 *
 * @brief [en]Description:TUP group basic service function class head file.
 * [cn]描述：TUP 群组基础业务功能类头文件。 \n
 **/
 
#import <Foundation/Foundation.h>

extern NSString* const kTupGroupInviteGroupName;
extern NSString* const kTupGroupInviteAnnounce;
extern NSString* const kTupGroupInviteIntro;
extern NSString* const kTupGroupInviteReason;
extern NSString* const TupGroupInviteNotify;
extern NSString* const TupGroupInviteNotify_TitleKey;

#define DEFAULT_TUP_GROUP_CAPACITY 30  //默认群组容量
#define DEFAULT_TUP_GROUP_NAME_LENGTH 50 //默认讨论组名称长度

@interface TupGroupService : NSObject

@end
