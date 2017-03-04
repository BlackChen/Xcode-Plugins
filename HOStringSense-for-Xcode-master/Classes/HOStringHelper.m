//
//  HOStringSense by Dirk Holtwick 2012, holtwick.it
//  Based on OMColorSense by by Ole Zorn, 2012
//  Licensed under BSD style license
//

#import "HOStringHelper.h"
#import "HOStringInfoButton.h"
#import "HOStringFrameView.h"
#import "HOPopoverViewController.h"

#define kHOStringHelperHighlightingDisabled	@"HOStringHelperHighlightingDisabled"

#define NSNullRange NSMakeRange(NSNotFound, 0)

@implementation HOStringHelper

#pragma mark - String Helper

- (NSString *)escapeString:(NSString *)string {
    NSMutableString *result = [NSMutableString string];
    @try {
        NSUInteger length = [string length];
        for (NSUInteger i = 0; i < length; i++) {
            unichar uc = [string characterAtIndex:i];
            switch (uc) {
                case '\"': [result appendString:@"\\\""]; break;
                case '\'': [result appendString:@"\\\'"]; break;
                case '\\': [result appendString:@"\\\\"]; break;
                case '\t': [result appendString:@"\\t"]; break;
                case '\n': [result appendString:@"\\n"]; break;
                case '\r': [result appendString:@"\\r"]; break;
                case '\b': [result appendString:@"\\b"]; break;
                case '\f': [result appendString:@"\\f"]; break;
                default: {
                    if (uc < 0x20) {
                        [result appendFormat:@"\\u%04x", uc];
                    }
                    else {
                        [result appendFormat:@"%C", uc];
                    }
                } break;
            }
        }
        //        }
    }
    @catch (NSException *exception) {
        NSLog(@"Error while converting string: %@", exception);
    }
    return (NSString *)result;
}

#define nextUC ++i; if(i>=length) { break; }; uc = [string characterAtIndex:i];
- (NSString *)unescapeString:(NSString *)string {
    // NSScanner *scanner = [[NSScanner alloc] initWithString:string];
    NSMutableString *result = [NSMutableString string];
    NSUInteger length = [string length];
    for (NSUInteger i = 0; i < length; i++) {
        unichar uc = [string characterAtIndex:i];
        if(uc == '\\') {
            nextUC;
            switch (uc) {
                case '\"': [result appendString:@"\""]; break;
                case '\'': [result appendString:@"\'"]; break;
                case '\\': [result appendString:@"\\"]; break;
                case 't':  [result appendString:@"\t"]; break;
                case 'n':  [result appendString:@"\n"]; break;
                case 'r':  [result appendString:@"\r"]; break;
                case 'b':  [result appendString:@"\b"]; break;
                case 'f':  [result appendString:@"\f"]; break;
                case 'u': {
                    unichar hex[5]; hex[4] = 0;
                    nextUC; hex[0] = uc;
                    nextUC; hex[1] = uc;
                    nextUC; hex[2] = uc;
                    nextUC; hex[3] = uc;

                } break;
                default: {
                    CFStringAppendCharacters((CFMutableStringRef)result, &uc, 1);
                } break;
            }
        }
        else {
            CFStringAppendCharacters((CFMutableStringRef)result, &uc, 1);
        }
    }
    return result;
}

//- (NSString *)unescapeString:(NSString *)string {
//    @try {
//        NSError *error = nil;
//        NSString *s = [NSString stringWithFormat:@"\"%@\"", string];
//        NSString *result = [NSJSONSerialization JSONObjectWithData:[s dataUsingEncoding:NSUTF8StringEncoding]
//                                                           options:NSJSONReadingAllowFragments
//                                                             error:&error];
//        if(!result) {
//            NSLog(@"Error while unescaping: %@", error);
//            return nil;
//        }
//        return result;
//    }
//    @catch (NSException *exception) { ; }
//    return nil;
//}

#pragma mark - Plugin Initialization

+ (void)pluginDidLoad:(NSBundle *)plugin {
	static id sharedPlugin = nil;
	static dispatch_once_t onceToken;
	dispatch_once(&onceToken, ^{
		sharedPlugin = [[self alloc] init];
	});
}

