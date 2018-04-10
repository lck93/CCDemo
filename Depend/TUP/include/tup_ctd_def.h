/** 
* @file ctd_def.h
* 
* Copyright(C), 2012-20157, Huawei Tech. Co., Ltd. ALL RIGHTS RESERVED. \n
* 
* @brief [en]Description: The header file of ctd subsystem basic service function structure definition.
* 描述：TUP CTD子系统基础业务功能结构体定义头文件。 \n
*/


#ifndef __CTD_DEF_H__
#define __CTD_DEF_H__

#include "tup_def.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /*  __cpluscplus */
#endif /*  __cpluscplus */

#define CTD_D_MAX_NUMBER_LEN 128                     /**< [en]Indicates the maximum length of number length
                                                          <br>[cn]号码最大长度  */
#define CTD_D_MAX_TOKEN_LEN  256                     /**< [en]Indicates the maximum length of token length
                                                          <br>[cn]token最大长度  */
#define CTD_D_MAX_SERVER_ADDR_LEN 256                /**< [en]Indicates the maximum length of server address length
                                                          <br>[cn]服务器地址最大长度  */
#define CTD_USER_NAME_LENGTH      64                 /**< [en]Indicates the maximum length of name length
                                                          <br>[cn]名称最大长度  */
#define CTD_USER_PASSWORD_LENGTH  32                 /**< [en]Indicates the maximum length of password length
                                                          <br>[cn]密码最大长度  */
/** 
 * [en]This struct is used to describe the param of ctd call
 * [cn]ctd呼叫相关参数
 */
typedef struct tagCTD_S_CALL_PARAM
{
    TUP_CHAR caller_number[CTD_D_MAX_NUMBER_LEN];    /**< [en]Indicates the caller number
                                                          <br>[cn]主叫号码  */
    TUP_CHAR callee_number[CTD_D_MAX_NUMBER_LEN];    /**< [en]Indicates the callee number
                                                          <br>[cn]被叫号码  */
    TUP_CHAR token[CTD_D_MAX_TOKEN_LEN];             /**< [en]Indicates the authentification token
                                                          <br>[cn]鉴权token */
    TUP_CHAR subscribe_number[CTD_D_MAX_NUMBER_LEN]; /**< [en]Indicates the subscribe number
                                                          <br>[cn]订阅号码  */
} CTD_S_CALL_PARAM;

/**
 * [en]This stuct is used to describe server address.
 * [cn]服务器地址
 */
typedef struct tagCTD_S_SERVER_PARA
{
    TUP_CHAR   server_addr[CTD_D_MAX_SERVER_ADDR_LEN]; /**< [en]Indicates server address. [cn]服务器地址 */
    TUP_UINT16 port;                                   /**< [en]Indicates port. [cn]端口号 */
} CTD_S_SERVER_PARA;

/** 
 * [en]This struct is used to describe the http proxy information.
 * [cn]代理信息
 */
typedef struct tagCTD_S_PROXY_PARAM
{  
    TUP_CHAR uri[CTD_D_MAX_SERVER_ADDR_LEN];          /**< [en]Indicates the server address. [cn]代理服务器url*/
    TUP_UINT32 port;                                  /**< [en]Indicates the server port. [cn]代理服务器端口*/
    TUP_CHAR user_name[CTD_USER_NAME_LENGTH];         /**< [en]Indicates the account user name. [cn]代理服务器鉴权用户名*/
    TUP_CHAR password[CTD_USER_PASSWORD_LENGTH];      /**< [en]Indicates the account password. [cn]代理服务器鉴权密码*/
} CTD_S_PROXY_PARAM;

/**
 * [en]Log level
 * [cn]日志级别
 */
typedef enum tagCTD_E_LOG_LEVEL
{
    CTD_E_LOG_ERROR = 0,       /**< [en]Error level
                                    <br>[cn]错误级别 */
    CTD_E_LOG_WARNING,         /**< [en]Warning level
                                    <br>[cn]警告级别 */     
    CTD_E_LOG_INFO,            /**< [en]Info level
                                    <br>[cn]一般级别 */      
    CTD_E_LOG_DEBUG            /**< [en]Debug level
                                    <br>[cn]调试级别 */      
} CTD_E_LOG_LEVEL;


/** 
 * [en]This enum is used to describe event which is reported to interface<br>
 * [cn]上报给界面的事件
 */
