/**
 * cpp file containing the constructor/destructor, as well as the mutator/accessor methods for the class
 * <class>Month</class>. This class represents a calendar month, and the dates that constitute this month.
 * @author arahma86
 * @date 10-11-2020
 */

#include "Month.h"

/**
 * Represents a calendar month
 * @param m_name                <std::string>The name of the month (i.e. October, January, etc.)</std::string>
 * @param m_number              <int>The month's number (i.e. October has number 10, June has number 6, etc.)</int>
 * @param m_year                <int>The year</int>
 * @param m_numDays             <int>Number of days within the month</int>
 * @param m_startingDayType     <std::string>The starting day of the month</std::string>
 * @param m_dates               <std::vector<Date>>The dates within this month</std::vector<Date>>
 */
Month::Month(std::string name, int number, int year, int numDays, std::string startingDayType, std::vector<Date> dates) {
    this->name = std::move(name);
    this->number = number;
    this->year = year;
    this->numDays = numDays;
    this->startingDayType = std::move(startingDayType);
    this->dates = std::move(dates);
}

/**
 * Default constructor without arguments.
 */
Month::Month() {
    this->name = "";
    this->number = 0;
    this->year = 0;
    this->numDays = 0;
    this->startingDayType = "";
    this->dates = std::vector<Date>();
}

/**
 * Mutator for <std::string>name</std::string>
 * @param m_name        <std::string>The name</std::string>
 */
void Month::setName(std::string m_name) {
    this->name = std::move(m_name);
}

/**
 * Mutator for <int>number</int>
 * @param m_number      <int>The month number</int>
 */
void Month::setNumber(int m_number) {
    this->number = m_number;
}

/**
 * Mutator for <int>year</int>
 * @param m_year        <int>The current year</int>
 */
void Month::setYear(int m_year) {
    this->year = m_year;
}

/**
 * Mutator for <int>numDays</int>
 * @param m_numDays     <int>The number of days within the month</int>
 */
void Month::setNumDays(int m_numDays) {
    this->numDays = m_numDays;
}

/**
 * Mutator for <std::string>startingDayType</std::string>
 * @param m_startingDayType     <std::string>The starting day type</std::string>
 */
void Month::setStartingDayType(std::string m_startingDayType) {
    this->startingDayType = std::move(m_startingDayType);
}

/**
 * Mutator for <std::vector<Date>>dates</std::vector<Dates>>
 * @param m_dates
 */
void Month::setDates(std::vector<Date> m_dates) {
    this->dates = std::move(m_dates);
}

/**
 * Accessor for <std::string>name</std::string>
 * @return          <std::string>The name of the month</std::string>
 */
std::string Month::getName() {
    return this->name;
}

/**
 * Accessor for <int>number</int>
 * @return          <int>The month number</int>
 */
int Month::getNumber() {
    return this->number;
}

/**
 * Accessor for <int>year</int>
 * @return          <int>The current year</int>
 */
int Month::getYear() {
    return this->year;
}

/**
 * Accessor for <int>numDays</int>
 * @return          <int>The number of days</int>
 */
int Month::getNumDays() {
    return this->numDays;
}

/**
 * Accessor for <std::string>startingDayType</std::string>
 * @return          <std::string>The starting day type</std::string>
 */
std::string Month::getStartingDayType() {
    return this->startingDayType;
}

/**
 * Accessor for <std::vector<Date>>dates</std::vector<Date>>
 * @return          <std::vector<Date>>The list of dates</std::vector<Date>>
 */
std::vector<Date> Month::getDates() {
    return this->dates;
}

/**
 * Checks if the months are matching (not based off of matching <std::vector<Date>>dates</std::vector<Date>>)
 * @param m         <Month>The other month</Month>
 * @return          <bool>True if the months are matching</bool>
 */
bool Month::isMatchingMonth(Month m) {
    return (this->getName() == m.getName()) && (this->getNumber() == m.getNumber()) || (this->getYear() == m.getYear())
    && (this->getNumDays() == m.getNumDays()) && (this->getStartingDayType() == m.getStartingDayType());
}

/**
 * Returns the union of daily schedules for two months.
 * @param m         <Month>The other month</Month>
 * @return          <std::vector<std::vector<Event>>>List of combined daily schedules throughout the month</std::vector<std::vector<Event>>>
 */
std::vector<std::vector<Event>> Month::combinedSchedule(Month m) {
    std::vector<std::vector<Event>> cmbSchedule;
    // Checking if the months are not empty or that the months are not matching. If these conditions are met, then
    // an <std::vector<std::vector<Event>>>empty list of daily schedules</std::vector<std::vector<Event>>> is returned.
    if (this->getDates().empty() || m.getDates().empty() || !this->isMatchingMonth(m)) return cmbSchedule;
    for (Date d : this->getDates()) {
        for (Date md : m.getDates()) {
            cmbSchedule.push_back(d.combinedSchedule(md));
        }
    }
    return cmbSchedule;
}

/**
 * Returns the intersection of daily schedules for two months.
 * @param m         <Month>The other month</Month>
 * @return          <std::vector<std::vector<Event>>>List of intersecting daily schedules throughout the month</std::vector<std::vector<Event>>>
 */
std::vector<std::vector<Event>> Month::intersect(Month m) {
    std::vector<std::vector<Event>> intersectingSchedule;
    // Checking if the months are not empty or that the months are not matching. If these conditions are met, then
    // an <std::vector<std::vector<Event>>>empty list of daily schedules</std::vector<std::vector<Event>>> is returned.
    if (this->getDates().empty() || m.getDates().empty() || !this->isMatchingMonth(m)) return intersectingSchedule;
    for (Date d : this->getDates()) {
        for (Date md : m.getDates()) {
            intersectingSchedule.push_back(d.intersect(md));
        }
    }
    return intersectingSchedule;
}

/**
 * The destructor method.
 */
Month::~Month() = default;
