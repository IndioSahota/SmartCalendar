#include <iostream>
#include <string>
#include <vector>
#include "EventTime.h"
#include "Event.h"
#include "Date.h"

using namespace std;

int main() {
    cout << "Test 1: Creating instance of EventTime object using no-args constructor" << endl;
    EventTime no_time = EventTime();
    cout << "Hours: " << no_time.getHours() << "\nMinutes:" << no_time.getMinutes() << endl;
    if (no_time.getHours() == 0 && no_time.getMinutes() == 0){
        cout << "Test 1 passed" << endl;
    } else {
        cout << "Test 1 failed" << endl;
    }

    cout << "\nTest 2: Creating instance of EventTime object using direct constructor" << endl;
    EventTime time = EventTime(1, 30);
    cout << "Hours: " << time.getHours() << "\nMinutes:" << time.getMinutes() << endl;
    if (time.getHours() == 1 && time.getMinutes() == 30){
        cout << "Test 2 passed" << endl;
    } else {
        cout << "Test 2 failed" << endl;
    }

    cout << "\nTest 3: Changing attributes in time" << endl;
    time.setHours(13);
    time.setMinutes(45);
    cout << "Hours: " << time.getHours() << "\nMinutes:" << time.getMinutes() << endl;
    if (time.getHours() == 13 && time.getMinutes() == 45){
        cout << "Test 3 passed" << endl;
    } else {
        cout << "Test 3 failed" << endl;
    }

    cout << "\nTest 4: Converting hours to minutes" << endl;
    cout << "Converted to minutes: " << time.convertToMinutes()<< endl;
    if (time.convertToMinutes() == 825){
        cout << "Test 4 passed" << endl;
    } else {
        cout << "Test 4 failed" << endl;
    }

    cout << "\nTest 5: Converting minutes to hours" << endl;
    cout << "Converted to hours: " << time.convertToHours()<< endl;
    if (time.convertToHours() == 13.75){
        cout << "Test 5 passed" << endl;
    } else {
        cout << "Test 5 failed" << endl;
    }

    cout << "\nTest 6: Creating instance of Event object using no-args constructor" << endl;
    Event no_event = Event();
    cout << "Name: " << no_event.getName() << "\nDescription:" << no_event.getDescription() << endl;
    if (no_time.getHours() == 0 && no_time.getMinutes() == 0){
        cout << "Test 6 passed" << endl;
    } else {
        cout << "Test 6 failed" << endl;
    }

    cout << "\nTest 7: Creating instance of Event object using direct constructor" << endl;
    Event event = Event("", "", "", EventTime(0, 0), EventTime(0, 0), 0, 0, 0, false, ToDoList());
    cout << "Name: " << no_event.getName() << "\nDescription:" << no_event.getDescription() << endl;
    if (no_time.getHours() == 0 && no_time.getMinutes() == 0){
        cout << "Test 7 passed" << endl;
    } else {
        cout << "Test 7 failed" << endl;
    }

    string a;
    cout << "\nPress any key to continue" << endl;
    cin >> a;

    cout << "\nTest 8: Testing intersection between two events - Where two events do not intersect" << endl;
    Event eventA = Event("A", "This is event A", "", EventTime(15, 20), EventTime(16, 0), 0, 0, 0, false, ToDoList());
    Event eventB = Event("B", "This is event B", "", EventTime(1, 0), EventTime(2, 0), 0, 0, 0, false, ToDoList());
    cout << "Event A: "<<eventA.getStartTime().getHours() << ":" << eventA.getStartTime().getMinutes() << " - "<< eventA.getEndTime().getHours() << ":" << eventA.getEndTime().getMinutes()<<endl;
    cout << "Event B: "<<eventB.getStartTime().getHours() << ":" << eventB.getStartTime().getMinutes() << " - "<< eventB.getEndTime().getHours() << ":" << eventB.getEndTime().getMinutes()<<endl;
    if (!eventA.isIntersecting(eventB)){
        cout << "Test 8 passed" << endl;
    } else {
        cout << "Test 8 failed" << endl;
    }

    string b;
    cout << "\nPress any key to continue" << endl;
    cin >> b;

    cout << "\nTest 9: Testing intersection between two events - Where two events do intersect" << endl;
    Event eventC = Event("B", "This is event B", "", EventTime(1, 0), EventTime(2, 0), 0, 0, 0, false, ToDoList());
    cout << "Event B: "<<eventB.getStartTime().getHours() << ":" << eventB.getStartTime().getMinutes() << " - "<< eventB.getEndTime().getHours() << ":" << eventB.getEndTime().getMinutes()<<endl;
    cout << "Event C: "<<eventB.getStartTime().getHours() << ":" << eventB.getStartTime().getMinutes() << " - "<< eventB.getEndTime().getHours() << ":" << eventB.getEndTime().getMinutes()<<endl;
    if (eventB.isIntersecting(eventC)){
        cout << "Test 9 passed" << endl;
    } else {
        cout << "Test 9 failed" << endl;
    }

    string c;
    cout << "\nPress any key to continue" << endl;
    cin >> c;

    cout << "\nTest 10: Testing combinedSchedule method from Date class" << endl;
    std::vector<Event> eventListA = {
            Event("Breakfast", "This is Breakfast", "Home", EventTime(8, 20), EventTime(9, 0), 0, 0, 0, false, ToDoList()),
            Event("Lunch", "This is Lunch", "Home", EventTime(12, 20), EventTime(16, 0), 0, 0, 0, false, ToDoList())
    };
    std::vector<Event> eventListB = {
            Event("Groceries", "Groceries", "Costco", EventTime(14, 0), EventTime(16, 0), 0, 0, 0, false, ToDoList()),
            Event("Shift", "Shift", "Dropzone-57A", EventTime(17, 0), EventTime(22, 0), 0, 0, 0, false, ToDoList())
    };
    Date dateA = Date("Thursday", 4, "November", 2020, "", false, eventListA);
    Date dateB = Date("Thursday", 4, "November", 2020, "", false, eventListB);
    cout << "\nCombined schedule:" << endl;
    for (Event e : dateA.combinedSchedule(dateB)) {
        cout << e.getName() << endl;
    }

    string d;
    cout << "\nPress any key to continue" << endl;
    cin >> d;

    cout << "\nIntersection of schedules:" << endl;
    for (Event e : dateA.intersect(dateB)) {
        cout << e.getName() << endl;
    }
    return 0;
}
