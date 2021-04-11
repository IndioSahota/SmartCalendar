/**
 * .cpp file containing the constructor/destructor, as well as mutators/accessor methods
 * for the ConflictingEvent class. The ConflictingEvent class is inherited from NestedEvent and represents an event that can be comprised of multiple conflicting sub events.
 * e.g. A haircut and dinner fall within the same time
 * @author Aja Prasad Khanal (akhanal3)
 * @date 10-11-2020
 */

#include "ConflictingEvent.h"

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
ConflictingEvent::ConflictingEvent(std::string tName, std::string tDescription, std::string tLocation, EventTime tStartTime, EventTime tEndTime, float tStartMargin, float tEndMargin, int tPriorityLevel, bool tIsFullDay, ToDoList tTodo, std::vector<Event> tEvents):
                                   NestedEvent(tName, tDescription, tLocation, tStartTime, tEndTime, tStartMargin, tEndMargin, tPriorityLevel, tIsFullDay, tTodo, tEvents) {

}
/**
 * No-args constructor
 */
ConflictingEvent::ConflictingEvent():NestedEvent(){

}

/**
 * destructor
 */
ConflictingEvent::~ConflictingEvent() = default;

/**
 * updates the start and end time of the event as a whole based on the entire length of the conflict when account of all events
 * start time will be the minimum of all start times
 * end time will be maximum of all end times
 */
void ConflictingEvent::updateEvent() {
    float newStart = getStartTime().convertToMinutes();
    float newEnd = getEndTime().convertToMinutes();

    for (Event i : getEvents()) {
        if (newStart > i.getStartTime().convertToMinutes()){
            newStart = i.getStartTime().convertToMinutes();
        } else if (newEnd < i.getEndTime().convertToMinutes()) {
            newEnd = newEnd < i.getEndTime().convertToMinutes();
        }
    }

    setStartTime(EventTime(0, newStart));
    setEndTime(EventTime(0, newEnd));
}

/**
 * Iterates through the vector of events to get the first event with the highest priority level
 * @return an instance of Event that have the highest priority level
 */
Event ConflictingEvent::getHighPriority() {
    int highIndex = 0;
    int highPriority = 0;
    for (int i = 0; i < getEvents().size(); i++) {
        if (highPriority < getEvents()[i].getPriorityLevel()){
            highPriority = getEvents()[i].getPriorityLevel();
            highIndex = i;
        }
    }
    return getEvents()[highIndex];
}
