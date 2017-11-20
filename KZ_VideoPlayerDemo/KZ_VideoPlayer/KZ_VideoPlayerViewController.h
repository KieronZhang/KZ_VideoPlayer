//
//  KZ_VideoPlayerViewController.h
//  KZ_VideoPlayer
//
//  Created by Kieron Zhang on 2016/12/25.
//  Copyright © 2016年 Kieron Zhang. All rights reserved.
//

#import <UIKit/UIKit.h>

@class KZ_VideoPlayerView;

@interface KZ_VideoPlayerViewController : UIViewController

@property (nonatomic, strong) NSString *videoURL;
@property (nonatomic, assign) float progress;

- (id)initWithVideoPlayerView:(KZ_VideoPlayerView *)videoPlayerView;

@end
