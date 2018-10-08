#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

	
class Node
{
    public:
    	
        Node(string nam = "", bool comp = false, double cert = 0, Node *par = nullptr);
        virtual ~Node();

        void setChild(Node *chi);
        void setSibling(Node *sib);
        Node *getParent();
        Node *getSibling();
        Node *getChild();
        
        void printName();

    protected:

    private:
    string name;
    bool completed;
    double certainty;
    Node *parent;
    Node *sibling;
    Node *child;
};

#endif // NODE_H