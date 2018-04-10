/************************************************************************/
/*@file tup_openmedia_interface.h
 *
 *Copyright(C), 2012-2017, Huawei Tech. Co., Ltd. ALL RIGHTS RESERVED.
 *
 *@brief [cn]描述：媒体模块接口头文件，直接提供给UI调用
 *       [en]description: media module interface directly called by UI  
 */
/************************************************************************/

#ifndef __TUP_OPEN_MEDIA_INTERFACE_H__
#define __TUP_OPEN_MEDIA_INTERFACE_H__

#include "tup_def.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define IN
#define OUT
#define INOUT

/********************************macro begin********************************/
#define OPENMEDIA_TUP_MAX_FILE_PATH                 255 /**<   [en]Indicates the maximum length of file path
                                                    <br>[cn]文件路径长度 */
#define OPENMEDIA_TUP_MAX_USERID_LEN                128 /**<   [en]Indicates the maximum length of user id, same as TC
                                                    <br>[cn]用户ID长度，同TC侧保持一致 */
#define OPENMEDIA_TUP_MAX_CODEC_NAME_LEN            31  /**<   [en]Indicates the maximum length of codec name
                                                    <br>[cn]编解码名称长度 */

#define OPENMEDIA_FILE_FORMAT_PCM                      0 /**< [en]Indicates PCM format [cn]PCM文件格式 */
#define OPENMEDIA_FILE_FORMAT_WAV                      1 /**< [en]Indicates WAV format [cn]WAV文件格式 */
#define OPENMEDIA_FILE_FORMAT_AMR                      2 /**< [en]Indicates AMR format, currently supports single-channel AMR-NB [cn]/AMR文件格式，目前支持单通道AMR-NB */

#define OPENMEDIA_BASE                           0
#define OPENMEDIA_NOERROR                        (OPENMEDIA_BASE + 0) /**<   [en]Indicates no error
                                                                       <br>[cn]没有错误 */
#define OPENMEDIA_ERROR                          (OPENMEDIA_BASE + 1) /**<   [en]Indicates undefined error
                                                                       <br>[cn]没有说明的错误 */
#define OPENMEDIA_UNINITIALIZE                   (OPENMEDIA_BASE + 2) /**<   [en]Indicates lib not initialized
                                                                       <br>[cn]库没有初始化 */
#define OPENMEDIA_INVALIDPARAM                   (OPENMEDIA_BASE + 3) /**<   [en]Indicates invalid parameters
                                                                       <br>[cn]无效的参数 */
#define OPENMEDIA_ALLOCMEMORY                    (OPENMEDIA_BASE + 4) /**<   [en]Indicates memory allocation error
                                                                       <br>[cn]分配内存失败 */
#define OPENMEDIA_NOIMPLEMENT                    (OPENMEDIA_BASE + 5) /**<   [en]Indicates function not implemented
                                                                       <br>[cn]功能未实现 */
#define OPENMEDIA_NOSESSION                      (OPENMEDIA_BASE + 6) /**<   [en]Indicates session not exist
                                                                       <br>[cn]会话不存在 */
#define OPENMEDIA_INVALID_SESSION                (OPENMEDIA_BASE + 7) /**<   [en]Indicates invalid session
                                                                       <br>[cn]会话无效 */
#define OPENMEDIA_NO_FILE                        (OPENMEDIA_BASE + 8) /**<   [en]Indicates file not exist
                                                                       <br>[cn]文件不存在 */
#define OPENMEDIA_CMD_FAIL                       (OPENMEDIA_BASE + 9) /**<   [en]Indicates start or stop recording fails
                                                                       <br>[cn]录制或停止录制失败 */
/********************************macro end********************************/

/********************************enum begin********************************/
/** 
 * [en]This enumeration is used to describe log mode.
 * [cn]日志模式
 */
