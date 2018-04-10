#import <Foundation/Foundation.h>
#import "ECSUserSettingServiceMessage.h"
#import "ECSBaseService.h"

#define kECSMultiTerminalNotify @"kECSMultiTerminalNotify"

@protocol ECSUserSettingServiceDelegate <NSObject>
@optional
- (void) didReceiveConfigChangeNotify:(ECSConfigChangeNotify*) notify;
- (void) didReceiveIPPhoneStateNotify:(ECSIPPhoneStateNotify*) notify;
- (void) didReceiveMultiTerminalNotify:(ECSMultiTerminalNotify*) notify;
@end

@class ECSTUPSetHeadImageService;
@interface ECSUserSettingService : ECSBaseService

@property (nonatomic, weak) id<ECSUserSettingServiceDelegate> delegate;
@property (nonatomic, strong, readonly) ECSTUPSetHeadImageService *uPortalSetHeadImageService;


- (void) setCountryWithRequest:(ECSSetCountry*) request 
		completionBlock:(void (^)(ECSSetCountryAck* retMsg, NSError* error)) completionBlock;

- (void) queryCountryWithRequest:(ECSQueryCountry*) request 
		completionBlock:(void (^)(ECSQueryCountryAck* retMsg, NSError* error)) completionBlock;

- (void) getSensitiveWithRequest:(ECSGetSensitive*) request 
		completionBlock:(void (^)(ECSGetSensitiveAck* retMsg, NSError* error)) completionBlock;

- (void) getLocationWithRequest:(ECSGetLocation*) request 
		completionBlock:(void (^)(ECSGetLocationAck* retMsg, NSError* error)) completionBlock;

- (void) setLocationWithRequest:(ECSSetLocation*) request 
		completionBlock:(void (^)(ECSSetLocationAck* retMsg, NSError* error)) completionBlock;

- (void) configPushWithRequest:(ECSConfigPush*) request 
		completionBlock:(void (^)(ECSConfigPushAck* retMsg, NSError* error)) completionBlock;

- (void) setSelfStateAndSignWithRequest:(ECSSetSelfStateAndSign*) request 
		completionBlock:(void (^)(ECSSetSelfStateAndSignAck* retMsg, NSError* error)) completionBlock;

- (void) setSelfStateWithRequest:(ECSSetSelfState*) request 
		completionBlock:(void (^)(ECSSetSelfStateAck* retMsg, NSError* error)) completionBlock;

- (void) setSelfHeadImageWithRequest:(ECSSetSelfHeadImage*) request 
		completionBlock:(void (^)(ECSSetSelfHeadImageAck* retMsg, NSError* error)) completionBlock;

- (void) feedbackWithRequest:(ECSFeedback*) request 
		completionBlock:(void (^)(ECSFeedbackAck* retMsg, NSError* error)) completionBlock;

- (void) queryVersionHistoryWithRequest:(ECSQueryVersionHistory*) request 
		completionBlock:(void (^)(ECSQueryVersionHistoryAck* retMsg, NSError* error)) completionBlock;

- (void) getConfigWithRequest:(ECSGetConfig*) request
              completionBlock:(void (^)(ECSGetConfigAck* retMsg, NSError* error)) completionBlock;

- (void) reportStatisticsInfoWithRequest:(ECSReportStatisticsInfo*) request
                         completionBlock:(void (^)(ECSReportStatisticsInfoAck* retMsg, NSError* error)) completionBlock;

- (void) kickoutWithRequest:(ECSKickout*) request
            completionBlock:(void (^)(ECSKickoutAck* retMsg, NSError* error)) completionBlock;

- (void) setDefCTDNumberWithRequest:(ECSSetDefCTDNumber*) request
                    completionBlock:(void (^)(ECSSetDefCTDNumberAck* retMsg, NSError* error)) completionBlock;
@end
