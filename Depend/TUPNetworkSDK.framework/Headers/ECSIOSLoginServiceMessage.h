#import <Foundation/Foundation.h>
#import "ECSBaseMsg.h"

@interface ECSCheckVersion : NSObject

@property (nonatomic, copy) NSString* ActionType;//CheckVersion
@property (nonatomic, copy) NSString* os;
@property (nonatomic, copy) NSString* ua;
@property (nonatomic, copy) NSString* vr;
@property (nonatomic, copy) NSString* la;
@property (nonatomic, copy) NSString* user;
@property (nonatomic, assign) NSInteger encrypt;//0
@property (nonatomic, assign) NSInteger umAbility;//0
@property (nonatomic, assign) NSInteger encrypt2;//-1
@property (nonatomic, assign) NSInteger tcpv3GroupSupport;//0
@property (nonatomic, assign) NSInteger groupAbility;//0
@property (nonatomic, assign) NSInteger umAbility2;//0
@property (nonatomic, assign) NSInteger multipleMsg;//0
@property (nonatomic, assign) NSInteger circleAbility;//0
@property (nonatomic, assign) NSInteger serviceNoAbility;//0
@property (nonatomic, assign) NSInteger unreadMsgPush;//0
@property (nonatomic, copy) NSString* deviceBrand;
@property (nonatomic, assign) NSInteger pulicNoForward;
@property (nonatomic, assign) NSInteger batchGMChange;//0
@property (nonatomic, assign) NSInteger notifyMsgRead;//0
@property (nonatomic, assign) NSInteger multiTerminalOnline;
@property (nonatomic, assign) NSInteger terminalCompatible;
@property (nonatomic, assign) NSInteger loginReplayAttack;
@property (nonatomic, assign) NSInteger microAPPOA;//0
@property (nonatomic, assign) NSInteger eSpaceGolf;//0
@property (nonatomic, assign) NSInteger businessGroup;//0

@end

@interface ECSCheckVersionAckAbilityAddr : NSObject

@property (nonatomic, assign) BOOL allowUpload;//0
@property (nonatomic, assign) BOOL allowDownload;//0
@property (nonatomic, assign) BOOL account;//0
@property (nonatomic, assign) BOOL name;//0
@property (nonatomic, assign) BOOL sex;//0
@property (nonatomic, assign) BOOL nickname;//0
@property (nonatomic, assign) BOOL deptname;//0
@property (nonatomic, assign) BOOL email;//0
@property (nonatomic, assign) BOOL fax;//0
@property (nonatomic, assign) BOOL address;//0
@property (nonatomic, assign) BOOL signature;//0
@property (nonatomic, assign) BOOL mobile;//0
@property (nonatomic, assign) BOOL office;//0
@property (nonatomic, assign) BOOL shortNumber;//0
@property (nonatomic, assign) BOOL binding;//0

@end

typedef NS_ENUM(NSInteger, ECSCheckVersionAckNetworkType)
{
	NT_UNKNOWN = -1,
	NT_NGN = 0,
	NT_IMS = 1,
	NT_UAP = 2,
	NT_IMS_ATS = 3
};

@interface ECSCheckVersionAckAbility : NSObject

@property (nonatomic, assign) BOOL isVoip;//0
@property (nonatomic, assign) BOOL isVoip_userDomain;//0
@property (nonatomic, strong) ECSCheckVersionAckAbilityAddr* addr;
@property (nonatomic, assign) BOOL isCTD;//0
@property (nonatomic, assign) BOOL isCTD_allowPhoneCall;//0
@property (nonatomic, assign) BOOL isTransPhone;//0
@property (nonatomic, assign) short isTransPhone_num;//0
@property (nonatomic, assign) BOOL isCTC;//0
@property (nonatomic, assign) BOOL isCTC_allowModifyEmcee;//0
@property (nonatomic, assign) BOOL isSMS;//0
@property (nonatomic, assign) BOOL isCallForward;//0
@property (nonatomic, assign) BOOL isManageConf;//0
@property (nonatomic, assign) BOOL isDataConf;//0
@property (nonatomic, copy) NSString* serverType;
@property (nonatomic, assign) NSInteger encrypt;//0
@property (nonatomic, assign) NSInteger sensitive;//0
@property (nonatomic, assign) NSInteger login3G;//0
@property (nonatomic, strong) NSData* key;
@property (nonatomic, assign) ECSCheckVersionAckNetworkType networkType;//2
@property (nonatomic, assign) NSInteger encrypt2;//-1
@property (nonatomic, assign) NSInteger tcpv3GroupSupport;//0
@property (nonatomic, copy) NSString* serviceName;
@property (nonatomic, assign) NSInteger tmpRlsFlag;//0
@property (nonatomic, assign) NSInteger batterySaveFlag;//0
@property (nonatomic, assign) NSInteger rootForbid;//0

