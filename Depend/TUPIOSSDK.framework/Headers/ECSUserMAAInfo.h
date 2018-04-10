/**
 * @file ECSUserMAAInfo.h
 *
 * Copyright © 2017 Huawei Tech. Co., Ltd. All rights reserved. \n
 *
 * @brief [en]Description:user info basic service function class head file.
 * [cn]描述：用户信息基础业务功能类头文件。 \n
 **/

#import <Foundation/Foundation.h>
#import "ECSDefines.h"

/**
 * [en]This enum is about client type definition.
 * [cn]客户端类型定义
 */
typedef NS_ENUM(NSInteger, ECS_CLIENT_TYPE) {
    ECS_UNKNOWN_CLIENT      = -1,       /**< [en]Indicates unknown.
                                         <br>[cn]未知 */
    ECS_PC_CLIENT			= 0,        /**< [en]Indicates pc.
                                         <br>[cn]pc */
    ECS_MOBILE_CLIENT		= 1,        /**< [en]Indicates mobile.
                                         <br>[cn]mobile */
    ECS_WEB_CLIENT			= 2,        /**< [en]Indicates web.
                                         <br>[cn]web */
    ECS_PAD_CLIENT			= 3,        /**< [en]Indicates pad.
                                         <br>[cn]Pad */
    ECS_IPPHONE_CLIENT     = 4,         /**< [en]Indicates ip phone.
                                         <br>[cn]IP电话 */
    ECS_IMSS_CLIENT        = 5,         /**< [en]Indicates imss client.
                                         <br>[cn]IMSS客户端 */
};

/**
 * [en]This enum is about password update flag.
 * [cn]密码更新标记
 */
typedef NS_ENUM(NSInteger, PwUpdateFlag) {
    PwUpdateFlagNormal = 0,             /**< [en]Indicates normal.
                                         <br>[cn]正常 */
    PwUpdateFlagExpire = 1,             /**< [en]Indicates password expire, need update.
                                         <br>[cn]密码过期，需要更新 */
    PwUpdateFlagInitialization = 2      /**< [en]Indicates init password, need update.
                                         <br>[cn]初始密码，需要更新 */
};

#define IS_FUNC_ON(funcid, x) ((([(funcid) length]) > (x)) && (([(funcid) characterAtIndex:(x)]) == '1'))

/**
 * [en] This class is about client info.
 * [cn] 客户端信息类
 **/
@interface ECSClientInfo : NSObject<NSCoding>

@property (nonatomic, assign) ECS_CLIENT_TYPE clientType;
@property (nonatomic, assign) NSTimeInterval  eventTime;


/**
 * @brief [en] This method is used to get client type by description.
 *        <br>[cn] 根据描述返回客户端类型
 *
 * @param [in] NSString* typeStr      <b>:</b><br>[en] Indicates description info.
 *                                             <br>[cn] 描述信息
 * @retval ECS_CLIENT_TYPE            <b>:</b><br>[en] Return client type if success, or return ECS_UNKNOWN_CLIENT.
 *                                             <br>[cn] 成功返回客户端类型，失败返回ECS_UNKNOWN_CLIENT
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
+ (ECS_CLIENT_TYPE) typeWithDesc:(NSString*) typeStr;


/**
 * @brief [en] This method is used to init type.
 *        <br>[cn] 初始化方法
 *
 * @param [in] NSString* type                <b>:</b><br>[en] Indicates client type description info.
 *                                                    <br>[cn] 客户端类型描述信息
 * @param [in] NSTimeInterval eventTime      <b>:</b><br>[en] Indicates event time.
 *                                                    <br>[cn] 时间
 * @retval id                                <b>:</b><br>[en] Return ECSClientInfo object if success, or return nil.
 *                                                    <br>[cn] 成功返回ECSClientInfo对象，失败返回nil
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
- (id) initWithType:(NSString*) type eventTime:(NSTimeInterval) eventTime;

@end

/**
 * [en] This class is about application info.
 * [cn] APP应用信息类
 **/
@interface ECSAppInfo : NSObject<NSCoding>
@property (nonatomic, copy) NSString *appID;
@property (nonatomic, copy) NSString *appName;
@property (nonatomic, copy) NSString *appLogo;


