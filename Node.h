#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <iomanip> 
#include <algorithm>
#include "Question.cpp"
#include "Dependency.cpp"
using namespace std;

	
class Node
{
    public:
    	
        Node(string nam = "", Node *par = nullptr, Question *quest = nullptr);
        virtual ~Node();

        void setChild(Node *chi);
        void setSibling(Node *sib);
        void setDependency(Dependency depnd);
        Node *getParent();
        Node *getSibling();
        Node *getChild();
        bool getCompleted();
		void checkCompleted();
		void calculateCertainty();
		void changeCertainty(double cer);
		
		vector<Node> checkDependency();
        Node *readNext();
        Node *findLearnRequest(string input);
        
        void printName();
        void printQuestion();
        double getAnswer();

    protected:

    private:
    string name;
    bool completed;
    double certainty;
    Node *parent;
    Node *sibling;
    Node *child;
    Question *question;
    vector<Dependency> dependens;      //one dependent contains pointer to node and a double
};

#endif // NODE_H