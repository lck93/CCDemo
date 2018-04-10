#import <Foundation/Foundation.h>
#import "ECSBaseMsg.h"

@interface ECSQueryRecentSessions : NSObject

@property (nonatomic, copy) NSString* ActionType;//QueryRecentSessions
@property (nonatomic, copy) NSString* user;
@property (nonatomic, assign) long long milltime;
@property (nonatomic, assign) long long count;

@end

@interface ECSQueryRecentSessionsAckRecordMessage : NSObject

@property (nonatomic, copy) NSString* id;
@property (nonatomic, copy) NSString* to;
@property (nonatomic, copy) NSString* from;
@property (nonatomic, copy) NSString* type;
@property (nonatomic, copy) NSString* name;
@property (nonatomic, copy) NSString* nativeName;
@property (nonatomic, copy) NSString* body;
@property (nonatomic, assign) long long milltime;
@property (nonatomic, copy) NSString* title;
@property (nonatomic, assign) short autoReply;
@property (nonatomic, copy) NSString* owner;
@property (nonatomic, assign) NSInteger contentType;
@property (nonatomic, assign) short readed;
@property (nonatomic, copy) NSString* msgEx;
@property (nonatomic, assign) NSInteger senderType;
@property (nonatomic, copy) NSString* appName;
@property (nonatomic, copy) NSString* appID;
@property (nonatomic, copy) NSString* cid;
@end

@interface ECSQueryRecentSessionsAckRecord : NSObject

@property (nonatomic, assign) NSInteger type;
@property (nonatomic, assign) long long milltime;
@property (nonatomic, copy) NSString* publicDes;
@property (nonatomic, strong) ECSQueryRecentSessionsAckRecordMessage* message;
@property (nonatomic, copy) NSString* headid;
@property (nonatomic, copy) NSString* name;
@property (nonatomic, copy) NSString* nativeName;
@property (nonatomic, copy) NSString* targetID;

@end

@interface ECSQueryRecentSessionsAck : ECSRootErrorMsg

@property (nonatomic, assign) long long milltime;
@property (nonatomic, strong) NSArray* list;//ECSQueryRecentSessionsAckRecord array

@end

@interface ECSDelRecentSessions : NSObject

@property (nonatomic, copy) NSString* ActionType;//DelRecentSessions
@property (nonatomic, copy) NSString* user;
@property (nonatomic, copy) NSString* attributes;
@property (nonatomic, assign) NSInteger type;
@property (nonatomic, assign) NSInteger opt;

@end

@interface ECSDelRecentSessionsAck : ECSRootErrorMsg


@end