@end

@interface ECSCheckVersionAck : ECSRootErrorMsg

@property (nonatomic, copy) NSString* vr;
@property (nonatomic, assign) short uflag;//0
@property (nonatomic, copy) NSString* url;
@property (nonatomic, assign) NSInteger length;//0
@property (nonatomic, assign) BOOL isSecreat;//0
@property (nonatomic, strong) ECSCheckVersionAckAbility* ability;
@property (nonatomic, copy) NSString* forwardAddress;
@property (nonatomic, assign) NSInteger otherLoginType;//-1
@property (nonatomic, assign) short newHB;//0

@end

@interface ECSKeyExchange : NSObject

@property (nonatomic, copy) NSString* ActionType;//KeyExchange
@property (nonatomic, copy) NSString* user;
@property (nonatomic, strong) NSData* key;

@end

@interface ECSKeyExchangeAck : ECSRootErrorMsg

@property (nonatomic, copy) NSString* random;
@property (nonatomic, copy) NSString* aesInitVector;

@end

@interface ECSLogin : NSObject

@property (nonatomic, copy) NSString* ActionType;//Login
@property (nonatomic, copy) NSString* user;
@property (nonatomic, copy) NSString* pwd;
@property (nonatomic, copy) NSString* timestamp;//00000000000000
@property (nonatomic, copy) NSString* deviceid;
@property (nonatomic, assign) NSInteger ct;//1
@property (nonatomic, copy) NSString* configTimestamp;
@property (nonatomic, copy) NSString* ipAddress;
@property (nonatomic, assign) NSInteger ipAddressType;//-1
@property (nonatomic, copy) NSString* timezone;
@property (nonatomic, copy) NSString* maaIpAddress;
@property (nonatomic, copy) NSString* deviceToken;
@property (nonatomic, copy) NSString* dstTimeZone;
@property (nonatomic, assign) NSInteger camera;//1
@property (nonatomic, assign) NSInteger webNetLocation;//0
@property (nonatomic, assign) short apnsserver;//1
@property (nonatomic, assign) short apnscer;//1
@property (nonatomic, assign) short stateSubscribe;//1
@property (nonatomic, assign) NSInteger pictureSize;
@property (nonatomic, copy) NSString* appID;
@property (nonatomic, copy) NSString* appURL;
@property (nonatomic, copy) NSString* random;
@property (nonatomic, copy) NSString* loginToken;
@property (nonatomic, assign) short authType;//1
@property (nonatomic, copy) NSString* voipToken;
@property (nonatomic, copy) NSString* emuiVersion;

@end

@interface ECSLoginAckBackup : NSObject

@property (nonatomic, copy) NSString* serverip;
@property (nonatomic, copy) NSString* serverport;
@property (nonatomic, copy) NSString* umServerHttp;
@property (nonatomic, copy) NSString* umServerHttps;

@end

@interface ECSLoginAckVideoCodecFrameSize : NSObject

@property (nonatomic, assign) NSInteger p2pSoft;//0
@property (nonatomic, assign) NSInteger p2pHard;//0
@property (nonatomic, assign) NSInteger confSoft;//0
@property (nonatomic, assign) NSInteger confHard;//0
@property (nonatomic, assign) NSInteger mcuSoft;//0
@property (nonatomic, assign) NSInteger mcuHard;//0

@end

@interface ECSLoginAckVideoCodecFrameRate : NSObject

