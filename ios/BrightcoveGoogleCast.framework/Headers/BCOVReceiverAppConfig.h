//
// BCOVReceiverAppConfig.h
// BrightcoveGoogleCast
//
// Copyright (c) 2020 Brightcove, Inc. All rights reserved.
// License: https://accounts.brightcove.com/en/terms-and-conditions
//

#import <Foundation/Foundation.h>

#import "BCOVGoogleCastManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface BCOVReceiverAppConfig : NSObject

/**
 * The accountId that a player should be setup to use.
 */
@property (nonatomic, copy, nullable) NSString *accountId;

/**
 * The policyKey that a player should be setup to use.
 */
@property (nonatomic, copy, nullable) NSString *policyKey;

/**
 * The authentication token used for verifying a license on a video.
 */
@property (nonatomic, copy, nullable) NSString *authToken;

/**
 * Provided for ssai ad setups
 */
@property (nonatomic, copy, nullable) NSString *adConfigId;

/**
 * Used for analytics.
 */
@property (nonatomic, copy, nullable) NSString *userId;

/**
 * Used for analytics.
 */
@property (nonatomic, copy, nullable) NSString *applicationId;

/**
 * When unspecified this will point to the local player that will play your videos.
 * Supplying this option will force the receiver to load a specific player rather than
 * the local player currently playing the video. This is useful when you want specific
 * player code to only run on the chromecast.
*/
@property (nonatomic, copy, nullable) NSString *playerUrl;

/**
 * The "splash screen" that should be shown before a video and when videos are switching.
*/
@property (nonatomic, copy, nullable) NSString *splashScreen;

@end

@interface BCOVGoogleCastManager (BrightcoveCastReceiver)

/**
 * @param appConfig The Google Cast receiver app configuration
 * @return An instance of BCOVGoogleCastManager configured
 * to make use of the Brightcove Google Cast Receiver App.
 */
- (instancetype)initForBrightcoveReceiverApp:(BCOVReceiverAppConfig *)appConfig;

@property (nonatomic, strong, readonly) BCOVReceiverAppConfig *appConfig;



@end

NS_ASSUME_NONNULL_END
