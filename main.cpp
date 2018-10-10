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

	Node C1("C1", false, 0.0, &B1);
	Node C2("C2", false, 0.0, &B1);

	Node C3("C3", false, 0.0, &B2);
	Node C4("C4", false, 0.0, &B2);

	Node D1("D1", false, 0.0, &C1);
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

	string qE1 = "3 + X = 10. X = ?";		//7
	string qE2 = "4 + X = 10. X = ?";		//6
	string qE3 = "5 + X = 10. X = ?";		//5

	string qE4 = "23 + 15 = ?";				//38
	string qE5 = "58 + 37 = ?";				//95
	string qE6 = "12 + 90 = ?";				//102

	string qE7 = "10 - 5 = ?";				//5
	string qE8 = "10 - 2 = ?";				//8
	string qE9 = "10 - 8 = ?";				//2

	string qE10 = "73 - 51 = ?";			//22
	string qE11 = "62 - 37 = ?";			//25
	string qE12 = "98 - 17 = ?";			//81
	
	string qE13 = "2 * 2 = ?";				//4
	string qE14 = "2 * 8 = ?";				//16
	string qE15 = "2 * 7 = ?";				//14

	string qE16 = "3 * 5 = ?";				//15
	string qE17 = "8 * 8 = ?";				//64
	string qE18 = "6 * 5 = ?";				//30

	string qE19 = "4 * 10 = ?";				//40
	string qE20 = "7 * 10 = ?";				//70
	string qE21 = "10 * 10 = ?";			//100

	string qE22 = "4 * 4 = ?";				//16
	string qE23 = "3 * 6 = ?";				//18
	string qE24 = "7 * 8 = ?";				//56

	string qE25 = "10 / 5 = ?";				//2
	string qE26 = "8 / 2 = ?";				//4
	string qE27 = "9 / 3 = ?";				//3

	string qE28 = "80 / 40 = ?";			//2
	string qE29 = "81 / 9 = ?";				//9
	string qE30 = "49 / 7 = ?";				//7


	/*E30.changeCertainty(1);
	C1.changeCertainty(1);
	E3.changeCertainty(15);
	E7.changeCertainty(0.6);
	E8.changeCertainty(1);
	E9.changeCertainty(1);
	cout << endl; */

	/* double answer;
	//Create a program that asks user questions
	cout << qE1 << endl;
	cin >> answer;

	if (answer == 7)
	{

		E1.changeCertainty(1);
		cout << "You answered correctly!" << endl;
	}
	 */


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

	

	int choice = 0;
	Node *read = nullptr;

	while(choice != 3){

		cout << "-----------Choose what you want to do:-----------" << endl << "1. Check what to read next"
			<< endl << "2. Answer next question" << endl << "3. End program" << endl;
		cin >> choice;

		 

		switch (choice)
		{
		case 1:
			read = A1.readNext();
			int answer;
			cout << "You should read ";
			read->printName();
			cout << " next." << endl;
			break;
		case 2:
			cout << "Skriv ut fråga här" << endl;
			cin >> answer;

			if (answer == 0) //Ändra till rätt svar här
			{
				//changeCertainty(1) på noden  
			}
			break;

		default:
			break;
		}

	}


    return 0;
}
