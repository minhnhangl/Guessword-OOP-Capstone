#include "Game.h"

#include <iostream>

using namespace std;

int main()
{
    Game game;

    game.loadWords("data/words.txt");

    game.play();

    return 0;
}