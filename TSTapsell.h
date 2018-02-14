#ifndef TSTAPSELL_H
#define TSTAPSELL_H

#include<functional>

#define ON_AD_AVAILABLE_CB std::function<void(char *)>
#define ON_NO_AD_AVAILABLE_CB std::function<void()>
#define ON_NO_NETWORK_CB std::function<void()>
#define ON_ERROR_CB std::function<void(char *)>
#define ON_EXPIRING_CB std::function<void(char *)>
#define ON_OPENED_CB std::function<void(char *)>
#define ON_CLOSED_CB std::function<void(char *)>

class TSTapsell{
public:
    static void initialize(char *appKey);
    
    static void requestAd(char *zoneId, bool isCached, ON_AD_AVAILABLE_CB onAdAvailable,
                          ON_NO_AD_AVAILABLE_CB onNoAdAvailable, ON_NO_NETWORK_CB onNoNetwork,
                          ON_ERROR_CB onError, ON_EXPIRING_CB onExpiring);
    
    static void showAd(char *zoneId, char *adId, bool back_disabled,
                       bool immersive_mode, int rotation_mode, bool showExitDialog,
                       ON_OPENED_CB onOpened, ON_CLOSED_CB onClosed);
    
    static void setDebugMode(bool isDebugMode);
};

#endif // TSTAPSELL_H
