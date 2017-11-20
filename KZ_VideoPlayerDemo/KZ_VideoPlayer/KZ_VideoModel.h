//
//  KZ_VideoModel.h
//  KZ_VideoPlayer
//
//  Created by Kieron Zhang on 2016/12/25.
//  Copyright © 2016年 Kieron Zhang. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface KZ_VideoModel : NSObject

@property (nonatomic, strong) UIImage *coverImage;
@property (nonatomic, strong) NSString *videoURL;
@property (nonatomic, strong) NSString *videoId;

@end
