#include "../Player.h"

Player::Player(string _name)
{
    name = _name;
}

string Player::getName() const
{
    return name;
}

Score Player::getScore() const
{
    return score;
}

void Player::addScore(int pts)
{
    score.addPoint(pts);
}