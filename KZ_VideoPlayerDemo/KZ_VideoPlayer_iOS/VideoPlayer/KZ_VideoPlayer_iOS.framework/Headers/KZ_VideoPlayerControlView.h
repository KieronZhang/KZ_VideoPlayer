//
//  KZ_VideoPlayerControlView.h
//  KZ_VideoPlayer
//
//  Created by Kieron Zhang on 2016/12/25.
//  Copyright © 2016年 Kieron Zhang. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "KZ_VideoPlayerStatus.h"

//左右滑动的时候出现的view
@interface KZ_VideoPlayerProgressView : UIView

@property (nonatomic, assign) float currentProgress;
@property (nonatomic, strong) UIProgressView *progressView;
@property (nonatomic, strong) UILabel *progressLabel;

- (void)setProgress:(float)progress title:(NSString *)title;

@end

@class KZ_VideoPlayerControlView;

@protocol KZ_VideoPlayerControlViewDelegate <NSObject>

@optional
- (void)videoPlayerControlViewDidClickPlayButton:(KZ_VideoPlayerControlView *)controlView;
- (void)videoPlayerControlView:(KZ_VideoPlayerControlView *)controlView didUpdateProgress:(float)progress;
- (void)videoPlayerControlViewDidClickFullScreenButton:(KZ_VideoPlayerControlView *)controlView;
- (void)videoPlayerControlViewDidAppear:(KZ_VideoPlayerControlView *)controlView;
- (void)videoPlayerControlViewDidDisappear:(KZ_VideoPlayerControlView *)controlView;
- (void)videoPlayerControlViewDidTapAtControlView:(KZ_VideoPlayerControlView *)controlView;
- (void)videoPlayerControlViewDidDoubleTapAtControlView:(KZ_VideoPlayerControlView *)controlView;
- (void)videoPlayerControlViewDidClickAtFailedStatus:(KZ_VideoPlayerControlView *)controlView;
- (void)videoPlayerControlViewDidClickCloseButton:(KZ_VideoPlayerControlView *)controlView;

@end

@interface KZ_VideoPlayerControlView : UIView {
    UISlider *volumeViewSlider; //系统声音
    float systemVolume;
}
@property (nonatomic, weak) id<KZ_VideoPlayerControlViewDelegate> delegate;
@property (nonatomic, assign) KZ_VideoPlayerViewPlayStatus playStatus;
@property (nonatomic, assign) KZ_VideoPlayerControlGestureType gestureType;
@property (nonatomic, strong) UIImage *coverImage;
@property (nonatomic, assign) float progress;
@property (nonatomic, assign) float bufferProgress;
@property (nonatomic, assign) float playerDuration;
@property (nonatomic, assign) BOOL isFullScreen;

@property (nonatomic, strong) UIView *normalBackgroundView;
@property (nonatomic, strong) UIView *backgroundView;
@property (nonatomic, strong) UIButton *playButton;
@property (nonatomic, strong) UIView *bottomView;
@property (nonatomic, strong) UILabel *currentTimeLabel;
@property (nonatomic, strong) UILabel *totalTimeLabel;
@property (nonatomic, strong) UISlider *progressSlider;
@property (nonatomic, strong) UIProgressView *progressBufferView;
@property (nonatomic, strong) UIButton *fullScreenButton;
@property (nonatomic, strong) UIImageView *coverImageView;
@property (nonatomic, strong) UIProgressView *largeBufferView;
@property (nonatomic, strong) UIProgressView *largeProgressView;
@property (nonatomic, strong) KZ_VideoPlayerProgressView *playerProgressView;

@property (nonatomic, strong) UIView *smallBackgroundView;
@property (nonatomic, strong) UIButton *closeButton;

@property (nonatomic, strong) UILabel *failedLabel;

- (void)appearOrDisappear;
- (void)appear;
- (void)disappear;

- (void)transToNormalScreen;
- (void)transToSmallScreen;

@end
