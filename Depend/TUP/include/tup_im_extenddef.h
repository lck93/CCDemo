/** 
* @file tup_im_baseapi.h
* 
* Copyright(C), 2012-2015, Huawei Tech. Co., Ltd. ALL RIGHTS RESERVED. \n
* 
* ������TUP IM��ϵͳ��չҵ���ܽӿڽṹ�嶨��ͷ�ļ��� \n
* @brief [en]Description: The header file of The TUP IM subsystem expands server function interface.
*        [cn]������TUP IM��ϵͳ��չҵ���ܽӿڽṹ�嶨��ͷ�ļ��� \n
*/


/**
*
*  @{
*/


#ifndef _TUP_IM_EXTENDDEF_H_
#define _TUP_IM_EXTENDDEF_H_

#include "tup_im_basedef.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /*  __cpluscplus */
#endif /*  __cpluscplus */


#define IM_D_MAX_SMSID_LENGTH (16)                            /**< [en]Indicates the maximum length of the SMS ID. 
                                                                   <br>[cn]����ID��󳤶� */
#define IM_D_MAX_SMSCONENT_LENGTH (350)                       /**< [en]Indicates the maximum length of SMS content. 
                                                                   <br>[cn]����������󳤶� */
#define IM_D_MAX_SMSRECEIVEER_LENGTH (1000)                   /**< [en]Indicates the maximum length of SMS recipient. 
                                                                   <br>[cn]�����ռ�����󳤶� */

/**
 * [en]This enumeration is used to describe query type of group shared file .
 * [cn]Ⱥ�����ļ���ѯ����
 */
typedef enum tagIM_E_GROUPFILE_QUERY_TYPE
{
    IM_E_GROUPFILE_QUERY_TYPE_FILENAME                = 0,    /**< [en]Indicates searching by file name. 
                                                                   <br>[cn]���ļ������� */
    IM_E_GROUPFILE_QUERY_TYPE_FILETYPE                = 1,    /**< [en]Indicates query by file type. 
                                                                   <br>[cn]���ļ��������� */
    IM_E_GROUPFILE_QUERY_TYPE_FILEID                  = 2     /**< [en]Indicates searching by file ID. 
                                                                   <br>[cn]���ļ�ID���� */
}IM_E_GROUPFILE_QUERY_TYPE;

/**
 * [en]This enumeration is used to describe notification type of group shared file .
 * [cn]Ⱥ�����ļ�֪ͨ��ʶ
 */
typedef enum tagIM_E_GROUPFILE_NOTIFE_TYPE
{
    IM_E_GROUPFILE_NOTIFE_TYPE_FILECHANGE             = 0      /**< [en]Indicates group shared file notification. 
                                                                    <br>[cn]Ⱥ�����ļ�֪ͨ */
}IM_E_GROUPFILE_NOTIFE_TYPE;

/**
 * [en]This enumeration is used to describe operation type of group shared file.
 * [cn]Ⱥ�����ļ��������
 */
typedef enum tagIM_E_GROUPFILE_OPT_TYPE
{
    IM_E_GROUPFILE_OPT_TYPE_ADD                        = 0,    /**< [en]Indicates add new group file. 
                                                                    <br>[cn]����Ⱥ�ļ� */
    IM_E_GROUPFILE_OPT_TYPE_DEL                        = 1     /**< [en]Indicates delete group file. 
                                                                    <br>[cn]ɾ��Ⱥ�ļ� */
}IM_E_GROUPFILE_OPT_TYPE;

/**
 * [en]This structure is used to describe group shared file information.
 * [cn]Ⱥ�����ļ���Ϣ
 */
typedef struct tagIM_S_GROUPFILE_INFO
{
    TUP_CHAR    fileId[IM_D_MAX_PASSWORD_LENGTH];              /**< [en]Indicates file ID. [cn]�ļ�ID */
    TUP_CHAR    uploadTime[IM_D_MAX_TIMESTAMP_LENGTH];         /**< [en]Indicates uploaded time of server. [cn]���������ϴ��ɹ���ʱ�� */
    TUP_CHAR    uploadUserAccount[IM_D_MAX_ACCOUNT_LENGTH];    /**< [en]Indicates upload user account. [cn]�ϴ����˺� */
    TUP_CHAR    uploadUserName[IM_D_MAX_NAME_LENGTH];          /**< [en]Indicates upload user name. [cn]�ϴ������� */
    TUP_CHAR    fileURL[IM_D_URL_LENGTH];                      /**< [en]Indicates file URL. [cn]�ļ�URL */
    TUP_CHAR    fileName[IM_D_MAX_NAME_LENGTH];                /**< [en]Indicates file name. [cn]�ļ��� */
    TUP_INT64    fileSize;                                     /**< [en]Indicates file size. [cn]�ļ���С */
    TUP_CHAR    prefileId[IM_D_MAX_PASSWORD_LENGTH];           /**< [en]Indicates file pre-upload ID. [cn]�ļ�Ӧ�Ե�Ԥ�ϴ�ID */
}IM_S_GROUPFILE_INFO;

