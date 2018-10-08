#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

	
class Node
{
    public:
        Node(string nam = "", bool comp = false, double cert = 0);
        virtual ~Node();
        

    protected:

    private:
    string name;
    bool completed;
    double certainty;
};

#endif // NODE_H