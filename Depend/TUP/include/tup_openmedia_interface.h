/************************************************************************/
/*@file tup_openmedia_interface.h
 *
 *Copyright(C), 2012-2017, Huawei Tech. Co., Ltd. ALL RIGHTS RESERVED.
 *
 *@brief [cn]������ý��ģ��ӿ�ͷ�ļ���ֱ���ṩ��UI����
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
                                                    <br>[cn]�ļ�·������ */
#define OPENMEDIA_TUP_MAX_USERID_LEN                128 /**<   [en]Indicates the maximum length of user id, same as TC
                                                    <br>[cn]�û�ID���ȣ�ͬTC�ౣ��һ�� */
#define OPENMEDIA_TUP_MAX_CODEC_NAME_LEN            31  /**<   [en]Indicates the maximum length of codec name
                                                    <br>[cn]��������Ƴ��� */

#define OPENMEDIA_FILE_FORMAT_PCM                      0 /**< [en]Indicates PCM format [cn]PCM�ļ���ʽ */
#define OPENMEDIA_FILE_FORMAT_WAV                      1 /**< [en]Indicates WAV format [cn]WAV�ļ���ʽ */
#define OPENMEDIA_FILE_FORMAT_AMR                      2 /**< [en]Indicates AMR format, currently supports single-channel AMR-NB [cn]/AMR�ļ���ʽ��Ŀǰ֧�ֵ�ͨ��AMR-NB */

#define OPENMEDIA_BASE                           0
#define OPENMEDIA_NOERROR                        (OPENMEDIA_BASE + 0) /**<   [en]Indicates no error
                                                                       <br>[cn]û�д��� */
#define OPENMEDIA_ERROR                          (OPENMEDIA_BASE + 1) /**<   [en]Indicates undefined error
                                                                       <br>[cn]û��˵���Ĵ��� */
#define OPENMEDIA_UNINITIALIZE                   (OPENMEDIA_BASE + 2) /**<   [en]Indicates lib not initialized
                                                                       <br>[cn]��û�г�ʼ�� */
#define OPENMEDIA_INVALIDPARAM                   (OPENMEDIA_BASE + 3) /**<   [en]Indicates invalid parameters
                                                                       <br>[cn]��Ч�Ĳ��� */
#define OPENMEDIA_ALLOCMEMORY                    (OPENMEDIA_BASE + 4) /**<   [en]Indicates memory allocation error
                                                                       <br>[cn]�����ڴ�ʧ�� */
#define OPENMEDIA_NOIMPLEMENT                    (OPENMEDIA_BASE + 5) /**<   [en]Indicates function not implemented
                                                                       <br>[cn]����δʵ�� */
#define OPENMEDIA_NOSESSION                      (OPENMEDIA_BASE + 6) /**<   [en]Indicates session not exist
                                                                       <br>[cn]�Ự������ */
#define OPENMEDIA_INVALID_SESSION                (OPENMEDIA_BASE + 7) /**<   [en]Indicates invalid session
                                                                       <br>[cn]�Ự��Ч */
#define OPENMEDIA_NO_FILE                        (OPENMEDIA_BASE + 8) /**<   [en]Indicates file not exist
                                                                       <br>[cn]�ļ������� */
#define OPENMEDIA_CMD_FAIL                       (OPENMEDIA_BASE + 9) /**<   [en]Indicates start or stop recording fails
                                                                       <br>[cn]¼�ƻ�ֹͣ¼��ʧ�� */
/********************************macro end********************************/

/********************************enum begin********************************/
/** 
 * [en]This enumeration is used to describe log mode.
 * [cn]��־ģʽ
 */
typedef enum _OPENMEDIA_ENUM_LOG_USE_MODE
{
    OPENMEDIA_E_LOG_USE_MODE_FILE = 0x00,       /**< [en]Indicates file mode [cn]�ļ�ģʽ */
    OPENMEDIA_E_LOG_USE_MODE_CALLBACK           /**< [en]Indicates callback mode [cn]�ص�����ģʽ */
} OPENMEDIA_ENUM_LOG_USE_MODE;

