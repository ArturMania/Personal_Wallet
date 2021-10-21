#include "FileWithExpenses.h"

string FileWithExpenses::getNameOfFileWithExpenses() {
    return FILE_WITH_EXPENSES;
}

int FileWithExpenses::getLastExpenseId() {
    return lastExpenseId;
}


void FileWithExpenses::addExpenseToFile(Expense expense) {
    CMarkup xml;
    bool fileExists = xml.Load(getNameOfFileWithExpenses());
    if(!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }
    xml.FindElem("Expenses");
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("ExpenseID",expense.getExpenseId());
    xml.AddElem("UserId",expense.getUserId());
    xml.AddElem("ExpenseDate",expense.getDate());
    xml.AddElem("ExpenseName",expense.getExpenseName());
    xml.AddElem("ExpenseValue",AuxillaryMethodes::convertFloatToString(expense.getExpenseValue()));

    xml.Save(getNameOfFileWithExpenses());
    lastExpenseId++;
}

vector<Expense>FileWithExpenses::loadExpensesFromFile(int loggedUserId) {
    CMarkup xml;
    Expense expense;
    vector<Expense>expenses;
    int userId=0;
    bool fileExists = xml.Load(getNameOfFileWithExpenses());
    if(fileExists) {
        xml.FindElem("Expenses");
        xml.IntoElem();
        while(xml.FindElem("Expense")) {
            xml.IntoElem();
            xml.FindElem("UserId");
            userId=atoi(xml.GetData().c_str());
            if(userId==loggedUserId) {
                xml.FindElem("ExpenseID");
                expense.setExpenseId(atoi(xml.GetData().c_str()));
                xml.FindElem("UserId");
                expense.setUserId(atoi(xml.GetData().c_str()));
                xml.FindElem("ExpenseDate");
                expense.setDate(atoi(xml.GetData().c_str()));
                xml.FindElem("ExpenseName");
                expense.setExpenseName(xml.GetData());
                xml.FindElem("ExpenseValue");
                expense.setExpenseValue(atof(xml.GetData().c_str()));
                expenses.push_back(expense);
            }
            xml.OutOfElem();
            lastExpenseId++;
        }
    }
    return expenses;
}

//FW
