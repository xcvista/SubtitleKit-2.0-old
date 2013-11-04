//
//  SKSubtitleLine.h
//  Subtitler
//
//  Created by Maxthon Chan on 13-6-13.
//  Copyright (c) 2013年 muski. All rights reserved.
//

#import <MSBooster/MSBooster.h>
#import <SubtitleKit/SKSubtitleTrack.h>

__BEGIN_DECLS

static MSInline NSTimeInterval SKTimeIntervalFromComponents(NSUInteger hour, NSUInteger minute, NSUInteger second, NSUInteger millisecond, NSTimeInterval offset)
{
    return hour * 3600.0 + minute * 60.0 + second * 1.0 + millisecond * 0.001 + offset;
}

extern void SKComponentsFromTimeInterval(NSTimeInterval interval, NSUInteger *hour, NSUInteger *minute, NSUInteger *second, NSUInteger *millisecond);

@interface SKSubtitleLine : NSObject <NSCopying, NSCoding>

@property NSTimeInterval start;
@property NSTimeInterval duration;
@property NSTimeInterval end;
@property id content;
@property id tag;

- (NSComparisonResult)timeCompare:(SKSubtitleLine *)other;

- (BOOL)isEqualToLine:(SKSubtitleLine *)line;

@end

@interface SKSubtitleTrack (SKOffsetting)

- (void)offsetAllLines:(NSTimeInterval)offset;

@end

__END_DECLS
