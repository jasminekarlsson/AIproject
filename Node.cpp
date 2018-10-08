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

bool Node::getCompleted()
{
	return completed;
}

Node *Node::readNext()
{
	//börja på roten

	//base case, det finns inga barn
	if (!completed && child == nullptr)
	{
		cout << "Not completed, no children - I am going to recommend this" << endl;
		return this;
	}

	//false, gå till barn
	if(!completed && child != nullptr)
	{
		cout << "Not completed, goes to child" << endl;
		//finns barn?
		return child->readNext();
	}
	//inte completed, det finns inga barn --> den här ska rekommenderas
	else if(!completed)
	{
		cout << "Not completed, no children - I am going to recommend this" << endl;
		return this;
	} 
	//true, det finns syskon
	else if (completed && sibling != nullptr)
	{
		cout << "Completed, goes to sibling" << endl;
		return sibling->readNext();
	}
	
	else if (sibling == nullptr && completed)
	{
		//true, det finns inga syskon --> hela boken är utläst
		cout << "Completed, no sibligs, you know the whole book" << endl;
		return nullptr;
	} 
	
	cout << "Why are you even here?" << endl;
	return nullptr;

}


void Node::printName()
{
	cout << name;
}
