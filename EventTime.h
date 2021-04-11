
/**
 * .h file containing definitions for the destructor/constructor, as well as the mutator/accessor and instance methods
 * methods for the class EventTime.cpp
 * @author Aja Prasad Khanal (akhanal3)
 * @date 10-11-2020
 */

#ifndef SMART_CALENDAR_EVENTTIME_H
#define SMART_CALENDAR_EVENTTIME_H

class EventTime {
private:

//instance variables
    float hours;
    float minutes;
public:
    //Constructor and Destructor
    EventTime(float t_hours, float t_minutes);
    EventTime();
    ~EventTime();

    //Accessor methods
    float getHours();
    float getMinutes();

    //Mutator methods
    void setHours(float t_hours);
    void setMinutes(float t_minutes);

    //Instance methods
    float convertToHours();
    float convertToMinutes();
};

#endif //SMART_CALENDAR_EVENTTIME_H
