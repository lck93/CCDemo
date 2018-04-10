/**
 * @file TupContactService.h
 *
 * Copyright © 2017 Huawei Tech. Co., Ltd. All rights reserved. \n
 *
 * @brief [en]Description:TUP contact basic service function class head file.
 * [cn]描述：TUP 联系人基础业务功能类头文件。 \n
 **/

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import <TUPIOSSDK/ECSDefines.h>

ECS_EXTERN NSString* const TUP_USER_STATUS_CHANGED;
ECS_EXTERN NSString* const TUP_USER_STATUS_CHANGED_BY_ACCOUNT;
ECS_EXTERN NSString* const TUP_CONTACT_FULL_SYNC_FINISHED;
ECS_EXTERN NSString* const TUPAddFriendNotify;
ECS_EXTERN NSString* const TUPAddFriendNotify_TitleKey;


@class EmployeeEntity;
@class CustomContactEntity;
@class ChatSessionEntity;
@class ContactEntity;
@class EmployeeCategoryEntity;
@class GroupEntity;
@class EspaceUserOnlineStatus;
@class AssistantMessageEntity;



/**
 * [en] This class is about contact basic service .
 * [cn] 联系人基础业务功能类
 **/
@interface TupContactService : NSObject

@property (nonatomic, strong, readonly) NSMutableSet * validGroupHeadImages;


