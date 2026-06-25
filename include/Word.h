#pragma once
#include <string>
#include <set>
using namespace std;

class Word
{
private:
    string answer;
    string hiddenWord;
public:
    Word();
    void setAnswer(string answer);
    Word(string answer);
    void hideCharacters(int count);
    bool checkAnswer(string userAnswer);
    string getAnswer() const;
    string getHiddenWord() const;
};