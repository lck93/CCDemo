//
//  ECSLogCofig.h
//  ECSIOSSDK
//
//  Created by wangxiangyang on 11/29/16.
//  Copyright © 2016 uc.huawei.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#define _SDK_LOG_ENABLED_	1

#if _SDK_LOG_ENABLED_

//#define DEBUG_LOG_FOR_NET_TEST
#ifdef DEBUG_LOG_FOR_NET_TEST
double g_test_timer = 0.0;
#define PRINT_TIME_S(x) {\
NSLog(@"%s, %d", __FILE__, __LINE__);\
double tmpTimer = [[NSDate date] timeIntervalSince1970]; \
if(0.0 == g_test_timer) { \
g_test_timer = tmpTimer; \
}\
SDK_INFO_LOG("{Login_Debug_Log} functoin:" << __FUNCTION__ << " current:" << tmpTimer << ", last:" << g_test_timer << ", timeInterval:" << tmpTimer-g_test_timer);\
if ((x)) { \
g_test_timer = tmpTimer;\
}\
}

#define PRINT_TIME() PRINT_TIME_S(0)
#else
#define PRINT_TIME_S(x)
#define PRINT_TIME()
#endif

#define SDK_LOG_TAG				"SDK"
#define SDK_ERROR_LOG(msg)		ECS_USER_ERROR_LOG(SDK_LOG_TAG, msg)
#define SDK_WRN_LOG(msg)		ECS_USER_WARN_LOG(SDK_LOG_TAG, msg)
#define SDK_INFO_LOG(msg)		ECS_USER_INFO_LOG(SDK_LOG_TAG, msg)
#define SDK_DEBUG_LOG(msg)		ECS_USER_DEBUG_LOG(SDK_LOG_TAG, msg)
#define SDK_VERBOSE_LOG(msg)	ECS_USER_VERBOSE_LOG(SDK_LOG_TAG, msg)
#define SDK_TRACE()				CTK_TRACE()

#else

#define SDK_ERROR_LOG(msg)
#define SDK_INFO_LOG(msg)
#define SDK_DEBUG_LOG(msg)
#define SDK_VERBOSE_LOG(msg)
#define SDK_TRACE()

#endif

/* define of log level enum */
typedef enum
{
    kECSLogDebug	= 0,
    kECSLogInfo		= 1,
    kECSLogError	= 2,
    kECSLogVerbose	= 3,
    kECSLogUnknown	= -1,
}ECSLogLevel;

@interface ECSLogCofig : NSObject

/**
 *  设置SDK日志级别
 *
 *  @param level 日志级别
 */
-(void)setLoggerLevel:(ECSLogLevel)level;

@end
