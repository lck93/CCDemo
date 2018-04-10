/**
 * @file TUPMAALoginService.h
 *
 * Copyright © 2017 Huawei Tech. Co., Ltd. All rights reserved. \n
 *
 * @brief [en]Description:login server service component operation head file.
 * [cn]描述：登录服务器业务组件操作类头文件。 \n
 **/

#import <Foundation/Foundation.h>
#import "ECSLoginService.h"

/**
 * [en]This enum is about login auth type.
 * [cn]登录鉴权类型
 */
typedef NS_ENUM(NSUInteger, LOGINAUTHTYPE)
{
    LOGINAUTHTYPE_PassWord = 1,     /**< [en]Indicates password auth.
                                     <br>[cn]密码鉴权 */
    LOGINAUTHTYPE_fingerprint = 2,  /**< [en]Indicates finger print.
                                     <br>[cn]指纹鉴权 */
    LOGINAUTHTYPE_ticket = 3,       /**< [en]Indicates ticket auth.
                                     <br>[cn]ticket鉴权 */
    LOGINAUTHTYPE_token = 4         /**< [en]Indicates token auth.
                                     <br>[cn]token鉴权 */
};

typedef NS_ENUM(NSUInteger, LOGINSOCKETTYPE) {
    LOGINSOCKETTYPE_NORMAL,
    LOGINSOCKETTYPE_STG
};

/**
 * [en] This method is used to get login server service component operation.
 * [cn] 登录服务器业务组件操作类
 **/
@interface TUPMAALoginService : NSObject

@property(nonatomic, strong, readonly)ECSLoginService *loginService;
@property(nonatomic, assign) LOGINAUTHTYPE authType;//默认LOGINAUTHTYPE_PassWord
@property(nonatomic, assign) LOGINSOCKETTYPE socketType; // default vaule: LOGINSOCKETTYPE_NORMAL

/**
 * @brief [en] This method is used to get instance object.
 *        <br>[cn] 获取单例对象
 *
 * @retval instancetype                           <b>:</b><br>[en] Return an instance type.
 *                                                        <br>[cn] 返回一个单例对象
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
+ (instancetype) sharedInstance;


/**
 * @brief [en] This method is used to login with account.
 *        <br>[cn] 登录
 *
 * @param [in] NSString* account            <b>:</b><br>[en] Indicates account.
 *                                                  <br>[cn] 账号
 * @param [in] NSString* pw                 <b>:</b><br>[en] Indicates password.
 *                                                  <br>[cn] 密码
 * @param [in] NSArray* serverList           <b>:</b><br>[en] Indicates server list.
 *                                                  <br>[cn] 服务器地址列表
 * @param [in] NSString* token              <b>:</b><br>[en] Indicates single login token.
 *                                                  <br>[cn] 单点登录token，若无填空
 * @param [in] NSInteger retryCount         <b>:</b><br>[en] Indicates retry count after login failed.
 *                                                  <br>[cn] 登录失败后重登次数
 * @param [out] completionBlock             <b>:</b><br>[en] Indicates handle result block, carry error info.
 *                                                  <br>[cn] 处理结果Block，携带错误信息(NSError*)
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
- (void) loginWithAccount:(NSString*)account
                       pw:(NSString*)pw
               serverList:(NSArray<ECSSocketParam *> *)serverList
                 ssoToken:(NSString*)token
               retryCount:(NSInteger)retryCount
               completion:(void(^)(NSError* error))completionBlock;


/**
 * @brief [en] This method is used to logout.
 *        <br>[cn] 注销
 *
 * @param [out] completionBlock             <b>:</b><br>[en] Indicates handle result block, carry error info.
 *                                                  <br>[cn] 处理结果Block，携带错误信息(NSError*)
 * @attention [en] when logout , can do reasonable save and clean operation.
 *            <br>[cn] 注销，可在回调中进行合理的保存和清理动作
 * @see NA
 **/
- (void) logout:(void(^)(NSError* error))completionBlock;

@end