typedef enum _OPENMEDIA_ENUM_LOG_USE_MODE
{
    OPENMEDIA_E_LOG_USE_MODE_FILE = 0x00,       /**< [en]Indicates file mode [cn]文件模式 */
    OPENMEDIA_E_LOG_USE_MODE_CALLBACK           /**< [en]Indicates callback mode [cn]回调函数模式 */
} OPENMEDIA_ENUM_LOG_USE_MODE;

/** 
 * [en]This enumeration is used to describe record type.
 * [cn]录制类型
 */
typedef enum _OPENMEDIA_ENUM_TUP_RECORD_TYPE
{
    OPENMEDIA_E_RECORD_NONSESSION_AUDIO               = 0         /**< [en]Indicates nonsession local audio recording [cn]非通话状态下，录制本地声音 */
} OPENMEDIA_ENUM_TUP_RECORD_TYPE;

/** 
 * [en]This enumeration is used to describe media service upcall event.
 * [cn]媒体模块上报消息
 */
typedef enum _OPENMEDIA_E_EVENT
{
    OPENMEDIA_E_EVT_BEGIN = 0,  
    OPENMEDIA_E_EVT_NTF_FROM_AUDIO = 1,    /**< [en]Indicates notify from audio [cn]音频文件播放结束通知 */
    OPENMEDIA_E_EVT_END                      
} OPENMEDIA_E_EVENT;

/** 
 * [en]This enumeration is used to describe file play type.
 * [cn]文件播放类型
 */
typedef enum _OPENMEDIA_ENUM_PLAY_FILE_TYPE
{
    OPENMEDIA_NORMAL_PLAYFILE   = 0x00,     /**< [en]Indicates normal file play, no need to create channel [cn]普通文件播放，不需要创建通道 */
    OPENMEDIA_SPECIAL_PLAYFILE  = 0x01,     /**< [en]Indicates special file play, need to create channel [cn]特殊文件播放，需要额外创建通道 */
    OPENMEDIA_INVALID_PLAYFILE  = 0xff
} OPENMEDIA_ENUM_PLAY_FILE_TYPE;

/********************************enum end********************************/

/********************************struct begin********************************/
/** 
 * [en]This structure is used to describe media original notify.
 * [cn]媒体原始回调函数信息
 */
typedef struct _OpenmediaOriginalNotify
{
    TUP_UPTR   upHandle;
    TUP_UINT32 uiEventId;             /**< [en]Indicates media original notify. For audio: 0: MMA_FILE_END, 2:MMA_INVOLUME_CHANGE 
                                           [cn]媒体原始通知。音频通知：0:MMA_FILE_END 文件播放完毕 2:MMA_INVOLUME_CHANGE 系统录音音量发生变化*/
    TUP_UPTR   uiInstance;
    void *     pvParam;
    TUP_UINT32 uiParamLen;
} OpenmediaOriginalNotify;

/** 
 * [en]This structure is used to describe media log info.
 * [cn]媒体日志信息
 */
typedef struct _tagOpenmediaLogInfo
{
    TUP_BOOL   bLogSwitch;                                /**< [en]Indicates log switch, 0: off 1:on [cn]日志开关 0：关闭 1：打开 */
    TUP_INT8   iLogMode;                                  /**< [en]Indicates log mode, refer to OPENMEDIA_ENUM_LOG_USE_MODE [cn]日志模式 OPENMEDIA_ENUM_LOG_USE_MODE */
    void *     pCallback;                                 /**< [en]Indicates callback function, in use when iLogMode is OPENMEDIA_E_LOG_USE_MODE_CALLBACK [cn]日志回调函数，在日志模式为OPENMEDIA_E_LOG_USE_MODE_CALLBACK有效 */
    TUP_CHAR   acLogPath[OPENMEDIA_TUP_MAX_FILE_PATH + 1];       /**< [en]Indicates log path [cn]日志路径 */
    TUP_INT8   iLevel;                                    /**< [en]Indicates log level  1：error 2：info 3: debug [cn]日志级别 1：error 2：info 3: debug*/
    TUP_UINT32 uiSize;                                    /**< [en]Indicates log size, default is 5M [cn]日志大小，默认为5M  （单位：M）*/
    TUP_UINT32 uiCount;                                   /**< [en]Indicates number of log files, default is 2 [cn]绕接次数，默认值2 */
} OpenmediaLogInfo;