/** 
 * [en]This enumeration is used to describe record type.
 * [cn]¼������
 */
typedef enum _OPENMEDIA_ENUM_TUP_RECORD_TYPE
{
    OPENMEDIA_E_RECORD_NONSESSION_AUDIO               = 0         /**< [en]Indicates nonsession local audio recording [cn]��ͨ��״̬�£�¼�Ʊ������� */
} OPENMEDIA_ENUM_TUP_RECORD_TYPE;

/** 
 * [en]This enumeration is used to describe media service upcall event.
 * [cn]ý��ģ���ϱ���Ϣ
 */
typedef enum _OPENMEDIA_E_EVENT
{
    OPENMEDIA_E_EVT_BEGIN = 0,  
    OPENMEDIA_E_EVT_NTF_FROM_AUDIO = 1,    /**< [en]Indicates notify from audio [cn]��Ƶ�ļ����Ž���֪ͨ */
    OPENMEDIA_E_EVT_END                      
} OPENMEDIA_E_EVENT;

/** 
 * [en]This enumeration is used to describe file play type.
 * [cn]�ļ���������
 */
typedef enum _OPENMEDIA_ENUM_PLAY_FILE_TYPE
{
    OPENMEDIA_NORMAL_PLAYFILE   = 0x00,     /**< [en]Indicates normal file play, no need to create channel [cn]��ͨ�ļ����ţ�����Ҫ����ͨ�� */
    OPENMEDIA_SPECIAL_PLAYFILE  = 0x01,     /**< [en]Indicates special file play, need to create channel [cn]�����ļ����ţ���Ҫ���ⴴ��ͨ�� */
    OPENMEDIA_INVALID_PLAYFILE  = 0xff
} OPENMEDIA_ENUM_PLAY_FILE_TYPE;

/********************************enum end********************************/

/********************************struct begin********************************/
/** 
 * [en]This structure is used to describe media original notify.
 * [cn]ý��ԭʼ�ص�������Ϣ
 */
typedef struct _OpenmediaOriginalNotify
{
    TUP_UPTR   upHandle;
    TUP_UINT32 uiEventId;             /**< [en]Indicates media original notify. For audio: 0: MMA_FILE_END, 2:MMA_INVOLUME_CHANGE 
                                           [cn]ý��ԭʼ֪ͨ����Ƶ֪ͨ��0:MMA_FILE_END �ļ�������� 2:MMA_INVOLUME_CHANGE ϵͳ¼�����������仯*/
    TUP_UPTR   uiInstance;
    void *     pvParam;
    TUP_UINT32 uiParamLen;
} OpenmediaOriginalNotify;

/** 
 * [en]This structure is used to describe media log info.
 * [cn]ý����־��Ϣ
 */
typedef struct _tagOpenmediaLogInfo
{
    TUP_BOOL   bLogSwitch;                                /**< [en]Indicates log switch, 0: off 1:on [cn]��־���� 0���ر� 1���� */
    TUP_INT8   iLogMode;                                  /**< [en]Indicates log mode, refer to OPENMEDIA_ENUM_LOG_USE_MODE [cn]��־ģʽ OPENMEDIA_ENUM_LOG_USE_MODE */
    void *     pCallback;                                 /**< [en]Indicates callback function, in use when iLogMode is OPENMEDIA_E_LOG_USE_MODE_CALLBACK [cn]��־�ص�����������־ģʽΪOPENMEDIA_E_LOG_USE_MODE_CALLBACK��Ч */
    TUP_CHAR   acLogPath[OPENMEDIA_TUP_MAX_FILE_PATH + 1];       /**< [en]Indicates log path [cn]��־·�� */
    TUP_INT8   iLevel;                                    /**< [en]Indicates log level  1��error 2��info 3: debug [cn]��־���� 1��error 2��info 3: debug*/
    TUP_UINT32 uiSize;                                    /**< [en]Indicates log size, default is 5M [cn]��־��С��Ĭ��Ϊ5M  ����λ��M��*/
    TUP_UINT32 uiCount;                                   /**< [en]Indicates number of log files, default is 2 [cn]�ƽӴ�����Ĭ��ֵ2 */
} OpenmediaLogInfo;