typedef enum tagCTD_E_EVENT
{
    CTD_E_EVT_BEGIN = 0,

    CTD_E_EVT_START_CALL_RESULT,   /**< [en]Indicates the result of start ctd call
                                        <br>[cn]发起ctd呼叫结果
                                        <br>param1：callid
                                        <br>param2：result
                                        <br>data：  无  */       
    CTD_E_EVT_END_CALL_RESULT,     /**< [en]Indicates the result of end ctd call
                                        <br>[cn]发起ctd呼叫结果
                                        <br>param1：callid
                                        <br>param2：result
                                        <br>data：  无  */    
    CTD_E_EVT_CALL_STATUS_NOTIFY,  /**< [en]Indicates the ctd call status notify
                                        <br>[cn]ctd呼叫状态上报
                                        <br>param1：callid
                                        <br>param2：CTD_E_CALL_STATE
                                        <br>data：  无  */    
    CTD_E_EVT_END
} CTD_E_EVENT;

/** 
 * [en]This enum is used to describe error code of ctd module<br>
 * [cn]ctd模块错误码
 */
typedef enum tagCTD_E_ERR_ID
{
    CTD_E_ERR_BEGIN = 0,                         /**< [en]begin
                                                      <br>[cn]起始 */
    CTD_E_ERR_GENERAL,                           /**< [en]Indicates general error
                                                      <br>[cn]一般错误 */
    CTD_E_ERR_PARAM_ERROR,                       /**< [en]Indicates param error
                                                      <br>[cn]参数错误 */
    CTD_E_ERR_TIMEOUT,                           /**< [en]Indicates timeout
                                                      <br>[cn]超时 */
    CTD_E_ERR_MEM_ERROR,                         /**< [en]Indicates MEM error
                                                      <br>[cn]分配内存错误 */
    CTD_E_ERR_DNS_ERROR,                         /**< [en]Indicates DNS parser error
                                                      <br>[cn]DNS解析异常 */
    CTD_E_ERR_REQUEST_FAILED,                    /**< [en]Indicates request failed
                                                      <br>[cn]请求消息异常 */
    CTD_E_ERR_AUTH_FAILED,                       /**< [en]Indicates authentication failed
                                                      <br>[cn]鉴权失败 */
    CTD_E_ERR_SERVICE_ERROR,                     /**< [en]Indicates service error
                                                      <br>[cn]服务器异常 */
    CTD_E_ERR_ACCOUNT_LOCKED,                    /**< [en]Indicates the account is locked
                                                      <br>[cn]账号被锁定 */
} CTD_E_ERR_ID;

/** 
 * [en][en]This enum is used to describe ctd status of ctd module<br>.
 * [cn]CTD 呼叫状态
 */
typedef enum tagCTD_E_CALL_STATE
{
    CTD_E_CALL_STATE_IDLE = 0,                      /**< [en]Indicates idle status
                                                        <br>[cn]空闲态*/
    CTD_E_CALL_STATE_CALLING,                       /**< [en]Indicates calling status
                                                        <br>[cn]呼叫中 */
    CTD_E_CALL_STATE_TALKING,                       /**< [en]Indicates talking status
                                                        <br>[cn]通话中 */
    CTD_E_CALL_STATE_END,                           /**< [en]Indicates end status
                                                        <br>[cn]结束 */
    CTD_E_CALL_STATE_HOLD,                          /**< [en]Indicates hold status
                                                        <br>[cn]保持 */
    CTD_E_CALL_STATE_BUTT                           /**< [en]Indicates invalid status
                                                        <br>[cn]无效状态 */
} CTD_E_CALL_STATE;

/**
 * @ingroup 
 * @brief [en]This interface is used to notify message callback.
 *        <br>[cn]通知消息回调
 * 
 * @param [in] TUP_UINT32 msgid    <b>:</b><br>[en]Indicates callback message id.
 *                                         <br>[cn]回调消息ID，
 * @param [in] TUP_UINT32 param1   <b>:</b><br>[en]Indicates param 1.
 *                                         <br>[cn]参数1
 * @param [in] TUP_UINT32 param2   <b>:</b><br>[en]Indicates param 2.
 *                                         <br>[cn]参数2
 * @param [in] TUP_VOID *data      <b>:</b><br>[en]Indicates message data.
 *                                         <br>[cn]消息数据
 * @retval TUP_VOID
 * 
 * @attention [en]NA.
 *            <br>[cn]NA
 * @see NA
 **/
typedef TUP_VOID (*CTD_FN_CALLBACK_PTR)(TUP_UINT32 msgid, TUP_UINT32 param1, TUP_UINT32 param2, TUP_VOID *data);



#ifdef __cplusplus
#if __cplusplus
}
#endif /*  __cpluscplus */
#endif /*  __cpluscplus */


#endif  /* __CTD_DEF_H__ */

