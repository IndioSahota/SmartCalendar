
/**
 * .h file containing definitions for the destructor/constructor, as well as the mutator/accessor and instance methods
 * methods for the class ConflictingEvent.cpp
 * @author Aja Prasad Khanal (akhanal3)
 * @date 10-11-2020
 */

#ifndef SMART_CALENDAR_CONFLICTINGEVENT_H
#define SMART_CALENDAR_CONFLICTINGEVENT_H

#include "NestedEvent.h"
#include <vector>

class ConflictingEvent: public NestedEvent{
public:
    ConflictingEvent(std::string tName, std::string tDescription, std::string tLocation, EventTime tStartTime, EventTime tEndTime, float tStartMargin, float tEndMargin, int tPriorityLevel, bool tIsFullDay, ToDoList tTodo, std::vector<Event> tEvents);
    ConflictingEvent();
    ~ConflictingEvent() override;
    Event getHighPriority();
    void updateEvent();
};


#endif //SMART_CALENDAR_CONFLICTINGEVENT_H
