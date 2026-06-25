#include "Game.h"

#include "EasyDifficulty.h"
#include "MediumDifficulty.h"
#include "HardDifficulty.h"

#include <fstream>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
Game::Game()
{
    difficulty = nullptr;
    currentIndex = -1;

    srand(time(NULL));
}
Game::~Game()
{
    if (difficulty != nullptr)
    {
        delete difficulty;
    }
}
void Game::loadWords(string filename)
{
    ifstream fin(filename);

    if (!fin.is_open())
    {
        cout << "Cannot open file!" << endl;
        return;
    }

    string word;

    while (fin >> word)
    {
        Word w(word);
        words.push_back(w);
    }

    fin.close();

    cout << "Loaded " << words.size() << " words." << endl;
}
void Game::chooseDifficulty()
{
    int choice;

    cout << "==============================" << endl;
    cout << "      GUESS WORD GAME" << endl;
    cout << "==============================" << endl;

    cout << "1. Easy" << endl;
    cout << "2. Medium" << endl;
    cout << "3. Hard" << endl;

    cout << "Choose difficulty: ";
    cin >> choice;

    if (difficulty != nullptr)
    {
        delete difficulty;
    }

    switch (choice)
    {
    case 1:
        difficulty = new EasyDifficulty();
        break;

    case 2:
        difficulty = new MediumDifficulty();
        break;

    case 3:
        difficulty = new HardDifficulty();
        break;

    default:
        cout << "Invalid choice!" << endl;
        difficulty = new EasyDifficulty();
        break;
    }
}
void Game::play()
{
    if (words.empty())
    {
        cout << "No words loaded!" << endl;
        return;
    }

    chooseDifficulty();

    currentIndex = 0;

    while (currentIndex < words.size())
    {
        Word& currentWord = words[currentIndex];

        int hideCount = difficulty->getHiddenCount(currentWord.getAnswer().length());

        currentWord.hideCharacters(hideCount);

        cout << "\n------------------------" << endl;
        cout << "Word: " << currentWord.getHiddenWord() << endl;

        string answer;

        while (true)
        {
            cout << "Your answer: ";
            cin >> answer;

            if (currentWord.checkAnswer(answer))
            {
                cout << "Correct!" << endl;

                player.addScore(1);

                break;
            }
            else
            {
                cout << "Wrong! Try again." << endl;
            }
        }

        currentIndex++;

        if (currentIndex == words.size())
            break;

        char c;

        cout << "\nContinue? (y/n): ";
        cin >> c;

        if (c == 'n' || c == 'N')
            break;
    }

    displayResult();
}
void Game::displayResult()
{
    cout << "\n==============================" << endl;
    cout << "         GAME OVER" << endl;
    cout << "==============================" << endl;

    cout << "Player: " << player.getName() << endl;

    cout << "Score: " << player.getScore() << endl;

    cout << "Words completed: " << currentIndex << "/" << words.size() << endl;

    cout << "Thank you for playing!" << endl;
}