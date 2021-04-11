/**
 * cpp file containing the constructor/deconstructor, as well as getters/setters
 * for the <class>ToDoList</class>
 * @author Indio Sahota
 * @date Nov 11th, 2020
 */
#include "ToDoList.h"

#include <utility>
using namespace std;

/**
 * Construct a new ToDoList with a list of items
 * @param items The list of items
 */
ToDoList::ToDoList(std::vector<ToDoItem> items) {
    this->items = move(items);
}

/**
 * Construct a new ToDoList with a list of items (no-args)
 */
ToDoList::ToDoList() {
    items = vector<ToDoItem>();
}

/**
 * Add an item to the to-do list
 * @param item The item to add
 */
void ToDoList::addItem(ToDoItem item) {
    items.push_back(item);
}

/**
 * Remove an item from the to-do list
 * @param item The item to remove
 */
void ToDoList::removeItem(ToDoItem item) {
    for(int i = 0; i < items.size(); i++) {
        if(((ToDoItem) items[i]).getItemName() == item.getItemName()) {
            items.erase(items.begin() + i);
        }
    }
}

/**
 * Get the vector containing the ToDoList.
 * @return The list
 */
vector<ToDoItem> ToDoList::getList() {
    return items;
}

/**
 * The type of list (Date or Event)
 * @return The type of the list
 */
string ToDoList::getListType() {
    return listType;
}

/**
 * Set the list type.
 * @param mlistType
 */
void ToDoList::setListType(std::string mlistType) {
    listType = move(mlistType);
}

/** Deconstructor */
ToDoList::~ToDoList() = default;
