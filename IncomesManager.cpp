#include "IncomesManager.h"

Income IncomesManager::addNewIncome() {
    Income income;
    string incomeValue;
    string dateInput;
    float numberValue;
    char selection;

    income.setUserId(LOGGED_USER_ID);
    income.setIncomeId(fileWithIncomes.getLastIncomeId()+1);
    cout<<"Source of income: ";
    income.setIncomeName(AuxillaryMethodes::loadLine());
    cout<<"Value of income: ";
    incomeValue=AuxillaryMethodes::loadLine();
    incomeValue=AuxillaryMethodes::replaceCommaWithDot(incomeValue);
    numberValue=atof(incomeValue.c_str());
    income.setIncomeValue(numberValue);
    cout<<"_____________Choose date of income_____________"<<endl;
    cout<<"Press 't' if today or 'any key' to enter date: "<<endl;
    selection=AuxillaryMethodes::loadChar();
    if(selection=='t') {
        income.setDate(dateUsageMethodes.getCurrentDate());
    } else {
        cout<<"Type date in yyyy-mm-dd format: "<<endl;
        dateInput=AuxillaryMethodes::loadLine();
        dateInput=dateUsageMethodes.changeDateWithDashesToString(dateInput);
        income.setDate(dateUsageMethodes.changeDateToInt(dateInput));
    }
    return income;
}

void IncomesManager::addIncome() {
    system ("cls");
    Income income;
    income=addNewIncome();
    incomes.push_back(income);
    fileWithIncomes.addIncomeToFile(income);
    system("pause");
}

float IncomesManager::sumOfIncomes(int startDate, int endDate) {
    float incomeSum=0;

    for (int i=0; i<incomes.size(); i++) {
        if(incomes[i].getUserId()==LOGGED_USER_ID) {
            if((incomes[i].getDate()>=startDate)&&(incomes[i].getDate()<=endDate)) {
                incomeSum+=incomes[i].getIncomeValue();
            }
        }
    }
    return incomeSum;
}

void IncomesManager::dispalyIncomes(int startDate, int endDate) {
    vector<Income>selectedIncomes;
    for (int i=0; i<incomes.size(); i++) {
        if(incomes[i].getUserId()==LOGGED_USER_ID) {
            if((incomes[i].getDate()>=startDate)&&(incomes[i].getDate()<=endDate)) {
                selectedIncomes.push_back(incomes[i]);
            }
        }
    }
    for(int i=0; i<selectedIncomes.size(); i++) {
        cout<<"Date: "<<dateUsageMethodes.changeIntDateToDateWithDashes(selectedIncomes[i].getDate())<<endl;
        cout<<"Income source: "<<selectedIncomes[i].getIncomeName()<<endl;
        cout<<"Income value: "<<selectedIncomes[i].getIncomeValue()<<endl<<endl;
    }
    selectedIncomes.clear();
}
