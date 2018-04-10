#import <Foundation/Foundation.h>
#import "ECSBaseMsg.h"

@interface ECSSetCountry : NSObject

@property (nonatomic, copy) NSString* ActionType;//SetCountry
@property (nonatomic, copy) NSString* user;
@property (nonatomic, copy) NSString* code;

@end

@interface ECSSetCountryAck : ECSRootErrorMsg


@end

@interface ECSQueryCountry : NSObject

@property (nonatomic, copy) NSString* ActionType;//QueryCountry
@property (nonatomic, copy) NSString* user;

@end

@interface ECSQueryCountryAck : ECSRootErrorMsg

@property (nonatomic, copy) NSString* code;

@end

@interface ECSGetSensitive : NSObject

@property (nonatomic, copy) NSString* ActionType;//GetSensitive
@property (nonatomic, copy) NSString* user;

@end

@interface ECSGetSensitiveAck : ECSRootErrorMsg

@property (nonatomic, copy) NSString* w;

@end

@interface ECSGetLocation : NSObject

@property (nonatomic, copy) NSString* ActionType;//GetLocation
@property (nonatomic, copy) NSString* user;
@property (nonatomic, copy) NSString* pid;

@end

@interface ECSGetLocationAckLocation : NSObject

@property (nonatomic, copy) NSString* id;
@property (nonatomic, assign) BOOL isLeaf;//0
@property (nonatomic, copy) NSString* name;

@end

@interface ECSGetLocationAck : ECSRootErrorMsg

@property (nonatomic, strong) NSArray* list;//ECSGetLocationAckLocation array

@end

@interface ECSSetLocation : NSObject

@property (nonatomic, copy) NSString* ActionType;//SetLocation
@property (nonatomic, copy) NSString* user;
@property (nonatomic, copy) NSString* location;
@property (nonatomic, copy) NSString* customLocation;

@end

@interface ECSSetLocationAck : ECSRootErrorMsg


@end

@interface ECSConfigPush : NSObject

@property (nonatomic, copy) NSString* ActionType;//ConfigPush
@property (nonatomic, copy) NSString* user;
@property (nonatomic, assign) BOOL enable;
@property (nonatomic, copy) NSString* noPushStart;
@property (nonatomic, copy) NSString* noPushEnd;
@property (nonatomic, assign) BOOL timeEnable;

@end

@interface ECSConfigPushAck : ECSRootErrorMsg


@end

@interface ECSSetSelfStateAndSignQuery : NSObject

@property (nonatomic, copy) NSString* xmlns;//jabber:iq:presence
@property (nonatomic, copy) NSString* show;
@property (nonatomic, copy) NSString* status;
@property (nonatomic, copy) NSString* signature;

@end

@interface ECSSetSelfStateAndSign : NSObject

@property (nonatomic, copy) NSString* type;//set
@property (nonatomic, copy) NSString* from;
@property (nonatomic, strong) ECSSetSelfStateAndSignQuery* query;

@end

@interface ECSSetSelfStateAndSignAck : ECSIqErrorMsg


@end

@interface ECSSetSelfStateQuery : NSObject

@property (nonatomic, copy) NSString* xmlns;//jabber:iq:presence
@property (nonatomic, copy) NSString* show;
@property (nonatomic, copy) NSString* status;
@property (nonatomic, assign) NSInteger camera;//1

@end

@interface ECSSetSelfState : NSObject

@property (nonatomic, copy) NSString* type;//set
@property (nonatomic, copy) NSString* from;
@property (nonatomic, strong) ECSSetSelfStateQuery* query;

@end

@interface ECSSetSelfStateAck : ECSIqErrorMsg


@end

@interface ECSSetSelfHeadImageQuery : NSObject

@property (nonatomic, copy) NSString* xmlns;//jabber:iq:presence
@property (nonatomic, copy) NSString* headpicture;

@end

@interface ECSSetSelfHeadImage : NSObject

@property (nonatomic, copy) NSString* type;//set
@property (nonatomic, copy) NSString* from;
@property (nonatomic, strong) ECSSetSelfHeadImageQuery* query;

