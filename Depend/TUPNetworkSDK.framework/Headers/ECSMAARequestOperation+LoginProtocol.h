//
//  ECSMAARequestOperation+LoginProtocol.h
//  ECSIOSSDK
//
//  Created by huawei on 2017/1/5.
//  Copyright © 2017年 uc.huawei.com. All rights reserved.
//

#import "ECSMAARequestOperation.h"

@protocol ECSLoginProtocal <NSObject>
@property(nonatomic, copy) NSString *sessionId;
@property(nonatomic, assign) BOOL bCheckingNetwork;

- (void)restartHeartbeat;

- (void)stopHeartBeat;

- (void)sendHeartBeatFailed:(BOOL)checkNetwork;

- (void)logoutWithError:(NSError*) error
        completionBlock:(void (^)(NSError* error)) completionBlock;

- (void)forceReloginWithCompletionBlock:(void (^)(NSError* error)) completionBlock;

- (void)doCheckNetwork;

- (void)heartbeatTimeoutOffline:(NSError*)error;

- (BOOL)isLoginStatusSigning;

- (BOOL)isLoginStatusLogin;

@end

@interface ECSMAACoreOperation (LoginProtocol)

+ (void)setLoginProtocalDelegate:(id<ECSLoginProtocal>)loginDelegate;

+ (id<ECSLoginProtocal>)loginProtocalResponder;

@end
