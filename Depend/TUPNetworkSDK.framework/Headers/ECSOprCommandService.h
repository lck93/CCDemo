#import <Foundation/Foundation.h>
#import "ECSOprCommandServiceMessage.h"
#import "ECSBaseService.h"

@protocol ECSOprCommandServiceDelegate <NSObject>
@optional
//收到指令性消息通知
- (void) didReceiveOprCommandNotify:(ECSOprCommandNotify*) notify;
@end


@interface ECSOprCommandService : ECSBaseService

@property (nonatomic, weak) id<ECSOprCommandServiceDelegate> delegate;


- (void) oprCommandWithRequest:(ECSOprCommand*) request 
		completionBlock:(void (^)(ECSOprCommandAck* retMsg, NSError* error)) completionBlock;

- (void) setMuteForMobileWithRequest:(ECSSetMuteForMobile*) request
                     completionBlock:(void (^)(ECSSetMuteForMobileAck* retMsg, NSError* error)) completionBlock;

- (void) getMuteForMobileWithRequest:(ECSGetMuteForMobile*) request
                     completionBlock:(void (^)(ECSGetMuteForMobileAck* retMsg, NSError* error)) completionBlock;

@end