/** 
 * [en]This structure is used to describe audio or video lib log infomation.
 * [cn]�ײ�ý�����־��Ϣ
 */
typedef struct _tagOpenmediaSupportLogInfo
{
    TUP_CHAR  acLogPath[OPENMEDIA_TUP_MAX_FILE_PATH + 1];    /**< [en]Indicates log path [cn]��־·�� */
    TUP_INT32 iAudioLogLevel;                         /**< [en]Indicates audio log level 0-no log 1-error 2-info 3-debug [cn]audioý������־����:0-������־ 1-error 2-info 3-debug */
    TUP_INT32 iAudioLogSize;                          /**< [en]Indicates audio log size [cn]audioý�����־��ֵ */
    TUP_INT8  iAudioTraceMode;                        /**< [en]Indicates audio trace mode [cn]audioý���traceģʽ */
    TUP_INT32 iVideoLogLevel;                         /**< [en]Indicates video log level 0-no log 1-error 2-info 3-debug, not in use [cn]videoý������־����:0-������־ 1-error 2-info 3-debug, �ò���������*/
    TUP_INT32 iVideoLogSize;                          /**< [en]Indicates audio log size, not in use [cn]videoý�����־��ֵ���ò����ݲ����� */
} OpenmediaSupportLogInfo;

/** 
 * [en]This structure is used to describe media lib initialization parameters.
 * [cn]ý����ʼ������
 */
typedef struct _tagOpenmediaInit
{
    TUP_BOOL bEnableAudio;                      /**< [en]Indicates wether audio is enabled, default is true [cn]�Ƿ�ʹ����Ƶ��Ĭ��true */
    TUP_BOOL bEnableVideo;                      /**< [en]Indicates wether video is enabled, default is true, not in use [cn]�Ƿ�ʹ����Ƶ��Ĭ��true, �ò��������� */
    TUP_CHAR szUserID[OPENMEDIA_TUP_MAX_USERID_LEN];   /**< [en]Indicates user infomation, for cloud mode TC only [cn]�û���Ϣ,��ģʽ��TCר�� */
} OpenmediaInit;

/** 
 * [en]This structure is used to describe recording parameters.
 * [cn]¼�Ʋ���
 */
typedef struct _tagOpenmediaRecord
{
    TUP_UINT8  uiType;                                /**< [en]Indicates record type, refer to OPENMEDIA_ENUM_TUP_RECORD_TYPE, for both start and stop record [cn]¼������ OPENMEDIA_ENUM_TUP_RECORD_TYPE, ��ʼ��ֹͣ¼�ƹ��� */
    TUP_UINT8  uiCaptureIndex;                        /**< [en]Indicates capture index, for both start and stop record, not available for hard terminal [cn]�Ự��¼��ѡ�񣬿�ʼ��ֹͣ¼�ƹ��ã�Ӳ�ն�Ŀǰ����Ҫ���� */

    TUP_UINT16 uiFileSize;                            /**< [en]Indicates file size threshold, notification will be sent when record file exceeds the threshold, but record procedure will not be affected, default is 100M, required for video record, a start record param, not in use, 
                                                           [cn]¼���ļ���С��ʾ�澯�����¼���ļ������ô�С��������֪ͨ����Ӱ��¼�ƣ�Ĭ��100M,��Ƶ¼����Ҫ, ��ʼ¼�Ʋ���, �ò���������, */
    TUP_UINT32 uiSampleFreq;                          /**< [en]Indicates sample frequency, currently for 16k and 48k only, a start record param [cn]¼�������� Ŀǰֻ֧��16k 48k, ��ʼ¼�Ʋ��� */
    TUP_UINT32 uiRate;                                /**< [en]Indicates record rate, a start record param [cn]¼�����ʣ���ʼ¼�Ʋ��� */
    TUP_CHAR   fileName[OPENMEDIA_TUP_MAX_FILE_PATH + 1];    /**< [en]Indicates file name *.wav, a start record param [cn]¼���ļ����� *.wav����ʼ¼�Ʋ��� */
    TUP_CHAR   codecName[OPENMEDIA_TUP_MAX_CODEC_NAME_LEN];  /**< [en]Indicates codec name, a start record param [cn]¼�����룬��ʼ¼�Ʋ��� */
} OpenmediaRecord;

