/**
 * @file TupErrorCode.h
 *
 * Copyright © 2017 Huawei Tech. Co., Ltd. All rights reserved. \n
 *
 * @brief [en]Description:error code definition class head file.
 * [cn]描述：错误码定义类头文价。 \n
 **/

#import <Foundation/Foundation.h>

#define Tup_SPECIFIC_ERROR_CODE_BEIGN 1000 // 除了TupCommonErrorCode以外的特定模块的错误码的最小值

#pragma mark - Error Domain

extern NSString * const TupCommonErrorDomain; // 通用错误

extern NSString * const TupLoginErrorDomain; // 登录
extern NSString * const TupContactErrorDomain; // 联系人
extern NSString * const TupGroupErrorDomain; // 群组
extern NSString * const TupiPhoneContactErrorDomain; // 手机通讯录
extern NSString * const TupInstantMessageErrorDomain; // IM消息
extern NSString * const TupRecentSessionErrorDomain;// 最近对话
extern NSString * const TupCallRecordErrorDomain; // 通话记录
extern NSString * const TupCallErrorDomain; // 通话
extern NSString * const TupUMErrorDomain; // UM
extern NSString * const TupConferenceErrorDomain; // 会议
extern NSString * const TupPublicAccountErrorDomain; // 公众号
extern NSString * const TupLightAppErrorDomain; // 轻应用
extern NSString * const TupCircleColleagueErrorDomain; // 同事圈
extern NSString * const TupVoiceMailErrorDomain; // 语音留言
extern NSString * const TupSettingErrorDomain; // 设置
extern NSString * const TupSvnErrorDomain; // svn
extern NSString * const TupDBUpdateErrorDomain; // 数据库升级
extern NSString * const TupEventRecordErrorDomain; // 事件打点

extern NSString * const TupUMServerErrorDomain; // 富媒体服务器错误
extern NSString * const TupCertificateDownloadErrorDomain; // 证书下载错误

//消息撤回
extern NSString * const TupRecallMessageTimeOutErrorDomain;
extern NSString * const TupRecallMessageTimeOutKey;
//
#pragma mark - Error userInfo
/*
 * 基本上只使用iOS自带的key值即可 [key, value]
 * NSLocalizedDescriptionKey 问题描述
 * NSLocalizedFailureReasonErrorKey 问题原因 （建议大家使用这个来写自己的具体问题）
 * NSLocalizedRecoverySuggestionErrorKey 针对问题给出的建议
 
 举例:
 NSDictionary *userInfo =
 @{
 NSLocalizedDescriptionKey: NSLocalizedString(@"Operation was unsuccessful.", nil),
 NSLocalizedFailureReasonErrorKey: NSLocalizedString(@"The operation timed out.", nil),
 NSLocalizedRecoverySuggestionErrorKey: NSLocalizedString(@"Have you tried turning it off and on again?", nil)
 };
 */



#pragma mark - Error Code
/*
 * 1: error code 是跟特定的error domain绑定的，所以原则上每个特定error domain下可以定义一样的错误码；
 ＊
 ＊ 2: 为了更易于区分错误，每个error domain下拥有自己单独的error code范围为1000
 ＊（不需要显示的进行赋值，为了以防以后TupCommonErrorCode超过1000的情况）
 ＊
 ＊ 3: TupCommonErrorCode 定义了一些通用的错误码，比如服务器响应超时，接口请求参数不正确等。可被所有的模块所使用
 ＊
 ＊ 4: Tup*ErrorCode 都是特定模块的错误码，只用于特定模块
 */

/**
 * [en]This enum is about normal error code definition.
 * [cn]普通错误码定义
 */
