#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <iomanip> 
#include "Question.cpp"
using namespace std;

	
class Node
{
    public:
    	
        Node(string nam = "", Node *par = nullptr, Question *quest = nullptr);
        virtual ~Node();

        void setChild(Node *chi);
        void setSibling(Node *sib);
        Node *getParent();
        Node *getSibling();
        Node *getChild();
        bool getCompleted();
		void checkCompleted();
		void calculateCertainty();
		void changeCertainty(double cer);
		

        Node *readNext();
        
        void printName();

    protected:

    private:
    string name;
    bool completed;
    double certainty;
    Node *parent;
    Node *sibling;
    Node *child;
    Question *question;
};

#endif // NODE_H