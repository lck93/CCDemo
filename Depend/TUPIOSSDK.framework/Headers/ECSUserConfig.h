/**
 * @file ECSUserConfig.h
 *
 * Copyright (c) 2015 Huawei Tech. Co., Ltd. All rights reserved. \n
 *
 * @brief [en]Description:user config service operation class head file.
 * [cn]描述：用户配置业务操作类头文件。 \n
 **/

#import <Foundation/Foundation.h>
#import "ECSDefines.h"


#define ECS_HEARTBEAT_DELAY                              2

/**
 * [en]This enum is about call mode.
 * [cn]呼叫方式
 */
typedef NS_ENUM(NSInteger, ECSCallModeType)
{
    ECSCallModeTypeUnknow = -1,         /**< [en]Indicates unknow.
                                         <br>[cn]未知 */
    ECSCallModeVoipType,                /**< [en]Indicates voip call type.
                                         <br>[cn]voip呼叫方式 */
    ECSCallModeCTDType,                 /**< [en]Indicates ctd call type.
                                         <br>[cn]CTD呼叫方式 */
    ECSCallModePhoneCallType            /**< [en]Indicates phone call type.
                                         <br>[cn]手机呼叫方式 */
};

/**
 * [en]This enum is about mobile contact match state.
 * [cn]手机通讯录匹配状态（内部使用不对外开放）
 */
typedef NS_ENUM(NSInteger, MatchMobileState) {
    MatchMobileStateDefault = 0,
    MatchMobileStateEnable,
    MatchMobileStateDisable
};

extern NSString* const ECSConfigsDBVersionKey;			// 键值类型：NSNumber of int，取值范围：NA，默认值：NA，描述：NA
extern NSString* const ECSConfigsTimestampKey;			// 键值类型：NSString，取值范围：NA，默认值：NA，描述：NA
extern NSString* const ECSConfigsRememberPasswordKey;	// 键值类型：NSNumber of bool，取值范围：NA，默认值：NA，描述：NA
extern NSString* const ECSConfigsAutoLoginKey;			// 键值类型：NSNumber of bool，取值范围：NA，默认值：NA，描述：NA
extern NSString* const ECSConfigsPasswordKey;			// 键值类型：NSString，取值范围：NA，默认值：NA，描述：NA
extern NSString* const ECSConfigsPasswordSaveTypeKey;   // 键值类型：NSNumber of PSW_PROTECT_TYPE，取值范围：NA，默认值：NA，描述：NA

extern NSString* const ECSConfigsContactModeKey;		// 键值类型：NSNumber of int，取值范围：NA，默认值：NA，描述：NA
extern NSString* const ECSConfigsDefaultModeKey;		// 键值类型：NSNumber of int，取值范围：NA，默认值：NA，描述：NA
extern NSString* const ECSConfigsPopupKey;				// 键值类型：NSNumber of bool，取值范围：NA，默认值：NA，描述：N
extern NSString* const ECSConfigsPhotoOrientationKey;	// 键值类型：NSNumber of int，取值范围：NA，默认值：NA，描述：NA
extern NSString* const ECSConfigsQuickRevertContentsKey;// 键值类型：NSArray，取值范围：NA，默认值：NA，描述：NA
extern NSString* const ECSConfigsVoiceMailNumberKey;	// 键值类型：NSString，取值范围：NA，默认值：NA，描述：NA

extern NSString* const ECSConfigsDBFileNameKey;			// 键值类型：NSString，取值范围：NA，默认值：NA，描述：NA
extern NSString* const ECSConfigsGuideViewVersionKey;	    // 键值类型：NSString，取值范围：NA，默认值：NA，描述：导引图对应版本号
extern NSString* const ECSConfigsHistoryGuideViewVersionKey;	// 键值类型：NSString，取值范围：NA，默认值：NA，描述：最近对话导引图对应版本号
extern NSString* const ECSConfigsContactGuideViewVersionKey;	// 键值类型：NSString，取值范围：NA，默认值：NA，描述：联系人导引图对应版本号
extern NSString* const ECSConfigsImGuideViewVersionKey;	    // 键值类型：NSString，取值范围：NA，默认值：NA，描述：im导引图对应版本号
extern NSString* const ECSConfigsWelcomeHintVersionKey; //键值类型：NSString，取值范围：NA，默认值：NA，描述:最近对话欢迎提示信息对应版本号
extern NSString* const ECSConfigsSettingCountryCodeKey; // 键值类型：NSString，取值范围：NA，默认值：NA，描述：强制设置国家码对应版本号

