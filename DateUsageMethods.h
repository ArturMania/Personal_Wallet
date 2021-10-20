#ifndef DATEUSAGEMETHODES_H
#define DATEUSAGEMETHODES_H

#include <iostream>
#include <time.h>
#include <ctime>
#include <sstream>

#include "AuxillaryMethodes.h"

using namespace std;

class DateUsageMethodes{

public:
    int getYear();
    int getMonth();
    int getDay();
    int getCurrentDay();
    int getCurrentMonth();
    int getCurrentYear();
    int getCurrentDate();
    int howManyDaysHaveMonth(int month,int year);
    string changeYearToString(int year);
    string changeMonthToString(int month);
    string changeDayToString(int day);
    string changeDateToString(int year,int month,int day);
    string changeDateWithDashesToString(string dateDashedString);
    string changeIntDateToDateWithDashes(int dateInt);
    int changeDateToInt(string date);
    bool checkEarlierDate(int fisrtDate,int secondDate);
    bool isItLeapYear(int year);
    bool isYearCorrect(int year);
    bool isMonthCorrect(int month);
    bool isDayCorrect(int day);

};


#endif