/**
 * @brief [en] This method is used to get shared instance objects .
 *        <br>[cn] 获取共享实例对象
 *
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
+ (instancetype) sharedInstance;

/**
 * @brief [en]This method is used to judge whether a contact has IM privileges .
 *        <br>[cn] 判断某个联系人是否有IM权限
 *
 * @param [in] EmployeeEntity* employ    <b>:</b><br>[en] Indicates contact object .
 *                                               <br>[cn] 联系人对象
 * @retval BOOL *                        <b>:</b><br>[en] Indicates true return yes false return no.
 *                                               <br>[cn] 是返回YES，否返回NO
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
+ (BOOL)imAbilityOfPerson:(EmployeeEntity*)employ;

/**
 * @brief [en]This method is used to judge whether there is authority .
 *        <br>[cn] 判断某个联系人是否有状态权限
 *
 * @param [in] EmployeeEntity* employ    <b>:</b><br>[en] Indicates contact object.
 *                                               <br>[cn] 联系人对象
 * @retval BOOL *                        <b>:</b><br>[en] Indicates true return yes false return no.
 *                                               <br>[cn] 是返回YES，否返回NO
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
+ (BOOL)presenceAbilityOfPerson:(EmployeeEntity*)employ;

/**
 * @brief [en]This method is used to hidden assistant .
 *        <br>[cn] 隐藏小e助手session
 *
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
- (void) hideAssistentSession;

/**
 * @brief [en]This method is used to generate contacts based on contact accounts .
 *        <br>[cn] 根据联系人账号生成联系人
 *
 * @param [in] NSString* userAccount              <b>:</b><br>[en] Indicates contact account .
 *                                                        <br>[cn] 联系人账号
 * @param [in] NSManagedObjectContext* context    <b>:</b><br>[en] Indicates context .
 *                                                        <br>[cn] 上下文
 * @param [in] BOOL* bAutoCreate                  <b>:</b><br>[en] Indicates automatic creation .
 *                                                        <br>[cn] 是否自动创建
 * @retval EmployeeEntity *                       <b>:</b><br>[en] Indicates success return contact object fail return nil.
 *                                                        <br>[cn] 成功返回联系人对象，失败返回nil
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
- (EmployeeEntity*) userWithAccount:(NSString*) userAccount
                          inContext:(NSManagedObjectContext*) context
                         autoCreate:(BOOL) bAutoCreate;

/**
 * @brief [en]This method is used to according to user id create custom contacts .
 *        <br>[cn] 根据用户id创建自定义联系人
 *
 * @param [in] NSString* userId                   <b>:</b><br>[en] Indicates user id.
 *                                                        <br>[cn] 用户id
 * @param [in] NSManagedObjectContext* context    <b>:</b><br>[en] Indicates context.
 *                                                        <br>[cn] 上下文
 * @param [in] BOOL* bAutoCreate                  <b>:</b><br>[en] Indicates whether automatic create.
 *                                                        <br>[cn] 是否自动创建
 * @retval CustomContactEntity *                  <b>:</b><br>[en] Indicates success return custom contacts object fail return nil.
 *                                                        <br>[cn] 成功返回自定义联系人对象，失败返回nil
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
- (CustomContactEntity*) customUserWithId:(NSString*)userId
                                inContext:(NSManagedObjectContext*)context
                                autoCreat:(BOOL)bAutoCreate;

/**
 * @brief [en]This method is used to create groups according to grouping ID .
 *        <br>[cn] 根据分组id创建分组
 *
 * @param [in] NSString* categoryId               <b>:</b><br>[en] Indicates grouping ID.
 *                                                        <br>[cn] 分组id
 * @param [in] NSManagedObjectContext* context    <b>:</b><br>[en] Indicates context.
 *                                                        <br>[cn] 上下文
 * @param [in] BOOL* bAutoCreate                  <b>:</b><br>[en] Indicates automatic creation.
 *                                                        <br>[cn] 是否自动创建
 * @retval EmployeeCategoryEntity *               <b>:</b><br>[en] Indicates success return grouping object fail return nil.
 *                                                        <br>[cn] 成功返回分组对象，失败返回nil
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
- (EmployeeCategoryEntity*) employeeCategoryWithId:(NSString*)categoryId
                                         inContext:(NSManagedObjectContext*)context
                                        autoCreate:(BOOL)bAutoCreate;

/**
 * @brief [en]This method is used to create groups according to grouping ID .
 *        <br>[cn] 根据群组id创建群组
 *
 * @param [in] NSString* _id                      <b>:</b><br>[en] Indicates grouping ID.
 *                                                        <br>[cn] 群组id
 * @param [in] NSInteger* type                    <b>:</b><br>[en] Indicates group type 0:fixed group 1:discussion group.
 *                                                        <br>[cn] 群组类型，0是固定群 1是讨论组
 * @param [in] NSManagedObjectContext* context    <b>:</b><br>[en] Indicates context.
 *                                                        <br>[cn] 上下文
 * @param [in] BOOL* bAutoCreate                  <b>:</b><br>[en] Indicates automatic creation.
 *                                                        <br>[cn] 是否自动创建
 * @retval EmployeeCategoryEntity *               <b>:</b><br>[en] Indicates success return groups object fail return nil.
 *                                                        <br>[cn] 成功返回群组对象，失败返回nil
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
- (GroupEntity*) groupWithId:(NSString*) _id
                        type:(NSInteger) type
                   inContext:(NSManagedObjectContext*) context autoCreate:(BOOL) bAutoCreate;

/**
 * @brief [en]This method is used to find groups based on group ID .
 *        <br>[cn] 根据群组id查找群组
 *
 * @param [in] NSString* _id                      <b>:</b><br>[en] Indicates group ID.
 *                                                        <br>[cn] 群组id
 * @param [in] NSManagedObjectContext* context    <b>:</b><br>[en] Indicates context.
 *                                                        <br>[cn] 上下文
 * @retval EmployeeCategoryEntity *               <b>:</b><br>[en] Indicates success return groups object fail return nil.
 *                                                        <br>[cn] 成功返回群组对象，失败返回nil
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
- (GroupEntity*) groupWithId:(NSString*) _id inContext:(NSManagedObjectContext *)context;

/**
 * @brief [en]This method is used to full volume synchronous contact .
 *        <br>[cn] 是否需要全量同步联系人
 *
 * @retval BOOL *                        <b>:</b><br>[en] Return yes if true, false return no. .
 *                                               <br>[cn] 是返回YES，否返回NO
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
- (BOOL) needFullSyncContacts;

/**
 * @brief [en]This method is used to full volume synchronous contact.
 *        <br>[cn] 全量同步联系人
 *
 * @param [out] completionBlock        <b>:</b><br>[en] Indicates handle result block carry error message.
 *                                             <br>[cn] 处理结果Block，携带错误信息(NSError*)
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
- (void) fullSyncContacts:(void (^)(NSError* error)) completionBlock;

/**
 * @brief [en]This method is used to incremental synchronization contact.
 *        <br>[cn] 增量同步联系人
 *
 * @param [out] completionBlock        <b>:</b><br>[en] Indicates handle result block carry error message.
 *                                             <br>[cn] 处理结果Block，携带错误信息(NSError*)
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
- (void) partialSyncContacts:(void (^)(NSError* error)) completionBlock;

/**
 * @brief [en]This method is used to sync contacts .
 *        <br>[cn] 同步联系人
 *
 * @param [out] completionBlock        <b>:</b><br>[en] Indicates handle result block carry error message.
 *                                             <br>[cn] 处理结果Block，携带错误信息(NSError*)
 * @attention [en] Indicates internal will automatically determine the full volume synchronous or incremental synchronization .
 *            <br>[cn] 内部会自动判断全量同步还是增量同步
 * @see NA
 **/
