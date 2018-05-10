//
//  KZ_VideoPlayerView.h
//  KZ_VideoPlayer
//
//  Created by Kieron Zhang on 2016/12/25.
//  Copyright © 2016年 Kieron Zhang. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "KZ_VideoPlayerStatus.h"
#import "KZ_VideoPlayerControlView.h"

@class AVPlayerItem;
@class KZ_VideoPlayerView;

@protocol KZ_VideoPlayerViewDelegate <NSObject>

@optional
- (void)videoPlayerViewDidPlay:(KZ_VideoPlayerView *)playerView; //播放器开始播放
- (void)videoPlayerViewDidPause:(KZ_VideoPlayerView *)playerView; //播放器暂停播放
- (void)videoPlayerViewDidStop:(KZ_VideoPlayerView *)playerView; //播放器停止播放
- (void)videoPlayerViewDidLoadFailed:(KZ_VideoPlayerView *)playerView;

- (void)videoPlayerView:(KZ_VideoPlayerView *)playerView playDuration:(float)duration; //返回当前播放器的总时长
- (void)videoPlayerView:(KZ_VideoPlayerView *)playerView playBuffer:(float)buffer; //返回当前播放器的缓存时长
- (void)videoPlayerView:(KZ_VideoPlayerView *)playerView playProgress:(float)progress; //返回当前播放器的播放进度时长

- (void)videoPlayerViewDidEnterFullScreen:(KZ_VideoPlayerView *)playerView; //播放器进入全屏
- (void)videoPlayerViewDidExitFullScreen:(KZ_VideoPlayerView *)playerView; //播放器退出全屏
- (void)videoPlayerView:(KZ_VideoPlayerView *)playerView didRotateToOrientation:(UIDeviceOrientation)orientation; //播放器旋转到一个角度
- (void)videoPlayerViewDidTap:(KZ_VideoPlayerView *)playerView;

- (void)videoPlayerViewControlDidAppear:(KZ_VideoPlayerView *)playerView; //控制器显示
- (void)videoPlayerViewControlDidDisappear:(KZ_VideoPlayerView *)playerView; //控制器隐藏

@end

//这个类是底层的一个view 用来添加播放器的view和播放器控制的view 这两个view之间没有相互调用 都是通过这个类来调用的
@interface KZ_VideoPlayerView : UIView

@property (nonatomic, weak) id<KZ_VideoPlayerViewDelegate> delegate;
@property (nonatomic, strong) NSString *videoURL; //url支持web的url 也支持本地的路径
@property (nonatomic, strong) AVPlayerItem *playerItem; //playerItem是苹果支持的播放item 就算传了url其实也是转换成playerItem来播放的

@property (nonatomic, assign) KZ_VideoPlayerViewPlayStatus playStatus; //播放状态
@property (nonatomic, assign) KZ_VideoPlayerControlGestureType gestureType; //支持的手势
@property (nonatomic, assign) KZ_VideoPlayerControlGestureType fullScreenGestureType; //全屏模式支持的手势
@property (nonatomic, strong) KZ_VideoPlayerControlView *playerControlView;
@property (nonatomic, strong) UIImage *coverImage;
@property (nonatomic, assign) BOOL lockOrientation; //锁住旋转
@property (nonatomic, assign) BOOL isFullScreen; //是否是全屏，可以通过设置这个来强行全屏
@property (nonatomic, assign) float autoDisappearControlViewDelay; //播放时控制view自动隐藏时间 为0不隐藏
@property (nonatomic, assign, readonly) BOOL isPlaying; //是否在播放中
@property (nonatomic, assign, readonly) double playerDuration; //视频的总时长
@property (nonatomic, assign, readonly) double currentTime; //播放当前的时间

@property (nonatomic, assign) BOOL shouldSmallScreen; //当屏幕滚动时候是否要显示小屏幕
@property (nonatomic, assign) BOOL isSmallScreen; //当前是否是小屏幕
@property (nonatomic, assign) CGRect smallScreenRect; //小屏幕尺寸
@property (nonatomic, assign) BOOL shouldOrientationWhenSmallScreen; //小屏幕是是否支持旋转

+ (instancetype)sharedVideoPlayerView;

//旋转到一个特定的角度 force如果为NO则还可以通过旋转手机调整，否则除非是旋转到竖屏，其他旋转都不支持
- (void)didRotateToOrientation:(UIDeviceOrientation)orientation force:(BOOL)force;
- (BOOL)reloadPlayer;
- (void)playOrPause; //如果播放就暂停，如果没有播放就播放
- (void)play; //播放
- (void)pause; //暂定
- (void)stop;
- (void)playToProgress:(float)progress; //播放到一个位置，设置的是播放的时间（秒级时间戳） 不是比例

- (void)playWithVideoURL:(NSString *)videoURL frame:(CGRect)frame tableView:(UITableView *)tableView indexPath:(NSIndexPath *)indexPath;

- (void)transToNormalScreen;
- (void)transToSmallScreen;

- (void)removeTableView:(BOOL)stop;

@end
