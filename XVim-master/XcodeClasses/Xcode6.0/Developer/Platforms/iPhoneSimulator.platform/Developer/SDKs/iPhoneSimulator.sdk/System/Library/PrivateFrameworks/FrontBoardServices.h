//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#pragma mark Blocks

typedef void (^CDUnknownBlockType)(void); // return type and parameters are unknown

#pragma mark Named Structures

struct CGPoint {
    double x;
    double y;
};

struct CGRect {
    struct CGPoint origin;
    struct CGSize size;
};

struct CGSize {
    double width;
    double height;
};

#pragma mark -

//
// File: /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneSimulator.platform/Developer/SDKs/iPhoneSimulator.sdk/System/Library/PrivateFrameworks/FrontBoardServices.framework/FrontBoardServices
// UUID: 7313FA11-EA5C-309A-BF8F-60E492803D28
//
//                           Arch: x86_64
//                Current version: 1.0.0
//          Compatibility version: 1.0.0
//                 Source version: 120.1.0.0.0
//            Minimum iOS version: 8.0.0
//                    SDK version: 8.0.0
//
// Objective-C Garbage Collection: Unsupported
//

@protocol BSXPCCoding <NSObject>
- (void)encodeWithXPCDictionary:(NSObject<OS_xpc_object> *)arg1;
- (id)initWithXPCDictionary:(NSObject<OS_xpc_object> *)arg1;
@end

@protocol FBSSceneUpdater <NSObject>
- (void)scene:(FBSScene *)arg1 didReceiveActions:(NSSet *)arg2;
- (void)scene:(FBSScene *)arg1 didUpdateClientSettings:(FBSSceneClientSettings *)arg2 withDiff:(FBSSceneClientSettingsDiff *)arg3 transitionContext:(FBSSceneTransitionContext *)arg4;
- (void)scene:(FBSScene *)arg1 didDetachContext:(FBSSceneContext *)arg2;
- (void)scene:(FBSScene *)arg1 didReceiveUpdateToContext:(FBSSceneContext *)arg2;
- (void)scene:(FBSScene *)arg1 didAttachContext:(FBSSceneContext *)arg2;
- (_Bool)willObserveContextsManually;
- (void)unregisterDelegateForSceneID:(NSString *)arg1;
- (void)registerDelegate:(id <FBSSceneUpdaterDelegate>)arg1 forSceneID:(NSString *)arg2;
@end

@protocol FBSUIApplicationWorkspaceClientDelegate <FBSWorkspaceClientDelegate>
- (void)clientHandleAssertionExpirationImminent:(FBSWorkspaceClient *)arg1;
- (void)clientHandleExit:(FBSWorkspaceClient *)arg1;
- (void)client:(FBSWorkspaceClient *)arg1 handleLaunch:(FBSUIApplicationLaunchEvent *)arg2 withCompletion:(void (^)(FBSUIApplicationLaunchResponseEvent *))arg3;
@end

@protocol FBSWorkspaceClientDelegate <NSObject>
- (void)client:(FBSWorkspaceClient *)arg1 handleActions:(FBSWorkspaceActionsEvent *)arg2;
- (void)client:(FBSWorkspaceClient *)arg1 handleDestroyScene:(FBSWorkspaceDestroySceneEvent *)arg2 withCompletion:(void (^)(FBSWorkspaceDestroySceneResponseEvent *))arg3;
- (void)client:(FBSWorkspaceClient *)arg1 handleCreateScene:(FBSWorkspaceCreateSceneEvent *)arg2 withCompletion:(void (^)(FBSWorkspaceCreateSceneResponseEvent *))arg3;
- (void)clientEndTransaction:(FBSWorkspaceClient *)arg1;
- (void)clientBeginTransaction:(FBSWorkspaceClient *)arg1;
- (void)clientSystemApplicationTerminated:(FBSWorkspaceClient *)arg1;
@end

@protocol NSCoding
- (id)initWithCoder:(NSCoder *)arg1;
- (void)encodeWithCoder:(NSCoder *)arg1;
@end

@protocol NSCopying
- (id)copyWithZone:(struct _NSZone *)arg1;
@end

@protocol NSMutableCopying
- (id)mutableCopyWithZone:(struct _NSZone *)arg1;
@end

@protocol NSObject
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;
@property(readonly) unsigned long long hash;
- (struct _NSZone *)zone;
- (unsigned long long)retainCount;
- (id)autorelease;
- (oneway void)release;
- (id)retain;
- (_Bool)respondsToSelector:(SEL)arg1;
- (_Bool)conformsToProtocol:(Protocol *)arg1;
- (_Bool)isMemberOfClass:(Class)arg1;
- (_Bool)isKindOfClass:(Class)arg1;
- (_Bool)isProxy;
- (id)performSelector:(SEL)arg1 withObject:(id)arg2 withObject:(id)arg3;
- (id)performSelector:(SEL)arg1 withObject:(id)arg2;
- (id)performSelector:(SEL)arg1;
- (id)self;
- (Class)class;
- (_Bool)isEqual:(id)arg1;

@optional
@property(readonly, copy) NSString *debugDescription;
@end

@protocol NSSecureCoding <NSCoding>
+ (_Bool)supportsSecureCoding;
@end

@interface FBSContext : NSObject <BSXPCCoding>
{
    unsigned int _identifier;
    double _level;
}