@property (nonatomic, assign) NSInteger p2pSoft;//15
@property (nonatomic, assign) NSInteger p2pHard;//15
@property (nonatomic, assign) NSInteger confSoft;//15
@property (nonatomic, assign) NSInteger confHard;//15
@property (nonatomic, assign) NSInteger mcuSoft;//15
@property (nonatomic, assign) NSInteger mcuHard;//15

@end

@interface ECSLoginAckVideoCodecDataRate : NSObject

@property (nonatomic, assign) NSInteger p2pSoft;//192
@property (nonatomic, assign) NSInteger p2pHard;//192
@property (nonatomic, assign) NSInteger confSoft;//192
@property (nonatomic, assign) NSInteger confHard;//192
@property (nonatomic, assign) NSInteger mcuSoft;//192
@property (nonatomic, assign) NSInteger mcuHard;//192

@end

@interface ECSLoginAckVideoCodec : NSObject

@property (nonatomic, strong) ECSLoginAckVideoCodecFrameSize* frameSize;
@property (nonatomic, strong) ECSLoginAckVideoCodecFrameRate* frameRate;
@property (nonatomic, strong) ECSLoginAckVideoCodecDataRate* dataRate;

@end

@interface ECSLoginAckPushConfig : NSObject

@property (nonatomic, assign) BOOL enable;
@property (nonatomic, copy) NSString* noPushStart;
@property (nonatomic, copy) NSString* noPushEnd;
@property (nonatomic, assign) BOOL timeEnable;

@end

@interface ECSLoginAckLoginDevice : NSObject

@property (nonatomic, copy) NSString* deviceType;
@property (nonatomic, assign) long long loginTime;

@end

@interface ECSLoginAckAppInfo : NSObject

@property (nonatomic, copy) NSString* appID;
@property (nonatomic, copy) NSString* appName;
@property (nonatomic, copy) NSString* appLogo;

@end

@interface ECSLoginAck : ECSRootErrorMsg