/**
 * @brief [en] This method is used to init with id.
 *        <br>[cn] 初始化方法
 *
 * @param [in] NSString* type                <b>:</b><br>[en] Indicates app id.
 *                                                    <br>[cn] app id
 * @param [in] NSString* name                <b>:</b><br>[en] Indicates app name.
 *                                                    <br>[cn] app名称
 * @param [in] NSString* Logo                <b>:</b><br>[en] Indicates app logo.
 *                                                    <br>[cn] app图标地址
 * @retval id                                <b>:</b><br>[en] Return ECSAppInfo object if success, or return nil .
 *                                                    <br>[cn] 成功返回ECSAppInfo对象，失败返回nil
 * @attention [en] xxxx.
 *            <br>[cn] NA
 * @see NA
 **/
- (id) initWithID:(NSString *)ID name:(NSString *)name logo:(NSString *)Logo;
@end

/**
 * [en] This class is about video param.
 * [cn] 视频参数类
 **/
@interface ECSVideoParm : NSObject<NSCoding>

@property (nonatomic,assign) NSInteger p2pSoft;
@property (nonatomic,assign) NSInteger p2pHard;
@property (nonatomic,assign) NSInteger confSoft;
@property (nonatomic,assign) NSInteger confHard;
@property (nonatomic,assign) NSInteger mcuSoft;
@property (nonatomic,assign) NSInteger mcuHard;

@end

@interface ECSDiscoveryParam : NSObject<NSCoding>

@property (nonatomic,copy)NSString *logoUrl;
@property (nonatomic,copy)NSString *EName;
@property (nonatomic,copy)NSString *CName;
@property (nonatomic,copy)NSString *Url;

@end

@interface ECSNumberShowSupport : NSObject<NSCoding>

@property (nonatomic, assign) BOOL eSpaceNumberShowSupport;
@property (nonatomic, assign) BOOL phoneNumberShowSupport;

@end

@class ECSLoginAck;

/**
 * [en] This class is about info return after login successfully.
 * [cn] 登录返回的信息类
 **/
@interface ECSUserMAAInfo : NSObject<NSCoding>
@property (nonatomic,retain)    NSString*	name;
@property (nonatomic,retain)	NSString*	mobile;
@property (nonatomic,retain)	NSString*	callno;
@property (nonatomic,retain)	NSString*	sex;
@property (nonatomic,retain)	NSString*	headAddress;
@property (nonatomic,retain)	NSString*	mailAddress;
@property (nonatomic,retain)	NSString*	funcID;

@property (nonatomic,retain)	NSString*	imuserver;
@property (nonatomic,retain)	NSString*	imuport;
@property (nonatomic,assign)	short		maxconfnum;
@property (nonatomic,assign)	short		maxsmsnum;
@property (nonatomic,retain)	NSString*	voipnum;
@property (nonatomic,retain)	NSString*	voippin;
@property (nonatomic,retain)    NSString*   videoCodec;//点对点视频支持的媒体编码格式优先级 106:H264；34:H263
@property (nonatomic,assign)    int         priorityRtp;//呼叫rtp/srtp优先级 1 rtp优先，2 srtp优先

/*
 REGISTER sip:domain SIP/2.0
 Via: SIP/2.0/ proxy-ip:5060;branch=z9hG4bK-d8754z-c006fb3551b41d64-1---d8754z-;rport
 Max-Forwards: 70
 Contact: <sip:8998508;rinstance=04e3f53d075ddf4f>
 To: <sip:8998508@domain>
 From: <sip:8998508@domain>;tag=da911156
 Call-ID: NWViOGE3ODgwM2E2NDQwOTVmNTFiZTExM2E1M2NmN2U.
 CSeq: 1 REGISTER
 Expires: 300
 Allow: INVITE, ACK, CANCEL, OPTIONS, BYE, UPDATE, MESSAGE, NOTIFY, PRACK, INFO, REFER
 Supported: path
 User-Agent: FstUC v1.0
 Content-Length: 0
 
 Server IP参数，影响这些SIP注册相关内容：
 a、信令中的位置(蓝色字体）， VIA头域中 （可选的）
 b、客户端实际网络层报文发送的目的IP地址（UDP/TLS指向地址）
 
 Server Domain参数，影响这些SIP注册相关内容：
 a、信令中的位置（红色字体）：包括REQEST-URI参数，TO/FROM头域
 b、用于diagest鉴权（401鉴权）
 */