+ (id)contextWithSceneContext:(id)arg1;
@property(readonly, nonatomic) double level; // @synthesize level=_level;
@property(readonly, nonatomic) unsigned int identifier; // @synthesize identifier=_identifier;
- (void)encodeWithXPCDictionary:(id)arg1;
- (id)initWithXPCDictionary:(id)arg1;
@property(readonly, copy) NSString *description;
- (_Bool)isEqual:(id)arg1;
@property(readonly) unsigned long long hash;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly) Class superclass;

@end

@interface FBSDisplay : NSObject <BSXPCCoding, NSCopying, NSSecureCoding>
{
    unsigned int _seed;
    CADisplay *_caDisplay;
    unsigned long long _type;
    long long _tags;
}

+ (id)_CADisplayForId:(unsigned int)arg1;
+ (_Bool)supportsSecureCoding;
@property(nonatomic) unsigned int seed; // @synthesize seed=_seed;
@property(readonly, nonatomic) long long tags; // @synthesize tags=_tags;
@property(readonly, nonatomic) unsigned long long type; // @synthesize type=_type;
@property(readonly, retain, nonatomic) CADisplay *caDisplay; // @synthesize caDisplay=_caDisplay;
- (_Bool)isConnected;
- (void)setConnected:(_Bool)arg1;
- (_Bool)isExternal;
- (unsigned long long)_typeFromTags:(unsigned long long)arg1;
- (void)encodeWithXPCDictionary:(id)arg1;
- (id)initWithXPCDictionary:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)copyWithZone:(struct _NSZone *)arg1;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
- (_Bool)isEqual:(id)arg1;
- (id)_nameForDisplayType;
- (_Bool)isHiddenDisplay;
- (_Bool)isMusicOnlyDisplay;
- (_Bool)isMainDisplay;
- (_Bool)isiPodOnlyDisplay;
- (_Bool)isCarDisplay;
- (_Bool)isAirPlayDisplay;
@property(readonly, nonatomic) double orientation;
@property(readonly, nonatomic) double scale;
- (id)initWithCADisplay:(id)arg1 isMainDisplay:(_Bool)arg2 seed:(unsigned int)arg3 tags:(long long)arg4;
- (id)initWithCADisplay:(id)arg1 isMainDisplay:(_Bool)arg2;
- (id)initWithCADisplay:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly) Class superclass;

@end

@interface FBSLogger : NSObject
{
}

+ (id)environment;
+ (_Bool)isEnabled;

@end

@interface FBSSceneClientSettings : NSObject <NSCopying, NSMutableCopying>
{
    double _preferredLevel;
    long long _preferredInterfaceOrientation;
    NSSet *_occlusions;
    BSSettings *_otherSettings;
}

+ (_Bool)_isMutable;
+ (id)settings;
@property(readonly, copy, nonatomic) NSSet *occlusions; // @synthesize occlusions=_occlusions;
@property(readonly, nonatomic) long long preferredInterfaceOrientation; // @synthesize preferredInterfaceOrientation=_preferredInterfaceOrientation;
@property(readonly, nonatomic) double preferredLevel; // @synthesize preferredLevel=_preferredLevel;
- (id)valueDescriptionForFlag:(long long)arg1 object:(id)arg2 ofSetting:(unsigned long long)arg3;
- (id)keyDescriptionForSetting:(unsigned long long)arg1;
- (id)mutableCopyWithZone:(struct _NSZone *)arg1;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)description;
- (_Bool)isEqual:(id)arg1;
- (unsigned long long)hash;
- (id)_descriptionOfSettingsWithMultilinePrefix:(id)arg1;
- (id)otherSettings;
- (void)dealloc;
- (id)init;
- (id)initWithSettings:(id)arg1;

@end

@interface FBSMutableSceneClientSettings : FBSSceneClientSettings
{
}

+ (_Bool)_isMutable;
- (id)mutableCopyWithZone:(struct _NSZone *)arg1;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)otherSettings;
@property(copy, nonatomic) NSSet *occlusions;
@property(nonatomic) long long preferredInterfaceOrientation;
@property(nonatomic) double preferredLevel;

@end

@interface FBSSceneSettings : NSObject <NSCopying, NSMutableCopying>
{
    struct CGRect _frame;
    struct CGPoint _contentOffset;
    double _level;
    long long _interfaceOrientation;
    _Bool _backgrounded;
    _Bool _occluded;
    _Bool _occludedHasBeenCalculated;
    NSSet *_ignoreOcclusionReasons;
    NSArray *_occlusions;
    BSSettings *_otherSettings;
    BSSettings *_transientLocalSettings;
}

+ (_Bool)_isMutable;
+ (id)settings;
@property(readonly, copy, nonatomic) NSArray *occlusions; // @synthesize occlusions=_occlusions;
@property(readonly, nonatomic, getter=isBackgrounded) _Bool backgrounded; // @synthesize backgrounded=_backgrounded;
@property(readonly, nonatomic) long long interfaceOrientation; // @synthesize interfaceOrientation=_interfaceOrientation;
@property(readonly, nonatomic) double level; // @synthesize level=_level;
@property(readonly, nonatomic) struct CGPoint contentOffset; // @synthesize contentOffset=_contentOffset;
@property(readonly, nonatomic) struct CGRect frame; // @synthesize frame=_frame;
- (id)valueDescriptionForFlag:(long long)arg1 object:(id)arg2 ofSetting:(unsigned long long)arg3;
- (id)keyDescriptionForSetting:(unsigned long long)arg1;
- (id)mutableCopyWithZone:(struct _NSZone *)arg1;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)description;
- (_Bool)isEqual:(id)arg1;
- (unsigned long long)hash;
- (id)_descriptionOfSettingsWithMultilinePrefix:(id)arg1;
- (id)transientLocalSettings;
- (_Bool)isIgnoringOcclusions;
- (id)ignoreOcclusionReasons;
- (id)otherSettings;
- (_Bool)isOccluded;
- (struct CGRect)bounds;
- (void)dealloc;
- (id)init;
- (id)initWithSettings:(id)arg1;

