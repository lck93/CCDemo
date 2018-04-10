#import <Foundation/Foundation.h>
#import "ECSBaseMsg.h"

@interface ECSFullSync : NSObject

@property (nonatomic, copy) NSString* ActionType;//GetAllUser
@property (nonatomic, copy) NSString* user;
@property (nonatomic, copy) NSString* fields;

@end

@interface ECSFullSyncAckGroup : NSObject

@property (nonatomic, copy) NSString* id;
@property (nonatomic, copy) NSString* name;
@property (nonatomic, assign) short num;//0
@property (nonatomic, assign) NSInteger idx;//0

@end

@interface ECSFullSyncAckUser : NSObject

@property (nonatomic, copy) NSString* id;
@property (nonatomic, copy) NSString* domain;
@property (nonatomic, copy) NSString* name;
@property (nonatomic, copy) NSString* account;
@property (nonatomic, copy) NSString* sex;
@property (nonatomic, copy) NSString* phone;
@property (nonatomic, copy) NSString* mobile;
@property (nonatomic, copy) NSString* shortnumber;
@property (nonatomic, copy) NSString* officephone;
@property (nonatomic, copy) NSString* bindnumber;
@property (nonatomic, copy) NSString* fax;
@property (nonatomic, copy) NSString* email;
@property (nonatomic, copy) NSString* groupid;
@property (nonatomic, copy) NSString* deptname;
@property (nonatomic, copy) NSString* nickname;
@property (nonatomic, copy) NSString* signature;
@property (nonatomic, copy) NSString* address;
@property (nonatomic, assign) BOOL isFriend;//0
@property (nonatomic, copy) NSString* nativeName;
@property (nonatomic, copy) NSString* originMobile;
@property (nonatomic, copy) NSString* originOffice;
@property (nonatomic, copy) NSString* headid;
@property (nonatomic, copy) NSString* voip;
@property (nonatomic, copy) NSString* homepage;
@property (nonatomic, copy) NSString* position;
@property (nonatomic, copy) NSString* postalcode;
@property (nonatomic, copy) NSString* voip2;
@property (nonatomic, copy) NSString* deptDesc;
@property (nonatomic, copy) NSString* staffNo;
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
@property (nonatomic, copy) NSString* timezone;
@property (nonatomic, copy) NSString* simplifiedPinyin;
@property (nonatomic, copy) NSString* mobileList;
@property (nonatomic, copy) NSString* phoneList;
@property (nonatomic, copy) NSString* timezoneValue;
@property (nonatomic, copy) NSString* homePhone;
@property (nonatomic, copy) NSString* softClientExtPhone;
@property (nonatomic, copy) NSString* softClientExtPhoneDomain;
@property (nonatomic, copy) NSString* sp2;
@property (nonatomic, copy) NSString* m2;
@property (nonatomic, copy) NSString* spDomain;
@property (nonatomic, copy) NSString* sp2Domain;
@property (nonatomic, copy) NSString* voipDomain;
@property (nonatomic, copy) NSString* voip2Domain;
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
@property (nonatomic, copy) NSString* pinyinName;
@property (nonatomic, assign) NSInteger bdHideFlag;//0
@property (nonatomic, assign) NSInteger circleRelation;//0
@property (nonatomic, assign) NSInteger sendCircleMsg;//0
@property (nonatomic, assign) NSInteger recvCircleMsg;//0

@end

@interface ECSFullSyncAckTeam : NSObject

@property (nonatomic, copy) NSString* id;
@property (nonatomic, copy) NSString* name;
@property (nonatomic, assign) NSInteger recvmsg;//0
@property (nonatomic, copy) NSString* announce;
@property (nonatomic, copy) NSString* intro;
@property (nonatomic, copy) NSString* owner;
@property (nonatomic, assign) short joinFlag;//0
@property (nonatomic, assign) NSInteger groupType;//0
@property (nonatomic, assign) BOOL fixed;//0
@property (nonatomic, assign) NSInteger capacity;//0
@property (nonatomic, copy) NSString *appName;
@property (nonatomic, copy) NSString *appID;
@property (nonatomic, assign) NSInteger servicePolicy;
@property (nonatomic, copy) NSString* enName;
@property (nonatomic, copy) NSString* groupSpaceInfo;
@end

