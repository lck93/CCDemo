/**
 * @file ESpaceMediaService.h
 *
 * Copyright (c) 2015 Huawei Tech. Co., Ltd. All rights reserved. \n
 *
 * @brief [en]Description:Media file service operation  class head file.
 * [cn]描述：媒体文件业务操作类头文件。 \n
 **/

#import <Foundation/Foundation.h>
#import "ESpaceUMResource.h"

@class ESpaceMediaService;
@protocol ESpaceMediaServiceDelegate <NSObject>

/**
 * @brief [en] This method is used to finish media resource file.
 *        <br>[cn] 结束媒体资源文件
 *
 * @param [in] ESpaceMediaService* mediaService     <b>:</b><br>[en] Indicates media resource file.
 *                                                          <br>[cn] 媒体资源对象
 * @param [in] BOOL force                           <b>:</b><br>[en] Indicates whether force stop.
 *                                                          <br>[cn] 是否强制停止
 * @attention [en] Tell UI finish playing media file.
 *            <br>[cn] 委托告诉UI播放媒体资源文件结束
 * @see NA
 **/
- (void)espaceMediaServiceDidFinishPlaying:(ESpaceMediaService *)mediaService force:(BOOL)force;

@end

/**
 * [en] This class is about media resouce file operation.
 * [cn] 媒体资源文件操作类
 **/
@interface ESpaceMediaService : NSObject

@property (nonatomic, weak) id<ESpaceMediaServiceDelegate>delegate;
@property (nonatomic, assign) NSInteger inputAudioVolume; // A range from 0 to 10.
@property (nonatomic, strong, readonly) ESpaceUMAudioResource *playingAudioResource;

/**
 * @brief [en] This method is used to get instance object.
 *        <br>[cn] 获取单例对象
 *
 * @retval instancetype                           <b>:</b><br>[en] Return an instance object .
 *                                                        <br>[cn] 返回一个单例对象
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
+ (instancetype) sharedInstance;


/**
 * @brief [en] This method is used to prepare play new audio.
 *        <br>[cn] 准备播放新的音频文件
 *
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
- (void)preparePlayNewAudio;


/**
 * @brief [en] This method is used to prepare record new audio.
 *        <br>[cn] 准备录制新的音频文件
 *
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
- (void)prepareRecordNewAudio;


/**
 * @brief [en] This method is used to judge whether loop play local audio file.
 *        <br>[cn] 判断是否循环播放本地音频文件
 *
 * @param [in] NSString* fileName   <b>:</b><br>[en] Indicates file name.
 *                                          <br>[cn] 文件路径
 * @param [in] NSInteger loops      <b>:</b><br>[en] Indicates whether loop, 0:loop, more than 0:not loop.
 *                                          <br>[cn] 是否循环，0：循环；大于0不循环
 * @retval BOOL                     <b>:</b><br>[en] Return interface invoked result, true return yes, or return no .
 *                                          <br>[cn] 返回接口调用结果，是返回YES，否返回NO
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
- (BOOL)startPlayLocalAudioFile:(NSString *)fileName loops:(NSInteger)loops;


/**
 * @brief [en] This method is used to judge whether stop play audio file.
 *        <br>[cn] 判断是否停止播放音频文件
 *
 * @retval BOOL *                   <b>:</b><br>[en] Return interface invoked result, true return yes, or return no .
 *                                          <br>[cn] 返回接口调用结果。是返回YES，否返回NO
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
- (BOOL)stopPlayLocalAudioFile;


/**
 * @brief [en] This method is used to judge whether start record.
 *        <br>[cn] 判断是否开始录音
 *
 * @param [in] NSString* destFilePath   <b>:</b><br>[en] Indicates dest file path.
 *                                              <br>[cn] 存放路径
 * @retval BOOL                         <b>:</b><br>[en] Return interface invoked result, true return yes, or return no .
 *                                              <br>[cn] 返回接口调用结果，是返回YES，否返回NO
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
- (BOOL)startRecord:(NSString *)destFilePath;


/**
 * @brief [en] This method is used to judge whether stop record.
 *        <br>[cn] 判断是否停止录音
 *
 * @param [in] NSTimeInterval* duration <b>:</b><br>[en] Indicates duration,give value by interface, back to UI.
 *                                              <br>[cn] 录音时长,由接口内部赋值返回UI
 * @retval BOOL                         <b>:</b><br>[en] Return interface invoked result, true return yes, or return no .
 *                                              <br>[cn] 返回接口调用结果，是返回YES，否返回NO
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
- (BOOL)stopRecord:(NSTimeInterval*)duration;

/**
 * @brief [en] This method is used to get audio output device volume.
 *        <br>[cn] 获取音频输出设备音量
 *
 * @param [in] NSInteger* volume        <b>:</b><br>[en] Indicates volume.
 *                                              <br>[cn] 音量大小
 * @retval BOOL                         <b>:</b><br>[en] Return interface invoked result, true return yes, or return no .
 *                                              <br>[cn] 返回接口调用结果，是返回YES，否返回NO
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
- (BOOL)getAudioInputDeviceVolume:(NSInteger*)volume;


/**
 * @brief [en] This method is used to get duration.
 *        <br>[cn] 录音时长
 *
 * @retval NSTimeInterval           <b>:</b><br>[en] Return duration if success,give value by interface, back to UI, if failed return nil .
 *                                          <br>[cn] 成功返回录音时长,由接口内部赋值返回UI，失败返回nil
 * @attention [en] NA
 *            <br>[cn] NA
 * @see NA
 **/
- (NSTimeInterval)duration;

/**
 *   Attention !!!
 *   Below two methods only can be called in ESpaceUMResource, otherwise the playing property of ESpaceUMResource will not updated.
 *
 *   @return Determin function called successfully
 */

/**
 * @brief [en] This method is used to judge whether start play ESpaceUMAudioResource.
 *        <br>[cn] 判断是否开始播放ESpaceUMAudioResource文件
 *
 * @param [in] ESpaceUMAudioResource* audioResource   <b>:</b><br>[en] Indicates ESpaceUMAudioResource object.
 *                                                            <br>[cn] ESpaceUMAudioResource对象
 * @param [in] NSInteger loops                        <b>:</b><br>[en] Indicates whether loop, 0:loop, more than 0:not loop. .
 *                                                            <br>[cn] 是否循环播放，0：循环；大于0不循环
 * @retval BOOL                     <b>:</b><br>[en] Return interface invoked result, true return yes, or return no .
 *                                          <br>[cn] 返回接口调用结果，是返回YES，否返回NO
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
- (BOOL)startPlayAudioResource:(ESpaceUMAudioResource *)audioResource loops:(NSInteger)loops;


/**
 * @brief [en] This method is used to judge whether stop play ESpaceUMAudioResource file.
 *        <br>[cn] 判断是否停止播放ESpaceUMAudioResource文件
 *
 * @retval BOOL *                   <b>:</b><br>[en] Return interface invoked result, true return yes, or return no .
 *                                          <br>[cn] 返回接口调用结果。是返回YES，否返回NO
 * @attention [en] NA.
 *            <br>[cn] NA
 * @see NA
 **/
- (BOOL)stopPlayAudioResource;
@end
