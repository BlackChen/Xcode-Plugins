//
//  CocoaPods.m
//
//  Copyright (c) 2013 Delisa Mason. http://delisa.me
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to
//  deal in the Software without restriction, including without limitation the
//  rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
//  sell copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
//  IN THE SOFTWARE.

#import "CCPDocumentationManager.h"
#import "CCPPathResolver.h"
#import "CCPProject.h"
#import "CCPShellRunner.h"
#import "CCPWorkspaceManager.h"
#import "CocoaPods.h"

@interface NSObject (IDEKit)
+ (NSArray *)workspaceWindowControllers;
- (void)close;
@end

@interface CocoaPods () <NSTextFieldDelegate>

@property(nonatomic, strong) NSMenuItem *installPodsItem;
@property(nonatomic, strong) NSMenuItem *outdatedPodsItem;
@property(nonatomic, strong) NSMenuItem *updatePodsItem;
@property(nonatomic, strong) NSMenuItem *installUpdateOfflineItem;
@property(nonatomic, strong) NSMenuItem *installDocsItem;
@property(nonatomic, strong) NSMenuItem *pathItem;
@property(nonatomic, strong) IBOutlet NSTextField *pathField;
@property(nonatomic, strong) IBOutlet NSView *pathView;

@property(nonatomic, strong) NSBundle *bundle;

@end

@implementation CocoaPods

static NSString *const DMMCocoaPodsIntegrateWithDocsKey =
    @"DMMCocoaPodsIntegrateWithDocs";
static NSString *const DMMCocoaPodsShouldInstallUpdateOfflineKey =
    @"DMMCocoaPodsShouldInstallUpdateOffline";
static NSString *const DOCSET_ARCHIVE_FORMAT =
    @"http://cocoadocs.org/docsets/%@/docset.xar";
static NSString *const GEM_EXECUTABLE = @"gem";
static NSString *const GEM_PATH_DEFAULT = @"/usr/bin";
static NSString *const GEM_PATH_KEY = @"GEM_PATH_KEY";
static NSString *const OPEN_EXECUTABLE = @"/usr/bin/open";
static NSString *const POD_EXECUTABLE = @"pod";
static NSString *const RESOLVER_ERROR_FORMAT =
    @"Resolved command path for \"%@\" is invalid.\n\nExpanded GEM_PATH: %@";
static NSString *const RESOLVER_TITLE_TEXT =
    @"The command path could not be resolved";
static NSString *const XAR_EXECUTABLE = @"/usr/bin/xar";

+ (void)pluginDidLoad:(NSBundle *)plugin {
  static id sharedPlugin = nil;
  static dispatch_once_t onceToken;
  dispatch_once(&onceToken, ^{
    sharedPlugin = [[self alloc] initWithBundle:plugin];
  });
}

- (id)initWithBundle:(NSBundle *)plugin {
  if (self = [super init]) {
    _bundle = plugin;
    [[NSNotificationCenter defaultCenter]
        addObserver:self
           selector:@selector(xcodeDidLoad)
               name:NSApplicationDidFinishLaunchingNotification
             object:nil];
  }
  return self;
}

- (void)xcodeDidLoad {
  [[NSNotificationCenter defaultCenter]
      removeObserver:self
                name:NSApplicationDidFinishLaunchingNotification
              object:nil];
  [[NSOperationQueue mainQueue] addOperationWithBlock:^{
    [self loadCustomGemPath];
    [self addMenuItems];
  }];
}

#pragma mark - Menu

- (BOOL)validateMenuItem:(NSMenuItem *)menuItem {
  if ([menuItem isEqual:self.installPodsItem] ||
      [menuItem isEqual:self.outdatedPodsItem] ||
      [menuItem isEqual:self.updatePodsItem]) {
    return [[CCPProject projectForKeyWindow] hasPodfile];
  }

  return YES;
}

