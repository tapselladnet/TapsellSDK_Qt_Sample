#ifndef PROJ_ANDROID_STUDIO_TAPSELL_H
#define PROJ_ANDROID_STUDIO_TAPSELL_H

#include <functional>
#include <map>
#include <QString>
#include <QDebug>
#include <QtAndroidExtras>
#include <QApplication>
#include <jni.h>
#include <string.h>
#include <qpa/qplatformnativeinterface.h>

const std::string TAPSELL_CLASS = "ir/tapsell/sdk/Tapsell";

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

class Tapsell {
public:
    static void initialize(QString appKey) {
        QAndroidJniObject str = QAndroidJniObject::fromString(appKey);
        QAndroidJniObject::callStaticMethod<void>(TAPSELL_CLASS.c_str(), "initialize", "(Landroid/content/Context;Ljava/lang/String;)V", QtAndroid::androidContext().object(), str.object<jstring>());
    }

    static void setRewardListener(ON_AD_SHOW_FINISHED onAdShowFinished) {
        onAdShowFinishedCb = onAdShowFinished;
    }

    static void requestAd(QString zoneId, bool isCached, ON_AD_AVAILABLE_CB onAdAvailable,
                          ON_NO_AD_AVAILABLE_CB onNoAdAvailable, ON_NO_NETWORK_CB onNoNetwork,
                          ON_ERROR_CB onError, ON_EXPIRING_CB onExpiring) {
        onAdAvailableCbs[zoneId.toStdString()] = onAdAvailable;
        onErrorCbs[zoneId.toStdString()] = onError;
        onNoAdAvailableCbs[zoneId.toStdString()] = onNoAdAvailable;
        onNoNetworkCbs[zoneId.toStdString()] = onNoNetwork;
        onExpiringCbs[zoneId.toStdString()] = onExpiring;

        QAndroidJniObject str = QAndroidJniObject::fromString(zoneId);
        QAndroidJniObject::callStaticMethod<void>(TAPSELL_CLASS.c_str(), "requestAd", "(Landroid/content/Context;Ljava/lang/String;Z)V", QtAndroid::androidContext().object(), str.object<jstring>(), jboolean(isCached));
    }

    static void showAd(QString zoneId, QString adId, bool back_disabled,
                       bool immersive_mode, int rotation_mode, bool showExitDialog){
        QAndroidJniObject jAdId = QAndroidJniObject::fromString(adId);
        QAndroidJniObject::callStaticMethod<void>(TAPSELL_CLASS.c_str(), "showAd", "(Landroid/content/Context;Ljava/lang/String;ZZIZ)V",
                                                  QtAndroid::androidContext().object(), jAdId.object<jstring>(), back_disabled, immersive_mode, rotation_mode, showExitDialog);
    }
    static void showAd(QString zoneId, QString adId, bool back_disabled,
                       bool immersive_mode, int rotation_mode, bool showExitDialog,
                       ON_OPENED_CB onOpened, ON_CLOSED_CB onClosed){
        onOpenedCbs[zoneId.toStdString()] = onOpened;
        onClosedCbs[zoneId.toStdString()] = onClosed;
        Tapsell::showAd(zoneId, adId, back_disabled, immersive_mode, rotation_mode, showExitDialog);
    }
    static void setDebugMode(bool debug) {
        QAndroidJniObject::callStaticMethod<void>(TAPSELL_CLASS.c_str(), "setDebugMode", "(Landroid/content/Context;Z)V", QtAndroid::androidContext().object(), debug);
    }

    static bool isDebugMode() {
        return QAndroidJniObject::callStaticMethod<bool>(TAPSELL_CLASS.c_str(), "isDebugMode", "(Landroid/content/Context;)Z", QtAndroid::androidContext().object());;
    }
    static void setAppUserId(QString appUserId) {
        QAndroidJniObject str = QAndroidJniObject::fromString(appUserId);
        QAndroidJniObject::callStaticMethod<void>(TAPSELL_CLASS.c_str(), "setAppUserId", "(Landroid/content/Context;Ljava/lang/String;)V", QtAndroid::androidContext().object(), str.object<jstring>());
    }
    static QString getAppUserId() {
        QAndroidJniObject userId = QAndroidJniObject::callStaticMethod<QAndroidJniObject>(TAPSELL_CLASS.c_str(), "getAppUserId", "(Landroid/content/Context;)Ljava/lang/String;", QtAndroid::androidContext().object());;
        return userId.toString();
    }
    static QString getVersion() {
        QAndroidJniObject version = QAndroidJniObject::callStaticMethod<QAndroidJniObject>(TAPSELL_CLASS.c_str(), "getVersion", "()Ljava/lang/String;");
        return version.toString();
    }
    static void setPermissionHandlerConfig(int permissionHandlerConfig) {
        QAndroidJniObject::callStaticMethod<void>(TAPSELL_CLASS.c_str(), "setPermissionHandlerConfig", "(Landroid/content/Context;I)V", QtAndroid::androidContext().object(), permissionHandlerConfig);
    }
    static void setMaxAllowedBandwidthUsage(int maxBpsSpeed) {
        QAndroidJniObject::callStaticMethod<void>(TAPSELL_CLASS.c_str(), "setMaxAllowedBandwidthUsage", "(Landroid/content/Context;I)V", QtAndroid::androidContext().object(), maxBpsSpeed);
    }
    static void setMaxAllowedBandwidthUsagePercentage(int maxPercentage) {
        QAndroidJniObject::callStaticMethod<void>(TAPSELL_CLASS.c_str(), "setMaxAllowedBandwidthUsagePercentage", "(Landroid/content/Context;I)V", QtAndroid::androidContext().object(), maxPercentage);
    }
    static void clearBandwidthUsageConstrains() {
        QAndroidJniObject::callStaticMethod<void>(TAPSELL_CLASS.c_str(), "clearBandwidthUsageConstrains", "(Landroid/content/Context;)V", QtAndroid::androidContext().object());
    }

