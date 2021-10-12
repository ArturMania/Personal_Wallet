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
    static int getYear();
    static int getMonth();
    static int getDay();
    static int getCurrentDay();
    static int getCurrentMonth();
    static int getCurrentYear();
    static string changeYearToString(int year);
    static string changeMonthToString(int month);
    static string changeDayToString(int day);
    static string changeDateToString(int year,int month,int day);
    static int changeDateToInt(string date);
    bool checkEarlierDate(int fisrtDate,int secondDate);

};


#endif