@property (nonatomic,retain)	NSString*	serverIP;
@property (nonatomic,retain)	NSString*	serverport;
@property (nonatomic,retain)	NSString*	countrycode;
@property (nonatomic,retain)	NSString*	useragent;
@property (nonatomic,retain)	NSString*	serverdomain;
@property (nonatomic,retain)	NSString*	outgoingacccode;

@property (nonatomic,assign)	short		entvlevel;
@property (nonatomic,assign)	short		isupdate;
@property (nonatomic,retain)	NSString*	ucnum;
@property (nonatomic,retain)	NSString*	ucpin;
@property (nonatomic,retain)	NSString*	imnum;
@property (nonatomic,retain)	NSString*	impin;

@property (nonatomic,retain)	NSString*	signature;
@property (nonatomic,retain)	NSString*	headID;
@property (nonatomic,retain)	NSString*	confAddr;

@property (nonatomic,retain)	NSString*	recordId;		//记录ID（同企业通讯录查询的id）
@property (nonatomic,retain)	NSString*	eSpaceNumber;	//espace帐号
@property (nonatomic,retain)	NSString	*staffNo;		//工号
@property (nonatomic,retain)	NSString	*phone;			//电话号码
@property (nonatomic, retain)   NSString    *voip;
@property (nonatomic, retain)   NSString    *voip2;
@property (nonatomic,retain)	NSString	*fax;			//传真号
@property (nonatomic,retain)	NSString	*email;			//email帐号
@property (nonatomic,retain)	NSString	*shortPhone;	//短号
@property (nonatomic,retain)	NSString	*officePhone;	//办公室号码
@property (nonatomic,retain)	NSString	*departmentName;//部门名称
@property (nonatomic,retain)	NSString	*deptDesc;    //部门描述
@property (nonatomic,retain)	NSString*	bindNo;			//绑定号（*+工号）
@property (nonatomic,retain)	NSString*	address;

// backup
@property (nonatomic,retain)	NSString*	backup_serverip;
@property (nonatomic,retain)	NSString*	backup_serverport;
@property (nonatomic,retain)	NSString*	backup_countrycode;//?
@property (nonatomic,retain)	NSString*	backup_useragent;//?
@property (nonatomic,retain)	NSString*	backup_serverdomain;//?
@property (nonatomic,retain)	NSString*	backup_outgoingaccode;//?

@property (nonatomic,assign)	int			msgSize;//消息大小限制
@property (nonatomic,assign)	int			picSize;//图片大小限制
@property (nonatomic,retain)	NSString*	confCode;//会议接入码

@property (nonatomic,retain)	NSString*	domain;

@property (nonatomic,retain)    NSString* nativeName; // 用户自己的本地语言名字



@property (nonatomic) short int	location;//1:内网；2:外网

@property (nonatomic, retain) NSString * maaDeployID;

@property (nonatomic, retain) NSString * audioCodec;//语音编解码顺续
@property (nonatomic, retain) NSString * audioCodecMobile;//3GLTE下的语音编解码顺序
@property (nonatomic, retain) NSString * voiceMailAccessCode;//企业语音邮箱接入号码
@property (nonatomic, retain) NSString * lastLocation;//上次用户所设定大位置信息
@property (nonatomic, assign) NSInteger callLimitType;//密码限呼类型，0不做限制；1国内长途不可，国际长途可；2国内长途可，国际长途不可；3均不可
@property (nonatomic, retain) NSString * mailBoxNum;//自己的语言邮箱号码
@property (nonatomic, retain) NSString * homepage;//个人主页
@property (nonatomic, retain) NSString * position;//职位
@property (nonatomic, retain) NSString * postalcode;//邮政编码
@property (nonatomic, assign) NSInteger ANR;//降噪参数
@property (nonatomic, assign) NSInteger audioDSCP;
@property (nonatomic, assign) NSInteger videoDSCP;
@property (nonatomic, assign) NSInteger dataDSCP;
@property (nonatomic, assign) NSInteger sipDSCP;
@property (nonatomic, assign) NSInteger maaDSCP;//maa>sip>audio>video>data

@property (nonatomic, assign) NSInteger controlCFU;//管理员控制无条件前转

@property (nonatomic, assign) NSInteger holdDuration;//HOLD切换时长
@property (nonatomic, assign) NSInteger fec;//是否支持fec冗余

@property (nonatomic, assign) NSInteger iLBCMode;//ilbc模式，单位ms，默认30

