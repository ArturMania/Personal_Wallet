#include "DateUsageMethods.h"

int DateUsageMethodes::getYear() {
    cout<<"Podaj rok: ";
    int year=0;
    year=AuxillaryMethodes::loadNumber();
    return year;
}

int DateUsageMethodes::getMonth() {
    cout<<"Podaj miesiac: ";
    int month=0;
    month=AuxillaryMethodes::loadNumber();
    return month;
}

int DateUsageMethodes::getDay() {
    cout<<"Podaj dzien: ";
    int day=0;
    day=AuxillaryMethodes::loadNumber();
    return day;
}

int DateUsageMethodes::getCurrentYear() {
    time_t now =time(&now);
    struct tm*dt =localtime(&now);
    int currentYear =(dt->tm_year+1900);
    return currentYear;
}

int DateUsageMethodes::getCurrentMonth() {
    time_t now =time(&now);
    struct tm*dt =localtime(&now);
    int currentMonth=(dt->tm_mon+1);
    return currentMonth;
}

int DateUsageMethodes::getCurrentDay() {
    time_t now =time(&now);
    struct tm*dt =localtime(&now);
    int currentDay =(dt->tm_mday);
    return currentDay;
}

string DateUsageMethodes::changeYearToString(int year) {
    string yearAsString = AuxillaryMethodes::convertIntToString(year);
    return yearAsString;
}

string DateUsageMethodes::changeMonthToString(int month) {
    string monthAsString = AuxillaryMethodes::convertIntToString(month);
    if(monthAsString.size()<2)
        monthAsString.insert(0,"0");
    return monthAsString;
}

string DateUsageMethodes::changeDayToString(int day) {
    string dayAsString = AuxillaryMethodes::convertIntToString(day);
    if(dayAsString.size()<2)
        dayAsString.insert(0,"0");
    return dayAsString;
}

string DateUsageMethodes::changeDateToString(int year,int month,int day) {
    string dateAsString="";
    string yearAsString=changeYearToString(year);
    string monthAsString = changeMonthToString(month);
    string dayAsString = changeDayToString(day);
    dateAsString=yearAsString+monthAsString+dayAsString;
    return dateAsString;
}

int DateUsageMethodes::changeDateToInt(string date) {
    int dateAsInt=0;
    dateAsInt=AuxillaryMethodes::convertStringToInt(date);
    return dateAsInt;
}

bool DateUsageMethodes::checkEarlierDate(int firstDate, int secondDate) {
    if(firstDate<secondDate)
        cout<<"First Date is earlier."<<endl;
    else
        cout<<"Second Date is earlier "<<endl;
}
