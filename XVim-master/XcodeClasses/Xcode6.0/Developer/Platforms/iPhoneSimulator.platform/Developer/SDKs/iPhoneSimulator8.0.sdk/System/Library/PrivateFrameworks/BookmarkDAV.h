//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#pragma mark Blocks

typedef void (^CDUnknownBlockType)(void); // return type and parameters are unknown

#pragma mark -

//
// File: /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneSimulator.platform/Developer/SDKs/iPhoneSimulator.sdk/System/Library/PrivateFrameworks/BookmarkDAV.framework/BookmarkDAV
// UUID: B4EEB05A-F924-39AE-B44E-A5891F442499
//
//                           Arch: x86_64
//                Current version: 1.0.0
//          Compatibility version: 1.0.0
//                 Source version: 108.0.0.0.0
//            Minimum iOS version: 8.0.0
//                    SDK version: 8.0.0
//
// Objective-C Garbage Collection: Unsupported
//

@protocol CoreDAVAddedContainer <CoreDAVModifiedContainer>
- (CoreDAVMkcolTask *)copyMkcolTask;
@end

@protocol CoreDAVContainerInfoTaskGroupDelegate <CoreDAVTaskGroupDelegate>
- (void)containerInfoTask:(CoreDAVContainerInfoTaskGroup *)arg1 completedWithContainers:(NSSet *)arg2 error:(NSError *)arg3;
@end

@protocol CoreDAVDeleteTaskDelegate <CoreDAVTaskDelegate>

@optional
- (void)deleteTask:(CoreDAVDeleteTask *)arg1 completedWithError:(NSError *)arg2;
@end

@protocol CoreDAVGetAccountPropertiesTaskGroupDelegate <CoreDAVTaskGroupDelegate>
- (void)getAccountPropertiesTask:(CoreDAVGetAccountPropertiesTaskGroup *)arg1 completedWithError:(NSError *)arg2;
@end

@protocol CoreDAVLeafDataPayload <NSObject>
@property(readonly, nonatomic) NSString *syncKey;
@property(readonly, nonatomic) NSData *dataPayload;
@property(retain, nonatomic) NSURL *serverID;
- (id)initWithURL:(NSURL *)arg1 eTag:(NSString *)arg2 dataPayload:(NSData *)arg3 inContainerWithURL:(NSURL *)arg4 withAccountInfoProvider:(id <CoreDAVAccountInfoProvider>)arg5;

@optional
@property(readonly, nonatomic) NSArray *childrenOrder;
@end

@protocol CoreDAVLocalDBTreeInfoProvider <CoreDAVTaskGroupDelegate>
- (void)notePutToURL:(NSURL *)arg1 withDataPayload:(NSData *)arg2 finishedWithIgnoredError:(NSError *)arg3;
- (void)recursiveContainerSyncTask:(CoreDAVRecursiveContainerSyncTaskGroup *)arg1 completedFullSyncWithNewCTag:(NSString *)arg2 newPTag:(NSString *)arg3 newSyncToken:(NSString *)arg4 error:(NSError *)arg5;
- (void)recursiveContainerSyncTask:(CoreDAVRecursiveContainerSyncTaskGroup *)arg1 completedSyncOfFolderWithURL:(NSURL *)arg2 newCTag:(NSString *)arg3 newPTag:(NSString *)arg4 addedOrModified:(NSSet *)arg5 removed:(NSSet *)arg6 error:(NSError *)arg7;
- (void)recursiveContainerSyncTask:(CoreDAVRecursiveContainerSyncTaskGroup *)arg1 retrievedAddedOrModifiedActions:(NSSet *)arg2 removed:(NSSet *)arg3;
- (void)recursiveContainerSyncTask:(CoreDAVRecursiveContainerSyncTaskGroup *)arg1 receivedAddedOrModifiedFolder:(id)arg2;
- (_Bool)setLocalETag:(NSString *)arg1 forItemWithURL:(NSURL *)arg2;
- (NSSet *)copyAllLocalURLsInFolderWithURL:(NSURL *)arg1;
- (NSDictionary *)copyLocalETagsForURLs:(NSArray *)arg1;
- (_Bool)getCTag:(id *)arg1 pTag:(id *)arg2 forFolderWithURL:(NSURL *)arg3;
@end

