/**
 * .cpp file containing the constructor/destructor, as well as mutators/accessor methods
 * for the EventTime class. The EventTime class represents an instance of a 24 hour time, in the hours:minutes (hh:mm)
 * @author Aja Prasad Khanal (akhanal3)
 * @date 10-11-2020
 */

#include "EventTime.h"

/**
 * Direct constructor
 * @param t_hours - hours attribute of object
 * @param t_minutes  - minutes attribute of object
 */
EventTime::EventTime(float t_hours, float t_minutes) {
    hours = t_hours;
    minutes = t_minutes;
}

/**
 * No-args constructor
 * Sets all attribute values to 0
 */
EventTime::EventTime() {
    hours = 0;
    minutes = 0;
}

/**
 * Destructor
 */
EventTime::~EventTime() = default;

/**
 * Accessor for hours
 * @return float representing the hours
 */
float EventTime::getHours() {
    return hours;
}

/**
 * Accessor for minutes
 * @return float representing minutes
 */
float EventTime::getMinutes() {
    return minutes;
}

/**
 * Mutator for hours
 * @param t_hours - the updated hours
 */
void EventTime::setHours(float t_hours) {
    hours = t_hours;
}

/**
 * Mutator for minutes
 * @param t_minutes - the updated minutes
 */
void EventTime::setMinutes(float t_minutes) {
    minutes = t_minutes;
}

/**
 * Represents the current instance of EventTime as only hours in the (hh:00) format
 * @return
 */
float EventTime::convertToHours() {
    return hours + minutes/60;
}

/**
 * Represents the current instance of EventTime as only minutes in the (00:mm) format
 * @return
 */
float EventTime::convertToMinutes() {
    return minutes + hours*60;
}


