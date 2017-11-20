//
//  ViewController.m
//  KZ_VideoPlayer
//
//  Created by Kieron Zhang on 2016/12/25.
//  Copyright © 2016年 Kieron Zhang. All rights reserved.
//

#import "ViewController.h"
#import "KZ_VideoPlayerViewController.h"
#import "KZ_VideoTableViewController.h"

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"网络视频";
    self.view.backgroundColor = [UIColor whiteColor];
    UIBarButtonItem *rightButton = [[UIBarButtonItem alloc] initWithTitle:@"视频列表" style:UIBarButtonItemStyleDone target:self action:@selector(rightButtonTapped)];
    self.navigationItem.rightBarButtonItem = rightButton;
    
    videoListArray = @[@"http://wvideo.spriteapp.cn/video/2016/0328/56f8ec01d9bfe_wpd.mp4",
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
    
    videoListTableView = [[UITableView alloc] initWithFrame:self.view.bounds];
    videoListTableView.delegate = self;
    videoListTableView.dataSource = self;
    [self.view addSubview:videoListTableView];
}

- (void)rightButtonTapped {
    KZ_VideoTableViewController *videoTableViewController = [[KZ_VideoTableViewController alloc] init];
    [self.navigationController pushViewController:videoTableViewController animated:YES];
}

#pragma mark UITableViewDelegate
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return videoListArray.count;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return 50;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    static NSString *NameCell = @"NameCell";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:NameCell];
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:NameCell];
    }
    cell.textLabel.text = [NSString stringWithFormat:@"视频%d", (int)indexPath.row + 1];
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    KZ_VideoPlayerViewController *videoPlayerViewController = [[KZ_VideoPlayerViewController alloc] init];
    videoPlayerViewController.videoURL = videoListArray[indexPath.row];
    [self.navigationController pushViewController:videoPlayerViewController animated:YES];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

@end
