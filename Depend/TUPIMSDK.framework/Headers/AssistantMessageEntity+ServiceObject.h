/**
 * @file AssistantMessageEntity+ServiceObject.h
 *
 * Copyright(C), 2012-2017, Huawei Tech. Co., Ltd. ALL RIGHTS RESERVED. \n
 *
 * @brief [en]Description:TUP group member manager operation class head file.
 * [cn]描述：TUP 群组成员管理操作类头文件。 \n
 **/
#import <TUPIOSSDK/AssistantMessageEntity.h>


@class EmployeeCategoryEntity;

/**
 * [en] This class is about group member manager operation.
 * [cn] 群组成员管理操作类
 **/
@interface AssistantMessageEntity (ServiceObject)

/**
 * @brief [en]This method is used to accept group join invitation.
 *        <br>[cn] 接受加入群组邀请
 *
 * @param [out] completionBlock              <b>:</b><br>[en] Indicates deeling result block, carry error message.
 *                                                  <br>[cn] 处理结果Block，携带错误信息(NSError*)
 **/
- (void) acceptGroupInvite:(void (^)(NSError* error)) completionBlock;

/**
 * @brief [en]This method is used to reject group join invitation.
 *        <br>[cn] 拒绝加入群组邀请
 *
 * @param [out] completionBlock              <b>:</b><br>[en] Indicates deeling result block, carry error message.
 *                                                  <br>[cn] 处理结果Block，携带错误信息(NSError*)
 **/
- (void) rejectGroupInvite:(void (^)(NSError* error)) completionBlock;

/**
 * @brief [en]This method is used to accept friend invitation and add him to appointed contact group.
 *        <br>[cn] 接受好友邀请并且把他加入自己的指定联系人分组
 *
 * @param [in] EmployeeCategoryEntity* category     <b>:</b><br>[en] Indicates contact group.
 *                                                          <br>[cn] 联系人分组
 * @param [out] completionBlock              <b>:</b><br>[en] Indicates deeling result block, carry error message.
 *                                                  <br>[cn] 处理结果Block，携带错误信息(NSError*)
 **/
- (void) acceptFriendInviteInCategory:(EmployeeCategoryEntity*)category completionBlock:(void (^)(NSError *error))completionBlock;

@end
