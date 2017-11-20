//
//  KZ_VideoPlayerViewController.m
//  KZ_VideoPlayer
//
//  Created by Kieron Zhang on 2016/12/25.
//  Copyright © 2016年 Kieron Zhang. All rights reserved.
//

#import "KZ_VideoPlayerViewController.h"
#import <KZ_VideoPlayerFramework/KZ_VideoPlayerView.h>

@interface KZ_VideoPlayerViewController () <KZ_VideoPlayerViewDelegate>

@property (nonatomic, strong) KZ_VideoPlayerView *videoPlayerView;

@end

@implementation KZ_VideoPlayerViewController

- (id)initWithVideoPlayerView:(KZ_VideoPlayerView *)videoPlayerView {
    self = [super init];
    if (self) {
        self.videoPlayerView = videoPlayerView;
    }
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    self.title = @"视频";
    
    self.videoPlayerView = [KZ_VideoPlayerView sharedVideoPlayerView];
    [self.videoPlayerView transToNormalScreen];
    self.videoPlayerView.frame = CGRectMake(0, 64, CGRectGetWidth(self.view.bounds), 200);
    if (self.videoPlayerView.superview) {
        [self.videoPlayerView removeFromSuperview];
    }
    self.videoPlayerView.playerControlView.coverImageView.contentMode = UIViewContentModeScaleAspectFill;
    self.videoPlayerView.gestureType = KZ_VideoPlayerControlGestureType_All;
    self.videoPlayerView.delegate = self;
    self.videoPlayerView.videoURL = self.videoURL;
    self.videoPlayerView.coverImage = [UIImage imageNamed:@"cover.jpg"];
    [self.view addSubview:self.videoPlayerView];
    if (self.progress > 0) {
        [self.videoPlayerView playToProgress:self.progress];
        [self.videoPlayerView play];
    }
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

- (void)dealloc {
    if (self.videoPlayerView) {
        [self.videoPlayerView removeFromSuperview];
        [self.videoPlayerView stop];
        self.videoPlayerView = nil;
    }
    NSLog(@"dealloc");
}

@end