typedef NS_ENUM(NSInteger, TupCommonErrorCode)
{
    TupCommonSuccessCode = 0,                       /**< [en]Indicates MAA response success result code.
                                                     <br>[cn]MAA响应成功的结果码 */
    
    // MAA 接口返回 -----Begin
    TupCommonMaaUndefinedError = -1,                /**< [en]Indicates  common error, undefined error.
                                                     <br>[cn]通用错误，未加以定义的错误 */
    TupCommonSessionExpiredError = -2,              /**< [en]Indicates session expire, client can chose this session for login.
                                                     <br>[cn]session过期，客户端可选择使用此会话重登 */
    TupCommonLoginFailedError = -3,                 /**< [en]Indicates login failed, server will return error prompt.
                                                     <br>[cn]登录失败; 此错误服务器会返回失败提示语 */
    TupCommonRequestMessageError = -4,              /**< [en]Indicates client request message error, client CDATA file not suit XML standard, lack node, must return when attribute is null.
                                                     <br>[cn]客户端请求消息异常, 客户端的CDATA文件不符合XML规范, 缺少节点, 必填属性为空时返回 */
    TupCommonClientInterfaceError = -5,             /**< [en]Indicates interface error, include no response, return message parse error.
                                                     <br>[cn]与appServer, eServer交互时出现错误，包括无响应，返回消息解析出错 */
    TupCommonSessionKickedOutError = -6,            /**< [en]Indicates user login in other place, session state has changed.
                                                     <br>[cn]用户在其他地方登录，会话状态已改变 */
    TupCommonRequestPageSizeError = -7,             /**< [en]Indicates request page size error(page not  correct).
                                                     <br>[cn]请求页数错误（页数不正确，包括请求的页数大于最大页数） */
    TupCommonMessageNotExistError = -8,             /**< [en]Indicates mode message deel not exist.
                                                     <br>[cn]模块消息处理未找到(业务层中未定义的消息接口) */
    TupCommonSessionNotExistError = -9,             /**< [en]Indicates session not exist or overtime, when user offline too long.
                                                     <br>[cn]session不存在或已超时被回收，当用户离线时间过长（默认配置1小时） */
    TupCommonClientNotEnableError = -10,            /**< [en]Indicates not enable mobile authority.
                                                     <br>[cn]未开通手机客户端权限 */
    TupCommonDeviceSerialNumberError = -11,         /**< [en]Indicates device serial number error.
                                                     <br>[cn]设备序列号不正确 */
    TupCommonQueryResultNotExistError = -12,        /**< [en]Indicates query result not exist.
                                                     <br>[cn]查询结果不存在 */
    TupCommonMediaXEnterConfFailedError = -20,      /**< [en]Indicates mediax enter conf failed.
                                                     <br>[cn]MediaX一键入会失败 */
    TupCommonAppServerResponseError = -21,          /**< [en]Indicates appserver return error, conf has locked.
                                                     <br>[cn]AppServer返回信息错误， 会场已经锁定 */
    TupCommonConfNotExist = -30,                    /**< [en]Indicates conf not exist.
                                                     <br>[cn]会议不存在 */
    TupCommonAddConfParticipantFailedError = -31,   /**< [en]Indicates add conf participant failed.
                                                     <br>[cn]与会人邀请失败（与会人正在呼叫或已经加入会议，再次邀请出现此错误） */
    TupCommonConfParticipantNotInConfError = -35,   /**< [en]Indicates participant not in conf.
                                                     <br>[cn]与会人不在会议中 */
    TupCommonNoNeedChangeSpeakingRightError = -43,  /**< [en]Indicates no need change speaking right.
                                                     <br>[cn]无需修改话语权 */
    TupCommonMAAForwardAddressError = -50,          /**< [en]Indicates maa server forward .
                                                     <br>[cn]maa服务器重定向（非错误） */
    TupCommonLackOfResourceError = -100,            /**< [en]Indicates lack of resource.
                                                     <br>[cn]资源不足，专用与升级响应 */
    TupCommonAccessEachOtherForbiddenError = -101,  /**< [en]Indicates access each other forbidden.
                                                     <br>[cn]服务器因为安全策略不允许互相通信 */
    TupCommonServerOverFlowError = -102,            /**< [en]Indicates overflow.
                                                     <br>[cn]服务器过载 */
    TupCommonBusinessConflictError = -106,          /**< [en]Indicates business conflict.
                                                     <br>[cn]业务冲突 */
    TupCommonDeviceIDError = -201,                  /**< [en]Indicates device id expire.
                                                     <br>[cn]表示push通道的deviceID过期，或者不可用 */
    TupCommonRefressHeatBeatError = -412,           /**< [en]Indicates represent ps disaster recovery, must refresh heat beat.
                                                     <br>[cn]表示PS容灾，必须重新刷新心跳（PS服务器异常之后，客户端发布状态会返回该错误码，需要发送第一次心跳触发MAA／ESG需要客户端到新的PS上重新注册／订阅） */
    
    TupCommonInvalidDataException = 1,              /**< [en]Indicates invalid data or xml standard.
                                                     <br>[cn]消息不完整或者不符合xml规范而无法解析 */
    TupCommonServiceNotFoundException = 2,          /**< [en]Indicates service not found.
                                                     <br>[cn]消息服务不存在（不存在这样的MsgType时候，返回错误响应） */
    TupCommonReloginSuccessError = 4,               /**< [en]Indicates relogin success.
                                                     <br>[cn]客户端重新连接的返回结果 */
    // MAA 接口返回 －－－-End
    
    //消息撤回超时 ————————————————————————————————————————————
    TupCommonRecallMessageTimeOutError = 38,        /**< [en]Indicates recall message time out.
                                                     <br>[cn]消息撤回超时 */
    
    TupCommonMessageSizeError = 200,                /**< [en]Indicates maa message size error.
                                                     <br>[cn]maa消息大小不正确 */
    
    // http 请求错误 ——————————————————————————————————————————
    TupCommonHttpRequestError = 400,                /**< [en]Indicates request error.
                                                     <br>[cn]请求错误 */
    TupCommonHttpUnauthorizedError = 401,           /**< [en]Indicates unauthorized.
                                                     <br>[cn]未授权 */
    TupCommonHttpForbiddenError = 403,              /**< [en]Indicates forbidden.
                                                     <br>[cn]禁止访问 */
    TupCommonHttpNotFoundError = 404,               /**< [en]Indicates http not found.
                                                     <br>[cn]URL错误,未找到 */
    TupCommonHttpTimeoutError = 408,                /**< [en]Indicates http time out.
                                                     <br>[cn]请求超时 */
    // http 请求错误 ——————————————————————————————————————————
    
    TupCommonMAAConnectionFailedError = INT_MAX,    /**< [en]xxxx.
                                                     <br>[cn]2147483647 */
    TupCommonMAACancelledError = INT_MAX - 1,       /**< [en]xxxx.
                                                     <br>[cn]2147483646 */
    TupCommonMAATimeOutError = INT_MAX - 2,         /**< [en]xxxx.
                                                     <br>[cn]2147483645 */
    TupCommonSocketCloseError = INT_MAX - 3,        /**< [en]xxxx.
                                                     <br>[cn]2147483644 */
    TupCommonMAAResendFailedError = INT_MAX - 4,    /**< [en]xxxx.
                                                     <br>[cn]2147483643 */
    TupCommonNetworkUnreachError = INT_MAX - 5,     /**< [en]xxxx.
                                                     <br>[cn]2147483642 */
    
    TupCommonMAAInvalidArgsError = INT_MAX - 10,    /**< [en]xxxx.
                                                     <br>[cn]2147483637 */
    TupCommonMAANoRightError = INT_MAX - 11,        /**< [en]xxxx.
                                                     <br>[cn]2147483636 */
    
    TupCommonHTTPCancelledError = TupCommonMAACancelledError
};

