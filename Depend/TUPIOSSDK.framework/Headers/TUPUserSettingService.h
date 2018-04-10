/**
 * @file TUPUserSettingService.h
 *
 * Copyright © 2017 Huawei Tech. Co., Ltd. All rights reserved. \n
 *
 * @brief [en]Description:set personal info basic service function class head file.
 * [cn]描述：设置个人信息基础业务功能类头文件。 \n
 **/

#import <Foundation/Foundation.h>
#import "EmployeeEntity.h"

/**
 * [en] This class is about set personal info basic service function.
 * [cn] 设置个人信息基础业务功能类
 **/
@interface TUPUserSettingService : NSObject

/**
 * @brief [en] This method is used to get instance object.
 *        <br>[cn] 获取单例对象
 *
 * @retval instancetype                           <b>:</b><br>[en] Return an instance object.
 *                                                        <br>[cn] 返回一个单例对象
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
+ (instancetype) sharedInstance;


/**
 * @brief [en] This method is used to set signature.
 *        <br>[cn] 设置签名
 *
 * @param [in] NSString* signature          <b>:</b><br>[en] Indicates signature content.
 *                                                  <br>[cn] 签名内容
 * @param [out] completionBlock             <b>:</b><br>[en] Indicates handle result block, carry error info.
 *                                                  <br>[cn] 处理结果Block，携带错误信息(NSError*)
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 */
- (void) setSelfSignature:(NSString*)signature completion:(void(^)(NSError* error))completionBlock;


/**
 * @brief [en] This method is used to set status.
 *        <br>[cn] 设置状态
 *
 * @param [in] ESpaceUserStatus status      <b>:</b><br>[en] Indicates status.
 *                                                  <br>[cn] 状态
 * @param [out] completionBlock             <b>:</b><br>[en] Indicates handle result block, carry error info.
 *                                                  <br>[cn] 处理结果Block，携带错误信息(NSError*)
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 */
- (void) setSelfStatus:(ESpaceUserStatus)status completion:(void(^)(NSError* error))completionBlock;

@end
