//
//  KZ_VideoPlayer.h
//  KZ_VideoPlayer
//
//  Created by Kieron Zhang on 2016/12/25.
//  Copyright © 2016年 Kieron Zhang. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "KZ_VideoPlayerStatus.h"

@class AVPlayerItem;
@class KZ_VideoPlayer;

@protocol KZ_VideoPlayerDelegate <NSObject>

@optional
- (void)videoPlayerDidPlay:(KZ_VideoPlayer *)videoPlayer;
- (void)videoPlayerDidPause:(KZ_VideoPlayer *)videoPlayer;
- (void)videoPlayerDidStop:(KZ_VideoPlayer *)videoPlayer;
- (void)videoPlayerDidLoadFailed:(KZ_VideoPlayer *)videoPlayer;

- (void)videoPlayer:(KZ_VideoPlayer *)videoPlayer playDuration:(float)duration;
- (void)videoPlayer:(KZ_VideoPlayer *)videoPlayer playProgress:(float)progress;
- (void)videoPlayer:(KZ_VideoPlayer *)videoPlayer playBuffer:(float)buffer;

@end

//系统播放的类
@interface KZ_VideoPlayer : UIView

@property (nonatomic, weak) id<KZ_VideoPlayerDelegate> delegate;
@property (nonatomic, strong) NSString *videoURL;
@property (nonatomic, copy) AVPlayerItem *playerItem;

@property (nonatomic, assign, readonly) BOOL isPlaying;
@property (nonatomic, assign, readonly) double playerDuration;
@property (nonatomic, assign, readonly) double currentTime;

- (BOOL)reloadPlayer;
- (void)playOrPause;
- (void)play;
- (void)pause;
- (void)stop;
- (void)playToProgress:(float)progress;

@end
