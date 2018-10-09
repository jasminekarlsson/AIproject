#include <iostream>
#include <fstream>
#include <vector>
#include "Node.cpp"
using namespace std;

int main()
{

	//create a class with a string (name), a bool (completed) and a double (certainty), parent, sibling, child


	Node A1("A1", false, 0.0, nullptr);

	Node B1("B1", false, 0.0, &A1);
	Node B2("B2", false, 0.0, &A1);

	Node C1("C1", true, 0.0, &B1);
	Node C2("C2", false, 0.0, &B1);

	Node C3("C3", false, 0.0, &B2);
	Node C4("C4", false, 0.0, &B2);

	Node D1("D1", true, 0.0, &C1);
	Node D2("D2", false, 0.0, &C1);

	Node D3("D3", false, 0.0, &C2);
	Node D4("D4", false, 0.0, &C2);

	Node D5("D5", false, 0.0, &C3);
	Node D6("D6", false, 0.0, &C3);

	Node D7("D7", false, 0.0, &C3);
	Node D8("D8", false, 0.0, &C3);

	Node D9("D9", false, 0.0, &C4);
	Node D10("D10", false, 0.0, &C4);

	Node E1("E1", false, 0.0, &D1);
	Node E2("E2", false, 0.0, &D1);
	Node E3("E3", false, 0.0, &D1);

	Node E4("E4", false, 0.0, &D2);
	Node E5("E5", false, 0.0, &D2);
	Node E6("E6", false, 0.0, &D2);

	Node E7("E7", false, 0.0, &D3);
	Node E8("E8", false, 0.0, &D3);
	Node E9("E9", false, 0.0, &D3);

	Node E10("E10", false, 0.0, &D4);
	Node E11("E11", false, 0.0, &D4);
	Node E12("E12", false, 0.0, &D4);

	Node E13("E13", false, 0.0, &D5);
	Node E14("E14", false, 0.0, &D5);
	Node E15("E15", false, 0.0, &D5);

	Node E16("E16", false, 0.0, &D6);
	Node E17("E17", false, 0.0, &D6);
	Node E18("E18", false, 0.0, &D6);

	Node E19("E19", false, 0.0, &D7);
	Node E20("E20", false, 0.0, &D7);
	Node E21("E21", false, 0.0, &D7);

	Node E22("E22", false, 0.0, &D8);
	Node E23("E23", false, 0.0, &D8);
	Node E24("E24", false, 0.0, &D8);

	Node E25("E25", false, 0.0, &D9);
	Node E26("E26", false, 0.0, &D9);
	Node E27("E27", false, 0.0, &D9);

	Node E28("E28", false, 0.0, &D10);
	Node E29("E29", false, 0.0, &D10);
	Node E30("E30", false, 0.0, &D10);

	//loopa igenom trädet, föreslå läsning
	Node *whatToRead = A1.readNext();

	if(!whatToRead)
	{
		cout << "You know everything!" << endl;
	}
	else
	{
		whatToRead->printName();
		cout << endl;
	}

	E30.changeCertainty(1);
	C1.changeCertainty(1);
	E3.changeCertainty(15);
	E7.changeCertainty(0.6);
	E8.changeCertainty(1);
	E9.changeCertainty(1);
	cout << endl;

    return 0;
}
