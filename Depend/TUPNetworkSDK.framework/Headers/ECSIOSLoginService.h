#import <Foundation/Foundation.h>
#import "ECSIOSLoginServiceMessage.h"
#import "ECSBaseService.h"

@protocol ECSIOSLoginServiceDelegate <NSObject>
@optional
@end

@interface ECSIOSLoginService : ECSBaseService

@property (nonatomic, weak) id<ECSIOSLoginServiceDelegate> delegate;

- (void) checkVersionWithRequest:(ECSCheckVersion*) request 
		completionBlock:(void (^)(ECSCheckVersionAck* retMsg, NSError* error, BOOL needReconnect, NSString* redirectAddress)) completionBlock;

- (void) keyExchangeWithRequest:(ECSKeyExchange*) request 
		completionBlock:(void (^)(ECSKeyExchangeAck* retMsg, NSError* error)) completionBlock;

- (void) loginWithRequest:(ECSLogin*) request 
		completionBlock:(void (^)(ECSLoginAck* retMsg, NSError* error)) completionBlock;

- (void) heartbeatWithRequest:(ECSHeartbeat*) request
                 checkNetwork:(BOOL)checkNetwork
                      timeout:(NSTimeInterval)time
		completionBlock:(void (^)(ECSHeartbeatAck* retMsg, NSError* error)) completionBlock;

- (void) getPosterWithRequest:(ECSGetPoster*) request 
		completionBlock:(void (^)(ECSGetPosterAck* retMsg, NSError* error)) completionBlock;

- (void) logoutWithRequest:(ECSLogout*) request
           completionBlock:(void (^)(ECSLogoutAck* retMsg, NSError* error)) completionBlock;

@end