@interface ECSFullSyncAck : ECSRootErrorMsg

@property (nonatomic, assign) BOOL simplifyMode;//0
@property (nonatomic, copy) NSString* timestamp;
@property (nonatomic, strong) NSArray* groups;//ECSFullSyncAckGroup array
@property (nonatomic, strong) NSArray* users;//ECSFullSyncAckUser array
@property (nonatomic, strong) NSArray* grplist;//ECSFullSyncAckTeam array
@property (nonatomic, assign) short total;//0

@end

@interface ECSPartialSync : NSObject

@property (nonatomic, copy) NSString* ActionType;//GetPartialUser
@property (nonatomic, copy) NSString* user;
@property (nonatomic, copy) NSString* timestamp;
@property (nonatomic, copy) NSString* fields;

@end

typedef NS_ENUM(NSInteger, ECSPartialSyncAckOption)
{
	OPT_UNKNOWN = -1,
	OPT_INSERT = 0,
	OPT_DELETE = 1,
	OPT_UPDATE = 2
};

@interface ECSPartialSyncAckUser : ECSFullSyncAckUser

@property (nonatomic, assign) ECSPartialSyncAckOption opt;//-1

@end

@interface ECSPartialSyncAckTeam : ECSFullSyncAckTeam

@property (nonatomic, assign) ECSPartialSyncAckOption opt;//-1

@end


@interface ECSPartialSyncAckGroup : NSObject

@property (nonatomic, copy) NSString* id;
@property (nonatomic, copy) NSString* name;
@property (nonatomic, assign) NSInteger idx;//0
@property (nonatomic, assign) ECSPartialSyncAckOption opt;//-1

@end

@interface ECSPartialSyncAckRelation : NSObject

@property (nonatomic, copy) NSString* tid;
@property (nonatomic, copy) NSString* mid;
@property (nonatomic, assign) ECSPartialSyncAckOption opt;//-1

@end

@interface ECSPartialSyncAck : ECSRootErrorMsg

@property (nonatomic, assign) BOOL simplifyMode;//0
@property (nonatomic, copy) NSString* timestamp;
@property (nonatomic, strong) NSArray* users;//ECSPartialSyncAckUser array
@property (nonatomic, strong) NSArray* grplist;//ECSPartialSyncAckTeam array
@property (nonatomic, strong) NSArray* groups;//ECSPartialSyncAckGroup array
@property (nonatomic, strong) NSArray* relations;//ECSPartialSyncAckRelation array
@property (nonatomic, assign) short total;//0

@end

@interface ECSQueryMobile : NSObject

@property (nonatomic, copy) NSString* ActionType;//QueryMobile
@property (nonatomic, copy) NSString* user;
@property (nonatomic, strong) NSArray* list;//NSString array

@end

@interface ECSQueryMobileAckRecord : NSObject

@property (nonatomic, copy) NSString* num;
@property (nonatomic, copy) NSString* account;

@end

@interface ECSQueryMobileAck : ECSRootErrorMsg

@property (nonatomic, strong) NSArray* list;//ECSQueryMobileAckRecord array

@end

@interface ECSAddContactGroup : NSObject

@property (nonatomic, copy) NSString* ActionType;//AddContactGroup
@property (nonatomic, copy) NSString* user;
@property (nonatomic, copy) NSString* groupID;
@property (nonatomic, copy) NSString* groupName;

@end

@interface ECSAddContactGroupAck : ECSRootErrorMsg


@end

@interface ECSDelContactGroup : NSObject