/**
 * [en]xxxx.
 * [cn]登录错误码定义
 */
typedef NS_ENUM(NSInteger, TupLoginErrorCode)
{
    TupLoginErrorCodeBegin = 1000,
    TupLoginServiceOverFlow = TupCommonServerOverFlowError, /**< [en]Indicates login service over flow.
                                                             <br>[cn]loginAck返回服务器过载 */
    TupLoginWatingUIOperationError = 1001,                  /**< [en]Indicates waiting UI operation.
                                                             <br>[cn]登录流程中，需要等待UI的操作，返回此错误码。 */
    TupLoginCancelByUIError = 1002,                         /**< [en]Indicates cancel by UI.
                                                             <br>[cn]登录流程中，UI取消登录，返回此错误码。 */
    TupLoginNeedToUpgradeError = 1003,                      /**< [en]Indicates check version need to upgrade.
                                                             <br>[cn]登录流程中，checkVersion返回需要升级，返回此错误码 */
    TupLoginKeyExchangeError = 1004,                        /**< [en]Indicates key exchange.
                                                             <br>[cn]密钥交换中没有找到aesKey */
    TupLoginRequestToMAACancelError = 1005,                 /**< [en]Indicates request to MAA cancel.
                                                             <br>[cn]自动取消 */
    TupLoginRequestToMAASelfCancelError = 1006,             /**< [en]Indicates request to MAA self cancel.
                                                             <br>[cn]自己主动取消 */
    TupLoginLoginingError = 1007,                           /**< [en]Indicates logining.
                                                             <br>[cn]已经处于登录状态 */
    TupLoginUndefinedStatusMachineCommadError = 1008,       /**< [en]Indicates undefined status machine commad.
                                                             <br>[cn]状态码未找到 */
    TupLoginGetMDMInfoFailed = 1009,                        /**< [en]Indicates get MDM info failed.
                                                             <br>[cn]从mdm获取登录帐号和密码失败 */
    TupLoginHWUCSwitchLoginUserError = 1010,                /**< [en]Indicates HWUC switch login user.
                                                             <br>[cn]hwuc单点登录，获取到的登录账号和当前已经登录的账号不同 */
    TupLoginAnyofficeSwitchLoginUserError = 1011,           /**< [en]Indicates any office switch login user.
                                                             <br>[cn]基线anyoffice单点登录，获取到的登录信息和当前已经登录的账号信息不同 */
    TupLoginUportalDetectFailed = 1012,                     /**< [en]Indicates uportal detect failed.
                                                             <br>[cn]登录流程中, 向Uportal探测失败 */
    TupLoginUportalConnectedFailed = 1013,                  /**< [en]Indicates uportal connected failed.
                                                             <br>[cn]EC6.0 Uportal不可达 */
    TupLoginUportalAccountError = 1014,                     /**< [en]Indicates uportal account passcode error.
                                                             <br>[cn]EC6.0 uPortal鉴权账号密码错误 */
    TupLoginUportalTimeout = 1015,                          /**< [en]Indicates uportal time out.
                                                             <br>[cn]EC6.0 uPortal鉴权超时 */
    TupLoginUportalAccountLockedError = 1016,               /**< [en]Indicates uportal account locked.
                                                             <br>[cn]EC6.0 uPortal账号被锁定 */
    TupLoginUportalUnBussinessError = 1017,                 /**< [en]Indicates uportal unbussiness.
                                                             <br>[cn]EC6.0 uPortal鉴权中，非业务错误 */
    TupLoginTokenRefreshFailed = 1018,                      /**< [en]Indicates token refresh failed.
                                                             <br>[cn]token刷新失败 */
    TupLoginArgInvalidError = 1019,                         /**< [en]Indicates arg invalid.
                                                             <br>[cn]参数错误 */
    TupLoginTokenValueEmptyError = 1020,                    /**< [en]Indicates token value empty.
                                                             <br>[cn]token值为空 */
    TupLoginDestroySTGTunnelError = 1021,                   /**< [en]Indicates destroy stg tunnel failed.
                                                             <br>[cn]销毁隧道失败 */
    TupLoginCreateSTGTunnelError = 1022,                    /**< [en]Indicates create stg tunnel failed.
                                                             <br>[cn]创建stg隧道失败 */
    TupLoginFirewallDetectError = 1023,                     /**< [en]Indicates firewall detect failed.
                                                             <br>[cn]防火墙探测失败 */
    TupLoginActionProcessingError = 1024,                   /**< [en]Indicates action processing.
                                                             <br>[cn]存在类似操作正在进行 */
    TupLoginErrorCodeEnd = 1999
};