@end

@interface ECSSetSelfHeadImageAck : ECSIqErrorMsg

@property (nonatomic, copy) NSString* headid;

@end

@interface ECSFeedback : NSObject

@property (nonatomic, copy) NSString* ActionType;//Feedback
@property (nonatomic, copy) NSString* user;
@property (nonatomic, copy) NSString* body;

@end

@interface ECSFeedbackAck : ECSRootErrorMsg


@end

@interface ECSQueryVersionHistory : NSObject

@property (nonatomic, copy) NSString* ActionType;//QueryVersionHistory
@property (nonatomic, copy) NSString* user;
@property (nonatomic, copy) NSString* vr;
@property (nonatomic, copy) NSString* la;

@end

@interface ECSQueryVersionHistoryAck : ECSRootErrorMsg

@property (nonatomic, copy) NSString* body;

@end

@interface ECSConfigChangeNotify : NSObject

@property (nonatomic, copy) NSString* funcid;
@property (nonatomic, assign) short callLimitType;//-1
@property (nonatomic, assign) short controlCFU;//-1
@property (nonatomic, copy) NSString* SNRNumber;
@property (nonatomic, assign) NSInteger DNDConfig;//0

@end

@interface ECSIPPhoneStateNotify : NSObject

@property (nonatomic, copy) NSString* to;
@property (nonatomic, assign) NSInteger stat;//0

@end

@interface ECSGetConfig : NSObject

@property (nonatomic, copy) NSString* ActionType;//GetConfig
@property (nonatomic, copy) NSString* user;

@end

@interface ECSGetConfigAckAccountInfo : NSObject

@property (nonatomic, copy) NSString* name;
@property (nonatomic, copy) NSString* label;
@property (nonatomic, assign) short canModify;//0
@property (nonatomic, assign) short canDisplay;//1

@end

@interface ECSGetConfigAckDetailInfo : NSObject

@property (nonatomic, copy) NSString* name;
@property (nonatomic, copy) NSString* label;
@property (nonatomic, assign) short canModify;//0
@property (nonatomic, assign) short canDisplay;//1

@end

@interface ECSGetConfigAck : ECSRootErrorMsg

@property (nonatomic, copy) NSString* timestamp;
@property (nonatomic, assign) short showPhoneStatus;//0
@property (nonatomic, strong) NSArray* accountInfoList;//ECSGetConfigAckAccountInfo array
@property (nonatomic, strong) NSArray* detailInfoList;//ECSGetConfigAckDetailInfo array

@end

@interface ECSReportStatisticsInfoReportInfo : NSObject

@property (nonatomic, assign) NSInteger jsonType;
@property (nonatomic, copy) NSString* jsonBody;

@end

@interface ECSReportStatisticsInfo : NSObject

@property (nonatomic, copy) NSString* ActionType;//ReportStatisticsInfo
@property (nonatomic, copy) NSString* user;
@property (nonatomic, copy) NSString* deviceID;
@property (nonatomic, assign) NSInteger number;//100
@property (nonatomic, strong) NSArray* list;//ECSReportStatisticsInfoReportInfo array

@end

@interface ECSReportStatisticsInfoAck : ECSRootErrorMsg


@end

@interface ECSKickout : NSObject

@property (nonatomic, copy) NSString* ActionType;//Kickout
@property (nonatomic, copy) NSString* user;
@property (nonatomic, copy) NSString* toDType;

@end

@interface ECSKickoutAck : ECSRootErrorMsg


@end

@interface ECSMultiTerminalNotify : NSObject

@property (nonatomic, copy) NSString* user;
@property (nonatomic, copy) NSString* deviceType;
@property (nonatomic, assign) long long time;
@property (nonatomic, assign) NSInteger eventType;
@end

@interface ECSSetDefCTDNumber : NSObject

@property (nonatomic, copy) NSString* ActionType;//SetDefCTDNumber
@property (nonatomic, copy) NSString* user;
@property (nonatomic, copy) NSString* defCTDNumber;

@end

@interface ECSSetDefCTDNumberAck : ECSRootErrorMsg


@end
