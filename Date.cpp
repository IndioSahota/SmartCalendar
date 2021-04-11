/**
 * .cpp file containing the constructor/destructor, as well as mutators/accessor methods
 * for the <class>Date</class>. The Date class represents a calendar date, and the schedule attributed to this date.
 * @author arahma86
 * @date 10-11-2020
 */

#include <iostream>
#include <algorithm>
#include "Date.h"

/**
 * Constructor for class representing a calendar Date
 * @param dayType           <std::string>One of seven possible day types (i.e. Monday, Friday, etc.)</std::string>
 * @param dayNumber         <int>The day number (i.e. June "24", Feb. "29", etc.)</int>
 * @param month             <std::string>The month (i.e. October, January, etc.)</std::string>
 * @param year              <int>The year</int>
 * @param description       <std::string>Description of the user's day schedule</std::string>
 * @param holidayFlag       <bool>Flag to check if today is a special holiday</bool>
 * @param events            <std::vector<Event>>List of events on this day</std::vector<Event>>
 * @param toDoList          <ToDoList>A to-do list of events for this day</ToDoList>
 */
Date::Date(std::string dayType, int dayNumber, std::string month, int year, std::string description, bool holidayFlag, std::vector<Event> events) {
    this->dayType = std::move(dayType);
    this->dayNumber = dayNumber;
    this->month = std::move(month);
    this->year = year;
    this->description = std::move(description);
    this->holidayFlag = holidayFlag;
    this->events = std::move(events);
    for (Event e : this->events) {
        this->toDoList.addItem(ToDoItem(
                e.getName() + " - " + std::to_string(e.getStartTime().getHours()) + ":" + std::to_string(e.getStartTime().getMinutes()) +
                              " - " + std::to_string(e.getEndTime().getHours()) +   ":" + std::to_string(e.getEndTime().getMinutes()),
                e.getPriorityLevel(), false));
    }
}

/**
 * Default constructor without arguments
 */
Date::Date() {
    this->dayType = "";
    this->dayNumber = 0;
    this->month = "";
    this->year = 0;
    this->description = "";
    this->holidayFlag = false;
    this->events = std::vector<Event>();
    this->toDoList = ToDoList();
}

/**
 * Mutator for <std::string>dayType</std::string>
 * @param d_type    <std::string>The day type</std::string>
 */
void Date::setDayType(std::string d_type) {
    this->dayType = move(d_type);
}

/**
 * Mutator for <int>dayNumber</int>
 * @param d_num     <int>The day number</int>
 */
void Date::setDayNumber(int d_num) {
    this->dayNumber = d_num;
}

/**
 * Mutator for <std::string>month</std::string>
 * @param d_month   <std::string>The month</std::string>
 */
void Date::setMonth(std::string d_month) {
    this->month = std::move(d_month);
}

/**
 * Mutator for <int>year</int>
 * @param d_year    <int>The year</int>
 */
void Date::setYear(int d_year) {
    this->year = d_year;
}

/**
 * Mutator for <std::string>description</std::string>
 * @param d_description     <std::string>The description</std::string>
 */
void Date::setDescription(std::string d_description) {
    this->description = std::move(d_description);
}

/**
 * Mutator for <bool>holidayFlag</bool>
 * @param d_isHoliday       <bool>The holiday flag</bool>
 */
void Date::setHoliday(bool d_isHoliday) {
    this->holidayFlag = d_isHoliday;
}

/**
 * Mutator for <std::vector<Event>>events</std::vector<Event>>
 * @param d_events          <std::vector<Event>>The event list for the day</std::vector<Event>>
 */
void Date::setEvents(std::vector<Event> d_events) {
    this->events = std::move(d_events);
}

/**
 * Mutator for <ToDoList>list</ToDoList>
 * @param list              <ToDoList>The to-do list for this date.</ToDoList>
 */
void Date::setToDoList(ToDoList list) {
    this->toDoList = list;
}

/**
 * Accessor for <std::string>dayType</std::string>
 * @return          <std::string>The day type</std::string>
 */
std::string Date::getDayType() {
    return this->dayType;
}

/**
 * Accessor for <int>dayNumber</int>
 * @return          <int>The day type</int>
 */
int Date::getDayNumber() {
    return this->dayNumber;
}

/**
 * Accessor for <std::string>month</std::string>
 * @return          <std::string>The month</std::string>
 */
std::string Date::getMonth() {
    return this->month;
}

/**
 * Accessor for <int>year</int>
 * @return          <int>The year</int>
 */
int Date::getYear() {
    return this->year;
}

/**
 * Accessor for <std::string>description</std::string>
 * @return          <std::string>The description</std::string>
 */
std::string Date::getDescription() {
    return this->description;
}

/**
 * Accessor for <bool>holidayFlag</bool>
 * @return          <bool>The holiday flag</bool>
 */
bool Date::isHoliday() {
    return this->holidayFlag;
}