@property (nonatomic, retain) NSString * SNRNumber;
@property (nonatomic, retain) NSString * password;//语音留言密码

@property (nonatomic, retain) NSString * passwordCallAccessCode;//密码限呼逾越码
@property (nonatomic, retain) NSString * SNRAccessCode;//SNR取回功能码
@property (nonatomic, retain) NSString * enterpriseID;//用户的企业ID，用于MS地址的映射，在PAD通过sip上报终端类型时要带上此参数
@property (nonatomic, retain) NSString * emsAccount;
@property (nonatomic, retain) NSString * emsPassword;
@property (nonatomic, assign) NSInteger srtpPolicy;
@property (nonatomic, assign) BOOL tlsPolicy;
@property (nonatomic, assign) NSInteger userID;//数据会议中自己的唯一标识
@property (nonatomic, assign) NSInteger otherLoginType;//已废弃

@property (nonatomic, retain) NSString * umServerHttp;//UM服务器
@property (nonatomic, retain) NSString * umServerHttps;
@property (nonatomic, retain) NSString * umServerHttpBackup;
@property (nonatomic, retain) NSString * umServerHttpsBackup;

@property (nonatomic, retain) NSString * digitMap;//拨号规则

@property (nonatomic, retain) NSString * helpURL;//帮助URL
@property (nonatomic, assign) NSInteger  isConfUpdate;//是否更新个人通讯录的标签配置
@property (nonatomic, retain) NSString * notesMail;//Notes邮箱地址
@property (nonatomic, retain) NSString * faxList;//用户传真号码
@property (nonatomic, retain) NSString * otherInfo;//其他信息
@property (nonatomic, retain) NSString * contact;//出差联系，自定义描述信息
@property (nonatomic, retain) NSString * assistantList;//秘书
@property (nonatomic, retain) NSString * foreignName;//外国名字
@property (nonatomic, retain) NSString * room;//位置
@property (nonatomic, retain) NSString * deptDescEnglish;//部门描述英文
@property (nonatomic, retain) NSString * homePhone;//家庭电话
@property (nonatomic, retain) NSString * sp2;
@property (nonatomic, retain) NSString * m2;
@property (nonatomic, retain) NSString * spDomain;
@property (nonatomic, retain) NSString * sp2Domain;
@property (nonatomic, retain) NSString * voipDomain;
@property (nonatomic, retain) NSString * voip2Domain;
@property (nonatomic, retain) NSString * softClientExtPhone;
@property (nonatomic, retain) NSString * softClientExtPhoneDomain;
@property (nonatomic, retain) NSString * sp3;
@property (nonatomic, retain) NSString * sp3Domain;
@property (nonatomic, retain) NSString * sp4;
@property (nonatomic, retain) NSString * sp4Domain;
@property (nonatomic, retain) NSString * sp5;
@property (nonatomic, retain) NSString * sp5Domain;
@property (nonatomic, retain) NSString * sp6;
@property (nonatomic, retain) NSString * sp6Domain;
@property (nonatomic, retain) NSString * voip3;
@property (nonatomic, retain) NSString * voip4;
@property (nonatomic, retain) NSString * voip5;
@property (nonatomic, retain) NSString * voip6;
@property (nonatomic, assign) NSInteger  bindnoHideFlag;//是否隐藏软终端绑定号码,0:不隐藏；1隐藏




@property (nonatomic, retain) ECSVideoParm * frameSize;
@property (nonatomic, retain) ECSVideoParm * frameRate;
@property (nonatomic, retain) ECSVideoParm * dataRate;

@property (nonatomic, assign) NSInteger regExpires; // 注册超时,单位：秒
@property (nonatomic, assign) NSInteger sessionExpires; // 呼叫会话超时,单位：秒
@property (nonatomic, assign) NSInteger maxContact;

@property (nonatomic, assign) NSInteger opusSamplingFreq; // 建议默认16。可选值为16，24、48。 注：仅华为UC使用
@property (nonatomic, assign) NSInteger netate;//语音编解码网络模式
@property (nonatomic, retain) NSString *rejectResponse;
@property (nonatomic, retain) NSArray *confMediaXNumber;
@property (nonatomic, assign) NSInteger heartBeatTime;
@property (nonatomic, assign) NSInteger sCoreNetDeployModel;//核心网部署模式

