#include "FileWithExpenses.h"

string FileWithExpenses::getNameOfFileWithExpenses() {
    return FILE_WITH_EXPENSES;
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
    xml.AddElem("ExpenseValue",expense.getExpenseValue());

    xml.Save(getNameOfFileWithExpenses());
}

vector<Expense>FileWithExpenses::loadExpensesFromFile() {
    CMarkup xml;
    Expense expense;
    vector<Expense>expenses;
    bool fileExists = xml.Load(getNameOfFileWithExpenses());
    if(fileExists) {
        xml.FindElem("Expenses");
        xml.IntoElem();
        while(xml.FindElem("Expense")) {
            xml.IntoElem();
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
    }
    return expenses;
}