/** 
 * [en]This structure is used to describe audio or video lib log infomation.
 * [cn]底层媒体库日志信息
 */
typedef struct _tagOpenmediaSupportLogInfo
{
    TUP_CHAR  acLogPath[OPENMEDIA_TUP_MAX_FILE_PATH + 1];    /**< [en]Indicates log path [cn]日志路径 */
    TUP_INT32 iAudioLogLevel;                         /**< [en]Indicates audio log level 0-no log 1-error 2-info 3-debug [cn]audio媒体库的日志级别:0-不打日志 1-error 2-info 3-debug */
    TUP_INT32 iAudioLogSize;                          /**< [en]Indicates audio log size [cn]audio媒体库日志阀值 */
    TUP_INT8  iAudioTraceMode;                        /**< [en]Indicates audio trace mode [cn]audio媒体库trace模式 */
    TUP_INT32 iVideoLogLevel;                         /**< [en]Indicates video log level 0-no log 1-error 2-info 3-debug, not in use [cn]video媒体库的日志级别:0-不打日志 1-error 2-info 3-debug, 该参数不启用*/
    TUP_INT32 iVideoLogSize;                          /**< [en]Indicates audio log size, not in use [cn]video媒体库日志阀值，该参数暂不启用 */
} OpenmediaSupportLogInfo;

/** 
 * [en]This structure is used to describe media lib initialization parameters.
 * [cn]媒体库初始化参数
 */
typedef struct _tagOpenmediaInit
{
    TUP_BOOL bEnableAudio;                      /**< [en]Indicates wether audio is enabled, default is true [cn]是否使能音频，默认true */
    TUP_BOOL bEnableVideo;                      /**< [en]Indicates wether video is enabled, default is true, not in use [cn]是否使能视频，默认true, 该参数不启用 */
    TUP_CHAR szUserID[OPENMEDIA_TUP_MAX_USERID_LEN];   /**< [en]Indicates user infomation, for cloud mode TC only [cn]用户信息,云模式下TC专用 */
} OpenmediaInit;

/** 
 * [en]This structure is used to describe recording parameters.
 * [cn]录制参数
 */
typedef struct _tagOpenmediaRecord
{
    TUP_UINT8  uiType;                                /**< [en]Indicates record type, refer to OPENMEDIA_ENUM_TUP_RECORD_TYPE, for both start and stop record [cn]录制类型 OPENMEDIA_ENUM_TUP_RECORD_TYPE, 开始和停止录制共用 */
    TUP_UINT8  uiCaptureIndex;                        /**< [en]Indicates capture index, for both start and stop record, not available for hard terminal [cn]会话外录制选择，开始和停止录制共用，硬终端目前不需要设置 */

    TUP_UINT16 uiFileSize;                            /**< [en]Indicates file size threshold, notification will be sent when record file exceeds the threshold, but record procedure will not be affected, default is 100M, required for video record, a start record param, not in use, 
                                                           [cn]录制文件大小提示告警，如果录制文件超过该大小，会上抛通知，不影响录制，默认100M,视频录制需要, 开始录制参数, 该参数不启用, */
    TUP_UINT32 uiSampleFreq;                          /**< [en]Indicates sample frequency, currently for 16k and 48k only, a start record param [cn]录音采样率 目前只支持16k 48k, 开始录制参数 */
    TUP_UINT32 uiRate;                                /**< [en]Indicates record rate, a start record param [cn]录音码率，开始录制参数 */
    TUP_CHAR   fileName[OPENMEDIA_TUP_MAX_FILE_PATH + 1];    /**< [en]Indicates file name *.wav, a start record param [cn]录制文件名称 *.wav，开始录制参数 */
    TUP_CHAR   codecName[OPENMEDIA_TUP_MAX_CODEC_NAME_LEN];  /**< [en]Indicates codec name, a start record param [cn]录音编码，开始录制参数 */
} OpenmediaRecord;