@property (nonatomic, copy) NSString* ActionType;//DelContactGroup
@property (nonatomic, copy) NSString* user;
@property (nonatomic, copy) NSString* groupID;

@end

@interface ECSDelContactGroupAck : ECSRootErrorMsg


@end

@interface ECSAddFriendQueryItem : NSObject

@property (nonatomic, copy) NSString* jid;
@property (nonatomic, copy) NSString* nickname;
@property (nonatomic, copy) NSString* subscription;//add
@property (nonatomic, assign) NSInteger idx;//-1
@property (nonatomic, copy) NSString* group;

@end

@interface ECSAddFriendQuery : NSObject

@property (nonatomic, copy) NSString* xmlns;//jabber:iq:roster
@property (nonatomic, strong) ECSAddFriendQueryItem* item;

@end

@interface ECSAddFriend : NSObject

@property (nonatomic, copy) NSString* type;//set
@property (nonatomic, copy) NSString* from;
@property (nonatomic, strong) ECSAddFriendQuery* query;
@property (nonatomic, assign) BOOL notify;

@end

@interface ECSAddFriendAck : ECSIqErrorMsg


@end

@interface ECSDelFriendQueryItem : NSObject

@property (nonatomic, copy) NSString* jid;
@property (nonatomic, copy) NSString* subscription;//remove
@property (nonatomic, copy) NSString* id;
@property (nonatomic, copy) NSString* tid;

@end

@interface ECSDelFriendQuery : NSObject

@property (nonatomic, copy) NSString* xmlns;//jabber:iq:roster
@property (nonatomic, strong) ECSDelFriendQueryItem* item;

@end

@interface ECSDelFriend : NSObject

@property (nonatomic, copy) NSString* type;//set
@property (nonatomic, copy) NSString* from;
@property (nonatomic, strong) ECSDelFriendQuery* query;

@end

@interface ECSDelFriendAck : ECSIqErrorMsg


@end

@interface ECSViewFriendHeadImageQueryItem : NSObject

@property (nonatomic, copy) NSString* width;
@property (nonatomic, copy) NSString* height;
@property (nonatomic, copy) NSString* headid;
@property (nonatomic, copy) NSString* jid;

@end

@interface ECSViewFriendHeadImageQuery : NSObject

@property (nonatomic, copy) NSString* xmlns;//jabber:iq:headpic
@property (nonatomic, strong) NSArray* items;//ECSViewFriendHeadImageQueryItem array

@end

@interface ECSViewFriendHeadImage : NSObject

@property (nonatomic, copy) NSString* type;//get
@property (nonatomic, copy) NSString* from;
@property (nonatomic, strong) ECSViewFriendHeadImageQuery* query;

@end

@interface ECSViewFriendHeadImageAckHeadPicture : NSObject

@property (nonatomic, copy) NSString* from;
@property (nonatomic, copy) NSString* picture;

@end

@interface ECSViewFriendHeadImageAck : ECSIqErrorMsg

@property (nonatomic, copy) NSString* to;
@property (nonatomic, strong) NSArray* headpictures;//ECSViewFriendHeadImageAckHeadPicture array

@end

@interface ECSInviteFriend : NSObject

@property (nonatomic, copy) NSString* from;
@property (nonatomic, copy) NSString* to;
@property (nonatomic, copy) NSString* type;//subscribe
@property (nonatomic, copy) NSString* nickname;

@end

@interface ECSInviteFriendAck : ECSPresenceErrorMsg


@end

@interface ECSAddNonFriendMemberQueryItem : NSObject

@property (nonatomic, copy) NSString* jid;
@property (nonatomic, copy) NSString* subscription;//add

@end

@interface ECSAddNonFriendMemberQuery : NSObject

@property (nonatomic, copy) NSString* xmlns;//jabber:iq:presence
@property (nonatomic, strong) NSArray* list;//ECSAddNonFriendMemberQueryItem array

@end

@interface ECSAddNonFriendMember : NSObject

