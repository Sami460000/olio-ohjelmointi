#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void timeout();

private slots:
    void on_time120Button_clicked();
    void on_time300Button_clicked();
    void on_startButton_clicked();
    void on_stopButton_clicked();
    void on_player1SwitchButton_clicked();
    void on_player2SwitchButton_clicked();

private:
    void updateProgressBar();
    void setGameInfoText(QString text, short fontSize);
    void resetGame();

    Ui::MainWindow *ui;
    QTimer *timer;

    short player1Time;
    short player2Time;
    short currentTime;
    short gameTime;

    bool player1Turn;
    bool gameRunning;
};

#endif