/** 
 * [en]This union is used to describe notify parameters.
 * [cn]消息参数
 */
typedef union
{
    OpenmediaOriginalNotify   stOriginalNotify;   /**< [en]Indicates media original parameter, MEDIA_NTF_FROM_AUDIO [cn]媒体原始通知参数 MEDIA_NTF_FROM_AUDIO */
} OpenCallBackUnion;

/** 
 * [en]This structure is used to describe callback overall parameter.
 * [cn]回调函数参数
 */
typedef struct _OpenCallBackParams
{
    OPENMEDIA_E_EVENT          notifyType;         /**< [en]Indicates notify type [cn]消息类型 */
    OpenCallBackUnion unParams;           /**< [en]Indicates notify parameters [cn]消息参数 */
} OpenCallBackParams;

typedef void (*OpenNotifyFunc)(OpenCallBackParams *pstParams);

/** 
 * [en]This structure is used to describe audio play file info.
 * [cn]本地播放音频文件信息
 */
typedef struct _OpenPlayFile
{
    OPENMEDIA_ENUM_PLAY_FILE_TYPE ePlayFileType;                             /**< [en]Indicates file type [cn]播放文件类型 */
    TUP_INT32              iHandle;                                          /**< [en]Indicates output param, currently no use for conf [cn]出参，目前会议放音未使用 */
    TUP_CHAR               fileName[OPENMEDIA_TUP_MAX_FILE_PATH + 1];        /**< [en]Indicates file path and name, file format is limited by HME, to be specified when HME hard terminal releases 
                                                                               [cn]播放文件路径，文件格式受限于HME，具体需要等待HME硬终端库发布 */
    TUP_UINT32             uiLoops;                                          /**< [en]Indicates file play loop, 0 is infinite loop [cn]0是无限 播放循环次数 */
    TUP_INT32              iFileFormat;                                      /**< [en]Indicates file format OPENMEDIA_FILE_FORMAT_PCM/OPENMEDIA_FILE_FORMAT_WAV/OPENMEDIA_FILE_FORMAT_AMR[cn]播放文件格式 OPENMEDIA_FILE_FORMAT_PCM/OPENMEDIA_FILE_FORMAT_WAV/OPENMEDIA_FILE_FORMAT_AMR */
    TUP_FLOAT              fVolumeScale;                                     /**< [en]Indicates volume scale level, range[0, 10] [0,1)lower 1 no change (1, 10]higher 
                                                                               [cn]音量倍数调节值，范围[0，10] [0,1)音量变小  1 音量不变  (1,10]音量变大 */
    TUP_CHAR               codecName[OPENMEDIA_TUP_MAX_CODEC_NAME_LEN + 1];  /**< [en]Indicates codec name for special file [cn]SPECIAL_PLAYFILE需要指定编解码 */
    TUP_INT32              iClockRate;                                       /**< [en]Indicates sample frequency for special file [cn]SPECIAL_PLAYFILE需要指定采样率 */
    TUP_INT32              iForceLocalPlay;                                  /**< [en]Indicates force local play [cn]是否强制本地播放 */
} OpenPlayFile;

/********************************struct end********************************/

/*******************************************************************************
 * @ingroup OpenAPI
 * @brief [en]This interface is used to set log parameters and start the log.
 *        <br>[cn]设置媒体日志参数，并启动日志
 * 
 * @param [in] OpenMediaLogInfo * pstOpenMediaLogInfo <b>:</b><br>[en]Indicates media log info
 *                                                                <br>[cn]媒体日志信息
 * @retval TUP_RESULT                                     <b>:</b><br>[en]If it's success return TUP_SUCCESS, otherwise return the corresponding error code.
 *                                                                <br>[cn]成功返回TUP_SUCCESS，失败返回相应错误码
 * 
 * @attention [en]This interface must be invoked before initialization.
 *            <br>[cn]必须在组件初始化之前调用
 * @see NA
 *******************************************************************************/
