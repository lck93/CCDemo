//
//  ECSUMService.h
//  eSpaceIOSSDK
//
//  Created on 15/4/23.
//  Copyright (c) 2015年 Huawei Tech. Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, ECSUMResourceCatalog) {
    ECSUMResourceInternal,
    ECSUMResourcePublic,
    ECSUMResourceEmail
};

@protocol ECSUMServiceProtocol <NSObject>

- (void)UMAudioPlayEnd;

@end

@interface ECSUMService : NSObject
@property (nonatomic, weak)id<ECSUMServiceProtocol> UMServiceDelegate;
@property (nonatomic, strong, readonly) NSThread* workThread;
+ (instancetype) sharedInstance;

/**
 *  [en]
 *  [cn]发起富媒体上传请求
 *
 *  @param filePath        文件路径
 *  @param progress        进度
 *  @param fileType        文件类型
 *  @param completionBlock 结果回调
 *
 *  @return 请求Operation
 */
- (NSOperation*) upload:(NSString *)filePath
               progress:(NSProgress*) progress
               fileType:(NSString*)fileType
        completionBlock:(void (^)(NSError* error,
                                 NSString* url,
                                  NSString* fileId,
                                 NSString* accessCode)) completionBlock;

/**
 *  [en]
 *  [cn]发起富媒体下载请求
 *
 *  @param url             下载地址
 *  @param catalog         下载策略
 *  @param encrypt         是否加密
 *  @param progress        进度
 *  @param accessCode      提取码
 *  @param bThumbnial      是否是缩略图
 *  @param width           宽
 *  @param height          高
 *  @param localPath       本地路径
 *  @param fileName        文件名称
 *  @param completionBlock 结果回调
 *
 *  @return 请求Operation
 */
- (NSOperation*) download:(NSString*)url
                  catalog:(ECSUMResourceCatalog)catalog
                  encrypt:(BOOL)encrypt
                 progress:(NSProgress *)progress
               accessCode:(NSString*) accessCode
               bThumbnial:(BOOL) bThumbnial
                    width:(NSInteger) width
                   height:(NSInteger) height
                localPath:(NSString*) localPath
                 fileName:(NSString*) fileName
          completionBlock:(void (^)(NSError* error,NSString *fileId)) completionBlock;

/**
 *  [en]
 *  [cn]删除富媒体
 *
 *  @param fileIdOrURL     文件ID或者路径
 *  @param completionBlock 结果回调
 *
 *  @return 请求Operation
 */
- (NSOperation*) deleted:(NSString*)fileIdOrURL
         completionBlock:(void(^)(NSError *error)) completionBlock;

/**
 *  [en]
 *  [cn]语音录制
 *
 *  @param Localpath 存放路径
 *
 *  @return 接口是否调用成功
 */
- (BOOL)startRecordLocalAudioToPath:(NSString *)Localpath;

/**
 *  [en]
 *  [cn]停止录音
 *
 *  @return 接口是否调用成功
 */
- (BOOL)stopRecordLocalAudio;

/**
 *  [en]
 *  [cn]播放语音
 *
 *  @param fileName <#fileName description#>
 *  @param loops    <#loops description#>
 *  @param tagID    <#tagID description#>
 *
 *  @return 接口是否调用成功
 */
- (BOOL)startPlayLocalAudioFileWithName:(NSString *)fileName andNeedloops:(NSInteger)loops generateTagID:(NSMutableString *)tagID;

/**
 *  [en]
 *  [cn]停止播放语音
 *
 *  @param tagID <#tagID description#>
 *
 *  @return 接口是否调用成功
 */
- (BOOL)stopPlayLocalAudioFileWithTagId:(NSString *)tagID;

/**
 *  [en]
 *  [cn]设置播放音量
 *
 *  @param volume <#volume description#>
 *
 *  @return 接口是否调用成功
 */
- (BOOL)localAudioDeviceVolumeValue:(NSInteger *)volume;

/**
 *  [en]
 *  [cn]tup http模块是否初始化
 *
 *  @return 是／否
 */
-(BOOL)isUMInit;


/**
 *  [en]
 *  [cn]tup 初始化tup http模块
 *
 *  @return 是／否
 */
-(BOOL)initCloudStore;


/**
 *  [en]
 *  [cn]um下线，umservice模块会在下次判断时认为需要重新登录
 */
-(void)umLogOff;

@end
