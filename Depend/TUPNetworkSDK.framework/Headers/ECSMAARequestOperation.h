//
//  ECSMIPRequestOperation.h
//  eSpaceIOSSDK
//
//  Created by yemingxing on 2/13/15.
//  Copyright (c) 2015 huawei. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "mip.h"

#define ECS_MAA_REQ_RETRY_COUNT 1

typedef NS_ENUM(NSInteger, ECSRequestAckTcpType){
    ECSRequestAck_TCP_UNKNOWN = -1,
    ECSRequestAck_TCP_OK = 0,
    ECSRequestAck_TCP_CONNECTED,
    ECSRequestAck_TCP_TIMEDOUT,
    ECSRequestAck_TCP_UNREACHABLE,
    ECSRequestAck_TCP_CANCELLED,
};

typedef ctk::SharedPtr<mip::MsgCallback> MsgCallbackPtr;

@interface ECSMAACoreOperation : NSOperation {
@public
    mip::msg::BaseMsg::_Ptr _message;//发送的消息
    mip::msg::BaseMsg::_Ptr _ackMessage;//接收到得ack消息
    mip::msg::MsgId _ackMessageId;//ack消息id
@protected
    MsgCallbackPtr _sendMsgCallback;//ack消息处理callback
    MsgCallbackPtr _timeoutCallback;//发送消息超时callback
    NSUInteger _retryCount;//已经重试的次数
    NSError* _error;
    NSRecursiveLock* _lock;
    NSString *_sessionId;
}

@property (nonatomic, assign) NSTimeInterval operationTimeout;//超时时间，默认为servicetimeout
@property (nonatomic, assign) NSUInteger maxRetryCount;//最大重试次数，默认为ECS_MAA_REQ_RETRY_COUNT
@property (nonatomic, readonly, strong) NSError* error;
@property (nonatomic, readonly, copy) NSString* sessionId;
@property (nonatomic, assign) BOOL supportResend;//默认NO
@property (nonatomic, assign) ECSRequestAckTcpType resultTcpType;


//在service线程延时执行,不等待执行完成
- (void) ecsThreadPerformSelector:(SEL)aSelector withObject:(id)obj afterDelay:(NSTimeInterval) delay;
//operation超时
- (void) didRequestTimeout;
//任务开始前调用，重写时必须在函数末尾调用super doStart
- (void) doStart;
- (void) restart;
//任务结束前调用，重写时必须在函数末尾调用super doFinish
- (void) doFinish:(mip::msg::BaseMsg*) retObj withError:(NSError*) error;
/**
 *  判断当前的operation的socketSessionID是否与目标的socketSessionID一致
 *
 *  @param targetSessionID 需要比较的socketSessionID
 *
 *  @return YES表示一致，NO标示bu yi zhi
 */
- (BOOL) isSameSession:(NSString*)targetSessionID;

@end

@interface ECSMAARequestOperation : ECSMAACoreOperation

@end

@interface ECSMAALoginActionOperation : ECSMAACoreOperation

@end

@interface ECSMAASupportResendRequestOperation : ECSMAARequestOperation
@property (nonatomic, assign) NSInteger totalTimeout;//默认5分钟
@property (nonatomic, assign) NSInteger retryDuration;//默认失败后重发间隔10s
@property (nonatomic, strong) NSDate* operationStartTime;

- (BOOL)isOverTime;

/**
 *  消息重发
 */
- (void)resendRequest;
/**
 *  处理消息超时
 */
- (void)handleTimeout;
/**
 *  处理断网时TCP上报错误
 */
- (void)handleMaaCancelled;

@end