- (void)addMenuItems {
  NSMenuItem *topMenuItem = [[NSApp mainMenu] itemWithTitle:@"Product"];
  if (topMenuItem) {
    NSMenuItem *cocoaPodsMenu = [[NSMenuItem alloc] initWithTitle:@"CocoaPods"
                                                           action:nil
                                                    keyEquivalent:@""];
    cocoaPodsMenu.submenu = [[NSMenu alloc] initWithTitle:@"CocoaPods"];

    self.installDocsItem =
        [[NSMenuItem alloc] initWithTitle:@"Install Docs during Integration"
                                   action:@selector(toggleInstallDocsForPods)
                            keyEquivalent:@""];
    self.installDocsItem.state =
        [self shouldInstallDocsForPods] ? NSOnState : NSOffState;

    self.installPodsItem =
        [[NSMenuItem alloc] initWithTitle:@"Install Pods"
                                   action:@selector(integratePods)
                            keyEquivalent:@""];

    self.installUpdateOfflineItem =
        [[NSMenuItem alloc] initWithTitle:@"Update and Install Offline Only"
                                   action:@selector(toggleInstallUpdateOffline)
                            keyEquivalent:@""];
    self.installUpdateOfflineItem.state =
        [self shouldInstallUpdateOffline] ? NSOnState : NSOffState;
    self.outdatedPodsItem =
        [[NSMenuItem alloc] initWithTitle:@"Check for Outdated Pods"
                                   action:@selector(checkForOutdatedPods)
                            keyEquivalent:@""];

    self.updatePodsItem =
        [[NSMenuItem alloc] initWithTitle:@"Update Pods"
                                   action:@selector(updatePods)
                            keyEquivalent:@""];

    NSMenuItem *createPodfileItem =
        [[NSMenuItem alloc] initWithTitle:@"Create/Edit Podfile"
                                   action:@selector(createPodfile)
                            keyEquivalent:@""];

    NSMenuItem *createPodspecItem =
        [[NSMenuItem alloc] initWithTitle:@"Create/Edit Podspec"
                                   action:@selector(createPodspecFile)
                            keyEquivalent:@""];

    [[self bundle] loadNibNamed:@"PodPathView" owner:self topLevelObjects:nil];
    self.pathItem = [[NSMenuItem alloc] initWithTitle:@"Set POD_PATH"
                                               action:@selector(setPATH)
                                        keyEquivalent:@""];

    [self.pathField.cell setPlaceholderString:GEM_PATH_DEFAULT];

    if ([self customGemPath].length > 0) {
      self.pathField.stringValue = [self customGemPath];
    }

    [self.pathItem setView:self.pathView];

    [self.installDocsItem setTarget:self];
    [self.installPodsItem setTarget:self];
    [self.installUpdateOfflineItem setTarget:self];
    [self.outdatedPodsItem setTarget:self];
    [self.updatePodsItem setTarget:self];
    [createPodfileItem setTarget:self];
    [createPodspecItem setTarget:self];
    [self.pathItem setTarget:self];

    [[cocoaPodsMenu submenu] addItem:self.installPodsItem];
    [[cocoaPodsMenu submenu] addItem:self.outdatedPodsItem];
    [[cocoaPodsMenu submenu] addItem:self.updatePodsItem];
    [[cocoaPodsMenu submenu] addItem:self.installUpdateOfflineItem];
    [[cocoaPodsMenu submenu] addItem:[NSMenuItem separatorItem]];
    [[cocoaPodsMenu submenu] addItem:createPodfileItem];
    [[cocoaPodsMenu submenu] addItem:createPodspecItem];
    [[cocoaPodsMenu submenu] addItem:[NSMenuItem separatorItem]];
    [[cocoaPodsMenu submenu] addItem:self.installDocsItem];
    [[cocoaPodsMenu submenu] addItem:[NSMenuItem separatorItem]];
    [[cocoaPodsMenu submenu] addItem:self.pathItem];

    [[topMenuItem submenu]
        insertItem:cocoaPodsMenu
           atIndex:[topMenuItem.submenu indexOfItemWithTitle:@"Build For"]];
  }
}

- (BOOL)control:(NSControl *)control
    textShouldEndEditing:(NSText *)fieldEditor {
  NSLog(@"endEditing : %@", fieldEditor.string);
  [self updateGemPath:fieldEditor.string];
  return YES;
}

#pragma mark - Menu Actions

- (void)toggleInstallDocsForPods {
  [self setShouldInstallDocsForPods:![self shouldInstallDocsForPods]];
}

- (void)toggleInstallUpdateOffline {
  [self setShouldInstallUpdateOffline:![self shouldInstallUpdateOffline]];
}

- (void)createPodfile {
  CCPProject *project = [CCPProject projectForKeyWindow];
  NSString *podFilePath = project.podfilePath;

  if (![project hasPodfile]) {
    NSError *error = nil;
    [[NSFileManager defaultManager]
        copyItemAtPath:[self.bundle pathForResource:@"DefaultPodfile"
                                             ofType:@""]
                toPath:podFilePath
                 error:&error];
    if (error) {
      [[NSAlert alertWithError:error] runModal];
    }
  }

  [[[NSApplication sharedApplication] delegate]
      application:[NSApplication sharedApplication]
         openFile:podFilePath];
}