@property (nonatomic, copy) NSString* type;//get
@property (nonatomic, copy) NSString* from;
@property (nonatomic, strong) ECSAddNonFriendMemberQuery* query;

@end

@interface ECSAddNonFriendMemberAck : ECSIqErrorMsg


@end

@interface ECSQueryCorpContacts : NSObject

@property (nonatomic, copy) NSString* ActionType;//GetEPersonList
@property (nonatomic, copy) NSString* user;
@property (nonatomic, copy) NSString* department;
@property (nonatomic, copy) NSString* condition;
@property (nonatomic, assign) NSInteger pagecount;//0
@property (nonatomic, assign) NSInteger pagenum;//0
@property (nonatomic, copy) NSString* fields;
@property (nonatomic, copy) NSString* show;
@property (nonatomic, assign) BOOL queryCustom;//0
@property (nonatomic, copy) NSString* queryField;
@property (nonatomic, assign) NSInteger searchFlag;//0

@end

@interface ECSQueryCorpContactsAckEntAddrRecord : NSObject

@property (nonatomic, copy) NSString* id;
@property (nonatomic, copy) NSString* domain;
@property (nonatomic, copy) NSString* name;
@property (nonatomic, copy) NSString* eSpaceNumber;
@property (nonatomic, copy) NSString* staffNo;
@property (nonatomic, copy) NSString* sex;
@property (nonatomic, copy) NSString* phone;
@property (nonatomic, copy) NSString* voip;
@property (nonatomic, copy) NSString* voip2;
@property (nonatomic, copy) NSString* nativeName;
@property (nonatomic, copy) NSString* mobile;
@property (nonatomic, copy) NSString* fax;
@property (nonatomic, copy) NSString* email;
@property (nonatomic, copy) NSString* shortphone;
@property (nonatomic, copy) NSString* officephone;
@property (nonatomic, copy) NSString* bindno;
@property (nonatomic, copy) NSString* deptname;
@property (nonatomic, copy) NSString* deptDesc;
@property (nonatomic, copy) NSString* signature;
@property (nonatomic, copy) NSString* address;
@property (nonatomic, copy) NSString* originMobile;
@property (nonatomic, copy) NSString* originOffice;
@property (nonatomic, copy) NSString* headid;
@property (nonatomic, copy) NSString* homepage;
@property (nonatomic, copy) NSString* position;
@property (nonatomic, copy) NSString* postalcode;
@property (nonatomic, copy) NSString* notesMail;
@property (nonatomic, copy) NSString* faxList;
@property (nonatomic, copy) NSString* otherInfo;
@property (nonatomic, copy) NSString* contact;
@property (nonatomic, copy) NSString* assistantList;
@property (nonatomic, copy) NSString* displayName;
@property (nonatomic, copy) NSString* foreignName;
@property (nonatomic, copy) NSString* voipList;
@property (nonatomic, copy) NSString* softClientExtPhone;
@property (nonatomic, copy) NSString* softClientExtPhoneDomain;
@property (nonatomic, copy) NSString* sp2;
@property (nonatomic, copy) NSString* m2;
@property (nonatomic, copy) NSString* spDomain;
@property (nonatomic, copy) NSString* sp2Domain;
@property (nonatomic, copy) NSString* voipDomain;
@property (nonatomic, copy) NSString* voip2Domain;
@property (nonatomic, copy) NSString* room;
@property (nonatomic, copy) NSString* interPhoneList;
@property (nonatomic, copy) NSString* deptDescEnglish;
@property (nonatomic, copy) NSString* timezone;
@property (nonatomic, copy) NSString* simplifiedPinyin;
@property (nonatomic, copy) NSString* mobileList;
@property (nonatomic, copy) NSString* phoneList;
@property (nonatomic, copy) NSString* timezoneValue;
@property (nonatomic, copy) NSString* homePhone;
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
@property (nonatomic, copy) NSString* pinyinName;
@property (nonatomic, assign) NSInteger bindnoHideFlag;//0

