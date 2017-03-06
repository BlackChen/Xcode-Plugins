//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#pragma mark -

//
// File: /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneSimulator.platform/Developer/SDKs/iPhoneSimulator.sdk/System/Library/PrivateFrameworks/FTClientServices.framework/FTClientServices
// UUID: 93CB6386-94CA-3AE6-9947-AA5CF2D5C292
//
//                           Arch: x86_64
//                Current version: 800.0.0
//          Compatibility version: 1.0.0
//                 Source version: 1323.3.0.0.0
//            Minimum iOS version: 8.0.0
//                    SDK version: 8.0.0
//
// Objective-C Garbage Collection: Unsupported
//

@interface FTCServiceAvailabilityCenter : NSObject
{
    NSMutableDictionary *_availabilityHandlers;
}

+ (id)sharedInstance;
- (long long)availabilityForListenerID:(id)arg1 forService:(long long)arg2;
- (_Bool)removeListenerID:(id)arg1 forService:(long long)arg2;
- (_Bool)addListenerID:(id)arg1 forService:(long long)arg2;
- (_Bool)hasListenerID:(id)arg1 forService:(long long)arg2;
- (id)containerForService:(long long)arg1 create:(_Bool)arg2;
- (void)_stopListeningToMonitor:(id)arg1;
- (void)_startListeningToMonitor:(id)arg1;
- (void)_handleServiceMonitorNotification:(id)arg1;
- (void)_postNotificationForService:(long long)arg1 availability:(long long)arg2;
- (_Bool)_isValidServiceType:(long long)arg1;
- (void)dealloc;
- (id)init;

@end

@interface FTCServiceContainer : NSObject
{
    FTCServiceMonitor *_monitor;
    NSMutableSet *_listeners;
}

@property(readonly, retain, nonatomic) NSMutableSet *listeners; // @synthesize listeners=_listeners;
@property(retain, nonatomic) FTCServiceMonitor *monitor; // @synthesize monitor=_monitor;
- (_Bool)removeListenerID:(id)arg1;
- (_Bool)addListenerID:(id)arg1;
- (_Bool)hasListenerID:(id)arg1;
- (void)dealloc;
- (id)initWithServiceType:(long long)arg1;

@end

@interface FTCServiceMonitor : NSObject
{
    long long _availability;
    long long _type;
    int _token;
}

@property(readonly, nonatomic) long long serviceType;
- (long long)serviceAvailability;
- (void)handleActiveAccountsChanged:(id)arg1;
- (void)updateAvailability;
- (void)_updateAvailability;
- (void)_postAvailability:(long long)arg1;
- (void)dealloc;
- (id)initWithServiceType:(long long)arg1;

@end

