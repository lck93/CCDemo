//
//  ESpaceVersionSwitchHelper.h
//  
//
//  Created on 15/9/24.
//
//

#import <Foundation/Foundation.h>
#import "ECSUtils.h"

#define ReplaceNULL2Empty2(str)      ((nil == (str)) ? @"" : (str))
#define DelimSpace2(str)             ((NULL == (str)) ? "" : (str))

#define DB_DATA_ENCRYPT(data)			([ECSUtils databaseDataEncrypt:ReplaceNULL2Empty2(data)])
#define DB_DATA_DECRYPT(data)			([ECSUtils databaseDataDecrypt:(data)])

#define DB_TEXT_DATA_DECRYPT(statement, columnNum) (DB_DATA_DECRYPT([NSString stringWithUTF8String:DelimSpace2((const char*)sqlite3_column_text(statement, columnNum))]))

#define DB_GET_TEXT_DATA_DECRYPT(statement, columnNum) (DB_DATA_DECRYPT([NSString stringWithUTF8String:DelimSpace2((const char*)sqlite3_column_text(statement, columnNum))]))

#define DB_GET_TEXT_DATA(statement, columnNum) ([NSString stringWithUTF8String:DelimSpace2((const char*)sqlite3_column_text(statement, columnNum))])

@interface ESpaceVersionSwitchHelper : NSObject
@property (nonatomic, retain)NSMutableDictionary* localManagersForDbUpdate;//key:account;value:localManager
@property (nonatomic, assign)BOOL isUpdating;

+ (instancetype)sharedInstance;
/**
 *  Document路径地址
 *
 *  @return 地址
 */
+ (NSString*)appDocumentsPath;

/**
 *  是否需要进行数据库前移
 *
 *  @return 是否需要
 */
+ (BOOL)needDBVisionSwitch;
/**
 *  数据库文件夹路径
 *
 *  @return 路径
 */
+ (NSString*)databaseFolderPath;
/**
 *  数据库文件夹下的文件列表
 *
 *  @return 文件列表
 */
+ (NSArray*)databaseFilesList;

/**
 *  清空旧版本的数据库
 */
+ (void)deleteOldDBData;

@end
