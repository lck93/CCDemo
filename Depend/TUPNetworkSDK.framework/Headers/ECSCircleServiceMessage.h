#import <Foundation/Foundation.h>
#import "ECSBaseMsg.h"

@interface ECSSetCircleRelationRecord : NSObject

@property (nonatomic, copy) NSString* targetId;
@property (nonatomic, assign) NSInteger optType;

@end

@interface ECSSetCircleRelation : NSObject

@property (nonatomic, copy) NSString* ActionType;//SetCircleRelation
@property (nonatomic, copy) NSString* user;
@property (nonatomic, assign) NSInteger isFirstUse;
@property (nonatomic, strong) NSArray* list;//ECSSetCircleRelationRecord array

@end

@interface ECSSetCircleRelationAck : ECSRootErrorMsg


@end

@interface ECSSetCircleAuth : NSObject

@property (nonatomic, copy) NSString* ActionType;//SetCircleAuth
@property (nonatomic, copy) NSString* user;
@property (nonatomic, copy) NSString* targetId;
@property (nonatomic, assign) NSInteger type;
@property (nonatomic, assign) NSInteger auth;

@end

@interface ECSSetCircleAuthAck : ECSRootErrorMsg


@end

@interface ECSPubCircleTopic : NSObject

@property (nonatomic, copy) NSString* ActionType;//PubCircleTopic
@property (nonatomic, copy) NSString* from;
@property (nonatomic, copy) NSString* content;
@property (nonatomic, strong) NSArray* umList;//NSString array
@property (nonatomic, copy) NSString* topicGUID;
@property (nonatomic, copy) NSString* sourceTitle;
@property (nonatomic, copy) NSString* sourceUrl;
@property (nonatomic, assign) NSInteger contentType;
@property (nonatomic, copy) NSString* newcontent;

@end

@interface ECSPubCircleTopicAck : ECSRootErrorMsg

@property (nonatomic, copy) NSString* topicId;

@end

@interface ECSDeleteCircleTopic : NSObject

@property (nonatomic, copy) NSString* ActionType;//DeleteCircleTopic
@property (nonatomic, copy) NSString* topicOwner;
@property (nonatomic, copy) NSString* topicId;

@end

@interface ECSDeleteCircleTopicAck : ECSRootErrorMsg


@end

@interface ECSPubCircleComment : NSObject

@property (nonatomic, copy) NSString* ActionType;//PubCircleComment
@property (nonatomic, copy) NSString* from;
@property (nonatomic, copy) NSString* toTopicId;
@property (nonatomic, assign) NSInteger type;
@property (nonatomic, copy) NSString* to;
@property (nonatomic, copy) NSString* content;
@property (nonatomic, copy) NSString* commentGUID;

@end

@interface ECSPubCircleCommentAck : ECSRootErrorMsg

@property (nonatomic, copy) NSString* commentId;

@end

@interface ECSQueryCircleTopicList : NSObject

@property (nonatomic, copy) NSString* ActionType;//QueryCircleTopicList
@property (nonatomic, copy) NSString* user;
@property (nonatomic, copy) NSString* topicOwner;
@property (nonatomic, assign) NSInteger count;
@property (nonatomic, copy) NSString* topicId;
@property (nonatomic, assign) NSInteger queryType;
@property (nonatomic, assign) short likeCommentMode;//0

@end

@interface ECSQueryCircleTopicListAckTopicLike : NSObject

@property (nonatomic, copy) NSString* commentId;
@property (nonatomic, copy) NSString* from;
@property (nonatomic, assign) NSInteger time;

@end

@interface ECSQueryCircleTopicListAckTopicComment : NSObject

@property (nonatomic, copy) NSString* commentId;
@property (nonatomic, copy) NSString* from;
@property (nonatomic, copy) NSString* to;
@property (nonatomic, copy) NSString* content;
@property (nonatomic, assign) NSInteger time;
@property (nonatomic, copy) NSString* commentGUID;
@end

@interface ECSQueryCircleTopicListAckTopic : NSObject