extern NSString* const ECSIsHttpsRequestKey;            // value type:NSNumber, ragnt:{0, 1}, 0表示不使用https协议，1表示使用https协议。
extern NSString* const ECSNewCircleTopicValueKey;       // value type:NSNumber, ragnt:{0, 1}, 0表示不存在新topic，1表示存在新topic。

extern NSString* const ECSProgramRunningInBackground;

extern NSString* const ECSConfigsIsVOIPAllowedKey;				// 键值类型：NSNumber of bool，取值范围：NA，默认值：NA，描述：N

extern NSString* const ECSPublicAccountTimestampKey; // 键值类型：NSString，取值范围：0或者服务器返回的时间戳，默认值：@"0"，描述：公众号时间戳

extern NSString* const kECSKeyCircleHasNewInvite;   // 键值类型：NSString，取值范围：YES/NO，默认值：NO，描述：是否有新的全邀请
extern NSString* const kECSKeyCircleStateSyncTimestamp; // 键值类型：NSString，取值范围：同事圈时间戳，默认值：@"0"，描述：全量同步时为@“0”

ECS_EXTERN NSString* const  ECSConfigIsFirstBfcpSildRemindKey;      // 键值类型：NSString，取值范围：NA，默认值：NA，描述：NA

#define IS_FUNC_ON(funcid, x) ((([(funcid) length]) > (x)) && (([(funcid) characterAtIndex:(x)]) == '1'))

@class ECSUserMAAInfo;
@class ECSTUPLoginAuthResult;

/**
 * [en] This class is about user config service operation.
 * [cn] 用户配置业务操作类
 **/
@interface ECSUserConfig : NSObject <NSCoding>

- (id) initWithAccount:(NSString*) account;

@property (nonatomic, copy) NSString* account;  //登录真实返回的账号，可能和初始化时不同
@property (nonatomic, copy) NSString* password;
@property (nonatomic, copy) NSString* token;
@property (nonatomic, assign) BOOL bFirstUse;
@property (nonatomic, assign) BOOL bRememberPassword;
@property (nonatomic, strong) NSNumber* dbVersion;
@property (nonatomic, strong) NSNumber* configVersion;
@property (nonatomic, strong) NSDate* lastSyncTimestamp;
@property (nonatomic, strong) NSDate* lastConfigSyncTimestamp;
@property (nonatomic, strong) NSString* serverSyncContactTimestamp;
@property (nonatomic, strong) ECSUserMAAInfo* maaInfo;
@property (nonatomic, assign) NSInteger batterySavingMode;
@property (nonatomic, assign) NSInteger lastSavedbatterySavingMode;//BATTERY_MODE
//@property (nonatomic, copy) NSString* latestServerAddress;
@property (nonatomic, strong) NSNumber* peopleNumber;
@property (nonatomic, strong) NSNumber* peopleRanking;
@property (nonatomic, strong) NSNumber* peopleSurpass;
@property (nonatomic, strong) NSString* circleStateSyncTimestamp;
@property (nonatomic, strong) NSNumber* isHaveNewCircleTopic;
@property (nonatomic, strong) NSNumber* isHaveNewCircleInvite;
@property (nonatomic, strong) NSNumber* unusedLightAppPaNums;
@property (nonatomic, strong) NSNumber* unusedLocalAppPaNums;
@property (nonatomic, strong) NSDate * recentSessionsSyncTimestamp;
@property (nonatomic, assign) BOOL isAutoLogin;
@property (nonatomic, assign) BOOL showWelcomeMessage;
@property (nonatomic, assign) ECSCallModeType callModeType;
@property (nonatomic, assign) BOOL vibrateValue;//打开:YES;关闭:NO

