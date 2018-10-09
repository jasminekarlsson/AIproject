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
}

void Node::calculateCertainty()
{
	if (child == nullptr)
	{
		cout << "No children to calculate Curtainity from" << endl;
		return;
	}

	Node *ndChild = child;
	int nrChild = 0;
	double sumCert = 0;

	while (ndChild != nullptr)
	{
		sumCert += ndChild->certainty;
		nrChild++;
		ndChild = ndChild->sibling;
	}

	certainty = sumCert / nrChild;
	checkCompleted();

	cout << "Node " << name << " has now certainty " << setprecision(2) << certainty*100 << " %" << endl;

}

void Node::changeCertainty(double cert)
{
	if (child != nullptr)
	{
		cout << "This node is not a base and cant be changed" << endl;
		return;
	}
	else if (cert < 0 || cert > 1)
	{
		cout << "Invalid certanity, choose a value between 0 and 1" << endl;
		return;
	}

	certainty = cert;
	checkCompleted();

	cout << "Node " << name << " has now certainty " << setprecision(2) << certainty * 100 << " %" << endl;


	Node *par = parent;

	while (par != nullptr)
	{
		par->calculateCertainty();
		par = par->parent;
	}
	

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


