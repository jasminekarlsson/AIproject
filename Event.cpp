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

void Event::setTimestamp(string time)
{
	timestamp = time;
}

void Event::setEventtype(string event)
{
	eventtype = event;
}

void Event::setValue(string val)
{
	value = val;
}

void Event::setDuration(double dur)
{
	duration = dur;
}

void Event::displayEvent()
{

    cout << "Time: " << timestamp << "\t Event type: " << eventtype << " \t Duration: " << duration << endl;

}
