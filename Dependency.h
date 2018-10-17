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
		bool operator<(const Dependency &first, const Dependency &second);

    protected:

    private:
		Node *dependent;
		double weight;		//how well the student knows the node

};

#endif // DEPENDENCY_H
