#import <Foundation/Foundation.h>
#import "ECSMAARequestOperation.h"
#import "ECSOprCommandServiceMessage.h"

@interface ECSOprCommandOperation : ECSMAARequestOperation

@property (nonatomic, strong) ECSOprCommand* oprCommandRequest;
@property (nonatomic, strong) ECSOprCommandAck* oprCommandResponse;

@end

@interface ECSSetMuteForMobileOperation : ECSMAARequestOperation

@property (nonatomic, strong) ECSSetMuteForMobile* setMuteForMobileRequest;
@property (nonatomic, strong) ECSSetMuteForMobileAck* setMuteForMobileResponse;

@end

@interface ECSGetMuteForMobileOperation : ECSMAARequestOperation

@property (nonatomic, strong) ECSGetMuteForMobile* getMuteForMobileRequest;
@property (nonatomic, strong) ECSGetMuteForMobileAck* getMuteForMobileResponse;

@end