/** 
 * [en]This union is used to describe notify parameters.
 * [cn]��Ϣ����
 */
typedef union
{
    OpenmediaOriginalNotify   stOriginalNotify;   /**< [en]Indicates media original parameter, MEDIA_NTF_FROM_AUDIO [cn]ý��ԭʼ֪ͨ���� MEDIA_NTF_FROM_AUDIO */
} OpenCallBackUnion;

/** 
 * [en]This structure is used to describe callback overall parameter.
 * [cn]�ص���������
 */
typedef struct _OpenCallBackParams
{
    OPENMEDIA_E_EVENT          notifyType;         /**< [en]Indicates notify type [cn]��Ϣ���� */
    OpenCallBackUnion unParams;           /**< [en]Indicates notify parameters [cn]��Ϣ���� */
} OpenCallBackParams;

typedef void (*OpenNotifyFunc)(OpenCallBackParams *pstParams);

/** 
 * [en]This structure is used to describe audio play file info.
 * [cn]���ز�����Ƶ�ļ���Ϣ
 */
typedef struct _OpenPlayFile
{
    OPENMEDIA_ENUM_PLAY_FILE_TYPE ePlayFileType;                             /**< [en]Indicates file type [cn]�����ļ����� */
    TUP_INT32              iHandle;                                          /**< [en]Indicates output param, currently no use for conf [cn]���Σ�Ŀǰ�������δʹ�� */
    TUP_CHAR               fileName[OPENMEDIA_TUP_MAX_FILE_PATH + 1];        /**< [en]Indicates file path and name, file format is limited by HME, to be specified when HME hard terminal releases 
                                                                               [cn]�����ļ�·�����ļ���ʽ������HME��������Ҫ�ȴ�HMEӲ�ն˿ⷢ�� */
    TUP_UINT32             uiLoops;                                          /**< [en]Indicates file play loop, 0 is infinite loop [cn]0������ ����ѭ������ */
    TUP_INT32              iFileFormat;                                      /**< [en]Indicates file format OPENMEDIA_FILE_FORMAT_PCM/OPENMEDIA_FILE_FORMAT_WAV/OPENMEDIA_FILE_FORMAT_AMR[cn]�����ļ���ʽ OPENMEDIA_FILE_FORMAT_PCM/OPENMEDIA_FILE_FORMAT_WAV/OPENMEDIA_FILE_FORMAT_AMR */
    TUP_FLOAT              fVolumeScale;                                     /**< [en]Indicates volume scale level, range[0, 10] [0,1)lower 1 no change (1, 10]higher 
                                                                               [cn]������������ֵ����Χ[0��10] [0,1)������С  1 ��������  (1,10]������� */
    TUP_CHAR               codecName[OPENMEDIA_TUP_MAX_CODEC_NAME_LEN + 1];  /**< [en]Indicates codec name for special file [cn]SPECIAL_PLAYFILE��Ҫָ������� */
    TUP_INT32              iClockRate;                                       /**< [en]Indicates sample frequency for special file [cn]SPECIAL_PLAYFILE��Ҫָ�������� */
    TUP_INT32              iForceLocalPlay;                                  /**< [en]Indicates force local play [cn]�Ƿ�ǿ�Ʊ��ز��� */
} OpenPlayFile;

/********************************struct end********************************/

