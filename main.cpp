#include <iostream>
#include "Event.h"
using namespace std;

int main(){

    cout << "Hello world! How are you?" << endl;
    Event party("09:41:19.635","En fest","","50.0");
    party.displayEvent();

    return 0;
}
