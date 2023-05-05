#include "PersonalBudget.h"

using namespace std;

void PersonalBudget::registrationOfUser()
{
     userManager.registrationOfUser();
}

void PersonalBudget::logIn()
{
    idLoggedUser = userManager.logIn();
    if (userManager.isUserLoggedIn())
    {
        budgetManager = new BudgetManager(idLoggedUser); //creating object of class BudgetManager when logged in (also loading incomes and expenses!!)
    }
}

bool PersonalBudget::isUserLoggedIn()
{
    userManager.isUserLoggedIn();
}

char PersonalBudget::chooseFromMainMenu()
{
    userManager.chooseFromMainMenu();
}

char PersonalBudget::chooseFromUserMenu()
{
    userManager.chooseFromUserMenu();
}

void PersonalBudget::addIncome()
{
    budgetManager -> addIncome(idLoggedUser);
}

void PersonalBudget::addExpense()
{
    budgetManager -> addExpense(idLoggedUser);
}

void PersonalBudget::showBalanceFromCurrentMonth()
{
    budgetManager -> showBalanceFromCurrentMonth();
}

void PersonalBudget::showBalanceFromPreviousMonth()
{
    budgetManager -> showBalanceFromPreviousMonth();
}

void PersonalBudget::showBalanceFromSelectedPeriod()
{
    budgetManager -> showBalanceFromSelectedPeriod();
}

void PersonalBudget::changePassword()
{
    userManager.changePassword();
}

void PersonalBudget::logOut()
{
    userManager.logOut();
    delete budgetManager;
    budgetManager = NULL;
}
