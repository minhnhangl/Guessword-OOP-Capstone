#pragma once

#include <iostream>

using namespace std;

class Score
{
private:
    int points;

public:
    Score(int points = 0);

    void addPoint(int p);

    int getPoints() const;

    Score operator+(const Score& other);

    friend ostream& operator<<(ostream& out,
                               const Score& s);
};