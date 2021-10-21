#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

#include "Expense.h"
#include "AuxillaryMethodes.h"
#include "Markup.h"

using namespace std;

class FileWithExpenses {
    int lastExpenseId;
    vector<Expense>expenses;
    const string FILE_WITH_EXPENSES;
    string getNameOfFileWithExpenses();

public:
    FileWithExpenses(string nameOfFileWithExpenses)
        :FILE_WITH_EXPENSES(nameOfFileWithExpenses) {
            lastExpenseId=0;
    };
    void addExpenseToFile(Expense expense);
    vector<Expense> loadExpensesFromFile(int loggedUserId);
    int getLastExpenseId();

};
#endif

//FW
