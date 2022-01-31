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
    ui->l_volume->setText(QString::number(ui->hS_volume->value()));

    connect(player,SIGNAL(positionChanged(qint64)),this,SLOT(setPosition(qint64)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_action_triggered()
{
    player->setMedia(QUrl(QFileDialog::getOpenFileName(this,"Выберите видео","")));
    player->setVolume(50);

}

void MainWindow::on_pB_play_clicked()
{
    int pos = player->duration()/1000;
    int min = pos/60;
    int sec= pos-(min*60);
    QString str = "0"+QString::number(min)+":"+QString::number(sec);
    ui->l_fullTime->setText(str);
    player->play();

}

void MainWindow::on_pB_pause_clicked()
{
    player->pause();

}

void MainWindow::setPosition(qint64 position)
{
    int pos = position/1000;
    int min = pos/60;
    int sec= pos-(min*60);
    QString str = QString("%1").arg(min,2,10,QChar('0'))+":"+QString("%1").arg(sec,2,10,QChar('0'));
    ui->l_currentTime->setText(str);
    ui->hS_position->setMaximum(player->duration()/1000);
    ui->hS_position->setValue(pos);

}

void MainWindow::on_pB_min5sec_clicked()
{
    player->setPosition(player->position()-5000);
}



void MainWindow::on_hS_volume_sliderMoved(int position)
{
    player->setVolume(position);
    ui->l_volume->setText(QString::number(position));
}

void MainWindow::on_pB_plus5sec_clicked()
{
    player->setPosition(player->position()+5000);

}

void MainWindow::on_hS_position_sliderMoved(int position)
{
    player->setPosition(position*1000);
}

void MainWindow::on_action_fullScreen_triggered()
{
    videoWidget->setFullScreen(true);
    if(Qt::Key_Escape==true)
    {
        videoWidget->setFullScreen(false);
    }
}
