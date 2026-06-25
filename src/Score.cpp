#include "Score.h"

Score::Score(int _points)
{
    points = _points;
}

void Score::addPoint(int pts)
{
    points += pts;
}

int Score::getPoints() const
{
    return points;
}

Score Score::operator+(const Score &other)
{
    Score temp;
    temp.points = this->points + other.points;
    return temp;
}

ostream& operator<<(ostream &out, const Score &s)
{
    out << s.points << " points";
    return out;
}