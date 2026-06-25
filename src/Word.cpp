#include "Word.h"
Word::Word()
{
    answer = "";
    hiddenWord = "";
}
void Word::setAnswer(string answer)
{
    this->answer = answer;
    hiddenWord = answer;
}
Word::Word(string answer)
{
    this->answer = answer;
    this->hiddenWord = answer; 
}
void Word::hideCharacters(int count)
{
    hiddenWord = answer;

    for (int i = 0; i < answer.length() && count > 0; i++)
    {
        hiddenWord[i] = '_';
        count--;
    }
}
bool Word::checkAnswer(string userAnswer)
{
    return userAnswer == answer;
}
string Word::getAnswer() const
{
    return answer;
}

string Word::getHiddenWord() const
{
    return hiddenWord;
};