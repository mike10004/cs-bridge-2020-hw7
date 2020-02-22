// mac937@nyu.edu
// CS Bridge 2020 Winter Extended
// HW7 Question 1

#include <iostream>
#include <cassert>
#include <cstdlib>  // stage: cut

using namespace std;

const char SEPARATOR = '\t';
const int DAYS_PER_WEEK = 7;

int printMonthCalendar(int numDays, int startingDay) {
    assert(startingDay >= 1 && startingDay <= DAYS_PER_WEEK);
    cout << "Mon" << SEPARATOR 
         << "Tue" << SEPARATOR 
         << "Wed" << SEPARATOR 
         << "Thu" << SEPARATOR 
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

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "usage error: two arguments required" << endl;
        return 1;
    }
    int calendarYear, calendarStartingDay;
//    cout << "Please enter calendar year and starting day: " << endl;
//    cin >> calendarYear >> calendarStartingDay;
    calendarYear = (int) strtol(argv[1], nullptr, 10);
    calendarStartingDay = (int) strtol(argv[2], nullptr, 10);
    printMonthCalendar(calendarYear, calendarStartingDay);
        

    return 0;
}