@end

typedef ECSQueryCorpContactsAckEntAddrRecord ECSCorpUserContact;

@interface ECSQueryCorpContactsAckDeptRecord : NSObject

@property (nonatomic, copy) NSString* id;
@property (nonatomic, copy) NSString* deptName;
@property (nonatomic, copy) NSString* parentDept;
@property (nonatomic, assign) NSInteger count;//0
@property (nonatomic, assign) NSInteger children;//0

@end

@interface ECSQueryCorpContactsAck : ECSRootErrorMsg

@property (nonatomic, assign) NSInteger total;//0
@property (nonatomic, strong) NSArray* entAddrRecord;//ECSQueryCorpContactsAckEntAddrRecord array
@property (nonatomic, strong) NSArray* deptRecord;//ECSQueryCorpContactsAckDeptRecord array

@end

@interface ECSGetDepartList : NSObject

@property (nonatomic, copy) NSString* ActionType;//GetDepartList
@property (nonatomic, copy) NSString* user;
@property (nonatomic, assign) NSInteger parentId;//-1
@property (nonatomic, assign) NSInteger pagecount;//0
@property (nonatomic, assign) NSInteger pagenum;//0

@end

@interface ECSGetDepartListAckDeptRecord : NSObject

@property (nonatomic, assign) NSInteger id;//0
@property (nonatomic, copy) NSString* deptName;
@property (nonatomic, assign) NSInteger parentDept;//0
@property (nonatomic, assign) NSInteger count;//0
@property (nonatomic, assign) NSInteger children;//0

@end

@interface ECSGetDepartListAck : ECSRootErrorMsg

@property (nonatomic, assign) NSInteger total;//0
@property (nonatomic, strong) NSArray* deptRecord;//ECSGetDepartListAckDeptRecord array

@end

typedef NS_ENUM(NSInteger, ECSFriendStateChangedNotifyExchangeStatus)
{
	XS_UNKNOWN = -1,
	XS_AVAILABLE = 1,
	XS_BUSY = 2,
	XS_AWAY = 3,
	XS_OFFLINE = 4
};

@interface ECSFriendStateChangedNotify : NSObject

@property (nonatomic, copy) NSString* from;
@property (nonatomic, copy) NSString* to;
@property (nonatomic, copy) NSString* type;
@property (nonatomic, copy) NSString* show;
@property (nonatomic, copy) NSString* status;
@property (nonatomic, assign) NSInteger ct;//-1
@property (nonatomic, copy) NSString* cd;
@property (nonatomic, assign) ECSFriendStateChangedNotifyExchangeStatus exchange;//-1
@property (nonatomic, copy) NSString* softClient;
@property (nonatomic, copy) NSString* softClient_funcid;
@property (nonatomic, assign) NSInteger softClient_camera;//0
@property (nonatomic, copy) NSString* IPPhone1;
@property (nonatomic, copy) NSString* IPPhone1_funcid;
@property (nonatomic, assign) NSInteger IPPhone1_camera;//0
@property (nonatomic, copy) NSString* number1;
@property (nonatomic, copy) NSString* IPPhone2;
@property (nonatomic, copy) NSString* IPPhone2_funcid;
@property (nonatomic, assign) NSInteger IPPhone2_camera;//0
@property (nonatomic, copy) NSString* number2;
@property (nonatomic, copy) NSString* IPPhone3;
@property (nonatomic, copy) NSString* IPPhone3_funcid;
@property (nonatomic, assign) NSInteger IPPhone3_camera;//0
@property (nonatomic, copy) NSString* number3;
@property (nonatomic, copy) NSString* IPPhone4;
@property (nonatomic, copy) NSString* IPPhone4_funcid;
@property (nonatomic, assign) NSInteger IPPhone4_camera;//0
@property (nonatomic, copy) NSString* number4;
@property (nonatomic, copy) NSString* IPPhone5;
@property (nonatomic, copy) NSString* IPPhone5_funcid;
@property (nonatomic, assign) NSInteger IPPhone5_camera;//0
@property (nonatomic, copy) NSString* number5;
@property (nonatomic, copy) NSString* IPPhone6;
@property (nonatomic, copy) NSString* IPPhone6_funcid;
@property (nonatomic, assign) NSInteger IPPhone6_camera;//0
@property (nonatomic, copy) NSString* number6;
@property (nonatomic, copy) NSString* bd;

