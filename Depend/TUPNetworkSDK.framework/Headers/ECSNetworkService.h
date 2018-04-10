//
//  ECSNetworkService.h
//  eSpaceIOSSDK
//
//  Created by yemingxing on 2/6/15.
//  Copyright (c) 2015 huawei. All rights reserved.
//

//注意生成SDK时不要导出此头文件(不让调用者获得connect及disconnect的权限，只有子服务才可能使用到)

#import <Foundation/Foundation.h>
#import "ECSBaseService.h"
#import "ECSNetworkReachability.h"
#import "ECSSocketController.h"

#define TCP_VERSION 3
#define MAX_TIMEOUT_COUNT 2
#define ECS_SERVICE_THREAD [[ECSNetworkService sharedInstance] serviceThread]

extern NSInteger __timeoutCount;

typedef NS_ENUM(NSUInteger, ECServiceStatus) {
    ECServiceStatusInited = 0,
    ECServiceStatusConnectingSocket = 2,
    ECServiceStatusConnected,
    ECServiceStatusDisconnected,
    ECServiceStatusUnReachable,
    ECServiceStatusTerminate = 6,
};

typedef NS_ENUM(NSUInteger, ECSSvnTunnelStatus) {
    ECSSvnTunnelStatusOffline = 0,
    ECSSvnTunnelStatusOnline = 2,
    ECSSvnTunnelStatusConnecting
};

@protocol ECSNetworkServiceDelegate <NSObject>
- (void)checkNetwork;
- (void)netServiceSVNTunnelStatusChange:(ECSSvnTunnelStatus)svnTunnelStatus;
@end

@interface ECSNetworkService : NSObject

@property (nonatomic, assign) NSTimeInterval lastActionTimestamp;
@property (nonatomic, assign, readonly) NSTimeInterval avgResponseInterval;
@property (nonatomic, strong, readonly) NSOperationQueue* sendOperationQueue;
@property (nonatomic, strong, readonly) NSOperationQueue* receiveOperationQueue;
@property (nonatomic, strong, readonly) NSOperationQueue* loginQueue;
@property (nonatomic, strong, readonly) NSThread* serviceThread;
@property (nonatomic, strong, readonly) NSThread *reachableThread;
@property (nonatomic, assign) NSTimeInterval serviceTimeout;
@property (nonatomic, assign, readonly) ECServiceStatus serviceStatus;
@property (nonatomic, strong, readonly) NSArray<ECSSocketParam*> *hostList;
@property (nonatomic, copy, readonly) NSString* currentIPAddress;
@property (nonatomic, assign, readonly) NSUInteger currentPort;
@property (nonatomic, readonly) unsigned long socketBufferSize;
@property (nonatomic, readonly) ECSReachabilityStatus reachabilityStatus;
//@property (nonatomic, strong, readonly) ECSNetworkReachability* reachability;
@property (nonatomic, weak) id<ECSNetworkServiceDelegate> delegate;

@property (nonatomic, strong) NSString *mipLogPath;

+ (instancetype) sharedInstance;

- (void) registerSerivce:(ECSBaseService*) service;

- (void) connect:(NSArray<ECSSocketParam*> *)hostList
      completion:(void (^)(ECServiceStatus status, NSError *error))completionBlock;

- (void) disconnectWithError:(NSError*) error;

- (void) disconnectWithError:(NSError *)error waitUntilDone:(BOOL)needWait;

- (void) start;

- (void) stop;

- (void) updateResponseInterval:(NSTimeInterval) interval;

- (void) lockMAASendQueue;

- (void) unlockMAASendQueue;

- (void) waitMAASendQueue;

- (void) lockMAARecivQueue;

- (void) unlockMAARecivQueue;

- (void) waitMAARecivQueue;

- (BOOL) networkReachable;

- (BOOL) setSocketDSCP:(NSUInteger)DSCPValue;

- (void)createSVNTunnelWithCompletionBlock:(void (^)(BOOL bTunnelNetOnline, NSError *error))completionBlock;

- (void)configSocketTypeWithSTG:(BOOL)bSTGEnable andSVN:(BOOL)bSVNEnable;
@end