@property (nonatomic, copy) NSString* topicId;
@property (nonatomic, copy) NSString* topicOwner;
@property (nonatomic, copy) NSString* content;
@property (nonatomic, strong) NSArray* umList;//NSString array
@property (nonatomic, assign) NSInteger time;
@property (nonatomic, assign) NSInteger likeListTotalCount;
@property (nonatomic, assign) NSInteger commentListTotalCount;
@property (nonatomic, strong) NSArray* likeList;//ECSQueryCircleTopicListAckTopicLike array
@property (nonatomic, strong) NSArray* commentList;//ECSQueryCircleTopicListAckTopicComment array
@property (nonatomic, assign) NSInteger updateTime;
@property (nonatomic, copy) NSString* sourceTitle;
@property (nonatomic, copy) NSString* sourceUrl;
@property (nonatomic, assign) NSInteger contentType;
@property (nonatomic, copy) NSString* newcontent;
@property (nonatomic, copy) NSString* topicGUID;

@end

@interface ECSQueryCircleTopicListAck : ECSRootErrorMsg

@property (nonatomic, strong) NSArray* list;//ECSQueryCircleTopicListAckTopic array

@end

@interface ECSQueryCircleTopic : NSObject

@property (nonatomic, copy) NSString* ActionType;//QueryCircleTopic
@property (nonatomic, copy) NSString* user;
@property (nonatomic, copy) NSString* topicId;
@property (nonatomic, assign) short likeCommentMode;//0

@end

@interface ECSQueryCircleTopicAckLike : NSObject

@property (nonatomic, copy) NSString* commentId;
@property (nonatomic, copy) NSString* from;
@property (nonatomic, assign) NSInteger time;

@end

@interface ECSQueryCircleTopicAckComment : NSObject

@property (nonatomic, copy) NSString* commentId;
@property (nonatomic, copy) NSString* from;
@property (nonatomic, copy) NSString* to;
@property (nonatomic, copy) NSString* content;
@property (nonatomic, assign) NSInteger time;

@end

@interface ECSQueryCircleTopicAck : ECSRootErrorMsg

@property (nonatomic, copy) NSString* topicOwner;
@property (nonatomic, copy) NSString* content;
@property (nonatomic, strong) NSArray* umList;//NSString array
@property (nonatomic, assign) NSInteger time;
@property (nonatomic, assign) NSInteger likeListTotalCount;
@property (nonatomic, assign) NSInteger commentListTotalCount;
@property (nonatomic, strong) NSArray* likeList;//ECSQueryCircleTopicAckLike array
@property (nonatomic, strong) NSArray* commentList;//ECSQueryCircleTopicAckComment array
@property (nonatomic, assign) NSInteger updateTime;
@property (nonatomic, copy) NSString* sourceTitle;
@property (nonatomic, copy) NSString* sourceUrl;
@property (nonatomic, assign) NSInteger contentType;
@property (nonatomic, copy) NSString* newcontent;

@end

@interface ECSGetCircleCommentList : NSObject

@property (nonatomic, copy) NSString* ActionType;//GetCircleCommentList
@property (nonatomic, copy) NSString* user;
@property (nonatomic, copy) NSString* topicId;
@property (nonatomic, assign) NSInteger commentType;
@property (nonatomic, assign) NSInteger count;
@property (nonatomic, copy) NSString* commentId;
@property (nonatomic, assign) NSInteger queryType;

@end

@interface ECSGetCircleCommentListAckRecord : NSObject

@property (nonatomic, copy) NSString* commentId;
@property (nonatomic, copy) NSString* from;
@property (nonatomic, copy) NSString* to;
@property (nonatomic, assign) NSInteger time;
@property (nonatomic, copy) NSString* content;

@end

@interface ECSGetCircleCommentListAck : ECSRootErrorMsg

@property (nonatomic, strong) NSArray* list;//ECSGetCircleCommentListAckRecord array

@end

@interface ECSCircleRelationChanged : NSObject

@property (nonatomic, copy) NSString* ActionType;//CircleRelationChanged
@property (nonatomic, copy) NSString* from;
@property (nonatomic, assign) NSInteger relation;
@property (nonatomic, copy) NSString* name;
@property (nonatomic, copy) NSString* nativeName;

@end

@interface ECSCircleRelationChangedAck : ECSRootErrorMsg


@end

@interface ECSNewCircleTopic : NSObject

@property (nonatomic, copy) NSString* ActionType;//NewCircleTopic
@property (nonatomic, copy) NSString* topicOwner;
@property (nonatomic, assign) NSInteger time;
@property (nonatomic, copy) NSString* topicId;

