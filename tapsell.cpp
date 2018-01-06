#include "tapsell.h"

ON_AD_SHOW_FINISHED Tapsell::onAdShowFinishedCb;
std::map<std::string, ON_AD_AVAILABLE_CB> Tapsell::onAdAvailableCbs;
std::map<std::string, ON_ERROR_CB> Tapsell::onErrorCbs;
std::map<std::string, ON_NO_AD_AVAILABLE_CB> Tapsell::onNoAdAvailableCbs;
std::map<std::string, ON_NO_NETWORK_CB> Tapsell::onNoNetworkCbs;
std::map<std::string, ON_EXPIRING_CB> Tapsell::onExpiringCbs;
std::map<std::string, ON_OPENED_CB> Tapsell::onOpenedCbs;
std::map<std::string, ON_CLOSED_CB> Tapsell::onClosedCbs;

//std::map<std::string, ON_NATIVE_BANNER_AD_AVAILABLE_CB> Tapsell::onNativeBannerAdAvailableCbs;
//std::map<std::string, ON_NATIVE_BANNER_ERROR_CB> Tapsell::onNativeBannerErrorCbs;
//std::map<std::string, ON_NATIVE_BANNER_NO_AD_AVAILABLE_CB> Tapsell::onNativeBannerNoAdAvailableCbs;
//std::map<std::string, ON_NATIVE_BANNER_NO_NETWORK_CB> Tapsell::onNativeBannerNoNetworkCbs;

extern "C" {
JNIEXPORT void JNICALL Java_ir_tapsell_sdk_Tapsell_onAdShowFinished(
    JNIEnv *env, jobject thiz, jstring jZoneId, jstring jAdId,
    jboolean completed, jboolean rewarded);
};

JNIEXPORT void JNICALL Java_ir_tapsell_sdk_Tapsell_onAdShowFinished(
    JNIEnv *env, jobject thiz, jstring jZoneId, jstring jAdId,
    jboolean completed, jboolean rewarded) {
  std::string zoneId = env->GetStringUTFChars(jZoneId, NULL);
  std::string adId = env->GetStringUTFChars(jAdId, NULL);
  if (Tapsell::onAdShowFinishedCb != nullptr) {
    Tapsell::onAdShowFinishedCb(QString::fromStdString(zoneId), QString::fromStdString(adId), completed, rewarded);
    Tapsell::onAdShowFinishedCb = nullptr;
  }
}

extern "C" {
JNIEXPORT void JNICALL Java_ir_tapsell_sdk_Tapsell_onAdAvailable(
    JNIEnv *env, jobject thiz, jstring jZoneId, jstring jAdId);
};

JNIEXPORT void JNICALL Java_ir_tapsell_sdk_Tapsell_onAdAvailable(
    JNIEnv *env, jobject thiz, jstring jZoneId, jstring jAdId) {
  std::string zoneId = env->GetStringUTFChars(jZoneId, NULL);
  std::string adId = env->GetStringUTFChars(jAdId, NULL);
  if (Tapsell::onAdAvailableCbs.find(zoneId) !=
      Tapsell::onAdAvailableCbs.end()) {
    Tapsell::onAdAvailableCbs[zoneId](QString::fromStdString(adId));
    Tapsell::onAdAvailableCbs.erase(zoneId);
  }
}

extern "C" {
JNIEXPORT void JNICALL Java_ir_tapsell_sdk_Tapsell_onError(JNIEnv *env,
                                                             jobject thiz,
                                                             jstring jZoneId,
                                                             jstring jError);
};

JNIEXPORT void JNICALL Java_ir_tapsell_sdk_Tapsell_onError(JNIEnv *env,
                                                             jobject thiz,
                                                             jstring jZoneId,
                                                             jstring jError) {
  std::string zoneId = env->GetStringUTFChars(jZoneId, NULL);
  std::string error = env->GetStringUTFChars(jError, NULL);
  if (Tapsell::onErrorCbs.find(zoneId) != Tapsell::onErrorCbs.end()) {
    Tapsell::onErrorCbs[zoneId](QString::fromStdString(error));
    Tapsell::onErrorCbs.erase(zoneId);
  }
}

