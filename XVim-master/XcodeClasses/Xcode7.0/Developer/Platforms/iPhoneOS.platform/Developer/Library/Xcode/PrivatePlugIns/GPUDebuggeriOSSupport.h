//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#pragma mark -

//
// File: /Applications/Xcode-7GM.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/Library/Xcode/PrivatePlugIns/GPUDebuggeriOSSupport.ideplugin/Contents/MacOS/GPUDebuggeriOSSupport
// UUID: 4C4AC76C-49BF-3006-A77B-023D995F621B
//
//                           Arch: x86_64
//                Current version: 1.0.0
//          Compatibility version: 1.0.0
//                 Source version: 18019.0.0.0.0
//       Minimum Mac OS X version: 10.10.0
//                    SDK version: 10.11.0
//
// Objective-C Garbage Collection: Unsupported
//
//                       Run path: @loader_path/../../../../../PrivateFrameworks
//                               = /Applications/Xcode-7GM.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/Library/PrivateFrameworks
//

@protocol IDEDeferredInitialization
+ (BOOL)ide_deferredInitializeWithOptions:(int)arg1 error:(id *)arg2;
@end

__attribute__((visibility("hidden")))
@interface GPUiOSInferiorSession : GPUInferiorSession
{
}

+ (id)GPUToolsDeviceFromDVTDevice:(id)arg1 error:(id *)arg2;
- (id)GPUToolsDeviceFromDVTDevice:(id)arg1 error:(id *)arg2;
- (id)initWithAppName:(id)arg1 launchSession:(id)arg2 controller:(id)arg3 error:(id *)arg4;

@end

__attribute__((visibility("hidden")))
@interface GPUiOSInitializer : NSObject <IDEDeferredInitialization>
{
}

+ (BOOL)ide_deferredInitializeWithOptions:(int)arg1 error:(id *)arg2;

@end

__attribute__((visibility("hidden")))
@interface GPUiOSQuicklooksEditor : GPUQuicklooksEditor
{
}

- (id)toolsDeviceFromDVTDevice:(id)arg1 error:(id *)arg2;

@end

__attribute__((visibility("hidden")))
@interface GPUiOSReplayController : GPUTraceReplayController
{
}

- (id)replayerGuestApp;
- (id)prepareCaptureArchive:(id)arg1 withDestinationName:(id)arg2;
- (id)_prepareCaptureArchiveForSimulatorDevice:(id)arg1 withDestinationName:(id)arg2;
- (id)_prepareCaptureArchiveForIOSDevice:(id)arg1 withDestinationName:(id)arg2;
- (id)connectedDevices;

@end

