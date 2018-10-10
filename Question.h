#ifndef QUESTION_H
#define QUESTION_H
using namespace std;

class Node;

class Question
{
    public:
		Question(string q, double ans);
        virtual ~Question();

        string getQuestion();
        double getAnswer();

    protected:

    private:
		string quest;
		double answer;
		

};

#endif // QUESTION_H
