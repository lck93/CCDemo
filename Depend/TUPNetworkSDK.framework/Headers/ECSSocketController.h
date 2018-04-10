//
//  ECSSocketController.h
//  eSpaceIOSSDK
//
//  Created by espacemobile on 11/10/15.
//  Copyright © 2015 huawei. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, ECSSocketStatus) {
    ECSSocketStatusUndefined = 0,
    ECSSocketStatusOffline,
//    ECSSocketStatusConnecting,
    ECSSocketStatusConnected,
    ECSSocketStatusUnreachable
};

@interface ECSSocketParam : NSObject
@property (nonatomic, copy, readonly)NSString *host;
@property (nonatomic, assign, readonly)NSUInteger port;

- (instancetype)initWithHost:(NSString *)host
                        port:(NSUInteger)port;
@end

@interface ECSSocketController : NSObject

@property (nonatomic, copy) NSString *currentMAAIP;
@property (nonatomic, assign) NSUInteger currentMAAPort;
@property (nonatomic, copy) NSString *currentSVNIP;
@property (nonatomic, readonly) NSDictionary *MAAIPList;
@property (nonatomic, readonly) NSDictionary *SVNIPList;
@property (nonatomic, readonly) ECSSocketStatus socketStatus;
@property (nonatomic, readonly) NSUInteger socketBufferSize;

- (instancetype)initWithThread:(NSThread *)workThread ;
- (BOOL)setSocketDSCP:(NSUInteger)DSCPValue;
- (BOOL)openSocket;
- (BOOL)closeSocket;
- (ECSSocketStatus)connectSocketToHost:(ECSSocketParam *)param
                               timeout:(NSTimeInterval)timeout
                           isSVNSocket:(BOOL)bSVNSocket;
- (void)stopConnecting;
- (BOOL)reconnectSocketTimeout:(NSTimeInterval)timeout;
- (BOOL)disconnectSocket;
- (BOOL)IPAddress:(NSMutableArray <NSString *> *)ipLists forDomain:(NSString *)domain error:(NSError **)error;
- (void)configTCPSocketType:(BOOL)bSTGEnable :(BOOL)bSVNEnable;
@end
