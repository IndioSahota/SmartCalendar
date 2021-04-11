
#ifndef SMART_CALENDAR_TIME_H
#define SMART_CALENDAR_TIME_H

class Time {
private:

//instance variables
    float hours;
    float minutes;
public:
    //Constructor and Destructor
    Time(float t_hours, float t_minutes);
    Time();
    ~Time();

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

#endif //SMART_CALENDAR_TIME_H