@protocol CoreDAVModifiedContainer
- (CoreDAVPropPatchTask *)copyPropPatchTask;
@end

@protocol CoreDAVTaskDelegate <NSObject>

@optional
- (void)task:(CoreDAVTask *)arg1 didFinishWithError:(NSError *)arg2;
@end

@protocol CoreDAVTaskGroupDelegate <NSObject>

@optional
- (void)taskGroup:(CoreDAVTaskGroup *)arg1 didFinishWithError:(NSError *)arg2;
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

@protocol NSXMLParserDelegate <NSObject>

@optional
- (void)parser:(NSXMLParser *)arg1 validationErrorOccurred:(NSError *)arg2;
- (void)parser:(NSXMLParser *)arg1 parseErrorOccurred:(NSError *)arg2;
- (NSData *)parser:(NSXMLParser *)arg1 resolveExternalEntityName:(NSString *)arg2 systemID:(NSString *)arg3;
- (void)parser:(NSXMLParser *)arg1 foundCDATA:(NSData *)arg2;
- (void)parser:(NSXMLParser *)arg1 foundComment:(NSString *)arg2;
- (void)parser:(NSXMLParser *)arg1 foundProcessingInstructionWithTarget:(NSString *)arg2 data:(NSString *)arg3;
- (void)parser:(NSXMLParser *)arg1 foundIgnorableWhitespace:(NSString *)arg2;
- (void)parser:(NSXMLParser *)arg1 foundCharacters:(NSString *)arg2;
- (void)parser:(NSXMLParser *)arg1 didEndMappingPrefix:(NSString *)arg2;
- (void)parser:(NSXMLParser *)arg1 didStartMappingPrefix:(NSString *)arg2 toURI:(NSString *)arg3;
- (void)parser:(NSXMLParser *)arg1 didEndElement:(NSString *)arg2 namespaceURI:(NSString *)arg3 qualifiedName:(NSString *)arg4;
- (void)parser:(NSXMLParser *)arg1 didStartElement:(NSString *)arg2 namespaceURI:(NSString *)arg3 qualifiedName:(NSString *)arg4 attributes:(NSDictionary *)arg5;
- (void)parser:(NSXMLParser *)arg1 foundExternalEntityDeclarationWithName:(NSString *)arg2 publicID:(NSString *)arg3 systemID:(NSString *)arg4;
- (void)parser:(NSXMLParser *)arg1 foundInternalEntityDeclarationWithName:(NSString *)arg2 value:(NSString *)arg3;
- (void)parser:(NSXMLParser *)arg1 foundElementDeclarationWithName:(NSString *)arg2 model:(NSString *)arg3;
- (void)parser:(NSXMLParser *)arg1 foundAttributeDeclarationWithName:(NSString *)arg2 forElement:(NSString *)arg3 type:(NSString *)arg4 defaultValue:(NSString *)arg5;
- (void)parser:(NSXMLParser *)arg1 foundUnparsedEntityDeclarationWithName:(NSString *)arg2 publicID:(NSString *)arg3 systemID:(NSString *)arg4 notationName:(NSString *)arg5;
- (void)parser:(NSXMLParser *)arg1 foundNotationDeclarationWithName:(NSString *)arg2 publicID:(NSString *)arg3 systemID:(NSString *)arg4;
- (void)parserDidEndDocument:(NSXMLParser *)arg1;
- (void)parserDidStartDocument:(NSXMLParser *)arg1;
@end

@interface BookmarkDAVBookmark : NSObject <CoreDAVLeafDataPayload, NSXMLParserDelegate>
{
    NSURL *_bookmarkURL;
    NSURL *_serverID;
    NSString *_name;
    NSString *_syncKey;
    NSMutableString *_appleAttributeString;
    NSDictionary *_appleAttributes;
    int _parseState;
    int _ignoreLevel;
    CoreDAVErrorItem *_bulkUploadErrorItem;
}

