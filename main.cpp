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

	Question qE1("3 + X = 10. X = ?", 7);
	Question qE2("4 + X = 10. X = ?", 6);		//6
	Question qE3 ("5 + X = 10. X = ?", 5);		//5
	Node E1("E1", &D1, &qE1);
	Node E2("E2", &D1, &qE2);
	Node E3("E3", &D1, &qE3);

	Question qE4("23 + 15 = ?", 38);				//38
	Question qE5("58 + 37 = ?", 95);				//95
	Question qE6("12 + 90 = ?", 102);				//102
	Node E4("E4", &D2, &qE4);
	Node E5("E5", &D2, &qE5);
	Node E6("E6", &D2, &qE6);

	Question qE7("10 - 5 = ?", 5);				//5
	Question qE8("10 - 2 = ?", 8);				//8
	Question qE9("10 - 8 = ?", 2);				//2
	Node E7("E7", &D3, &qE7);
	Node E8("E8", &D3, &qE8);
	Node E9("E9", &D3, &qE9);

	Question qE10("73 - 51 = ?", 22);			//22
	Question qE11("62 - 37 = ?", 25);			//25
	Question qE12("98 - 17 = ?", 81);			//81
	Node E10("E10", &D4, &qE10);
	Node E11("E11", &D4, &qE11);
	Node E12("E12", &D4, &qE12);

	Question qE13("2 * 2 = ?", 4);				//4
	Question qE14("2 * 8 = ?", 16);				//16
	Question qE15("2 * 7 = ?", 14);				//14
	Node E13("E13", &D5, &qE13);
	Node E14("E14", &D5, &qE14);
	Node E15("E15", &D5, &qE15);

	Question qE16("3 * 5 = ?", 15);				//15
	Question qE17("8 * 8 = ?", 64);				//64
	Question qE18("6 * 5 = ?", 30);				//30
	Node E16("E16", &D6, &qE16);
	Node E17("E17", &D6, &qE17);
	Node E18("E18", &D6, &qE18);

	Question qE19("4 * 10 = ?", 40);				//40
	Question qE20("7 * 10 = ?", 70);				//70
	Question qE21("10 * 10 = ?", 100);			//100
	Node E19("E19", &D7, &qE19);
	Node E20("E20", &D7, &qE20);
	Node E21("E21", &D7, &qE21);

	Question qE22("4 * 4 = ?", 16);				//16
	Question qE23("3 * 6 = ?", 18);				//18
	Question qE24("7 * 8 = ?", 56);				//56
	Node E22("E22", &D8, &qE22);
	Node E23("E23", &D8, &qE23);
	Node E24("E24", &D8, &qE24);

	Question qE25("10 / 5 = ?", 2);				//2
	Question qE26("8 / 2 = ?", 4);				//4
	Question qE27("9 / 3 = ?", 3);				//3
	Node E25("E25", &D9, &qE25);
	Node E26("E26", &D9, &qE26);
	Node E27("E27", &D9, &qE27);

	Question qE28("80 / 40 = ?", 2);			//2
	Question qE29("81 / 9 = ?", 9);				//9
	Question qE30("49 / 7 = ?", 7);				//7
	Node E28("E28", &D10, &qE28);
	Node E29("E29", &D10, &qE29);
	Node E30("E30", &D10, &qE30);

	//Add dependencies
	Dependency dptb2b1(&B1, 0.4);		//B2 dependent on B
	B2.setDependency(dptb2b1);

	Dependency dptd2d1(&D1, 0.7);		//D2 dependent on D1
	D2.setDependency(dptd2d1);

	Dependency dptd4d2(&D2, 0.5);		//D4 dependent on D2
	D4.setDependency(dptd4d2);

	Dependency dptc4c3(&C3, 0.3);
	C4.setDependency(dptc4c3);

	Dependency dptd8d5(&D5, 0.9);
	D8.setDependency(dptd8d5);
	Dependency dptd8d6(&D6, 0.8);
	D8.setDependency(dptd8d6);
	Dependency dptd8d7(&D7, 0.4);
	D8.setDependency(dptd8d7);

	Dependency dptd10d9(&D9, 0.4);
	D9.setDependency(dptd10d9);

	Dependency dptd6d2(&D2, 0.7);
	D6.setDependency(dptd6d2);

	E1.changeCertainty(1);
	E2.changeCertainty(1);
	/*E3.changeCertainty(1);
	E4.changeCertainty(0);
	E5.changeCertainty(0);
	E6.changeCertainty(0);
	E7.changeCertainty(0);
	E8.changeCertainty(0);
	E9.changeCertainty(0);
	E10.changeCertainty(0);
	E11.changeCertainty(0); */

	//loop through tree, suggest reading
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
	Node *learn = nullptr;

	while(choice != 4){

		cout << endl << endl << "-----------Choose what you want to do:-----------" << endl << "1. Check what to read next"
			<< endl << "2. Answer next question" << endl << "3. Choose what to learn" << endl << "4. End program" << endl;
		cin >> choice;

		read = A1.readNext();

		string toLearn = "";	//needs to be here, otherwise crashes
		vector<Node> toRead;
		//check if coice is an int!
		/*if(choice != int(choice))
		{

			cout << "Not a valid input, try again." << endl;

		else
		{*/

			switch (choice)
			{
				case 1:
					int answer;
					cout << "You should read ";
					read->printName();
					cout << " next." << endl;
					break;
				case 2:
					read->printQuestion();
					cout << endl;
					cin >> answer;

					if (answer == read->getAnswer()) //Ändra till rätt svar här
					{
						cout << "Your answer is correct" << endl;
						read->changeCertainty(1);
					}
					else
					{
						cout << "Your answer is incorrect." << endl;
					}
					break;
				case 3: 
					learn = &A1;
					cout << "Enter which node you would like to learn. ";
					cin >> toLearn;
					//loop through the tree, and find if there is matching string.

					//if matching string 	--> check if exists
					learn = learn->findLearnRequest(toLearn);
					//find if the string matches something
					if(learn == nullptr)	//if not, say that it doesn't exist
					{
						cout << "There is no such thing." << endl;
					}
					//print node name
					else
					{
						toRead = learn->checkDependency();
						cout << "you should read in order:";
						for (int i = 0; i < toRead.size(); i++)
						{
							cout << " ";
							toRead[i].printName();
						}
					}
					

					//						--> check dependencies
					//						--> start suggesting the highest unlearned dependency
					//						--> remember what to read in next somehow?!
					//						--> how do we do this without messing up the pointers?
					//						--> could we have a read-next-vector of some kind?
					
					break;
				default:
					break;

			}
		//}

		//Error when we know the whole tree (it breakes before we can exit the program)

	}


    return 0;
}
