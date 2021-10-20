#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income {
    int incomeId;
    int userId;
    int incomeDate;
    string incomeName;
    float incomeValue;

public:

    void setIncomeId(int newId);
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setIncomeName(string newName);
    void setIncomeValue(float newValue);

    int getIncomeId();
    int getUserId();
    int getDate();
    string getIncomeName();
    float getIncomeValue();
};
#endif
