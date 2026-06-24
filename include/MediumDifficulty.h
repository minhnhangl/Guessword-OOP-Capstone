#pragma once

#include "Difficulty.h"

class MediumDifficulty : public Difficulty
{
public:
    int getHiddenCount(int wordLength) override
    {
        int count = wordLength * 40 / 100;
        return (count > 0) ? count : 2;
    }
};