    static void requestNativeBannerAd(QString zoneId, ON_NATIVE_BANNER_AD_AVAILABLE_CB onAdAvailable,
                          ON_NATIVE_BANNER_NO_AD_AVAILABLE_CB onNoAdAvailable, ON_NATIVE_BANNER_NO_NETWORK_CB onNoNetwork,
                          ON_NATIVE_BANNER_ERROR_CB onError) {
        onNativeBannerAdAvailableCbs[zoneId.toStdString()] = onAdAvailable;
        onNativeBannerErrorCbs[zoneId.toStdString()] = onError;
        onNativeBannerNoAdAvailableCbs[zoneId.toStdString()] = onNoAdAvailable;
        onNativeBannerNoNetworkCbs[zoneId.toStdString()] = onNoNetwork;

        QAndroidJniObject::callStaticMethod<void>(TAPSELL_CLASS.c_str(), "requestNativeBannerAd", "(Landroid/app/Activity;Ljava/lang/String;)V", QtAndroid::androidActivity().object(), QAndroidJniObject::fromString(zoneId).object<jstring>());
    }

    static void onNativeBannerAdShown(QString adId) {
        QAndroidJniObject::callStaticMethod<void>(TAPSELL_CLASS.c_str(), "nativeBannerAdShown", "(Landroid/content/Context;Ljava/lang/String;)V", QtAndroid::androidContext().object(), QAndroidJniObject::fromString(adId).object<jstring>());
    }

    static void onNativeBannerAdClicked(QString adId) {
        QAndroidJniObject::callStaticMethod<void>(TAPSELL_CLASS.c_str(), "nativeBannerAdClicked", "(Landroid/content/Context;Ljava/lang/String;)V", QtAndroid::androidContext().object(), QAndroidJniObject::fromString(adId).object<jstring>());
    }

    static void requestNativeVideoAd(QString zoneId, ON_NATIVE_VIDEO_AD_AVAILABLE_CB onAdAvailable,
                          ON_NATIVE_VIDEO_NO_AD_AVAILABLE_CB onNoAdAvailable, ON_NATIVE_VIDEO_NO_NETWORK_CB onNoNetwork,
                          ON_NATIVE_VIDEO_ERROR_CB onError) {
        onNativeVideoAdAvailableCbs[zoneId.toStdString()] = onAdAvailable;
        onNativeVideoErrorCbs[zoneId.toStdString()] = onError;
        onNativeVideoNoAdAvailableCbs[zoneId.toStdString()] = onNoAdAvailable;
        onNativeVideoNoNetworkCbs[zoneId.toStdString()] = onNoNetwork;

        QAndroidJniObject::callStaticMethod<void>(TAPSELL_CLASS.c_str(), "requestNativeVideoAd", "(Landroid/app/Activity;Ljava/lang/String;)V", QtAndroid::androidActivity().object(), QAndroidJniObject::fromString(zoneId).object<jstring>());
    }

    static void onNativeVideoAdShown(QString adId) {
        QAndroidJniObject::callStaticMethod<void>(TAPSELL_CLASS.c_str(), "nativeVideoAdShown", "(Landroid/content/Context;Ljava/lang/String;)V", QtAndroid::androidContext().object(), QAndroidJniObject::fromString(adId).object<jstring>());
    }

    static void onNativeVideoAdClicked(QString adId) {
        QAndroidJniObject::callStaticMethod<void>(TAPSELL_CLASS.c_str(), "nativeVideoAdClicked", "(Landroid/content/Context;Ljava/lang/String;)V", QtAndroid::androidContext().object(), QAndroidJniObject::fromString(adId).object<jstring>());
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


#endif // TAPSELL_H
