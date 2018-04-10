//
//  NSURL+Export.h
//
//  Created on 4/26/15.
//  Copyright (c) 2017 Huawei Tech. Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ESpaceUMResource.h"

@interface NSURL (Export)
/**
 *  Move the file from the receiver's path to temporary path.
 *
 *  @param error Any fault will be stored in this given NSError. Pass NULL if you don't want this value.
 *
 *  @return The URL of destination folder if success, otherwise will reuturn nil.
 */
- (NSURL *)export2TemporaryDirectory:(NSError **)error;

/**
 *  A URL composed with given ext: [AppDir]/Library/Caches/Upload/[yyyy-MM-dd]/[timestampe in seconds]-[Resource count, from 0001 - 9999].ext
 *
 *  @param ext   extention name
 *  @param error Any fault will be stored in this given NSError. Pass NULL if you don't want this value.
 *
 *  @return The destination URL if success, otherwise will reuturn nil.
 */
+ (NSURL *)exportURLInCacheDirecotry:(NSString *)ext error:(NSError **)error;

/**
 *  Export the receiver's data to a temporary directory. Method will be invoked in thread created by method exportAsynchronouslyWithCompletionHandler of AVAssetExportSession. The final orientation will be transform to portrait.
 *
 *  @param completionBlock The block to invoke when current exporting is complete. error: Export error if have. umResource: Instance of ESpaceUMResource created by current ALAsset.
 */
- (void)export2TmpDir:(void (^)(NSError *error, ESpaceUMResource *umResource))completionBlock;

- (ESpaceUMAudioResource *)audioResource:(NSTimeInterval)audioDuration;

- (UIImage *)captureVideoThumbnail;

@end
