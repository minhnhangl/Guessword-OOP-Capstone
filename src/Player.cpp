#include "Player.h"
Player::Player()
{
    name = "";
}
void Player::setName(string name)
{
    this->name = name;
}
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