#ifndef tup_service_interface_h__
#define tup_service_interface_h__

#include "tup_def.h"

/**
 * [en]This enumeration is used to describe tup interface err.
 * [cn]tup接口错误码
 */
typedef enum tagTUP_E_SERVICE_IF_ERR
{
    TUP_E_SERVICE_OK = 0                    /**<[en]Indicates suces. <br>[cn]成功 */
    ,TUP_E_SERVICE_MSGP_CREATE_ERR          /**<[en]Indicates message queue thread create failed. <br>[cn]消息队列线程/进程创建失败 */     
    ,TUP_E_SERVICE_TIMER_START_ERR          /**<[en]Indicates timer thread start failed. <br>[cn]定时器线程启动失败 */     
}TUP_E_SERVICE_IF_ERR;

/**
 * [en]This struct is used to describe initialize the parameters.
 * [cn]初始化参数结构体
 */
typedef struct tagTUP_S_INIT_PARAM
{
    TUP_BOOL with_ws_service;   /**<[en]init with websocket service. <br>[cn]是否启动websockets服务 */
    TUP_BOOL with_wss;          /**<[en]init with wss for websocket. <br>[cn]是否支持 websockets wss加密协议 */
    TUP_CHAR *resource_path;    /**<[en]init with resource path for service. <br>[cn]设置服务的资源路径 */
    TUP_CHAR *log_path;         /**<[en]init with log path for service. <br>[cn]设置日志路径 */
    TUP_BOOL reserved;
} TUP_S_INIT_PARAM;

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/**
 * @brief [en]This interface is used to startup tup service and set init parameters.
 *        <br>[cn]启动TUP服务，设置初始化参数
 * 
 * @param [in] const TUP_S_INIT_PARAM* param         <b>:</b><br>[en]Indicates the initialization parameter.
 *                                                             <br>[cn]初始化参数
 * @retval TUP_RESULT <b>:</b><br>[en]If it's success return TUP_SUCCESS, otherwise return the corresponding error code.
 *                            <br>[cn]成功返回TUP_SUCCESS，失败返回相应错误码
 * 
 * @see NA
 **/
TUP_API TUP_RESULT tup_service_startup(TUP_S_INIT_PARAM *param);
/**
 * @brief [en]This interface is used to shutdown tup service.
 *        <br>[cn]停止TUP服务 
 *                                                            
 * @retval TUP_RESULT <b>:</b><br>[en]If it's success return TUP_SUCCESS, otherwise return the corresponding error code.
 *                            <br>[cn]成功返回TUP_SUCCESS，失败返回相应错误码
 * 
 * @see NA
 **/
TUP_API TUP_RESULT tup_service_shutdown();

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif // tup_service_interface_h__
