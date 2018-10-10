#ifndef QUESTION_H
#define QUESTION_H
using namespace std;

class Node;

class Question
{
    public:
		Question(string q, int ans, Node *nd);
        virtual ~Question();

    protected:

    private:
		string quest;
		int answer;
		Node *master;

};

#endif // QUESTION_H
