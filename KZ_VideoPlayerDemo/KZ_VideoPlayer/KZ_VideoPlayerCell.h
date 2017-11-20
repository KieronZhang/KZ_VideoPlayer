//
//  KZ_VideoPlayerCell.h
//  KZ_VideoPlayer
//
//  Created by Kieron Zhang on 2016/12/25.
//  Copyright © 2016年 Kieron Zhang. All rights reserved.
//

#import <UIKit/UIKit.h>

@class KZ_VideoModel;

@protocol KZ_VideoPlayerCellDelegate <NSObject>

- (void)videoPlayerCellDidClickDetailAtModel:(KZ_VideoModel *)videoModel;

@end

@interface KZ_VideoPlayerCell : UITableViewCell {
    UIImageView *coverImageView;
    UIButton *detailButton;
}
@property (nonatomic, weak) id<KZ_VideoPlayerCellDelegate> delegate;
@property (nonatomic, strong) KZ_VideoModel *videoModel;

@end
