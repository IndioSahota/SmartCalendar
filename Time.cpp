
#include "Time.h"

/**
 * Direct constructor
 * @param t_hours - hours attribute of object
 * @param t_minutes  - minutes attribute of object
 */
Time::Time(float t_hours, float t_minutes) {
    hours = t_hours;
    minutes = t_minutes;
}

/**
 * No-args constructor
 * Sets all attribute values to 0
 */
Time::Time() {
    hours = 0;
    minutes = 0;
}

Time::~Time() = default;

float Time::getHours() {
    return hours;
}

float Time::getMinutes() {
    return minutes;
}

void Time::setHours(float t_hours) {
    hours = t_hours;
}

void Time::setMinutes(float t_minutes) {
    minutes = t_minutes;
}

float Time::convertToHours() {
    return hours + minutes/60;
}

float Time::convertToMinutes() {
    return minutes + hours*60;
}


