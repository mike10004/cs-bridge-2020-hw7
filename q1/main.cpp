// mac937@nyu.edu
// CS Bridge 2020 Winter Extended
// HW7 Question 1

#include <iostream>
#include <cassert>
#include <cstdlib>  // stage: cut

using namespace std;

const char SEPARATOR = '\t';
const int DAYS_PER_WEEK = 7;
const int M_JAN = 1;
const int M_FEB = 2;
const int M_MAR = 3;
const int M_APR = 4;
const int M_MAY = 5;
const int M_JUN = 6;
const int M_JUL = 7;
const int M_AUG = 8;
const int M_SEP = 9;
const int M_OCT = 10;
const int M_NOV = 11;
const int M_DEC = 12;

int printMonthCalendar(int numDays, int startingDay) {
    assert(startingDay >= 1 && startingDay <= DAYS_PER_WEEK);
    cout << "Mon" << SEPARATOR 
         << "Tue" << SEPARATOR 
         << "Wed" << SEPARATOR 
         << "Thu" << SEPARATOR    // question has this as "Thr" 
         << "Fri" << SEPARATOR 
         << "Sat" << SEPARATOR 
         << "Sun" << endl;
    
    int numDaysPrinted = 0, lastDay = 0;
    while (numDaysPrinted < numDays) {
        for (int day = 1; day <= DAYS_PER_WEEK; day++) {
            if (day > 1) {
                cout << SEPARATOR;
            }
            if ((numDaysPrinted < numDays) && (numDaysPrinted > 0 || day == startingDay)) {
                numDaysPrinted++;
                cout << numDaysPrinted;
                lastDay = day;
            } 
        }
        cout << endl;
    }
    return lastDay;
}

bool isLeapYear(int year) {
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

int getNumDaysInMonth(int month, int year) {
    switch (month) {
        case M_FEB:
            if (isLeapYear(year)) {
                return 29;
            } else {
                return 28;
            }
        case M_JAN:
        case M_MAR:
        case M_MAY:
        case M_JUL:
        case M_AUG:
        case M_OCT:
        case M_DEC:
            return 31;
        case M_APR:
        case M_JUN:
        case M_SEP:
        case M_NOV:
            return 30;
        default:
            cerr << "getNumDaysInMonth: invalid month: " << month << endl;
            assert(false);
            return 0;
    }
}

void printMonthName(int month) {
    switch (month) {
        case M_JAN:
            cout << "January";
            break;
        case M_FEB:
            cout << "February";
            break;
        case M_MAR:
            cout << "March";
            break;
        case M_APR:
            cout << "April";
            break;
        case M_MAY:
            cout << "May";
            break;
        case M_JUN:
            cout << "June";
            break;
        case M_JUL:
            cout << "July";
            break;
        case M_AUG:
            cout << "August";
            break;
        case M_SEP:
            cout << "September";
            break;
        case M_OCT:
            cout << "October";
            break;
        case M_NOV:
            cout << "November";
            break;
        case M_DEC:
            cout << "December";
            break;
        default:
            cerr << "printMonthName: invalid month: " << month << endl;
            assert(false);
    }
}

void printYearCalendar(int year, int startingDay) {
    for (int month = M_JAN; month <= M_DEC; month++) {
        if (month > M_JAN) {
            cout << endl;
        }
        printMonthName(month);
        cout << ' ' << year << endl;
        int numDays = getNumDaysInMonth(month, year);
        int lastDay = printMonthCalendar(numDays, startingDay);
        // +1 to advance a day, -1 to map [1.7] range to [0,6] range for mod, 
        // and then another +1 to map back to [1,7] range
        startingDay = ((lastDay + 1 - 1) % DAYS_PER_WEEK) + 1;
    }
}

int main() {
    int calendarYear, calendarStartingDay;
    char* yearStr = getenv("CALENDAR_YEAR");
    char* dayStr = getenv("CALENDAR_STARTING_DAY");
    if (yearStr != nullptr) {
        calendarYear = (int) strtol(yearStr, nullptr, 10);
        calendarStartingDay = (int) strtol(dayStr, nullptr, 10);
    } else {
    cout << "Please enter calendar year and starting day: ";
    cin >> calendarYear >> calendarStartingDay;
    }
    printYearCalendar(calendarYear, calendarStartingDay);
    return 0;
}
