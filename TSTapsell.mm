#import <Foundation/Foundation.h>

#import "TSTapsell.h"
#import <TapsellSDKv3/TapsellSDKv3.h>

void TSTapsell::initialize(char *appKey){
    NSString *NSStringAppKey = [NSString stringWithUTF8String:appKey];
    [Tapsell initializeWithAppKey:NSStringAppKey];
}
