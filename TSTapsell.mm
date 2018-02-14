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
