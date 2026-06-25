#pragma once

#include <vector>

#include "Word.h"
#include "Player.h"
#include "Difficulty.h"

using namespace std;

class Game
{
private:
    vector<Word> words;

    Player player;

    Difficulty* difficulty;

    int currentIndex;

public:
    Game();

    ~Game();

    void loadWords(string filename);

    void chooseDifficulty();

    void play();

    void displayResult();

};