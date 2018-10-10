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
	child = chi;
}

void Node::setSibling(Node *sib)
{
	sibling = sib;
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

void Node::checkCompleted()
{
	if (certainty == 1)		
	{
		completed = true;
	}
	else
	{
		completed = false;
	}
}

void Node::calculateCertainty()
{
	if (child == nullptr)
	{
		cout << "No children to calculate Curtainity from" << endl;
		return;
	}

	Node *ndChild = child;
	int nrChild = 0;		//count number of children
	double sumCert = 0;

	while (ndChild != nullptr)	//visit children and its sibling until there is no more children
	{
		sumCert += ndChild->certainty;
		nrChild++;
		ndChild = ndChild->sibling;		//go to sibling
	}

	certainty = sumCert / nrChild;		//calculate certainty
	checkCompleted();					//check if node is completed

	cout << "Node " << name << " has now certainty " << setprecision(2) << certainty*100 << " %" << endl;

}

void Node::changeCertainty(double cert)
{
	if (child != nullptr)	//is not a leaf
	{
		cout << "This node is not a base and cant be changed" << endl;
		return;
	}
	else if (cert < 0 || cert > 1)	//wrong input
	{
		cout << "Invalid certanity, choose a value between 0 and 1" << endl;
		return;
	}

	certainty = cert;
	checkCompleted();

	cout << "Node " << name << " has now certainty " << setprecision(2) << fixed << certainty * 100 << " %" << endl;


	Node *par = parent;

	while (par != nullptr)
	{
		par->calculateCertainty();
		par = par->parent;
	}
	

}

Node *Node::readNext()
{

	//base case, there are no children
	if (!completed && child == nullptr)
	{
		cout << "Not completed, no children - I am going to recommend this" << endl;
		return this;
	}

	//false, go to child
	if(!completed && child != nullptr)
	{
		cout << "Not completed, goes to child" << endl;
		//finns barn?
		return child->readNext();
	}
	//not completed, there are no children --> recommend this
	else if(!completed)
	{
		cout << "Not completed, no children - I am going to recommend this" << endl;
		return this;
	} 
	//true, there are siblings
	else if (completed && sibling != nullptr)
	{
		cout << "Completed, goes to sibling" << endl;
		return sibling->readNext();
	}
	
	else if (sibling == nullptr && completed)
	{
		//true, there are no siblings --> the whole book is finished
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


