#import <Foundation/Foundation.h>
#import "ECSGroupManageServiceMessage.h"
#import "ECSBaseService.h"

typedef NS_ENUM(NSInteger, ECSGroupManageType) {
    ECSGroupCreate = 0,
    ECSGroupDelete = 1,
    ECSGroupModify = 2,
    ECSGroupTransferAdmin = 3,
    ECSGroupChangeType = 4,
    ECSGroupAdministratorQuitButNotDismiss = 5,
    ECSGroupModifyGroupSpace = 6
};

typedef NS_ENUM(NSInteger, ECSGroupType) {
    ECSFixGroup = 0,
    ECSChatGroup = 1
};

typedef NS_ENUM(NSInteger, ECSGroupJoinType) {
    ECSGroupJoinAuto = 0,
    ECSGroupJoinApply = 1,
    ECSGroupJoinDeny = 2
};

@protocol ECSGroupManageServiceDelegate <NSObject>
@optional
- (void) didReceiveGroupMemberChangedNotify:(ECSGroupMemberChangedNotify*) notify;
- (void) didReceiveGroupJoiningNotify:(ECSGroupJoiningNotify*) notify;
- (void) didReceiveGroupRemovedNotify:(ECSGroupRemovedNotify*) notify;
- (void) didReceiveTempGroupAdminMsgNotify:(ECSTempGroupAdminMsgNotify*) notify;
@end

@interface ECSGroupManageService : ECSBaseService

@property (nonatomic, weak) id<ECSGroupManageServiceDelegate> delegate;

- (void) manageGroupWithRequest:(ECSManageGroup*) request 
		completionBlock:(void (^)(ECSManageGroupAck* retMsg, NSError* error)) completionBlock;

- (void) sendTempGroupAdminMsgWithRequest:(ECSSendTempGroupAdminMsg*) request 
		completionBlock:(void (^)(ECSSendTempGroupAdminMsgAck* retMsg, NSError* error)) completionBlock;

- (void) joinGroupWithRequest:(ECSJoinGroup*) request 
		completionBlock:(void (^)(ECSJoinGroupAck* retMsg, NSError* error)) completionBlock;

- (void) leaveGroupWithRequest:(ECSLeaveGroup*) request 
		completionBlock:(void (^)(ECSLeaveGroupAck* retMsg, NSError* error)) completionBlock;

- (void) markGroupWithRequest:(ECSMarkGroup*) request 
		completionBlock:(void (^)(ECSMarkGroupAck* retMsg, NSError* error)) completionBlock;

- (void) getGroupPicWithRequest:(ECSGetGroupPic*) request 
		completionBlock:(void (^)(ECSGetGroupPicAck* retMsg, NSError* error)) completionBlock;

- (void) queryGroupMembersWithRequest:(ECSQueryGroupMembers*) request 
		completionBlock:(void (^)(ECSQueryGroupMembersAck* retMsg, NSError* error)) completionBlock;

- (void) acceptJoinInGroupWithRequest:(ECSAcceptJoinInGroup*) request 
		completionBlock:(void (^)(ECSAcceptJoinInGroupAck* retMsg, NSError* error)) completionBlock;

- (void) rejectJoinInGroupWithRequest:(ECSRejectJoinInGroup*) request 
		completionBlock:(void (^)(ECSRejectJoinInGroupAck* retMsg, NSError* error)) completionBlock;

@end
