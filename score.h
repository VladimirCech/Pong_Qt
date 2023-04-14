#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score : public QGraphicsTextItem {
public:
    explicit Score(const std::string &owner = "");

    void updateScore(int value);

protected:
    int x;
    int y = 20;
    int score = 0;
};

#endif // SCORE_H