/**
 * [en]This structure is used to describe SMS sending.
 * [cn]���ŷ���
 */
typedef struct tagIM_S_SENDSMS_ARG
{
    TUP_CHAR    msgID[IM_D_MAX_SMSID_LENGTH];                  /**< [en]Indicates client generate message ID. [cn]�ͻ��˲�������ϢID */ 
    TUP_CHAR    bindNo[IM_D_MAX_PHONE_LENGTH];                 /**< [en]Indicates current user binding number. [cn]��ǰ�û��İ󶨺��� */ 
    TUP_CHAR    content[IM_D_MAX_SMSCONENT_LENGTH];            /**< [en]Indicates SMS content. [cn]�������� */ 
    TUP_CHAR    receiverList[IM_D_MAX_SMSRECEIVEER_LENGTH];    /**< [en]Indicates recipients list, separated by semicolons. [cn]�������б��԰�Ƿֺŷָ� */ 
    TUP_CHAR    sendTime[IM_D_MAX_TIMESTAMP_LENGTH];           /**< [en]Indicates SMS sending time 19000000000000 (years, months, minutes and seconds). [cn]���ŷ���ʱ�� 19000000000000��������ʱ���룩 */ 
    TUP_BOOL    needReceipt;                                   /**< [en]Indicates whether need return value: true means yes, false means no. [cn]�Ƿ���Ҫ��ִ ȡֵ��trueΪ��Ҫ��ִ��falseΪ����Ҫ��ִ[MODIFY] */ 
}IM_S_SENDSMS_ARG;     

/**
 * [en]This structure is used to describe SMS notify.
 * [cn]����֪ͨ
 */
typedef struct tagIM_S_SENDSMS_NOTIFY
{
    TUP_CHAR    msgID[IM_D_MAX_SMSID_LENGTH];                  /**< [en]Indicates the message ID generated by the client. [cn]�ͻ��˲�������ϢID */ 
    TUP_CHAR    origin[IM_D_MAX_PHONE_LENGTH];                 /**< [en]Indicates sender number. [cn]���ͷ����� */ 
    TUP_CHAR    target[IM_D_MAX_PHONE_LENGTH];                 /**< [en]Indicates the receiver number. [cn]���շ�����*/
    TUP_CHAR    content[IM_D_MAX_SMSCONENT_LENGTH];            /**< [en]Indicates SMS content. [cn]�������� */ 
    TUP_CHAR    sendTime[IM_D_MAX_TIMESTAMP_LENGTH];           /**< [en]Indicates SMS sending time 19000000000000 (years, months, minutes and seconds). [cn]���ŷ���ʱ�� 19000000000000��������ʱ���룩 */ 
    IM_E_SMS_NOTIFY_TYPE    smsType;                           /**< [en]Indicates the type of the received SMS message. Value reference: tagIM_E_SMS_NOTIFY_TYPE. [cn]���յ��Ķ�����Ϣ�����ͣ�ȡֵ�ο�tagIM_E_SMS_NOTIFY_TYPE[TODO] */
    TUP_INT64    serverMsgID;                                  /**< [en]Indicates the server message ID. [cn]��������ϢID */
}IM_S_SENDSMS_NOTIFY;  

/**
 * [en]This structure is used to describe pre-upload group shared file information.
 * [cn]Ԥ�ϴ�Ⱥ�����ļ���Ϣ 
 */
typedef struct tagIM_S_GROUPFILE_PRE_UPLOAD_ARG
{
    TUP_CHAR    groupId[IM_D_GROUPID_LENGTH];                  /**< [en]Indicates group ID. [cn]Ⱥ��ID */
    TUP_CHAR    fileName[IM_D_MAX_NAME_LENGTH];                /**< [en]Indicates file name. [cn]�ļ��� */
    TUP_INT64    fileSize;                                     /**< [en]Indicates file size. [cn]�ļ���С */
}IM_S_GROUPFILE_PRE_UPLOAD_ARG;