@end

@interface ECSFriendAddingNotify : NSObject

@property (nonatomic, copy) NSString* from;
@property (nonatomic, copy) NSString* to;
@property (nonatomic, copy) NSString* type;//subscribe
@property (nonatomic, copy) NSString* nickname;
@property (nonatomic, copy) NSString* nativeName;
@property (nonatomic, copy) NSString* deptDesc;
@property (nonatomic, copy) NSString* deptDescEnglish;
@property (nonatomic, copy) NSString* sex;
@property (nonatomic, copy) NSString* id;

@end

@interface ECSFriendRemovedNotify : NSObject

@property (nonatomic, copy) NSString* from;
@property (nonatomic, copy) NSString* to;
@property (nonatomic, copy) NSString* type;//friendremove

@end

@interface ECSFriendAddResultNotify : NSObject

@property (nonatomic, copy) NSString* from;
@property (nonatomic, copy) NSString* to;
@property (nonatomic, copy) NSString* type;
@property (nonatomic, copy) NSString* nickname;
@property (nonatomic, copy) NSString* nativeName;
@property (nonatomic, copy) NSString* signature;
@property (nonatomic, assign) short update;//0

@end

@interface ECSFriendRelationChangedNotify : NSObject

@property (nonatomic, copy) NSString* from;
@property (nonatomic, copy) NSString* to;
@property (nonatomic, copy) NSString* type;//state
@property (nonatomic, copy) NSString* state;
@property (nonatomic, copy) NSString* timestamp;
@property (nonatomic, copy) NSString* en;
@property (nonatomic, copy) NSString* name;
@property (nonatomic, copy) NSString* m;
@property (nonatomic, copy) NSString* op;
@property (nonatomic, copy) NSString* voip;
@property (nonatomic, copy) NSString* voipDomain;
@property (nonatomic, copy) NSString* e;
@property (nonatomic, copy) NSString* si;
@property (nonatomic, copy) NSString* headid;
@property (nonatomic, copy) NSString* deptDesc;
@property (nonatomic, copy) NSString* sp;
@property (nonatomic, copy) NSString* voip2;
@property (nonatomic, copy) NSString* sp2;
@property (nonatomic, copy) NSString* spDomain;
@property (nonatomic, copy) NSString* voip2Domain;
@property (nonatomic, copy) NSString* sp2Domain;
@property (nonatomic, copy) NSString* bd;
@property (nonatomic, copy) NSString* domain;
@property (nonatomic, copy) NSString* softClientExtPhone;
@property (nonatomic, copy) NSString* softClientExtPhoneDomain;
@property (nonatomic, assign) NSInteger newProcessIdx;//0
@property (nonatomic, copy) NSString* m2;
@property (nonatomic, copy) NSString* homePhone;
@property (nonatomic, copy) NSString* phone;
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
@property (nonatomic, assign) NSInteger bdHideFlag;//0

@end

@interface ECSGetAppInfo : NSObject

@property (nonatomic, copy) NSString* ActionType;//GetAppInfo
@property (nonatomic, copy) NSString* user;

@end

@interface ECSGetAppInfoAckAppInfo : NSObject

@property (nonatomic, copy) NSString* appID;
@property (nonatomic, copy) NSString* appName;
@property (nonatomic, copy) NSString* appLogo;

@end

@interface ECSGetAppInfoAck : ECSRootErrorMsg

@property (nonatomic, strong) NSArray* appList;//ECSGetAppInfoAckAppInfo array

@end
