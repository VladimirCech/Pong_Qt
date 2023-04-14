//
// Created by hafy on 3/27/23.
//

#ifndef PONG_V2_PADDLE_H
#define PONG_V2_PADDLE_H

#include <QWidget>
#include <QTimer>
#include <QPainter>
#include <QApplication>
#include <QGraphicsView>
#include <memory>
#include <QGraphicsRectItem>
#include <QCursor>
#include <QMouseEvent>
#include <QGuiApplication>


class Paddle : public QTimer, public QGraphicsRectItem {
Q_OBJECT

public:
    Paddle(const std::string &side);

public slots:

    void movePaddle();

    void updateTargetY();

    void movePaddleCpu(int ballPos);

private:

protected:
    QWidget *parent = nullptr;
    int x = 0;

    int y = 0;

    int m_targetY;
};

typedef std::shared_ptr<Paddle> PaddlePtr;


#endif //PONG_V2_PADDLE_H