/**
 * [en]This enum is about contact error code definition.
 * [cn]联系人错误码定义
 */
typedef NS_ENUM(NSInteger, TupContactErrorCode)
{
    TupContactErrorCodeBegin = 2000,
    
    TupContactErrorArgsError = 2001,            /**< [en]Indicates arg error.
                                                 <br>[cn]参数错误 */
    TupContactSyncLocalContactError = 2002,     /**< [en]Indicates syn local contact failed.
                                                 <br>[cn]没有权限导致同步本地联系人失败 */
    TupContactQueryServerContactError = 2003,   /**< [en]Indicates query server contact failed.
                                                 <br>[cn]查询指定联系人失败 */
    TupContactAddFriendTeamNotExistError = 2004,/**< [en]Indicates team not exist.
                                                 <br>[cn]分组不存在错误 */
    
    TupContactErrorCodeEnd = 2999
};

/**
 * [en]This enum is about group error code definition.
 * [cn]分组错误码定义
 */
typedef NS_ENUM(NSInteger, TupGroupErrorCode)
{
    TupGroupErrorCodeBegin = 3000,
    
    TupGroupGroupNameError = 3001,              /**< [en]Indicates group name illegal.
                                                 <br>[cn]群组名称不合法 */
    
    TupGroupErrorCodeEnd = 3999
};