@end

@interface FBSMutableSceneSettings : FBSSceneSettings
{
}

+ (_Bool)_isMutable;
- (id)mutableCopyWithZone:(struct _NSZone *)arg1;
- (id)copyWithZone:(struct _NSZone *)arg1;
@property(copy, nonatomic) NSArray *occlusions;
- (id)transientLocalSettings;
- (id)ignoreOcclusionReasons;
- (id)otherSettings;
@property(nonatomic, getter=isBackgrounded) _Bool backgrounded;
@property(nonatomic) long long interfaceOrientation;
@property(nonatomic) double level;
@property(nonatomic) struct CGPoint contentOffset;
@property(nonatomic) struct CGRect frame;

@end

@interface FBSScene : NSObject
{
}

- (id)_descriptionWithMultilinePrefix:(id)arg1;
- (void)invalidate;
- (void)detachSceneContext:(id)arg1;
- (void)attachSceneContext:(id)arg1;
- (void)detachContext:(id)arg1;
- (void)attachContext:(id)arg1;
- (void)sendActions:(id)arg1;
- (void)updateClientSettingsWithBlock:(CDUnknownBlockType)arg1;
- (void)updateClientSettings:(id)arg1 withTransitionContext:(id)arg2;
@property(readonly, retain, nonatomic) FBSDisplay *fbsDisplay;
@property(readonly, nonatomic) CADisplay *display;
@property(readonly, retain, nonatomic) NSArray *contexts;
@property(readonly, retain, nonatomic) FBSSceneClientSettings *clientSettings;
@property(readonly, retain, nonatomic) FBSSceneSettings *settings;
@property(nonatomic) id <FBSSceneDelegate> delegate;
@property(readonly, copy, nonatomic) NSString *identifier;
- (id)_init;
- (id)init;
- (id)initWithQueue:(id)arg1 identifier:(id)arg2 display:(id)arg3 settings:(id)arg4 clientSettings:(id)arg5;

@end

@interface FBSSceneClientSettingsDiff : NSObject <BSXPCCoding>
{
    BSMutableSettings *_changes;
}

+ (id)diffFromSettings:(id)arg1 toSettings:(id)arg2;
@property(readonly, copy) NSString *description;
- (void)inspectOtherChangesWithBlock:(CDUnknownBlockType)arg1;
- (void)inspectChangesWithBlock:(CDUnknownBlockType)arg1;
- (id)settingsByApplyingToMutableCopyOfSettings:(id)arg1;
- (void)encodeWithXPCDictionary:(id)arg1;
- (id)initWithXPCDictionary:(id)arg1;
- (void)dealloc;
- (id)init;
- (id)_initWithChanges:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

@interface FBSSceneClientSettingsDiffInspector : NSObject
{
    BSMutableSettings *_observerInfo;
    _Bool _iteratingObservers;
}

- (id)description;
- (void)_addObserver:(id)arg1 forSetting:(unsigned long long)arg2 inInfo:(id)arg3;
- (void)observeOtherSetting:(unsigned long long)arg1 withBlock:(CDUnknownBlockType)arg2;
- (void)observeOcclusionsWithBlock:(CDUnknownBlockType)arg1;
- (void)observePreferredInterfaceOrientationWithBlock:(CDUnknownBlockType)arg1;
- (void)observePreferredLevelWithBlock:(CDUnknownBlockType)arg1;
- (void)observeClassWithBlock:(CDUnknownBlockType)arg1;
- (void)removeAllObservers;
- (void)inspectDiff:(id)arg1 withContext:(void *)arg2;
- (void)dealloc;
- (id)init;

@end

@interface FBSSceneContext : NSObject
{
    unsigned int _identifier;
    double _level;
    CAContext *_context;
    id <FBSSceneContextDelegate> _delegate;
    _Bool _shouldObserveContext;
}

+ (id)contextWithCAContext:(id)arg1;
@property(nonatomic) id <FBSSceneContextDelegate> delegate; // @synthesize delegate=_delegate;
@property(readonly, nonatomic) unsigned int identifier; // @synthesize identifier=_identifier;
@property(readonly, retain, nonatomic) CAContext *CAContext; // @synthesize CAContext=_context;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (id)description;
- (_Bool)isEqual:(id)arg1;
- (unsigned long long)hash;
@property(nonatomic) double level; // @synthesize level=_level;
- (void)dealloc;
- (id)initWithIdentifier:(unsigned int)arg1 level:(double)arg2;
- (id)initWithCAContext:(id)arg1;

@end

@interface FBSSceneImpl : FBSScene
{
    id <FBSSceneDelegate> _delegate;
    NSString *_identifier;
    FBSSceneSettings *_settings;
    FBSSceneClientSettings *_clientSettings;
    id <FBSSceneUpdater> _updater;
    CADisplay *_display;
    FBSDisplay *_fbsDisplay;
    FBSSerialQueue *_callOutQueue;
    NSObject<OS_dispatch_queue> *_queue;
    NSMutableArray *_contexts;
    _Bool _shouldObserveContexts;
}

