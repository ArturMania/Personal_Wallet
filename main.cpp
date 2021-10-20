#include <iostream>
#include "DateUsageMethods.h"
#include "UserManager.h"
#include "IncomesManager.h"
#include "FileWithIncomes.h"
#include "FileWithExpenses.h"
#include "ExpensesManager.h"


using namespace std;

int main() {

    DateUsageMethodes data;
    FileWithIncomes file("Incomes.xml");
    UserManager userManager("Users.xml");
    IncomesManager incomeManager("Incomes.xml",1);
    ExpensesManager expense("Expenses.xml",1);
    int day1=20211021,day2=20210901;
    int sum=0;


    //expense.addExpense();
    //expense.addExpense();
    //sum=expense.sumOfExpenses(day2,day1);
    //expense.dispalyExpenses(day2,day1);
    //cout<<sum<<endl;


    //file.loadIncomesFromFile(1);
    //int id=0;
    //id=file.getLastIncomeId();
    //cout<<id;

    //incomeManager.addIncome();
    //incomeManager.addIncome();

    float sum2=  incomeManager.sumOfIncomes(day2,day1);
    cout<<sum2<<endl;
    incomeManager.dispalyIncomes(day2,day1);



    //userManager.userRegistration();
    //userManager.userLogIn();
    //userManager.loggedUserPasswordChange();





    return 0;
}


