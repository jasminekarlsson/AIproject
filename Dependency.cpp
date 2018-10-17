#include "Dependency.h"

Dependency::Dependency(Node *depnt, double wei)
{
    //ctor
	dependent = depnt; 
	weight = wei;
}

Dependency::~Dependency()
{
    //dtor
}

Node *Dependency::getDependent()
{
	return dependent;
}

double Dependency::getWeight()
{
	return weight;
}

bool Dependency::operator<(const Dependency &first, const Dependency &second)
{
	return (first.getWeight() > second.getWeight());
}