/**
 * @file ECSServerAbility.h
 *
 * Copyright (c) 2015 Huawei Tech. Co., Ltd. All rights reserved. \n
 *
 * @brief [en]Description:server info basic service function class head file.
 * [cn]描述：服务器信息基础业务功能类头文件。 \n
 **/

#import <Foundation/Foundation.h>

/** <!-- CheckVersionAck Sample Message -->
 <root>
 <return>-9999</return>
 <desc></desc>
 <vr></vr>
 <uflag>0</uflag>
 <url></url>
 <length>0</length>
 <isSecreat>0</isSecreat>
 <ability>
 <isVoip userDomain="0">0</isVoip>
 <addr allowUpload="0"
 allowDownload="0">
 <account>0</account>
 <name>0</name>
 <sex>0</sex>
 <nickname>0</nickname>
 <deptname>0</deptname>
 <email>0</email>
 <fax>0</fax>
 <address>0</address>
 <signature>0</signature>
 <mobile>0</mobile>
 <office>0</office>
 <short>0</short>
 <binding>0</binding>
 </addr>
 <isCTD allowPhoneCall="0">0</isCTD>
 <isTransPhone num="0">0</isTransPhone>
 <isCTC allowModifyEmcee="0">0</isCTC>
 <isSMS>0</isSMS>
 <isCallForward>0</isCallForward>
 <isManageConf>0</isManageConf>
 <isDataConf>0</isDataConf>
 <serverType></serverType>
 <encrypt>0</encrypt>
 <sensitive>0</sensitive>
 <login3G>0</login3G>
 </ability>
 <forwardAddress></forwardAddress>
 </root>
 */

/**
 * [en]This enum is about server type, return by checkversion ack.
 * [cn]服务器类型，checkversion ack中返回
 */
typedef enum tsgServerType
{
    SERVERTYPE_UC_UNKNOWN,
    SERVERTYPE_UC_V1,               /**< [en]Indicates UC1.0.
                                     <br>[cn]UC1.0 */
    SERVERTYPE_UC_HW,               /**< [en]Indicates HUAWEI UC .
                                     <br>[cn]HUAWEI UC */
    SERVERTYPE_UC_V2,               /**< [en]Indicates UC2.0.
                                     <br>[cn]UC2.0 */
    SERVERTYPE_UC_IPT,              /**< [en]Indicates IPT.
                                     <br>[cn]IPT */
    
    SERVERTYPE_UC_BUTT
}SERVERTYPE;

#define UC_UNKNOWN
#define UCV1		(@"UC1.0")
#define UCHW		(@"HUAWEIUC")
#define UCV2		(@"UC2.0")
#define UCIPT       (@"IPT")
#define ESPACE_DEFAULT_DOWNLOAD_URL       @"https://itunes.apple.com/us/app/espace-2.0/id579264720?mt=8" //当升级url为空时 使用商店的下载地址

/**
 * [en] This class is about server function.
 * [cn] 服务器功能类
 **/
@interface ECSServerAbility : NSObject

@property (nonatomic)       int			isSecret; //1 ecs 版本都是加密 0 C07 版本不是加密
@property (nonatomic,copy)	NSString	*version; //手机客户端版本号
@property (nonatomic)       short int	uflag; //0 不升级 1 强制升级 2 可选升级
@property (nonatomic,copy)	NSString	*url; //升级包下载地址
@property (nonatomic)       int			length; //升级包长度

@property (nonatomic,copy)	NSString   	*desc; //升级包描述信息
@property (nonatomic)       BOOL		isVoip; //服务器不支持softCo，不需要注册softCo；1 服务器支持softCo，
@property (nonatomic)       BOOL		userDomain; //0 注册softCo时不带UserDomain；1 注册softCo时带UserDomain(默认或无此节点)
@property (nonatomic)       BOOL		allowUpload; //是否允许本地通讯录同步到个人通讯录: 0 不支持; 1 支持;
@property (nonatomic)       BOOL		allowDownload; //是否允许个人通讯录同步到本地通讯录: 0 不支持; 1 支持;

@property (nonatomic)       BOOL		account; //是否显示eSpace帐号: 0 不支持; 1 支持;
@property (nonatomic)       BOOL		name; //是否显示用户姓名: 0 不支持; 1 支持;
@property (nonatomic)       BOOL		sex; //是否显示性别: 0 不支持; 1 支持;
@property (nonatomic)       BOOL		nickName; //是否显示昵称: 0 不支持; 1 支持;
@property (nonatomic)       BOOL		deptName; //是否显示部门名: 0 不支持; 1 支持;

@property (nonatomic)       BOOL		email;
@property (nonatomic)       BOOL		fax;
@property (nonatomic)       BOOL		address;
@property (nonatomic)       BOOL		signature;
@property (nonatomic)       BOOL		mobile;

@property (nonatomic)       BOOL			office;
@property (nonatomic)       BOOL			shortNum;
@property (nonatomic)       BOOL			bindNum;
@property (nonatomic)       BOOL			isCTD; //是否支持ctd: 0 不支持; 1 支持;
@property (nonatomic)       BOOL			allowPhoneCall; //是否允许本地phone呼叫,实现ctd: 0 不支持; 1 支持;

@property (nonatomic)       BOOL			isTransPhone; //是否支持来电转接设置能力: 0 不支持; 1 支持;
@property (nonatomic)       int				transPhoneCount;//允许设置来电转接号码的个数
@property (nonatomic)       BOOL			isCTC; //是否支持ctc能力: 0 不支持; 1 支持;
@property (nonatomic)       BOOL			alloModifyEmcee;
@property (nonatomic)       BOOL			isSMS;

@property (nonatomic)       BOOL			isCallForward;
@property (nonatomic)       BOOL			isManageConf;
@property (nonatomic)       BOOL			isDataConf;
@property (nonatomic)       int				encrypt; //服务器支持的加密能力版本 1-aes加密
@property (nonatomic)       NSInteger             serverType; 	//系统服务器类型,支持 “HuaweiUC” “UC1.0” “UC2.0”

@property (nonatomic)       BOOL			isSensitiveWords;//UC2现支持敏感词，置1，老的MAA不支持，不返回或为置为0，表示服务器无此能力。服务器是否支持返回敏感词能力，如果不支持，客户端就不需要在登录之后下载敏感词。
@property (nonatomic)       BOOL			login3G;// 0 不允许3G登录， 1 允许3G登录
@property (nonatomic)       BOOL            tmpRlsFlag;//状态订阅
@property (nonatomic)       BOOL            batterySaveFlag;//省电模式
@property (nonatomic)       BOOL            rootForbid;//
@property (nonatomic)       NSInteger		networkType;//组网模式 0,代表NGN组网 1,代表IMS组网 2,代表UAP组网 缺省为2 UAP组网。
@property (nonatomic, strong) NSData * rsaPublicKey;
@property (nonatomic)       NSInteger encrypt2;
@property (nonatomic, copy) NSString * serviceName; // “LPOE ” – 代表产权局定制。定制特性：1、允许PAD登录UC1；2、关闭PAD临时群功能。
@property (nonatomic)       NSInteger otherLoginType;//其他客户端登录类型

@end
