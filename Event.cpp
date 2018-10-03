#include "Event.h"

Event::Event(string time, string event, string val, double dur)
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

void Event::displayEvent()
{

    cout << "Time: " << timestamp << "\t Event type: " << eventtype << " \t Duration: " << duration << endl;

}
