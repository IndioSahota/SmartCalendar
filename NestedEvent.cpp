/**
 * .cpp file containing the constructor/destructor, as well as mutators/accessor methods
 * for the NestedEvent class. The NestedEvent class is inherited from Event and represents an event that can be comprised of multiple sub events.
 * e.g. A wedding can have a reception, ceremony, dinner, after party, etc.
 * @author Aja Prasad Khanal (akhanal3)
 * @date 10-11-2020
 */

#include "NestedEvent.h"
#include <vector>
using namespace std;

/**
 * Direct constructor
 * @param t_name - Event name
 * @param t_description - Event description
 * @param t_location - Location of event
 * @param t_startTime - Stored as an EventTime object, represents the starting time of the event
 * @param t_endTime - Stored as an EventTime object, represents the ending time of the event
 * @param t_startMargin - this float stores the margin or error (in minutes) of an event starting +/- x minutes
 * @param t_endMargin - this float stores the margin or error (in minutes) of an event ending +/- x minutes
 * @param t_priorityLevel - an integer from 1 to 10 representing the priority of an event (where 10 is the highest)
 * @param t_isFullDay - boolean indicating if the event occupies a full day
 * @param t_todo -  a specific todo list for each event. For example, a shopping event can have a grocery list with it
 * @param t_events - a vector storing all the nested events
 */
NestedEvent::NestedEvent(string tName, string tDescription, string tLocation, EventTime tStartTime, EventTime tEndTime, float tStartMargin, float tEndMargin, int tPriorityLevel, bool tIsFullDay, ToDoList tTodo, std::vector<Event> t_events)
        : Event(tName, tDescription, tLocation, tStartTime, tEndTime, tStartMargin, tEndMargin, tPriorityLevel, tIsFullDay, tTodo) {
    events = t_events;
}

/**
 * No-args constructor for nested event
 */
NestedEvent::NestedEvent():Event() {
    events = vector<Event>();
}

/**
 * Destructor
 */
NestedEvent::~NestedEvent() = default;

std::vector<Event> NestedEvent::getEvents() {
    return events;
}

/**
 * Mutator for the vector of nested events
 * @param t_events
 */
void NestedEvent::setEvents(std::vector<Event> t_events) {
    NestedEvent::events = t_events;
}

/**
 * Similar to the is intersecting but only checks the case where an event's start and end times fall in between another event's times
 * @param event - another instance of event
 * @return boolean indicating whether an event's times falls within with another event
 */
bool NestedEvent::canBeNested(Event event) {
    float start1 = getStartTime().convertToMinutes();
    float end1 = getEndTime().convertToMinutes();
    float start2 = event.getStartTime().convertToMinutes();
    float end2 = event.getEndTime().convertToMinutes();

    return (start1 >= start2 && end1 <= end2);
}

