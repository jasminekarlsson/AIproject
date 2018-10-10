#include "Question.h"

Question::Question(string q, double ans)
{
    //ctor
	quest = q; 
	answer = ans;
}

Question::~Question()
{
    //dtor
}

string Question::getQuestion()
{
	return quest;
}

double Question::getAnswer()
{
	return answer;
}