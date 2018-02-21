#import <Foundation/Foundation.h>

#import "TSTapsell.h"
#import <TapsellSDKv3/TapsellSDKv3.h>

NSMutableDictionary * tapsellAds;

void TSTapsell::initialize(char *appKey){
    NSString *NSStringAppKey = [NSString stringWithUTF8String:appKey];
    [Tapsell initializeWithAppKey:NSStringAppKey];
    
    tapsellAds = [[NSMutableDictionary alloc] init];
}

void TSTapsell::requestAd(char *zoneId, bool isCached, ON_AD_AVAILABLE_CB onAdAvailable,
                          ON_NO_AD_AVAILABLE_CB onNoAdAvailable, ON_NO_NETWORK_CB onNoNetwork,
                          ON_ERROR_CB onError, ON_EXPIRING_CB onExpiring){
    NSString *NSStringZoneId = [NSString stringWithUTF8String:zoneId];
    
    TSAdRequestOptions* requestOptions = [[TSAdRequestOptions alloc] init];
    if(isCached){
        [requestOptions setCacheType:CacheTypeCached];
    } else {
        [requestOptions setCacheType:CacheTypeStreamed];
    }
    
    [Tapsell requestAdForZone:NSStringZoneId
                   andOptions:requestOptions
                onAdAvailable:^(TapsellAd *ad){
                    [tapsellAds setObject:ad forKey:ad.getId];
                    onAdAvailable((char*)[[ad getId] UTF8String]);
                }
              onNoAdAvailable:^{
                  onNoAdAvailable();
              }
                      onError:^(NSString* error){
                          onError((char*)[error UTF8String]);
                      }
                   onExpiring:^(TapsellAd* ad){
                       onExpiring((char*)[[ad getId] UTF8String]);
                      }
     ];
}

void TSTapsell::showAd(char *zoneId, char *adId, bool back_disabled,
            bool immersive_mode, int rotation_mode, bool showExitDialog,
                       ON_OPENED_CB onOpened, ON_CLOSED_CB onClosed){
    TSAdShowOptions* showOptions = [[TSAdShowOptions alloc] init];
    [showOptions setOrientation:(Orientation)(NSInteger)rotation_mode];
    [showOptions setBackDisabled:back_disabled];
    [showOptions setShowDialoge:showExitDialog];
    
    TapsellAd* targetAd = tapsellAds[[NSString stringWithCString:adId
                                                  encoding:[NSString defaultCStringEncoding]]];
    
    [targetAd showWithOptions:showOptions
      andOpenedCallback:^(TapsellAd * _Nullable ad){
          onOpened((char*)[[ad getId] UTF8String]);
      } andClosedCallback:^(TapsellAd * _Nullable ad){
          onClosed((char*)[[ad getId] UTF8String]);
      }];
}

void TSTapsell::setDebugMode(bool isDebugMode){
    [Tapsell setDebugMode:isDebugMode];
}

bool TSTapsell::isDebugMode(){
    return [Tapsell isDebugMode];
}

void TSTapsell::setAppUserId(char *appUserId){
    NSString *NSStringAppUserId = [NSString stringWithUTF8String:appUserId];
    [Tapsell setAppUserId:NSStringAppUserId];
}

char *TSTapsell::getAppUserId(){
    return (char*)[[Tapsell getAppUserId] UTF8String];
}

void TSTapsell::setRewardListener(ON_AD_SHOW_FINISHED onAdShowFinished){
    [Tapsell setAdShowFinishedCallback:^(TapsellAd *ad, BOOL completed) {
        onAdShowFinished((char*)[[ad getZoneId] UTF8String],
                         (char*)[[ad getId] UTF8String],
                         completed,
                         [ad isRewardedAd]);
    }];
}

char *TSTapsell::getVersion(){
    return (char*)[[Tapsell getVersion] UTF8String];
}

