#import <Foundation/Foundation.h>
#import "ECSRecentSessionServiceMessage.h"
#import "ECSBaseService.h"

@protocol ECSRecentSessionServiceDelegate <NSObject>
@optional
@end

@interface ECSRecentSessionService : ECSBaseService

@property (nonatomic, weak) id<ECSRecentSessionServiceDelegate> delegate;

- (void) queryRecentSessionsWithRequest:(ECSQueryRecentSessions*) request 
		completionBlock:(void (^)(ECSQueryRecentSessionsAck* retMsg, NSError* error)) completionBlock;

- (void) delRecentSessionsWithRequest:(ECSDelRecentSessions*) request 
		completionBlock:(void (^)(ECSDelRecentSessionsAck* retMsg, NSError* error)) completionBlock;

@end
