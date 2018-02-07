#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "tapsell.h"

const QString appKey = "qjmospqbfarbhodregqecbbnfhcjllkflpbpsmdrtpqkapdeptftldfiapfgbamkhalbij";
const QString ZONE_ID = "59b4d07d468465281b792cb7";
const QString NATIVE_BANNER_ZONEID = "59c8a9334684656c504f0e19";
const QString NATIVE_VIDEO_ZONEID = "59c8ae514684656c504fce40";
const QString STANDARD_BANNER_ZONEID = "5a44aa6565a77100013d5fb3";

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
