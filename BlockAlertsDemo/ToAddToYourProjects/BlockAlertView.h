//
//  BlockAlertView.h
//
//

#import <UIKit/UIKit.h>

enum {
    kAlertViewAnimationSlideFromTop = 1, // Default, slide from top
    kAlertViewAnimationFadeIn,	// Fade in
};
typedef NSUInteger kAlertViewAnimationType;

@interface BlockAlertView : NSObject {
@protected
    UIView *_view;
    NSMutableArray *_blocks;
    CGFloat _height;
    NSUInteger animationType;
	
    id _selfRetain;
}

+ (BlockAlertView *)alertWithTitle:(NSString *)title message:(NSString *)message;

- (id)initWithTitle:(NSString *)title message:(NSString *)message;

- (void)setDestructiveButtonWithTitle:(NSString *)title block:(void (^)())block;
- (void)setCancelButtonWithTitle:(NSString *)title block:(void (^)())block;
- (void)addButtonWithTitle:(NSString *)title block:(void (^)())block;

- (void)show;
- (void) showWithAnimation:(kAlertViewAnimationType)_animationType;
- (void)dismissWithClickedButtonIndex:(NSInteger)buttonIndex animated:(BOOL)animated;

@property (nonatomic, assign) UIImage *backgroundImage;
@property (nonatomic, readonly) UIView *view;
@property (nonatomic, readwrite) BOOL vignetteBackground;

@end
