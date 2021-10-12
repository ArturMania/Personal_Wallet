#include <iostream>
#include "DateUsageMethods.h"
using namespace std;

int main() {
    DateUsageMethodes data;
    int year =data.getYear();
    int month =data.getMonth();
    int day = data.getDay();

    cout << "Hello world!" << endl;
    cout<<"Your date: "<<year<<"."<<month<<"."<<day<<endl;
    return 0;
}