- (id)init {
	if (self = [super init]) {
		[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(applicationDidFinishLaunching:) name:NSApplicationDidFinishLaunchingNotification object:nil];
		_selectedStringRange = NSMakeRange(NSNotFound, 0);
        _stringRegex = [NSRegularExpression regularExpressionWithPattern:@"\"((\\\\\"|.)*?)\""
                                                                  options:0
                                                                    error:NULL];
	}
	return self;
}

- (void)applicationDidFinishLaunching:(NSNotification *)notification {
	NSMenuItem *editMenuItem = [[NSApp mainMenu] itemWithTitle:@"Edit"];
	if (editMenuItem) {
		[[editMenuItem submenu] addItem:[NSMenuItem separatorItem]];

        {
            NSMenuItem *item = [[NSMenuItem alloc] initWithTitle:@"Enable Strings Popover" action:@selector(toggleColorHighlightingEnabled:) keyEquivalent:@""];
            [item setTarget:self];
            [[editMenuItem submenu] addItem:item];
        }

        {
            NSMenuItem *item = [[NSMenuItem alloc] initWithTitle:@"Show Strings Popover" action:@selector(showPopover:) keyEquivalent:@""];
            [item setTarget:self];
            [[editMenuItem submenu] addItem:item];
        }

        //		NSMenuItem *insertColorMenuItem = [[[NSMenuItem alloc] initWithTitle:@"Insert Color..." action:@selector(insertColor:) keyEquivalent:@""] autorelease];
        //		[insertColorMenuItem setTarget:self];
        //		[[editMenuItem submenu] addItem:insertColorMenuItem];
	}

	BOOL highlightingEnabled = ![[NSUserDefaults standardUserDefaults] boolForKey:kHOStringHelperHighlightingDisabled];
	if (highlightingEnabled) {
        [self activateColorHighlighting];
	}
}

#pragma mark - Preferences

- (BOOL)validateMenuItem:(NSMenuItem *)menuItem {
	if ([menuItem action] == @selector(showPopover:)) {
        return ![_stringPopover isShown];
	}
    else if ([menuItem action] == @selector(toggleColorHighlightingEnabled:)) {
		BOOL enabled = [[NSUserDefaults standardUserDefaults] boolForKey:kHOStringHelperHighlightingDisabled];
		[menuItem setState:enabled ? NSOffState : NSOnState];
		return YES;
    }
	return YES;
}

- (void)toggleColorHighlightingEnabled:(id)sender {
	BOOL enabled = [[NSUserDefaults standardUserDefaults] boolForKey:kHOStringHelperHighlightingDisabled];
	[[NSUserDefaults standardUserDefaults] setBool:!enabled forKey:kHOStringHelperHighlightingDisabled];
	if (enabled) {
		[self activateColorHighlighting];
	} else {
		[self deactivateColorHighlighting];
	}
}

- (void)activateColorHighlighting {
	[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(selectionDidChange:) name:NSTextViewDidChangeSelectionNotification object:nil];
	if (!self.textView) {
		NSResponder *firstResponder = [[NSApp keyWindow] firstResponder];
		if ([firstResponder isKindOfClass:NSClassFromString(@"DVTSourceTextView")] && [firstResponder isKindOfClass:[NSTextView class]]) {
			self.textView = (NSTextView *)firstResponder;
		}
	}
	if (self.textView) {
		NSNotification *notification = [NSNotification notificationWithName:NSTextViewDidChangeSelectionNotification object:self.textView];
		[self selectionDidChange:notification];

	}
}

- (void)deactivateColorHighlighting {
	[[NSNotificationCenter defaultCenter] removeObserver:self name:NSTextViewDidChangeSelectionNotification object:nil];
	[self dismissPopover];
	self.textView = nil;
}

#pragma mark - Text Selection Handling

