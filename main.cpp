#include <iostream>
#include <fstream>
#include <vector>
#include "Node.cpp"
//#include "Question.cpp"
using namespace std;

int main()
{

	//create a class with a string (name), a bool (completed) and a double (certainty), parent, sibling, child


	Node A1("A1", nullptr, nullptr);

	Node B1("B1", &A1, nullptr);
	Node B2("B2", &A1, nullptr);

	Node C1("C1", &B1, nullptr);
	Node C2("C2", &B1, nullptr);

	Node C3("C3", &B2, nullptr);
	Node C4("C4", &B2, nullptr);

	Node D1("D1", &C1, nullptr);
	Node D2("D2", &C1, nullptr);

	Node D3("D3", &C2, nullptr);
	Node D4("D4", &C2, nullptr);

	Node D5("D5", &C3, nullptr);
	Node D6("D6", &C3, nullptr);

	Node D7("D7", &C3, nullptr);
	Node D8("D8", &C3, nullptr);

	Node D9("D9", &C4, nullptr);
	Node D10("D10", &C4, nullptr);

	Node E1("E1", &D1, nullptr);
	Node E2("E2", &D1, nullptr);
	Node E3("E3", &D1, nullptr);

	Node E4("E4", &D2, nullptr);
	Node E5("E5", &D2, nullptr);
	Node E6("E6", &D2, nullptr);

	Node E7("E7", &D3, nullptr);
	Node E8("E8", &D3, nullptr);
	Node E9("E9", &D3, nullptr);

	Node E10("E10", &D4, nullptr);
	Node E11("E11", &D4, nullptr);
	Node E12("E12", &D4, nullptr);

	Node E13("E13", &D5, nullptr);
	Node E14("E14", &D5, nullptr);
	Node E15("E15", &D5, nullptr);

	Node E16("E16", &D6, nullptr);
	Node E17("E17", &D6, nullptr);
	Node E18("E18", &D6, nullptr);

	Node E19("E19", &D7, nullptr);
	Node E20("E20", &D7, nullptr);
	Node E21("E21", &D7, nullptr);

	Node E22("E22", &D8, nullptr);
	Node E23("E23", &D8, nullptr);
	Node E24("E24", &D8, nullptr);

	Node E25("E25", &D9, nullptr);
	Node E26("E26", &D9, nullptr);
	Node E27("E27", &D9, nullptr);

	Node E28("E28", &D10, nullptr);
	Node E29("E29", &D10, nullptr);
	Node E30("E30", &D10, nullptr);

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

		cout << endl << endl << "-----------Choose what you want to do:-----------" << endl << "1. Check what to read next"
			<< endl << "2. Answer next question" << endl << "3. End program" << endl;
		cin >> choice;

		read = A1.readNext();

		switch (choice)
		{
		case 1:
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
				cout << "Your answer is correct" << endl;
				//changeCertainty(1) på noden  
			}
			else
			{
				cout << "Your answer is incorrect." << endl;
			}
			break;

		default:
			break;
		}

	}


    return 0;
}
