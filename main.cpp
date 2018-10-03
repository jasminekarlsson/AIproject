#include <iostream>
#include <fstream>
#include <vector>
#include "Event.cpp"
using namespace std;

int main()
{

    cout << "Hello world! How are you?" << endl;
    Event party("09:41:19.635","En fest","",50.0);
    //party.displayEvent();

    ifstream file ( "LIU1_2018-02-19.log_sc.csv" );		//timestamp, event, value, duration of event
	string line;
	vector<Event> eventVector;

	if (file.is_open())
  	{
	    while ( getline (file,line,',') )	//read one line, separate when there is a ','
	    {
	    	Event lineSeg;
	    	//save into the class Event (skip first line?)

	      	//cout << line << '\n';
	    }
	    file.close();
	}

    return 0;
}
