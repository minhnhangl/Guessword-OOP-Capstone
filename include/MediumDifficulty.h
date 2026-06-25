#pragma once

#include "Difficulty.h"

class MediumDifficulty : public Difficulty
{
public:
<<<<<<< HEAD
    int getHiddenCount(int wordLength) override;
=======
    int getHiddenCount(int wordLength) override
    {
        int count = wordLength * 40 / 100;
        return (count > 0) ? count : 2;
    }
>>>>>>> 1cef71b9970d80b7adda4f12b4964f3c4956cafd
};