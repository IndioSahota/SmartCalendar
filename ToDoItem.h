/**
 * Header file containing class that contains a construction for an item
 * belonging to a To-Do List for the SmartCalender Project.
 * @author Indio Sahota
 * @date Nov 11, 2020
 */
#ifndef DELIVERY3_TODOITEM_H
#define DELIVERY3_TODOITEM_H

#include <string>

class ToDoItem {
private:
    std::string itemName;
    int itemPriority;
    bool isComplete;
public:
    ToDoItem(std::string mitemName, int mitemPriority, bool misComplete);
    ToDoItem();
    std::string getItemName();
    int getItemPriority();
    bool getIsCompleted();
    void setItemName(std::string newName);
    void setItemPriority(int newPriority);
    void setCompleted(bool flag);
    ~ToDoItem();
};


#endif //DELIVERY3_TODOITEM_H
