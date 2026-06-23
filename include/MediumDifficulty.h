#pragma once

#include "Difficulty.h"

class MediumDifficulty : public Difficulty
{
public:
    int getHiddenCount(int wordLength) override;
};