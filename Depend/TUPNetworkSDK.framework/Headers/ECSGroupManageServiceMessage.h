#import <Foundation/Foundation.h>
#import "ECSBaseMsg.h"

@interface ECSManageGroup : NSObject

@property (nonatomic, copy) NSString* ActionType;//ManageGroup
@property (nonatomic, copy) NSString* user;
@property (nonatomic, copy) NSString* groupID;
@property (nonatomic, copy) NSString* groupName;
@property (nonatomic, copy) NSString* groupAdmin;
@property (nonatomic, assign) NSInteger joinCondition;//-1
@property (nonatomic, copy) NSString* declare;
@property (nonatomic, copy) NSString* desc;
@property (nonatomic, assign) NSInteger opt;//-1
@property (nonatomic, assign) NSInteger groupType;//0
@property (nonatomic, copy) NSString* inviteList;
@property (nonatomic, copy) NSString* announce;
@property (nonatomic, copy) NSString* intro;
@property (nonatomic, copy) NSString* enName;
@property (nonatomic, copy) NSString* groupSpaceInfo;
@end

@interface ECSManageGroupAck : ECSRootErrorMsg

@property (nonatomic, copy) NSString* groupID;
@property (nonatomic, copy) NSString* destAccount;
@property (nonatomic, assign) NSInteger capacity;//0
@property (nonatomic, copy) NSString* failedList;

@end

@interface ECSSendTempGroupAdminMsg : NSObject

@property (nonatomic, copy) NSString* to;
@property (nonatomic, copy) NSString* from;
@property (nonatomic, copy) NSString* type;//managetempgroup
@property (nonatomic, copy) NSString* body;
@property (nonatomic, copy) NSString* body_jid;
@property (nonatomic, copy) NSString* body_flag;

@end

@interface ECSSendTempGroupAdminMsgAck : ECSMessageErrorMsg


@end

@interface ECSJoinGroup : NSObject

@property (nonatomic, copy) NSString* ActionType;//JoinGroup
@property (nonatomic, copy) NSString* groupID;
@property (nonatomic, assign) NSInteger groupType;//0
@property (nonatomic, copy) NSString* groupName;
@property (nonatomic, copy) NSString* user;
@property (nonatomic, copy) NSString* inviteList;
@property (nonatomic, assign) NSInteger joinFlag;//0
@property (nonatomic, copy) NSString* desc;
@property (nonatomic, copy) NSString* userName;

@end

@interface ECSJoinGroupAck : ECSRootErrorMsg

@property (nonatomic, copy) NSString* groupID;
@property (nonatomic, assign) NSInteger groupType;//0
@property (nonatomic, copy) NSString* user;
@property (nonatomic, copy) NSString* destAccount;
@property (nonatomic, assign) NSInteger joinFlag;//0
@property (nonatomic, copy) NSString* failedList;

@end

@interface ECSLeaveGroup : NSObject

@property (nonatomic, copy) NSString* ActionType;//LeaveGroup
@property (nonatomic, copy) NSString* groupID;
@property (nonatomic, assign) NSInteger groupType;//0
@property (nonatomic, copy) NSString* user;
@property (nonatomic, assign) NSInteger leaveFlag;//0
@property (nonatomic, copy) NSString* leavedList;

@end

@interface ECSLeaveGroupAck : ECSRootErrorMsg

@property (nonatomic, copy) NSString* groupID;
@property (nonatomic, assign) NSInteger groupType;//0
@property (nonatomic, assign) NSInteger leaveFlag;//0
@property (nonatomic, copy) NSString* destAccount;

@end

@interface ECSMarkGroup : NSObject

@property (nonatomic, copy) NSString* ActionType;//MarkGroup
@property (nonatomic, copy) NSString* user;
@property (nonatomic, assign) short opType;//0
@property (nonatomic, assign) short opValue;//0
@property (nonatomic, copy) NSString* groupID;
@property (nonatomic, assign) NSInteger groupType;//1

@end

@interface ECSMarkGroupAck : ECSRootErrorMsg


@end

@interface ECSGetGroupPic : NSObject

