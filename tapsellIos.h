#ifndef TAPSELLIOS_H
#define TAPSELLIOS_H

#include <functional>
#include <map>
#include <QString>
#include <QDebug>
#include <QApplication>
#include <string.h>
#include <qpa/qplatformnativeinterface.h>


#define ON_AD_SHOW_FINISHED std::function<void(QString, QString, bool, bool)>
#define ON_AD_AVAILABLE_CB std::function<void(QString)>
#define ON_ERROR_CB std::function<void(QString)>
#define ON_NO_AD_AVAILABLE_CB std::function<void()>
#define ON_NO_NETWORK_CB std::function<void()>
#define ON_EXPIRING_CB std::function<void(QString)>
#define ON_OPENED_CB std::function<void(QString)>
#define ON_CLOSED_CB std::function<void(QString)>

#define ON_NATIVE_BANNER_AD_AVAILABLE_CB std::function<void(QString, QString, QString, QString, QString, QString, QString)>
#define ON_NATIVE_BANNER_ERROR_CB std::function<void(QString)>
#define ON_NATIVE_BANNER_NO_AD_AVAILABLE_CB std::function<void()>
#define ON_NATIVE_BANNER_NO_NETWORK_CB std::function<void()>

#define ON_NATIVE_VIDEO_AD_AVAILABLE_CB std::function<void(QString, QString, QString, QString, QString, QString)>
#define ON_NATIVE_VIDEO_ERROR_CB std::function<void(QString)>
#define ON_NATIVE_VIDEO_NO_AD_AVAILABLE_CB std::function<void()>
#define ON_NATIVE_VIDEO_NO_NETWORK_CB std::function<void()>

#define ROTATION_LOCKED_PORTRAIT 1
#define ROTATION_LOCKED_LANDSCAPE 2
#define ROTATION_UNLOCKED 3
#define ROTATION_LOCKED_REVERSED_LANDSCAPE 4
#define ROTATION_LOCKED_REVERSED_PORTRAIT 5

#define PERMISSION_HANDLER_DISABLED 0
#define PERMISSION_HANDLER_AUTO 1
#define PERMISSION_HANDLER_AUTO_INSIST 2

#define BANNER_320x50 1
#define BANNER_320x100 2
#define BANNER_250x250 3
#define BANNER_300x250 4

#define TOP 1
#define BOTTOM 2
#define LEFT 3
#define RIGHT 4
#define CENTER 5


class Tapsell{
public:
    static void initialize(QString appKey) {

    }

    static void setRewardListener(ON_AD_SHOW_FINISHED onAdShowFinished) {

    }

    static void requestAd(QString zoneId, bool isCached, ON_AD_AVAILABLE_CB onAdAvailable,
                          ON_NO_AD_AVAILABLE_CB onNoAdAvailable, ON_NO_NETWORK_CB onNoNetwork,
                          ON_ERROR_CB onError, ON_EXPIRING_CB onExpiring) {

    }

    static void showAd(QString zoneId, QString adId, bool back_disabled,
                       bool immersive_mode, int rotation_mode, bool showExitDialog){

    }

    static void showAd(QString zoneId, QString adId, bool back_disabled,
                       bool immersive_mode, int rotation_mode, bool showExitDialog,
                       ON_OPENED_CB onOpened, ON_CLOSED_CB onClosed){

    }

    static void setDebugMode(bool debug) {

    }

    static bool isDebugMode() {
        return true;
    }

    static void setAppUserId(QString appUserId) {

    }

    static QString getAppUserId() {
        return "salam";
    }

    static QString getVersion() {
        return "version.toString()";
    }

    static void setPermissionHandlerConfig(int permissionHandlerConfig) {

    }

    static void setMaxAllowedBandwidthUsage(int maxBpsSpeed) {

    }

    static void setMaxAllowedBandwidthUsagePercentage(int maxPercentage) {

    }

    static void clearBandwidthUsageConstrains() {

    }

    static void requestNativeBannerAd(QString zoneId, ON_NATIVE_BANNER_AD_AVAILABLE_CB onAdAvailable,
                          ON_NATIVE_BANNER_NO_AD_AVAILABLE_CB onNoAdAvailable, ON_NATIVE_BANNER_NO_NETWORK_CB onNoNetwork,
                          ON_NATIVE_BANNER_ERROR_CB onError) {

    }

    static void onNativeBannerAdShown(QString adId) {

    }

    static void onNativeBannerAdClicked(QString adId) {

    }

    static void requestNativeVideoAd(QString zoneId, ON_NATIVE_VIDEO_AD_AVAILABLE_CB onAdAvailable,
                          ON_NATIVE_VIDEO_NO_AD_AVAILABLE_CB onNoAdAvailable, ON_NATIVE_VIDEO_NO_NETWORK_CB onNoNetwork,
                          ON_NATIVE_VIDEO_ERROR_CB onError) {

    }

    static void onNativeVideoAdShown(QString adId) {

    }

    static void onNativeVideoAdClicked(QString adId) {

    }

    static void requestStandardBannerAd(QString zoneId, int bannerType,
                                        int horizontalGravity, int verticalGravity) {

    }

    static ON_AD_SHOW_FINISHED onAdShowFinishedCb;
    static std::map<std::string, ON_AD_AVAILABLE_CB> onAdAvailableCbs;
    static std::map<std::string, ON_ERROR_CB> onErrorCbs;
    static std::map<std::string, ON_NO_AD_AVAILABLE_CB> onNoAdAvailableCbs;
    static std::map<std::string, ON_NO_NETWORK_CB> onNoNetworkCbs;
    static std::map<std::string, ON_EXPIRING_CB> onExpiringCbs;
    static std::map<std::string, ON_OPENED_CB> onOpenedCbs;
    static std::map<std::string, ON_CLOSED_CB> onClosedCbs;

    static std::map<std::string, ON_NATIVE_BANNER_AD_AVAILABLE_CB> onNativeBannerAdAvailableCbs;
    static std::map<std::string, ON_NATIVE_BANNER_ERROR_CB> onNativeBannerErrorCbs;
    static std::map<std::string, ON_NATIVE_BANNER_NO_AD_AVAILABLE_CB> onNativeBannerNoAdAvailableCbs;
    static std::map<std::string, ON_NATIVE_BANNER_NO_NETWORK_CB> onNativeBannerNoNetworkCbs;

    static std::map<std::string, ON_NATIVE_VIDEO_AD_AVAILABLE_CB> onNativeVideoAdAvailableCbs;
    static std::map<std::string, ON_NATIVE_VIDEO_ERROR_CB> onNativeVideoErrorCbs;
    static std::map<std::string, ON_NATIVE_VIDEO_NO_AD_AVAILABLE_CB> onNativeVideoNoAdAvailableCbs;
    static std::map<std::string, ON_NATIVE_VIDEO_NO_NETWORK_CB> onNativeVideoNoNetworkCbs;
};

#endif // TAPSELLIOS_H
