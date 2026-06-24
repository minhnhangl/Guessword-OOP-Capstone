#pragma once

#include "Difficulty.h"

class EasyDifficulty : public Difficulty
{
public:
    int getHiddenCount(int wordLength) override
    {
        int count = wordLength * 20 / 100;
        return (count > 0) ? count : 1;
    }
};