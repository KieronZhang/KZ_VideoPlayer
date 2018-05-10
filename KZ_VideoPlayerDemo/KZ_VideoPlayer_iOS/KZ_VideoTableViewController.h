//
//  KZ_VideoTableViewController.h
//  KZ_VideoPlayer_iOS
//
//  Created by Kieron Zhang on 2018/5/10.
//  Copyright © 2018年 Kieron Zhang. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface KZ_VideoTableViewController : UIViewController <UITableViewDelegate, UITableViewDataSource> {
    UITableView *videoTableView;
    NSMutableArray *videoArray;
}

@end
