//
//  KZ_VideoPlayerCell.h
//  KZ_VideoPlayer_iOS
//
//  Created by Kieron Zhang on 2018/5/10.
//  Copyright © 2018年 Kieron Zhang. All rights reserved.
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
