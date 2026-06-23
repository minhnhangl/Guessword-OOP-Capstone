#pragma once

#include <string>
#include "Score.h"

using namespace std;

class Player
{
private:
    string name;
    Score score;

public:
    Player();

    Player(string name);

    string getName() const;

    Score getScore() const;

    void addScore(int point);
};