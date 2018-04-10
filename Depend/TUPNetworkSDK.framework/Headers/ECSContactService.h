#import <Foundation/Foundation.h>
#import "ECSContactServiceMessage.h"
#import "ECSBaseService.h"

typedef NS_ENUM(NSInteger, ECS_CONTACT_SYNC_MODE) {
    ECS_CONTACT_SYNC_NONE = 0,
    ECS_CONTACT_SYNC_PART = 1,
    ECS_CONTACT_SYNC_FULL = 2
};

@protocol ECSContactServiceDelegate <NSObject>
@optional
- (void) didReceiveFriendStateChangedNotify:(NSArray*) notify;
- (void) didReceiveFriendAddingNotify:(ECSFriendAddingNotify*) notify;
- (void) didReceiveFriendRemovedNotify:(ECSFriendRemovedNotify*) notify;
- (void) didReceiveFriendAddResultNotify:(ECSFriendAddResultNotify*) notify;
- (void) didReceiveFriendRelationChangedNotify:(ECSFriendRelationChangedNotify*) notify;
@end

@interface ECSContactService : ECSBaseService

@property (nonatomic, weak) id<ECSContactServiceDelegate> delegate;

- (void) getUserHeadImage:(NSString*) headId
                    width:(NSUInteger) width
                   height:(NSUInteger) height
              currentUser:(NSString *)userAccount
          completionBlock:(void (^)(NSData* imageData, NSError* error)) completionBlock;

- (void) queryCorpContractByEmployeeNumber:(NSString*) employeeNumber
                              returnStatus:(BOOL) bStatus
                               currentUser:(NSString *)userAccount
                           completionBlock:(void (^)(ECSCorpUserContact* retMsg, NSError* error)) completionBlock;

- (void) fullSyncWithRequest:(ECSFullSync*) request 
		completionBlock:(void (^)(ECSFullSyncAck* retMsg, NSError* error)) completionBlock;

- (void) partialSyncWithRequest:(ECSPartialSync*) request 
		completionBlock:(void (^)(ECSPartialSyncAck* retMsg, NSError* error)) completionBlock;

- (void) queryMobileWithRequest:(ECSQueryMobile*) request 
		completionBlock:(void (^)(ECSQueryMobileAck* retMsg, NSError* error)) completionBlock;

- (void) addContactGroupWithRequest:(ECSAddContactGroup*) request 
		completionBlock:(void (^)(ECSAddContactGroupAck* retMsg, NSError* error)) completionBlock;

- (void) delContactGroupWithRequest:(ECSDelContactGroup*) request 
		completionBlock:(void (^)(ECSDelContactGroupAck* retMsg, NSError* error)) completionBlock;

- (void) addFriendWithRequest:(ECSAddFriend*) request 
		completionBlock:(void (^)(ECSAddFriendAck* retMsg, NSError* error)) completionBlock;

- (void) delFriendWithRequest:(ECSDelFriend*) request 
		completionBlock:(void (^)(ECSDelFriendAck* retMsg, NSError* error)) completionBlock;

- (void) viewFriendHeadImageWithRequest:(ECSViewFriendHeadImage*) request 
		completionBlock:(void (^)(ECSViewFriendHeadImageAck* retMsg, NSError* error)) completionBlock;

- (void) inviteFriendWithRequest:(ECSInviteFriend*) request 
		completionBlock:(void (^)(ECSInviteFriendAck* retMsg, NSError* error)) completionBlock;

- (void) addNonFriendMemberWithRequest:(ECSAddNonFriendMember*) request 
		completionBlock:(void (^)(ECSAddNonFriendMemberAck* retMsg, NSError* error)) completionBlock;

- (void) queryCorpContactsWithRequest:(ECSQueryCorpContacts*) request 
		completionBlock:(void (^)(ECSQueryCorpContactsAck* retMsg, NSError* error)) completionBlock;

- (void) getDepartListWithRequest:(ECSGetDepartList*) request 
		completionBlock:(void (^)(ECSGetDepartListAck* retMsg, NSError* error)) completionBlock;

- (void) getAppInfoWithRequest:(ECSGetAppInfo*) request
               completionBlock:(void (^)(ECSGetAppInfoAck* retMsg, NSError* error)) completionBlock;
@end
