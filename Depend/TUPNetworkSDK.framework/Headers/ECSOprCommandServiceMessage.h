#import <Foundation/Foundation.h>
#import "ECSBaseMsg.h"

@interface ECSOprCommand : NSObject

@property (nonatomic, copy) NSString* ActionType;//OprCommand
@property (nonatomic, copy) NSString* origin;
@property (nonatomic, assign) NSInteger receiverType;
@property (nonatomic, strong) NSArray* userList;//NSString array
@property (nonatomic, copy) NSString* groupID;
@property (nonatomic, copy) NSString* commandBody;
@property (nonatomic, assign) long long deliverTime;
@property (nonatomic, copy) NSString* originAppID;
@property (nonatomic, copy) NSString* originAppName;
@property (nonatomic, assign) NSInteger senderType;

@end

@interface ECSOprCommandAck : ECSRootErrorMsg


@end

@interface ECSOprCommandNotify : NSObject

@property (nonatomic, copy) NSString* ActionType;//OprCommandNotify
@property (nonatomic, copy) NSString* origin;
@property (nonatomic, copy) NSString* groupId;
@property (nonatomic, copy) NSString* target;
@property (nonatomic, copy) NSString* id;
@property (nonatomic, copy) NSString* commandBody;
@property (nonatomic, assign) long long deliverTime;
@property (nonatomic, copy) NSString* originAppID;
@property (nonatomic, copy) NSString* originAppName;
@property (nonatomic, assign) NSInteger senderType;

@end

@interface ECSSetMuteForMobile : NSObject

@property (nonatomic, copy) NSString* ActionType;//SetMuteForMobile
@property (nonatomic, copy) NSString* user;
@property (nonatomic, copy) NSString* muteFlagForMobile;

@end

@interface ECSSetMuteForMobileAck : ECSRootErrorMsg


@end

@interface ECSGetMuteForMobile : NSObject

@property (nonatomic, copy) NSString* ActionType;//GetMuteForMobile
@property (nonatomic, copy) NSString* user;

@end

@interface ECSGetMuteForMobileAck : ECSRootErrorMsg

@property (nonatomic, copy) NSString* muteFlagForMobile;

@end
