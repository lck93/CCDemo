#import <Foundation/Foundation.h>
#import "ECSIMessagingServiceMessage.h"
#import "ECSBaseService.h"

typedef ECSSendGroupMsg ECSGroupMsg;

@protocol ECSIMessagingServiceDelegate <NSObject>
@optional
- (void) didReceiveChatMessage:(NSArray*) message;
- (void) didReceiveGroupMessage:(NSArray*) message;
- (void) didReceiveChatMessageNotify:(ECSChatMessageNotify*) notify;
- (void) didReceiveGroupMsgNotify:(ECSGroupMsgNotify*) notify;
- (void) didReceiveGroupChatResultNotify:(ECSGroupChatResultNotify*) notify;
- (void) didReceiveTempGroupMsgNotify:(ECSTempGroupMsgNotify*) notify;
- (void) didReceiveUnreadMessagesNotify:(ECSUnreadMessagesNotify*) notify;
- (void) didReceiveMessageReadNotify:(ECSMessageReadNotify*) notify;
- (void) didReceiveNewBulletinNotify:(ECSNewsMessage*)notify;
//收到撤回消息通知
- (void) didReceiveOprMsgNotify:(ECSOprMsgNotify*) notify;
@end

@interface ECSIMessagingService : ECSBaseService

@property (nonatomic, weak) id<ECSIMessagingServiceDelegate> delegate;

- (void) markReadWithRequest:(ECSMarkRead*) request 
		completionBlock:(void (^)(ECSMarkReadAck* retMsg, NSError* error)) completionBlock;

- (void) getMsgLogWithRequest:(ECSGetMsgLog*) request 
		completionBlock:(void (^)(ECSGetMsgLogAck* retMsg, NSError* error)) completionBlock;

- (void) delMsgLogWithRequest:(ECSDelMsgLog*) request 
		completionBlock:(void (^)(ECSDelMsgLogAck* retMsg, NSError* error)) completionBlock;

- (void) chatMessageWithRequest:(ECSChatMessage*) request 
		completionBlock:(void (^)(ECSChatMessageAck* retMsg, NSError* error)) completionBlock;

- (void) sendGroupMsgWithRequest:(ECSSendGroupMsg*) request 
		completionBlock:(void (^)(ECSSendGroupMsgAck* retMsg, NSError* error)) completionBlock;

- (void) sendTempGroupMsgWithRequest:(ECSSendTempGroupMsg*) request 
		completionBlock:(void (^)(ECSSendTempGroupMsgAck* retMsg, NSError* error)) completionBlock;

- (void) getRoamingMsgWithRequest:(ECSGetRoamingMsg*) request 
		completionBlock:(void (^)(ECSGetRoamingMsgAck* retMsg, NSError* error)) completionBlock;

- (void) delRoamingMsgWithRequest:(ECSDelRoamingMsg*) request 
		completionBlock:(void (^)(ECSDelRoamingMsgAck* retMsg, NSError* error)) completionBlock;

- (void) queryNewsListWithRequest:(ECSQueryNewsList*) request 
		completionBlock:(void (^)(ECSQueryNewsListAck* retMsg, NSError* error)) completionBlock;

- (void) queryNewsWithRequest:(ECSQueryNews*) request 
		completionBlock:(void (^)(ECSQueryNewsAck* retMsg, NSError* error)) completionBlock;
//撤回消息
- (void) oprMsgWithRequest:(ECSOprMsg*) request
           completionBlock:(void (^)(ECSOprMsgAck* retMsg, NSError* error)) completionBlock;
@end
