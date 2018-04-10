//
//  IDeskNetworkReachability.h
//  iDeskAPI
//
//  Created by yemingxing on 6/23/14.
//  Copyright (c) 2014 www.huawei.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SystemConfiguration/SystemConfiguration.h>
#import <netinet/in.h>

typedef NS_ENUM(NSInteger, ECSReachabilityStatus) {
	ECSNotReachable = 0,
	ECSReachableViaWiFi,
	ECSReachableViaWWAN,
    ECSReachableVia3G,
    ECSReachableVia2G
};

extern NSString *kECSReachabilityChangedNotification;

@interface ECSNetworkReachability : NSObject

/*!
 * Use to check the reachability of a given host name.
 */
+ (instancetype)reachabilityWithHostName:(NSString *)hostName;

/*!
 * Use to check the reachability of a given IP address.
 */
+ (instancetype)reachabilityWithAddress:(const struct sockaddr *)hostAddress;

/*!
 * Checks whether the default route is available. Should be used by applications that do not connect to a particular host.
 */
+ (instancetype)reachabilityForInternetConnection;

/*!
 * Checks whether a local WiFi connection is available.
 */
+ (instancetype)reachabilityForLocalWiFi;

/*!
 * Start listening for reachability notifications on the current run loop.
 */
- (BOOL)startNotifier;
- (void)stopNotifier;
- (void)setHostName:(NSString *)hostName;

@property(readonly, assign, nonatomic) ECSReachabilityStatus currentReachabilityStatus;
@property(readonly, assign, nonatomic) SCNetworkReachabilityFlags networkReachabilityFlags;

/*!
 * WWAN may be available, but not active until a connection has been established. WiFi may require a connection for VPN on Demand.
 */
- (BOOL)connectionRequired;

@end
