#include "calendarwindow.h"
#include "ui_calendarwindow.h"

#include <QCalendarWidget>
#include <QCheckBox>
#include <QComboBox>
#include <QDateEdit>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QTextCharFormat>
#include <QTextEdit>

#include <iostream> // for cout, REMOVE LATER

// Constructor
CalendarWindow::CalendarWindow(QWidget *parent)
    : QMainWindow(parent) // The main window
    , ui(new Ui::CalendarWindow) // The UI for the main window
{
    ui->setupUi(this); // Set up the UI for the main window
    this->setFixedWidth(605);
    this->setFixedHeight(522);

    // Left side (column 0) group boxes
    createSmartCalendarGroupBox();
    createOptionsGroupBox();
    createFeatureButtonsGroupBox();

    // Right side (column 1) group boxes
    createTextAreaGroupBox();
    createTextBoxGroupBox();
    createEventSettingsGroupBox();

    QGridLayout *layout = new QGridLayout;
    // Left side (column 0) group boxes
    layout->addWidget(smartCalendarGroupBox, 0, 0);
    layout->addWidget(optionsGroupBox, 1, 0);
    layout->addWidget(featureButtonsGroupBox, 2, 0);

    // Right side (column 1) group boxes
    layout->addWidget(textAreaGroupBox, 0, 1);
    layout->addWidget(textBoxGroupBox, 1, 1);
    layout->addWidget(eventSettingsGroupBox, 2, 1);

    layout->setSizeConstraint(QLayout::SetFixedSize);

    QWidget *widget = new QWidget();
    widget->setLayout(layout);
    this->setCentralWidget(widget);

    // The QCalendarWidget 'calendar' is placed onto smartCalendarLayout at (0, 0),
    // or row 0 and column 0. Set row 0's height to be at least the recommended height
    // of 'eventsList' in pixels, and set column 0's width to be at least the recommended
    // width of 'eventsList' in pixels. This ensures that both 'calendar' and 'eventsList'
    // in the adjacent group box are fully displayed, since 'eventsList' is the bigger one.
    smartCalendarLayout->setRowMinimumHeight(0, eventsList->sizeHint().height());
    smartCalendarLayout->setColumnMinimumWidth(0, eventsList->sizeHint().width());

    this->setWindowTitle(tr("SmartCalendar"));

    // Weekday font colour is black by default. Weekend font colour is red by default.
    // Set weekend font colour to black to make it all uniform.
    QTextCharFormat weekendFontColour;
    weekendFontColour.setForeground(QColor(Qt::black));
    calendar->setWeekdayTextFormat(Qt::Saturday, weekendFontColour);
    calendar->setWeekdayTextFormat(Qt::Sunday, weekendFontColour);
}

// Destructor
CalendarWindow::~CalendarWindow()
{
    delete ui;
}

void CalendarWindow::firstDayChanged(int index)
{
    calendar->setFirstDayOfWeek(Qt::DayOfWeek(firstDayMenu->itemData(index).toInt()));
}

void CalendarWindow::selectedDateChanged()
{
    selectedDateEdit->setDate(calendar->selectedDate());

    viewEventsButton->setEnabled(true);
    hideEventsButton->setEnabled(false);

    eventsList->setVisible(false);
}

void CalendarWindow::viewEventsButtonClick()
{
    viewEventsButton->setEnabled(false);
    hideEventsButton->setEnabled(true);

    eventsList->setVisible(true);
}

void CalendarWindow::addEventButtonClick()
{
    addEventButton->setEnabled(false);
    confirmAddButton->setEnabled(true);

    addEventInput->setEnabled(true);
    startTimeInput->setEnabled(true);
    endTimeInput->setEnabled(true);
}

void CalendarWindow::confirmAddButtonClick()
{
    confirmAddButton->setEnabled(false);
    addEventButton->setEnabled(true);

    addEventInput->setEnabled(false);
    addEventInput->clear();
    startTimeInput->setEnabled(false);
    startTimeInput->clear();
    startTimeInput->setText(QString::fromStdString("00:00"));
    endTimeInput->setEnabled(false);
    endTimeInput->clear();
    endTimeInput->setText(QString::fromStdString("00:00"));
}

void CalendarWindow::hideEventsButtonClick()
{
    hideEventsButton->setEnabled(false);
    viewEventsButton->setEnabled(true);

    eventsList->setVisible(false);
}

