/**
 * .h file containing definitions for the destructor/constructor, as well as the mutator/accessor
 * methods for the class <class>Month</class>
 * @author arahma86
 * @date 10-11-2020
 */

#ifndef SMARTCALENDAR_MONTH_H
#define SMARTCALENDAR_MONTH_H

#include <string>
#include <vector>
#include "Date.h"

class Month {
private:
    std::string name, startingDayType;
    int number, year, numDays;
    std::vector<Date> dates;
public:
    Month(std::string, int, int, int, std::string, std::vector<Date>);
    Month();
    ~Month();
    void setName(std::string);
    void setNumber(int);
    void setYear(int);
    void setNumDays(int);
    void setStartingDayType(std::string);
    void setDates(std::vector<Date>);
    std::string getName();
    int getNumber();
    int getYear();
    int getNumDays();
    std::string getStartingDayType();
    std::vector<Date> getDates();
    bool isMatchingMonth(Month);
    std::vector<std::vector<Event>> combinedSchedule(Month);
    std::vector<std::vector<Event>> intersect(Month);
};

#endif //SMARTCALENDAR_MONTH_H
