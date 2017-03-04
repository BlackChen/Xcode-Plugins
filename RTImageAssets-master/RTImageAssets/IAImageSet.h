//
//  IAImageSet.h
//  RTImageAssets
//
//  Created by ricky on 14-12-10.
//  Copyright (c) 2014年 rickytan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Cocoa/Cocoa.h>

extern NSString const *IAImageIdiom;
extern NSString const *IAImageScale;
extern NSString const *IAImageFilename;
extern NSString const *IAImageSubtype;


@interface IAImageSet : NSObject
@property (nonatomic, readonly) NSString *name;
@property (nonatomic, readonly) NSArray *images;

+ (instancetype)imageSetWithPath:(NSString *)path;
- (id)initWithPath:(NSString *)path;

@end

@interface IAIconSet : IAImageSet

- (void)generateAllIcons:(NSImage* )image;

@end

@interface IAImageAssets : NSObject
@property (nonatomic, readonly) NSString *name;
@property (nonatomic, readonly) NSArray *imageSets;
@property (nonatomic, readonly) NSArray *iconSets;

+ (instancetype)assetsWithPath:(NSString *)path;

- (id)initWithPath:(NSString *)path;
- (void)addToProccesingQueue:(NSOperationQueue *)queue;
@end

@interface NSImage (Resizing)
- (NSImage *)resizedImageWithScale:(CGFloat)scale;
- (NSImage *)resizedImageWithSize:(NSSize)size;
- (BOOL)saveToFile:(NSString *)filePath withType:(NSBitmapImageFileType)type;
@end