- (void)sceneContextDidInvalidate:(id)arg1;
- (void)sceneContextDidUpdate:(id)arg1;
- (_Bool)sceneContextShouldObserveUpdates:(id)arg1;
- (void)updater:(id)arg1 didReceiveActions:(id)arg2;
- (void)updater:(id)arg1 didUpdateSettings:(id)arg2 withDiff:(id)arg3 transitionContext:(id)arg4 completion:(CDUnknownBlockType)arg5;
- (id)description;
- (void)_performDelegateCallOut:(CDUnknownBlockType)arg1;
- (id)_descriptionWithMultilinePrefix:(id)arg1;
- (void)_queue_invalidate;
- (void)_updateContext:(id)arg1;
- (void)detachSceneContext:(id)arg1;
- (void)attachSceneContext:(id)arg1;
- (void)detachContext:(id)arg1;
- (void)attachContext:(id)arg1;
- (void)sendActions:(id)arg1;
- (void)updateClientSettingsWithBlock:(CDUnknownBlockType)arg1;
- (void)updateClientSettings:(id)arg1 withTransitionContext:(id)arg2;
- (id)fbsDisplay;
- (id)display;
- (id)contexts;
- (id)clientSettings;
- (id)settings;
- (void)setDelegate:(id)arg1;
- (id)delegate;
- (id)identifier;
- (void)dealloc;
- (id)_initWithInternalQueue:(id)arg1 callOutQueue:(id)arg2 updater:(id)arg3 identifier:(id)arg4 display:(id)arg5 settings:(id)arg6 clientSettings:(id)arg7;
- (id)_initWithCallOutQueue:(id)arg1 updater:(id)arg2 identifier:(id)arg3 display:(id)arg4 settings:(id)arg5 clientSettings:(id)arg6;
- (id)_initWithWorkspace:(id)arg1 updater:(id)arg2 identifier:(id)arg3 display:(id)arg4 settings:(id)arg5 clientSettings:(id)arg6;
- (id)initWithQueue:(id)arg1 identifier:(id)arg2 display:(id)arg3 settings:(id)arg4 clientSettings:(id)arg5;
- (id)_initWithQueue:(id)arg1 callOutQueue:(id)arg2 identifier:(id)arg3 display:(id)arg4 settings:(id)arg5 clientSettings:(id)arg6;

@end

@interface FBSSceneOcclusion : NSObject <BSXPCCoding>
{
    struct CGRect _rect;
}

+ (id)occlusionWithRect:(struct CGRect)arg1;
+ (id)fullOcclusion;
- (void)encodeWithXPCDictionary:(id)arg1;
- (id)initWithXPCDictionary:(id)arg1;
@property(readonly, copy) NSString *description;
- (_Bool)isEqual:(id)arg1;
@property(readonly) unsigned long long hash;
- (_Bool)isEqualToOcclusion:(id)arg1;
- (struct CGRect)CGRect;
- (id)init;
- (id)_initWithCGRect:(struct CGRect)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly) Class superclass;

@end

@interface FBSSceneSettingsDiff : NSObject <BSXPCCoding>
{
    BSMutableSettings *_changes;
}

+ (id)diffFromSettings:(id)arg1 toSettings:(id)arg2;
@property(readonly, copy) NSString *description;
- (void)inspectOtherChangesWithBlock:(CDUnknownBlockType)arg1;
- (void)inspectChangesWithBlock:(CDUnknownBlockType)arg1;
- (id)settingsByApplyingToMutableCopyOfSettings:(id)arg1;
- (void)encodeWithXPCDictionary:(id)arg1;
- (id)initWithXPCDictionary:(id)arg1;
- (void)dealloc;
- (id)init;
- (id)_initWithChanges:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

@interface FBSSceneSettingsDiffInspector : NSObject
{
    BSMutableSettings *_observerInfo;
    _Bool _iteratingObservers;
}

- (id)description;
- (void)_addObserver:(id)arg1 forSetting:(unsigned long long)arg2 inInfo:(id)arg3;
- (void)observeOtherSetting:(unsigned long long)arg1 withBlock:(CDUnknownBlockType)arg2;
- (void)observeOcclusionsWithBlock:(CDUnknownBlockType)arg1;
- (void)observeIsBackgroundedWithBlock:(CDUnknownBlockType)arg1;
- (void)observeInterfaceOrientationWithBlock:(CDUnknownBlockType)arg1;
- (void)observeLevelWithBlock:(CDUnknownBlockType)arg1;
- (void)observeFrameWithBlock:(CDUnknownBlockType)arg1;
- (void)observeClassWithBlock:(CDUnknownBlockType)arg1;
- (void)removeAllObservers;
- (void)inspectDiff:(id)arg1 withContext:(void *)arg2;
- (void)dealloc;
- (id)init;

@end

@interface FBSSceneTransitionContext : NSObject <NSCopying, NSMutableCopying>
{
    BSAnimationSettings *_animationSettings;
    BSMachSendRight *_animationFencePort;
    NSSet *_actions;
    BSMutableSettings *_otherSettings;
    BSMutableSettings *_transientLocalClientSettings;
}

