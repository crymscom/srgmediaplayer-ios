//
//  Created by Samuel Défago on 06.05.15.
//  Copyright (c) 2015 RTS. All rights reserved.
//

#import <RTSMediaPlayer/RTSMediaPlayerSegmentDataSource.h>
#import <RTSMediaPlayer/RTSMediaPlayerSegmentView.h>
#import <RTSMediaPlayer/RTSTimeSlider.h>

@class RTSMediaPlayerController;

/**
 *  A slider displaying segment start times along its track as small icons. The slider can be tapped at any point to 
 *  jump at the corresponding location.
 *
 *  To add a slider to a custom player layout, simply drag and drop an RTSTimelineSlider onto the player layout,
 *  and bind its segment controller outlet. You can of course also instantiate and configure the view programmatically.
 *  Then call -reloadSegmentsWithIdentifier: when you need to retrieve segments from the controller
 */
@interface RTSTimelineSlider : RTSTimeSlider

/**
 *  The controller which provides segments to the timeline
 */
@property (nonatomic, weak) IBOutlet RTSMediaSegmentsController *segmentsController;

/**
 *  Call this method to trigger a reload of the segments from the data source
 */
- (void) reloadSegmentsForIdentifier:(NSString *)identifier;

@end
