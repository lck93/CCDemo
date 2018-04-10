//
//  TUPMediator_ContactService.h
//  TUPMediatorSDK
//
//  Created on 3/24/17.
//  Copyright © 2017 Huawei Tech. Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

#define ESPACE_CONTACT_SERVICE   @"ESpaceContactServiceAdapter"

@interface TUPMediator_ContactService : NSObject

+ (BOOL) M_imAbilityOfPerson:(id)employ;

+ (BOOL) M_presenceAbilityOfPerson:(id)employ;

+ (void) M_hideAssistentSession;

+ (id) M_createChatSessionForContact:(id)contact;

+ (id) M_creatMsgLogSessionForContact:(id)contact;

+ (id) M_callContactWithPhoneNumber:(NSString*)phoneNumber
                          inContext:(NSManagedObjectContext*)context
                         autoCreate:(BOOL) bAutoCreate;

+ (id) M_userWithAccount:(NSString*) userAccount
               inContext:(NSManagedObjectContext*) context
              autoCreate:(BOOL) bAutoCreate;

+ (id) M_customUserWithId:(NSString*)userId
                inContext:(NSManagedObjectContext*)context
                autoCreat:(BOOL)bAutoCreate;

+ (id) M_employeeCategoryWithId:(NSString*)categoryId
                      inContext:(NSManagedObjectContext*)context
                     autoCreate:(BOOL)bAutoCreate;

+ (id) M_groupWithId:(NSString*) _id
                type:(NSInteger) type
           inContext:(NSManagedObjectContext*) context autoCreate:(BOOL) bAutoCreate;

+ (id) M_systemInfoWithAppID:(NSString *)appName
                    inContex:(NSManagedObjectContext *)context
                   autoCreat:(BOOL)bAutoCreate;

+ (NSMutableDictionary *)M_nonFriendsRefreshTagsDic;

+ (void)M_employeeEntityReloadDetail:(id)entity;

//add su IM need
+ (void) M_ECS_acceptJoinInGroupWithRequest:(id)request
                            completionBlock:(void (^)(id retMsg, NSError* error)) completionBlock;
//add su IM need
+ (void) M_ECS_rejectJoinInGroupWithRequest:(id)request
                            completionBlock:(void (^)(id retMsg, NSError* error)) completionBlock;
//add su IM need
+ (void)M_addFriend:(id)person toExistedTeam:(id)team notify:(BOOL)needNotify completion:(void (^)(NSError* error)) completionBlock;

//add su IM need
+ (void)M_syncContacts:(void (^)(NSError* error)) completionBlock;

//add su IM need
+ (BOOL)M_EmployeeIsMe:(id)employee;

/**
 *  根据联系人账号查找对应的状态信息
 *
 *  @param account 联系人账号
 *  @param bForce  是否强制订阅
 *
 *  @return 状态信息
 */
+ (id)M_onlineStatusForUser:(NSString*) account forceSubscribe:(BOOL) bForce;

/**
 *  获取群组头像信息
 *
 *  @return NSMutibleSet
 */
+ (id)M_validGroupHeadImages;

+ (id)M_callNumsViaEspaceWithShowLimit:(BOOL)limit person:(id)employeeEntity;

@end