TUP_API TUP_RESULT OPENMEDIA_SetLog(IN const OpenmediaLogInfo *pstOpenmediaLogInfo);

/*******************************************************************************
 * @ingroup OpenAPI
 * @brief [en]This interface is used to set log parameters and start the log.
 *        <br>[cn]设置媒体日志参数，并启动日志
 * 
 * @param [in] OpenMediaSupportLogInfo * pstOpenMediaSupportLogInfo <b>:</b><br>[en]Indicates audio or video log info
 *                                                                              <br>[cn]音视频库日志信息
 * @retval TUP_RESULT                                                   <b>:</b><br>[en]If it's success return TUP_SUCCESS, otherwise return the corresponding error code.
 *                                                                              <br>[cn]成功返回TUP_SUCCESS，失败返回相应错误码
 * 
 * @attention [en]This interface must be invoked before initialization.
 *            <br>[cn]必须在组件初始化之前调用
 * @see NA
 *******************************************************************************/
TUP_API TUP_RESULT OPENMEDIA_SetSupportLog(IN const OpenmediaSupportLogInfo *pstOpenmediaSupportLogInfo);

/*******************************************************************************
 * @ingroup OpenAPI
 * @brief [en]This interface is used to media module initialization.
 *        <br>[cn]media模块初始化
 * 
 * @param [in] OpenMediaInit* pstOpenMediaInit  <b>:</b><br>[en]Indicates media initialization parameters.
 *                                                          <br>[cn]媒体库初始化参数
 * @retval TUP_RESULT                               <b>:</b><br>[en]If it's success return TUP_SUCCESS, otherwise return the corresponding error code.
 *                                                          <br>[cn]成功返回TUP_SUCCESS，失败返回相应错误码
 * 
 * @attention [en]NA.
 *            <br>[cn]NA
 * @see NA
 *******************************************************************************/
TUP_API TUP_RESULT OPENMEDIA_Init(IN const OpenmediaInit *pstOpenmediaInit);

/*******************************************************************************
 * @ingroup OpenAPI
 * @brief [en]This interface is used to uninit media module.
 *        <br>[cn]media模块去初始化
 * 
 * @param NA
 * @retval TUP_RESULT <b>:</b><br>[en]If it's success return TUP_SUCCESS, otherwise return the corresponding error code.
 *                            <br>[cn]成功返回TUP_SUCCESS，失败返回相应错误码
 * 
 * @attention [en]NA.
 *            <br>[cn]NA
 * @see NA
 *******************************************************************************/
TUP_API TUP_RESULT OPENMEDIA_Uninit(void);

/*******************************************************************************
 * @ingroup OpenAPI
 * @brief [en]This interface is used to record audio or video, hard terminal only supports audio recording currently.
 *        <br>[cn]录音 录制视频 录制音视频，目前硬终端只支持录音
 * 
 * @param [in] OpenMediaRecord* pstOpenMediaRecord  <b>:</b><br>[en]Indicates recording parameters.
 *                                                              <br>[cn]录制参数
 * @retval TUP_RESULT                                   <b>:</b><br>[en]If it's success return TUP_SUCCESS, otherwise return the corresponding error code.
 *                                                              <br>[cn]成功返回TUP_SUCCESS，失败返回相应错误码
 * 
 * @attention [en]NA.
 *            <br>[cn]NA
 * @see NA
 *******************************************************************************/
TUP_API TUP_RESULT OPENMEDIA_StartRecord(IN const OpenmediaRecord *pstOpenmediaRecord);

/*******************************************************************************
 * @ingroup OpenAPI
 * @brief [en]This interface is used to stop recording.
 *        <br>[cn]停止录制
 * 
 * @param [in] OpenMediaRecord* pstOpenMediaRecord  <b>:</b><br>[en]Indicates recording parameters.
 *                                                              <br>[cn]录制参数
 * @retval TUP_RESULT                                   <b>:</b><br>[en]If it's success return TUP_SUCCESS, otherwise return the corresponding error code.
 *                                                              <br>[cn]成功返回TUP_SUCCESS，失败返回相应错误码
 * 
 * @attention [en]NA.
 *            <br>[cn]NA
 * @see NA
 *******************************************************************************/
