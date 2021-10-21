#ifndef INCOMESMANAGER_H
#define INCOMESMANAGER_H

#include <iostream>
#include <vector>
#include <math.h>

#include "DateUsageMethods.h"
#include "FileWithIncomes.h"
#include "Income.h"

using namespace std;

class IncomesManager {
    int const LOGGED_USER_ID;
    FileWithIncomes fileWithIncomes;
    DateUsageMethodes dateUsageMethodes;
    vector<Income>incomes;

public:
    IncomesManager(string nameOfFileWithIncomes, int loggedUserId):
        fileWithIncomes(nameOfFileWithIncomes),LOGGED_USER_ID(loggedUserId){
        incomes=fileWithIncomes.loadIncomesFromFile(LOGGED_USER_ID);
        };
    //void addIncome();
    float sumOfIncomes(int startDate,int endDate);
    void dispalyIncomes(int startDate, int endDate);
    void addNewIncome();

};
#endif

//FW
