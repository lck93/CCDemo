//
//  ECSPublicAccountStructure.h
//  eSpaceIOSSDK
//
//  Created by ZengyiWang on 15/7/10.
//  Copyright (c) 2015年 huawei. All rights reserved.
//

#import <Foundation/Foundation.h>

//公众号同步
typedef NS_ENUM(NSInteger, SyncServicePublicAccountMode)
{
    SyncPublicAccountSubscribe = 0,//新增订阅
    SyncPublicAccountUnSubscribe = 1,//取消关注
    SyncPublicAccountMenuOnly = 2,//只修改菜单
    SyncPublicAccountAccountOnly = 3,//只修改公众号详情
    SyncPublicAccountAccountAndMenu = 4,//修改公众号和菜单
    SyncPublicAccountLogoOnly = 5,//只修改Logo
    SyncPublicAccountUnknow = -1
};

typedef NS_ENUM(NSInteger, PublicAccountMsgType)
{
    PublicAccountMsgTypeText = 1,//文本消息
    PublicAccountMsgTypeImage = 2,//图片消息
    PublicAccountMsgTypeTextAndImage = 3,//多图文消息
    PublicAccountMsgTypeVoice = 4,//语音消息
    PublicAccountMsgTypeVideo = 5,//视频消息
    PublicAccountMsgTypeLightApp = 6,//轻应用消息
    PublicAccountMsgTypeUnknown = -1
};

@class ECSPublicAccountBaseMsgObject;

@interface ECSPublicAccountObject : NSObject

//服务器对应本地的公众号的模式，当是logoOnly时则只有logoID字段有数据，UnSubscribe时其他字段都为空
@property (nonatomic, assign) SyncServicePublicAccountMode serviceMode;

@property (nonatomic, copy) NSString *publicAccountID;//一定有值
@property (nonatomic, copy) NSString *publicAccountName;
@property (nonatomic, copy) NSString *publicAccountLogoID;

@property (nonatomic, retain) NSNumber * isAuth;
@property (nonatomic, retain) NSNumber * isSubscription;
@property (nonatomic, retain) NSNumber * isSupportPush;
@property (nonatomic, retain) NSNumber * mode;
@property (nonatomic, retain) NSNumber * accountEntity;
@property (nonatomic, retain) NSNumber * state;
@property (nonatomic, retain) NSString * summary;
@property (nonatomic, retain) NSNumber * type;
@property (nonatomic, retain) NSArray  * ownMenus;//ECSPublicAccountMenuObject
@property (nonatomic, retain) NSNumber *disPosition;//显示位置: 0公众号盒子内部, 1公众号盒子外部

- (id)initWithPublicAccountID:(NSString *)publicAccountID;

@end

@interface ECSPublicAccountMenuObject : NSObject

@property (nonatomic, retain) NSString * cmdContent;
@property (nonatomic, retain) NSNumber * cmdType;
@property (nonatomic, retain) NSString * materialId;
@property (nonatomic, retain) NSNumber * materialType;
@property (nonatomic, retain) NSString * menuId;
@property (nonatomic, retain) NSNumber * menuLevel;
@property (nonatomic, retain) NSString * menuName;
@property (nonatomic, retain) NSNumber * menuOrder;
@property (nonatomic, retain) NSString * parentMenuId;
@property (nonatomic, retain) NSString * publicAccountID;

- (id)initWithPublicAccountID:(NSString *)publicAccountID;

@end

@interface ECSPublicAccountBaseMsgObject : NSObject

@property (nonatomic, retain) NSString * messageID;//此id时根据sendTime + 8位的随机数组成的
@property (nonatomic, retain) NSString * chatID;
@property (nonatomic, retain) NSDate   * receiveTime;
@property (nonatomic, retain) NSDate   * createTime;
@property (nonatomic, retain) NSString * msgBody;//除了图文消息其他消息的内容都放在这个字段中
@end

@interface ECSPublicAccountMsgObject : ECSPublicAccountBaseMsgObject

@property (nonatomic, retain) NSString * publicAccountID;
@property (nonatomic, retain) NSNumber * publicAccountMsgType;
@property (nonatomic, retain) NSNumber * publicSource;
@property (nonatomic, retain) NSArray  * ownMsgItem;//此字段只有多图文消息会有
@end

@interface ECSPublicAccountMsgItemObject : NSObject

@property (nonatomic, retain) NSString * title;
@property (nonatomic, retain) NSString * digest;
@property (nonatomic, retain) NSNumber * order;
@property (nonatomic, retain) NSString * author;
@property (nonatomic, retain) NSString * umLocalURL;
@property (nonatomic, retain) NSString * umRemoteURL;
@property (nonatomic, retain) NSString * contentURL;
@property (nonatomic, retain) NSString * sourceURL;
@end

@interface ECSLightAppPaObject : NSObject

@property (nonatomic, retain) NSString * lightAppID;
@property (nonatomic, retain) NSString * logoID;
@property (nonatomic, retain) NSString * eName;
@property (nonatomic, retain) NSString * cName;
@property (nonatomic, retain) NSString * openURL;
@property (nonatomic, retain) NSNumber * isFirstUse;
@property (nonatomic, retain) NSNumber * isSessionShow;
@property (nonatomic, retain) NSNumber * isDiscoveryShow;
@property (nonatomic, retain) NSNumber * isDiscoveryDelete;
@end

@interface ECSLightAppPaMsgObject : ECSPublicAccountBaseMsgObject

@property (nonatomic, retain) NSString * lightAppID;
@property (nonatomic, retain) NSString * contentURL; // 对应轻应用公众号消息点击后的打开地址

@end

@interface ECSLocalAppPaMsgObject : ECSPublicAccountBaseMsgObject

@property (nonatomic, retain) NSString * localAppID;

@end

@interface ECSLocalAppPaEmailMsgObject : ECSLocalAppPaMsgObject

@property (nonatomic, strong) NSString *senderAccount;
@property (nonatomic, strong) NSString *senderName;
@property (nonatomic, strong) NSString *senderEmailAdress;
//@property (nonatomic, strong) NSNumber *isVIP;
@property (nonatomic, strong) NSString *emailTitle;
@property (nonatomic, strong) NSString *emailDigest;
@property (nonatomic, strong) NSString *emailID;
@property (nonatomic, strong) NSNumber *hasAttachment;
@property (nonatomic, strong) NSString *vipIndicators;

@end

@interface ECSLocalAppPaObject : NSObject

@property (nonatomic, strong) NSString * localAppID;
@property (nonatomic, strong) NSString * logoID;
@property (nonatomic, strong) NSString * eName;
@property (nonatomic, strong) NSString * cName;
@property (nonatomic, strong) NSNumber * isFirstUse;
@property (nonatomic, strong) NSNumber * isUsed;
@property (nonatomic, strong) NSNumber * location;

@end

@interface ECSEmailVIPUser : NSObject

@property (nonatomic, strong) NSString *account;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *nativeName;
@property (nonatomic, strong) NSString *headId;
@property (nonatomic, assign) NSInteger optType;

@end