void CalendarWindow::removeEventButtonClick()
{
    removeEventButton->setEnabled(false);
    confirmRemoveButton->setEnabled(true);

    removeEventInput->setEnabled(true);
}

void CalendarWindow::confirmRemoveButtonClick()
{
    confirmRemoveButton->setEnabled(false);
    removeEventButton->setEnabled(true);

    removeEventInput->setEnabled(false);
    removeEventInput->clear();
}

void CalendarWindow::editEventsButtonClick()
{
    /*
    eventsList->append("");
    eventsList->append(addEventInput->text());
    */

    viewEventsButtonClick();
    hideEventsButton->setEnabled(false);

    editEventsButton->setEnabled(false);
    doneEditButton->setEnabled(true);

    eventsList->setReadOnly(false);
}

void CalendarWindow::doneEditButtonClick()
{
    /*
    std::string utf8_string = input->text().toUtf8().constData(); // remove later
    std::cout << utf8_string; // change to cout!@!@!@!@!@
    */

    hideEventsButton->setEnabled(true);

    doneEditButton->setEnabled(false);
    editEventsButton->setEnabled(true);

    eventsList->setReadOnly(true);
}

void CalendarWindow::cancelButtonClick()
{
    /*
    std::cout << "hurray\n"; // change to cout!@!@!@!@!@

    QTextCharFormat weekendFontColour;
    weekendFontColour.setForeground(QColor(Qt::red));
    calendar->setWeekdayTextFormat(Qt::Wednesday, weekendFontColour);
    */

    // Set everything back to original state
    viewEventsButton->setEnabled(true);
    addEventButton->setEnabled(true);
    confirmAddButton->setEnabled(false);

    hideEventsButton->setEnabled(false);
    removeEventButton->setEnabled(true);
    confirmRemoveButton->setEnabled(false);

    editEventsButton->setEnabled(true);
    doneEditButton->setEnabled(false);

    eventsList->setVisible(false);
    addEventInput->setEnabled(false);
    addEventInput->clear();
    startTimeInput->setEnabled(false);
    startTimeInput->clear();
    startTimeInput->setText(QString::fromStdString("00:00"));
    endTimeInput->setEnabled(false);
    endTimeInput->clear();
    endTimeInput->setText(QString::fromStdString("00:00"));

    removeEventInput->setEnabled(false);
    removeEventInput->clear();
}

void CalendarWindow::priorityLowButtonClick()
{

}

void CalendarWindow::priorityMediumButtonClick()
{

}

void CalendarWindow::priorityHighButtonClick()
{
    /*
    QTextCharFormat weekendFontColour;
    weekendFontColour.setForeground(QColor(Qt::yellow));
    calendar->setWeekdayTextFormat(Qt::Tuesday, weekendFontColour);
    */
}

void CalendarWindow::toDoCheckBoxToggled()
{
    /*
    if (toDoCheckBox->isChecked()) {
        QTextCharFormat weekendFontColour;
        weekendFontColour.setForeground(QColor(Qt::green));
        calendar->setWeekdayTextFormat(Qt::Tuesday, weekendFontColour);
    } else {
        QTextCharFormat weekendFontColour;
        weekendFontColour.setForeground(QColor(Qt::black));
        calendar->setWeekdayTextFormat(Qt::Tuesday, weekendFontColour);
    }
    */
}

void CalendarWindow::createSmartCalendarGroupBox()
{
    smartCalendarGroupBox = new QGroupBox(tr("SmartCalendar"));

    calendar = new QCalendarWidget;
    calendar->setMinimumDate(QDate(1920, 1, 1));
    calendar->setMaximumDate(QDate(2120, 1, 1));
    calendar->setGridVisible(true);
    calendar->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);

    connect(calendar, &QCalendarWidget::selectionChanged,
            this, &CalendarWindow::selectedDateChanged);

    smartCalendarLayout = new QGridLayout;
    smartCalendarLayout->addWidget(calendar, 0, 0, Qt::AlignCenter);

    smartCalendarGroupBox->setLayout(smartCalendarLayout);
}