- (void) syncContacts:(void (^)(NSError* error)) completionBlock;

/**
 * @brief [en]This method is used to query contact status .
 *        <br>[cn] 查询联系人状态信息
 *
 * @param [in] NSString* account      <b>:</b><br>[en] Indicates contact account .
 *                                            <br>[cn] 联系人账号
 * @param [in] BOOL* bForce           <b>:</b><br>[en] Indicates is push subscription .
 *                                            <br>[cn] 是否强制订阅
 * @retval EspaceUserOnlineStatus *   <b>:</b><br>[en] Indicates success return contact status object fail return nil.
 *                                            <br>[cn] 成功返回状态信息对象，失败返回nil
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
- (EspaceUserOnlineStatus*) onlineStatusForUser:(NSString*) account forceSubscribe:(BOOL) bForce;

/**
 * @brief [en]This method is used to query contact status.
 *        <br>[cn] 查询联系人状态信息
 *
 * @param [in] NSString* account      <b>:</b><br>[en] Indicates contact account.
 *                                            <br>[cn] 联系人账号
 * @retval EspaceUserOnlineStatus *   <b>:</b><br>[en] Indicates success return contact status object fail return nil.
 *                                            <br>[cn] 成功返回联系人状态对象，失败返回nil
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
- (EspaceUserOnlineStatus*) onlineStatusForUser:(NSString*) account;

/**
 * @brief [en]This method is used to generate e assistant prompt information .
 *        <br>[cn] 生成小e助手提示信息
 *
 * @param [in] NSString* msgId                  <b>:</b><br>[en] Indicates message id.
 *                                                      <br>[cn] 消息id
 * @param [in] NSDate* timestamp                <b>:</b><br>[en] Indicates time.
 *                                                      <br>[cn] 时间
 * @param [in] BOOL* readed                     <b>:</b><br>[en] Indicates is read .
 *                                                      <br>[cn] 是否已读
 * @param [in] NSManagedObjectContext* ctx      <b>:</b><br>[en] Indicates context.
 *                                                      <br>[cn] 上下文
 * @retval AssistantMessageEntity *             <b>:</b><br>[en] Indicates success return prompt information object fail return nil.
 *                                                      <br>[cn] 成功返回小e助手提示信息对象，失败返回nil
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
- (AssistantMessageEntity*) createAssistantMessageWithId:(NSString*) msgId timestamp:(NSDate*)timestamp readed:(BOOL)readed inContext:(NSManagedObjectContext*) ctx;

/**
 * @brief [en]This method is used to create group .
 *        <br>[cn] 创建群组
 *
 * @param [in] NSString* groupName              <b>:</b><br>[en] Indicates group name.
 *                                                      <br>[cn] 群名称
 * @param [in] NSString* enName                 <b>:</b><br>[en] Indicates english group name.
 *                                                      <br>[cn] 英文群组名
 * @param [in] NSArray* users                   <b>:</b><br>[en] Indicates invite user list .
 *                                                      <br>[cn] 邀请用户列表
 * @param [in] NSString* announce               <b>:</b><br>[en] Indicates group declaration .
 *                                                      <br>[cn] 群组声明
 * @param [in] NSString* intro                  <b>:</b><br>[en] Indicates group profiles .
 *                                                      <br>[cn] 群组简介
 * @param [out] completionBlock                 <b>:</b><br>[en] Indicates treatment result block carry error message,group id user information
 *                                                      <br>[cn] 处理结果Block，携带群id、邀请失败的用户和错误信息(NSString*, NSString*, NSError*)
 * @attention [en] Indicates support incoming member objects for creation .
 *            <br>[cn] 支持传入成员对象进行创群。邀请失败的用户，用户之间用分号隔开
 * @see NA
 */
