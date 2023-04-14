#ifndef BALL_H
#define BALL_H

#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include <QObject>
#include <QTimer>
#include <QPainter>
#include <QBrush>
#include <QRandomGenerator>
#include "paddle.h"


class Ball : public QTimer, public QGraphicsEllipseItem {
Q_OBJECT

public:
    Ball(QGraphicsItem *parent = nullptr);

    void setPaddles(Paddle *player, Paddle *computer);

public slots:

    void move();

signals:

    void yChanged(int y);

    void pointScored(int x);

protected:

    QWidget *parent = nullptr;
    QRandomGenerator *gen = QRandomGenerator::global();
    QPointF *velocity;
    int x = 600;
    int y = 400;
    float kx;
    float ky;
    Paddle *playerPaddle;
    Paddle *cpuPaddle;
    int angle;
    float speed;
    float newAngle = 0;

};

#endif // BALL_H