/*******************************************************************************
 * @ingroup OpenAPI
 * @brief [en]This interface is used to set log parameters and start the log.
 *        <br>[cn]����ý����־��������������־
 * 
 * @param [in] OpenMediaLogInfo * pstOpenMediaLogInfo <b>:</b><br>[en]Indicates media log info
 *                                                                <br>[cn]ý����־��Ϣ
 * @retval TUP_RESULT                                     <b>:</b><br>[en]If it's success return TUP_SUCCESS, otherwise return the corresponding error code.
 *                                                                <br>[cn]�ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention [en]This interface must be invoked before initialization.
 *            <br>[cn]�����������ʼ��֮ǰ����
 * @see NA
 *******************************************************************************/
TUP_API TUP_RESULT OPENMEDIA_SetLog(IN const OpenmediaLogInfo *pstOpenmediaLogInfo);

/*******************************************************************************
 * @ingroup OpenAPI
 * @brief [en]This interface is used to set log parameters and start the log.
 *        <br>[cn]����ý����־��������������־
 * 
 * @param [in] OpenMediaSupportLogInfo * pstOpenMediaSupportLogInfo <b>:</b><br>[en]Indicates audio or video log info
 *                                                                              <br>[cn]����Ƶ����־��Ϣ
 * @retval TUP_RESULT                                                   <b>:</b><br>[en]If it's success return TUP_SUCCESS, otherwise return the corresponding error code.
 *                                                                              <br>[cn]�ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention [en]This interface must be invoked before initialization.
 *            <br>[cn]�����������ʼ��֮ǰ����
 * @see NA
 *******************************************************************************/
TUP_API TUP_RESULT OPENMEDIA_SetSupportLog(IN const OpenmediaSupportLogInfo *pstOpenmediaSupportLogInfo);

/*******************************************************************************
 * @ingroup OpenAPI
 * @brief [en]This interface is used to media module initialization.
 *        <br>[cn]mediaģ���ʼ��
 * 
 * @param [in] OpenMediaInit* pstOpenMediaInit  <b>:</b><br>[en]Indicates media initialization parameters.
 *                                                          <br>[cn]ý����ʼ������
 * @retval TUP_RESULT                               <b>:</b><br>[en]If it's success return TUP_SUCCESS, otherwise return the corresponding error code.
 *                                                          <br>[cn]�ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention [en]NA.
 *            <br>[cn]NA
 * @see NA
 *******************************************************************************/
TUP_API TUP_RESULT OPENMEDIA_Init(IN const OpenmediaInit *pstOpenmediaInit);

/*******************************************************************************
 * @ingroup OpenAPI
 * @brief [en]This interface is used to uninit media module.
 *        <br>[cn]mediaģ��ȥ��ʼ��
 * 
 * @param NA
 * @retval TUP_RESULT <b>:</b><br>[en]If it's success return TUP_SUCCESS, otherwise return the corresponding error code.
 *                            <br>[cn]�ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention [en]NA.
 *            <br>[cn]NA
 * @see NA
 *******************************************************************************/
TUP_API TUP_RESULT OPENMEDIA_Uninit(void);

/*******************************************************************************
 * @ingroup OpenAPI
 * @brief [en]This interface is used to record audio or video, hard terminal only supports audio recording currently.
 *        <br>[cn]¼�� ¼����Ƶ ¼������Ƶ��ĿǰӲ�ն�ֻ֧��¼��
 * 
 * @param [in] OpenMediaRecord* pstOpenMediaRecord  <b>:</b><br>[en]Indicates recording parameters.
 *                                                              <br>[cn]¼�Ʋ���
 * @retval TUP_RESULT                                   <b>:</b><br>[en]If it's success return TUP_SUCCESS, otherwise return the corresponding error code.
 *                                                              <br>[cn]�ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention [en]NA.
 *            <br>[cn]NA
 * @see NA
 *******************************************************************************/
TUP_API TUP_RESULT OPENMEDIA_StartRecord(IN const OpenmediaRecord *pstOpenmediaRecord);