- (void)createPodspecFile {
  CCPProject *project = [CCPProject projectForKeyWindow];
  NSString *podspecPath = project.podspecPath;

  if (![project hasPodspecFile]) {
    NSString *podspecTemplate = [NSString
        stringWithContentsOfFile:[self.bundle pathForResource:@"DefaultPodspec"
                                                       ofType:@""]
                        encoding:NSUTF8StringEncoding
                           error:nil];

    [project createPodspecFromTemplate:podspecTemplate];
  }

  [[[NSApplication sharedApplication] delegate]
      application:[NSApplication sharedApplication]
         openFile:podspecPath];
}

- (void)integratePods {
  CCPProject *project = [CCPProject projectForKeyWindow];
  BOOL isDir;
  BOOL fileExists =
      [[NSFileManager defaultManager] fileExistsAtPath:project.workspacePath
                                           isDirectory:&isDir];
  NSMutableArray *arguments = [@[ @"install" ] mutableCopy];
  if ([self shouldInstallUpdateOffline]) {
    [arguments addObject:@"--no-repo-update"];
  }
  [self runPodWithArguments:arguments
                 completion:^(NSTask *t) {
                   if ([self shouldInstallDocsForPods])
                     [self installOrUpdateDocSetsForPods];
                   // Only prompt if this is the first time
                   if (!fileExists || !isDir) {
                     dispatch_async(dispatch_get_main_queue(), ^{
                       [self showReopenWorkspaceMessageForProject:project];
                     });
                   }
                 }];
}

- (void)showReopenWorkspaceMessageForProject:(CCPProject *)project {
  NSBeginAlertSheet(
      @"Do you want to open the workspace?", @"Yes", nil, @"No", nil, self,
      @selector(sheetDidEndShouldReopenWorkspace:returnCode:contextInfo:), NULL,
      (__bridge_retained void *)project,
      @"[!] From now on use `%@.xcworkspace`.", project.projectName);
}

- (void)sheetDidEndShouldReopenWorkspace:(NSWindow *)sheet
                              returnCode:(NSInteger)returnCode
                             contextInfo:(void *)contextInfo {
  [sheet close];
  if (returnCode == NSAlertDefaultReturn) {
    [self closeCurrentWorkspace];

    CCPProject *project = (__bridge_transfer id)contextInfo;
    [self openWorkspaceForProject:project];
  }
}

- (void)openWorkspaceForProject:(CCPProject *)project {
  NSString *directoryPath = project.directoryPath;
  NSString *workspacePath = project.workspacePath;

  [CCPShellRunner runShellCommand:OPEN_EXECUTABLE
                         withArgs:@[ workspacePath ]
                        directory:directoryPath
                       completion:nil];
}

- (void)closeCurrentWorkspace {
  NSArray *workspaceWindowControllers = [NSClassFromString(
      @"IDEWorkspaceWindowController") workspaceWindowControllers];
  [workspaceWindowControllers
      enumerateObjectsUsingBlock:^(id controller, NSUInteger idx, BOOL *stop) {
        if ([[controller valueForKey:@"window"] isMainWindow]) {
          id workspaceDocument = [[controller valueForKey:@"window"] document];
          NSLog(@"Closing workspace : %@", workspaceDocument);
          [workspaceDocument performSelectorOnMainThread:@selector(close)
                                              withObject:nil
                                           waitUntilDone:YES];
        }
      }];
}

- (void)checkForOutdatedPods {
  NSMutableArray *arguments = [@[ @"outdated" ] mutableCopy];
  if ([self shouldInstallUpdateOffline]) {
    [arguments addObject:@"--no-repo-update"];
  }
  [self runPodWithArguments:arguments completion:NULL];
}

- (void)updatePods {
  NSMutableArray *arguments = [@[ @"update" ] mutableCopy];
  if ([self shouldInstallUpdateOffline]) {
    [arguments addObject:@"--no-repo-update"];
  }
  [self runPodWithArguments:arguments completion:NULL];
}

- (void)installCocoaPods {
  [self runPodWithArguments:@[ @"install", @"cocoapods" ] completion:NULL];
}

- (void)installOrUpdateDocSetsForPods {
  for (NSString *podName in
       [CCPWorkspaceManager installedPodNamesInCurrentWorkspace]) {
    NSURL *docsetURL =
        [NSURL URLWithString:[NSString stringWithFormat:DOCSET_ARCHIVE_FORMAT,
                                                        podName]];
    [NSURLConnection
        sendAsynchronousRequest:[NSURLRequest requestWithURL:docsetURL]
                          queue:[NSOperationQueue mainQueue]
              completionHandler:^(NSURLResponse *response, NSData *xarData,
                                  NSError *connectionError) {
                if (xarData) {
                  NSString *fileName =
                      [NSString stringWithFormat:@"%@.xar", podName];
                  NSString *tmpFilePath = [NSString
                      pathWithComponents:@[ NSTemporaryDirectory(), fileName ]];
                  [xarData writeToFile:tmpFilePath atomically:YES];
                  [self extractAndInstallDocsAtPath:tmpFilePath];
                }
              }];
  }
}

