#import <Foundation/Foundation.h>
#import "ECSPublicAccountStructure.h"
#import "ECSBaseMsg.h"

#define SubscribePublicAccountEvent @"subscribe"
#define UnSubscribePublicAccountEvent @"unsubscribe"

@class ECSPublicAccountMsgObject;

typedef NS_ENUM(NSInteger, PublicAccountResultCode)
{
    PublicAccountResultCodeSuc = 0,
    PublicAccountResultCodeFailed = -1
};

typedef NS_ENUM(NSInteger, PublicAccountServiceMode)
{
    PublicAccountServiceModeEdit = 0,
    PublicAccountServiceModeDevelop = 1,
    PublicAccountServiceModeUnknow = -1
};

typedef NS_ENUM(NSInteger, PublicAccountQueryMode)
{
    PublicAccountQueryModeSendMsg = 0,
    PublicAccountQueryModeGetMenuReply = 1,
    PublicAccountQueryModeUnknow = -1
};

typedef NS_ENUM(NSInteger, PublicAccountMsgSource)
{
    PublicAccountMsgSourceInternal = 1,//内部公众号消息
    PublicAccountMsgSourceThirdParty = 2//第三方公众号
};

typedef NS_ENUM(NSInteger, PublicAccountAutoReplyKeyType)
{
    PublicAccountAutoReplyKeyTypeText = 1,
    PublicAccountAutoReplyKeyTypeImage = 2,
    PublicAccountAutoReplyKeyTypeImageText = 3,
    PublicAccountAutoReplyKeyTypeVoice = 4,
    PublicAccountAutoReplyKeyTypeVideo = 5,
    PublicAccountAutoReplyKeyTypeUnknow = -1
};

@interface ECSExtendRequest : NSObject

@property (nonatomic, copy) NSString* ActionType;//ServiceNo
@property (nonatomic, copy) NSString* user;
@property (nonatomic, assign) NSInteger jsonid;//所有请求对象（包括子类），此字段延迟到parseMsg中赋值
@property (nonatomic, strong) NSData* requestBody;//同jsonid
@end

@interface ECSExtendRequestAck : ECSRootErrorMsg

@property (nonatomic, strong) NSData* ackBody;
@property (nonatomic, assign) NSInteger jsonid;

@end

@interface ECSExtendNotify : NSObject

@property (nonatomic, copy) NSString* ActionType;//ServiceNoNotify
@property (nonatomic, assign) NSInteger jsonid;
@property (nonatomic, strong) NSData* requestBody;

@end


#pragma mark - 同步公众号
@interface ECSSyncPublicAccountRequest : ECSExtendRequest

@property (nonatomic, copy) NSString *timestamp;
@end

@interface ECSSyncPublicAccountAck : ECSExtendRequestAck

@property (nonatomic, copy) NSString *timestamp;
@property (nonatomic, strong) NSDictionary *publicAccountDic;//key-publicAccountID value-publicAccount
@end

#pragma mark - 查询头像()
@interface ECSQueryPaLogoRequest : ECSExtendRequest

@property (nonatomic, copy) NSString *logoID;
@property (nonatomic, copy) NSString *publicAccountID;
@property (nonatomic, assign) int imgWidth;
@property (nonatomic, assign) int imgHeight;
@end

@interface ECSQueryPaLogoAck : ECSExtendRequestAck

@property (nonatomic, retain) NSData *logo;
@end

#pragma mark - 公众号搜索
@interface ECSPublicAccountListRequest : ECSExtendRequest

@property (nonatomic, copy) NSString *condition;
@property (nonatomic, assign) NSInteger pageNo;
@property (nonatomic, assign) NSInteger pageSize;
@property (nonatomic, copy) NSString *language;//[[ECSUtils clientLanguage] UTF8String]
@end

@interface ECSPublicAccountListAck : ECSExtendRequestAck

@property (nonatomic, assign) NSInteger pageNo;
@property (nonatomic, assign) NSInteger pageSize;
@property (nonatomic, assign) BOOL isOver;
@property (nonatomic, retain) NSArray *paList;
@end

#pragma mark - 订阅公众号
@interface ECSSubscribePublicAccountRequest : ECSExtendRequest

@property (nonatomic, copy) NSString *publicAccountID;
@end

@interface ECSSubscribePublicAccountAck : ECSExtendRequestAck

@property (nonatomic, copy) NSString *timestamp;
@property (nonatomic, assign) BOOL ifPush;
@property (nonatomic, retain) ECSPublicAccountMsgObject *welcomePaMsg;
@property (nonatomic, retain) NSArray *menuList;
@end

#pragma mark - 取消订阅公众号
@interface ECSUnSubscribePublicAccountRequest : ECSExtendRequest

@property (nonatomic, copy) NSString *publicAccountID;
@end

@interface ECSUnSubscribePublicAccountAck : ECSExtendRequestAck

@property (nonatomic, copy) NSString *timestamp;
@end

#pragma mark - 设置公众号push开关
@interface ECSConfigPaPushAbilityRequest : ECSExtendRequest

@property (nonatomic, copy) NSString *publicAccountID;
@property (nonatomic, assign) BOOL isOpen;
@end

