#pragma once

class Difficulty
{
public:
    virtual int getHiddenCount(int wordLength)=0;

    virtual ~Difficulty(){}
};