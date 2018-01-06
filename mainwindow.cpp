#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Tapsell::initialize(appKey);
    Tapsell::setDebugMode(true);

    Tapsell::setRewardListener([](QString zoneId, QString adId, bool completed, bool rewarded) {
        qDebug() << "Reward! " << completed << ", " << rewarded;
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
QString AD_ID = "";
void MainWindow::on_pushButton_clicked()
{
    Tapsell::requestAd(ZONE_ID, false, [](QString adId) {
            qDebug() << "onAdAvailable";
            AD_ID = adId;
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

void MainWindow::on_pushButton_2_clicked()
{
    Tapsell::showAd(ZONE_ID, AD_ID, false, false, ROTATION_UNLOCKED, true,
            [](QString adId) {
                qDebug() << "onOpened";
            },
            [](QString adId) {
                qDebug() << "onClosed";
            });
}
