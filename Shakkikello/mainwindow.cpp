#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFont>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , timer(new QTimer(this))
    , player1Time(0)
    , player2Time(0)
    , currentTime(0)
    , gameTime(0)
    , player1Turn(true)
    , gameRunning(false)
{
    ui->setupUi(this);

    connect(timer, &QTimer::timeout, this, &MainWindow::timeout);

    // Initial
    ui->player1ProgressBar->setRange(0, 100);
    ui->player2ProgressBar->setRange(0, 100);

    ui->player1ProgressBar->setValue(0);
    ui->player2ProgressBar->setValue(0);

    ui->player1SwitchButton->setEnabled(false);
    ui->player2SwitchButton->setEnabled(false);

    setGameInfoText("Select playtime and press start game!", 12);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setGameInfoText(QString text, short fontSize)
{
    ui->infoLabel->setText(text);

    QFont font = ui->infoLabel->font();
    font.setPointSize(fontSize);
    font.setBold(true);
    ui->infoLabel->setFont(font);
}

void MainWindow::updateProgressBar()
{
    if (gameTime <= 0) {
        ui->player1ProgressBar->setValue(0);
        ui->player2ProgressBar->setValue(0);
        return;
    }

    int p1Percent = (player1Time * 100) / gameTime;
    int p2Percent = (player2Time * 100) / gameTime;

    if (p1Percent < 0) p1Percent = 0;
    if (p2Percent < 0) p2Percent = 0;

    ui->player1ProgressBar->setValue(p1Percent);
    ui->player2ProgressBar->setValue(p2Percent);
}

void MainWindow::resetGame()
{
    timer->stop();
    gameRunning = false;
    player1Turn = true;

    player1Time = gameTime;
    player2Time = gameTime;
    currentTime = gameTime;

    updateProgressBar();

    ui->player1SwitchButton->setEnabled(false);
    ui->player2SwitchButton->setEnabled(false);

    if (gameTime > 0) {
        setGameInfoText("Ready to play", 14);
    } else {
        setGameInfoText("Select playtime and press start game!", 12);
    }
}

void MainWindow::on_time120Button_clicked()
{
    gameTime = 120;
    resetGame();
}

void MainWindow::on_time300Button_clicked()
{
    gameTime = 300;
    resetGame();
}

void MainWindow::on_startButton_clicked()
{
    if (gameTime <= 0) {
        setGameInfoText("Select playtime first!", 12);
        return;
    }

    player1Time = gameTime;
    player2Time = gameTime;
    currentTime = player1Time;

    player1Turn = true;
    gameRunning = true;

    updateProgressBar();

    ui->player1SwitchButton->setEnabled(true);
    ui->player2SwitchButton->setEnabled(true);

    setGameInfoText("Game ongoing", 16);

    timer->start(1000); // one second interval
}

void MainWindow::on_stopButton_clicked()
{
    timer->stop();
    gameRunning = false;

    ui->player1SwitchButton->setEnabled(false);
    ui->player2SwitchButton->setEnabled(false);

    if (gameTime > 0) {
        player1Time = gameTime;
        player2Time = gameTime;
        updateProgressBar();
        setGameInfoText("Ready to play", 14);
    } else {
        setGameInfoText("Select playtime and press start game!", 12);
    }
}

void MainWindow::on_player1SwitchButton_clicked()
{
    if (!gameRunning)
        return;


    if (player1Turn) {
        player1Turn = false;
        currentTime = player2Time;
    }
}

void MainWindow::on_player2SwitchButton_clicked()
{
    if (!gameRunning)
        return;


    if (!player1Turn) {
        player1Turn = true;
        currentTime = player1Time;
    }
}

void MainWindow::timeout()
{
    if (!gameRunning)
        return;

    if (player1Turn) {
        player1Time--;
        currentTime = player1Time;

        if (player1Time <= 0) {
            player1Time = 0;
            updateProgressBar();
            timer->stop();
            gameRunning = false;

            ui->player1SwitchButton->setEnabled(false);
            ui->player2SwitchButton->setEnabled(false);

            setGameInfoText("Player 2 WON!!", 16);
            return;
        }
    } else {
        player2Time--;
        currentTime = player2Time;

        if (player2Time <= 0) {
            player2Time = 0;
            updateProgressBar();
            timer->stop();
            gameRunning = false;

            ui->player1SwitchButton->setEnabled(false);
            ui->player2SwitchButton->setEnabled(false);

            setGameInfoText("Player 1 WON!!", 16);
            return;
        }
    }

    updateProgressBar();
}