/**
 * [en]This structure is used to describe pre-upload group shared file.
 * [cn]Ԥ�ϴ�Ⱥ�����ļ�
 */
typedef struct tagIM_S_GROUPFILE_PRE_UPLOAD_ACK
{
    TUP_CHAR    prefileId[IM_D_MAX_PASSWORD_LENGTH];           /**< [en]Indicates pre-upload group shared file ID. [cn]Ԥ�ϴ��ļ�ID */
}IM_S_GROUPFILE_PRE_UPLOAD_ACK;

/**
 * [en]This structure is used to describe request of group shared file upload.
 * [cn]Ⱥ�����ļ��ϴ�����
 */
typedef struct tagIM_S_GROUPFILE_REPORT_UPLOAD_RESULT_ARG
{
    TUP_CHAR    prefileId[IM_D_MAX_PASSWORD_LENGTH];           /**< [en]Indicates pre-upload file ID. [cn]Ԥ�ϴ��ļ�ID */
    TUP_CHAR    groupId[IM_D_GROUPID_LENGTH];                  /**< [en]Indicates group ID. [cn]Ⱥ��ID */
    TUP_CHAR    uploadUserAccount[IM_D_MAX_ACCOUNT_LENGTH];    /**< [en]Indicates upload user account. [cn]�ϴ����˺� */
    TUP_CHAR    fileName[IM_D_MAX_NAME_LENGTH];                /**< [en]Indicates file name. [cn]�ļ��� */
    TUP_INT64    fileSize;                                     /**< [en]Indicates file size. [cn]�ļ���С */
    TUP_CHAR    fileURL[IM_D_URL_LENGTH];                      /**< [en]Indicates file URL. [cn]�ļ�URL */
    TUP_BOOL    result;                                        /**< [en]Indicates whether upload successful, value: true meas yes, false means no. [cn]�ϴ��Ƿ�ɹ� ȡֵ��trueΪ�ϴ��ɹ���falseΪ�ϴ�ʧ��[MODIFY] */
}IM_S_GROUPFILE_REPORT_UPLOAD_RESULT_ARG;

/**
 * [en]This structure is used to describe result of group shared file upload.
 * [cn]Ⱥ�����ļ��ϴ����
 */
typedef struct tagIM_S_GROUPFILE_REPORT_UPLOAD_RESULT_ACK
{
    TUP_CHAR    fileId[IM_D_MAX_PASSWORD_LENGTH];              /**< [en]Indicates file ID. [cn]�ļ�ID */
    TUP_CHAR    uploadTime[IM_D_MAX_TIMESTAMP_LENGTH];         /**< [en]Indicates uploaded time of server. [cn]���������ϴ��ɹ���ʱ�� */
}IM_S_GROUPFILE_REPORT_UPLOAD_RESULT_ACK; 

/**
 * [en]This structure is used to describe request of pre-deletion group shared file.
 * [cn]Ԥɾ��Ⱥ�����ļ�����
 */
typedef struct tagIM_S_GROUPFILE_PRE_DELETE_ARG
{
    TUP_CHAR    fileId[IM_D_MAX_PASSWORD_LENGTH];              /**< [en]Indicates file ID. [cn]�ļ�ID */
    TUP_CHAR    groupId[IM_D_GROUPID_LENGTH];                  /**< [en]Indicates group ID. [cn]Ⱥ��ID */
}IM_S_GROUPFILE_PRE_DELETE_ARG;

/**
 * [en]This structure is used to describe reponse of pre-deletion group shared file.
 * [cn]Ԥɾ��Ⱥ�����ļ���Ӧ
 */
typedef struct tagIM_S_GROUPFILE_PRE_DELETE_ACK
{
    TUP_CHAR    preDeleteFileID[IM_D_MAX_PASSWORD_LENGTH];     /**< [en]Indicates pre-delete file ID. [cn]Ԥɾ���ļ�ID */
}IM_S_GROUPFILE_PRE_DELETE_ACK;

/**
 * [en]This structure is used to describe result of group share file delete.
 * [cn]Ⱥ�����ļ�ɾ�����
 */
typedef struct tagIM_S_GROUPFILE_REPORT_DELETE_RESULT_ARG
{
    TUP_CHAR    fileId[IM_D_MAX_PASSWORD_LENGTH];              /**< [en]Indicates file ID. [cn]�ļ�ID */
    TUP_CHAR    groupId[IM_D_GROUPID_LENGTH];                  /**< [en]Indicates group ID. [cn]Ⱥ��ID */
}IM_S_GROUPFILE_REPORT_DELETE_RESULT_ARG;