@property (nonatomic, assign) float mosthreshold;//QoS上报的Mos阈值
@property (nonatomic, assign) NSInteger vqminterval;//QoS上报的时间间隔
@property (nonatomic, retain) NSString *SSLSouthTLSAddress;
@property (nonatomic, retain) NSString *SSLNorthTLSAddress;
@property (nonatomic, assign) BOOL callTransfer;
@property (nonatomic, retain) NSString * sipTLSPort;
@property (nonatomic, retain) NSString *DNDActive;
@property (nonatomic, retain) NSString *DNDDeactive;
@property (nonatomic, assign) NSInteger DNDConfig;
@property (nonatomic, assign) NSInteger DNDStatus;
@property (nonatomic, assign) NSInteger groupCapacity;
@property (nonatomic, assign) NSInteger groupMaxNum;
@property (nonatomic, retain) NSString *umServerPwd;//umServer鉴权码

@property (nonatomic, assign) NSInteger portraitpixelw;
@property (nonatomic, assign) NSInteger portraitpixelh;

@property (nonatomic, retain) NSString *thirdPartyAppName;
@property (nonatomic, retain) NSString *thirdPartyAppURL;
@property (nonatomic, retain) NSString *thirdPartyAppKey;
@property (nonatomic, retain) NSString *thirdPartyAppDownloadURL;

//push消息设置
@property (nonatomic, assign) BOOL pushConfig_enable;
@property (nonatomic, retain) NSString * pushConfig_noPushStart;
@property (nonatomic, retain) NSString * pushConfig_noPushEnd;
@property (nonatomic, assign) BOOL pushConfig_timeEnable;
@property (nonatomic, assign) float mosValue;

@property (nonatomic, retain) NSString *gatewaySVNAddr;
@property (nonatomic, retain) NSString *gatewaySVNPort;
@property (nonatomic, assign) BOOL isEnableAnyOfficeBrowser;

@property (nonatomic, assign) BOOL isFriendCircleFirstUsed;

@property (nonatomic, assign) NSUInteger UMVoiceRecordLength;     //Record时长，单位秒
@property (nonatomic, assign) NSUInteger UMVideoSize;             //视频大小，单位m
@property (nonatomic, assign) NSUInteger UMVideoRecordLength;     //视频录制时长，单位秒
@property (nonatomic, retain) NSString * UMVoiceCodecs;           //语音编解码，G729 or AMR-WB
@property (nonatomic, assign) NSUInteger UMMode;
@property (nonatomic, retain) NSString * umHttpList;
@property (nonatomic, retain) NSString * umHttpsList;

@property (nonatomic, assign) NSInteger JailbreakingDetect;//越狱检测 0不检测 1检测并提示 2检测并不允许登录,JAILBREAK_DETECT

@property (nonatomic, assign) BOOL confMute;//全体静音配置开关，兼容老版本，0表示不启用，1表示启用，默认为0
@property (nonatomic, retain) NSString * communityChineseName;
@property (nonatomic, retain) NSString * communityEnglishName;
@property (nonatomic, assign) BOOL imWorkWarning;
@property (nonatomic, assign) NSInteger forceCloseInfoI; //是否强制关闭info i帧请求(0,开启"强制INFO I帧"，定时请求I帧；1，关闭"强制INFO I帧"，按需请求I帧；2，禁止“INFO I帧”，任何时候都不发I帧。默认设置为-1)
@property (nonatomic, assign) NSInteger eventReportCountThreshold;
@property (nonatomic, assign) BOOL      MultiVoipRegister; //多终端登录时是否进行voip注册
@property (nonatomic, retain) NSMutableArray  *otherClientInfo;  //多终端登录时其他终端的信息，NSArray of OtherLoginClient
@property (nonatomic, assign) BOOL      backgroundVoip;  //是否支持后台来电，1为支持，0为不支持，默认为0
@property (nonatomic, assign) BOOL      disablePhoneCall;//是否禁止使用手机拨打,0不禁止，1禁止
@property (nonatomic, assign) BOOL      wrMDMFile;       //是否支持读写MDM加密文件， 0不支持 1支持
@property (nonatomic, assign) BOOL      enableEncryptData;
@property (nonatomic, assign) BOOL      hideMobileNum;