/**
 * Accessor for <std::vector<Event>>events</std::vector<Event>>
 * @return          <std::vector<Event>>List of events for this date.</std::vector<Event>>
 */
std::vector<Event> Date::getEvents() {
    return this->events;
}

/**
 * Accessor for <ToDoList>toDoList</ToDoList>
 * @return          <ToDoList>To-do list for this date</ToDoList>
 */
ToDoList Date::getToDoList() {
    return this->toDoList;
}

/**
 * Checks if the dates are matching (not based off of matching <std::vector<Event>>events</std::vector<Event>>)
 * @param d         <Date>A date</Date>
 * @return          <bool>True if dates are matching, false otherwise</bool>
 */
bool Date::isMatchingDay(Date d) {
    return (this->getDayType() == d.getDayType()) && (this->getDayNumber() == d.getDayNumber())
        && (this->getMonth() == d.getMonth()) && (this->getYear() == d.getYear());
}

/**
 * Method for adding an <Event>event</Event> to <std::vector<Event>>events</std::vector<Event>>
 * @param e         <Event>An event</Event>
 */
void Date::addEvent(const Event& e) {
    this->events.push_back(e);
}

/**
 * Method for removing an <Event>event</Event> from <std::vector<Event>>events</std::vector<Event>>
 * @param e
 */
void Date::deleteEvent(const Event& e) {
    this->events.erase(std::find(this->events.begin(), this->events.end(), e));
}

/**
 * Method for adding an event list to <std::vector<Event>>event</std::vector<Event>>
 * @param eventList     <std::vector<Event>>The event list</std::vector<Event>>
 */
void Date::addEventList(std::vector<Event> eventList) {
    if (this->getEvents().empty()) {
        this->setEvents(std::move(eventList));      // If event list for this Date is not initialized, then add the events
                                                    // via std::move()
    } else {
        // Appending new event list items to the end to this Date's event list.
        this->getEvents().insert(
            this->getEvents().end(),
            eventList.begin(),
            eventList.end()
        );
    }
}

/**
 * Operator method to check if two events are identical
 * @param e1        <Event>The first event</Event>
 * @param e2        <Event>The second event</Event>
 * @return          <bool>True if the events are identical</bool>
 */
static bool operator==(Event e1, Event e2) {
    return e1.getName() == e2.getName();
}

/**
 * Operator method to check if one event's starting time is earlier than that of the second event.
 * @param e1        <Event>The first event</Event>
 * @param e2        <Event>The second event</Event>
 * @return          <bool>True if first event's starting time is earlier than the second event</bool>
 */
static bool operator<(Event e1, Event e2) {
    return e1.getStartTime().convertToMinutes() < e2.getStartTime().convertToMinutes();
}

/**
 * Returns the union of two <class>Date<class> schedules
 * @param d         <Date>The other date</Date>
 * @return          <std::vector<Event>>The combined schedule</std::vector<Event>>
 */
std::vector<Event> Date::combinedSchedule(Date d) {
    std::vector<Event> cmbSchedule;
    std::vector<Event> blacklist = this->intersect(d);
    if (this->getEvents().empty() || d.getEvents().empty() || !this->isMatchingDay(d)) return cmbSchedule;
    for (const Event& e : this->getEvents()) {
        if (std::find(blacklist.begin(), blacklist.end(), e) == blacklist.end()) {
            cmbSchedule.push_back(e);
        }
    }
    for (const Event& e : d.getEvents()) {
        if (std::find(blacklist.begin(), blacklist.end(), e) == blacklist.end()) {
            cmbSchedule.push_back(e);
        }
    }
    return cmbSchedule;
}

/**
 * Returns the intersection of two <class>Date</class> schedules
 * @param d         <Date>The other date</Date>
 * @return          <std::vector<Event>>The intersection of the two schedules</std::vector<Event>>
 */
std::vector<Event> Date::intersect(Date d) {
    std::vector<Event> intersectingEvents;
    // Checking if the schedules are not empty or that the dates are not matching. If these conditions are met, then
    // an <std::vector<Event>>empty event list</std::vector<Event>> is returned.
    if (this->getEvents().empty() || d.getEvents().empty() || !this->isMatchingDay(d)) return intersectingEvents;
    for (Event e : this->getEvents()) {
        for (const Event& de : d.getEvents()) {
            if (e.isIntersecting(de)) {
                intersectingEvents.push_back(e);
                intersectingEvents.push_back(de);
            }
        }
    }
    // Removing duplicate items from <std::vector<Event>>cmbSchedule</std::vector<Event>>
    std::sort(intersectingEvents.begin(), intersectingEvents.end());
    intersectingEvents.erase(std::unique(intersectingEvents.begin(), intersectingEvents.end()), intersectingEvents.end());
    return intersectingEvents;
}

/**
 * The destructor method.
 */
Date::~Date() = default;