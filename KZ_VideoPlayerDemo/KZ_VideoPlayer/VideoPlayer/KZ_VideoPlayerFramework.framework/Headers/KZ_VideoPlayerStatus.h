//
//  KZ_VideoPlayerStatus.h
//  KZ_VideoPlayer
//
//  Created by Kieron Zhang on 2016/12/25.
//  Copyright © 2016年 Kieron Zhang. All rights reserved.
//

typedef NS_ENUM(NSInteger, KZ_VideoPlayerViewPlayStatus) {
    KZ_VideoPlayerViewPlayStatus_Stop,
    KZ_VideoPlayerViewPlayStatus_Pause,
    KZ_VideoPlayerViewPlayStatus_Play,
    KZ_VideoPlayerViewPlayStatus_Failed,
};

typedef NS_OPTIONS(NSInteger, KZ_VideoPlayerControlGestureType) {
    KZ_VideoPlayerControlGestureType_None = 0,
    KZ_VideoPlayerControlGestureType_SingleTap = 1 << 0,
    KZ_VideoPlayerControlGestureType_DoubleTap = 1 << 1,
    KZ_VideoPlayerControlGestureType_PanGesture = 1 << 2,
    KZ_VideoPlayerControlGestureType_TapGesture = (KZ_VideoPlayerControlGestureType_SingleTap | KZ_VideoPlayerControlGestureType_DoubleTap),
    KZ_VideoPlayerControlGestureType_All = (KZ_VideoPlayerControlGestureType_SingleTap | KZ_VideoPlayerControlGestureType_DoubleTap | KZ_VideoPlayerControlGestureType_PanGesture)
};
