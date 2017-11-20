//
//  ViewController.h
//  KZ_VideoPlayer
//
//  Created by Kieron Zhang on 2016/12/25.
//  Copyright © 2016年 Kieron Zhang. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController <UITableViewDelegate, UITableViewDataSource> {
    UITableView *videoListTableView;
    NSArray *videoListArray;
}

@end