+ (id)transitionContext;
@property(copy, nonatomic) NSSet *actions; // @synthesize actions=_actions;
@property(copy, nonatomic) BSMachSendRight *animationFencePort; // @synthesize animationFencePort=_animationFencePort;
@property(copy, nonatomic) BSAnimationSettings *animationSettings; // @synthesize animationSettings=_animationSettings;
- (id)valueDescriptionForFlag:(long long)arg1 object:(id)arg2 ofSetting:(unsigned long long)arg3;
- (id)keyDescriptionForSetting:(unsigned long long)arg1;
- (void)encodeWithXPCDictionary:(id)arg1;
- (id)initWithXPCDictionary:(id)arg1;
- (id)mutableCopyWithZone:(struct _NSZone *)arg1;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)description;
- (_Bool)isEqual:(id)arg1;
- (unsigned long long)hash;
- (id)_descriptionOfSettingsWithMultilinePrefix:(id)arg1;
- (id)transientLocalClientSettings;
- (id)otherSettings;
- (void)dealloc;

@end

@interface FBSSerialQueue : NSObject
{
    NSObject<OS_dispatch_queue> *_dispatchQueue;
    NSArray *_mainRunLoopModes;
    struct __CFRunLoopSource *_runLoopSource;
}

+ (id)queueWithMainRunLoopModes:(id)arg1;
+ (id)queueWithDispatchQueue:(id)arg1;
- (id)description;
- (_Bool)isEqual:(id)arg1;
- (unsigned long long)hash;
- (void)performAsync:(CDUnknownBlockType)arg1;
- (void)assertOnQueue;
- (void)dealloc;
- (id)init;
- (id)_initWithDispatchQueue:(id)arg1 mainRunLoopModes:(id)arg2;

@end

@interface FBSServiceNames : NSObject
{
}

+ (id)workspaceServiceName;
+ (id)systemAppProxyServiceName;
+ (void)_computeNames;

@end

@interface FBSSystemAppProxy : BSBaseXPCClient
{
    _Bool _uiApplicationClient;
}

+ (id)sharedInstance;
@property(getter=isUIApplicationClient, setter=setUIApplicationClient:) _Bool uiApplicationClient; // @synthesize uiApplicationClient=_uiApplicationClient;
- (void)fireCompletion:(CDUnknownBlockType)arg1 openAppErrorCode:(long long)arg2;
- (void)fireCompletion:(CDUnknownBlockType)arg1 pidResult:(int)arg2 error:(id)arg3;
- (void)fireCompletion:(CDUnknownBlockType)arg1 bundleIDResult:(id)arg2 error:(id)arg3;
- (void)fireCompletion:(CDUnknownBlockType)arg1 error:(id)arg2;
- (id)clientCallbackQueue;
- (void)_sendMessageType:(long long)arg1 withMessage:(CDUnknownBlockType)arg2 withReplyHandler:(CDUnknownBlockType)arg3 waitForReply:(_Bool)arg4;
- (void)shutdownAndReboot:(_Bool)arg1;
- (void)terminateApplicationGroup:(int)arg1 forReason:(int)arg2 andReport:(_Bool)arg3 withDescription:(id)arg4 withResult:(CDUnknownBlockType)arg5;
- (void)terminateApplication:(id)arg1 forReason:(int)arg2 andReport:(_Bool)arg3 withDescription:(id)arg4 withResult:(CDUnknownBlockType)arg5;
- (void)sendActions:(id)arg1 withResult:(CDUnknownBlockType)arg2;
- (void)openURL:(id)arg1 application:(id)arg2 options:(id)arg3 clientPort:(unsigned int)arg4 withResult:(CDUnknownBlockType)arg5;
- (void)openApplication:(id)arg1 options:(id)arg2 clientPort:(unsigned int)arg3 withResult:(CDUnknownBlockType)arg4;
- (void)canActivateApplication:(id)arg1 withResult:(CDUnknownBlockType)arg2;
- (void)pidForApplication:(id)arg1 withResult:(CDUnknownBlockType)arg2;
- (void)systemApplicationBundleIdentifierWithResult:(CDUnknownBlockType)arg1;
- (_Bool)isClientLoggingEnabled;
- (void)setNextWakeInterval:(double)arg1 completion:(CDUnknownBlockType)arg2;
- (void)applicationBundleID:(id)arg1 requestBrightness:(double)arg2 completion:(CDUnknownBlockType)arg3;
- (void)badgeValueForBundleID:(id)arg1 completion:(CDUnknownBlockType)arg2;
- (void)setBadgeValue:(id)arg1 forBundleID:(id)arg2;
- (void)checkInUIApplication;
- (void)queue_connectionWasCreated;
- (void)invalidate;
- (id)initWithEndpoint:(id)arg1;
- (id)init;

@end

@interface FBSSystemService : NSObject
{
}

+ (id)sharedService;
- (void)fireCompletion:(CDUnknownBlockType)arg1 error:(id)arg2;
- (id)clientCallbackQueue;
- (id)_badArgumentError;
- (void)shutdown;
- (void)reboot;
- (void)setBadgeValue:(id)arg1 forBundleID:(id)arg2;
- (void)cleanupClientPort:(unsigned int)arg1;
- (unsigned int)createClientPort;
- (void)openURL:(id)arg1 application:(id)arg2 options:(id)arg3 clientPort:(unsigned int)arg4 withResult:(CDUnknownBlockType)arg5;
- (void)openApplication:(id)arg1 options:(id)arg2 clientPort:(unsigned int)arg3 withResult:(CDUnknownBlockType)arg4;
- (void)terminateApplicationGroup:(long long)arg1 forReason:(long long)arg2 andReport:(_Bool)arg3 withDescription:(id)arg4;
- (void)terminateApplication:(id)arg1 forReason:(long long)arg2 andReport:(_Bool)arg3 withDescription:(id)arg4;
- (void)sendActions:(id)arg1 withResult:(CDUnknownBlockType)arg2;
- (void)openApplication:(id)arg1 options:(id)arg2 withResult:(CDUnknownBlockType)arg3;
- (void)openDataActivationURL:(id)arg1 withResult:(CDUnknownBlockType)arg2;
- (_Bool)canOpenApplication:(id)arg1 reason:(long long *)arg2;
- (int)pidForApplication:(id)arg1;
- (id)systemApplicationBundleIdentifier;
- (void)dealloc;
- (id)init;

