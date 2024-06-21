#ifndef TIME_H
#define TIME_H
#include"List.h"
class Event;
class Time
{
public:
	long long time;
	List<Event> *eventList_ptr;
};

#endif // !TIME_H