@property(retain, nonatomic) CoreDAVErrorItem *bulkUploadErrorItem; // @synthesize bulkUploadErrorItem=_bulkUploadErrorItem;
@property(readonly, retain, nonatomic) NSDictionary *appleAttributes; // @synthesize appleAttributes=_appleAttributes;
@property(readonly, retain, nonatomic) NSString *name; // @synthesize name=_name;
@property(readonly, retain, nonatomic) NSURL *bookmarkURL; // @synthesize bookmarkURL=_bookmarkURL;
@property(readonly, nonatomic) NSString *syncKey; // @synthesize syncKey=_syncKey;
@property(retain, nonatomic) NSURL *serverID; // @synthesize serverID=_serverID;
@property(readonly, nonatomic) NSData *dataPayload;
- (void)setPropertiesFromXBEL:(id)arg1;
- (void)parser:(id)arg1 foundCDATA:(id)arg2;
- (void)parser:(id)arg1 foundCharacters:(id)arg2;
- (void)parser:(id)arg1 didEndElement:(id)arg2 namespaceURI:(id)arg3 qualifiedName:(id)arg4;
- (void)parser:(id)arg1 didStartElement:(id)arg2 namespaceURI:(id)arg3 qualifiedName:(id)arg4 attributes:(id)arg5;
- (void)dealloc;
- (id)initWithBookmarkURL:(id)arg1 serverID:(id)arg2 name:(id)arg3 syncKey:(id)arg4 appleAttributes:(id)arg5;
- (id)initWithURL:(id)arg1 eTag:(id)arg2 dataPayload:(id)arg3 inContainerWithURL:(id)arg4 withAccountInfoProvider:(id)arg5;

// Remaining properties
@property(readonly, nonatomic) NSArray *childrenOrder;
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

@interface BookmarkDAVBulkPostTask : CoreDAVPostTask
{
    NSString *_checkCTag;
    NSMutableArray *_parsedBookmarks;
    NSMutableDictionary *_parsedBookmarksByURL;
    NSMutableArray *_parsedFolders;
    NSMutableDictionary *_parsedFoldersByURL;
    NSMutableDictionary *_folderURLToChildrenURLOrder;
    NSString *_nextRootCTag;
    NSString *_nextRootSyncToken;
    NSURL *_checkCTagURL;
}

@property(retain, nonatomic) NSString *nextRootSyncToken; // @synthesize nextRootSyncToken=_nextRootSyncToken;
@property(retain, nonatomic) NSString *nextRootCTag; // @synthesize nextRootCTag=_nextRootCTag;
@property(readonly, nonatomic) NSDictionary *folderURLToChildrenURLOrder; // @synthesize folderURLToChildrenURLOrder=_folderURLToChildrenURLOrder;
@property(readonly, nonatomic) NSArray *parsedFolders; // @synthesize parsedFolders=_parsedFolders;
@property(readonly, nonatomic) NSArray *parsedBookmarks; // @synthesize parsedBookmarks=_parsedBookmarks;
- (void)finishCoreDAVTaskWithError:(id)arg1;
- (void)_foundChildrenOrder:(id)arg1 inFolderWithURL:(id)arg2;
- (id)copyDefaultParserForContentType:(id)arg1;
- (id)additionalHeaderValues;
- (void)dealloc;
- (id)initWithDataPayload:(id)arg1 atURL:(id)arg2 checkCTag:(id)arg3 checkCTagURL:(id)arg4;

@end

@interface BookmarkDAVFolder : CoreDAVContainer <CoreDAVModifiedContainer, CoreDAVAddedContainer, CoreDAVLeafDataPayload>
{
    NSDictionary *_appleAttributes;
    NSMutableArray *_childrenOrder;
    NSString *_bulkParsedCTag;
    NSString *_bulkParsedPTag;
    CoreDAVErrorItem *_bulkUploadErrorItem;
}