void CalendarWindow::createOptionsGroupBox()
{
    optionsGroupBox = new QGroupBox(tr("Calendar Options"));

    selectedDateLabel = new QLabel(tr("&Selected Date:"));
    selectedDateEdit = new QDateEdit;
    selectedDateEdit->setDisplayFormat("MMM dd yyyy");
    selectedDateEdit->setDate(calendar->selectedDate());
    selectedDateEdit->setDateRange(calendar->minimumDate(),
                                  calendar->maximumDate());
    selectedDateLabel->setBuddy(selectedDateEdit);

    firstDayLabel = new QLabel(tr("Wee&k starts on:"));
    firstDayMenu = new QComboBox;
    firstDayMenu->addItem(tr("Sunday"), Qt::Sunday);
    firstDayMenu->addItem(tr("Monday"), Qt::Monday);
    firstDayMenu->addItem(tr("Tuesday"), Qt::Tuesday);
    firstDayMenu->addItem(tr("Wednesday"), Qt::Wednesday);
    firstDayMenu->addItem(tr("Thursday"), Qt::Thursday);
    firstDayMenu->addItem(tr("Friday"), Qt::Friday);
    firstDayMenu->addItem(tr("Saturday"), Qt::Saturday);
    firstDayLabel->setBuddy(firstDayMenu);

    connect(selectedDateEdit, &QDateEdit::dateChanged,
            calendar, &QCalendarWidget::setSelectedDate);
    connect(firstDayMenu, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &CalendarWindow::firstDayChanged);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(selectedDateLabel, 0, 0);
    layout->addWidget(selectedDateEdit, 0, 1);

    layout->addWidget(firstDayLabel, 1, 0);
    layout->addWidget(firstDayMenu, 1, 1);

    optionsGroupBox->setLayout(layout);
}

void CalendarWindow::createFeatureButtonsGroupBox()
{
    featureButtonsGroupBox = new QGroupBox(tr("Features"));

    viewEventsButton = new QPushButton("View Events");
    viewEventsButton->setMaximumWidth(150);
    viewEventsButton->setMaximumHeight(100);
    viewEventsButton->setToolTip("View events of this date");

    addEventButton = new QPushButton("Add Event");
    addEventButton->setMaximumWidth(150);
    addEventButton->setMaximumHeight(100);
    addEventButton->setToolTip("Add an event to this date");

    confirmAddButton = new QPushButton("Confirm Add");
    confirmAddButton->setMaximumWidth(150);
    confirmAddButton->setMaximumHeight(100);
    confirmAddButton->setToolTip("Add event confirmation");
    confirmAddButton->setEnabled(false);

    hideEventsButton = new QPushButton("Hide Events");
    hideEventsButton->setMaximumWidth(150);
    hideEventsButton->setMaximumHeight(100);
    hideEventsButton->setToolTip("Hide events of this date");
    hideEventsButton->setEnabled(false);

    removeEventButton = new QPushButton("Remove Event");
    removeEventButton->setMaximumWidth(150);
    removeEventButton->setMaximumHeight(100);
    removeEventButton->setToolTip("Remove an event from this date");

    confirmRemoveButton = new QPushButton("Confirm Remove");
    confirmRemoveButton->setMaximumWidth(150);
    confirmRemoveButton->setMaximumHeight(100);
    confirmRemoveButton->setToolTip("Remove event confirmation");
    confirmRemoveButton->setEnabled(false);

    editEventsButton = new QPushButton("Edit Events");
    editEventsButton->setMaximumWidth(150);
    editEventsButton->setMaximumHeight(100);
    editEventsButton->setToolTip("Edit events of this date");

    doneEditButton = new QPushButton("Done Edit");
    doneEditButton->setMaximumWidth(150);
    doneEditButton->setMaximumHeight(100);
    doneEditButton->setToolTip("Done editing events of this date");
    doneEditButton->setEnabled(false);

    cancelButton = new QPushButton("Cancel");
    cancelButton->setMaximumWidth(150);
    cancelButton->setMaximumHeight(100);
    cancelButton->setToolTip("Cancel add/remove");

    connect(viewEventsButton, &QPushButton::clicked,
            this, &CalendarWindow::viewEventsButtonClick);
    connect(addEventButton, &QPushButton::clicked,
            this, &CalendarWindow::addEventButtonClick);
    connect(confirmAddButton, &QPushButton::clicked,
            this, &CalendarWindow::confirmAddButtonClick);

    connect(hideEventsButton, &QPushButton::clicked,
            this, &CalendarWindow::hideEventsButtonClick);
    connect(removeEventButton, &QPushButton::clicked,
            this, &CalendarWindow::removeEventButtonClick);
    connect(confirmRemoveButton, &QPushButton::clicked,
            this, &CalendarWindow::confirmRemoveButtonClick);
    connect(editEventsButton, &QPushButton::clicked,
            this, &CalendarWindow::editEventsButtonClick);
    connect(doneEditButton, &QPushButton::clicked,
            this, &CalendarWindow::doneEditButtonClick);
    connect(cancelButton, &QPushButton::clicked,
            this, &CalendarWindow::cancelButtonClick);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(viewEventsButton, 0, 0);
    layout->addWidget(addEventButton, 0, 1);
    layout->addWidget(confirmAddButton, 0, 2);

    layout->addWidget(hideEventsButton, 1, 0);
    layout->addWidget(removeEventButton, 1, 1);
    layout->addWidget(confirmRemoveButton, 1, 2);

    layout->addWidget(editEventsButton, 2, 0);
    layout->addWidget(doneEditButton, 2, 1);
    layout->addWidget(cancelButton, 2, 2);

    featureButtonsGroupBox->setLayout(layout);
}