/**
 * [en]This enum is about iphone contact error code definition.
 * [cn]iPhone联系人错误码定义
 */
typedef NS_ENUM(NSInteger, TupiPhoneContactErrorCode)
{
    TupiPhoneContactErrorCodeBegin = 4000,
    
    TupiPhoneContactErrorCodeEnd = 4999
};

/**
 * [en]This enum is about instant message error code definition.
 * [cn]即时消息错误码定义
 */
typedef NS_ENUM(NSInteger, TupInstantMessageErrorCode)
{
    TupInstantMessageErrorCodeBegin = 5000,
    
    TupInstantMessageResourceUploadError = 5001,    /**< [en]Indicates um upload failed.
                                                     <br>[cn]UM上传失败 */
    TupInstantMessageResourceUploadingError = 5002, /**< [en]Indicates is uploading.
                                                     <br>[cn]正在上传UM */
    
    TupInstantMessageErrorCodeEnd = 5999
};

/**
 * [en]This enum is about recent error code definition.
 * [cn]最近会话错误码定义
 */
typedef NS_ENUM(NSInteger, TupRecentSessionErrorCode)
{
    TupRecentSessionErrorCodeBegin = 6000,
    
    TupRecentSessionErrorCodeError = 6999
};

/**
 * [en]This enum is about call record error code definition.
 * [cn]呼叫记录错误码定义
 */
typedef NS_ENUM(NSInteger, TupCallRecordErrorCode)
{
    TupCallRecordErrorCodeBegin = 7000,
    
    TupCallRecordErrorCodeError = 7999
};

/**
 * [en]This enum is about call error code.
 * [cn]呼叫错误码定义
 */
typedef NS_ENUM(NSInteger, TupCallErrorCode)
{
    TupCallErrorCodeBegin = 8000,
    
    TupCallErrorCodeEnd = 8999
};

/**
 * [en]This enum is about um resource file error code definition.
 * [cn]富媒体文件错误码定义
 */
