#include "Expense.h"

void Expense::setExpenseId(int newId) {
    if(newId>=0)
        expenseId=newId;
}
void Expense::setUserId(int newUserId) {
    userId=newUserId;
}
void Expense::setDate(int newDate) {
    expenseDate=newDate;
}

void Expense::setExpenseName(string newName) {
    expenseName=newName;
}

void Expense::setExpenseValue(float newValue) {
    expenseValue=newValue;
}

int Expense::getExpenseId() {
    return expenseId;
}
int Expense::getUserId() {
    return userId;
}
int Expense::getDate() {
    return expenseDate;
}

string Expense::getExpenseName() {
    return expenseName;
}

float Expense::getExpenseValue() {
    return expenseValue;
}
