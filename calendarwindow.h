#ifndef CALENDARWINDOW_H
#define CALENDARWINDOW_H

#include <QMainWindow>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class CalendarWindow; }

class QCalendarWidget;
class QCheckBox;
class QComboBox;

class QDateEdit;

class QGridLayout;
class QGroupBox;

class QLabel;
class QLineEdit;

class QPushButton;

class QRadioButton;

class QTextEdit;
QT_END_NAMESPACE

class CalendarWindow : public QMainWindow
{
    Q_OBJECT

public:
    CalendarWindow(QWidget *parent = nullptr);
    ~CalendarWindow();

// Functions that respond to a signal (e.g. button click)
private slots:
    void firstDayChanged(int index);
    void selectedDateChanged();

    void viewEventsButtonClick();
    void addEventButtonClick();
    void confirmAddButtonClick();

    void hideEventsButtonClick();
    void removeEventButtonClick();
    void confirmRemoveButtonClick();

    void editEventsButtonClick();
    void doneEditButtonClick();
    void cancelButtonClick();

    void priorityLowButtonClick();
    void priorityMediumButtonClick();
    void priorityHighButtonClick();

    void toDoCheckBoxToggled();

private:
    // Left side (column 0) group boxes
    void createSmartCalendarGroupBox();
    void createOptionsGroupBox();
    void createFeatureButtonsGroupBox();

    // Right side (column 1) group boxes
    void createTextAreaGroupBox();
    void createTextBoxGroupBox();
    void createEventSettingsGroupBox();

    Ui::CalendarWindow *ui;

    // Left side (column 0) group boxes
    QGroupBox *smartCalendarGroupBox;
    QGridLayout *smartCalendarLayout;
    QCalendarWidget *calendar;

    QGroupBox *optionsGroupBox;
    QLabel *selectedDateLabel;
    QDateEdit *selectedDateEdit;
    QLabel *firstDayLabel;
    QComboBox *firstDayMenu;

    QGroupBox *featureButtonsGroupBox;
    QPushButton *viewEventsButton;
    QPushButton *addEventButton;
    QPushButton *confirmAddButton;
    QPushButton *hideEventsButton;
    QPushButton *removeEventButton;
    QPushButton *confirmRemoveButton;
    QPushButton *editEventsButton;
    QPushButton *doneEditButton;
    QPushButton *cancelButton;

    // Right side (column 1) group boxes
    QGroupBox *textAreaGroupBox;
    QTextEdit *eventsList;

    QGroupBox *textBoxGroupBox;
    QLabel *addEventLabel;
    QLineEdit *addEventInput;
    QLabel *startTimeLabel;
    QLineEdit *startTimeInput;
    QLabel *endTimeLabel;
    QLineEdit *endTimeInput;
    QLabel *removeEventLabel;
    QLineEdit *removeEventInput;

    QGroupBox *eventSettingsGroupBox;
    QRadioButton *priorityLowButton;
    QRadioButton *priorityMediumButton;
    QRadioButton *priorityHighButton;
    QCheckBox *toDoCheckBox;
};

#endif