@end

@interface FBSSystemServiceUtility : NSObject
{
}

+ (id)auditTokenFromClientPort:(unsigned int)arg1;
+ (void)cleanupClientPort:(unsigned int)arg1;
+ (unsigned int)createClientPort;

@end

@interface FBSWorkspaceEvent : NSObject <BSXPCCoding>
{
}

- (void)encodeWithXPCDictionary:(id)arg1;
- (id)initWithXPCDictionary:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

@interface FBSUIApplicationLaunchEvent : FBSWorkspaceEvent
{
}

@end

@interface FBSWorkspaceResponse : NSObject <BSXPCCoding>
{
}

- (void)encodeWithXPCDictionary:(id)arg1;
- (id)initWithXPCDictionary:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

@interface FBSUIApplicationLaunchResponse : FBSWorkspaceResponse
{
    _Bool _supportsTaskSuspension;
    _Bool _supportsTaskSuspensionOnLock;
    BSMachSendRight *_taskPort;
}

@property(retain, nonatomic) BSMachSendRight *taskPort; // @synthesize taskPort=_taskPort;
@property(nonatomic) _Bool supportsTaskSuspensionOnLock; // @synthesize supportsTaskSuspensionOnLock=_supportsTaskSuspensionOnLock;
@property(nonatomic) _Bool supportsTaskSuspension; // @synthesize supportsTaskSuspension=_supportsTaskSuspension;
- (void)encodeWithXPCDictionary:(id)arg1;
- (id)initWithXPCDictionary:(id)arg1;
- (void)dealloc;

@end

@interface FBSUIApplicationLaunchResponseEvent : FBSWorkspaceEvent
{
    FBSUIApplicationLaunchResponse *_response;
}

@property(retain, nonatomic) FBSUIApplicationLaunchResponse *response; // @synthesize response=_response;
- (void)encodeWithXPCDictionary:(id)arg1;
- (id)initWithXPCDictionary:(id)arg1;
- (void)dealloc;

@end

@interface FBSUIApplicationSystemService : NSObject
{
    NSObject<OS_dispatch_queue> *_delegateQueue;
    id <FBSUIApplicationSystemServiceDelegate> _delegate;
}

@property(nonatomic) id <FBSUIApplicationSystemServiceDelegate> delegate; // @synthesize delegate=_delegate;
@property(nonatomic) double currentBacklightLevel;
@property(readonly, nonatomic) double backgroundTimeRemaining;
- (_Bool)setNextWakeInterval:(double)arg1;
@property(copy, nonatomic) NSString *badgeString;
@property(nonatomic) long long badgeNumber;
- (id)_getBadgeValue;
- (void)dealloc;
- (id)initWithQueue:(id)arg1;
- (id)init;

@end

@interface FBSWorkspace : NSObject <FBSWorkspaceClientDelegate>
{
    NSObject<OS_dispatch_queue> *_queue;
    id <FBSWorkspaceDelegate> _delegate;
    FBSWorkspaceClient *_client;
    FBSSerialQueue *_callOutQueue;
    NSObject<OS_dispatch_queue> *_scenesQueue;
    NSMutableDictionary *_scenesByIdentifier;
}

@property(readonly, retain, nonatomic) FBSSerialQueue *queue; // @synthesize queue=_callOutQueue;
- (void)client:(id)arg1 handleActions:(id)arg2;
- (void)client:(id)arg1 handleDestroyScene:(id)arg2 withCompletion:(CDUnknownBlockType)arg3;
- (void)client:(id)arg1 handleCreateScene:(id)arg2 withCompletion:(CDUnknownBlockType)arg3;
- (void)clientEndTransaction:(id)arg1;
- (void)clientBeginTransaction:(id)arg1;
- (void)clientSystemApplicationTerminated:(id)arg1;
- (id)_sceneWithIdentifier:(id)arg1;
- (void)_performDelegateCallOut:(CDUnknownBlockType)arg1;
- (id)_internalQueue;
- (id)_client;
- (Class)_clientClass;
@property(readonly, copy) NSString *description;
- (void)requestDestructionOfScene:(id)arg1 withCompletion:(CDUnknownBlockType)arg2;
- (void)requestSceneCreationWithInitialClientSettings:(id)arg1 completion:(CDUnknownBlockType)arg2;
- (void)enumerateScenesWithBlock:(CDUnknownBlockType)arg1;
- (id)sceneWithIdentifier:(id)arg1;
@property(readonly, copy, nonatomic) NSArray *scenes;
@property(nonatomic) id <FBSWorkspaceDelegate> delegate;
- (void)dealloc;
- (id)initWithSerialQueue:(id)arg1;
- (id)initWithQueue:(id)arg1;
- (id)init;
- (_Bool)isUIApplicationWorkspace;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

@interface FBSUIApplicationWorkspace : FBSWorkspace <FBSUIApplicationWorkspaceClientDelegate>
{
}