@end

@interface ECSNewCircleTopicAck : ECSRootErrorMsg


@end

@interface ECSNewCircleComment : NSObject

@property (nonatomic, copy) NSString* ActionType;//NewCircleComment
@property (nonatomic, copy) NSString* from;
@property (nonatomic, copy) NSString* toTopicId;
@property (nonatomic, assign) NSInteger type;
@property (nonatomic, copy) NSString* to;
@property (nonatomic, assign) NSInteger time;
@property (nonatomic, copy) NSString* content;
@property (nonatomic, copy) NSString* commentId;

@end

@interface ECSNewCircleCommentAck : ECSRootErrorMsg


@end

@interface ECSGetBidirectionalFriendList : NSObject

@property (nonatomic, copy) NSString* ActionType;//GetBidirectionalFriendList
@property (nonatomic, copy) NSString* user;

@end

@interface ECSGetBidirectionalFriendListAckRecord : NSObject

@property (nonatomic, copy) NSString* account;
@property (nonatomic, copy) NSString* name;
@property (nonatomic, copy) NSString* nativeName;

@end

@interface ECSGetBidirectionalFriendListAck : ECSRootErrorMsg

@property (nonatomic, strong) NSArray* list;//ECSGetBidirectionalFriendListAckRecord array

@end

@interface ECSQueryTopicId : NSObject

@property (nonatomic, copy) NSString* ActionType;//QueryTopicId
@property (nonatomic, copy) NSString* user;
@property (nonatomic, assign) NSInteger count;//100

@end

@interface ECSQueryTopicIdAckRecord : NSObject

@property (nonatomic, copy) NSString* topicId;
@property (nonatomic, assign) NSInteger updateTime;

@end

@interface ECSQueryTopicIdAck : ECSRootErrorMsg

@property (nonatomic, strong) NSArray* list;//ECSQueryTopicIdAckRecord array

@end

@interface ECSReqCircleState : NSObject

@property (nonatomic, copy) NSString* ActionType;//ReqCircleState
@property (nonatomic, copy) NSString* user;
@property (nonatomic, copy) NSString* timestamp;

@end

@interface ECSReqCircleStateAckReqState : NSObject

@property (nonatomic, copy) NSString* from;
@property (nonatomic, assign) NSInteger relation;
@property (nonatomic, assign) BOOL isHid;
@property (nonatomic, assign) long long modifyTime;
@property (nonatomic, copy) NSString* name;
@property (nonatomic, copy) NSString* nativeName;

@end

@interface ECSReqCircleStateAck : ECSRootErrorMsg

@property (nonatomic, copy) NSString* timestamp;
@property (nonatomic, strong) NSArray* stateList;//ECSReqCircleStateAckReqState array
@property (nonatomic, assign) NSInteger myRange;

@end

@interface ECSHidCircleStateRecord : NSObject

@property (nonatomic, copy) NSString* targetId;
@property (nonatomic, assign) BOOL isHid;

@end

@interface ECSHidCircleState : NSObject

@property (nonatomic, copy) NSString* ActionType;//HidCircleState
@property (nonatomic, copy) NSString* user;
@property (nonatomic, strong) NSArray* list;//ECSHidCircleStateRecord array

@end

@interface ECSHidCircleStateAck : ECSRootErrorMsg


@end

@interface ECSDelCircleComment : NSObject

@property (nonatomic, copy) NSString* ActionType;//DelCircleComment
@property (nonatomic, copy) NSString* from;
@property (nonatomic, copy) NSString* commentId;
@property (nonatomic, copy) NSString* topicId;

@end

@interface ECSDelCircleCommentAck : ECSRootErrorMsg


@end

@interface ECSQueryCirclePeopleNumber : NSObject

@property (nonatomic, copy) NSString* ActionType;//QueryCirclePeopleNumber
@property (nonatomic, copy) NSString* user;

@end

@interface ECSQueryCirclePeopleNumberAck : ECSRootErrorMsg

@property (nonatomic, assign) NSInteger peopleNumber;
@property (nonatomic, assign) NSInteger peopleRanking;
@property (nonatomic, assign) NSInteger peopleSurpass;

@end