- (void)extractAndInstallDocsAtPath:(NSString *)path {
  NSArray *arguments =
      @[ @"-xf", path, @"-C", [CCPDocumentationManager docsetInstallPath] ];
  [CCPShellRunner runShellCommand:XAR_EXECUTABLE
                         withArgs:arguments
                        directory:NSTemporaryDirectory()
                       completion:nil];
}

- (void)runPodWithArguments:(NSArray *)args
                 completion:(void (^)(NSTask *t))completion {
  NSString *const CPFallbackPodPath = @"/usr/local/bin";
  NSString *expandedGemPath =
      [CCPPathResolver stringByAdjustingGemPathForEnvironment:[self gemPath]];
  NSString *resolvedCommand =
      [CCPPathResolver resolveCommand:POD_EXECUTABLE forPath:expandedGemPath];

  if (resolvedCommand == nil) {
    resolvedCommand = [CCPPathResolver resolveCommand:POD_EXECUTABLE
                                              forPath:CPFallbackPodPath];
    if (resolvedCommand == nil) {
      NSAlert *alert = [[NSAlert alloc] init];
      [alert setAlertStyle:NSCriticalAlertStyle];
      [alert setMessageText:RESOLVER_TITLE_TEXT];
      [alert
          setInformativeText:[NSString stringWithFormat:RESOLVER_ERROR_FORMAT,
                                                        POD_EXECUTABLE,
                                                        expandedGemPath]];
      [alert runModal];
      return;
    }
  }

  [CCPShellRunner
      runShellCommand:resolvedCommand
             withArgs:args
            directory:[CCPWorkspaceManager currentWorkspaceDirectoryPath]
           completion:completion];
}

- (void)showResolverErrorForExecutable:(NSString *)executable
                          expandedPath:(NSString *)expandedPath {
  NSAlert *alert = [[NSAlert alloc] init];
  [alert setAlertStyle:NSCriticalAlertStyle];
  [alert setMessageText:RESOLVER_TITLE_TEXT];
  [alert
      setInformativeText:[NSString stringWithFormat:RESOLVER_ERROR_FORMAT,
                                                    executable, expandedPath]];
  [alert runModal];
}

#pragma mark - Preferences

- (BOOL)shouldInstallDocsForPods {
  return [[NSUserDefaults standardUserDefaults]
      boolForKey:DMMCocoaPodsIntegrateWithDocsKey];
}

- (void)setShouldInstallDocsForPods:(BOOL)enabled {
  [[NSUserDefaults standardUserDefaults]
      setBool:enabled
       forKey:DMMCocoaPodsIntegrateWithDocsKey];
  self.installDocsItem.state = enabled ? NSOnState : NSOffState;
}

- (BOOL)shouldInstallUpdateOffline {
  return [[NSUserDefaults standardUserDefaults]
      boolForKey:DMMCocoaPodsShouldInstallUpdateOfflineKey];
}

- (void)setShouldInstallUpdateOffline:(BOOL)shouldBeOffline {
  [[NSUserDefaults standardUserDefaults]
      setBool:shouldBeOffline
       forKey:DMMCocoaPodsShouldInstallUpdateOfflineKey];
  self.installUpdateOfflineItem.state =
      shouldBeOffline ? NSOnState : NSOffState;
}

- (void)updateGemPath:(NSString *)string {
  if (string.length == 0) {
    [[NSUserDefaults standardUserDefaults] removeObjectForKey:GEM_PATH_KEY];
  } else {
    [[NSUserDefaults standardUserDefaults] setObject:string
                                              forKey:GEM_PATH_KEY];
  }
  [[NSUserDefaults standardUserDefaults] synchronize];

  [self loadCustomGemPath];
}

- (void)loadCustomGemPath {
  NSString *newPath = [CCPPathResolver
      stringByAdjustingGemPathForEnvironment:[self customGemPath]];
  if (newPath.length > 0) {
    char *oldPath = getenv("PATH");
    newPath = [NSString stringWithFormat:@"%@:%s", newPath, oldPath];
    setenv("PATH", [newPath UTF8String], 1);
  }
}

- (NSString *)customGemPath {
  return [[NSUserDefaults standardUserDefaults] objectForKey:GEM_PATH_KEY];
}

- (NSString *)gemPath {
  NSString *path = [self customGemPath];
  if (path.length == 0) {
    path = GEM_PATH_DEFAULT;
  }
  return path;
}

@end