- (void)clientHandleAssertionExpirationImminent:(id)arg1;
- (void)clientHandleExit:(id)arg1;
- (void)client:(id)arg1 handleLaunch:(id)arg2 withCompletion:(CDUnknownBlockType)arg3;
- (_Bool)isUIApplicationWorkspace;
- (Class)_clientClass;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(nonatomic) id <FBSUIApplicationWorkspaceDelegate> delegate;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

@interface FBSWorkspaceClient : BSBaseXPCClient <FBSSceneUpdater>
{
    BSBasicServerClient *_client;
    NSMutableArray *_queuedMessages;
    NSMutableDictionary *_sceneIDToSceneHandlerMap;
    NSObject<OS_dispatch_queue> *_callOutQueue;
    _Bool _inTransaction;
    id <FBSWorkspaceClientDelegate> _delegate;
}

@property(readonly, nonatomic) NSObject<OS_dispatch_queue> *callOutQueue; // @synthesize callOutQueue=_callOutQueue;
@property(readonly, nonatomic) id <FBSWorkspaceClientDelegate> delegate; // @synthesize delegate=_delegate;
- (void)queue_connectionWasInterrupted;
- (void)queue_handleMessage:(id)arg1;
- (id)_loggingProem;
- (void)_queue_handleSceneActions:(id)arg1;
- (void)_queue_handleActions:(id)arg1;
- (void)_queue_handleDestroyScene:(id)arg1;
- (void)_queue_handleSceneUpdate:(id)arg1;
- (void)_queue_handleCreateScene:(id)arg1;
- (void)_queue_handleTransactionBookEnd;
- (void)_queue_ensureTransaction;
- (void)_queue_sendReplyForMessage:(id)arg1 withEvent:(id)arg2;
- (void)_queue_sendMessage:(long long)arg1 withEvent:(id)arg2 withResponseEvent:(CDUnknownBlockType)arg3 ofType:(Class)arg4;
- (void)_queue_sendMessage:(long long)arg1 withEvent:(id)arg2;
- (id)_queue_workspaceEventFromMessage:(id)arg1 ofType:(Class)arg2;
- (_Bool)queue_handleMessageWithType:(long long)arg1 message:(id)arg2 client:(id)arg3;
- (void)_debugLog:(id)arg1;
- (void)_sendMessage:(long long)arg1 withEvent:(id)arg2;
- (void)_sendReplyForMessage:(id)arg1 withEvent:(id)arg2;
@property(readonly, copy) NSString *description;
- (void)scene:(id)arg1 didReceiveActions:(id)arg2;
- (void)scene:(id)arg1 didUpdateClientSettings:(id)arg2 withDiff:(id)arg3 transitionContext:(id)arg4;
- (void)scene:(id)arg1 didDetachContext:(id)arg2;
- (void)scene:(id)arg1 didReceiveUpdateToContext:(id)arg2;
- (void)scene:(id)arg1 didAttachContext:(id)arg2;
- (_Bool)willObserveContextsManually;
- (void)unregisterDelegateForSceneID:(id)arg1;
- (void)registerDelegate:(id)arg1 forSceneID:(id)arg2;
- (void)sendDestroySceneRequestEvent:(id)arg1 withCompletion:(CDUnknownBlockType)arg2;
- (void)sendCreateSceneRequestEvent:(id)arg1 withCompletion:(CDUnknownBlockType)arg2;
- (void)dealloc;
- (id)initWithDelegate:(id)arg1;
- (id)initWithServiceName:(id)arg1 endpoint:(id)arg2;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

@interface FBSUIApplicationWorkspaceClient : FBSWorkspaceClient
{
}

- (void)_queue_handleAssertionExpirationImminent:(id)arg1;
- (void)_queue_handleExit:(id)arg1;
- (void)_queue_handleLaunch:(id)arg1;
- (_Bool)willObserveContextsManually;
- (_Bool)_queue_handleMessageWithType:(long long)arg1 message:(id)arg2;

// Remaining properties
@property(readonly, nonatomic) id <FBSUIApplicationWorkspaceClientDelegate> delegate;

@end

@interface FBSWorkspaceActionsEvent : FBSWorkspaceEvent
{
    NSSet *_actions;
}

@property(copy, nonatomic) NSSet *actions; // @synthesize actions=_actions;
- (void)encodeWithXPCDictionary:(id)arg1;
- (id)initWithXPCDictionary:(id)arg1;
- (void)dealloc;

@end

@interface FBSWorkspaceSceneEvent : FBSWorkspaceEvent
{
    NSString *_sceneID;
}

@property(copy, nonatomic) NSString *sceneID; // @synthesize sceneID=_sceneID;
- (void)encodeWithXPCDictionary:(id)arg1;
- (id)initWithXPCDictionary:(id)arg1;
- (void)dealloc;

@end

@interface FBSWorkspaceSceneUpdateEvent : FBSWorkspaceSceneEvent
{
    FBSSceneSettingsDiff *_settings;
    FBSSceneTransitionContext *_transitionContext;
}

@property(retain, nonatomic) FBSSceneTransitionContext *transitionContext; // @synthesize transitionContext=_transitionContext;
@property(retain, nonatomic) FBSSceneSettingsDiff *settingsDiff; // @synthesize settingsDiff=_settings;
- (void)encodeWithXPCDictionary:(id)arg1;
- (id)initWithXPCDictionary:(id)arg1;
- (void)dealloc;

@end