@property (nonatomic, copy) NSString* name;
@property (nonatomic, copy) NSString* mobile;
@property (nonatomic, copy) NSString* callno;
@property (nonatomic, copy) NSString* sex;
@property (nonatomic, copy) NSString* headaddress;
@property (nonatomic, copy) NSString* mailaddress;
@property (nonatomic, copy) NSString* funcid;
@property (nonatomic, copy) NSString* imuserver;
@property (nonatomic, copy) NSString* imuport;
@property (nonatomic, assign) short maxconfnum;//0
@property (nonatomic, assign) short maxsmsnum;//0
@property (nonatomic, copy) NSString* voipunm;
@property (nonatomic, copy) NSString* voippin;
@property (nonatomic, copy) NSString* serverip;
@property (nonatomic, copy) NSString* serverport;
@property (nonatomic, copy) NSString* countrycode;
@property (nonatomic, copy) NSString* useragent;
@property (nonatomic, copy) NSString* serverdomain;
@property (nonatomic, copy) NSString* outgoingacccode;
@property (nonatomic, assign) short entvlevel;//0
@property (nonatomic, assign) short isupdate;//0
@property (nonatomic, copy) NSString* ucnum;
@property (nonatomic, copy) NSString* ucpin;
@property (nonatomic, copy) NSString* imnum;
@property (nonatomic, copy) NSString* impin;
@property (nonatomic, copy) NSString* signature;
@property (nonatomic, copy) NSString* headid;
@property (nonatomic, copy) NSString* confaddr;
@property (nonatomic, copy) NSString* id;
@property (nonatomic, copy) NSString* eSpaceNumber;
@property (nonatomic, copy) NSString* staffNo;
@property (nonatomic, copy) NSString* phone;
@property (nonatomic, copy) NSString* voip;
@property (nonatomic, copy) NSString* voip2;
@property (nonatomic, copy) NSString* fax;
@property (nonatomic, copy) NSString* email;
@property (nonatomic, copy) NSString* shortPhone;
@property (nonatomic, copy) NSString* officePhone;
@property (nonatomic, copy) NSString* bindNo;
@property (nonatomic, copy) NSString* deptName;
@property (nonatomic, copy) NSString* deptDesc;
@property (nonatomic, copy) NSString* address;
@property (nonatomic, strong) ECSLoginAckBackup* backup;
@property (nonatomic, assign) NSInteger msgSize;//0
@property (nonatomic, assign) NSInteger picSize;//0
@property (nonatomic, copy) NSString* confCode;
@property (nonatomic, copy) NSString* nativeName;
@property (nonatomic, assign) short location;//0
@property (nonatomic, copy) NSString* maaDeployID;
@property (nonatomic, copy) NSString* audioCodec;
@property (nonatomic, copy) NSString* voiceMailAccessCode;
@property (nonatomic, copy) NSString* lastLocation;
@property (nonatomic, assign) short callLimitType;//-1
@property (nonatomic, copy) NSString* mailBoxNum;
@property (nonatomic, copy) NSString* homepage;
@property (nonatomic, copy) NSString* position;
@property (nonatomic, copy) NSString* postalcode;
@property (nonatomic, assign) NSInteger ANR;//0
@property (nonatomic, assign) NSInteger audioDSCP;//0
@property (nonatomic, assign) NSInteger videoDSCP;//0
@property (nonatomic, assign) NSInteger dataDSCP;//0
@property (nonatomic, assign) NSInteger sipDSCP;//0
@property (nonatomic, assign) NSInteger maaDSCP;//0
@property (nonatomic, assign) NSInteger controlCFU;//0
@property (nonatomic, assign) NSInteger holdDuration;//0
@property (nonatomic, assign) NSInteger iLBCMode;//30
@property (nonatomic, copy) NSString* SNRNumber;
@property (nonatomic, copy) NSString* password;
@property (nonatomic, copy) NSString* passwordCallAccessCode;
@property (nonatomic, copy) NSString* SNRAccessCode;
@property (nonatomic, copy) NSString* enterpriseID;
@property (nonatomic, copy) NSString* emsAddress1;
@property (nonatomic, copy) NSString* emsAddress2;
@property (nonatomic, copy) NSString* emsAccount;
@property (nonatomic, copy) NSString* emsPassword;
@property (nonatomic, assign) short srtpPolicy;//0
@property (nonatomic, assign) short tlsPolicy;//0
@property (nonatomic, assign) NSInteger userID;//0
@property (nonatomic, assign) NSInteger otherLoginType;//-1
@property (nonatomic, copy) NSString* umServerHttp;
@property (nonatomic, copy) NSString* umServerHttps;
@property (nonatomic, copy) NSString* digitMap;
@property (nonatomic, copy) NSString* help;
@property (nonatomic, assign) short isConfUpdate;//0
@property (nonatomic, copy) NSString* notesMail;
@property (nonatomic, copy) NSString* faxList;
@property (nonatomic, copy) NSString* otherInfo;
@property (nonatomic, copy) NSString* contact;
@property (nonatomic, copy) NSString* assistantList;
@property (nonatomic, copy) NSString* displayName;
@property (nonatomic, copy) NSString* foreignName;
@property (nonatomic, copy) NSString* voipList;
@property (nonatomic, copy) NSString* room;
@property (nonatomic, copy) NSString* interPhoneList;
@property (nonatomic, copy) NSString* deptDescEnglish;
@property (nonatomic, copy) NSString* mobileList;
@property (nonatomic, copy) NSString* phoneList;
@property (nonatomic, copy) NSString* homePhone;
@property (nonatomic, strong) ECSLoginAckVideoCodec* videoCodec;
@property (nonatomic, assign) NSInteger regExpires;//0
@property (nonatomic, assign) NSInteger sessionExpires;//0
@property (nonatomic, assign) NSInteger maxContact;//0
@property (nonatomic, assign) NSInteger opusSamplingFreq;//16000
@property (nonatomic, assign) NSInteger netate;//2
@property (nonatomic, copy) NSString* rejectResponse;
@property (nonatomic, copy) NSString* sp2;
@property (nonatomic, copy) NSString* m2;
@property (nonatomic, copy) NSString* spDomain;
@property (nonatomic, copy) NSString* sp2Domain;
@property (nonatomic, copy) NSString* voipDomain;
@property (nonatomic, copy) NSString* voip2Domain;
@property (nonatomic, copy) NSString* softClientExtPhone;
@property (nonatomic, copy) NSString* softClientExtPhoneDomain;
@property (nonatomic, copy) NSString* confMediaXNumber;
@property (nonatomic, assign) NSInteger heartBeatTime;//0
@property (nonatomic, copy) NSString* audioCodecMobile;
@property (nonatomic, copy) NSString* sp3;
@property (nonatomic, copy) NSString* sp3Domain;
@property (nonatomic, copy) NSString* sp4;
@property (nonatomic, copy) NSString* sp4Domain;
@property (nonatomic, copy) NSString* sp5;
@property (nonatomic, copy) NSString* sp5Domain;
@property (nonatomic, copy) NSString* sp6;
@property (nonatomic, copy) NSString* sp6Domain;
@property (nonatomic, copy) NSString* voip3;
@property (nonatomic, copy) NSString* voip4;
@property (nonatomic, copy) NSString* voip5;
@property (nonatomic, copy) NSString* voip6;
@property (nonatomic, assign) NSInteger sCoreNetDeployModel;//-1
@property (nonatomic, assign) float mosthreshold;//3.6f
@property (nonatomic, assign) NSInteger vqminterval;//5
@property (nonatomic, assign) NSInteger bindnoHideFlag;//0
@property (nonatomic, copy) NSString* SSLSouthTLSAddress;
@property (nonatomic, copy) NSString* SSLNorthTLSAddress;
@property (nonatomic, assign) NSInteger groupCapacity;//0
@property (nonatomic, copy) NSString* umServerPwd;
@property (nonatomic, assign) NSInteger groupMaxNum;//0
@property (nonatomic, copy) NSString* posterId;
@property (nonatomic, strong) NSDictionary* componentParams;
@property (nonatomic, assign) NSInteger posterTimestamp;//0
@property (nonatomic, assign) NSInteger posterBeginTime;//0
@property (nonatomic, assign) NSInteger posterEndTime;//0
@property (nonatomic, copy) NSString* DNDActive;
@property (nonatomic, copy) NSString* DNDDeactive;
@property (nonatomic, assign) NSInteger DNDConfig;//0
@property (nonatomic, assign) NSInteger DNDStatus;//0
@property (nonatomic, strong) ECSLoginAckPushConfig* pushConfig;
@property (nonatomic, assign) float mosValue;
@property (nonatomic, assign) NSInteger isFriendCircleFirstUsed;//0
@property (nonatomic, copy) NSString* umHttpList;
@property (nonatomic, copy) NSString* umHttpsList;
@property (nonatomic, strong) NSArray* deviceList;//ECSLoginAckLoginDevice array
@property (nonatomic, copy) NSString* oldstaffNo;
@property (nonatomic, assign) short pwdExpireFlag;//0
@property (nonatomic, strong) NSArray* appList;//ECSLoginAckAppInfo array

