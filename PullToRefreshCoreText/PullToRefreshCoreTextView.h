//
//  PullToRefreshCoreTextView.h
//  PullToRefreshCoreText
//
//  Created by Cem Olcay on 14/10/14.
//  Copyright (c) 2014 questa. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreText/CoreText.h>

#import "FBShimmeringLayer.h"
#import "FBShimmeringView.h"

typedef void(^pullToRefreshAction)(void);

typedef NS_ENUM(NSUInteger, PullToRefreshCoreTextStatus) {
    PullToRefreshCoreTextStatusNatural,
    PullToRefreshCoreTextStatusDragging,
    PullToRefreshCoreTextStatusLoading
};

@interface PullToRefreshCoreTextView : UIView

@property (assign) PullToRefreshCoreTextStatus status;
@property (copy) pullToRefreshAction action;

@property (nonatomic, strong) NSString *pullText;
@property (nonatomic, strong) UIColor *pullTextColor;
@property (nonatomic, strong) UIFont *pullTextFont;

@property (nonatomic, strong) NSString *refreshingText;
@property (nonatomic, strong) UIColor *refreshingTextColor;
@property (nonatomic, strong) UIFont *refreshingTextFont;

@property (nonatomic, strong) CAShapeLayer *textLayer;
@property (nonatomic, strong) CABasicAnimation *pullAnimation;

@property (nonatomic, strong) UIScrollView *scrollView;
@property (nonatomic, strong) FBShimmeringLayer *shimmeringLayer;

- (instancetype)initWithFrame:(CGRect)frame
                     pullText:(NSString *)pullText
                pullTextColor:(UIColor *)pullTextColor
                 pullTextFont:(UIFont *)pullTextFont
               refreshingText:(NSString *)refreshingText
          refreshingTextColor:(UIColor *)refreshingTextColor
           refreshingTextFont:(UIFont *)refreshingTextFont
                       action:(pullToRefreshAction)action;

- (void)endLoading;

@end