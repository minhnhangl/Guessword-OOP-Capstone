#pragma once

#include "Difficulty.h"

class HardDifficulty : public Difficulty
{
public:
    int getHiddenCount(int wordLength) override;
};