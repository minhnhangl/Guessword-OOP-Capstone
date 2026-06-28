#pragma once

#include <string>
#include "Score.h"

using namespace std;

class Player
{
private:
    string name;
    Score score;// has a

public:
    Player();

    Player(string name);

    void setName(string name);

    string getName() const;

    Score getScore() const;

    void addScore(int point);
};