typedef NS_ENUM(NSInteger, TupUMErrorCode)
{
    TupUMErrorCodeBegin = 9000,
    
    TupUMFileNotFoundError = 9001,          /**< [en]Indicates file not found.
                                             <br>[cn]文件未找到 */
    TupUMCreateEncrtypedError = 9002,       /**< [en]Indicates create encrtyed file failed.
                                             <br>[cn]创建加密文件夹失败 */
    TupUMFileResourcePathError = 9003,      /**< [en]Indicates file resource path error.
                                             <br>[cn]文件路径错误 */
    TupUMIdeskFileInputStreamError = 9004,  /**< [en]Indicates idesk file input stream created failed.
                                             <br>[cn]加密文件输入流创建失败 */
    TupUMDownloadLocalPathOrURLError = 9005,/**< [en]Indicates download local path or url error.
                                             <br>[cn]下载的文件服务器地址，或者本地存储路径不正确 */
    
    TupUMErrorCodeEnd = 9999
};

/**
 * [en]This enum is about conf error code definition.
 * [cn]会议错误码定义
 */
typedef NS_ENUM(NSInteger, TupConferenceErrorCode)
{
    TupConferenceErrorCodeBegin = 10000,
    
    TupConferenceJoinConferenceResultError = 10001,             /**< [en]Indicates join conf error.
                                                                 <br>[cn]加入会议失败 */
    TupConferenceConferenceIDIllegalError = 10002,              /**< [en]Indicates conf in illegal.
                                                                 <br>[cn]会议ID不合法 */
    TupConferenceEmptyUserNumError = 10003,                     /**< [en]Indicates user number is null.
                                                                 <br>[cn]用户帐号为空 */
    TupConferenceInviteAttendeesEmptyError = 10004,             /**< [en]Indicates invite attendee empty.
                                                                 <br>[cn]邀请列表为空 */
    TupConferenceAttendeeNotExistError = 10005,                 /**< [en]Indicates attendee not exist.
                                                                 <br>[cn]与会者不存在 */
    TupConferenceAttendeeHaveLeaveError = 10006,                /**< [en]Indicates attendee have leave.
                                                                 <br>[cn]与会者已经离开会议 */
    TupConferenceBeenMultimediaAlreadyError = 10007,            /**< [en]Indicates current been multi media already.
                                                                 <br>[cn]当前已经是多媒体会议 */
    TupConferenceConferenceHaveCloseError = 10008,              /**< [en]Indicates conference have close.
                                                                 <br>[cn]会议已经关闭 */
    TupConferenceNeedShieldConfError = 10009,                   /**< [en]Indicates conf need shield .
                                                                 <br>[cn]会议需要屏蔽 */
    TupConferenceBookConfError = 10010,                         /**< [en]Indicates book conf failed.
                                                                 <br>[cn]预约会议失败 */
    TupConferenceEndConfError = 10011,                          /**< [en]Indicates  end conf failed.
                                                                 <br>[cn]结束会议失败 */
    TupConferenceUpgradeConfError = 10012,                      /**< [en]Indicates upgrade conf failed.
                                                                 <br>[cn]升级会议失败 */
    TupConferenceRequestMasterError = 10013,                    /**< [en]Indicates request mastrt failed.
                                                                 <br>[cn]申请会议主持人失败 */
    TupConferenceReleaseMasterError = 10014,                    /**< [en]Indicates release master failed.
                                                                 <br>[cn]释放会议主持人失败 */
    TupConferenceLeaveConfError = 10015,                        /**< [en]Indicates leave conf failed.
                                                                 <br>[cn]退出会议失败 */
    TupConferenceAddAttendeeError = 10016,                      /**< [en]Indicates add attendee failed.
                                                                 <br>[cn]添加与会者失败 */
    TupConferenceRemoveAttendeeError = 10017,                   /**< [en]Indicates remove attendee failed.
                                                                 <br>[cn]删除与会者失败 */
    TupConferenceMuteConfError = 10018,                         /**< [en]Indicates mute conf failed.
                                                                 <br>[cn]闭音/取消闭音会场失败 */
    TupConferenceMuteAttendeeError = 10019,                     /**< [en]Indicates mute attendee failed.
                                                                 <br>[cn]闭音/取消闭音与会者失败 */
    TupConferenceHangupAttendeeError = 10020,                   /**< [en]Indicates hangup attendee failed.
                                                                 <br>[cn]挂断与会者失败 */
    TupConferenceGetDataConfParamError = 10021,                 /**< [en]Indicates get data conf param failed.
                                                                 <br>[cn]获取数据会议大参数失败 */
    TupConferenceUnopenError = 10022,                           /**< [en]Indicates conf not open.
                                                                 <br>[cn]会议未开始 */
    TupConferenceGetConfListError = 10023,                      /**< [en]Indicates get conf list failed.
                                                                 <br>[cn]获取会议列表失败 */
    TupConferenceGetConfInfoError = 10024,                      /**< [en]Indicates get conf info failed.
                                                                 <br>[cn]获取与会者列表失败 */
    TupConferenceSetHandleError = 10025,                        /**< [en]Indicates set conf handle failed.
                                                                 <br>[cn]创建confhandle失败 */
    TupConferenceGEtConfBigParamError = 10026,                  /**< [en]Indicates get conf big param failed.
                                                                 <br>[cn]获取数据会议大参数失败 */
    TupConferenceConfInProgressError = 10027,                   /**< [en]Indicates conf in progress.
                                                                 <br>[cn]当前有会议正在进行 */
    TupConferenceRequestRepeatError = 10997,                    /**< [en]Indicates request repeat.
                                                                 <br>[cn]同时存在多个相同请求错误 */
    TupConferenceGetConfInfoConfNotExistOrEndedError = 200001,  /**< [en]Indicates when get conf info, conf not exist or ended.
                                                                 <br>[cn]请求会议信息的时候会议已结束或者不存在错误 */
    TupConferenceAddAttendeeConfIsLocked = 200025,              /**< [en]Indicates conf is locked when add attendee.
                                                                 <br>[cn]邀请与会人入会的时候会议被锁定(EC6.0组网下内置会议一键入会流程处理) */
    TupConferenceCommonError = 10998,                           /**< [en]Indicates common error.
                                                                 <br>[cn]通用错误 */
    TupConferenceErrorCodeEnd = 10999
    
    
};

