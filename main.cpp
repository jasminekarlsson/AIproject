#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    ifstream file ( "LIU1_2018-02-19.log_sc.csv" );		//timestamp, event, value, duration of event
	string line;

	if (file.is_open())
  	{
	    while ( getline (file,line,',') )	//read one line, separate when there is a ','
	    {
	    	//save into the class Event (skip first line?)
	      	cout << line << '\n';
	    }
	    file.close();
	}

    return 0;
}
