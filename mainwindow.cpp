#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Tapsell::initialize(appKey);

    ui->pushButton_2->setEnabled(false);
    Tapsell::setRewardListener([](QString zoneId, QString adId, bool completed, bool rewarded) {
        qDebug() << "isRewarded: " << (rewarded ? "YES" : "No") << ", completed: " << (completed ? "YES" : "NO") << endl;
    });

    Tapsell::setDebugMode(true);
    qDebug() << "isDebugMode: " << Tapsell::isDebugMode() << endl;
    
    qDebug() << "Tapsell Version: " << Tapsell::getVersion() << endl;
    
    connect(ui->pushButton, SIGNAL (clicked()), this, SLOT (requestAd()));
    connect(this, SIGNAL (enableShowButtonSignal()), this, SLOT (enableShowButtonSlot()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

QString AD_ID = "";
QString NATIVE_BANNER_AD_ID = "";
QString NATIVE_VIDEO_AD_ID = "";
QString nativeMode = "banner";

void MainWindow::on_pushButton_clicked(){}

void MainWindow::on_pushButton_2_clicked()
{
    ui->pushButton_2->setEnabled(false);
    Tapsell::showAd(ZONE_ID, AD_ID, false, false, ROTATION_UNLOCKED, true,
            [](QString adId) {
                qDebug() << "Ad onOpened: " << adId;
            },
            [](QString adId) {
                qDebug() << "Ad onClosed: " << adId;
            });
}

void MainWindow::on_pushButton_3_clicked()
{

    Tapsell::requestNativeBannerAd(NATIVE_BANNER_ZONEID,
        [&](QString adId,QString title, QString description, QString iconUrl,
                                   QString ctaText, QString portraitUrl, QString landscapeUrl) {
        nativeMode = "banner";
        qDebug() << "onNativeBannerAdAvailable";
        NATIVE_BANNER_AD_ID = adId;
        QString nativeResult = "Sponsored: \n" + title + "\n" + description + "\n" + "ad icon url: " + iconUrl +
                "\n" + "banner urls: \nPortriat: \n" + portraitUrl + "\nLandscape: " + landscapeUrl;\
        ui->label->setText(nativeResult);
        ui->pushButton_5->setText(ctaText);
        Tapsell::onNativeBannerAdShown(adId);
        }, [](){
        qDebug() << "onNoNativeBannerAdAvailable";
        }, [](){
        qDebug() << "onNoNetwork";
        }, [](QString error) {
        qDebug() << "onError: " << error;
        });
}

void MainWindow::on_pushButton_5_clicked()
{
    if (nativeMode == "banner") {
        Tapsell::onNativeBannerAdClicked(NATIVE_BANNER_AD_ID);
    } else if (nativeMode == "video") {
        Tapsell::onNativeVideoAdClicked(NATIVE_VIDEO_AD_ID);
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    Tapsell::requestNativeVideoAd(NATIVE_VIDEO_ZONEID,
        [&](QString adId,QString title, QString description, QString iconUrl,
                                   QString ctaText, QString videoUrl) {
        nativeMode = "video";
        qDebug() << "onNativeVideoAdAvailable";
        NATIVE_VIDEO_AD_ID = adId;
        QString nativeResult = "Sponsored: \n" + title + "\n" + description + "\n" + "ad icon url: " + iconUrl +
                "\n" + "Video url: \n" + videoUrl;
        ui->label->setText(nativeResult);
        ui->pushButton_5->setText(ctaText);
        Tapsell::onNativeVideoAdShown(adId);
        }, [](){
        qDebug() << "onNoNativeVideoAdAvailable";
        }, [](){
        qDebug() << "onNoNetwork";
        }, [](QString error) {
        qDebug() << "onError: " << error;
        });
}

void MainWindow::on_pushButton_6_clicked()
{
    Tapsell::requestStandardBannerAd(STANDARD_BANNER_ZONEID, BANNER_320x100, BOTTOM, CENTER);
}

void MainWindow::requestAd(){
    Tapsell::requestAd(ZONE_ID, false, [&](QString adId) {
        qDebug() << "onAdAvailable" << endl;
        AD_ID = adId;
        emit enableShowButtonSignal();
    }, []() {
        qDebug() << "onNoAdAvailable";
    }, []() {
        qDebug() << "onNoNetwork";
    }, [](QString error) {
        qDebug() << "onError: " << error;
    }, [](QString adId) {
        qDebug() << "onExpiring " << adId;
    });
}

void MainWindow::enableShowButton(){
    ui->pushButton_2->setEnabled(true);
}

void MainWindow::enableShowButtonSlot(){
     ui->pushButton_2->setEnabled(true);
}
