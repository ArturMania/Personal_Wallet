#include "YourWallet.h"

//USER
int YourWallet::getLoggedUserID() {
    userManager.getIdOfLoggedInUser();
}

void YourWallet::userRegistration() {
    userManager.userRegistration();
}

void YourWallet::userLogin() {
    userManager.userLogIn();
    if(userManager.getIdOfLoggedInUser()>0){
        incomeManager = new IncomesManager(FILE_WITH_INCOMES,userManager.getIdOfLoggedInUser());
        expenseManager = new ExpensesManager(FILE_WITH_EXPENSES,userManager.getIdOfLoggedInUser());
    }
}

void YourWallet::userLogout() {
    userManager.userLogout();
    delete incomeManager;
    incomeManager=NULL;
    delete expenseManager;
    expenseManager=NULL;
}

void YourWallet::passwordChange() {
    userManager.loggedUserPasswordChange();
}

//INCOMES AND EXPENSES

void YourWallet::addIncome() {
    if(userManager.getIdOfLoggedInUser()>0)
        incomeManager -> addNewIncome();
}

void YourWallet::addExpense() {
    if(userManager.getIdOfLoggedInUser()>0)
        expenseManager->addNewExpense();
}

void YourWallet::displayBalanceOfCurrentMonth() {
    system("cls");
    int startDate=dateUsageMethodes.getFirstDayOfCurrentMonth();
    int endDate=dateUsageMethodes.getCurrentDate();
    float incomeSum = incomeManager->sumOfIncomes(startDate,endDate);
    float expenseSum = expenseManager->sumOfExpenses(startDate,endDate);
    cout<<"==============INCOMES=============="<<endl;
    incomeManager->dispalyIncomes(startDate,endDate);
    cout<<"==============EXPENSES============="<<endl;
    expenseManager->dispalyExpenses(startDate,endDate);
    float Sum=incomeSum-expenseSum;
    cout<<"==================================="<<endl;
    cout<<"Overall Balance for this month is: "<<Sum<<endl;
    system("pause");
}

void YourWallet::displayBalancePreviousMonth() {
    system("cls");
    int startDate=dateUsageMethodes.getLastDayOfPreviousMonth();
    int endDate=dateUsageMethodes.getFirstDayOfPreviousMonth();
    float incomeSum = incomeManager->sumOfIncomes(startDate,endDate);
    float expenseSum = expenseManager->sumOfExpenses(startDate,endDate);
    cout<<"==============INCOMES=============="<<endl;
    incomeManager->dispalyIncomes(startDate,endDate);
    cout<<"==============EXPENSES============="<<endl;
    expenseManager->dispalyExpenses(startDate,endDate);
    float Sum=incomeSum-expenseSum;
    cout<<"==================================="<<endl;
    cout<<"Overall Balance for this month is: "<<Sum<<endl;
    system("pause");
}

void YourWallet::displayBalanceOfSelectedPeriod() {
    system("cls");
    cout<<"Type the start date for balance sheet in yyyy-mm-dd format: "<<endl;
    string startDay=dateUsageMethodes.changeDateWithDashesToString(AuxillaryMethodes::loadLine());
    cout<<"Type the end date for balance sheet in yyyy-mm-dd format: "<<endl;
    string endDay=dateUsageMethodes.changeDateWithDashesToString(AuxillaryMethodes::loadLine());
    int startDate=dateUsageMethodes.changeDateToInt(startDay);
    int endDate=dateUsageMethodes.changeDateToInt(endDay);
    float incomeSum = incomeManager->sumOfIncomes(startDate,endDate);
    float expenseSum = expenseManager->sumOfExpenses(startDate,endDate);
    cout<<"==============INCOMES=============="<<endl;
    incomeManager->dispalyIncomes(startDate,endDate);
    cout<<"==============EXPENSES============="<<endl;
    expenseManager->dispalyExpenses(startDate,endDate);
    float Sum=incomeSum-expenseSum;
    cout<<"==================================="<<endl;
    cout<<"Overall Balance for this period is: "<<Sum<<endl;
    system("pause");

}

//FW
