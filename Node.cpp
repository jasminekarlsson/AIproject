#include "Node.h"

Node::Node(string nam, bool comp, double cert)
{
    name = nam;
    completed = comp;
    certainty = cert;
}

Node::~Node()
{
    //dtor
}