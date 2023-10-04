# Google Cast Plugin for Brightcove Player SDK for iOS, version 6.12.5.2535

## Installation

The Google Cast Plugin for Brightcove Player SDK provides a static library framework for installation.

The Google Cast plugin supports version 4.8.0 of the Google Cast SDK for iOS. The Google Cast release notes can be found [here](https://developers.google.com/cast/docs/release-notes).

### CocoaPods

You can use [CocoaPods][cocoapods] to add the Google Cast Plugin for Brightcove Player SDK to your project.  You can find the latest Brightcove-Player-GoogleCast podspecs [here][podspecs]. The pod will incorporate the correct version of GoogleCast automatically.

CocoaPod Podfile example:

```bash
source 'https://github.com/CocoaPods/Specs'
source 'https://github.com/brightcove/BrightcoveSpecs.git'

platform :ios, '13.0'

use_frameworks!

target 'ExampleApp' do
    pod 'Brightcove-Player-GoogleCast'
end
```

Installing Brightcove-Player-GoogleCast automatically installs the dependency, Brightcove-Player-Core. Based on your needs, you may choose to include either the dynamic Brightcove-Player-Core framework, or the static one. By default, the dynamic Core framework is installed. To choose the static Core framework, your Podfile would look something like this:

```bash
source 'https://github.com/CocoaPods/Specs'
source 'https://github.com/brightcove/BrightcoveSpecs.git'

platform :ios, '13.0'
use_frameworks!

target 'ExampleApp' do
    pod 'Brightcove-Player-GoogleCast-static'
end
```

New subspecs have been added to support `no-bluetooth` version of Google Cast SDK and XCFramework.
The first subspec indicates the GoogleCast version (bluetooth or no-bluetooth) to be used and the second is the distribution package (Framework or XCFramework) for the plugin. Bluetooth and Framework are the default subspecs for `BrightcoveGoogleCast` plugin.

```bash
  pod 'Brightcove-Player-GoogleCast'                          # Bluetooth and Framework
  pod 'Brightcove-Player-GoogleCast/Bluetooth'                # Bluetooth and Framework
  pod 'Brightcove-Player-GoogleCast/Bluetooth/Framework'      # Bluetooth and Framework
  pod 'Brightcove-Player-GoogleCast/Bluetooth/XCFramework'    # Bluetooth and XCFramework
  pod 'Brightcove-Player-GoogleCast/No-Bluetooth'             # No-Bluetooth and Framework
  pod 'Brightcove-Player-GoogleCast/No-Bluetooth/Framework'   # No-Bluetooth and Framework
  pod 'Brightcove-Player-GoogleCast/No-Bluetooth/XCFramework' # No-Bluetooth and XCFramework
```

When updating your installation, it's a good idea to refresh the local copy of your BrightcoveSpecs repository to ensure you have the latest podspecs locally, just like you would update your CococaPods master repository. Use `pod repo update` to do so.

### Manual

To add the Google Cast Plugin for Brightcove Player SDK to your project manually:

1. Follow the [Google Cast SDK Manual Setup][googlecastsdkmanualsetup] guide.
1. Follow the [Brightcove Player SDK Manual Installation][bcovsdkmanualsetup] guide.
1. Download the [Google Cast Plugin for Brightcove Player SDK][bcovgooglecast] framework.
1. On the "General" tab of your application target, add `BrightcoveGoogleCast.framework` or `BrightcoveGoogleCast.xcframework` from the Google Cast Plugin for Brightcove Player SDK download to the list of **Frameworks, Libraries, Embedded Content**.
1. On the "Build Settings" tab of your application target, ensure that the "Framework Search Paths" include the paths to the frameworks. This should have been done automatically unless the framework is stored under a different root directory than your project.
1. (**Universal Framework** only) On the "Build Phases" tab, add a "Run Script" phase with the command `bash ${BUILT_PRODUCTS_DIR}/${FRAMEWORKS_FOLDER_PATH}/BrightcoveGoogleCast.framework/strip-frameworks.sh`. Check "Run script only when installing". This will remove unneeded architectures from the build, which is important for App Store submission.
1. (**Apple Silicon with Universal Framework** only) On the "Build Settings" tab of your application target:
    * Ensure that `arm64` has been added to your "Excluded Architectures" build setting for `Any iOS Simulator SDK`.

### Swift Package Manager

To add the Google Cast Plugin for Brightcove Player SDK to your project with Swift Package Manager: 

1. First [follow the steps][corespm] to add the Core XCFramework with Swift Package Mananger.
1. Add the Google Cast package to Swift Package Manager using `https://github.com/brightcove/brightcove-player-sdk-ios-googlecast.git`.
1. Follow the [Google Cast SDK Manual Setup][googlecastsdkmanualsetup] guide.

[corespm]: https://github.com/brightcove/brightcove-player-sdk-ios#swift-package-manager

### Imports

The Google Cast Plugin for Brightcove Player SDK can be imported into code a few different ways; `@import BrightcoveGoogleCast;`, `#import <BrightcoveGoogleCast/BrightcoveGoogleCast.h>` or `#import <BrightcoveGoogleCast/[specific class].h>`. You can import the `GoogleCast` and `BrightcovePlayerSDK` modules in similar fashion.

[bcovsdkmanualsetup]: https://github.com/brightcove/brightcove-player-sdk-ios#manual-installation
[googlecastsdkmanualsetup]: https://developers.google.com/cast/docs/ios_sender/#manual_setup 
[cocoapods]: http://cocoapods.org
[podspecs]: https://github.com/brightcove/BrightcoveSpecs/tree/master/Brightcove-Player-GoogleCast
[podspecs-static]: https://github.com/brightcove/BrightcoveSpecs/tree/master/Brightcove-Player-GoogleCast-Static
[release]: https://github.com/brightcove/brightcove-player-sdk-ios-google-cast/releases

## Before You Begin

Before attempting to utilize this plugin you should already be familiar with the following:

* [Register your application][registration]. This will walk you through creating your reciever application and grant you an application ID. Starting out you can use the demo application ID '4F8B3483'.
* [Setup for Developing with the Cast Application Framework (CAF) for iOS ][setupguide]. This will walk you through setting up the necessary entitlements for your app.
* [Initialze the Cast Context][castcontext]. This will walk you through initializing the Cast Context with your receiver application ID.
* [Add Mini Controllers][addminicontrollers]. This will walk you through how to take advantage of the Google Cast SDK's mini media controls. 

[registration]:https://developers.google.com/cast/docs/registration
[setupguide]:https://developers.google.com/cast/docs/ios_sender
[castcontext]:https://developers.google.com/cast/docs/ios_sender/integrate#initialize_the_cast_context
[addminicontrollers]:https://developers.google.com/cast/docs/ios_sender/integrate#add_mini_controllers

## Quick Start

The BrightcoveGoogleCast plugin is a bridge between [Google Cast iOS SDK][googlecast] and the [Brightcove Player SDK for iOS][bcovsdk]. 

This snippet shows its basic usage.

```
    [1] self.googleCastManager = [BCOVGoogleCastManager new];

    [2] id<BCOVPlaybackController> playbackController = [BCOVPlayerSDKManager.sharedManager createPlaybackController];

    [3] [playbackController addSessionConsumer:self.googleCastManager];
```

Breaking the code down into steps:

1. Create a reference to the BCOVGoogleCastManager singleton.
1. Create an instance of BCOVPlaybackController to use.
1. Add your BCOVGoogleCastManager reference as a session consumer to your BCOVPlaybackController instance.

[googlecast]: https://developers.google.com/cast/docs/ios_sender/
[bcovsdk]: https://github.com/brightcove/brightcove-player-sdk-ios
[bcovgooglecast]: https://github.com/brightcove/brightcove-player-sdk-ios-googlecast

## Brightcove CAF Receiver

The application ID for the Brightcove CAF Receiver is `341387A3` and is assigned to the constant `kBCOVCAFReceiverApplicationID`. You can verify the application ID by checking the [CAF Receiver config.json](https://players.brightcove.net/videojs-chromecast-receiver/2/config.json).

If you are using the Brightcove CAF Receiver you'll need to initialize these variables like this:

```
[1] BCOVReceiverAppConfig *receiverAppConfig = [BCOVReceiverAppConfig new];
    receiverAppConfig.accountId = kAccountID;
    receiverAppConfig.policyKey = kServicePolicyKey;

[2] self.googleCastManager = [[BCOVGoogleCastManager alloc] initForBrightcoveReceiverApp:receiverAppConfig];
```

The following properties are also available to set on `BCOVReceiverAppConfig` as needed:

* splashScreen (for customizing the splash screen image)
* playerUrl (for using a customized player)
* authToken (for use with PAS/EPA)
* watermarkingToken (for use with Forensic Watermaking)
* adConfigId (for use with SSAI)
* userId (for use with analytics tracking)
* applicationId (for use with analytics tracking)

**NOTE: When using the Brightcove Cast Receiver app with the Brightcove Native SDKs, you must send the `catalogParams` object via the `customData` interface. A static URL is not supported. If you are correctly utilizing the `BCOVReceiverAppConfig` class this is handled for you.**

## Generic Stream Concurrency

Generic Stream Concurrency is supported when using the Brightcove CAF Receiver. You must create a web player that has stream concurrency enabled.

At this time, there is no dedicated UI for this feature in Studio, so the JSON editor must be used. The configuration will look something like this:
```
  "video_cloud": {
    "stream_concurrency": true,
    "policy_key": "BCpk..."
  },
  "player": {
    "template": {
      "name": "single-video-template",
      "version": "6.63.1"
    }
  },
```

Once you have configured your player you can specify your GSC enabled player using the `playerUrl` property on `BCOVReceiverAppConfig`:

```
receiverAppConfig.playerUrl = @"https://players.brightcove.net/.../index.min.js";
```

The following claims are required:
* `climit`: The concurrency limit claim indicates how many watchers or streams can play at the same time.
* `uid`: The viewer identifier is used to correlate multiple sessions to enforce Stream Concurrency
* `sid`: [Correlator identifier](https://apis.support.brightcove.com/playback-restrictions/guides/generic-stream-concurrency.html#correlator_identifier) defines the streaming locations for a viewer.

For additional information please see the [Implementation](https://apis.support.brightcove.com/playback-restrictions/guides/generic-stream-concurrency.html#Implementation) section of our Generic Stream Concurrency guide.

You can then set the `authToken` property on `BCOVReceiverAppConfig` with your JWT:

```
receiverAppConfig.authToken = <jwt>
```

## Delegate Methods

BCOVGoogleCastManagerDelegate has delegate methods you can use to be notified when major cast-related events have occurred or are about to occur, for example

* `- (void)switchedToLocalPlayback:(NSTimeInterval)lastKnownStreamPosition;`
* `- (void)switchedToRemotePlayback;`
* `- (void)currentCastedVideoDidComplete;`
* `- (void)castedVideoFailedToPlay;`
* `- (void)suitableSourceNotFound;`
* `- (void)willBuildMediaInformationBuilder:(GCKMediaInformationBuilder *_Nonnull);`
* `- (void)willSendMediaLoadOptions:(GCKMediaLoadOptions *_Nonnull);`

For a complete list with descriptions, refer to the [BCOVGoogeCastManagerDelegate Protocol Reference](https://docs.brightcove.com/ios-plugins/googlecast/Protocols/BCOVGoogleCastManagerDelegate.html).

To take advantage of these events, set a delegate on the BCOVGoogleCastManager singleton. 

```
    self.googleCastManager.delegate = self;
```

## Source Selection

The BCOVGoogleCastManager will attempt to find a suitable source to use. It will look for sources in this order:

1. HTTPS HLS v3
1. HTTPS DASH
1. HTTPS MP4
1. HTTP HLS v3
1. HTTP DASH
1. HTTP MP4

If none of these are found, the delegate method `suitableSourceNotFound` will be called. 

Your Video Cloud account will need to be set up to support HLS v3, ensure that DASH is enabled or have an MP4 source available for each video.

## Customizations

There are two properties, in addition to the delegate property, that you can set on the BCOVGoogleCastManager class. These are:

* `GCKImage *fallbackPosterImage`: The GCKImage that will be used when there is no poster image available for a video.
* `CGSize posterImageSize`: The height and width that you want to use for the GCKImage object image that is created. Defaults to 480h x 720w.

## Known Issues / Limitations

### When using a default, unmodified receiver (including the demo receiver) the following limitations apply:

* DRM is not supported.
* Multiple Audio Tracks are not supported.
* Client-side and Server-side Advertising are not supported.
* Live and Live DVR streams are not supported.

### When using the Brightcove CAF receiver the following limitations apply:

* Client-side Advertising is not supported.

## Support

If you have questions, need help or want to provide feedback, please use the [Support Portal](https://supportportal.brightcove.com/s/login/) or contact your Account Manager.  To receive notification of new SDK software releases, subscribe to the Brightcove Native Player SDKs [Google Group](https://groups.google.com/g/brightcove-native-player-sdks).

