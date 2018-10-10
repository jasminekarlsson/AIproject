#ifndef DEPENDENCY_H
#define DEPENDENCY_H
using namespace std;

class Node;

class Dependency
{
    public:
		Dependency(Node *depnt = nullptr, double wei = 0.0);
        virtual ~Dependency();

        Node *getDependent();
        double getWeight();

    protected:

    private:
		Node *dependent;
		double weight;

};

#endif // DEPENDENCY_H