/**
 * [en]	This enum is about public account error code definition.
 * [cn]公众号错误码定义
 */
typedef NS_ENUM(NSInteger, TupPublicAccountErrorCode)
{
    TupPublicAccountErrorCodeBegin = 11000,
    
    TupPublicAccountHistorySessionParamError = 11001,           /**< [en]Indicates account history session param error.
                                                                 <br>[cn]公众号历史消息session错误 */
    TupPublicAccountQueryConditionError = 11002,                /**< [en]Indicates account query condition error.
                                                                 <br>[cn]向服务器查询公众号的条件不正确 */
    TupPublicAccountSubscribeExistError = 11003,                /**< [en]Indicates subcribe exist public account.
                                                                 <br>[cn]订阅已经存在的公众号 */
    TupPublicAccountDownloadHDIconError = 11004,                /**< [en]Indicates download HD icon error.
                                                                 <br>[cn]下载公众号高清头像错误 */
    TupPublicAccountSubscribePaError = 11005,                   /**< [en]Indicates subscribe public account error.
                                                                 <br>[cn]订阅公众号错误，公众号为空 */
    
    TupPublicAccountErrorCodeEnd = 11999
};

/**
 * [en]This enum is about light app error .
 * [cn]轻应用错误码定义
 */
typedef NS_ENUM(NSInteger, TupLightAppErrorCode)
{
    TupLightAppErrorCodeBegin = 12000,
    
    TupLightAppErrorCodeEnd = 12999
};

