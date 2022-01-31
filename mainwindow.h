#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QMediaContent>
#include <QVideoWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_action_triggered();

    void on_pB_play_clicked();

    void on_pB_pause_clicked();
    void setPosition(qint64);

    void on_pB_min5sec_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QMediaPlayer *player;
    QMediaContent *content;
    QVideoWidget *videoWidget;
};
#endif // MAINWINDOW_H
