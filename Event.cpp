/**
 * .cpp file containing the constructor/destructor, as well as mutators/accessor methods
 * for the Event class. The Event class represents an event with a name, description, location, start time, end time, start margin, end margin, priority, an indicator if it's full day, and it's own to-do list
 * @author Aja Prasad Khanal (akhanal3)
 * @date 10-11-2020
 */

#include "Event.h"
#include <string>
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
 */
Event::Event(string t_name, string t_description, string t_location, EventTime t_startTime, EventTime t_endTime, float t_startMargin, float t_endMargin, int t_priorityLevel, bool t_isFullDay, ToDoList t_todo) {
    name = t_name;
    description = t_description;
    location = t_location;
    startTime = t_startTime;
    endTime = t_endTime;
    startMargin = t_startMargin;
    endMargin = t_endMargin;
    priorityLevel = t_priorityLevel;
    isFullDay = t_isFullDay;
    todo = t_todo;
}

/**
 * No-args constructor
 * All strings have a default value of empty string
 * All numeric variables will be 0
 * Vectors will be empty
 * Booleans are set to false
 */
Event::Event() {
    name = "";
    description = "";
    location = "";
    startTime = EventTime();
    endTime = EventTime();
    startMargin = 0;
    endMargin = 0;
    priorityLevel = 0;
    isFullDay = false;
    todo = ToDoList();
}

/**
 * Destructor for the Event.cpp class
 */
Event::~Event() = default;

/**
 * Accessor for name
 * @return name of event
 */
string Event::getName(){
    return name;
}

/**
 * Mutator for name
 * @param t_name - new name of event
 */
void Event::setName(std::string t_name) {
    Event::name = t_name;
}

/**
 * Accessor for event description
 * @return description of event
 */
string Event::getDescription() {
    return description;
}

/**
 * Mutator for event description
 * @param t_description - new description
 */
void Event::setDescription(std::string t_description) {
    Event::description = t_description;
}

/**
 * Accessor for event location
 * @return event location
 */
string Event::getLocation() {
    return location;
}

/**
 * Mutator for event location
 * @param t_location - new event location
 */
void Event::setLocation(std::string t_location) {
    Event::location = t_location;
}

/**
 * Accessor for event start time
 * @return start time of event
 */
EventTime Event::getStartTime() {
    return startTime;
}

/**
 * Mutator for event start time
 * @param t_startTime - new event start time
 */
void Event::setStartTime(EventTime t_startTime) {
    Event::startTime = t_startTime;
}

/**
 * Accessor for event end time
 * @return event end time
 */
EventTime Event::getEndTime() {
    return endTime;
}

/**
 * Mutator for event end time
 * @param t_endTime - new event end time
 */
void Event::setEndTime(EventTime t_endTime) {
    Event::endTime = t_endTime;
}

/**
 * Accessor for event start margin
 * @return event start margin
 */
float Event::getStartMargin() {
    return startMargin;
}

/**
 * Mutator for event start margin
 * @param t_startMargin - new event start margin
 */
void Event::setStartMargin(float t_startMargin) {
    Event::startMargin = t_startMargin;
}

/**
 * Accessor for event end margin
 * @return end margin of event
 */
float Event::getEndMargin() {
    return endMargin;
}

/**
 * Mutator for event end margin
 * @param t_endMargin -  new event end margin
 */
void Event::setEndMargin(float t_endMargin) {
    Event::endMargin = t_endMargin;
}

/**
 * Accessor for event priority level
 * @return the priority level for the event
 */
int Event::getPriorityLevel() {
    return priorityLevel;
}

/**
 * Mutator for event pirority level
 * @param t_priorityLevel
 */
void Event::setPriorityLevel(int t_priorityLevel) {
   priorityLevel = t_priorityLevel;
}

/**
 * Accessor for boolean indicating whether an event is full day
 * @return boolean isFullDay
 */
bool Event::isFullDay1() {
    return isFullDay;
}

/**
 * Mutator for boolean indicating whether an event is full day
 * @param t_isFullDay - new boolean
 */
void Event::setIsFullDay(bool t_isFullDay) {
    Event::isFullDay = t_isFullDay;
}

/**
 * Accessor for the vector storing the todo list items
 * @return An instance of a ToDoList object
 */
ToDoList Event::getTodo(){
    return todo;
}

/**
 * Mutator for the ToDoList
 * @param todo - new to do list
 */
void Event::setTodo(ToDoList todo) {
    Event::todo = todo;
}

/**
 * Checks to see whether two events intersect with each other
 * @param event - another instance of event
 * @return boolean indicating whether an event's times intersects with another event
 */
bool Event::isIntersecting(Event event) {
    float start1 = startTime.convertToMinutes() + startMargin;
    float end1 = endTime.convertToMinutes() + endMargin;
    float start2 = event.getStartTime().convertToMinutes() + event.getStartMargin();
    float end2 = event.getEndTime().convertToMinutes() +event.getEndMargin();

    return (start1 <= end2) && (start2 <= end1);
}