/**
 * [en]This enum is about circle colleague error code.
 * [cn]同事圈错误码定义
 */
typedef NS_ENUM(NSInteger, TupCircleColleagueErrorCode)
{
    TupCircleColleagueErrorCodeBegin = 13000,
    
    TupCircleColleagueUMUploadingError = 13001,     /**< [en]Indicates be uploading um.
                                                     <br>[cn]正在上传UM */
    TupCircleColleagueUMUploadFailedError = 13002,  /**< [en]Indicates um upload failed.
                                                     <br>[cn]UM上传失败 */
    
    TupCircleColleagueErrorCodeEnd = 13999
};

/**
 * [en]This enum is about voice mail error code definition.
 * [cn]语音邮箱错误码定义
 */
typedef NS_ENUM(NSInteger, TupVoiceMailErrorCode)
{
    TupVoiceMailErrorCodeBegin = 14000,
    
    TupVoiceMailErrorCodeEnd = 14999
};

/**
 * [en]This enum is about setting personal error code.
 * [cn]设置个人信息错误码定义
 */
typedef NS_ENUM(NSInteger, TupSettingErrorCode)
{
    TupSettingErrorCodeBegin = 15000,
    
    TupSettingSelfStatusMapError = 15001,       /**< [en]Indicates self status.
                                                 <br>[cn]个人状态 */
    
    TupSettingDefHeadImageError = 15002,        /**< [en]Indicates definition head image.
                                                 <br>[cn]自定义头像 */
    
    TupSettingSysHeadImageError = 15003,        /**< [en]Indicates system head.
                                                 <br>[cn]系统头像 */
    
    TupSettingErrorCodeError = 15999
};

/**
 * [en]This enum is about safe gatewall error code definition.
 * [cn]安全网关错误码定义
 */
typedef NS_ENUM (NSInteger, TupSvnErrorCode)
{
    TupSvnAccountLockedError = -16,             /**< [en]Indicates safe gatewall account has locked.
                                                 <br>[cn]安全网关帐号已被锁定，请稍候再试或联系管理员 */
    TupSvnAccountOrPasswordError = -5,          /**< [en]Indicates account or password error.
                                                 <br>[cn]安全网关帐号或密码错误 */
    TupSvnNoResponseError = -4,                 /**< [en]Indicates safe gatewall no response.
                                                 <br>[cn]安全网关无响应 */
    // 以上是svn库返回的错误类型
    
    TupSvnErrorCodeBegin = 16000,
    
    TupSvnUnknowError = 16001,                  /**< [en]Indicates unknow error.
                                                 <br>[cn]未知错误 */
    TupSvnConnectedFailedError = 16002,         /**< [en]Indicates svn connected failed.
                                                 <br>[cn]svn连接失败 */
    
    TupSvnErrorCodeEnd = 16999
};

/**
 * [en]This enum is about database update error code definition.
 * [cn]数据库升级错误码定义
 */
typedef NS_ENUM(NSInteger, TupDBUpdateErrorCode)
{
    TupDBUpdateErrorCodeBegin = 17000,
    
    TupDBUpdateOldConfigNotExistError = 17001,  /**< [en]Indicates old version user config not exist.
                                                 <br>[cn]旧版本 UserConfig 不存在 */
    
    TupDBUpdateErrorCodeEnd = 17999
};

/**
 * [en]This enum is about record error code.
 * [cn]打点错误码定义
 */
typedef NS_ENUM(NSInteger, TupEventRecordErrorCode)
{
    TupEventRecordErrorCodeBegin = 18000,
    
    TupEventRecordNoRecodeToReportError = 18001,/**< [en]Indicates no record to report.
                                                 <br>[cn]没有需要报告的数据 */
    
    TupEventRecordErrorCodeEnd = 18999
};
