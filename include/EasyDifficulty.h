#pragma once

#include "Difficulty.h"

class EasyDifficulty : public Difficulty
{
public:
    int getHiddenCount(int wordLength) override;
};