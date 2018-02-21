package ir.tapsell.sdk;

import android.util.Log;
import android.app.Activity;
import android.widget.Toast;
import android.content.Context;
import ir.tapsell.sdk.TapsellQt;
import ir.tapsell.sdk.TapsellQtListener;
import ir.tapsell.sdk.nativeads.TapsellQtNativeListener;
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

    public static native void onNativeBannerAdAvailable(String s, String s1, String s2, String s3,
                                                        String s4, String s5, String s6, String s7);
    public static native void onNativeBannerError(String zoneId, String error);
    public static native void onNativeBannerNoAdAvailable(String zoneId);
    public static native void onNativeBannerNoNetwork(String zoneId);

    public static native void onNativeVideoAdAvailable(String s, String s1, String s2, String s3,
                                                       String s4, String s5, String s6);
    public static native void onNativeVideoError(String zoneId, String error);
    public static native void onNativeVideoNoAdAvailable(String zoneId);
    public static native void onNativeVideoNoNetwork(String zoneId);

    private static final int TOP = 1;
    private static final int BOTTOM = 2;
    private static final int LEFT = 3;
    private static final int RIGHT = 4;
    private static final int CENTER = 5;

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

    public static void nativeBannerAdShown(Context context, String ad_id) {
        TapsellQtModule.onNativeBannerAdShown(context, ad_id);
    }

    public static void nativeBannerAdClicked(Context context, String ad_id) {
        TapsellQtModule.onNativeBannerAdClicked(context, ad_id);
    }

    public static void requestNativeBannerAd(Activity activity, final String zoneId) {
        TapsellQtModule.requestNativeBannerAd(activity, zoneId, new TapsellQtNativeListener() {
                    @Override
                    public void onBannerAdAvailable(String zoneId, String adId, String title, String description, String iconUrl, String ctaText, String portraitUrl, String landscapeUrl) {
                        Tapsell.onNativeBannerAdAvailable(zoneId, adId, title, description, iconUrl, ctaText, portraitUrl, landscapeUrl);
                    }

                    @Override
                    public void onVideoAdAvailable(String zoneId, String adId, String title, String description, String iconUrl, String ctaText, String videoUrl) {}

                    @Override
                    public void onError(String zoneId, String error) {
                        Tapsell.onNativeBannerError(zoneId, error);
                    }

                    @Override
                    public void onNoAdAvailable(String zoneId) {
                        Tapsell.onNativeBannerNoAdAvailable(zoneId);
                    }

                    @Override
                    public void onNoNetwork(String zoneId) {
                        Tapsell.onNativeBannerNoNetwork(zoneId);
                    }
                });
    }

    public static void nativeVideoAdShown(Context context, String ad_id) {
        TapsellQtModule.onNativeVideoAdShown(context, ad_id);
    }

    public static void nativeVideoAdClicked(Context context, String ad_id) {
        TapsellQtModule.onNativeVideoAdClicked(context, ad_id);
    }

    public static void requestNativeVideoAd(Activity activity, final String zoneId) {
        TapsellQtModule.requestNativeVideoAd(activity, zoneId, new TapsellQtNativeListener() {
            @Override
            public void onBannerAdAvailable(String zoneId, String adId, String title, String description, String iconUrl, String ctaText, String portraitUrl, String landscapeUrl) {}

            @Override
            public void onVideoAdAvailable(String zoneId, String adId, String title, String description, String iconUrl, String ctaText, String videoUrl) {
                Tapsell.onNativeVideoAdAvailable(zoneId, adId, title, description, iconUrl, ctaText, videoUrl);
            }

            @Override
            public void onError(String zoneId, String error) {
                Tapsell.onNativeVideoError(zoneId, error);
            }

            @Override
            public void onNoAdAvailable(String zoneId) {
                Tapsell.onNativeVideoNoAdAvailable(zoneId);
            }

            @Override
            public void onNoNetwork(String zoneId) {
                Tapsell.onNativeVideoNoNetwork(zoneId);
            }
        });
    }

    public static void requestBannerAd(Activity activity, String zoneId, int bannerType, int horizontalGravity, int verticalGravity) {
        TapsellQtModule.requestBannerAd(activity, zoneId, bannerType, horizontalGravity, verticalGravity);
    }

    public static void setDebugMode(Context context, boolean debug) {
        TapsellQtModule.setDebugMode(context, debug);
    }

    public static boolean isDebugMode(Context context) {
        return TapsellQtModule.isDebugMode(context);
    }

    public static String getAppUserId(Context context) {
        return TapsellQtModule.getAppUserId(context);
    }

    public static void PermissionHandlerConfig(Context context, int permissionHandlerConfig) {
        TapsellQtModule.setPermissionHandlerConfig(context, permissionHandlerConfig);
    }

    public static String getVersion() {
        return TapsellQtModule.getVersion();
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
