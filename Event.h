/**
 * .h file containing definitions for the destructor/constructor, as well as the mutator/accessor and instance methods
 * methods for the class Event.cpp
 * @author Aja Prasad Khanal (akhanal3)
 * @date 10-11-2020
 */

#ifndef SMART_CALENDAR_EVENT_H
#define SMART_CALENDAR_EVENT_H

#include <string>
#include "EventTime.h"
#include "ToDoList.h"

class Event {
private:
    //instance variables
    std::string name;
    std::string description;
    std::string location;
    EventTime startTime;
    EventTime endTime;
    float startMargin;
    float endMargin;
    //using range from 0-10 where 0 is the lowest priority
    int priorityLevel;
    bool isFullDay;
    ToDoList todo;

public:
    Event(std::string t_name, std::string t_description, std::string t_location, EventTime t_startTime, EventTime t_endTime, float t_startMargin, float t_endMargin, int t_priorityLevel, bool t_isFullDay, ToDoList t_todo);
    Event();
    virtual ~Event();

    std::string getName();
    void setName(std::string t_name);
    std::string getDescription();
    void setDescription(std::string t_description);
    std::string getLocation();
    void setLocation(std::string t_location);
    EventTime getStartTime();
    void setStartTime(EventTime t_startTime);
    EventTime getEndTime();
    void setEndTime(EventTime t_endTime);
    float getStartMargin();
    void setStartMargin(float t_startMargin);
    float getEndMargin();
    void setEndMargin(float t_endMargin);
    int getPriorityLevel();
    void setPriorityLevel(int t_priorityLevel);
    bool isFullDay1();
    void setIsFullDay(bool t_isFullDay);
    bool isIntersecting (Event event);
    ToDoList getTodo();
    void setTodo(ToDoList t_todo);
};

#endif //SMART_CALENDAR_EVENT_H
