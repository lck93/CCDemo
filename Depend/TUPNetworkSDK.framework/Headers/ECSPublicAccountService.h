#import <Foundation/Foundation.h>
#import "ECSPublicAccountServiceMessage.h"
#import "ECSBaseService.h"

typedef void (^PaReqCompletionBlock)(ECSExtendRequestAck* retMsg, NSError* error);

@protocol ECSPublicAccountServiceDelegate <NSObject>
@optional
- (void) didReceivePublicAccountPushMsgNotify:(ECSPublicAccountPushMsgNotify *)paPushMsgNotify;
@end

@interface ECSPublicAccountService : ECSBaseService

@property (nonatomic, weak) id<ECSPublicAccountServiceDelegate> delegate;

/**
 *  同步公众号（全量/增量）
 *
 *  @param request         ECSSyncPublicAccountRequest
 *  @param completionBlock 完成回调
 */
- (void)sendSyncPaWithRequest:(ECSSyncPublicAccountRequest *)request
              completionBlock:(void (^)(ECSSyncPublicAccountAck *retMsg, NSError* error))completionBlock;

/**
 *  获取公众号头像
 *
 *  @param request         ECSQueryPaLogoRequest
 *  @param completionBlock 完成回调
 */
- (void)sendFetchLogoWithRequest:(ECSQueryPaLogoRequest *)request
                 completionBlock:(void (^)(ECSQueryPaLogoAck *retMsg, NSError* error))completionBlock;

/**
 *  请求公众号列表
 *
 *  @param request         ECSPublicAccountListRequest
 *  @param completionBlock 完成回调
 */
- (void)sendSearchPaListRequest:(ECSPublicAccountListRequest *)request
                completionBlock:(void (^)(ECSPublicAccountListAck *retMsg, NSError* error))completionBlock;

/**
 *  订阅公众号
 *
 *  @param request         ECSSubscribePublicAccountRequest
 *  @param completionBlock 完成回调
 */
- (void)sendSubscribePublicAccountRequest:(ECSSubscribePublicAccountRequest *)request
                          completionBlock:(void (^)(ECSSubscribePublicAccountAck *retMsg, NSError* error))completionBlock;

/**
 *  取消订阅公众号
 *
 *  @param request         ECSUnSubscribePublicAccountRequest
 *  @param completionBlock 完成回调
 */
- (void)sendUnSubscribePublicAccountRequest:(ECSUnSubscribePublicAccountRequest *)request
                          completionBlock:(void (^)(ECSUnSubscribePublicAccountAck *retMsg, NSError* error))completionBlock;

/**
 *  设置公众号push开关
 *
 *  @param request         ECSConfigPaPushAbilityRequest
 *  @param completionBlock 完成回调
 */
- (void)sendConfigPublicAccountPushAbility:(ECSConfigPaPushAbilityRequest *)request
                           completionBlock:(void (^)(ECSConfigPaPushAbilityAck *retMsg, NSError* error))completionBlock;

/**
 *  公众号消息置已读
 *
 *  @param request         ECSPublicAccountMsgMarkReadRequest
 *  @param completionBlock 完成回调
 */
- (void)sendMarkPublicAccountMsgReadedReques:(ECSPublicAccountMsgMarkReadRequest *)request
                             completionBlock:(void (^)(ECSPublicAccountMsgMarkReadAck * retMsg, NSError* error))completionBlock;

/**
 *  公众号请求消息
 *
 *  @param request         ECSPublicAccountRequestMsgRequest
 *  @param completionBlock 完成回调
 */
- (void)sendPublicAccountRequestMessageRequet:(ECSPublicAccountRequestMsgRequest *)request
                              completionBlock:(void (^)(ECSPublicAccountRequestMsgAck *retMsg, NSError* error))completionBlock;

/**
 *  请求公众号历史消息
 *
 *  @param reques          ECSQueryPublicAccountHistoryMsgRequest
 *  @param completionBlock 完成回调
 */
- (void)sendQueryPaHistoryMessageRequest:(ECSQueryPublicAccountHistoryMsgRequest *)request
                         completionBlock:(void (^)(ECSQueryPublicAccountHistoryMsgAck *retMsg, NSError* error))completionBlock;

/**
 *  全量同步轻应用公众号
 *
 *  @param request         ECSSyncLightAppPaRequest
 *  @param completionBlock 完成回调
 */
- (void)sendSyncLightAppPaRequest:(ECSSyncLightAppPaRequest *)request
                  completionBlock:(void (^)(ECSSyncLightAppPaAck *retMsg, NSError* error))completionBlock;

/**
 *  设置轻应用公众号已使用
 *
 *  @param request         ECSSetLightAppPaUsedRequest
 *  @param completionBlock 完成回调
 */
- (void)sendSetLightAppPaUsedRequest:(ECSSetLightAppPaUsedRequest *)request
                     completionBlock:(void (^)(ECSSetLightAppPaUsedAck *retMsg, NSError* error))completionBlock;

/**
 *  获取本地应用列表
 *
 *  @param request         ECSSyncLocalAppPaRequest
 *  @param completionBlock 完成回调
 */
- (void)sendGetLocalAppListRequest:(ECSSyncLocalAppPaRequest *)request completionBlock:(void(^)(ECSSyncLocalAppPaAck *retMsg, NSError *error))completionBlock;
/**
 *  获取邮件提醒VIP列表
 *
 *  @param request         ECSGetEmailVIPListRequest
 *  @param completionBlock 完成回调
 */
- (void)sendGetEmailVIPListWithRequest:(ECSGetEmailVIPListRequest *)request
                       completionBlock:(void (^)(ECSGetEmailVIPListAck* retMsg, NSError* error)) completionBlock;
/**
 *  设置邮件提醒VIP列表
 *
 *  @param request         ECSSetEmailVIPListRequest
 *  @param completionBlock 完成回调
 */
- (void)sendSetEmailVIPListWithRequest:(ECSSetEmailVIPListRequest *)request
                       completionBlock:(void (^)(ECSSetEmailVIPListAck* retMsg, NSError* error)) completionBlock;

@end
