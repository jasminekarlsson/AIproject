#include "Question.h"

Question::Question(string q, int ans, Node *nd)
{
    //ctor
	quest = q; 
	answer = ans;
	master = nd;
}

Question::~Question()
{
    //dtor
}
