//
//  NSArray+KZ_Constraints.h
//  KZ_Constraints
//
//  Created by Kieron Zhang on 2017/5/15.
//  Copyright © 2017年 Kieron Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KZ_View+KZ_Constraints.h"

@interface NSArray (KZ_Constraints)

@property (nonatomic, strong, readonly) KZ_ConstraintAttribute *kz_left;
@property (nonatomic, strong, readonly) KZ_ConstraintAttribute *kz_right;
@property (nonatomic, strong, readonly) KZ_ConstraintAttribute *kz_top;
@property (nonatomic, strong, readonly) KZ_ConstraintAttribute *kz_bottom;
@property (nonatomic, strong, readonly) KZ_ConstraintAttribute *kz_leading;
@property (nonatomic, strong, readonly) KZ_ConstraintAttribute *kz_trailing;
@property (nonatomic, strong, readonly) KZ_ConstraintAttribute *kz_width;
@property (nonatomic, strong, readonly) KZ_ConstraintAttribute *kz_height;
@property (nonatomic, strong, readonly) KZ_ConstraintAttribute *kz_centerx;
@property (nonatomic, strong, readonly) KZ_ConstraintAttribute *kz_centery;
@property (nonatomic, strong, readonly) KZ_ConstraintAttribute *kz_baseline;

#if __IPHONE_OS_VERSION_MIN_REQUIRED >= __IPHONE_8_0 || __MAC_OS_X_VERSION_MIN_REQUIRED >= __MAC_10_11
@property (nonatomic, strong, readonly) KZ_ConstraintAttribute *kz_firstBaseline;
@property (nonatomic, strong, readonly) KZ_ConstraintAttribute *kz_lastBaseline;
#endif

#if __IPHONE_OS_VERSION_MIN_REQUIRED >= __IPHONE_8_0
@property (nonatomic, strong, readonly) KZ_ConstraintAttribute *kz_leftMargin;
@property (nonatomic, strong, readonly) KZ_ConstraintAttribute *kz_rightMargin;
@property (nonatomic, strong, readonly) KZ_ConstraintAttribute *kz_topMargin;
@property (nonatomic, strong, readonly) KZ_ConstraintAttribute *kz_bottomMargin;
@property (nonatomic, strong, readonly) KZ_ConstraintAttribute *kz_leadingMargin;
@property (nonatomic, strong, readonly) KZ_ConstraintAttribute *kz_trailingMargin;
@property (nonatomic, strong, readonly) KZ_ConstraintAttribute *kz_centerxWithinMargins;
@property (nonatomic, strong, readonly) KZ_ConstraintAttribute *kz_centeryWithinMargins;
#endif

@property (nonatomic, strong, readonly) KZ_ConstraintAttribute *kz_center;
@property (nonatomic, strong, readonly) KZ_ConstraintAttribute *kz_size;
@property (nonatomic, strong, readonly) KZ_ConstraintAttribute *kz_edgeInsets;

- (void)kz_addConstraintsWithAttribute:(KZ_LayoutAttribute)layoutAttribute equalValue:(id)value;
- (void)kz_addConstraintsWithAttribute:(KZ_LayoutAttribute)layoutAttribute equalValue:(id)value offset:(id)offset;
- (void)kz_addConstraintsWithAttribute:(KZ_LayoutAttribute)layoutAttribute equalValue:(id)value multipier:(CGFloat)multipier;
- (void)kz_addConstraintsWithAttribute:(KZ_LayoutAttribute)layoutAttribute equalValue:(id)value offset:(id)offset multipier:(CGFloat)multipier;

- (void)kz_addConstraintsWithAttribute:(KZ_LayoutAttribute)layoutAttribute greaterThanOrEqualValue:(id)value;
- (void)kz_addConstraintsWithAttribute:(KZ_LayoutAttribute)layoutAttribute greaterThanOrEqualValue:(id)value offset:(id)offset;
- (void)kz_addConstraintsWithAttribute:(KZ_LayoutAttribute)layoutAttribute greaterThanOrEqualValue:(id)value multipier:(CGFloat)multipier;
- (void)kz_addConstraintsWithAttribute:(KZ_LayoutAttribute)layoutAttribute greaterThanOrEqualValue:(id)value offset:(id)offset multipier:(CGFloat)multipier;

- (void)kz_addConstraintsWithAttribute:(KZ_LayoutAttribute)layoutAttribute lessThanOrEqualValue:(id)value;
- (void)kz_addConstraintsWithAttribute:(KZ_LayoutAttribute)layoutAttribute lessThanOrEqualValue:(id)value offset:(id)offset;
- (void)kz_addConstraintsWithAttribute:(KZ_LayoutAttribute)layoutAttribute lessThanOrEqualValue:(id)value multipier:(CGFloat)multipier;
- (void)kz_addConstraintsWithAttribute:(KZ_LayoutAttribute)layoutAttribute lessThanOrEqualValue:(id)value offset:(id)offset multipier:(CGFloat)multipier;

@end