extern "C" {
JNIEXPORT void JNICALL Java_ir_tapsell_sdk_Tapsell_onNoAdAvailable(
    JNIEnv *env, jobject thiz, jstring jZoneId);
};

JNIEXPORT void JNICALL Java_ir_tapsell_sdk_Tapsell_onNoAdAvailable(
    JNIEnv *env, jobject thiz, jstring jZoneId) {
  std::string zoneId = env->GetStringUTFChars(jZoneId, NULL);
  if (Tapsell::onNoAdAvailableCbs.find(zoneId) !=
      Tapsell::onNoAdAvailableCbs.end()) {
    Tapsell::onNoAdAvailableCbs[zoneId]();
    Tapsell::onNoAdAvailableCbs.erase(zoneId);
  }
}

extern "C" {
JNIEXPORT void JNICALL Java_ir_tapsell_sdk_Tapsell_onNoNetwork(
    JNIEnv *env, jobject thiz, jstring jZoneId);
};

JNIEXPORT void JNICALL Java_ir_tapsell_sdk_Tapsell_onNoNetwork(
    JNIEnv *env, jobject thiz, jstring jZoneId) {
  std::string zoneId = env->GetStringUTFChars(jZoneId, NULL);
  if (Tapsell::onNoNetworkCbs.find(zoneId) != Tapsell::onNoNetworkCbs.end()) {
    Tapsell::onNoNetworkCbs[zoneId]();
    Tapsell::onNoNetworkCbs.erase(zoneId);
  }
}

extern "C" {
JNIEXPORT void JNICALL Java_ir_tapsell_sdk_Tapsell_onExpiring(JNIEnv *env,
                                                                jobject thiz,
                                                                jstring jZoneId,
                                                                jstring jAdId);
};

JNIEXPORT void JNICALL Java_ir_tapsell_sdk_Tapsell_onExpiring(JNIEnv *env,
                                                                jobject thiz,
                                                                jstring jZoneId,
                                                                jstring jAdId) {
  std::string zoneId = env->GetStringUTFChars(jZoneId, NULL);
  std::string adId = env->GetStringUTFChars(jAdId, NULL);
  if (Tapsell::onExpiringCbs.find(zoneId) != Tapsell::onExpiringCbs.end()) {
    Tapsell::onExpiringCbs[zoneId](QString::fromStdString(adId));
    Tapsell::onExpiringCbs.erase(zoneId);
  }
}

extern "C" {
JNIEXPORT void JNICALL Java_ir_tapsell_sdk_Tapsell_onClosed(JNIEnv *env,
                                                              jobject thiz,
                                                              jstring jZoneId,
                                                              jstring jAdId);
};

JNIEXPORT void JNICALL Java_ir_tapsell_sdk_Tapsell_onClosed(JNIEnv *env,
                                                              jobject thiz,
                                                              jstring jZoneId,
                                                              jstring jAdId) {
  std::string zoneId = env->GetStringUTFChars(jZoneId, NULL);
  std::string adId = env->GetStringUTFChars(jAdId, NULL);
  if (Tapsell::onClosedCbs.find(zoneId) != Tapsell::onClosedCbs.end()) {
    Tapsell::onClosedCbs[zoneId](QString::fromStdString(adId));
    Tapsell::onClosedCbs.erase(zoneId);
  }
}

extern "C" {
JNIEXPORT void JNICALL Java_ir_tapsell_sdk_Tapsell_onOpened(JNIEnv *env,
                                                              jobject thiz,
                                                              jstring jZoneId,
                                                              jstring jAdId);
};

JNIEXPORT void JNICALL Java_ir_tapsell_sdk_Tapsell_onOpened(JNIEnv *env,
                                                              jobject thiz,
                                                              jstring jZoneId,
                                                              jstring jAdId) {
  std::string zoneId = env->GetStringUTFChars(jZoneId, NULL);
  std::string adId = env->GetStringUTFChars(jAdId, NULL);
  if (Tapsell::onOpenedCbs.find(zoneId) != Tapsell::onOpenedCbs.end()) {
    Tapsell::onOpenedCbs[zoneId](QString::fromStdString(adId));
    Tapsell::onOpenedCbs.erase(zoneId);
  }
}
