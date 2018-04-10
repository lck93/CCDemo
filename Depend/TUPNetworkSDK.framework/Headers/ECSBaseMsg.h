//
//  ECSBaseMsg.h
//  eSpaceIOSSDK
//
//  Created by yemingxing on 3/9/15.
//  Copyright (c) 2015 huawei. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ECSDefaultAckMsg : NSObject
@property (nonatomic, assign) short retval;
@property (nonatomic, copy) NSString* desc;
@end

@interface ECSErrorQueryError : NSObject
@property (nonatomic, assign) NSInteger code;
@property (nonatomic, copy) NSString* text;
@end

@interface ECSErrorQuery : NSObject
@property (nonatomic, copy) NSString* type;
@property (nonatomic, strong) ECSErrorQueryError* error;
@end

@interface ECSErrorMsg : NSObject
@property (nonatomic, copy) NSString* type;
@property (nonatomic, strong) ECSErrorQuery* query;
@end


@interface ECSRootErrorMsg : ECSDefaultAckMsg

@end

@interface ECSIqErrorMsg : ECSErrorMsg

@end

@interface ECSMessageErrorMsg : ECSErrorMsg

@end

@interface ECSPresenceErrorMsg : ECSErrorMsg

@end

@interface ECSQueryErrorMsg : NSObject

@end