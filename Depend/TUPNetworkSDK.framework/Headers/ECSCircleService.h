#import <Foundation/Foundation.h>
#import "ECSCircleServiceMessage.h"
#import "ECSBaseService.h"

@protocol ECSCircleServiceDelegate <NSObject>
@optional
- (void) didReceiveCircleRelationChangedNotify:(ECSCircleRelationChanged*) relationChanged;
- (void) didReceiveNewTopicNotify:(ECSNewCircleTopic*) circleTopic;
- (void) didReceiveNewCircleCommentNotify:(ECSNewCircleComment *)circleComment;
@end

@interface ECSCircleService : ECSBaseService

@property (nonatomic, weak) id<ECSCircleServiceDelegate> delegate;

- (void) setCircleRelationWithRequest:(ECSSetCircleRelation*) request 
		completionBlock:(void (^)(ECSSetCircleRelationAck* retMsg, NSError* error)) completionBlock;

- (void) setCircleAuthWithRequest:(ECSSetCircleAuth*) request 
		completionBlock:(void (^)(ECSSetCircleAuthAck* retMsg, NSError* error)) completionBlock;

- (void) pubCircleTopicWithRequest:(ECSPubCircleTopic*) request 
		completionBlock:(void (^)(ECSPubCircleTopicAck* retMsg, NSError* error)) completionBlock;

- (void) deleteCircleTopicWithRequest:(ECSDeleteCircleTopic*) request 
		completionBlock:(void (^)(ECSDeleteCircleTopicAck* retMsg, NSError* error)) completionBlock;

- (void) pubCircleCommentWithRequest:(ECSPubCircleComment*) request 
		completionBlock:(void (^)(ECSPubCircleCommentAck* retMsg, NSError* error)) completionBlock;

- (void) queryCircleTopicListWithRequest:(ECSQueryCircleTopicList*) request 
		completionBlock:(void (^)(ECSQueryCircleTopicListAck* retMsg, NSError* error)) completionBlock;

- (void) queryCircleTopicWithRequest:(ECSQueryCircleTopic*) request 
		completionBlock:(void (^)(ECSQueryCircleTopicAck* retMsg, NSError* error)) completionBlock;

- (void) getCircleCommentListWithRequest:(ECSGetCircleCommentList*) request 
		completionBlock:(void (^)(ECSGetCircleCommentListAck* retMsg, NSError* error)) completionBlock;

- (void) getBidirectionalFriendListWithRequest:(ECSGetBidirectionalFriendList*) request 
		completionBlock:(void (^)(ECSGetBidirectionalFriendListAck* retMsg, NSError* error)) completionBlock;

- (void) queryTopicIdWithRequest:(ECSQueryTopicId*) request 
		completionBlock:(void (^)(ECSQueryTopicIdAck* retMsg, NSError* error)) completionBlock;

- (void) reqCircleStateWithRequest:(ECSReqCircleState*) request 
		completionBlock:(void (^)(ECSReqCircleStateAck* retMsg, NSError* error)) completionBlock;

- (void) hidCircleStateWithRequest:(ECSHidCircleState*) request 
		completionBlock:(void (^)(ECSHidCircleStateAck* retMsg, NSError* error)) completionBlock;

- (void) delCircleCommentWithRequest:(ECSDelCircleComment*) request 
		completionBlock:(void (^)(ECSDelCircleCommentAck* retMsg, NSError* error)) completionBlock;

- (void) queryCirclePeopleNumberWithRequest:(ECSQueryCirclePeopleNumber*) request 
		completionBlock:(void (^)(ECSQueryCirclePeopleNumberAck* retMsg, NSError* error)) completionBlock;

@end