TUP_API TUP_RESULT OPENMEDIA_StopRecord(IN const OpenmediaRecord *pstOpenmediaRecord);

/*******************************************************************************
 * @ingroup OpenAPI
 * @brief [en]This interface is used to set callback function.
 *        <br>[cn]设置回调函数
 * 
 * @param [in] OpenNotifyFunc pFunc                     <b>:</b><br>[en]Indicates callback function.
 *                                                              <br>[cn]回调函数
 * @retval TUP_RESULT                                   <b>:</b><br>[en]If it's success return TUP_SUCCESS, otherwise return the corresponding error code.
 *                                                              <br>[cn]成功返回TUP_SUCCESS，失败返回相应错误码
 * 
 * @attention [en]NA.
 *            <br>[cn]NA
 * @see NA
 *******************************************************************************/
TUP_API TUP_RESULT  OPENMEDIA_SetNotifyCallback(IN OpenNotifyFunc pFunc);

/*******************************************************************************
 * @ingroup OpenAPI
 * @brief [en]This interface is used to play local audio file.
 *        <br>[cn]播放本地音频文件
 *  
 * @param [in] PlayFile *pstPlayFile                    <b>:</b><br>[en]Indicates file info.
 *                                                              <br>[cn]回调函数
 * @retval TUP_RESULT                                   <b>:</b><br>[en]If it's success return TUP_SUCCESS, otherwise return the corresponding error code.
 *                                                              <br>[cn]成功返回TUP_SUCCESS，失败返回相应错误码
 * 
 * @attention [en]NA.
 *            <br>[cn]NA
 * @see NA
 *******************************************************************************/
TUP_API TUP_RESULT  OPENMEDIA_PlayFile(INOUT OpenPlayFile *pstOpenPlayFile);

/*******************************************************************************
 * @ingroup OpenAPI
 * @brief [en]This interface is used to stop playing local audio file.
 *        <br>[cn]停止播放本地音频文件
 *  
 * @param [in] TUP_INT iHandle                          <b>:</b><br>[en]play handle.
 *                                                              <br>[cn]播放句柄
 *        [in] OPENMEDIA_ENUM_PLAY_FILE_TYPE ePlayType         <b>:</b><br>[en]play file type.
 *                                                              <br>[cn]播放文件类型
 * @retval TUP_RESULT                                   <b>:</b><br>[en]If it's success return TUP_SUCCESS, otherwise return the corresponding error code.
 *                                                              <br>[cn]成功返回TUP_SUCCESS，失败返回相应错误码
 * 
 * @attention [en]NA.
 *            <br>[cn]NA
 * @see NA
 *******************************************************************************/
TUP_API TUP_RESULT  OPENMEDIA_EndPlayFile(IN TUP_INT iHandle, IN OPENMEDIA_ENUM_PLAY_FILE_TYPE ePlayType);

/*******************************************************************************
 * @ingroup OpenAPI
 * @brief [en]This interface is used to get mic level.
 *        <br>[cn]获取麦克风输入能量
 *  
 * @param [in] TUP_UINT32* puiLevel                     <b>:</b><br>[en]energy level.
 *                                                              <br>[cn]能量
 * @retval TUP_RESULT                                   <b>:</b><br>[en]If it's success return TUP_SUCCESS, otherwise return the corresponding error code.
 *                                                              <br>[cn]成功返回TUP_SUCCESS，失败返回相应错误码
 * 
 * @attention [en]NA.
 *            <br>[cn]NA
 * @see NA
 *******************************************************************************/
TUP_API TUP_RESULT  OPENMEDIA_GetMicLevel(OUT TUP_UINT32 *puiLevel);

#ifdef __cplusplus
}
#endif

#endif //__TUP_OPEN_MEDIA_INTERFACE_H__