@interface ECSConfigPaPushAbilityAck : ECSExtendRequestAck

@property (nonatomic, assign) BOOL isConfigSuccess;
@end

#pragma mark - 公众号推送消息通知
@interface ECSPublicAccountPushMsgNotify : ECSExtendNotify

@property (nonatomic, strong) NSArray *paPushMsgs;//[ECSPublicAccountMsgObject] 按照时间进行排序
@end

#pragma mark - 公众号消息置已读
@interface ECSPublicAccountMsgMarkReadRequest : ECSExtendRequest

@property (nonatomic, strong) NSArray *markReadChatIDs;
@end

@interface ECSPublicAccountMsgMarkReadAck : ECSExtendRequestAck
@end

#pragma mark - 公众号请求消息
@interface ECSPublicAccountRequestMsgRequest : ECSExtendRequest

@property (nonatomic, copy) NSString *publicAccountID;
@property (nonatomic, assign) PublicAccountServiceMode mode;//目前都只有编辑者这一种模式，代号0
@property (nonatomic, assign) PublicAccountQueryMode queryMode;
@property (nonatomic, copy) NSString *from;
@property (nonatomic, copy) NSString *to;
@property (nonatomic, copy) NSString *key;//内部公众号菜单不使用此字段，而是只用于存储发送消息时的消息内容，而w3m公众号菜单使用
@property (nonatomic, assign) PublicAccountAutoReplyKeyType keyType;

//内部公众号的菜单的key使用以下两个字段代替
@property (nonatomic, assign) NSInteger materialType;
@property (nonatomic, assign) NSInteger materialID;
@end

@interface ECSPublicAccountRequestMsgAck : ECSExtendRequestAck

@property (nonatomic, strong) NSString *publicAccountID;
@property (nonatomic, strong) ECSPublicAccountMsgObject *paMsg;//内部公众号的消息请求才会走，w3m公众号的消息通过通知接口返回
@end

#pragma mark - 请求公众号历史消息
@interface ECSQueryPublicAccountHistoryMsgRequest : ECSExtendRequest

@property (nonatomic, copy) NSString *from;
@property (nonatomic, copy) NSString *to;
@property (nonatomic, copy) NSString *publicAccountID;
@property (nonatomic, assign) NSInteger pageNo;
@property (nonatomic, assign) NSInteger pageSize;
@end

@interface ECSQueryPublicAccountHistoryMsgAck : ECSExtendRequestAck

@property (nonatomic, copy) NSString *publicAccountID;
@property (nonatomic, assign) BOOL isSub;
@property (nonatomic, assign) NSInteger pageNo;
@property (nonatomic, assign) NSInteger pageSize;
@property (nonatomic, assign) NSInteger totalNo;
@property (nonatomic, strong) NSArray *paMsgs;
@end

#pragma mark - 轻应用同步
@interface ECSSyncLightAppPaRequest : ECSExtendRequest

@property (nonatomic, copy) NSString *from;
@property (nonatomic, copy) NSString *condition;
@end

@interface ECSSyncLightAppPaAck : ECSExtendRequestAck

@property (nonatomic, strong) NSDictionary *lightAppPaDic;// key = lightAppID, value = ECSLightAppPaObject
@end

#pragma mark - 置轻应用公众号已读
@interface ECSSetLightAppPaUsedRequest : ECSExtendRequest

@property (nonatomic, copy) NSString *from;
@property (nonatomic, copy) NSString *lightAppID;
@property (nonatomic, assign) BOOL isUsed; // 都是yes
@end

@interface ECSSetLightAppPaUsedAck : ECSExtendRequestAck

@end

#pragma mark - 获取本地应用列表
@interface ECSSyncLocalAppPaRequest : ECSExtendRequest

@property (nonatomic, copy) NSString *from;
@property (nonatomic, copy) NSString *condition;

@end

@interface ECSSyncLocalAppPaAck : ECSExtendRequestAck

@property (nonatomic, strong) NSDictionary<NSString *, ECSLocalAppPaObject*> *localAppPaDic;// key = localAppId, value = ECSLocalAppPaObject

@end

#pragma mark - 获取邮件提醒VIP列表
@interface ECSGetEmailVIPListRequest : ECSExtendRequest

@property (nonatomic, copy) NSString *from;
@property (nonatomic, copy) NSString *publicAccount;
@property (nonatomic, assign) NSInteger num;

@end

@interface ECSGetEmailVIPListAck : ECSExtendRequestAck

@property (nonatomic, strong) NSArray<ECSEmailVIPUser *> *emailVIPUsers;

@end

#pragma mark - 设置邮件提醒VIP列表
@interface ECSSetEmailVIPListRequest : ECSExtendRequest

@property (nonatomic, copy) NSString *from;
@property (nonatomic, copy) NSString *publicAccount;
@property (nonatomic, strong) NSArray<ECSEmailVIPUser *> *emailVIPUsers;

@end

@interface ECSSetEmailVIPListAck : ECSExtendRequestAck

@property (nonatomic, copy) NSString *publicAccount;
@property (nonatomic, assign) NSInteger result;


@end