- (void)selectionDidChange:(NSNotification *)notification {
    //    NSLog(@"%s", __PRETTY_FUNCTION__);
	if ([[notification object] isKindOfClass:NSClassFromString(@"DVTSourceTextView")] && [[notification object] isKindOfClass:[NSTextView class]]) {
		self.textView = (NSTextView *)[notification object];
		BOOL disabled = [[NSUserDefaults standardUserDefaults] boolForKey:kHOStringHelperHighlightingDisabled];
		if (disabled) {
            return;
        }
		NSArray *selectedRanges = [self.textView selectedRanges];
		if (selectedRanges.count >= 1) {
			NSRange selectedRange = [[selectedRanges objectAtIndex:0] rangeValue];
			NSString *text = self.textView.textStorage.string;
			NSRange lineRange = [text lineRangeForRange:selectedRange];
			NSRange selectedRangeInLine = NSMakeRange(selectedRange.location - lineRange.location, selectedRange.length);
			NSString *line = [text substringWithRange:lineRange];
			NSRange stringRange = NSNullRange;

            self.selectedStringContent = [self stringInText:line selectedRange:selectedRangeInLine matchedRange:&stringRange];
			if (_selectedStringContent && [_selectedStringContent length] >= 2) {

                // String's content
                NSInteger oldLocation = _selectedStringRange.location;
                self.selectedStringContent = [_selectedStringContent substringWithRange:NSMakeRange(1, _selectedStringContent.length - 2)];
				self.selectedStringRange = NSMakeRange(stringRange.location + lineRange.location, stringRange.length);
                if(oldLocation != _selectedStringRange.location) {
                    [self dismissPopover];
                }

                // Color calculations based ion Xcode theme
				NSColor *backgroundColor = [self.textView.backgroundColor colorUsingColorSpace:[NSColorSpace genericRGBColorSpace]];
				CGFloat r = 1.0; CGFloat g = 1.0; CGFloat b = 1.0;
				[backgroundColor getRed:&r green:&g blue:&b alpha:NULL];
				CGFloat backgroundLuminance = (r + g + b) / 3.0;
				NSColor *strokeColor = (backgroundLuminance > 0.5) ? [NSColor colorWithCalibratedWhite:0.5 alpha:1.000] : [NSColor colorWithCalibratedWhite:1.000 alpha:0.900];

                // Place button
				NSRect selectionRectOnScreen = [self.textView firstRectForCharacterRange:self.selectedStringRange];
				NSRect selectionRectInWindow = [self.textView.window convertRectFromScreen:selectionRectOnScreen];
				NSRect selectionRectInView = [self.textView convertRect:selectionRectInWindow fromView:nil];
                NSRect buttonRect = NSMakeRect(NSMinX(selectionRectInView), NSMinY(selectionRectInView) - selectionRectInView.size.height - 2, 50, selectionRectInView.size.height + 2);
				self.stringButton.frame = NSIntegralRect(buttonRect);

                // Button's label
                NSString * aString = [NSString stringWithFormat:@"%d", (int)[[self unescapeString:_selectedStringContent] length]];
                NSMutableDictionary * aAttributes = [NSMutableDictionary dictionary];
                NSMutableParagraphStyle * aStyle = [[NSParagraphStyle defaultParagraphStyle] mutableCopy];
                aStyle.alignment = NSCenterTextAlignment;
                [aAttributes setValue:[NSColor whiteColor] forKey:NSForegroundColorAttributeName];
                [aAttributes setValue:[NSFont boldSystemFontOfSize:11] forKey:NSFontAttributeName];
                [aAttributes setValue:aStyle forKey:NSParagraphStyleAttributeName];
                NSAttributedString * aAttributedString = [[NSAttributedString alloc] initWithString:aString attributes:aAttributes];
                self.stringButton.attributedTitle = aAttributedString;
                self.stringButton.strokeColor = strokeColor;
				[self.textView addSubview:self.stringButton];

                // Draw the frame around the string
				self.stringFrameView.frame = NSInsetRect(NSIntegralRect(selectionRectInView), -1, -1);
				self.stringFrameView.color = strokeColor;
				[self.textView addSubview:self.stringFrameView];

                return;
			}
		}
        [self removeSelection];
	}
}

