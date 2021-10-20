#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

using namespace std;

class Expense{
    int expenseId;
    int userId;
    int expenseDate;
    string expenseName;
    float expenseValue;

public:

    void setExpenseId(int newId);
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setExpenseName(string newName);
    void setExpenseValue(float newValue);

    int getExpenseId();
    int getUserId();
    int getDate();
    string getExpenseName();
    float getExpenseValue();
};
#endif
