//
//  KZ_VideoPlayerViewController.h
//  KZ_VideoPlayer_iOS
//
//  Created by Kieron Zhang on 2018/5/10.
//  Copyright © 2018年 Kieron Zhang. All rights reserved.
//

#import <UIKit/UIKit.h>

@class KZ_VideoPlayerView;

@interface KZ_VideoPlayerViewController : UIViewController

@property (nonatomic, strong) NSString *videoURL;
@property (nonatomic, assign) float progress;

- (id)initWithVideoPlayerView:(KZ_VideoPlayerView *)videoPlayerView;

@end
