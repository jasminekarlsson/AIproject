#ifndef EVENT_H
#define EVENT_H

#include <iostream>
using namespace std;

class Event
{
    public:
        Event(string time = "", string event = "", string val = "", double dur = 0);
        virtual ~Event();
        void setTimestamp(string time);
        void setEventtype(string event);
        void setValue(string val);
        void setDuration(double dur);
        void displayEvent();

    protected:

    private:
    string timestamp;
    string eventtype;
    string value;
    double duration;
};

#endif // EVENT_H
