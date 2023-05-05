#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>

#include "UserManager.h"
#include "BudgetManager.h"

using namespace std;


class PersonalBudget
{
    int idLoggedUser = 0;
    UserManager userManager;
    BudgetManager *budgetManager;

public:
    PersonalBudget()
    {
        budgetManager = NULL;
    };
    ~PersonalBudget()
    {
        delete budgetManager;
        budgetManager = NULL;
    };

    void registrationOfUser();
    void logIn();
    bool isUserLoggedIn();
    char chooseFromMainMenu();
    char chooseFromUserMenu();
    void addIncome();
    void addExpense();
    void showBalanceFromCurrentMonth();
    void showBalanceFromPreviousMonth();
    void showBalanceFromSelectedPeriod();
    void changePassword();
    void logOut();

};


#endif
