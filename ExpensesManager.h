#ifndef EXPENSESMANAGER_H
#define EXPENSESMANAGER_H

#include <iostream>
#include <vector>
#include <math.h>

#include "DateUsageMethods.h"
#include "FileWithExpenses.h"
#include "Expense.h"

using namespace std;

class ExpensesManager {
    int const LOGGED_USER_ID;
    FileWithExpenses fileWithExpenses;
    DateUsageMethodes dateUsageMethodes;
    vector<Expense>expenses;

public:
    ExpensesManager(string nameOfFileWithExpenses, int loggedUserId):
        fileWithExpenses(nameOfFileWithExpenses),LOGGED_USER_ID(loggedUserId){
        expenses=fileWithExpenses.loadExpensesFromFile(LOGGED_USER_ID);
        };
    //void addExpense();
    float sumOfExpenses(int startDate,int endDate);
    void dispalyExpenses(int startDate, int endDate);
    void addNewExpense();

};
#endif

//FW
