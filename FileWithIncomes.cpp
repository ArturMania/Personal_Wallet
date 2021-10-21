#include "FileWithIncomes.h"

string FileWithIncomes::getNameOfFileWithIncomes() {
    return FILE_WITH_INCOMES;
}

int FileWithIncomes::getLastIncomeId() {
    return lastIncomeId;
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
    xml.AddElem("IncomeValue",AuxillaryMethodes::convertFloatToString(income.getIncomeValue()));

    xml.Save(getNameOfFileWithIncomes());
    lastIncomeId++;
}

vector<Income>FileWithIncomes::loadIncomesFromFile(int loggedUserId) {
    CMarkup xml;
    Income income;
    vector<Income>incomes;
    int userId=0;
    bool fileExists = xml.Load(getNameOfFileWithIncomes());
    if(fileExists) {
        xml.FindElem("Incomes");
        xml.IntoElem();
        while(xml.FindElem("Income")) {
            xml.IntoElem();
            xml.FindElem("UserId");
            userId=atoi(xml.GetData().c_str());
            if(userId==loggedUserId) {
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
            xml.OutOfElem();
            lastIncomeId++;
        }
    }
    return incomes;
}

//FW
