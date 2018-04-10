//
//  ESpaceAddressBookManager.h
//  eSpace
//
//  Created on 15/12/2.
//  Copyright © 2017年 Huawei Tech. Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AddressBook/AddressBook.h>

@interface ESpaceAddressBookManager : NSObject

+ (ABAddressBookRef)addressBook4CurrentThread;

@end
