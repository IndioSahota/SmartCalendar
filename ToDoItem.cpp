/**
 * cpp file containing the constructor/deconstructor, as well as getters/setters
 * for the <class>ToDoItem</class>
 * @author Indio Sahota
 * @date Nov 11, 2020
 */
#include "ToDoItem.h"

#include <utility>
using namespace std;

/**
 * Constructs a new ToDoItem
 * @param mitemName The item's name
 * @param mitemPriority The item's priority value
 * @param misComplete Flag if the item has been completed or not
 */
ToDoItem::ToDoItem(std::string mitemName, int mitemPriority, bool misComplete) {
    itemName = move(mitemName);
    itemPriority = mitemPriority;
    isComplete = misComplete;
}

/**
 * Constructs a new ToDoItem (no-args)
 */
ToDoItem::ToDoItem() {
    itemName = "";
    itemPriority = 0;
    isComplete = false;
}

/**
 * Get the item name
 * @return The item name
 */
string ToDoItem::getItemName() {
    return itemName;
}

/**
 * Get the item priority
 * @return The item priority
 */
int ToDoItem::getItemPriority() {
    return itemPriority;
}

/**
 * Get whether the item has been completed or not
 * @return The flag value
 */
bool ToDoItem::getIsCompleted() {
    return isComplete;
}

/**
 * Set a new name for the item
 * @param newName The new item name
 */
void ToDoItem::setItemName(string newName) {
    itemName = move(newName);
}

/**
 * Change the item's priority
 * @param newPriority The new priority
 */
void ToDoItem::setItemPriority(int newPriority) {
    itemPriority = newPriority;
}

/**
 * Flag the event as completed or incomplete
 * @param flag The flag for completion.
 */
void ToDoItem::setCompleted(bool flag) {
    isComplete = flag;
}


/** Deconstructor */
ToDoItem::~ToDoItem() = default;
