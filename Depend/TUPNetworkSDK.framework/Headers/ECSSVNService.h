//
//  ECSSVNService.h
//  eSpaceIOSSDK
//
//  Created by espacemobile on 15/7/14.
//  Copyright (c) 2015年 huawei. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SvnSdk/NetStatusManager.h>
//#import <SvnSdk/LoginParam.h>
#import <UIKit/UIKit.h>
#import <SvnSdk/LoginAgent.h>
#import <SvnSdk/svn_define.h>
#import <SvnSdk/anyoffice_keyspace.h>

typedef void (^SVNGatewayAuthCompleteBlock )(NSError *error);

typedef NS_ENUM(NSInteger, ECSSVNErrorCode) {
    ECSSVNErrTunnelShakeHandsFailed = -1,       // 与安全网关握手失败
    ECSSVNErrAuthGetWayNotConnectable = -4,     // 安全认证网关不通
    ECSSVNErrAuthWrongPwd = -5,                 // 安全认证帐号密码错误
    ECSSVNErrTunnelSelfDisconnected = -9,       // espace主动销毁隧道
    ECSSVNErrAuthAccountKickOff = -11,          // 登录安全网关的帐号被踢
    ECSSVNErrAuthAccountLocked = -16,           // 安全认证帐号被锁
    
    
    ECSSVNErrUnknownError = 1000
};

#pragma mark - ECSSVNService define.

@interface ECSSVNLoginParam : NSObject
@property (nonatomic, copy) NSString *hostname;
@property (nonatomic) NSUInteger hostport;
@property (nonatomic, copy) NSString *svnAccount;
@property (nonatomic, copy) NSString *svnPswd;

- (id)init;
- (void)wait;
- (void)signal;
- (void)waitUntilTimeOut:(NSTimeInterval)timeoutSeconds;
@end

#pragma info - ECSSVNService
@interface ECSSVNService : NSObject<NetChangeCallbackDelegate, LoginDelegate>
{
}

@property (nonatomic, strong, readonly) NSLock *lock4anyofficeCtx;
@property (nonatomic, assign, readonly) NET_STATUS_EN svnServiceStatus;
@property (nonatomic, strong, readonly) NSError *latestError;
@property (nonatomic, assign, readonly) BOOL isSVNValid;
@property (nonatomic, assign, readonly) BOOL hasLoginAnyOffice; // 是否已经成功登录了anyoffice。
@property (nonatomic, strong, readonly) NSString *currentUserName4eSDK;

@property (nonatomic, copy) NSString *svnSdkFilePath;
@property (nonatomic, copy) NSString *svnLogPath;
@property (nonatomic, copy) NSBundle *bundle;

+ (ECSSVNService *)shareInstance;
+ (void)destoryInstance;

/**
 *  AnyOffice sdk初始化方法，所有依赖AnyOffice sdk的功能都需要首先调用此函数初始化: 
 *  1. svn安全隧道；
 *  2. svn文件加密存储；
 *
 *  @param userName 用户帐号
 *
 *  @return YES：初始化成功，NO：初始化失败
 */
- (BOOL)eSDKInitWithUserName:(NSString *)userName;
- (BOOL)unInitESDK;

/**
 *  create svn tunnel
 *
 *  @param paramDic tunnel create param dic
 */
- (void)startSVN:(ECSSVNLoginParam *)paramD completion:(SVNGatewayAuthCompleteBlock)completion;
/**
 *  登录AnyOffice服务器
 *
 *  @param loginParam      登录参数（anyOffice单点登录时候与非单点登录两者有区别）
 *  @param completionBlock 完成登录之后的callback
 *
 *  @return YES：登录接口调用成功，NO：登录接口调用失败
 */
- (BOOL)loginAnyOfficeWithLoginInfo:(LoginParam *)loginParam completion:(SVNGatewayAuthCompleteBlock)completionBlock;

- (void)cleanSVNSocket:(BOOL)bForce;
- (void)keepSVNSocketAlive;
- (NSString*)getSVNVirtualIpAddress;

@end

#pragma mark KeyChainAccessGroup
@interface ECSSVNService (KeyChainAccessGroup)
- (NSString *)valueFromAnyOfficeKeySpaceWithKey:(NSString *)strKey error:(NSError **)error;
- (BOOL)setValue:(NSString *)value toAnyOfficeKeySpaceWithKey:(NSString *)strKey;
- (BOOL)deleteValueFromAnyOfficeKeySpaceWithKey:(NSString *)strKey;

- (NSString *)userAccountFromAnyOffcieKeySpace;
- (BOOL)setUserAccountToAnyOffcieKeySpace:(NSString *)account;

- (NSString *)userPasswordFromAnyOffcieKeySpace;
- (BOOL)setUserPasswordFromAnyOffcieKeySpace:(NSString *)p;

- (void)deleteKeySpaceData;
@end