@property (nonatomic, copy)   NSString* countryCode;                //国家码
@property (nonatomic, assign) NSInteger imDisplayFont;              //聊天显示字体
@property (nonatomic, copy)   NSString* mainCall;                   //主叫号码(CTD回呼主叫号码,对应login响应mobile节点)
@property (nonatomic, assign) BOOL onlyShowOnline;                  //只显示在线好友
@property (nonatomic, assign) MatchMobileState matchMobileState;    //开启匹配手机通讯录, (0)默认值 (1)开启 (2关闭)
@property (nonatomic, assign) BOOL bAutoAccept;                     //是否开启自动接听功能
@property (nonatomic, assign) NSInteger autoAcceptTime;             //自动接听等待时长

@property (nonatomic, strong)NSNumber* isDisplayLBSInfo;                 //是否显示LBS信息
@property (nonatomic, copy)NSString *locationInfo;                  //LBS信息
@property (nonatomic, strong) NSMutableArray *lbsNameInfoArray;
@property (nonatomic, strong) NSMutableArray *lbsIdInfoArray;
@property (nonatomic, strong) NSString *lastPaSyncTimestamp;
@property (nonatomic, strong) NSString *customNumbers;//自定义号码，号码之间用“;”隔开

@property (nonatomic, assign) NSInteger incomingCallRing;           //来电铃声
@property (nonatomic, assign) NSInteger notifyAndBulletinRing;      //通知和公告铃声
@property (nonatomic, assign) NSInteger instantMessageRing;         //即时消息铃声
@property (nonatomic, assign) NSInteger voiceMailRing;              //语音留言铃声
@property (nonatomic, strong) NSMutableDictionary* bulletinInfos;      //系统通知信息,key:notifyId,value:NSNumber of bool
@property (nonatomic, assign) AESKEY_MODE aesMode;
@property (nonatomic, assign) BOOL isLocalCallPrompt;
@property (nonatomic, assign) BOOL isUmDownLoadPrompt;              //非wifi环境下下载UMResource时是否进行提示, YES 提示， NO 不提示。
@property (nonatomic, assign) BOOL AlertedPwUpdateTipFlag;//是否已经提示用户密码更新，默认为NO，即提示用户
@property (nonatomic, assign) BOOL isMaaConfEnable; //是否开启maa会议功能
@property (nonatomic, strong) NSNumber* increasedDbId;//记录本地消息存储id;递增;初始化为0
@property (nonatomic, copy) NSString *appID;
@property (nonatomic, copy) NSString *appName;
@property (nonatomic, assign) BOOL isShutCTDTip;    // 是否需要提示CTD信息界面
@property (nonatomic, assign) BOOL isMute;//0:静音 1：非静音
@property (nonatomic, assign) BOOL VoipPushSwitch; //是否打开voip后台来电提醒
@property (nonatomic, assign) BOOL userTempVoipPushSwitch; //用户临时设置的voip后台提醒，当业务登记响应后和voippushswitch值相同
@property (nonatomic, assign) NSInteger mutilTerminalRemindStatus;//-1:初始值;0:未置顶;1:置顶
@property (nonatomic, assign) BOOL isFirstBfcpSildRemind;//第一次辅流界面左滑提示

@property (nonatomic, strong) NSMutableDictionary *userGuiRemindInfo;

@property (nonatomic, retain)ECSTUPLoginAuthResult * uPortalServerInfo;


