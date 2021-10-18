#include "FileWithIncomes.h"

string FileWithIncomes::getNameOfFileWithIncomes() {
    return FILE_WITH_INCOMES;
}

void FileWithIncomes::addIncomeToFile(Income income) {
    CMarkup xml;
    bool fileExists = xml.Load(getNameOfFileWithIncomes());
    if(!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }
    xml.FindElem("Incomes");
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("IncomeId",income.getIncomeId());
    xml.AddElem("UserId",income.getUserId());
    xml.AddElem("IncomeDate",income.getDate());
    xml.AddElem("IncomeName",income.getIncomeName());
    xml.AddElem("IncomeValue",income.getIncomeValue());

    xml.Save(getNameOfFileWithIncomes());
}

vector<Income>FileWithIncomes::loadIncomesFromFile() {
    CMarkup xml;
    Income income;
    vector<Income>incomes;
    bool fileExists = xml.Load(getNameOfFileWithIncomes());
    if(fileExists) {
        xml.FindElem("Incomes");
        xml.IntoElem();
        while(xml.FindElem("Income")) {
            xml.IntoElem();
            xml.FindElem("IncomeId");
            income.setIncomeId(atoi(xml.GetData().c_str()));
            xml.FindElem("UserId");
            income.setUserId(atoi(xml.GetData().c_str()));
            xml.FindElem("IncomeDate");
            income.setDate(atoi(xml.GetData().c_str()));
            xml.FindElem("IncomeName");
            income.setIncomeName(xml.GetData());
            xml.FindElem("IncomeValue");
            income.setIncomeValue(atof(xml.GetData().c_str()));
            incomes.push_back(income);

        }
    }
    return incomes;
}