- (void)dismissPopover {
    //    NSLog(@"%s", __PRETTY_FUNCTION__);
    if(_stringPopover) {
        [_stringPopover close];
    }
}

- (void)removeSelection {
    //    NSLog(@"%s", __PRETTY_FUNCTION__);
    [self dismissPopover];
	[self.stringButton removeFromSuperview];
	[self.stringFrameView removeFromSuperview];
	self.selectedStringRange = NSNullRange;
	self.selectedStringContent = nil;
}

- (void)stringDidChange:(id)sender {
    //    NSLog(@"%s", __PRETTY_FUNCTION__);
	if (self.selectedStringRange.location == NSNotFound) {
		return;
	}
    NSTextField *textfield = (id)_stringPopoverViewController.view;
    NSString *result = textfield.stringValue;
    if(result) {
        result = [self escapeString:result];
        if(![result isEqualToString:_selectedStringContent]) {
            [self.textView.undoManager beginUndoGrouping];
            [self.textView insertText:[NSString stringWithFormat:@"\"%@\"", result]
                     replacementRange:self.selectedStringRange];
            [self.textView.undoManager endUndoGrouping];
        }
    }
}

//- (void)popoverWillClose:(NSNotification *)notification {
//    NSLog(@"%s", __PRETTY_FUNCTION__);
//    // [self stringDidChange:nil];
//}

- (void)showPopover:(id)sender {
    //    NSLog(@"%s", __PRETTY_FUNCTION__);
    if(_selectedStringRange.location == NSNotFound) {
        return;
    }
    [self dismissPopover];
    if(!_stringPopoverViewController) {
        _stringPopoverViewController = [[HOPopoverViewController alloc] init];
        _stringPopoverViewController.delegate = self;
    }
    NSTextField *textfield = (id)_stringPopoverViewController.view;
    textfield.stringValue = [self unescapeString:_selectedStringContent];
    textfield.font = self.textView.font;
    NSSize size = NSMakeSize(self.textView.bounds.size.width * 0.50, 120);
    if(!_stringPopover) {
        _stringPopover = [[NSPopover alloc] init];
    }
    _stringPopover.contentViewController = _stringPopoverViewController;
    _stringPopover.contentSize = size;
    _stringPopover.delegate = self;
    [_stringPopover showRelativeToRect:self.stringButton.bounds
                                ofView:self.stringButton
                         preferredEdge:NSMinYEdge];
}

#pragma mark - View Initialization

- (HOStringInfoButton *)stringButton {
	if (!_stringButton) {
		_stringButton = [[HOStringInfoButton alloc] initWithFrame:NSMakeRect(0, 0, 100, 30)];
		[_stringButton setTarget:self];
		[_stringButton setAction:@selector(showPopover:)];
	}
	return _stringButton;
}

- (HOStringFrameView *)stringFrameView {
	if (!_stringFrameView) {
		_stringFrameView = [[HOStringFrameView alloc] initWithFrame:NSZeroRect];
	}
	return _stringFrameView;
}

#pragma mark - Color String Parsing

- (NSString *)stringInText:(NSString *)text selectedRange:(NSRange)selectedRange matchedRange:(NSRangePointer)matchedRange {
	__block NSString *foundStringContent = nil;
	__block NSRange foundColorRange = NSMakeRange(NSNotFound, 0);
	[_stringRegex enumerateMatchesInString:text options:0 range:NSMakeRange(0, text.length) usingBlock:^(NSTextCheckingResult *result, NSMatchingFlags flags, BOOL *stop) {
		NSRange colorRange = [result range];
		if (selectedRange.location >= colorRange.location && NSMaxRange(selectedRange) <= NSMaxRange(colorRange)) {
			foundStringContent = [text substringWithRange:[result rangeAtIndex:0]];
			foundColorRange = colorRange;
			*stop = YES;
		}
	}];
    if (foundStringContent) {
		if (matchedRange != NULL) {
			*matchedRange = foundColorRange;
		}
		return foundStringContent;
	}
    return nil;
}

#pragma mark -

- (void)dealloc {
	[[NSNotificationCenter defaultCenter] removeObserver:self];
    [self dismissPopover];
}

@end
