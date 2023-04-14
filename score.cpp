#include <QFont>
#include "score.h"

Score::Score(const std::string &owner){
    score = 0;

    if (owner == "player") {
        x = 60;
    } else if (owner == "computer") {
        x = (1200 - 100);
    }

    QFont scoreFont("times", 52);
    setFont(scoreFont);
    setDefaultTextColor(Qt::black);
    setPos(x, y);
    setPlainText(QString::number(score));
}

void Score::updateScore(int value) {
    score += value;
    setPlainText(QString::number(score));
}