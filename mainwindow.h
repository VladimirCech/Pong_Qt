#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QGraphicsView>

#include "ball.h"
#include "paddle.h"
#include "score.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();


signals:

private slots:

    void on_actionStart_triggered();

    void on_actionPause_triggered();

    void pointScored(int x);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsView *view;
    Paddle *playerPaddle;
    Paddle *cpuPaddle;
    Score *playerScore;
    Score *cpuScore;
    Ball *ball;
    QTimer *timer;

protected:

    void pointScored();
};

#endif // MAINWINDOW_H
