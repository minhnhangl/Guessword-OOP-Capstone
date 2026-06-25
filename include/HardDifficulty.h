#pragma once

#include "Difficulty.h"

class HardDifficulty : public Difficulty
{
public:
    int getHiddenCount(int wordLength) override
    {
        int count = wordLength * 60 / 100;
        return (count > 0) ? count : 3;
    }
};