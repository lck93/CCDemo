//
//  NSObject+Hook.h
//
//  Created on 16/2/19.
//  Copyright © 2017年 Huawei Tech. Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (Hook)

void exchangeMethodImplementation(Class _class, SEL oldSEL, SEL newSEL);

@end
