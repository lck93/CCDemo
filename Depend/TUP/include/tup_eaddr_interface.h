 /** 
 * @file tup_eaddr_interface.h
 * 
 * Copyright(C), 2012-2016, Huawei Tech. Co., Ltd. ALL RIGHTS RESERVED. 
 * 
 * @brief [en]Description: TUP eaddr search component interface header files
 * [cn]描述：TUP 企业通讯录查询组件功能接口头文件.
 **/
 
#ifndef __TUP_EADDR_INTERFACE_H__
#define __TUP_EADDR_INTERFACE_H__   

#include "tup_eaddr_def.h"


#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cpluscplus */
#endif /* __cpluscplus */


/**
 * @defgroup eAddr
 * @brief [en]This module is about opened API interface
 *        <br>[cn] 开放的API接口
 **/

/**
 * @brief [en]callback to handle the result msg of searching.
 *        <br>[cn]处理异步返回消息的回调
 * 
 * @param [in] TUP_UINT32 id        <b>:</b><br>[en]the id for identifying the different type of result msg.
 *                                          <br>[en]id should be chose in the enum TUP_EADDR_E_RESULT_OPER_ID.
 *                                          <br>[en]If id equals TUP_EADDR_E_HANDLE_PERSONINFO ,etc id==0,it should handle the result msg from
 *                                          <br>[en]the API searching contactors,so the value type should be  TUP_EADDR_S_SEARCH_CONTACTOR_RESULT. 
 *                                          <br>[en]else if id equals TUP_EADDR_E_HANDLE_ICON,etc id ==1,it should handle the result msg from the API searching contactor's icon,
 *                                          <br>[en]so the value type should be TUP_EADDR_S_GETICON_RESULT.
 *                                          <br>[en]else if id equals TUP_EADDR_E_HANDLE_DEPTINFO,etc id ==3,it should handle the result msg from the API searching contactor's department,
 *                                          <br>[en]so the value type should be TUP_EADDR_S_SEARCH_DEPT_RESULT.
 *                                          <br>[en]the caller should specify the operation for different result msg above.
 *                                          <br>[cn]表示不同的消息处理回调id
 *                                          <br>[cn]id 的值会在枚举值TUP_EADDR_E_RESULT_OPER_ID中变化，当id等于TUP_EADDR_E_HANDLE_PERSONINFO,即id==0时,
 *                                          <br>[cn]回调应当进入处理联系人查询返回结果消息分支，value值应为TUP_EADDR_SEARCH_CONTACTOR_RESULT类型。
 *                                          <br>[cn]当id等于TUP_EADDR_E_HANDLE_ICON,即id==1时回调应当进入处理联系人头像查询返回结果消息分支, 
 *                                          <br>[cn]value值应为TUP_EADDR_S_GETICON_RESULT类型。 
 *                                          <br>[cn]当id 等于TUP_EADDR_E_HANDLE_DEPTINFO,即id == 3时回调应当进入处理联系人部门查询返回结果消息分支， 
 *                                          <br>[cn]value值应为TUP_EADDR_SEARCH_DEPT_RESULT类型。 
 * @param [in] (TUP_VOID*)Value     <b>:</b><br>[en]msg content
 *                                          <br>[cn]消息内容
 * @retval TUP_VOID 
 * 
 * @attention NA
 * @see  tup_eaddr_init
 **/
typedef void (*TUP_EADDR_FN_CALLBACK_PTR)(unsigned int ,void*);

/**
 * @ingroup eAddr
 * @brief [en]Interface for setting logfile path.
 *        <br>[cn]设置日志路径 
 * 
 * @param [in] const TUP_EADDR_S_LOG_PARA *log_para        <b>:</b><br>[en]log parameters.
 *                                                                 <br>[cn]日志设置信息
 * @retval TUP_RESULT  <b>:</b><br>[en]The operation is successful if VOS_OK is returned; otherwise, the operation fails.
 *                                              <br>[cn]成功返回VOS_OK，失败返回相应错误码
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_eaddr_set_log(const TUP_EADDR_S_LOG_PARA *log_para);

/**
 * @ingroup eAddr
 * @brief [en]Interface for init: create a thread and msg quene,register a callback
 *        <br>[cn]初始化:起线程，起消息队列，注册回调 
 * 
 * @param [in] TUP_EADDR_FN_CALLBACK_PTR tup_eaddr_callback        <b>:</b><br>[en]callback function.
 *                                                                         <br>[cn]回调函数
 * @retval TUP_RESULT <b>:</b><br>[en]The operation is successful if VOS_OK is returned; otherwise, the operation fails.
 *                            <br>[cn]成功返回VOS_OK，失败返回相应错误码
 * 
 * @attention NA
 * @see TUP_EADDR_FN_CALLBACK_PTR
 * @see tup_eaddr_uninit
 **/
TUP_API TUP_RESULT tup_eaddr_init(TUP_EADDR_FN_CALLBACK_PTR tup_eaddr_callback);

