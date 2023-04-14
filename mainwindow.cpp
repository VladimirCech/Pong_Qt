#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ball.h"
#include "paddle.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setFixedSize(1200, 825);

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 1200, 800);
    scene->setBackgroundBrush(Qt::lightGray);

    ball = new Ball();
    playerPaddle = new Paddle("left");
    cpuPaddle = new Paddle("right");
    playerPaddle->setPos(20, 400);
    cpuPaddle->setPos(600, 400);

    playerScore = new Score("player");
    cpuScore = new Score("computer");

    ball->setPaddles(playerPaddle, cpuPaddle);

    view = new QGraphicsView(scene, this);
    view->setScene(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setGeometry(0, 0, width(), height());
    view->setFixedSize(1200, 800);
    setCentralWidget(view);

    scene->addItem(ball);
    scene->addItem(playerPaddle);
    scene->addItem(cpuPaddle);
    scene->addItem(playerScore);
    scene->addItem(cpuScore);

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), ball, SLOT(move()));
    connect(timer, SIGNAL(timeout()), playerPaddle, SLOT(updateTargetY()));
    connect(timer, SIGNAL(timeout()), playerPaddle, SLOT(movePaddle()));
    connect(ball, SIGNAL(yChanged(int)), cpuPaddle, SLOT(movePaddleCpu(int)));
    connect(ball, SIGNAL(pointScored(int)), this, SLOT(pointScored(int)));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_actionStart_triggered() {
    timer->start(10);
}

void MainWindow::on_actionPause_triggered() {
    timer->stop();
}

void MainWindow::pointScored(int x) {

    if (x <= 0) {
        playerPaddle->setPos(20, 400);
        cpuPaddle->setPos(600, 400);
        ball->setPos(300, 400);
        cpuScore->updateScore(1);
        timer->stop();
    } else {
        playerPaddle->setPos(20, 400);
        cpuPaddle->setPos(600, 400);
        ball->setPos(300, 400);
        playerScore->updateScore(1);
        timer->stop();
    }

}

