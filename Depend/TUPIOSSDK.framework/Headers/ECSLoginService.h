/**
 * @file ECSLoginService.h
 *
 * Copyright (c) 2015 Huawei Tech. Co., Ltd. All rights reserved. \n
 *
 * @brief [en]Description:Login server basic service function class head file.
 * [cn]描述：登录服务器基础业务功能类头文件。 \n
 **/

#import <Foundation/Foundation.h>
#import <TUPNetworkSDK/ECSBaseService.h>

#define CHECKVERION_TIMEDOUT_MAX						(15)
#define KEY_EXCHANGE_TIMEDOUT_MAX						(15)
#define LOGINACK_TIMEDOUT_MAX	                        (15)

extern NSString* keSpaceLoginStart;
extern NSString* keSpaceLoginFinished;
extern NSString* keSpaceCurrentUser;
extern NSString* keSpaceSocketDisconnect;
extern NSString* keSpaceNetworkChangedNotification;
extern NSString* keSpaceLoginWaitingForUIOperationNotification;
extern NSString* keSpaceLoginWaitingForUIOperationKey;

// SSO单点登录错误通知 object:nil userInfo:@{ECSCommonKeyErrorCode:@(ECSLoginErrorCode)}
extern NSString* const keSpaceLoginSSOErrorNotification;
extern NSString* const ECSCommonKeyErrorCode;					// 键值类型：NSNumber of ECSLoginErrorCode

/**
 * [en]This enum is about update type.
 * [cn]升级类型
 */
typedef NS_ENUM(NSUInteger, UPDATE_TYPE)
{
    UPDATE_TYPE_NO_UPDATE = 0,      /**< [en]Indicates no update.
                                     <br>[cn]不升级 */
    UPDATE_TYPE_FORCE_UPDATE = 1,   /**< [en]Indicates force update.
                                     <br>[cn]强制升级 */
    UPDATE_TYPE_OPTION_UPDATE = 2   /**< [en]Indicates option update.
                                     <br>[cn]可选升级 */
};

@interface ECSCheckVersionExtenalParam : NSObject
@property (nonatomic, readonly) dispatch_semaphore_t semp;
@property (nonatomic, readonly) NSDictionary *userInfo;
@property (nonatomic) BOOL bShouldGoOn;

/**
 * @brief [en] This method is used to init user info component.
 *        <br>[cn] 初始化用户信息组件
 *
 * @param [in] NSDictionary* userInfo             <b>:</b><br>[en] Indicates user info.
 *                                                        <br>[cn] 用户信息
 * @retval id *                                   <b>:</b><br>[en] Return this class instance object if success, or return nil.
 *                                                        <br>[cn] 成功返回该类的实例对象，失败返回nil
 * @attention [en] Indicates handle multi terminate login screne.
 *            <br>[cn] 处理多终端登录场景
 * @see NA
 **/
- (id)initWithUserInfo:(NSDictionary *)userInfo;

@end

/**
 * [en]This enum is about server login status.
 * [cn]服务器登录状态
 */
typedef NS_ENUM(NSUInteger, ECSLoginServiceStatus) {
    ECServiceOffline = 0,                   /**< [en]Indicates offline.
                                             <br>[cn]网络问题断线 */
    ECServiceSigning = 1,                   /**< [en]Indicates signing.
                                             <br>[cn]正在登录 */
    ECServiceLogin = 2,                     /**< [en]Indicates login success.
                                             <br>[cn]登录成功 */
    ECServiceKickOff = 3,                   /**< [en]Indicates kick off.
                                             <br>[cn]被踢 */
    ECServiceLogout = 4,                    /**< [en]Indicates logout active.
                                             <br>[cn]主动登出 */
    ECServiceInvalidAccountOrPassword = 5,  /**< [en]Indicates invalid account or password.
                                             <br>[cn]账号被锁或者无效、密码错误等错误 */
    ECServiceReconnecting = 6               /**< [en]Indicates reconnecting.
                                             <br>[cn]正在重新链接 */
};