@property (nonatomic, retain) NSString *myBonusChineseName;
@property (nonatomic, retain) NSString *myBonusEnglishName;
@property (nonatomic, retain) NSString *myBonusURL;
@property (nonatomic, assign) BOOL      myBonusDisplay;
@property (nonatomic, assign) PwUpdateFlag pwExpireFlag;
@property (nonatomic, retain) NSString *cloudServerURL;
@property (nonatomic, retain) NSString *cloudToken;
@property (nonatomic, retain) NSString *cloudUploadURL;
@property (nonatomic, retain) NSString *cloudUserId;
@property (nonatomic, retain) NSString *oldstaffNo;
@property (nonatomic, assign) BOOL  toneType2833; //DTMF模式是否启用2833，如果为YES则开启 NO不开启，默认为YES
@property (nonatomic, strong) ECSDiscoveryParam *discoveryParam1;
@property (nonatomic, strong) ECSDiscoveryParam *discoveryParam2;
@property (nonatomic, strong) ECSDiscoveryParam *discoveryParam3;
@property (nonatomic, assign) BOOL tlsCertDownload;
@property (nonatomic, strong) NSMutableArray *otherAppInfo;

@property (nonatomic, strong) ECSNumberShowSupport *mobileShowSupport; //移动电话拨打支持
@property (nonatomic, strong) ECSNumberShowSupport *originOfficeShowSupport; //固定电话拨打支持
@property (nonatomic, strong) ECSNumberShowSupport *homePhoneShowSupport; //家庭电话拨打支持
@property (nonatomic, strong) ECSNumberShowSupport *officePhoneShowSupport;//其他电话拨打支持
@property (nonatomic, strong) ECSNumberShowSupport *spShowSupport;//短号拨打支持

@property (nonatomic, assign) BOOL VoipPushSwitch; //是否支持voip后台push
@property (nonatomic, assign) BOOL clientsBothOnline;//是否支持将pc踢下线和手机静音，0:不支持;1:支持
@property (nonatomic, assign) BOOL revokeMsg;//是否支持消息撤回,0:不支持;1:支持
@property (nonatomic, copy) NSString *VoipPushActiveCode; //配置开启voip push业务字冠
@property (nonatomic, copy) NSString *VoipPushDeactiveCode; //配置关闭voip push业务字冠
@property (nonatomic, retain) NSString *imWorkWarning_EN;
@property (nonatomic, retain) NSString *imWorkWarning_ZN;
@property (nonatomic, assign) BOOL bfcp; //是否打开bfcp(辅流信令)
@property (nonatomic, copy) NSString *bfcpPort;//辅流信令端口
@property (nonatomic, assign) NSInteger bfcpTransport; //辅流信令传输方式
@property (nonatomic, assign) NSInteger videoDataRate; //点对点视频编解码目标输出比特率
@property (nonatomic, assign) BOOL secEnable;    //SEC3.0抗丢包能力

@property (nonatomic, strong) NSNumber *waterMarkEnable; //水印开关
@property (nonatomic, strong) NSNumber *waterMarkDisplay;//水印显示方式
@property (nonatomic, copy) NSString *waterMarkTips_CN;//水印中文提示语
@property (nonatomic, copy) NSString *waterMarkTips_EN;//水印英文提示语


/**
 * @brief [en] This method is used to parse  user MAA info.
 *        <br>[cn] 解析用户MAA信息
 *
 * @param [in] ECSLoginAck* loginAck             <b>:</b><br>[en] Indicates login ack info.
 *                                                        <br>[cn] 服务器登录返回信息
 * @retval ECSUserMAAInfo *                      <b>:</b><br>[en] Return ECSUserMAAInfo object if success, or return nil .
 *                                                        <br>[cn] 成功返回ECSUserMAAInfo对象，失败返回nil
 * @attention [en] generate ECSUserMAAInfo object according to server returned info.
 *            <br>[cn] 根据服务器返回信息生成ECSUserMAAInfo对象
 * @see NA
 **/
+ (ECSUserMAAInfo *)parseUserMAAInfo:(ECSLoginAck *)loginAck;


/**
 * @brief [en] This method is used to judge whether support the function.
 *        <br>[cn] 判断是否支持某项功能
 *
 * @param [in] SUPPORT_FUNC_TYPE funcType        <b>:</b><br>[en] Indicates function type.
 *                                                        <br>[cn] 功能项
 * @retval BOOL                                  <b>:</b><br>[en] Return yes if true, or return no .
 *                                                        <br>[cn] 是返回YES，否返回NO
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
- (BOOL)isSupportFunction:(SUPPORT_FUNC_TYPE)funcType;
@end
