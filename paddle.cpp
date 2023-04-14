#include <iostream>
#include "paddle.h"

Paddle::Paddle(const std::string &side) : m_targetY(0) {

    if (side == "left") {
        x = (0) + 20;
        setFlag(QGraphicsItem::ItemIsMovable); // povolit pohyb myší
        setAcceptHoverEvents(true); // zapnout zachytávání událostí myši
    } else if (side == "right") {
        x = (1200 - 80) / 2;
    }

    setPos(x, y);
    setRect(x, y, 20, 80);
    setBrush(Qt::white);

}

void Paddle::updateTargetY() {
    // aktualizujeme interní proměnnou s pozicí Y myši
    m_targetY = QCursor::pos().y() - rect().height() / 2;
}

void Paddle::movePaddle() {
    // získáme pozici pálky
    qreal paddleY = pos().y();

    // pohybujeme pálkou ke středové pozici myši
    if (m_targetY < paddleY) {
        paddleY -= 4;
    } else if (m_targetY > paddleY) {
        paddleY += 4;
    }

    // ošetříme hranice herní plochy
    if (paddleY < 0) {
        paddleY = 0;
    } else if (paddleY > scene()->height() - rect().height()) {
        paddleY = scene()->height() - rect().height();
    }

    // nastavíme novou pozici pálky
    setPos(x, paddleY);
//    qDebug() << "CPU paddle position:" << pos();

}

void Paddle::movePaddleCpu(int ballPos) {

    // získáme pozici pálky
    qreal paddleY = pos().y();

    // pohybujeme pálkou ke středové pozici myši
    if (ballPos < paddleY) {
        paddleY -= 3;
    } else if (ballPos > paddleY) {
        paddleY += 3;
    }

    // ošetříme hranice herní plochy
    if (paddleY < 0) {
        paddleY = 0;
    } else if (paddleY > scene()->height() - rect().height()) {
        paddleY = scene()->height() - rect().height();
    }

    // nastavíme novou pozici pálky
    setPos(x, paddleY);
//    qDebug() << "CPU paddle position:" << pos();
}










