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
    string changeYearToString(int year);
    string changeMonthToString(int month);
    string changeDayToString(int day);
    string changeDateToString(int year,int month,int day);
    int changeDateToInt(string date);
    bool checkEarlierDate(int fisrtDate,int secondDate);

};


#endif
