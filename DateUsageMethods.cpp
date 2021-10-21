#include "DateUsageMethods.h"

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

int DateUsageMethodes::getFirstDayOfCurrentMonth() {
    int year=getCurrentYear();
    int month=getCurrentMonth();
    string firstDay="01";
    string firstDayOfCurrentMonth=changeYearToString(year)+changeMonthToString(month)+firstDay;
    int firstDayOfCurrentMonthInt=changeDateToInt(firstDayOfCurrentMonth);
    return firstDayOfCurrentMonthInt;
}

int DateUsageMethodes::getFirstDayOfPreviousMonth() {
    string firstDay="01";
    int year=getCurrentYear();
    int month=getCurrentMonth();
    if(month==1) {
        month=12;
        year=year-1;
    } else
        month--;
    string firstDayOfPreviousMonth=changeYearToString(year)+changeMonthToString(month)+firstDay;
    int firstDayOfPreviousMonthInt=changeDateToInt(firstDayOfPreviousMonth);
    return firstDayOfPreviousMonthInt;
}

int DateUsageMethodes::getLastDayOfPreviousMonth() {
    int lastDay=0;
    int year=getCurrentYear();
    int month=getCurrentMonth();
    if(month==1) {
        month=12;
        year=year-1;
    } else
        month--;
    lastDay=howManyDaysHaveMonth(month,year);
    string lastDayOfPreviousMonth=changeYearToString(year)+changeMonthToString(month)+changeDayToString(lastDay);
    int lastDayOfPreviousMonthInt=changeDateToInt(lastDayOfPreviousMonth);
    return lastDayOfPreviousMonthInt;
}

int DateUsageMethodes::getCurrentDate() {
    int year=getCurrentYear();
    int month=getCurrentMonth();
    int day=getCurrentDay();
    string date=changeDateToString(year,month,day);
    int dateInt=changeDateToInt(date);
    return dateInt;
}

int DateUsageMethodes::howManyDaysHaveMonth(int month,int year) {
    int days=0;
    if((month==4)||(month==6)||(month==9)||(month==11)) {
        days=30;
    } else if(month==2) {
        if(isItLeapYear(year)==true)
            days=29;
        else
            days=28;
    } else {
        days=31;
    }
    return days;
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

string DateUsageMethodes::changeDateWithDashesToString(string dateDashedString) {
    string year="",month="",day="",date="";
    year=dateDashedString.substr(0,4);
    int yearInt=AuxillaryMethodes::convertStringToInt(year);
    month=dateDashedString.substr(5,2);
    int monthInt=AuxillaryMethodes::convertStringToInt(month);
    day=dateDashedString.substr(8,2);
    int dayInt=AuxillaryMethodes::convertStringToInt(day);
    string yearStr=changeYearToString(yearInt);
    string monthStr=changeMonthToString(monthInt);
    string dayStr=changeDayToString(dayInt);
    date=yearStr+monthStr+dayStr;
    return date;
}

string DateUsageMethodes::changeIntDateToDateWithDashes(int dateInt) {
    string dateString=AuxillaryMethodes::convertIntToString(dateInt);
    string yearStr=dateString.substr(0,4);
    string monthStr=dateString.substr(4,2);
    string dayStr=dateString.substr(6,2);
    string dateWithDashes=yearStr+"-"+monthStr+"-"+dayStr;
    return dateWithDashes;
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

bool DateUsageMethodes::isItLeapYear(int year) {
    return((year%4==0 && year%100!=0)||(year%400==0));
}

bool DateUsageMethodes::isYearCorrect(int year) {
    time_t now =time(&now);
    struct tm*dt =localtime(&now);
    int currentYear =(dt->tm_year+1900);
    if((year>=2000)&&(year<=currentYear))
        return year;
    else {
        cout<<"Wrong year input!"<<endl;
        system("pause");
        system ("cls");
        return 0;
    }
}

bool DateUsageMethodes::isMonthCorrect(int month) {
    if((month>=1)&&(month<=12))
        return month;
    else {
        cout<<"Wrong month input!"<<endl;
        system("pause");
        system ("cls");
        return 0;
    }
}

bool DateUsageMethodes::isDayCorrect(int day,int month,int year) {
    if((month==4)||(month==6)||(month==9)||(month==11)) {
        if(day>30) {
            cout<<"Wrong day input!"<<endl;
            system("pause");
            system ("cls");
            return false;
        }
    } else if(month==2) {
        if(isItLeapYear(year)==true) {
            if(day>29) {
                cout<<"Wrong day input!"<<endl;
                system("pause");
                system ("cls");
                return false;
            }
        } else {
            if(day>28) {
                cout<<"Wrong day input!"<<endl;
                system("pause");
                system ("cls");
                return false;
            }
        }
    } else {
        if(day>31) {
            cout<<"Wrong day input!"<<endl;
            system("pause");
            system ("cls");
            return false;
        }
    }
    return true;
}

bool DateUsageMethodes::isDateCorrect(string dateDashedString) {
    string year="",month="",day="",date="";
    year=dateDashedString.substr(0,4);
    int yearInt=AuxillaryMethodes::convertStringToInt(year);
    month=dateDashedString.substr(5,2);
    int monthInt=AuxillaryMethodes::convertStringToInt(month);
    day=dateDashedString.substr(8,2);
    int dayInt=AuxillaryMethodes::convertStringToInt(day);
    if((isYearCorrect(yearInt)==true)&&(isMonthCorrect(monthInt)==true)&&(isDayCorrect(dayInt,monthInt,yearInt)==true)) {
        return true;
    } else
        return false;
}


void DateUsageMethodes::setStartDate(int newStartDate) {
    startDate=newStartDate;
}

void DateUsageMethodes::setEndDate(int newEndDate) {
    endDate=newEndDate;
}

int DateUsageMethodes::getStartDate() {
    return startDate;
}

int DateUsageMethodes::getEndDate() {
    return endDate;
}

//FW
