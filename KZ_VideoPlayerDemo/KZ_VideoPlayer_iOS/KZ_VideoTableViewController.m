//
//  KZ_VideoTableViewController.m
//  KZ_VideoPlayer_iOS
//
//  Created by Kieron Zhang on 2018/5/10.
//  Copyright © 2018年 Kieron Zhang. All rights reserved.
//

#import "KZ_VideoTableViewController.h"
#import "KZ_VideoPlayerCell.h"
#import "KZ_VideoModel.h"
#import "KZ_VideoPlayerViewController.h"
#import <KZ_MacroDefinition_iOS/KZ_MacroDefinition.h>
#import <KZ_VideoPlayer_iOS/KZ_VideoPlayerView.h>

@interface KZ_VideoTableViewController () <KZ_VideoPlayerCellDelegate, KZ_VideoPlayerViewDelegate>

@property (nonatomic, strong) KZ_VideoModel *currentVideoModel;

@end

@implementation KZ_VideoTableViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"视频列表";
    videoArray = [[NSMutableArray alloc] initWithCapacity:0];
    
    NSArray *videoListArray = @[@"http://wvideo.spriteapp.cn/video/2016/0328/56f8ec01d9bfe_wpd.mp4",
                                @"http://baobab.wdjcdn.com/1456117847747a_x264.mp4",
                                @"http://baobab.wdjcdn.com/14525705791193.mp4",
                                @"http://baobab.wdjcdn.com/1456459181808howtoloseweight_x264.mp4",
                                @"http://baobab.wdjcdn.com/1455968234865481297704.mp4",
                                @"http://baobab.wdjcdn.com/1455782903700jy.mp4",
                                @"http://baobab.wdjcdn.com/14564977406580.mp4",
                                @"http://baobab.wdjcdn.com/1456316686552The.mp4",
                                @"http://baobab.wdjcdn.com/1456480115661mtl.mp4",
                                @"http://baobab.wdjcdn.com/1456665467509qingshu.mp4",
                                @"http://baobab.wdjcdn.com/1455614108256t(2).mp4",
                                @"http://baobab.wdjcdn.com/1456317490140jiyiyuetai_x264.mp4",
                                @"http://baobab.wdjcdn.com/1455888619273255747085_x264.mp4",
                                @"http://baobab.wdjcdn.com/1456734464766B(13).mp4",
                                @"http://baobab.wdjcdn.com/1456653443902B.mp4",
                                @"http://baobab.wdjcdn.com/1456231710844S(24).mp4"];
    
    for (int i = 0; i < 10; i++) {
        KZ_VideoModel *videoModel = [[KZ_VideoModel alloc] init];
        videoModel.videoId = [NSString stringWithFormat:@"%d", i];
        videoModel.videoURL = videoListArray[i];
        videoModel.coverImage = [UIImage imageNamed:@"cover.jpg"];
        [videoArray addObject:videoModel];
    }
    
    videoTableView = [[UITableView alloc] initWithFrame:self.view.bounds];
    videoTableView.delegate = self;
    videoTableView.dataSource = self;
    [self.view addSubview:videoTableView];
    videoTableView.tableFooterView = [[UIView alloc] init];
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    self.navigationController.navigationBarHidden = NO;
}

#pragma mark KZ_VideoPlayerCellDelegate
- (void)videoPlayerCellDidClickDetailAtModel:(KZ_VideoModel *)videoModel {
    KZ_VideoPlayerViewController *videoPlayerViewController;
    KZ_VideoPlayerView *videoPlayerView = [KZ_VideoPlayerView sharedVideoPlayerView];
    videoPlayerView.playerControlView.coverImageView.contentMode = UIViewContentModeScaleAspectFill;
    if ([self.currentVideoModel.videoId isEqualToString:videoModel.videoId]) {
        videoPlayerViewController = [[KZ_VideoPlayerViewController alloc] initWithVideoPlayerView:videoPlayerView];
    }
    else {
        [videoPlayerView stop];
        [videoPlayerView removeFromSuperview];
        videoPlayerViewController = [[KZ_VideoPlayerViewController alloc] init];
        videoPlayerViewController.videoURL = videoModel.videoURL;
    }
    [self.navigationController pushViewController:videoPlayerViewController animated:YES];
    self.currentVideoModel = nil;
}

#pragma mark KZ_VideoPlayerViewDelegate
- (void)videoPlayerViewDidTap:(KZ_VideoPlayerView *)playerView {
    if (playerView.isSmallScreen) {
        [playerView didRotateToOrientation:UIDeviceOrientationLandscapeLeft force:YES];
    }
}

#pragma mark UITableViewDelegate
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return videoArray.count;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return 260;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    static NSString *VideoPlayerCell = @"VideoPlayerCell";
    KZ_VideoPlayerCell *cell = [tableView dequeueReusableCellWithIdentifier:VideoPlayerCell];
    if (!cell) {
        cell = [[KZ_VideoPlayerCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:VideoPlayerCell];
    }
    cell.delegate = self;
    cell.videoModel = videoArray[indexPath.row];
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    KZ_VideoModel *videoModel = videoArray[indexPath.row];
    KZ_VideoPlayerView *videoPlayerView = [KZ_VideoPlayerView sharedVideoPlayerView];
    videoPlayerView.playerControlView.coverImageView.contentMode = UIViewContentModeScaleAspectFill;
    videoPlayerView.delegate = self;
    [videoPlayerView playWithVideoURL:videoModel.videoURL frame:CGRectMake(0, 10, CGRectGetWidth(tableView.frame), 200) tableView:tableView indexPath:indexPath];
    videoPlayerView.gestureType = KZ_VideoPlayerControlGestureType_TapGesture;
    videoPlayerView.coverImage = videoModel.coverImage;
    self.currentVideoModel = videoModel;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

- (void)dealloc {
    [[KZ_VideoPlayerView sharedVideoPlayerView] removeTableView:NO];
}

@end
