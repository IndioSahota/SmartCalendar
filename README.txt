# SmartCalendar
## A New and Improved Way to Plan Your Day!
### Created by: Aja Khanal, Aryan Rahman, Indio Sahota, Melvin Taing

The project's code is seperated into two working directories, one for the backend, the other for the frontend. To run Smart Calender on the RasberryPi, please do the following steps:

 1. Create a new directory and extract the project files
 2. In the terminal enter the following command:  
	 `g++ ConflictingEvent.* Date.* Event.* EventTime.* Month.* NestedEvent.* ToDoItem.* ToDoList.* main.cpp -o driver`
 3. You can now run the program by entering: `./driver`
 4. To run the gui first type: `sudo apt-get install qt4-dev-tools`
 5. After installing, simply click on the open on the main page, and choose the GUI folder

To run the program on windows, use the SmartCalendar executable file in the SmartCalendar folder.