- (void) createGroupWithName:(NSString*) groupName
                      enName:(NSString*) enName
                   initUsers:(NSArray *) users
                    announce:(NSString*) announce
                       intro:(NSString*) intro
                  completion:(void (^)(NSString* groupId, NSString* failedList, NSError* error)) completionBlock;

/**
 * @brief [en]This method is used to create group.
 *        <br>[cn] 创建群组
 *
 * @param [in] NSString* groupName              <b>:</b><br>[en] Indicates group name.
 *                                                      <br>[cn] 群名称
 * @param [in] NSString* enName                 <b>:</b><br>[en] Indicates english group name.
 *                                                      <br>[cn] 英文群组名
 * @param [in] NSArray* userAccounts            <b>:</b><br>[en] Indicates invite user list.
 *                                                      <br>[cn] 邀请用户列表
 * @param [in] NSString* announce               <b>:</b><br>[en] Indicates group declaration.
 *                                                      <br>[cn] 群组声明
 * @param [in] NSString* intro                  <b>:</b><br>[en] Indicates group profiles.
 *                                                      <br>[cn] 群组简介
 * @param [out] completionBlock                 <b>:</b><br>[en] Indicates treatment result block carry error message,group id user information.
 *                                                      <br>[cn] 处理结果Block，携带群id、邀请失败的用户和错误信息(NSString*, NSString*, NSError*)
 * @attention [en] Indicates support incoming member objects for creation.
 *            <br>[cn] 支持传入成员账号进行创群。邀请失败的用户，用户之间用分号隔开
 */
- (void) createGroupWithName:(NSString*) groupName
                      enName:(NSString*) enName
             userAccountList:(NSArray *) userAccounts
                    announce:(NSString*) announce
                       intro:(NSString*) intro
                  completion:(void (^)(NSString* groupId, NSString* failedList, NSError* error)) completionBlock;

/**
 * @brief [en]This method is used to query enterprise directory contacts .
 *        <br>[cn] 查询企业通讯录联系人
 *
 * @param [in] NSString* keyword                <b>:</b><br>[en] Indicates keyword .
 *                                                      <br>[cn] 关键字
 * @param [in] NSInteger pageIndex              <b>:</b><br>[en] Indicates page number.
 *                                                      <br>[cn] 页码
 * @param [in] NSInteger pageSize               <b>:</b><br>[en] Indicates display number per page .
 *                                                      <br>[cn] 每页显示数目
 * @param [in] NSString* field                  <b>:</b><br>[en] Indicates eSpaceNumber,bindno,staffNo.
 *                                                      <br>[cn] 区域:eSpaceNumber,bindno,staffNo三个字段
 * @param [in] BOOL bShow                       <b>:</b><br>[en] Indicates display status .
 *                                                      <br>[cn] 是否显示状态
 * @param [in] NSInteger searchFlag             <b>:</b><br>[en] Indicates search type 0:default 1:accurate .
 *                                                      <br>[cn] 搜索类型，取值：0:默认匹配 1:精确匹配
 * @param [in] NSManagedObjectContext* ctx      <b>:</b><br>[en] Indicates context.
 *                                                      <br>[cn] 上下文
 * @param [out] completionBlock                 <b>:</b><br>[en] Indicates handle result block carry error message and query result quantity .
 *                                                      <br>[cn] 处理结果Block，携带错误信息和查询结果数量(NSError*, NSInteger)
 */
