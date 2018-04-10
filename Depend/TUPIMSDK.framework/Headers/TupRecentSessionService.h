/**
 * @file TupRecentSessionService.h
 *
 * Copyright(C), 2012-2017, Huawei Tech. Co., Ltd. ALL RIGHTS RESERVED. \n
 *
 * @brief [en]Description:TUP recent session function class head file.
 * [cn]描述：TUP 最近会话功能类头文件。 \n
 **/

#import <Foundation/Foundation.h>

@class ChatSessionEntity;

/**
 * [en] This class is about recent session service.
 * [cn] 最近会话功能类
 **/
@interface TupRecentSessionService : NSObject


/**
 * @brief [en] This method is used to get shared instance object.
 *        <br>[cn] 获取共享实例对象
 *
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
+ (instancetype) sharedInstance;

/**
 * @brief [en] This method is used to query recent session.
 *        <br>[cn] 查询最近对话
 *
 * @param [out] completionBlock                    <b>:</b><br>[en] Indicates deeling result block, carry error message.
 *                                                         <br>[cn] 处理结果Block，携带错误信息(NSError*)
 **/
- (void) queryRecentSessions:(void(^)(NSError* error))completionBlock;

/**
 * @brief [en] This method is used to clean recent session.
 *        <br>[cn] 清除最近对话
 *
 * @param [out] completionBlock                    <b>:</b><br>[en] Indicates deeling result block, carry error message.
 *                                                         <br>[cn] 处理结果Block，携带错误信息(NSError*)
 **/
- (void) cleanRecentSessions:(void(^)(NSError* error))completionBlock;

/**
 * @brief [en] This method is used to clean recent chat unread count.
 *        <br>[cn] 清零最近对话未读数目
 *
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
- (void)cleanRecentChatUnreadCount;

/**
 * @brief [en] This method is used to delete single chatSession object
 *        <br>[cn]删除单个聊天对象
 *
 * @param [in] ChatSessionEntity* session     <b>:</b><br>[en] Indicates session object.
 *                                                    <br>[cn] 聊天对象
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
- (void)deleteChatSession:(ChatSessionEntity *)session;
@end
