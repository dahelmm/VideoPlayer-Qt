#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    player = new QMediaPlayer(this);
    videoWidget = new QVideoWidget;
    player->setVideoOutput(videoWidget);
    videoWidget->setGeometry(50,50,800,600);
    videoWidget->show();

    connect(player,SIGNAL(positionChanged(qint64)),this,SLOT(setPosition(qint64)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_action_triggered()
{
    player->setMedia(QUrl(QFileDialog::getOpenFileName(this,"Выберите видео","","(*.mp4)")));
    player->setVolume(50);
    ui->prB_volume->setValue(player->volume());
    qDebug()<<player->duration();

}

void MainWindow::on_pB_play_clicked()
{
    player->play();
    ui->prB_time->setMaximum(player->duration()/1000);
}

void MainWindow::on_pB_pause_clicked()
{
    player->pause();

}

void MainWindow::setPosition(qint64 position)
{
    int pos = position/1000;

    ui->prB_time->setValue(pos);

}