- (void) queryCorpAdressBook:(NSString*) keyword
                   pageIndex:(NSInteger) pageIndex
                    pageSize:(NSInteger) pageSize
                       field:(NSString*) field
                  showStatus:(BOOL) bShow
                  searchFlag:(NSInteger) searchFlag
                   inContext:(NSManagedObjectContext*) ctx
                  completion:(void (^)(NSError* error, NSInteger count)) completionBlock;

/**
 * @brief [en]This method is used to add strangers to already grouped .
 *        <br>[cn] 添加陌生人到已有到分组
 *
 * @param [in] EmployeeEntity* person           <b>:</b><br>[en] Indicates people to be added .
 *                                                      <br>[cn] 待添加的人
 * @param [in] NSString* teamName               <b>:</b><br>[en] Indicates target grouping .
 *                                                      <br>[cn] 要添加到的分组
 * @param [in] BOOL needNotify                  <b>:</b><br>[en] Indicates is need notice .
 *                                                      <br>[cn] 是否需要通知
 * @param [out] completionBlock                 <b>:</b><br>[en] Indicates handle result block carry error message.
 *                                                      <br>[cn] 处理结果Block，携带错误信息(NSError*)
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 */
- (void)addFriend:(EmployeeEntity*)person toExistedTeam:(EmployeeCategoryEntity*)team notify:(BOOL)needNotify completion:(void (^)(NSError* error)) completionBlock;

/**
 * @brief [en]This method is used to add strangers to new build packet .
 *        <br>[cn] 添加陌生人到新创建分组
 *
 * @param [in] EmployeeEntity* person           <b>:</b><br>[en] Indicates people to be added.
 *                                                      <br>[cn] 待添加的人
 * @param [in] NSString* teamName               <b>:</b><br>[en] Indicates target grouping.
 *                                                      <br>[cn] 要添加到的分组
 * @param [in] BOOL needNotify                  <b>:</b><br>[en] Indicates is need notice.
 *                                                      <br>[cn] 是否需要通知
 * @param [out] completionBlock                 <b>:</b><br>[en] Indicates handle result block carry error message.
 *                                                      <br>[cn] 处理结果Block，携带错误信息(NSError*)
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 */
- (void)addFriend:(EmployeeEntity *)person toNewTeam:(NSString *)teamName notify:(BOOL)needNotify completion:(void (^)(NSError *))completionBlock;

/**
 * @brief [en]This method is used to add strangers to already grouped.
 *        <br>[cn] 添加陌生人到已知分组
 *
 * @param [in] NSString* account                <b>:</b><br>[en] Indicates unknown contact account.
 *                                                      <br>[cn] 陌生人联系人账号
 * @param [in] NSString* teamID                 <b>:</b><br>[en] Indicates contact group id
 *                                                      <br>[cn] 联系人分组id
 * @param [in] BOOL needNotify                  <b>:</b><br>[en] Indicates is notify the other party .
 *                                                      <br>[cn] 是否通知对方被加为好友
 * @param [out] completionBlock                 <b>:</b><br>[en] Indicates handle result block carry error message.
 *                                                      <br>[cn] 处理结果Block，携带错误信息(NSError*)
 * @attention [en] If the database is in contact, you can call the addFriend: method directly, and both EmployeeEntity and EmployeeCategoryEntity must be objects in the database NSManagedObjectContext .
 *            <br>[cn] 数据库存在联系人则可以直接调用以上的addFriend:方法，且EmployeeEntity和EmployeeCategoryEntity都必须是数据库NSManagedObjectContext中的对象；
 *            <br>[cn] 否则调用当前方法来自动在数据库创建联系人并同步联系人信息
 * @see NA
 */
- (void)addFriendWith:(NSString*)account toExistedTeam:(NSString*)teamID notify:(BOOL)needNotify completion:(void (^)(NSError* error)) completionBlock;


