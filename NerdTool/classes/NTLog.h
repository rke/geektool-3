//
//  NTLog.h
//  NerdTool
//
//  Created by Kevin Nygaard on 7/20/09.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class NTGroup;
@class LogWindow;

@interface NTLog : NSObject
{
    NSMutableDictionary *properties;
    NSNumber *active;
    NTGroup *parentGroup;

    NSWindowController *windowController;
    LogWindow *window;

    BOOL _loadedView;
    IBOutlet id prefsView;

    id highlightSender;
    BOOL postActivationRequest;
    BOOL _isBeingDragged;

    NSArray *arguments;
    NSDictionary *env;
    NSTimer *timer;
    NSTask *task;
    BOOL timerNeedsUpdate;
}
@property (retain) NSMutableDictionary *properties;
@property (copy) NSNumber *active;
@property (assign) NTGroup *parentGroup;

@property (retain) NSWindowController *windowController;
@property (assign) LogWindow *window;

@property (assign) IBOutlet id prefsView;

@property (assign) id highlightSender;
@property (assign) BOOL postActivationRequest;
@property (assign) BOOL _isBeingDragged;

@property (copy) NSArray *arguments;
@property (copy) NSDictionary *env;
@property (retain) NSTimer *timer;
@property (retain) NSTask *task;
@property (assign) BOOL timerNeedsUpdate;

// Most likely to subclass
// Properties
- (NSString *)logTypeName;
- (BOOL)needsDisplayUIBox;
- (NSString *)preferenceNibName;
- (NSString *)displayNibName;
- (NSDictionary *)defaultProperties;
// Interface
- (void)setupInterfaceBindingsWithObject:(id)bindee;
- (void)destroyInterfaceBindings;
// Observing
- (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary *)change context:(void *)context;
// Window Management
- (void)createWindow;
- (void)updateWindow;
// Task
- (void)updateCommand:(NSTimer*)timer;
- (void)processNewDataFromTask:(NSNotification*)aNotification;
// Log Container
- (id)initWithProperties:(NSDictionary*)newProperties;
- (id)init;
- (void)dealloc;
// Interface
- (NSView *)loadPrefsViewAndBind:(id)bindee;
- (NSView *)unloadPrefsViewAndUnbind;
- (void)setupPreferenceObservers;
- (void)removePreferenceObservers;
// KVC
- (void)set_isBeingDragged:(BOOL)var;

// Log Process
// Management
- (void)createLogProcess;
- (void)destroyLogProcess;
// Observing
- (void)setupProcessObservers;
- (void)removeProcessObservers;
- (void)notificationHandler:(NSNotification *)notification;
// KVC
- (void)setTimer:(NSTimer*)newTimer;
- (void)killTimer;
- (void)updateTimer;
// Window Management
- (void)setupLogWindowAndDisplay;
- (void)setHighlighted:(BOOL)val from:(id)sender;
- (void)front;

// Convience
- (NSRect)screenToRect:(NSRect)appleCoordRect;
- (NSRect)rect;
- (BOOL)equals:(NTLog*)comp;
- (NSString*)description;
// Copying
- (id)copyWithZone:(NSZone *)zone;
- (id)mutableCopyWithZone:(NSZone *)zone;
// Coding
- (id)initWithCoder:(NSCoder *)coder;
- (void)encodeWithCoder:(NSCoder *)coder;
@end
