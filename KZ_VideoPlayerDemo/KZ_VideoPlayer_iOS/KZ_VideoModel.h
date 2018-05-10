//
//  KZ_VideoModel.h
//  KZ_VideoPlayer_iOS
//
//  Created by Kieron Zhang on 2018/5/10.
//  Copyright © 2018年 Kieron Zhang. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface KZ_VideoModel : NSObject

@property (nonatomic, strong) UIImage *coverImage;
@property (nonatomic, strong) NSString *videoURL;
@property (nonatomic, strong) NSString *videoId;

@end
