#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

#include "Income.h"
#include "AuxillaryMethodes.h"
#include "DateUsageMethods.h"
#include "UserManager.h"
#include "Markup.h"

using namespace std;

class FileWithIncomes {
    vector<Income>incomes;
    const string FILE_WITH_INCOMES;
    string getNameOfFileWithIncomes();
public:
    FileWithIncomes(string nameOfFileWithIncomes)
        :FILE_WITH_INCOMES(nameOfFileWithIncomes) {
    };
    void addIncomeToFile(Income income);
    vector<Income> loadIncomesFromFile();
    int getLastIncomeId();

};
#endif
