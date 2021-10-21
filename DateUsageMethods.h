#ifndef DATEUSAGEMETHODES_H
#define DATEUSAGEMETHODES_H

#include <iostream>
#include <time.h>
#include <ctime>
#include <sstream>

#include "AuxillaryMethodes.h"

using namespace std;

class DateUsageMethodes{
    int startDate;
    int endDate;

    int howManyDaysHaveMonth(int month,int year);
    string changeYearToString(int year);
    string changeMonthToString(int month);
    string changeDayToString(int day);
    string changeDateToString(int year,int month,int day);


    bool checkEarlierDate(int fisrtDate,int secondDate);
    bool isItLeapYear(int year);
    bool isYearCorrect(int year);
    bool isMonthCorrect(int month);
    bool isDayCorrect(int day,int month,int year);


public:

    int changeDateToInt(string date);
    string changeDateWithDashesToString(string dateDashedString);
    string changeIntDateToDateWithDashes(int dateInt);
    int getCurrentDay();
    int getCurrentMonth();
    int getCurrentYear();
    int getCurrentDate();
    int getFirstDayOfCurrentMonth();
    int getFirstDayOfPreviousMonth();
    int getLastDayOfPreviousMonth();
    void setStartDate(int newStartDate);
    void setEndDate(int newEndDate);
    int getStartDate();
    int getEndDate();
    bool isDateCorrect(string dateDashedString);

};

#endif

//FW