void CalendarWindow::createTextAreaGroupBox()
{
    textAreaGroupBox = new QGroupBox(tr("Events List"));

    eventsList = new QTextEdit("");
    eventsList->setReadOnly(true);
    eventsList->setVisible(false);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(eventsList, 0, 0);

    textAreaGroupBox->setLayout(layout);
}

void CalendarWindow::createTextBoxGroupBox()
{
    textBoxGroupBox = new QGroupBox(tr("Add/Remove Event/To-do List"));

    addEventLabel = new QLabel(tr("&Add Event:"));
    addEventInput = new QLineEdit("");
    addEventInput->setEnabled(false);
    addEventLabel->setBuddy(addEventInput);

    startTimeLabel = new QLabel(tr("&Start time:"));
    startTimeLabel->setToolTip("24-h format");
    startTimeInput = new QLineEdit("00:00");
    startTimeInput->setToolTip("24-h format");
    startTimeInput->setEnabled(false);
    startTimeLabel->setBuddy(startTimeInput);

    endTimeLabel = new QLabel(tr("&End time:"));
    endTimeLabel->setToolTip("24-h format");
    endTimeInput = new QLineEdit("00:00");
    endTimeInput->setToolTip("24-h format");
    endTimeInput->setEnabled(false);
    endTimeLabel->setBuddy(endTimeInput);

    removeEventLabel = new QLabel(tr("&Remove Event:"));
    removeEventInput = new QLineEdit("");
    removeEventInput->setEnabled(false);
    removeEventLabel->setBuddy(removeEventInput);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(addEventLabel, 0, 0);
    layout->addWidget(addEventInput, 0, 1);
    layout->addWidget(startTimeLabel, 1, 0);
    layout->addWidget(startTimeInput, 1, 1);
    layout->addWidget(endTimeLabel, 2, 0);
    layout->addWidget(endTimeInput, 2, 1);

    layout->addWidget(removeEventLabel, 3, 0);
    layout->addWidget(removeEventInput, 3, 1);

    textBoxGroupBox->setLayout(layout);
}

void CalendarWindow::createEventSettingsGroupBox()
{
    eventSettingsGroupBox = new QGroupBox(tr("Event Settings"));

    priorityLowButton = new QRadioButton("Low Priority");
    priorityLowButton->setChecked(true);
    priorityLowButton->setToolTip("Priority level: 1");
    priorityMediumButton = new QRadioButton("Medium Priority");
    priorityMediumButton->setToolTip("Priority level: 2");
    priorityHighButton = new QRadioButton("High Priority");
    priorityHighButton->setToolTip("Priority level: 3");

    toDoCheckBox = new QCheckBox(tr("&To-do list"));
    toDoCheckBox->setChecked(false);
    toDoCheckBox->setToolTip("If checked, enter a comma-separated list in the form: item1,item2,item3");

    connect(priorityLowButton, &QRadioButton::clicked,
            this, &CalendarWindow::priorityLowButtonClick);
    connect(priorityMediumButton, &QRadioButton::clicked,
            this, &CalendarWindow::priorityMediumButtonClick);
    connect(priorityHighButton, &QRadioButton::clicked,
            this, &CalendarWindow::priorityHighButtonClick);
    connect(toDoCheckBox, &QCheckBox::toggled,
            this, &CalendarWindow::toDoCheckBoxToggled);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(priorityLowButton, 0, 0);
    layout->addWidget(priorityMediumButton, 0, 1);
    layout->addWidget(priorityHighButton, 0, 2);
    layout->addWidget(toDoCheckBox, 1, 0);

    eventSettingsGroupBox->setLayout(layout);
}
