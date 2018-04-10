//
//  ECSNetworkConfig.h
//  ECSIOSSDK
//
//  Created by huawei on 2017/1/7.
//  Copyright © 2017年 uc.huawei.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ECSLogCofig.h"

@interface ECSNetworkConfig : NSObject

@property (nonatomic, assign) BOOL isSVNEnabled;
@property (nonatomic, assign) BOOL isAnyOfficeLogin;
@property (nonatomic, assign) BOOL isMDMSSO;
@property (nonatomic, assign) ECSLogLevel appLogLevel;
@property (nonatomic, assign) BOOL isLogEnabled;
@property (nonatomic, assign) BOOL supportSsoOperation; //default YES
@property (nonatomic, copy) NSString* latestAccount;    // 最近一次鉴权账号, 可能为uPortal鉴权账号或者MAA账号
@property (nonatomic, copy) NSString* version;


+ (instancetype) sharedInstance;

@end
