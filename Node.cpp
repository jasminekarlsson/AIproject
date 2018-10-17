#include "Node.h"

Node::Node(string nam, Node *par, Question *quest)
{
    name = nam;
    completed = false;
    certainty = 0.0;
    parent = par;
    sibling = nullptr;
    child = nullptr;
    question = quest;



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

void Node::setDependency(Dependency depnd)
{
	dependens.push_back(depnd);
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
		cout << "Error: This node is not a base and cant be changed" << endl;
		return;
	}
	else if (cert < 0 || cert > 1)	//wrong input
	{
		cout << "Error: Invalid certanity, choose a value between 0 and 1" << endl;
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

bool Node::compareWeight(Dependency &first, Dependency &second)
{
	return (first.getWeight() > second.getWeight());
}

vector<Node> Node::checkDependency(){

	vector<Node> readBefore;
	
	if(!dependens.empty())
	{
		sort(dependens.begin(), dependens.end());
		for(int i = 0; i < dependens.size(); i++)
		{
			if (!dependens[i].getDependent()->getCompleted())
			{
				//Om dependencin inte är klar, kolla dess dependencies
				Node temp = *(dependens[i].getDependent());
				readBefore.insert(readBefore.end(),temp);
				vector<Node> temp2 = temp.checkDependency();
				readBefore.insert(readBefore.begin(), temp2.begin(), temp2.end());
			}
		
		}

	}

	return readBefore;
}

Node *Node::readNext()
{

	//base case, there are no children
	if (!completed && child == nullptr)
	{
		return this;
	}

	//false, go to child
	if(!completed && child != nullptr)
	{
		//finns barn?
		return child->readNext();
	}
	//not completed, there are no children --> recommend this
	else if(!completed)
	{
		return this;
	} 
	//true, there are siblings
	else if (completed && sibling != nullptr)
	{
		return sibling->readNext();
	}
	else if (sibling == nullptr && completed)
	{
		//true, there are no siblings --> the whole book is finished
		return nullptr;
	} 
	
	cout << "Why are you even here?" << endl;
	return nullptr;
}

Node *Node::findLearnRequest(string input)
{
	//base case, there are no children (the name we are searching for)
	if (name.compare(input) == 0)
	{
		printName();
		cout << endl;
		return this;
	}

	//false, go to children 		(not the name we are searching for)
	if(name.compare(input) != 0 && child != nullptr)
	{
		cout << "down" << endl;
		//finns barn?
		Node *temp = child->findLearnRequest(input);
		if(temp != nullptr)
		{
			return temp;
		}
	}
	//there are siblings	(but still no name)
	if (name.compare(input) != 0 && sibling != nullptr)
	{
		cout << "right" << endl;
		Node *temp2 = sibling->findLearnRequest(input);
		if(temp2 != nullptr)
		{
			return temp2;
		}
	}
	/*else if (sibling == nullptr && name.compare(input) != 0)		//no siblings, but not found the name
	{
		//true, there are no siblings --> the whole book is finished
		cout << "No such node exists in this book, sadface" << endl;
		return nullptr;
	}  */
	
	cout << "Why are you even here?" << endl;
	return nullptr;
}


void Node::printName()
{
	cout << name;
}


void Node::printQuestion()
{
	cout << question->getQuestion();
}

double Node::getAnswer()
{
	return question->getAnswer();
}


