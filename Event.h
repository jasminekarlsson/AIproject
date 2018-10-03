#ifndef EVENT_H
#define EVENT_H

#include <iostream>
using namespace std;

class Event
{
    public:
        Event(string time, string event, string val = "", dur = 0.0);
        virtual ~Event();
        displayEvent();

    protected:

    private:
    string timestamp;
    string eventtype;
    string value;
    double duration
};

#endif // EVENT_H