/**
 * [en]This structure is used to describe request of query groups share file.
 * [cn]Ⱥ�����ļ���ѯ����
 */
typedef struct tagIM_S_GROUPFILE_QUERY_ARG
{
    TUP_CHAR    groupId[IM_D_GROUPID_LENGTH];                  /**< [en]Indicates group ID. [cn]Ⱥ��ID */
    TUP_CHAR    queryKey[IM_D_GENEAL_LENGTH] ;                 /**< [en]Indicates query key(Required). [cn]�ؼ��� (����) */
    IM_E_GROUPFILE_QUERY_TYPE    queryType;                    /**< [en]Indicates query type of group shared file. [cn]Ⱥ�����ļ���ѯ���� */
    TUP_INT32    offset;                                       /**< [en]Indicates query offset(Optional). [cn]��ѯƫ���� (ѡ��) */ 
    TUP_INT32    count;                                        /**< [en]Indicates the number of results returned by single query.(Required) [cn]���β�ѯ������ص�����(����) */ 
}IM_S_GROUPFILE_QUERY_ARG;

/**
 * [en]This structure is used to describe response of query group shared file.
 * [cn]Ⱥ�����ļ���ѯ��Ӧ
 */
typedef struct tagIM_S_GROUPFILE_QUERY_ACK
{
    TUP_INT32    recordAmount;                                 /**< [en]Indicates total number of records. [cn]�ܼ�¼�� */ 
    TUP_S_LIST*    groupFileList;                              /**< [en]Indicates group shared file list. Value reference: IM_S_GROUPFILE_INFO. [cn]Ⱥ�����ļ��б� TUP_S_LIST�е�*dada�ṹ����Ϊ IM_S_GROUPFILE_INFO*/ 
}IM_S_GROUPFILE_QUERY_ACK;

/**
 * [en]This structure is used to describe group shared file change notifications.
 * [cn]Ⱥ�����ļ����֪ͨ
 */
typedef struct tagIM_S_GROUPFILE_NOTIFY
{
    TUP_CHAR    origin[IM_D_MAX_ACCOUNT_LENGTH];               /**< [en]Indicates the sender account. [cn]���ͷ��˺�*/
    TUP_CHAR    target[IM_D_MAX_ACCOUNT_LENGTH];               /**< [en]Indicates the receiver account. [cn]���շ��˺�*/
    TUP_CHAR    groupId[IM_D_GROUPID_LENGTH];                  /**< [en]Indicates group ID. [cn]Ⱥ��ID */
    IM_E_GROUPFILE_NOTIFE_TYPE    type;                        /**< [en]Indicates notification type.[cn]֪ͨ��ʶ */
    TUP_CHAR    fileId[IM_D_MAX_PASSWORD_LENGTH];              /**< [en]Indicates file ID. [cn]�ļ�ID */
    IM_E_GROUPFILE_OPT_TYPE    opttype;                        /**< [en]Indicates group space file operation type. [cn]Ⱥ�ռ��ļ�������� */
    TUP_CHAR    timeStamp[IM_D_MAX_TIMESTAMP_LENGTH];          /**< [en]Indicates group space table update timestamp ID. [cn]Ⱥ�ռ�����ʱ���ID */
    TUP_INT64    totalSize;                                    /**< [en]Indicates total size. [cn]�ܿռ��С */
    TUP_INT64    remainSize;                                   /**< [en]Indicates remain size. [cn]ʣ��ռ��С */
}IM_S_GROUPFILE_NOTIFY; 

/**
 * [en]This structure is used to describe linkage status.
 * [cn]����״̬
 */
typedef struct tagIM_S_LINKAGE_STATUS
{
    TUP_BOOL  bisLinkage;                                      /**< [en]Indicates whether it's linkage. [cn]����״̬�������Ƿ��� */
}IM_S_LINKAGE_STATUS;


#ifdef __cplusplus
#if __cplusplus
}
#endif /*  __cpluscplus */
#endif /*  __cpluscplus */



#endif //_TUP_IM_EXTENDDEF_H_

/** @}*/

/*
* History: \n
* 2012-12-10, ��ʼ�����ļ��� \n
* 2015-12-30, TUP V100R001C50 TR5 ���������´��ļ��� \n
 *
* vi: set expandtab ts=4 sw=4 tw=80:
*/
