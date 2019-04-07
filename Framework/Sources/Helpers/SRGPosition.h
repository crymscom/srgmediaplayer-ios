//
//  Copyright (c) SRG SSR. All rights reserved.
//
//  License information is available from the LICENSE file.
//

#import <CoreMedia/CoreMedia.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  Representation of a position in time to reach within a given tolerance. In general, a small tolerance means greater
 *  precision, at the expense of efficiency (reaching a position precisely may require more buffering). Conversely,
 *  a large tolerance means less precision, but more efficiency (an acceptable position might require less buffering
 *  to be reached).
 *
 *  Remark: When designating a position to within a segment, there is no need to adjust tolerances based on the segment
 *          time range. In such cases, SRG Media Player ensures that the position stays within the desired segment.
 */
@interface SRGPosition : NSObject

/**
 *  The default position.
 */
@property (class, nonatomic, readonly) SRGPosition *defaultPosition;

/**
 *  Exact position at the specified time.
 */
+ (SRGPosition *)positionAtTime:(CMTime)time;

/**
 *  Exact position at the specified time (in seconds).
 */
+ (SRGPosition *)positionAtTimeInSeconds:(NSTimeInterval)timeInSeconds;

/**
 *  Position around the specified time with maximum tolerance.
 */
+ (SRGPosition *)positionAroundTime:(CMTime)time;

/**
 *  Position around the specified time with maximum tolerance.
 */
+ (SRGPosition *)positionAroundTimeInSeconds:(NSTimeInterval)timeInSeconds;

/**
 *  Position earlier than the specified time.
 */
+ (SRGPosition *)positionBeforeTime:(CMTime)time;

/**
 *  Position earlier than the specified time (in seconds).
 */
+ (SRGPosition *)positionBeforeTimeInSeconds:(NSTimeInterval)timeInSeconds;

/**
 *  Position later than the specified time.
 */
+ (SRGPosition *)positionAfterTime:(CMTime)time;

/**
 *  Position earlier than the specified time (in seconds).
 */
+ (SRGPosition *)positionAfterTimeInSeconds:(NSTimeInterval)timeInSeconds;

/**
 *  Position for the specified time with custom tolerance settings.
 */
+ (SRGPosition *)positionWithTime:(CMTime)time toleranceBefore:(CMTime)toleranceBefore toleranceAfter:(CMTime)toleranceAfter;

/**
 *  Instantiate a position for the specified time with custom tolerance settings.
 *
 *  @param time            The position time. Use `kCMTimeZero` for the default position.
 *  @param toleranceBefore The tolerance (before `time`) allowed when reaching the position. Use `kCMTimeZero` for precise
 *                         positioning, or `kCMTimePositiveInfinity` for efficient positioning.
 *  @param toleranceAfter  The tolerance (after `time`) allowed when reaching the position. Use `kCMTimeZero` for precise
 *                         positioning, or `kCMTimePositiveInfinity` for efficient positioning.
 *
 *  @discussion Invalid times are set to `kCMTimeZero`.
 */
- (instancetype)initWithTime:(CMTime)time toleranceBefore:(CMTime)toleranceBefore toleranceAfter:(CMTime)toleranceAfter;

/**
 *  The time to reach. Guaranteed to be valid.
 */
@property (nonatomic, readonly) CMTime time;

/**
 *  The tolerances applied when reaching `time`. Guaranteed to be valid.
 */
@property (nonatomic, readonly) CMTime toleranceBefore;
@property (nonatomic, readonly) CMTime toleranceAfter;

@end

NS_ASSUME_NONNULL_END