@class ECSServerAbility;
@class ECSTUPLoginService;
@class ECSSocketParam;

@interface ECSLoginService : ECSBaseService

@property (nonatomic, strong, readonly) ECSServerAbility* serverAbility;
@property (nonatomic, readonly, assign) ECSLoginServiceStatus serviceStatus;    // 注意：KVO登录状态之后，必须不能做耗时、阻塞的动作！！！如果有可能耗时、阻塞，请异步放到其他线程实现！！！！
@property (nonatomic, copy, readonly) NSString* sessionId;
@property (nonatomic, copy, readonly) NSError *latestError;   // 上一次login发生的错误
@property (nonatomic, strong, readonly) ECSTUPLoginService *uPortalLoginService;

/**
 * @brief [en] This method is used to login with account.
 *        <br>[cn] 登录MAA接口
 *
 * @param [in] NSString* employeeNo         <b>:</b><br>[en] Indicates account.
 *                                                  <br>[cn] 账号
 * @param [in] NSString* password           <b>:</b><br>[en] Indicates password.
 *                                                  <br>[cn] 密码
 * @param [in] NSArray* serverList             <b>:</b><br>[en] Indicates server address list.
 *                                                  <br>[cn] 服务器地址
 * @param [in] NSString* ssoToken           <b>:</b><br>[en] Indicates token.
 *                                                  <br>[cn] token
 * @param [out] completionBlock             <b>:</b><br>[en] Indicates handle result block, carry  error info.
 *                                                  <br>[cn] 处理结果Block，携带错误信息(NSError*)
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 */
- (void) loginWithAccount:(NSString*) employeeNo
                 password:(NSString*) password
                   serverList:(NSArray<ECSSocketParam*> *) serverList
                 ssoToken:(NSString*) ssoToken
               completion:(void (^)(NSError* error)) completionBlock;


/**
 * @brief [en] This method is used to logout.
 *        <br>[cn] 注销接口
 *
 * @param [in] NSError* error               <b>:</b><br>[en] Indicates error.
 *                                                  <br>[cn] 此处可传nil
 * @param [out] completionBlock             <b>:</b><br>[en] Indicates handle result block, carry  error info.
 *                                                  <br>[cn] 处理结果Block，携带错误信息(NSError*)
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 */
- (void) logoutWithError:(NSError*) error completionBlock:(void (^)(NSError* error)) completionBlock;


/**
 * @brief [en] This method is used toget whether need delete key space data when logout.
 *        <br>[cn] 注销时是否需要删除共享区数据
 *
 * @param [in] BOOL bNeed                   <b>:</b><br>[en] Indicates whether need delete.
 *                                                  <br>[cn] 是否需要删除共享区数据
 * @param [out] completionBlock             <b>:</b><br>[en] Indicates handle result block, carry error info.
 *                                                  <br>[cn] 处理结果Block，携带错误信息(NSError*)
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 */
- (void)logoutWithDeleteKeySpaceData:(BOOL)bNeed completionBlock:(void (^)(NSError *))completionBlock;


/**
 * @brief [en] This method is used to force relogin.
 *        <br>[cn] 强制重新登录
 *
 * @param [out] completionBlock             <b>:</b><br>[en] Indicates handle result block, carry error info.
 *                                                  <br>[cn] 处理结果Block，携带错误信息(NSError*)
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 */
- (void)forceReloginWithCompletionBlock:(void (^)(NSError* error)) completionBlock;


/**
 * @brief [en] This method is used to check network when receive voip push.
 *        <br>[cn] 是否进行网络检查
 *
 * @attention [en] Whether do check network when receive voip push.
 *            <br>[cn] 收到voip推送时是否进行网络检查
 * @see NA
 **/
- (void) doCheckNetworkWhenReceiveVoipPush;


