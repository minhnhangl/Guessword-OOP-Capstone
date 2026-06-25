#pragma once

#include "Difficulty.h"

class HardDifficulty : public Difficulty
{
public:
<<<<<<< HEAD
    int getHiddenCount(int wordLength) override;
=======
    int getHiddenCount(int wordLength) override
    {
        int count = wordLength * 60 / 100;
        return (count > 0) ? count : 3;
    }
>>>>>>> 1cef71b9970d80b7adda4f12b4964f3c4956cafd
};