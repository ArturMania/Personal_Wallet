#include "ExpensesManager.h"

Expense ExpensesManager::addNewExpense() {
    Expense expense;
    string expenseValue;
    string dateInput;
    float numberValue;
    char selection;

    expense.setUserId(LOGGED_USER_ID);
    expense.setExpenseId(fileWithExpenses.getLastExpenseId()+1);
    cout<<"Source of expense: ";
    expense.setExpenseName(AuxillaryMethodes::loadLine());
    cout<<"Value of expense: ";
    expenseValue=AuxillaryMethodes::loadLine();
    expenseValue=AuxillaryMethodes::replaceCommaWithDot(expenseValue);
    numberValue=atof(expenseValue.c_str());
    expense.setExpenseValue(numberValue);
    cout<<"_____________Choose date of income_____________"<<endl;
    cout<<"Press 't' if today or 'any key' to enter date: "<<endl;
    selection=AuxillaryMethodes::loadChar();
    if(selection=='t') {
        expense.setDate(dateUsageMethodes.getCurrentDate());
    } else {
        cout<<"Type date in yyyy-mm-dd format: "<<endl;
        dateInput=AuxillaryMethodes::loadLine();
        dateInput=dateUsageMethodes.changeDateWithDashesToString(dateInput);
        expense.setDate(dateUsageMethodes.changeDateToInt(dateInput));
    }
    return expense;
}

void ExpensesManager::addExpense() {
    system ("cls");
    Expense expense;
    expense=addNewExpense();
    expenses.push_back(expense);
    fileWithExpenses.addExpenseToFile(expense);
    system("pause");
}

float ExpensesManager::sumOfExpenses(int startDate, int endDate) {
    float expenseSum=0;

    for (int i=0; i<expenses.size(); i++) {
        if(expenses[i].getUserId()==LOGGED_USER_ID) {
            if((expenses[i].getDate()>=startDate)&&(expenses[i].getDate()<=endDate)) {
                expenseSum+=expenses[i].getExpenseValue();
            }
        }
    }
    return expenseSum;
}

void ExpensesManager::dispalyExpenses(int startDate, int endDate) {
    vector<Expense>selectedExpenses;
    for (int i=0; i<expenses.size(); i++) {
        if(expenses[i].getUserId()==LOGGED_USER_ID) {
            if((expenses[i].getDate()>=startDate)&&(expenses[i].getDate()<=endDate)) {
                selectedExpenses.push_back(expenses[i]);
            }
        }
    }
    for(int i=0; i<selectedExpenses.size(); i++) {
        cout<<"Date: "<<dateUsageMethodes.changeIntDateToDateWithDashes(selectedExpenses[i].getDate())<<endl;
        cout<<"Income source: "<<selectedExpenses[i].getExpenseName()<<endl;
        cout<<"Income value: "<<selectedExpenses[i].getExpenseValue()<<endl<<endl;
    }
    selectedExpenses.clear();
}