/**
 * @brief [en] This method is used to judge whether support function.
 *        <br>[cn] 判断是否支持某项功能
 *
 * @param [in] SUPPORT_FUNC_TYPE funcType         <b>:</b><br>[en] Indicates function type.
 *                                                        <br>[cn] 功能项
 * @retval BOOL *                                 <b>:</b><br>[en] Return yes if true, or return no.
 *                                                        <br>[cn] 是返回YES，否返回NO
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
- (BOOL)isSupportFunction:(SUPPORT_FUNC_TYPE)funcType;


/**
 * @brief [en] This method is used to judge whether is hwuc solution.
 *        <br>[cn] 判断是否为华为UC解决方案
 *
 * @retval BOOL *                   <b>:</b><br>[en] Return yes if true, or return no.
 *                                          <br>[cn] 是返回YES，否返回NO
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
- (BOOL)isHWUC;


/**
 * @brief [en] This method is used to judge whether is ipt solution.
 *        <br>[cn] 判断是否为IPT解决方案
 *
 * @retval BOOL *                   <b>:</b><br>[en] Return yes if true, or return no.
 *                                          <br>[cn] 是返回YES，否返回NO
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
- (BOOL)isIPTSolution;


/**
 * @brief [en] This method is used to judge whether is UC2.0 solution.
 *        <br>[cn] 判断是否为UC2.0解决方案
 *
 * @retval BOOL *                   <b>:</b><br>[en] Return yes if true, or return no.
 *                                          <br>[cn] 是返回YES，否返回NO
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
-(BOOL)isUCV2Solution;


/**
 * @brief [en] This method is used to judge whether is support calling via phone.
 *        <br>[cn] 判断是否支持显示使用手机拨打
 *
 * @retval BOOL *                   <b>:</b><br>[en] Return yes if true, or return no.
 *                                          <br>[cn] 是返回YES，否返回NO
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
- (BOOL)isSupportDisplayPhoneCall;


/**
 * @brief [en] This method is used to judge whether is hide mobile.
 *        <br>[cn] 判断是否隐藏移动号码
 *
 * @retval BOOL *                   <b>:</b><br>[en] Return yes if true, or return no.
 *                                          <br>[cn] 是返回YES，否返回NO
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
- (BOOL)hideMobileNum;


/**
 * @brief [en] This method is used to judge whether support mute conf.
 *        <br>[cn] 判断是否支持会议全场静音
 *
 * @retval BOOL *                   <b>:</b><br>[en] Return yes if true, or return no.
 *                                          <br>[cn] 是返回YES，否返回NO
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
-(BOOL)isSupportConfMuteAll;


/**
 * @brief [en] This method is used to judge whether has third part application link.
 *        <br>[cn] 判断是否有第三方应用链接
 *
 * @retval BOOL *                   <b>:</b><br>[en] Return yes if true, or return no.
 *                                          <br>[cn] 是返回YES，否返回NO
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
- (BOOL)hasThirdPartyAPPLink;


/**
 * @brief [en] This method is used to return third part application url.
 *        <br>[cn] 返回第三方应用URL
 *
 * @retval NSURL *                  <b>:</b><br>[en] Return an url string joint by account and code if success, or return nil.
 *                                          <br>[cn] 成功返回根据账号及密钥等信息拼接成一个URL字符串,失败返回nil
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
- (NSURL *)thirdPartyAppURL;


/**
 * @brief [en] This method is used to return third part application name.
 *        <br>[cn] 返回第三方应用名称
 *
 * @retval NSString *               <b>:</b><br>[en] Return third part application name if success, or return nul.
 *                                          <br>[cn] 成功返回返回第三方应用名称,失败返回nil
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
- (NSString *)thirdPartyAppName;


/**
 * @brief [en] This method is used to return third part application download url.
 *        <br>[cn] 返回第三方应用下载URL
 *
 * @retval NSURL *                  <b>:</b><br>[en] Return download url if success, or return nil.
 *                                          <br>[cn] 成功返回下载URL,失败返回nil
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
- (NSURL*)thirdPartyAppDownloadURL;


/**
 * @brief [en] This method is used to judge whether device is jail broken.
 *        <br>[cn] 判断设备是否越狱
 *
 * @retval BOOL *                   <b>:</b><br>[en] Return yes if true, or return no.
 *                                          <br>[cn] 是返回YES，否返回NO
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
- (BOOL)isJailbroken;


/**
 * @brief [en] This method is used to get jail break detect strategy.
 *        <br>[cn] 越狱检测策略
 *
 * @retval JAILBREAK_DETECT         <b>:</b><br>[en] Return jail break detect strategy config by server if success, default value JAILBREAK_DETECT_NONE.
 *                                          <br>[cn] 成功返回返回服务器配置的越狱检测策略,默认返回JAILBREAK_DETECT_NONE
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
- (JAILBREAK_DETECT)jailbreakStrategy;


/**
 * @brief [en] This method is used to get application heart beat time.
 *        <br>[cn] 程序的心跳时长
 *
 * @retval NSInteger                <b>:</b><br>[en] Return heart beat time (unit: minute) if success, default value 2 minutes.
 *                                          <br>[cn] 成功返回心跳时长（单位：分钟）,默认返回2分钟
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
- (NSInteger)heartBeatTime;

#pragma mark - um parameter


/**
 * @brief [en] This method is used to get  um voice record length.
 *        <br>[cn] 语音录制长度
 *
 * @retval NSUInteger               <b>:</b><br>[en] Return voice record length(unit:second), default value  600s.
 *                                          <br>[cn] 成功返回语音录制长度（单位：秒）,默认返回600秒
 * @attention [en] unit second.
 *            <br>[cn] 单位秒
 * @see NA
 **/