+ (id)copyPropertyMappingsForParser;
@property(retain, nonatomic) CoreDAVErrorItem *bulkUploadErrorItem; // @synthesize bulkUploadErrorItem=_bulkUploadErrorItem;
@property(retain, nonatomic) NSString *bulkParsedPTag; // @synthesize bulkParsedPTag=_bulkParsedPTag;
@property(retain, nonatomic) NSString *bulkParsedCTag; // @synthesize bulkParsedCTag=_bulkParsedCTag;
@property(readonly, nonatomic) NSDictionary *appleAttributes; // @synthesize appleAttributes=_appleAttributes;
@property(readonly, nonatomic) NSArray *childrenOrder; // @synthesize childrenOrder=_childrenOrder;
@property(readonly, nonatomic) NSString *syncKey;
@property(readonly, nonatomic) NSData *dataPayload;
@property(retain, nonatomic) NSURL *serverID;
- (id)copyMkcolTask;
- (id)copyPropPatchTask;
- (id)_appleAttributesString;
@property(nonatomic) _Bool isBookmarkMenuFolder; // @dynamic isBookmarkMenuFolder;
@property(nonatomic) _Bool isBookmarkBarFolder; // @dynamic isBookmarkBarFolder;
@property(nonatomic) _Bool isBookmarkFolder; // @dynamic isBookmarkFolder;
- (void)_faultResourceType;
- (void)applyParsedProperties:(id)arg1;
- (void)dealloc;
- (id)initWithURL:(id)arg1 eTag:(id)arg2 dataPayload:(id)arg3 inContainerWithURL:(id)arg4 withAccountInfoProvider:(id)arg5;
- (id)initWithServerID:(id)arg1 containerName:(id)arg2 appleAttributes:(id)arg3;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

@interface BookmarkDAVFolderMultiGetTask : CoreDAVFolderContentsMultiGetTask
{
}

- (id)initWithURLs:(id)arg1 atContainerURL:(id)arg2 appSpecificDataItemClass:(Class)arg3;

@end

@interface BookmarkDAVGetAccountPropertiesTaskGroup : CoreDAVGetAccountPropertiesTaskGroup
{
    NSSet *_bookmarkHomes;
}

@property(readonly, nonatomic) NSSet *bookmarkHomes; // @synthesize bookmarkHomes=_bookmarkHomes;
- (void)_setPropertiesFromParsedResponses:(id)arg1;
- (id)homeSet;
- (id)_copyAccountPropertiesPropFindElements;
- (id)description;
- (void)dealloc;

@end

@interface BookmarkDAVMultiGetTask : CoreDAVContainerMultiGetTask
{
}

- (id)initWithURLs:(id)arg1 atContainerURL:(id)arg2 appSpecificDataItemClass:(Class)arg3;

@end

@interface BookmarkDAVRecursiveContainerSyncTaskGroup : CoreDAVRecursiveContainerSyncTaskGroup
{
}

- (_Bool)shouldSyncChildWithResourceType:(id)arg1;
- (id)dataContentType;
- (id)copyFolderMultiGetTaskWithURLs:(id)arg1;
- (id)copyMultiGetTaskWithURLs:(id)arg1;
- (id)initWithFolderURL:(id)arg1 previousCTag:(id)arg2 previousPTag:(id)arg3 previousSyncToken:(id)arg4 actions:(id)arg5 syncItemOrder:(_Bool)arg6 context:(id)arg7 accountInfoProvider:(id)arg8 taskManager:(id)arg9;

@end

@interface BookmarkDAVSyncData : NSObject
{
    void *_db;
    NSMutableDictionary *_backingDict;
    _Bool _hasChanges;
}

@property(readonly, nonatomic) _Bool hasChanges; // @synthesize hasChanges=_hasChanges;
@property(retain, nonatomic) NSNumber *knownQuotaRemaining;
@property(nonatomic) _Bool hasHitQuotaLimit;
@property(retain, nonatomic) NSDictionary *heldAsideOrderings;
@property(retain, nonatomic) NSURL *principalURL;
@property(retain, nonatomic) NSString *accountPrsId;
@property(nonatomic) unsigned long long clientVersion;
@property(nonatomic) unsigned long long bookmarksMenuOrder;
@property(nonatomic) unsigned long long bookmarksBarOrder;
@property(retain, nonatomic) NSString *bookmarksMenuId;
@property(retain, nonatomic) NSString *bookmarksBarId;
@property(retain, nonatomic) NSDictionary *bulkRequests;
@property(retain, nonatomic) NSDictionary *pushTransports;
@property(retain, nonatomic) NSString *syncToken;
@property(retain, nonatomic) NSString *etag;
@property(retain, nonatomic) NSString *ptag;
@property(retain, nonatomic) NSString *ctag;
@property(retain, nonatomic) NSString *pushKey;
@property(nonatomic) _Bool supportsSyncCollection;
@property(nonatomic) _Bool initialSyncDone;
@property(retain, nonatomic) NSURL *homeURL;
- (void)writeToBookmarkDB;
- (void)dealloc;
- (id)initWithBookmarkDatabase:(void *)arg1;

