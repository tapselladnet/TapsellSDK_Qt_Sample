#-------------------------------------------------
#
# Project created by QtCreator 2018-01-01T13:29:35
#
#-------------------------------------------------

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


SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h \
    TapsellSDKAndHelpers/tapsell.h \

FORMS += \
    mainwindow.ui

android: SOURCES += \
    TapsellSDKAndHelpers/tapsellAndroid.cpp

android: HEADERS += \
    TapsellSDKAndHelpers/tapsellAndroid.h

ios: SOURCES += \
    TapsellSDKAndHelpers/tapsellIos.cpp \

ios: HEADERS += \
    TapsellSDKAndHelpers/tapsellIos.h

ios: OBJECTIVE_SOURCES += \
    TapsellSDKAndHelpers/TSTapsell.mm

ios: OBJECTIVE_HEADERS += \
    TapsellSDKAndHelpers/TSTapsell.h

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

ios: LIBS += -framework Foundation

QMAKE_INFO_PLIST = TapsellSDKAndHelpers/info.plist