/**
 * @ingroup eAddr
 * @brief [en]Interface for setting uportal parameters and token.
 *        <br>[cn]设置uportal参数和token 
 * 
 * @param [in] TUP_EADDR_S_UPORTAL_CONFIG * uportal_config        <b>:</b><br>[en]structure of the uportal configuration.
 *                                                                        <br>[cn]uportal 参数
 * @retval TUP_RESULT <b>:</b><br>[en]The operation is successful if VOS_OK is returned; otherwise, the operation fails.
 *                            <br>[cn]成功返回VOS_OK，失败返回相应错误码
 * 
 * @attention [en]This function should be invoked before set Icon.
 *            <br>[cn]建议每次上传头像前设置
 * @see NA
 **/
TUP_API TUP_RESULT tup_eaddr_config(TUP_EADDR_S_UPORTAL_CONFIG * uportal_config);

/**
 * @ingroup eAddr
 * @brief [en]Interface for setting system icon.
 *        <br>[cn]设置系统头像 
 * 
 * @param [in] TUP_UINT32 icon_id        <b>:</b><br>[en]id for system icon.
 *                                               <br>[cn]系统头像序号
 * @retval TUP_RESULT <b>:</b><br>[en]The operation is successful if VOS_OK is returned; otherwise, the operation fails.
 *                            <br>[cn]成功返回VOS_OK，失败返回相应错误码
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_eaddr_set_sysicon(TUP_UINT32 icon_id);

/**
 * @ingroup eAddr
 * @brief [en]Interface for setting self_defined icon.
 *        <br>[cn]设置自定义头像 
 * 
 * @param [in] const TUP_EADDR_S_ICON* icon_info <b>:</b><br>[en]self-defined icon info.
 *                                                       <br>[cn]自定义头像信息
 * @param [out] TUP_CHAR* modify_time             <b>:</b><br>[en]icon-modified time.
 *                                                       <br>[cn]头像更改时间,空间由产品提供
 * @param [in] TUP_UINT32 len                    <b>:</b><br>[en]icon-modified time string length.
 *                                                       <br>[cn]头像更改时间的字符串长度
 * @retval TUP_RESULT <b>:</b><br>[en]The operation is successful if VOS_OK is returned; otherwise, the operation fails.
 *                            <br>[cn]成功返回VOS_OK，失败返回相应错误码
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_eaddr_set_deficon( const TUP_EADDR_S_ICON* icon_info,  TUP_CHAR *modify_time, TUP_UINT32 len);

/**
 * @ingroup eAddr
 * @brief [en]Interface for searching contactor info.
 *        <br>[cn]搜索联系人 
 * 
 * @param [in] const TUP_EADDR_S_SEARCH_PARAM* search_param        <b>:</b><br>[en]searching configuration parameters.
 *                                                                         <br>[cn]查询服务器配置参数
 * @retval TUP_RESULT <b>:</b><br>[en]The operation is successful if VOS_OK is returned; otherwise, the operation fails.
 *                            <br>[cn]成功返回VOS_OK，失败返回相应错误码
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_eaddr_search_contactor( const TUP_EADDR_S_SEARCH_PARAM* search_param);

/**
 * @ingroup eAddr
 * @brief [en]Interface for get contactor icon.
 *        <br>[cn]搜索联系人头像 
 * 
 * @param [in] const TUP_EADDR_S_ICON_PARAM* icon_param        <b>:</b><br>[en]getting contactor icon configuration parameters.
 *                                                                     <br>[cn]查询头像服务器配置参数
 * @retval TUP_RESULT <b>:</b><br>[en]The operation is successful if VOS_OK is returned; otherwise, the operation fails.
 *                            <br>[cn]成功返回VOS_OK，失败返回相应错误码
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_eaddr_get_usericon(const TUP_EADDR_S_ICON_PARAM* icon_param);

/**
 * @ingroup eAddr
 * @brief [en]Interface for searching contactor department.
 *        <br>[cn]搜索联系人部门
 * 
 * @param [in] const TUP_EADDR_S_DEP_PARAM *pstDep        <b>:</b><br>[en]searching department configuration parameters.
 *                                                                <br>[cn]查询部门服务器配置参数
 * @retval TUP_RESULT <b>:</b><br>[en]The operation is successful if VOS_OK is returned; otherwise, the operation fails.
 *                            <br>[cn]成功返回VOS_OK，失败返回相应错误码
 * 
 * @attention NA
 * @see NA
 **/
TUP_API TUP_RESULT tup_eaddr_search_department(const TUP_EADDR_S_DEP_PARAM *pstDep);



/**
 * @ingroup eAddr
 * @brief [en]Interface for uninit
 *        <br>[cn]去初始化
 * 
 * @param NA
 * @retval VOS_VOID 
 * 
 * @attention NA
 * @see tup_eaddr_init
 **/
TUP_API TUP_VOID tup_eaddr_uninit();

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cpluscplus */
#endif /* __cpluscplus */


#endif /* __TUP_EADDR_INTERFACE_H__ */
