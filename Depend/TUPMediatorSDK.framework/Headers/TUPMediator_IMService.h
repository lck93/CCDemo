//
//  TUPMediator_IMService.h
//  TUPMediatorSDK
//
//  Created on 3/24/17.
//  Copyright © 2017 Huawei Tech. Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

#define ESPACE_IM_SERVICE   @"ESpaceIMServiceAdapter"

@interface TUPMediator_IMService : NSObject

+ (void)M_getMsgLogWithRequest:(id) request
               completionBlock:(void (^)(id retMsg, NSError* error)) completionBlock;

+ (id)M_createMessageForSession:(id) session
                      timestamp:(NSDate*) date
                           flag:(NSInteger) flag
                         readed:(BOOL) readed;

+ (void)M_markReadRequest:(NSInteger)type
                 targetId:(NSString *)targetId
                    msgId:(NSString *)msgId
               newMsgType:(NSInteger)newType;

+ (NSInteger)M_contentTypeFromServerValue:(NSInteger)type
                                  content:(NSString*)content;

@end
