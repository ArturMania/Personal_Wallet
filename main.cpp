#include <iostream>

#include "YourWallet.h"

using namespace std;

int main() {
    YourWallet yourWallet("Users.xml","Incomes.xml","Expenses.xml");
    char choice;
    int loggedUserId=0;


    return 0;
}



















































/* TESTY
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
    */
