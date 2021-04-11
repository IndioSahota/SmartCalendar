/**
 * Header file containing class that contains a construction for a To-DO list
 * for the SmartCalender Project.
 * @author Indio Sahota
 * @date Nov 11, 2020
 */
#ifndef DELIVERY3_TODOLIST_H
#define DELIVERY3_TODOLIST_H


#include "ToDoItem.h"
#include <vector>

class ToDoList {
private:
    std::vector<ToDoItem> items;
    std::string listType;
public:
    ToDoList(std::vector<ToDoItem> items);
    ToDoList();
    void addItem(ToDoItem item);
    void removeItem(ToDoItem item);
    std::vector<ToDoItem> getList();
    std::string getListType();
    void setListType(std::string mlistType);
    ~ToDoList();
};


#endif //DELIVERY3_TODOLIST_H
