package ir.tapsell.sdk;

import android.util.Log;
import android.app.Activity;
import android.widget.Toast;
import android.content.Context;
import ir.tapsell.sdk.TapsellQt;
import ir.tapsell.sdk.TapsellQtListener;
import ir.tapsell.sdk.TapsellQtModule;

public class Tapsell {
    public static native void onAdShowFinished(String zoneId, String adId, boolean completed, boolean rewarded);
    public static native void onAdAvailable(String zoneId, String adId);
    public static native void onError(String zoneId, String error);
    public static native void onNoAdAvailable(String zoneId);
    public static native void onNoNetwork(String zoneId);
    public static native void onExpiring(String zoneId, String adId);
    public static native void onClosed(String zoneId, String adId);
    public static native void onOpened(String zoneId, String adId);

//    public static native void onNativeBannerAdAvailable(String s, String s1, String s2, String s3,
//                                                        String s4, String s5, String s6, String s7);
//    public static native void onNativeBannerError(String zoneId, String error);
//    public static native void onNativeBannerNoAdAvailable(String zoneId);
//    public static native void onNativeBannerNoNetwork(String zoneId);

//    public static native void onNativeVideoAdAvailable(String s, String s1, String s2, String s3,
//                                                       String s4, String s5, String s6);
//    public static native void onNativeVideoError(String zoneId, String error);
//    public static native void onNativeVideoNoAdAvailable(String zoneId);
//    public static native void onNativeVideoNoNetwork(String zoneId);

    private TapsellQt tapsellQt = null;

    private void initializeTapsell() {
        tapsellQt = TapsellQt.newInstance(new TapsellQtListener() {
            @Override
            public void onAdShowFinished(String zoneId, String adId, boolean completed, boolean rewarded) {
                Tapsell.onAdShowFinished(zoneId, adId, completed, rewarded);
            }

            @Override
            public void onAdAvailable(String zoneId, String adId) {
                Tapsell.onAdAvailable(zoneId, adId);
            }

            @Override
            public void onError(String zoneId, String error) {
                Tapsell.onError(zoneId, error);
            }

            @Override
            public void onNoAdAvailable(String zoneId) {
                Tapsell.onNoAdAvailable(zoneId);
            }

            @Override
            public void onNoNetwork(String zoneId) {
                Tapsell.onNoNetwork(zoneId);
            }

            @Override
            public void onExpiring(String zoneId, String adId) {
                Tapsell.onExpiring(zoneId, adId);
            }

            @Override
            public void onClosed(String zoneId, String adId) {
                Tapsell.onClosed(zoneId, adId);
            }

            @Override
            public void onOpened(String zoneId, String adId) {
                Tapsell.onOpened(zoneId, adId);
            }
        });
    }

    public static void initialize(Context context, String appKey) {
        Tapsell tapsell = new Tapsell();
        tapsell.initializeTapsell();
        TapsellQtModule.initialize(context, appKey);
    }

    public static void showAd(Context context, final String adId, final boolean back_disabled, final boolean immersive_mode, final int rotation_mode,
                              final boolean showExitDialog) {

        TapsellQtModule.showAd(context, adId, back_disabled, immersive_mode, rotation_mode,
                showExitDialog);

    }

    public static void requestAd(Context context, String zoneId, boolean isCached) {
        TapsellQtModule.requestAd(context, zoneId, isCached);
    }

//    public static void nativeBannerAdShown(String ad_id) {
//        TapsellQtModule.nativeBannerAdShown(ad_id, app);
//    }
//
//    public static void nativeBannerAdClicked(String ad_id) {
//        TapsellQtModule.nativeBannerAdClicked(ad_id, app);
//    }
//
//    public static void requestNativeBannerAd(final String zoneId) {
//        TapsellQtModule.requestNativeBannerAd(zoneId, app, new TapsellQtNativeCppListener() {
//            @Override
//            public void onBannerAdAvailable(String s, String s1, String s2, String s3, String s4, String s5, String s6, String s7) {
//                Tapsell.onNativeBannerAdAvailable(s, s1, s2, s3, s4, s5, s6, s7);
//            }
//
//            @Override
//            public void onVideoAdAvailable(String s, String s1, String s2, String s3, String s4, String s5, String s6) {}
//
//            @Override
//            public void onError(String s, String s1) {
//                Tapsell.onNativeBannerError(s, s1);
//            }
//
//            @Override
//            public void onNoAdAvailable(String s) {
//                Tapsell.onNativeBannerNoAdAvailable(s);
//            }
//
//            @Override
//            public void onNoNetwork(String s) {
//                Tapsell.onNativeBannerNoNetwork(s);
//            }
//        });
//    }
//
//    public static void nativeVideoAdShown(String ad_id) {
//        TapsellQtModule.nativeVideoAdShown(ad_id, app);
//    }
//
//    public static void nativeVideoAdClicked(String ad_id) {
//        TapsellQtModule.nativeVideoAdClicked(ad_id, app);
//    }
//
//    public static void requestNativeVideoAd(final String zoneId) {
//        TapsellQtModule.requestNativeVideoAd(zoneId, app, new TapsellQtNativeCppListener() {
//            @Override
//            public void onVideoAdAvailable(String s, String s1, String s2, String s3, String s4, String s5, String s6) {
//                Tapsell.onNativeVideoAdAvailable(s, s1, s2, s3, s4, s5, s6);
//            }
//
//            @Override
//            public void onBannerAdAvailable(String s, String s1, String s2, String s3, String s4, String s5, String s6, String s7) {}
//
//            @Override
//            public void onError(String s, String s1) {
//                Tapsell.onNativeVideoError(s, s1);
//            }
//
//            @Override
//            public void onNoAdAvailable(String s) {
//                Tapsell.onNativeVideoNoAdAvailable(s);
//            }
//
//            @Override
//            public void onNoNetwork(String s) {
//                Tapsell.onNativeVideoNoNetwork(s);
//            }
//        });
//    }
//
//    public static void requestStandardBannerAd(final String zoneId, final int bannerType,
//                                               final int horizontalGravity, final int verticalGravity) {
//        TapsellQtModule.requestBannerAd(app, zoneId, bannerType, horizontalGravity, verticalGravity);
//    }
//
    public static void setDebugMode(Context context, boolean debug) {
        TapsellQtModule.setDebugMode(context, debug);
    }

    public static boolean isDebugMode(Context context) {
        return TapsellQtModule.isDebugMode(context);
    }

    public static void setAppUserId(Context context, String appUserId) {
        TapsellQtModule.setAppUserId(context, appUserId);
    }

    public static String getAppUserId(Context context) {
        return TapsellQtModule.getAppUserId(context);
    }

    public static void setPermissionHandlerConfig(Context context, int permissionHandlerConfig) {
        TapsellQtModule.setPermissionHandlerConfig(context, permissionHandlerConfig);
    }

    public static String getVersion(Context context) {
        return TapsellQtModule.getVersion(context);
    }

    public static void setMaxAllowedBandwidthUsage(Context context, int maxBpsSpeed) {
        TapsellQtModule.setMaxAllowedBandwidthUsage(context, maxBpsSpeed);
    }

    public static void setMaxAllowedBandwidthUsagePercentage(Context context, int maxPercentage) {
        TapsellQtModule.setMaxAllowedBandwidthUsagePercentage(context, maxPercentage);
    }

    public static void clearBandwidthUsageConstrains(Context context) {
        TapsellQtModule.clearBandwidthUsageConstrains(context);
    }

}
