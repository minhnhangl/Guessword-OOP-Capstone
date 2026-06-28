#include "Word.h"
Word::Word() // khởi tạo một word rỗng
{
    answer = "";
    hiddenWord = "";
}
Word::Word(string answer)// Khởi tạo và gán luôn.
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