/*******************************************************************************
 * @ingroup OpenAPI
 * @brief [en]This interface is used to stop recording.
 *        <br>[cn]ֹͣ¼��
 * 
 * @param [in] OpenMediaRecord* pstOpenMediaRecord  <b>:</b><br>[en]Indicates recording parameters.
 *                                                              <br>[cn]¼�Ʋ���
 * @retval TUP_RESULT                                   <b>:</b><br>[en]If it's success return TUP_SUCCESS, otherwise return the corresponding error code.
 *                                                              <br>[cn]�ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention [en]NA.
 *            <br>[cn]NA
 * @see NA
 *******************************************************************************/
TUP_API TUP_RESULT OPENMEDIA_StopRecord(IN const OpenmediaRecord *pstOpenmediaRecord);

/*******************************************************************************
 * @ingroup OpenAPI
 * @brief [en]This interface is used to set callback function.
 *        <br>[cn]���ûص�����
 * 
 * @param [in] OpenNotifyFunc pFunc                     <b>:</b><br>[en]Indicates callback function.
 *                                                              <br>[cn]�ص�����
 * @retval TUP_RESULT                                   <b>:</b><br>[en]If it's success return TUP_SUCCESS, otherwise return the corresponding error code.
 *                                                              <br>[cn]�ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention [en]NA.
 *            <br>[cn]NA
 * @see NA
 *******************************************************************************/
TUP_API TUP_RESULT  OPENMEDIA_SetNotifyCallback(IN OpenNotifyFunc pFunc);

/*******************************************************************************
 * @ingroup OpenAPI
 * @brief [en]This interface is used to play local audio file.
 *        <br>[cn]���ű�����Ƶ�ļ�
 *  
 * @param [in] PlayFile *pstPlayFile                    <b>:</b><br>[en]Indicates file info.
 *                                                              <br>[cn]�ص�����
 * @retval TUP_RESULT                                   <b>:</b><br>[en]If it's success return TUP_SUCCESS, otherwise return the corresponding error code.
 *                                                              <br>[cn]�ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention [en]NA.
 *            <br>[cn]NA
 * @see NA
 *******************************************************************************/
TUP_API TUP_RESULT  OPENMEDIA_PlayFile(INOUT OpenPlayFile *pstOpenPlayFile);

/*******************************************************************************
 * @ingroup OpenAPI
 * @brief [en]This interface is used to stop playing local audio file.
 *        <br>[cn]ֹͣ���ű�����Ƶ�ļ�
 *  
 * @param [in] TUP_INT iHandle                          <b>:</b><br>[en]play handle.
 *                                                              <br>[cn]���ž��
 *        [in] OPENMEDIA_ENUM_PLAY_FILE_TYPE ePlayType         <b>:</b><br>[en]play file type.
 *                                                              <br>[cn]�����ļ�����
 * @retval TUP_RESULT                                   <b>:</b><br>[en]If it's success return TUP_SUCCESS, otherwise return the corresponding error code.
 *                                                              <br>[cn]�ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
 * 
 * @attention [en]NA.
 *            <br>[cn]NA
 * @see NA
 *******************************************************************************/
TUP_API TUP_RESULT  OPENMEDIA_EndPlayFile(IN TUP_INT iHandle, IN OPENMEDIA_ENUM_PLAY_FILE_TYPE ePlayType);

/*******************************************************************************
 * @ingroup OpenAPI
 * @brief [en]This interface is used to get mic level.
 *        <br>[cn]��ȡ��˷���������
 *  
 * @param [in] TUP_UINT32* puiLevel                     <b>:</b><br>[en]energy level.
 *                                                              <br>[cn]����
 * @retval TUP_RESULT                                   <b>:</b><br>[en]If it's success return TUP_SUCCESS, otherwise return the corresponding error code.
 *                                                              <br>[cn]�ɹ�����TUP_SUCCESS��ʧ�ܷ�����Ӧ������
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
