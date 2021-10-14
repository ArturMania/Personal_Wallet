#include <iostream>
#include "DateUsageMethods.h"
#include "UserManager.h"

using namespace std;

int main() {
    DateUsageMethodes data;
    UserManager userManager("Users.xml");


    userManager.userRegistration();
    userManager.userLogIn();





    /*string date="",date2="";
    cout<<"Write down date in this format: yyyy-mm-dd "<<endl;
    string dateDashedString=AuxillaryMethodes::loadLine();
    //string dateDashedString="1993-04-11";
    cout<<dateDashedString<<endl<<endl;
    date=data.changeDateWithDashesToString(dateDashedString);
    cout<<endl<<date<<endl;

    int dateInt=0,dateInt2=0;
    /*int year =data.getYear();
    int month =data.getMonth();
    int day = data.getDay();
    date=data.changeDateToString(year,month,day);*/
    /*dateInt=data.changeDateToInt(date);
    int cyear=data.getCurrentYear();
    int cmonth=data.getCurrentMonth();
    int cday=data.getCurrentDay();
    date2=data.changeDateToString(cyear,cmonth,cday);
    dateInt2=data.changeDateToInt(date2);
    //int days = data.howManyDaysHaveMonth(month,year);


    //cout<<"Your date: "<<year<<"."<<month<<"."<<day<<endl;
    //cout<<"Today is: "<<cyear<<"."<<cmonth<<"."<<cday<<endl;
    //cout<<"Number od days in month: "<<days<<endl;
    //cout<<date<<endl;
    //cout<<date2<<endl;
    //cout<<dateInt<<endl;
    //data.checkEarlierDate(dateInt,dateInt2);*/

    return 0;
}


