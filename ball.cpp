#include <iostream>
#include "ball.h"
#include "paddle.h"

Ball::Ball(QGraphicsItem *parent) : QGraphicsEllipseItem(parent) {
    setRect(0, 0, 20, 20);
    setPos(600, 400);
    setBrush(Qt::white);
    srand(time(nullptr));
    angle = rand() % 360; // náhodný směr v rozsahu 0-359 stupňů
    kx = 5 * cos(angle * M_PI / 180.0); // x-složka vektoru rychlosti s délkou 5
    ky = 5 * sin(angle * M_PI / 180.0); // y-složka vektoru rychlosti s délkou 5
}

void Ball::setPaddles(Paddle *player, Paddle *computer) {

    playerPaddle = player;
    cpuPaddle = computer;

}

void Ball::move() {

    if (x < 0 || x > 1180) {
        emit pointScored(x);
        x = 600;
        y = 400;
        angle = rand() % 360; // náhodný směr v rozsahu 0-359 stupňů
        kx = 5 * cos(angle * M_PI / 180.0); // x-složka vektoru rychlosti s délkou 5
        ky = 5 * sin(angle * M_PI / 180.0); // y-složka vektoru rychlosti s délkou 5
    }
    if (y < 0 || y > 780) ky *= -1;


    if (collidesWithItem(playerPaddle) || collidesWithItem(cpuPaddle)) {
        angle = rand() % 91 - 45;
        speed = sqrt(kx * kx + ky * ky);
        newAngle = atan2(ky, kx) + angle * M_PI / 180.0;
        kx = speed * cos(newAngle);
        ky = speed * sin(newAngle);
        if (kx < 0) x += 1;
        else x -= 1;
        kx *= -1;

    }

    x += kx;
    y += ky;
    setPos(x, y);

    emit yChanged(y);

}
