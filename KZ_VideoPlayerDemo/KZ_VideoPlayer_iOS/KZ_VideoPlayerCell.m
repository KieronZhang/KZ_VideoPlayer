//
//  KZ_VideoPlayerCell.m
//  KZ_VideoPlayer_iOS
//
//  Created by Kieron Zhang on 2018/5/10.
//  Copyright © 2018年 Kieron Zhang. All rights reserved.
//

#import "KZ_VideoPlayerCell.h"
#import "KZ_VideoModel.h"
#import <KZ_MacroDefinition_iOS/KZ_MacroDefinition.h>
#import <KZ_Categories_iOS/UIImage+KZ_Bundle.h>

@interface KZ_VideoPlayerCell ()

@end

@implementation KZ_VideoPlayerCell

- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier {
    self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
    if (self) {
        self.selectionStyle = UITableViewCellSelectionStyleNone;
        coverImageView = [[UIImageView alloc] initWithFrame:CGRectMake(0, 10, KZ_SCREEN_WIDTH, 200)];
        [self.contentView addSubview:coverImageView];
        
        UIImageView *playImageView = [[UIImageView alloc] initWithImage:[UIImage kz_imageNamed:@"play" bundleClass:NSClassFromString(@"KZ_VideoPlayer") bundleName:@"KZ_VideoPlayer_Bundle"]];
        [self.contentView addSubview:playImageView];
        playImageView.center = coverImageView.center;
        
        detailButton = [UIButton buttonWithType:UIButtonTypeCustom];
        detailButton.frame = CGRectMake(10, 220, 50, 30);
        [detailButton setTitle:@"详情" forState:UIControlStateNormal];
        [detailButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        detailButton.titleLabel.font = [UIFont systemFontOfSize:14.0f];
        [detailButton addTarget:self action:@selector(detailButtonTapped) forControlEvents:UIControlEventTouchUpInside];
        [self.contentView addSubview:detailButton];
    }
    return self;
}

- (void)setVideoModel:(KZ_VideoModel *)videoModel {
    _videoModel = videoModel;
    coverImageView.image = videoModel.coverImage;
}

- (void)detailButtonTapped {
    if ([self.delegate respondsToSelector:@selector(videoPlayerCellDidClickDetailAtModel:)]) {
        [self.delegate videoPlayerCellDidClickDetailAtModel:self.videoModel];
    }
}

@end