@end

@interface ECSHeartbeatQuery : NSObject

@property (nonatomic, copy) NSString* xmlns;//jabber:iq:heartbeat

@end

@interface ECSHeartbeat : NSObject

@property (nonatomic, copy) NSString* type;//get
@property (nonatomic, copy) NSString* from;
@property (nonatomic, assign) short first;//0
@property (nonatomic, strong) ECSHeartbeatQuery* query;

@end

@interface ECSHeartbeatAck : ECSIqErrorMsg


@end

@interface ECSGetPoster : NSObject

@property (nonatomic, copy) NSString* ActionType;//GetPoster
@property (nonatomic, copy) NSString* user;
@property (nonatomic, copy) NSString* posterId;

@end

@interface ECSGetPosterAck : ECSRootErrorMsg

@property (nonatomic, strong) NSData* data;

@end

@interface ECSLogoutQuery : NSObject

@property (nonatomic, copy) NSString* xmlns;//jabber:iq:register
@property (nonatomic, copy) NSString* remove_sessionid;
@property (nonatomic, assign) NSInteger removemode;//0

@end

@interface ECSLogout : NSObject

@property (nonatomic, copy) NSString* type;//set
@property (nonatomic, copy) NSString* from;
@property (nonatomic, strong) ECSLogoutQuery* query;

@end

@interface ECSLogoutAck : ECSIqErrorMsg

@end
