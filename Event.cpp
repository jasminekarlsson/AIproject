#include "Event.h"

Event::Event(string time, string event, string val = "", dur = 0.0)
{
    timestamp = time;
    eventtype = event;
    value = val;
    duration = dur;
}

Event::~Event()
{
    //dtor
}

displayEvent(){

    cout << "Time: " << time << "\t Event type: " << event << " \t Duration: " << dur << endl;

}
