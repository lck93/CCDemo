/**
 * @file TupIMessageService.h
 *
 * Copyright(C), 2012-2017, Huawei Tech. Co., Ltd. ALL RIGHTS RESERVED. \n
 *
 * @brief [en]Description:TUP IM relative service operation class head file.
 * [cn]描述：TUP 即时消息相关业务操作类头文件。 \n
 **/

#import <Foundation/Foundation.h>
#import <TUPIOSSDK/ChatSessionEntity.h>
#import <TUPIOSSDK/ChatMessageEntity.h>
#ifdef __cplusplus
#define ECS_EXTERN		extern "C"
#else
#define ECS_EXTERN		extern
#endif

/* [en]xxxx. [cn]点对点聊天消息通知 */
ECS_EXTERN NSString* const TUP_RECEIVE_SINGLE_MESSAGE_NOTIFY;
/* [en]xxxx. [cn]群组聊天消息通知 */
ECS_EXTERN NSString* const TUP_RECEIVE_GROUP_MESSAGE_NOTIFY;
/* [en]xxxx. [cn]部门通知消息通知 */
ECS_EXTERN NSString* const TUP_RECEIVE_DEPT_MESSAGE_NOTIFY;
/* [en]xxxx. [cn]消息撤回通知 */
ECS_EXTERN NSString* const TUP_MESSAGE_RECALLED_NOTIFY;
/* [en]xxxx. [cn]清空聊天记录通知 */

ECS_EXTERN NSString* const TUP_CLEAR_ALL_MESSAGE_NOTIFY;
ECS_EXTERN NSString* const TUP_MESSAGE_RECALLED_NOTIFY_KEY;
ECS_EXTERN NSString* const TUP_MESSAGE_RECALLED_NOTIFY_MSGSTATE_KEY;
ECS_EXTERN NSString* const TUP_MESSAGE_RECALLED_MEDIA_UM_NOTIFY_KEY;
ECS_EXTERN NSString* const TUP_MESSAGE_RECALLED_FILE_UM_NOTIFY_KEY;
ECS_EXTERN NSString* const TUP_RECEIVE_MESSAGE_NOTIFY_KEY;


/**
 * [en] This class is about IM relative service operation.
 * [cn] 即时消息相关业务操作类
 **/
@interface TupIMessageService : NSObject


/**
 * @brief [en] This method is used to get shared instance object.
 *        <br>[cn] 获取共享实例对象
 *
 * @attention [en] xxxx.
 *            <br>[cn] NA
 * @see NA
 **/
+ (instancetype) sharedInstance;

/**
 * @brief [en] This method is used to batch set message read and update status to server
 *        <br>[cn] 批量设置消息已读并更新已读状态至服务器
 *
 * @param [in] SessionEntity* session  <b>:</b><br>[en] Indicates session object.
 *                                             <br>[cn] 聊天会话对象
 * @attention [en] xxxx.
 *            <br>[cn] NA
 * @see NA
 **/
- (void) markRead:(SessionEntity*) session;

/**
 * @brief [en] This method is used to batch set message read
 *        <br>[cn] 批量设置消息已读
 *
 * @param [in] SessionEntity* session  <b>:</b><br>[en] Indicates session object.
 *                                             <br>[cn] 聊天会话对象
 * @attention [en] xxxx.
 *            <br>[cn] 同步操作，仅在本地进行标记消息为已读
 * @see NA
 **/
- (void) markReadLocal:(SessionEntity *)session;

/**
 * @brief [en] This method is used to set appointed message read
 *        <br>[cn] 设置指定消息已读
 *
 * @param [in] ChatSessionEntity* session  <b>:</b><br>[en] Indicates session object.
 *                                                 <br>[cn] 聊天会话对象
 * @param [in] ChatMessageEntity* chatMsg  <b>:</b><br>[en] Indicates wait delete session object.
 *                                                 <br>[cn] 待删除的聊天消息对象
 * @attention [en] xxxx.
 *            <br>[cn] NA
 * @see NA
 **/
- (void)MarkReadMessageRequest:(ChatSessionEntity*)session message:(ChatMessageEntity*)chatMsg;


/**
 * @brief [en] This method is used to delete message
 *        <br>[cn] 删除消息
 *
 * @param [in] NSArray* messages            <b>:</b><br>[en] Indicates wait delete message object(MessageEntity *) array need delete MessageEntity array, if it's empty represent delete all message of session object.
 *                                                  <br>[cn] 待删除的消息对象(MessageEntity *)数组要删除的MessageEntity数组，为空时表示删除会话对象下的全部消息
 * @param [in] SessionEntity* session       <b>:</b><br>[en] Indicates session object.
 *                                                  <br>[cn] 聊天会话对象
 * @param [in] ContactEntity* target        <b>:</b><br>[en] Indicates contact object.
 *                                                  <br>[cn] 联系人对象
 * @param [out] completionBlock             <b>:</b><br>[en] Indicates deeling result block, carry error message .
 *                                                  <br>[cn] 处理结果Block，携带错误信息(NSError*)
 */
- (void) deleteMessages:(NSArray*) messages
                session:(SessionEntity*)session
                 target:(ContactEntity*)target
        completionBlock:(void (^)(NSError* error)) completionBlock;


/**
 * @brief [en] This method is used to mark sending message failed
 *        <br>[cn] 设置消息发送失败标识
 *
 * @attention [en] Include IM、topic、comment、publicAccount message.
 *            <br>[cn] 包括IM、topic、comment、publicAccount message
 * @see NA
 **/
- (void) markSendingMessageToFailed;

#pragma mark 漫游消息id管理相关接口

/**
 * @brief [en] This method is used to get previous roaming minimun message id
 *        <br>[cn] 获取当前漫游的最小消息id
 *
 * @param [in] ContactEntity* contact           <b>:</b><br>[en] Indicates contact object(specific contact or group).
 *                                                      <br>[cn] 联系人对象(特定联系人或群组)
 * @retval NSString *                           <b>:</b><br>[en] Return minimum message id if success, or return nil .
 *                                                      <br>[cn] 成功返回最小消息id，失败返回nil
 * @attention [en] xxxx.
 *            <br>[cn] NA
 * @see NA
 **/
- (NSString*)previousMessageid:(ContactEntity*)contact;


/**
 * @brief [en] This method is used to get current roaming maximum message id
 *        <br>[cn] 获取当前漫游的最大消息id
 *
 * @param [in] ContactEntity* contact           <b>:</b><br>[en] Indicates contact object(specific contact or group).
 *                                                      <br>[cn] 联系人对象(特定联系人或群组)
 * @retval NSString *                           <b>:</b><br>[en] Return maximum message id if success, or return nil .
 *                                                      <br>[cn] 成功返回最大消息id，失败返回nil
 * @attention [en] xxxx.
 *            <br>[cn] NA
 * @see NA
 **/
- (NSString*)latestMessageId:(ContactEntity*)contact;


@end