void TSTapsell::requestStandardBannerAd(char *zoneId, int bannerType,
                             int horizontalGravity, int verticalGravity){
    NSString *NSStringZoneId = [NSString stringWithUTF8String:zoneId];
    NSNumber *NSNumberBannerType = [NSNumber numberWithInteger:bannerType];
    NSNumber *NSNumberHorizontalGravity = [NSNumber numberWithInteger:horizontalGravity];
    NSNumber *NSNumberVerticalGravity = [NSNumber numberWithInteger:verticalGravity];
    
    
    [TSBannerAdView loadAdWithZoneId: NSStringZoneId
                       andBannerType:NSNumberBannerType
                     andHorizGravity:NSNumberHorizontalGravity
                      andVertGravity:NSNumberVerticalGravity];
 }

void TSTapsell::requestNativeBannerAd(char *zoneId,
                                      ON_NATIVE_BANNER_AD_AVAILABLE_CB onAdAvailable,
                           ON_NATIVE_BANNER_NO_AD_AVAILABLE_CB onNoAdAvailable,
                                      ON_NATIVE_BANNER_NO_NETWORK_CB onNoNetwork,
                                      ON_NATIVE_BANNER_ERROR_CB onError){
    NSString *NSStringZoneId = [NSString stringWithUTF8String:zoneId];
    
    [Tapsell requestNativeBannerAdForZone:NSStringZoneId
                            onAdAvailable:^(TSNativeBannerAdWrapper * _Nonnull nativeBannerAd) {
                                onAdAvailable((char *)[nativeBannerAd.adId UTF8String],
                                        (char *)[nativeBannerAd.title UTF8String],
                                        (char *)[nativeBannerAd.htmlDescription UTF8String],
                                        (char *)[nativeBannerAd.logoUrl UTF8String],
                                        (char *)[nativeBannerAd.callToActionText UTF8String],
                                        (char *)[nativeBannerAd.portriatImageUrl UTF8String],
                                        (char *)[nativeBannerAd.landscapeImageUrl UTF8String]);
    }
                          onNoAdAvailable:^{
        onNoAdAvailable();
    }
                                  onError:^(NSString * _Nullable error) {
        onError((char *)[error UTF8String]);
    }];
}

void TSTapsell::onNativeBannerAdShown(char *adId) {
     NSString *NSStringAdId = [NSString stringWithUTF8String:adId];
    
    [Tapsell nativeBannerAdShowWithAdId: NSStringAdId];
}

void TSTapsell::onNativeBannerAdClicked(char *adId) {
    NSString *NSStringAdId = [NSString stringWithUTF8String:adId];
    
    [Tapsell nativeBannerAdClickedWithAdId: NSStringAdId];
}

void TSTapsell::requestNativeVideoAd(char *zoneId, ON_NATIVE_VIDEO_AD_AVAILABLE_CB onAdAvailable,
                                     ON_NATIVE_VIDEO_NO_AD_AVAILABLE_CB onNoAdAvailable, ON_NATIVE_VIDEO_NO_NETWORK_CB onNoNetwork,
                                     ON_NATIVE_VIDEO_ERROR_CB onError){
    NSString *NSStringZoneId = [NSString stringWithUTF8String:zoneId];
    
    [Tapsell requestNativeVideoAdForZone:NSStringZoneId onAdAvailable:^(TSNativeVideoAdWrapper * _Nonnull nativeVideoAd) {
        onAdAvailable((char *)[nativeVideoAd.adId UTF8String],
                      (char *)[nativeVideoAd.title UTF8String],
                      (char *)[nativeVideoAd.htmlDescription UTF8String],
                      (char *)[nativeVideoAd.logoUrl UTF8String],
                      (char *)[nativeVideoAd.callToActionText UTF8String],
                      (char *)[nativeVideoAd.videoUrl UTF8String]);
    } onNoAdAvailable:^{
        onNoAdAvailable();
    } onError:^(NSString * _Nullable error) {
        onError((char *)[error UTF8String]);
    }];
}

void TSTapsell::onNativeVideoAdShown(char *adId) {
    NSString *NSStringAdId = [NSString stringWithUTF8String:adId];
    
    [Tapsell nativeVideoAdShowWithAdId: NSStringAdId];
}

void TSTapsell::onNativeVideoAdClicked(char *adId) {
    NSString *NSStringAdId = [NSString stringWithUTF8String:adId];
    
    [Tapsell nativeVideoAdClickedWithAdId: NSStringAdId];
}
