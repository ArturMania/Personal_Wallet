#include <iostream>

#include "YourWallet.h"
#include "UserManager.h"

using namespace std;

int main() {
    YourWallet yourWallet("Users.xml","Incomes.xml","Expenses.xml");
    char choice;
    int loggedUserId=0;
    while(true) {
        if(yourWallet.getLoggedUserID()==0) {
            system("cls");
            cout<<"Welcom to Your Wallet! "<<endl;
            cout<<"Push selected button for: "<<endl;
            cout<<"1. Login"<<endl;
            cout<<"2. User registration"<<endl;
            cout<<"3. Exit "<<endl;
            choice=AuxillaryMethodes::loadChar();
            switch(choice) {
            case '1':
                yourWallet.userLogin();
                break;
            case '2':
                yourWallet.userRegistration();
                break;
            case '3':
                exit(0);
                break;
            }
        } else if (yourWallet.getLoggedUserID()>0) {
            system("cls");
            loggedUserId=yourWallet.getLoggedUserID();
            cout << "================Main Menu================="<<endl;
            cout << "1. Add Income" << endl;
            cout << "2. Add Expense" << endl;
            cout << "3. Balance sheet from current month" << endl;
            cout << "4. Balance sheet from last month" << endl;
            cout << "5. Balance sheet for the selected period" << endl;
            cout << "========================================="<< endl;
            cout << "6. Change password" << endl;
            cout << "9. Log out" << endl;
            cout << "0. Exit program"<<endl;
            cout << "========================================="<< endl;
            choice=AuxillaryMethodes::loadChar();
            switch(choice) {
            case '1':
                yourWallet.addIncome();
                break;
            case '2':
                yourWallet.addExpense();
                break;
            case '3':
                yourWallet.displayBalanceOfCurrentMonth();
                break;
            case '4':
                yourWallet.displayBalancePreviousMonth();
                break;
            case '5':
                yourWallet.displayBalanceOfSelectedPeriod();
                break;
            case '6':
                yourWallet.passwordChange();
                break;
            case '9':
                yourWallet.userLogout();
                break;
            case '0':
                exit(0);
                break;
            }
        }
    }
    return 0;
}



















































/* TESTY FW

#include "DateUsageMethods.h"
#include "UserManager.h"
#include "IncomesManager.h"
#include "FileWithIncomes.h"
#include "FileWithExpenses.h"
#include "ExpensesManager.h"



    DateUsageMethodes data;
    FileWithIncomes file("Incomes.xml");
    UserManager userManager("Users.xml");
    IncomesManager incomeManager("Incomes.xml",1);
    ExpensesManager expense("Expenses.xml",1);
    YourWallet yourWallet("Users.xml","Incomes.xml","Expenses.xml");

    userManager.userLogIn();


    int day1=20211021;
    int day2=20210901;
    incomeManager.sumOfIncomes(day2,day1);
    incomeManager.dispalyIncomes(day2,day1);

    */
