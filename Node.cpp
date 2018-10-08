#include "Node.h"

Node::Node(string nam, bool comp, double cert, Node *par)
{
    name = nam;
    completed = comp;
    certainty = cert;
    parent = par;
    sibling = nullptr;
    child = nullptr;

    if( parent != nullptr && parent->child != nullptr)
    {
    	Node *tempSib = parent->child;
    	while (tempSib->sibling != nullptr)
    	{
			tempSib = tempSib->sibling;
    	}
    	
    	tempSib->setSibling(this); 
    }

    if (parent != nullptr && parent->child == nullptr)
    {
    	parent->setChild(this);
    }


}

Node::~Node()
{
    //dtor
}

void Node::setChild(Node *chi)
{
	this->child = chi;
}

void Node::setSibling(Node *sib)
{
	this->sibling = sib;
}

Node *Node::getParent()
{
	return parent;
}

Node *Node::getSibling()
{
	return sibling;
}

Node *Node::getChild()
{
	return child;
}

void Node::printName()
{
	cout << name;
}