@end

@interface BookmarkDAVSyncDriver : NSObject <CoreDAVLocalDBTreeInfoProvider, CoreDAVDeleteTaskDelegate, CoreDAVGetAccountPropertiesTaskGroupDelegate, CoreDAVContainerInfoTaskGroupDelegate>
{
    id <CoreDAVAccountInfoProvider> _accountInfoProvider;
    id <CoreDAVTaskManager> _taskManager;
    NSMutableSet *_outstandingTaskGroups;
    CDUnknownBlockType _getAccountPropertiesHandler;
    CDUnknownBlockType _syncHandler;
    void *_changeToken;
    NSURL *_homeURL;
    NSString *_pushKey;
    NSDictionary *_pushTransport;
    CDUnknownBlockType _openDBBlock;
    CDUnknownBlockType _getDBBlock;
    CDUnknownBlockType _saveDBBlock;
    CDUnknownBlockType _closeDBBlock;
    BookmarkDAVSyncData *_topLevelSyncData;
    CDUnknownBlockType _registerForPush;
    _Bool _forceSafariOrdering;
    _Bool _forceSave;
}

@property(copy, nonatomic) CDUnknownBlockType syncHandler; // @synthesize syncHandler=_syncHandler;
@property(copy, nonatomic) CDUnknownBlockType getAccountPropertiesHandler; // @synthesize getAccountPropertiesHandler=_getAccountPropertiesHandler;
@property(readonly, nonatomic) id <CoreDAVAccountInfoProvider> accountInfoProvider; // @synthesize accountInfoProvider=_accountInfoProvider;
@property(retain, nonatomic) NSDictionary *pushTransport; // @synthesize pushTransport=_pushTransport;
@property(retain, nonatomic) NSString *pushKey; // @synthesize pushKey=_pushKey;
@property(retain, nonatomic) NSURL *homeURL; // @synthesize homeURL=_homeURL;
@property(readonly, nonatomic) unsigned long long outstandingActionCount;
- (void)notePutToURL:(id)arg1 withDataPayload:(id)arg2 finishedWithIgnoredError:(id)arg3;
- (void)recursiveContainerSyncTask:(id)arg1 completedFullSyncWithNewCTag:(id)arg2 newPTag:(id)arg3 newSyncToken:(id)arg4 error:(id)arg5;
- (void)recursiveContainerSyncTask:(id)arg1 completedSyncOfFolderWithURL:(id)arg2 newCTag:(id)arg3 newPTag:(id)arg4 addedOrModified:(id)arg5 removed:(id)arg6 error:(id)arg7;
- (void)recursiveContainerSyncTask:(id)arg1 retrievedAddedOrModifiedActions:(id)arg2 removed:(id)arg3;
- (void)_handleAddsOrModifies:(id)arg1 removes:(id)arg2;
- (void)recursiveContainerSyncTask:(id)arg1 receivedAddedOrModifiedFolder:(id)arg2;
- (void)_makeFolderFromContainer:(id)arg1;
- (void)_makeBookmarkFromDAVNode:(id)arg1;
- (_Bool)setLocalETag:(id)arg1 forItemWithURL:(id)arg2;
- (id)copyAllLocalURLsInFolderWithURL:(id)arg1;
- (id)copyLocalETagsForURLs:(id)arg1;
- (_Bool)getCTag:(id *)arg1 pTag:(id *)arg2 forFolderWithURL:(id)arg3;
- (void)syncWithRemoteChanges:(_Bool)arg1 completionHandler:(CDUnknownBlockType)arg2;
- (void)_syncWithRemoteChanges:(_Bool)arg1 completionHandler:(CDUnknownBlockType)arg2 skipAddChanges:(_Bool)arg3;
- (void)_setChildrenOrder:(id)arg1 forFolderURL:(id)arg2;
- (int)_clientOrderOfItemPrecedingItemAtServerOrder:(int)arg1 inParentWithURL:(id)arg2;
- (id)_dbRelativeString:(id)arg1;
- (int)_serverOrderForChange:(void *)arg1;
- (void)_setServerIdOnItem:(void *)arg1 isBookmark:(_Bool)arg2 suggestedId:(id)arg3;
- (id)_copyDAVFolderFromFolderRef:(void *)arg1;
- (id)_copyDAVBookmarkFromBookmarkRef:(void *)arg1;
- (void)getAccountPropertiesWithCompletionHandler:(CDUnknownBlockType)arg1;
- (void)containerInfoTask:(id)arg1 completedWithContainers:(id)arg2 error:(id)arg3;
- (void)getAccountPropertiesTask:(id)arg1 completedWithError:(id)arg2;
- (void)_closeDBAndSave:(_Bool)arg1;
- (void)_saveDB;
@property(readonly, nonatomic) BookmarkDAVSyncData *topLevelSyncData;
- (void)_invokeAndNilGetAccountPropertiesHandlerWithSuccess:(_Bool)arg1 error:(id)arg2;
- (void)dealloc;
- (id)initWithAccountInfoProvider:(id)arg1 taskManager:(id)arg2 openDBBlock:(CDUnknownBlockType)arg3 getDBBlock:(CDUnknownBlockType)arg4 saveDBBlock:(CDUnknownBlockType)arg5 closeDBBlock:(CDUnknownBlockType)arg6 registerForPush:(CDUnknownBlockType)arg7 forceSafariOrdering:(_Bool)arg8;
- (void)_finishInitialSyncShouldPushChanges:(_Bool)arg1;
- (_Bool)_applyReturnedBookmarks:(id)arg1 withPushedBookmarks:(struct __CFArray *)arg2;
- (_Bool)_applyReturnedFolders:(id)arg1 parentToArrayOfChildrenFolders:(struct __CFDictionary *)arg2 topmostFolders:(struct __CFArray *)arg3 postedToURL:(id)arg4;
- (_Bool)_matchParsedFolders:(id)arg1 toPushedFolders:(struct __CFDictionary *)arg2 unmatchedParsedFolders:(id)arg3 parsedSetsOfChildrenFoldersByParentURL:(id)arg4 arraysOfChildrenByNameByParent:(struct __CFDictionary *)arg5;
- (void)_setRootCTag:(id)arg1 rootSyncToken:(id)arg2 knownOrderings:(id)arg3;
- (_Bool)_applyUnmatchedParsedFolders:(id)arg1;
- (void)_removeTempIdsFromFoldersInDict:(struct __CFDictionary *)arg1;
- (id)_bookmarkXBELDataForBookmarkChanges:(struct __CFArray *)arg1 pushedBookmarks:(struct __CFArray *)arg2 maxResources:(long long)arg3 maxSize:(long long)arg4;
- (id)_folderXBELDataForTopmostFolderChanges:(struct __CFArray *)arg1 foldersToAddByServerId:(struct __CFDictionary *)arg2 parentToArrayOfChildrenFolderChanges:(struct __CFDictionary *)arg3 pushedParentToArrayOfChildrenFolders:(struct __CFDictionary *)arg4 pushedTopmostFolders:(struct __CFArray *)arg5 maxResources:(long long)arg6 maxSize:(long long)arg7;
- (_Bool)_addChange:(void *)arg1 toData:(id)arg2 numActionsP:(int *)arg3 runningSizeP:(int *)arg4 maxResources:(long long)arg5 maxSize:(long long)arg6 foldersToAddByServerId:(struct __CFDictionary *)arg7 parentToArrayOfChildrenFolderChanges:(struct __CFDictionary *)arg8 pushedParentToArrayOfChildrenFolders:(struct __CFDictionary *)arg9;
- (_Bool)_handleErrorItem:(id)arg1 forBAItem:(void *)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

@interface CoreDAVResourceTypeItem (BookmarkDAVExtensions)
@property(retain, nonatomic) CoreDAVItemWithNoChildren *bookmarkMenuFolder;
@property(retain, nonatomic) CoreDAVItemWithNoChildren *bookmarkBarFolder;
@property(retain, nonatomic) CoreDAVItemWithNoChildren *bookmarkFolder;
- (void)setExtraChild:(id)arg1 forNameSpace:(id)arg2 name:(id)arg3;
- (id)extraChildWithNameSpace:(id)arg1 name:(id)arg2;
@end

