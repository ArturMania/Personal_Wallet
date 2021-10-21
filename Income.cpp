#include "Income.h"

void Income::setIncomeId(int newId) {
    if(newId>=0)
        incomeId=newId;
}
void Income::setUserId(int newUserId) {
    userId=newUserId;
}
void Income::setDate(int newDate) {
    incomeDate=newDate;
}

void Income::setIncomeName(string newName) {
    incomeName=newName;
}

void Income::setIncomeValue(float newValue) {
    incomeValue=newValue;
}

int Income::getIncomeId() {
    return incomeId;
}
int Income::getUserId() {
    return userId;
}
int Income::getDate() {
    return incomeDate;
}

string Income::getIncomeName() {
    return incomeName;
}

float Income::getIncomeValue() {
    return incomeValue;
}

//FW
