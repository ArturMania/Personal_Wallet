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

}

int DateUsageMethodes::getCurrentMonth() {

}

int DateUsageMethodes::getCurrentDay() {

}
