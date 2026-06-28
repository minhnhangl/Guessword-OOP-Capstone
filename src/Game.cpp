#include "Game.h"

#include "EasyDifficulty.h"
#include "MediumDifficulty.h"
#include "HardDifficulty.h"

#include <fstream>
#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>
#include <cstdlib>

using namespace std;
Game::Game()
{
    difficulty = nullptr;
    currentIndex = 0;
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
        shuffle(words.begin(), words.end(), default_random_engine(time(0)));
    }

    fin.close();

    cout << "Loaded " << words.size() << " words." << endl;
}
void Game::chooseDifficulty()
{
    int choice;

    while (true)
    {
        cout << "==============================" << endl;
        cout << "       GUESS WORD GAME" << endl;
        cout << "==============================" << endl;

        cout << "1. Easy" << endl;
        cout << "2. Medium" << endl;
        cout << "3. Hard" << endl;

        cout << "Choose difficulty: ";
        cin >> choice;

        if (choice == 1)
        {
            difficulty = new EasyDifficulty();
            break;
        }
        else if (choice == 2)
        {
            difficulty = new MediumDifficulty();
            break;
        }
        else if (choice == 3)
        {
            difficulty = new HardDifficulty();
            break;
        }
        else
        {
            cout << "\nInvalid choice! Please try again.\n" << endl;
        }
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
    string playerName;

    cout << "Enter your name: ";
    cin >> playerName;

    player.setName(playerName);
    currentIndex = 0;
    int streak = 0;
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
            cout << "Your answer (or type 'quit' to exit, 'skip' to skip): ";
            cin >> answer;

            if (answer == "quit")
            {
             displayResult();
             return;          // Kết thúc game
            }

            if (answer == "skip")
            {
            cout << "Correct answer: "
             << currentWord.getAnswer() << endl;
            break;           // Sang từ tiếp theo
            }

            if (currentWord.checkAnswer(answer))
            {
                cout << "Correct!" << endl;

                streak++;

                player.addScore(1);

                if (streak == 2)
                {
                    cout << "\n***** BONUS *****" << endl;
                    cout << "2 correct answers in a row!" << endl;

                    Score bonus(1);
                    Score total = player.getScore() + bonus;

                    player.addScore(1);

                    cout << "Current Score: " << total << endl;

                    streak = 0;
                }

                break;
            }
            else
            {
                cout << "Wrong! Try again." << endl;

                streak = 0;
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