@property (nonatomic, copy) NSString* ActionType;//GetGroupPic
@property (nonatomic, copy) NSString* user;
@property (nonatomic, copy) NSString* groupId;
@property (nonatomic, assign) NSInteger count;//4

@end

@interface ECSGetGroupPicAckItem : NSObject

@property (nonatomic, copy) NSString* headid;
@property (nonatomic, copy) NSString* user;

@end

@interface ECSGetGroupPicAck : ECSRootErrorMsg

@property (nonatomic, strong) NSArray* idList;//ECSGetGroupPicAckItem array

@end

@interface ECSQueryGroupMembers : NSObject

@property (nonatomic, copy) NSString* from;
@property (nonatomic, copy) NSString* to;
@property (nonatomic, copy) NSString* type;//get
@property (nonatomic, copy) NSString* owner;
@property (nonatomic, copy) NSString* query_xmlns;//http://jabber.org/protocol/disco#items
@property (nonatomic, assign) NSInteger groupType;//0

@end

@interface ECSQueryGroupMembersAckQueryItem : NSObject

@property (nonatomic, copy) NSString* jid;
@property (nonatomic, copy) NSString* name;
@property (nonatomic, copy) NSString* nativeName;
@property (nonatomic, copy) NSString* bd;
@property (nonatomic, copy) NSString* domain;
@property (nonatomic, assign) NSInteger type;//0
@property (nonatomic, copy) NSString* phone;
@property (nonatomic, copy) NSString* voip;
@property (nonatomic, copy) NSString* voip2;
@property (nonatomic, copy) NSString* mobile;
@property (nonatomic, copy) NSString* shortnumber;
@property (nonatomic, copy) NSString* officephone;
@property (nonatomic, copy) NSString* originMobile;
@property (nonatomic, copy) NSString* originOffice;
@property (nonatomic, copy) NSString* spDomain;
@property (nonatomic, copy) NSString* sp2;
@property (nonatomic, copy) NSString* sp2Domain;
@property (nonatomic, copy) NSString* m2;
@property (nonatomic, copy) NSString* homePhone;
@property (nonatomic, copy) NSString* voipDomain;
@property (nonatomic, copy) NSString* voip2Domain;
@property (nonatomic, copy) NSString* softClientExtPhone;
@property (nonatomic, copy) NSString* softClientExtPhoneDomain;
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
@property (nonatomic, copy) NSString* headid;

@end

@interface ECSQueryGroupMembersAckQuery : ECSErrorQuery

@property (nonatomic, copy) NSString* xmlns;
@property (nonatomic, strong) NSArray* items;//ECSQueryGroupMembersAckQueryItem array

@end

@interface ECSQueryGroupMembersAck : ECSQueryErrorMsg

@property (nonatomic, copy) NSString* from;
@property (nonatomic, copy) NSString* to;
@property (nonatomic, copy) NSString* type;
@property (nonatomic, strong) ECSQueryGroupMembersAckQuery* query;
@property (nonatomic, assign) NSInteger groupType;//0

@end

@interface ECSAcceptJoinInGroupXAccept : NSObject

@property (nonatomic, copy) NSString* to;

@end

@interface ECSAcceptJoinInGroupX : NSObject

@property (nonatomic, copy) NSString* xmlns;//http://jabber.org/protocol/muc#user
@property (nonatomic, strong) ECSAcceptJoinInGroupXAccept* accept;

@end

@interface ECSAcceptJoinInGroup : NSObject

@property (nonatomic, copy) NSString* from;
@property (nonatomic, copy) NSString* to;
@property (nonatomic, copy) NSString* type;//set
@property (nonatomic, strong) ECSAcceptJoinInGroupX* x;

@end

@interface ECSAcceptJoinInGroupAck : ECSQueryErrorMsg


@end

@interface ECSRejectJoinInGroupXDecline : NSObject

@property (nonatomic, copy) NSString* to;
@property (nonatomic, copy) NSString* reason;

@end

@interface ECSRejectJoinInGroupX : NSObject

