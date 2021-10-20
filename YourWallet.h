#ifndef YOURWALLET_H
#define YOURWALLET_H

#include <iostream>

#include "UserManager.h"
#include "IncomesManager.h"
#include "ExpensesManager.h"
#include "DateUsageMethods.h"


class YourWallet {
    DateUsageMethodes dateUsageMethodes;
    UserManager userManager;
    IncomesManager *incomeManager;
    ExpensesManager *expenseManager;
    const string FILE_WITH_INCOMES;
    const string FILE_WITH_EXPENSES;
public:
    YourWallet(string fileWithUsers,string fileWithIncomesName, string fileWithExpensesName):
        userManager(fileWithUsers),FILE_WITH_INCOMES(fileWithIncomesName),FILE_WITH_EXPENSES(fileWithExpensesName) {
        incomeManager=NULL;
        expenseManager=NULL;
    };
    ~YourWallet(){
        delete incomeManager;
        incomeManager=NULL;
        delete expenseManager;
        expenseManager=NULL;
    };

    int getLoggedUserID();
    void userRegistration();
    void userLogin();
    void passwordChange();
    void userLogout();
    void addIncome();
    void addExpense();
    void displayBalanceOfCurrentMonth();
    void displayBalancePreviousMonth();
    void displayBalanceOfSelectedPeriod();
};
#endif // YOURWALLET_H
