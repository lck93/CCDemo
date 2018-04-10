//
//  TUPMediator.h
//  TUPMediatorSDK
//
//  Created on 3/24/17.
//  Copyright © 2017 Huawei Tech. Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TUPMediator : NSObject

+ (instancetype)sharedInstance;

- (void)startBusinessService;

@end