-(NSUInteger)UMVoiceRecordLength;


/**
 * @brief [en] This method is used to video size.
 *        <br>[cn] 视频大小
 *
 * @retval NSUInteger               <b>:</b><br>[en] Return video size if success, default value 20m.
 *                                          <br>[cn] 成功返回视频大小（单位：m）,默认返回20M
 * @attention [en] xxxx.
 *            <br>[cn] 单位m
 * @see NA
 **/
-(NSUInteger)UMVideoSize;


/**
 * @brief [en] This method is used to get video record length.
 *        <br>[cn] 视频录制长度
 *
 * @retval NSUInteger               <b>:</b><br>[en] Return video record length, default value 120s.
 *                                          <br>[cn] 成功返回视频录制长度（单位：秒）,默认返回120秒
 * @attention [en] xxxx.
 *            <br>[cn] 单位秒
 * @see NA
 **/
-(NSUInteger)UMVideoRecordLength;


/**
 * @brief [en] This method is used to judge whether audio record codec is amr.
 *        <br>[cn] 判断语音录制编解码是否为amr
 *
 * @retval BOOL *                   <b>:</b><br>[en] Return yes if true, or return no.
 *                                          <br>[cn] 是返回YES，否返回NO
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
-(BOOL)isUMCodecsAMR;


/**
 * @brief [en] This method is used to judge um transform mode is cloud drive.
 *        <br>[cn] 判断um传输模式是否采用云盘模式
 *
 * @retval BOOL *                   <b>:</b><br>[en] Return yes if true, or return no.
 *                                          <br>[cn] 是返回YES，否返回NO
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
-(BOOL)isUMModeUsingClouddrive;


/**
 * @brief [en] This method is used to judge whether current is battery saving mode.
 *        <br>[cn] 判断当前是否是省电模式
 *
 * @retval BOOL *                   <b>:</b><br>[en] Return yes if true, or return no.
 *                                          <br>[cn] 是返回YES，否返回NO
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
- (BOOL)isBatterySavingMode;


/**
 * @brief [en] This method is used to maximum message size.
 *        <br>[cn] 可发送消息最大长度
 *
 * @retval NSInteger                <b>:</b><br>[en] Return maximum message size if success, default value 5000 byte.
 *                                          <br>[cn] 成功返回发送消息的最大长度,默认返回5000字符
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
- (NSInteger)maxMsgSize;


/**
 * @brief [en] This method is used to judge whether support pc mute online and kick off pc.
 *        <br>[cn] 判断是否支持PC在线时静音以及踢PC下线
 *
 * @retval BOOL *                   <b>:</b><br>[en] Return yes if true, or return no.
 *                                          <br>[cn] 是返回YES，否返回NO
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
- (BOOL)isSupportMuteSelf;


/**
 * @brief [en] This method is used to judge whether support revoke message.
 *        <br>[cn] 判断是否支持消息撤回
 *
 * @retval BOOL *                   <b>:</b><br>[en] Return yes if true, or return no.
 *                                          <br>[cn] 是返回YES，否返回NO
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
- (BOOL)isSupportRevokeMsg;
@end