/**
 * @brief [en] This method is used to restart heart beat.
 *        <br>[cn] 重新发送首次心条
 *
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
- (void) restartHeartbeat;


/**
 * @brief [en] This method is used to check version.
 *        <br>[cn] 发送版本验证请求
 *
 * @param [in] NSString* account            <b>:</b><br>[en] Indicates account.
 *                                                  <br>[cn] 账号
 * @param [out] completionBlock             <b>:</b><br>[en] Indicates handle result block, carry error info.
 *                                                  <br>[cn] 处理结果Block，携带服务器能力和错误信息(ECSServerAbility*，NSError*)
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 */
- (void) checkVersion:(NSString*) account
      completionBlock:(void (^)(ECSServerAbility* ability, NSError* error))completionBlock;


/**
 * @brief [en] This method is used to send subscribe status request.
 *        <br>[cn] 发送“订阅状态”接口请求
 *
 * @param [in] BOOL yesOrNo                 <b>:</b><br>[en] Indicates subscribe or cancel subscribe.
 *                                                  <br>[cn] 订阅或取消订阅
 * @param [out] completionBlock             <b>:</b><br>[en] Indicates handle result block, carry error info.
 *                                                  <br>[cn] 处理结果Block，携带错误信息(NSError*)
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 */
-(void)sendSubscribeRequest:(BOOL)yesOrNo completion:(void (^)(NSError* error)) completionBlock;


/**
 * @brief [en] This method is used to keep svn alive in socket backgroud.
 *        <br>[cn] 保持svn的socket后台alive
 *
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
- (void)keepSocketAlive;


/**
 * @brief [en] This method is used to force prelogin anyoffice with completion.
 *        <br>[cn] 是否强制进行anyoffice预登录
 *
 * @param [out] completionBlock             <b>:</b><br>[en] Indicates handle result block, carry error info.
 *                                                  <br>[cn] 处理结果Block，携带错误信息(NSError*)
 * @retval BOOL                             <b>:</b><br>[en] Return invoke result, if true return yes, or return no.
 *                                                  <br>[cn] 调用结果，是返回YES，否返回NO
 */
- (BOOL)forcePreLoginAnyofficeWithCompletion:(void (^)(NSError *error))completionBlock;


/**
 * @brief [en] This method is used to get current MAA server ip address.
 *        <br>[cn] 获取当前连接的MAA服务器IP地址
 *
 * @retval NSString *               <b>:</b><br>[en] Return server ip address if success, or return nil.
 *                                          <br>[cn] 成功返回服务器IP地址，失败返回nil
 * @attention [en] NA
 *            <br>[cn] NA
 * @see NA
 **/
- (NSString*)MAAIPAddress;


/**
 * @brief [en] This method is used to get curren domain address.
 *        <br>[cn] 获取当前连接的MAA服务器域名
 *
 * @retval NSString *               <b>:</b><br>[en] Indicates handle result block, carry error info.
 *                                          <br>[cn] 成功返回服务器域名，失败返回nil
 * @attention [en] NA
 *            <br>[cn] NA
 * @see NA
 **/
- (NSString*)MAADomainAddress;


/**
 * @brief [en] This method is used to check whether is login ack error
 *        <br>[cn] 判断是否为鉴权错误
 *
 * @param [in] NSError* error                   <b>:</b><br>[en] Indicates error
 *                                                      <br>[cn] 错误码
 * @retval BOOL                                 <b>:</b><br>[en] Return yes if true, or return no
 *                                                      <br>[cn] 是返回YES，否返回NO
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
- (BOOL)isLoginAckError:(NSError *)error;


/**
 * @brief [en] This method is used to kick pc client.
 *        <br>[cn] 踢掉PC客户端
 *
 * @param [out] completionBlock             <b>:</b><br>[en] Indicates handle result block, carry error info.
 *                                                  <br>[cn] 处理结果Block，携带错误信息(NSError*)
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 */
- (void)kickPCClient:(void(^)(NSError* error))completionBlock;
@end
