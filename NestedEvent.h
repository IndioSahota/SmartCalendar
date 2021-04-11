
/**
 * .h file containing definitions for the destructor/constructor, as well as the mutator/accessor and instance methods
 * methods for the class NestedEvent.cpp
 * @author Aja Prasad Khanal (akhanal3)
 * @date 10-11-2020
 */

#ifndef SMART_CALENDAR_NESTEDEVENT_H
#define SMART_CALENDAR_NESTEDEVENT_H

#include "Event.h"
#include <vector>

class NestedEvent: public Event {
private:
    std::vector<Event> events;
public:
    NestedEvent(std::string tName, std::string tDescription, std::string tLocation, EventTime tStartTime, EventTime tEndTime, float tStartMargin, float tEndMargin, int tPriorityLevel, bool tIsFullDay, ToDoList tTodo, std::vector<Event> t_events);
    NestedEvent();
    ~NestedEvent() override;

    std::vector<Event> getEvents();
    void setEvents(std::vector<Event> t_events);
    bool canBeNested(Event event);
};


#endif //SMART_CALENDAR_NESTEDEVENT_H
