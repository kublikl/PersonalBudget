#include <iostream>
#include "PersonalBudget.h"

using namespace std;

int main()
{
    PersonalBudget personalBudget;

    while (true)
    {
        if (!personalBudget.isUserLoggedIn())
        {
            char choice = personalBudget.chooseFromMainMenu();
            switch (choice)
            {
            case '1':
                personalBudget.registrationOfUser();
                break;
            case '2':
                personalBudget.logIn();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Selected option doesn't exist." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            char choice = personalBudget.chooseFromUserMenu();

            switch (choice)
            {
            case '1':
                personalBudget.addIncome();
                break;
            case '2':
                personalBudget.addExpense();
                break;
            case '3':
                personalBudget.showBalanceFromCurrentMonth();
                break;
            case '4':
                personalBudget.showBalanceFromPreviousMonth();
                break;
            case '5':
                personalBudget.showBalanceFromSelectedPeriod();
                break;
            case '6':
                personalBudget.changePassword();
                break;
            case '7':
                personalBudget.logOut();
                break;
            }
        }
    }
    return 0;
}

