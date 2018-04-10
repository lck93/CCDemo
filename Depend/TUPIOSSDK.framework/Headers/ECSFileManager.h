//
//  ECSFileManager.h
//  eSpaceIOSSDK
//
//  Created by yemingxing on 8/12/15.
//  Copyright (c) 2015 huawei. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, LocalFileEncryptStatus)
{
    LocalFileEncryptStatusUnknow = 0,
    LocalFileEncryptStatusEncrypt = 1,
    LocalFileEncryptStatusNotEncrypt = 2
};

@interface ECSFileManager : NSObject

+ (instancetype) defaultManager;

- (BOOL)fileExistsAtPath:(NSString*) path;
- (BOOL)fileExistsAtPath:(NSString*) path isDirectory:(BOOL*)b;
- (BOOL)isReadableFileAtPath:(NSString*) path;
- (BOOL)isWritableFileAtPath:(NSString*) path;
- (BOOL)isExecutableFileAtPath:(NSString*) path;
- (BOOL)isDeletableFileAtPath:(NSString*) path;

- (NSData*)contentsAtPath:(NSString*) path;

- (BOOL)createDirectoryAtURL:(NSURL*) url withIntermediateDirectories:(BOOL)b attributes:(NSDictionary*)attributes error:(NSError**)error;
- (BOOL)createDirectoryAtPath:(NSString*)path withIntermediateDirectories:(BOOL)b attributes:(NSDictionary*)attributes error:(NSError**)error;
- (BOOL)createFileAtPath:(NSString*)path contents:(NSData*)data attributes:(NSDictionary*)attributes;
- (BOOL)removeItemAtURL:(NSURL*) url error:(NSError**) error;
- (BOOL)removeItemAtPath:(NSString*) path error:(NSError**) error;

- (BOOL)copyItemAtURL:(NSURL*) fromURL toURL:(NSURL*) toURL error:(NSError**) error;
- (BOOL)copyItemAtPath:(NSString*)fromPath toPath:(NSString*) toPath error:(NSError**) error;
- (BOOL)moveItemAtURL:(NSURL*) fromURL toURL:(NSURL*) toURL error:(NSError**) error;
- (BOOL)moveItemAtPath:(NSString*)fromPath toPath:(NSString*) toPath error:(NSError**) error;
- (NSDictionary *)attributesOfItemAtPath:(NSString *)path error:(NSError **)error;

- (LocalFileEncryptStatus)isFileEncrypt:(NSString *)path;

- (BOOL) encryptPlainFile:(NSString*)path toPath:(NSString*) encPath;
@end