@property (nonatomic, copy) NSString* xmlns;//http://jabber.org/protocol/muc#user
@property (nonatomic, strong) ECSRejectJoinInGroupXDecline* decline;

@end

@interface ECSRejectJoinInGroup : NSObject

@property (nonatomic, copy) NSString* from;
@property (nonatomic, copy) NSString* to;
@property (nonatomic, copy) NSString* type;//set
@property (nonatomic, strong) ECSRejectJoinInGroupX* x;

@end

@interface ECSRejectJoinInGroupAck : ECSQueryErrorMsg


@end

@interface ECSGroupMemberChangedNotifyItem : NSObject

@property (nonatomic, copy) NSString* jid;
@property (nonatomic, copy) NSString* name;
@property (nonatomic, copy) NSString* nativeName;
@property (nonatomic, copy) NSString* bd;
@property (nonatomic, copy) NSString* domain;
@property (nonatomic, copy) NSString* phone;
@property (nonatomic, copy) NSString* voip;
@property (nonatomic, copy) NSString* voip2;
@property (nonatomic, copy) NSString* mobile;
@property (nonatomic, copy) NSString* shortnumber;
@property (nonatomic, copy) NSString* officephone;
@property (nonatomic, copy) NSString* originMobile;
@property (nonatomic, copy) NSString* originOffice;
@property (nonatomic, copy) NSString* spDomain;
@property (nonatomic, copy) NSString* sp2;
@property (nonatomic, copy) NSString* sp2Domain;
@property (nonatomic, copy) NSString* m2;
@property (nonatomic, copy) NSString* homePhone;
@property (nonatomic, copy) NSString* voipDomain;
@property (nonatomic, copy) NSString* voip2Domain;
@property (nonatomic, copy) NSString* softClientExtPhone;
@property (nonatomic, copy) NSString* softClientExtPhoneDomain;
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
@property (nonatomic, copy) NSString* reason;

@end

@interface ECSGroupMemberChangedNotify : NSObject

@property (nonatomic, copy) NSString* from;
@property (nonatomic, copy) NSString* to;
@property (nonatomic, copy) NSString* type;//kick
@property (nonatomic, copy) NSString* id;
@property (nonatomic, strong) ECSGroupMemberChangedNotifyItem* item;
@property (nonatomic, assign) NSInteger groupType;//0
@property (nonatomic, assign) NSInteger noticeType;

@end

@interface ECSGroupJoiningNotifyInvite : NSObject

@property (nonatomic, copy) NSString* to;
@property (nonatomic, copy) NSString* name;
@property (nonatomic, copy) NSString* announce;
@property (nonatomic, copy) NSString* intro;
@property (nonatomic, copy) NSString* reason;

@end

@interface ECSGroupJoiningNotify : NSObject

@property (nonatomic, copy) NSString* from;
@property (nonatomic, copy) NSString* to;
@property (nonatomic, copy) NSString* name;
@property (nonatomic, copy) NSString* nativeName;
@property (nonatomic, copy) NSString* id;
@property (nonatomic, strong) ECSGroupJoiningNotifyInvite* invite;
@property (nonatomic, assign) NSInteger groupType;//0

@end

@interface ECSGroupRemovedNotify : NSObject

@property (nonatomic, copy) NSString* from;
@property (nonatomic, copy) NSString* to;
@property (nonatomic, copy) NSString* type;//groupremove
@property (nonatomic, copy) NSString* name;
@property (nonatomic, copy) NSString* id;
@property (nonatomic, assign) NSInteger groupType;//0
@property (nonatomic, assign) short isAdmin;//0
@property (nonatomic, copy) NSString* opUser;
@property (nonatomic, copy) NSString* enName;
@property (nonatomic, copy) NSString* groupSpaceInfo;

@end

@interface ECSTempGroupAdminMsgNotify : NSObject

@property (nonatomic, copy) NSString* from;
@property (nonatomic, copy) NSString* to;
@property (nonatomic, copy) NSString* type;//managetempgroup
@property (nonatomic, copy) NSString* body;
@property (nonatomic, copy) NSString* body_jid;
@property (nonatomic, copy) NSString* body_flag;

@end