@interface FBSWorkspaceCreateSceneEvent : FBSWorkspaceSceneUpdateEvent
{
    FBSSceneClientSettingsDiff *_clientSettings;
    FBSDisplay *_display;
}

@property(retain, nonatomic) FBSDisplay *display; // @synthesize display=_display;
@property(retain, nonatomic) FBSSceneClientSettingsDiff *clientSettingsDiff; // @synthesize clientSettingsDiff=_clientSettings;
- (void)encodeWithXPCDictionary:(id)arg1;
- (id)initWithXPCDictionary:(id)arg1;
- (void)dealloc;

@end

@interface FBSWorkspaceCreateSceneRequestEvent : FBSWorkspaceEvent
{
    FBSSceneClientSettingsDiff *_clientSettings;
}

@property(retain, nonatomic) FBSSceneClientSettingsDiff *clientSettingsDiff; // @synthesize clientSettingsDiff=_clientSettings;
- (void)encodeWithXPCDictionary:(id)arg1;
- (id)initWithXPCDictionary:(id)arg1;
- (void)dealloc;

@end

@interface FBSWorkspaceCreateSceneRequestResponseEvent : FBSWorkspaceEvent
{
    NSString *_sceneID;
}

@property(copy, nonatomic) NSString *sceneID; // @synthesize sceneID=_sceneID;
- (void)encodeWithXPCDictionary:(id)arg1;
- (id)initWithXPCDictionary:(id)arg1;
- (void)dealloc;

@end

@interface FBSWorkspaceSceneUpdateResponse : FBSWorkspaceResponse
{
}

- (void)encodeWithXPCDictionary:(id)arg1;
- (id)initWithXPCDictionary:(id)arg1;

@end

@interface FBSWorkspaceCreateSceneResponse : FBSWorkspaceSceneUpdateResponse
{
}

- (void)encodeWithXPCDictionary:(id)arg1;
- (id)initWithXPCDictionary:(id)arg1;
- (void)dealloc;

@end

@interface FBSWorkspaceSceneUpdateResponseEvent : FBSWorkspaceSceneEvent
{
    FBSWorkspaceSceneUpdateResponse *_response;
}

@property(retain, nonatomic) FBSWorkspaceSceneUpdateResponse *response; // @synthesize response=_response;
- (void)encodeWithXPCDictionary:(id)arg1;
- (id)initWithXPCDictionary:(id)arg1;
- (void)dealloc;

@end

@interface FBSWorkspaceCreateSceneResponseEvent : FBSWorkspaceSceneUpdateResponseEvent
{
}

- (void)encodeWithXPCDictionary:(id)arg1;
- (id)initWithXPCDictionary:(id)arg1;
- (void)dealloc;

// Remaining properties
@property(retain, nonatomic) FBSWorkspaceCreateSceneResponse *response;

@end

@interface FBSWorkspaceDestroySceneEvent : FBSWorkspaceSceneEvent
{
    FBSSceneTransitionContext *_transitionContext;
}

@property(retain, nonatomic) FBSSceneTransitionContext *transitionContext; // @synthesize transitionContext=_transitionContext;
- (void)encodeWithXPCDictionary:(id)arg1;
- (id)initWithXPCDictionary:(id)arg1;
- (void)dealloc;

@end

@interface FBSWorkspaceDestroySceneRequestEvent : FBSWorkspaceSceneEvent
{
}

@end

@interface FBSWorkspaceDestroySceneRequestResponseEvent : FBSWorkspaceEvent
{
}

@end

@interface FBSWorkspaceDestroySceneResponse : FBSWorkspaceResponse
{
}

- (void)encodeWithXPCDictionary:(id)arg1;
- (id)initWithXPCDictionary:(id)arg1;
- (void)dealloc;

@end

@interface FBSWorkspaceDestroySceneResponseEvent : FBSWorkspaceSceneUpdateResponseEvent
{
}

- (void)encodeWithXPCDictionary:(id)arg1;
- (id)initWithXPCDictionary:(id)arg1;

@end

@interface FBSWorkspaceSceneActionsEvent : FBSWorkspaceSceneEvent
{
    NSSet *_actions;
}

@property(copy, nonatomic) NSSet *actions; // @synthesize actions=_actions;
- (void)encodeWithXPCDictionary:(id)arg1;
- (id)initWithXPCDictionary:(id)arg1;
- (void)dealloc;

@end

@interface FBSWorkspaceSceneClientSettingsChangedEvent : FBSWorkspaceSceneEvent
{
    FBSSceneClientSettingsDiff *_clientSettings;
    FBSSceneTransitionContext *_transition;
}

@property(retain, nonatomic) FBSSceneTransitionContext *transitionContext; // @synthesize transitionContext=_transition;
@property(retain, nonatomic) FBSSceneClientSettingsDiff *clientSettingsDiff; // @synthesize clientSettingsDiff=_clientSettings;
- (void)encodeWithXPCDictionary:(id)arg1;
- (id)initWithXPCDictionary:(id)arg1;
- (void)dealloc;

@end

@interface FBSWorkspaceSceneContextEvent : FBSWorkspaceSceneEvent
{
    FBSContext *_context;
    _Bool _orderOut;
}

@property(nonatomic) _Bool orderOut; // @synthesize orderOut=_orderOut;
@property(retain, nonatomic) FBSContext *context; // @synthesize context=_context;
- (void)encodeWithXPCDictionary:(id)arg1;
- (id)initWithXPCDictionary:(id)arg1;
- (id)description;
- (void)dealloc;

@end

