#include "tapsellIos.h"

ON_AD_SHOW_FINISHED Tapsell::onAdShowFinishedCb;
std::map<std::string, ON_AD_AVAILABLE_CB> Tapsell::onAdAvailableCbs;
std::map<std::string, ON_ERROR_CB> Tapsell::onErrorCbs;
std::map<std::string, ON_NO_AD_AVAILABLE_CB> Tapsell::onNoAdAvailableCbs;
std::map<std::string, ON_NO_NETWORK_CB> Tapsell::onNoNetworkCbs;
std::map<std::string, ON_EXPIRING_CB> Tapsell::onExpiringCbs;
std::map<std::string, ON_OPENED_CB> Tapsell::onOpenedCbs;
std::map<std::string, ON_CLOSED_CB> Tapsell::onClosedCbs;

std::map<std::string, ON_NATIVE_BANNER_AD_AVAILABLE_CB> Tapsell::onNativeBannerAdAvailableCbs;
std::map<std::string, ON_NATIVE_BANNER_ERROR_CB> Tapsell::onNativeBannerErrorCbs;
std::map<std::string, ON_NATIVE_BANNER_NO_AD_AVAILABLE_CB> Tapsell::onNativeBannerNoAdAvailableCbs;
std::map<std::string, ON_NATIVE_BANNER_NO_NETWORK_CB> Tapsell::onNativeBannerNoNetworkCbs;

std::map<std::string, ON_NATIVE_VIDEO_AD_AVAILABLE_CB> Tapsell::onNativeVideoAdAvailableCbs;
std::map<std::string, ON_NATIVE_VIDEO_ERROR_CB> Tapsell::onNativeVideoErrorCbs;
std::map<std::string, ON_NATIVE_VIDEO_NO_AD_AVAILABLE_CB> Tapsell::onNativeVideoNoAdAvailableCbs;
std::map<std::string, ON_NATIVE_VIDEO_NO_NETWORK_CB> Tapsell::onNativeVideoNoNetworkCbs;
