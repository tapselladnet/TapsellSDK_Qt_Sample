QT += core gui gui-private

android: QT += androidextras

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestProject
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the docuentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#   TestProject sources
SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h \
    TapsellSDKAndHelpers/tapsell.h \

FORMS += \
    mainwindow.ui

#   Add these lines in order to use Tapsell IOS SDK (34 - 47)
ios: SOURCES += \
    TapsellSDKAndHelpers/tapsellIos.cpp \

ios: HEADERS += \
    TapsellSDKAndHelpers/tapsellIos.h

ios: OBJECTIVE_SOURCES += \
    TapsellSDKAndHelpers/TSTapsell.mm

ios: OBJECTIVE_HEADERS += \
    TapsellSDKAndHelpers/TSTapsell.h

#   If you want to modify info.plist,just do it on TapsellSDKAndHelpers/info.plist
QMAKE_INFO_PLIST = TapsellSDKAndHelpers/info.plist

#   in order to embed Tapsell IOS binary framework please go to project settings and
#   in 'Build Steps' for IOS section add a 'Custom Process Step' between qmake and make steps
#   now, in command section just write 'python' and in arguments section add line below:
#   %{sourceDir}/TapsellSDKAndHelpers/embed.py %{buildDir}/TestProject.xcodeproj %{sourceDir}/TapsellSDKAndHelpers/TapsellSDKv3.framework
#   It is obvious that before these steps you have to download Tapsell Plugin from https://answers.tapsell.ir/?page_id=2572 and put it in
#   project root directory.
#   Note that you have to install python.

#   Add these lines in order to use Tapsell ANDROID SDK (58 - 74)
android: SOURCES += \
    TapsellSDKAndHelpers/tapsellAndroid.cpp

android: HEADERS += \
    TapsellSDKAndHelpers/tapsellAndroid.h

android: DISTFILES += \
    TapsellSDKAndHelpers/android/AndroidManifest.xml \
    TapsellSDKAndHelpers/android/gradle/wrapper/gradle-wrapper.jar \
    TapsellSDKAndHelpers/android/gradlew \
    TapsellSDKAndHelpers/android/res/values/libs.xml \
    TapsellSDKAndHelpers/android/build.gradle \
    TapsellSDKAndHelpers/android/gradle/wrapper/gradle-wrapper.properties \
    TapsellSDKAndHelpers/android/gradlew.bat \
    TapsellSDKAndHelpers/android/src/ir/tapsell/sdk/Tapsell.java

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/TapsellSDKAndHelpers/android