/**
 * @brief [en]This method is used to add strangers to new group .
 *        <br>[cn] 添加陌生人到新建分组
 *
 * @param [in] NSString* account                <b>:</b><br>[en] Indicates unknown contact account.
 *                                                      <br>[cn] 陌生人联系人账号
 * @param [in] NSString* teamName               <b>:</b><br>[en] Indicates new grouping name.
 *                                                      <br>[cn] 新建分组名
 * @param [in] BOOL needNotify                  <b>:</b><br>[en] Indicates notify the other party to be a friend .
 *                                                      <br>[cn] 是否通知对方被加为好友
 * @param [out] completionBlock                 <b>:</b><br>[en] Indicates treatment result block carry error message.
 *                                                      <br>[cn] 处理结果Block，携带错误信息(NSError*)
 * @attention [en] If the database is in contact, you can call the addFriend: method directly, and both EmployeeEntity and EmployeeCategoryEntity must be objects in the database NSManagedObjectContext .
 *            <br>[cn] 数据库存在联系人则可以直接调用以上的addFriend:方法，且EmployeeEntity和EmployeeCategoryEntity都必须是数据库NSManagedObjectContext中的对象
 *            <br>[cn] 否则调用当前方法来自动在数据库创建联系人并同步联系人信息
 * @see NA
 */
- (void)addFriendWith:(NSString *)account toNewTeam:(NSString *)teamName notify:(BOOL)needNotify completion:(void (^)(NSError *error))completionBlock;


/**
 * @brief [en]This method is used to delete buddy .
 *        <br>[cn] 删除好友
 *
 * @param [in] EmployeeEntity* person           <b>:</b><br>[en] Indicates friends to be deleted 
 *                                                      <br>[cn] 待删除的好友
 * @param [in] NSError* error                   <b>:</b><br>[en] Indicates error code.
 *                                                      <br>[cn] 错误码
 * @param [out] completionBlock                 <b>:</b><br>[en] Indicates treatment result block carry error message.
 *                                                      <br>[cn] 处理结果Block，携带错误信息(NSError*)
 */
- (void)deleteFriend:(EmployeeEntity*)person completion:(void (^)(NSError *error))completionBlock;

/**
 * @brief [en]This method is used to copy the employee in memory only to the database .
 *        <br>[cn] 将只存在内存中的employee拷贝到数据库中
 *
 * @param [in] EmployeeEntity* memoryUser          <b>:</b><br>[en] Indicates memory object.
 *                                                         <br>[cn] 内存对象
 * @retval EmployeeEntity *                        <b>:</b><br>[en] Indicates success return objects created in the database  fail return nil.
 *                                                         <br>[cn] 成功返回数据库中创建的的对象，失败返回nil
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
- (EmployeeEntity*)employeeFromCopyMemoryUser:(EmployeeEntity*)memoryUser;

#pragma mark - contact search history record

/**
 * @brief [en]This method is used to insert the search record .
 *        <br>[cn] 插入搜索到的记录
 *
 * @param [in] ContactEntity* insertContact        <b>:</b><br>[en] Indicates memory object.
 *                                                         <br>[cn] 内存对象
 * @retval ContactEntity *                         <b>:</b><br>[en] Indicates success return objects created in the database  fail return nil.
 *                                                         <br>[cn] 成功返回数据库中创建的的对象，失败返回nil
 * @attention [en] Indicates 10 bars at most .
 *            <br>[cn] 最多10条
 * @see NA
 **/
- (ContactEntity *)insertSearchHistoryRecord:(ContactEntity *)insertContact;


/**
 * @brief [en]This method is used to query, search, and save local history .
 *        <br>[cn] 查询搜索过并保存在本地的历史记录,
 *
 * @retval NSArray *                <b>:</b><br>[en] Indicates search history no return nil.
 *                                          <br>[cn] 返回搜索过的历史记录(ContactEntity *)，无则返回nil
 * @attention [en] Indicates 10 bars at most
 *            <br>[cn] 最多10条
 * @see NA
 **/
- (NSArray *)querySearchHistoryRecord;

/**
 * @brief [en]This method is used to clear search history .
 *        <br>[cn] 清空搜索历史纪录
 *
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
- (void)clearQuerySearchHistoryRecord;
@end
