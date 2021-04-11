/**
 * .h file containing definitions for the destructor/constructor, as well as the mutator/accessor
 * methods for the class <class>Date</class>
 * @author arahma86
 * @date 10-11-2020
 */

#include <string>
#include <vector>
#include "Event.h"
#include "ToDoList.h"

#ifndef SMARTCALENDAR_DATE_H
#define SMARTCALENDAR_DATE_H

class Date {
private:
    std::string dayType, month, description;
    int dayNumber, year;
    bool holidayFlag;
    std::vector<Event> events;
    ToDoList toDoList;
public:
    Date(std::string, int, std::string, int, std::string, bool, std::vector<Event>);
    Date();
    ~Date();
    void setDayType(std::string);
    void setDayNumber(int);
    void setMonth(std::string);
    void setYear(int);
    void setDescription(std::string);
    void setHoliday(bool);
    void setEvents(std::vector<Event>);
    void setToDoList(ToDoList);
    std::string getDayType();
    int getDayNumber();
    std::string getMonth();
    int getYear();
    std::string getDescription();
    bool isHoliday();
    bool isMatchingDay(Date);
    std::vector<Event> getEvents();
    ToDoList getToDoList();
    void addEvent(const Event&);
    void deleteEvent(const Event&);
    void addEventList(std::vector<Event>);
    std::vector<Event> combinedSchedule(Date);
    std::vector<Event> intersect(Date);
};

#endif //SMARTCALENDAR_DATE_H
