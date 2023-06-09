#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>
#include <algorithm> //for sort
#include <windows.h>

#include "Income.h"
#include "Expense.h"
#include "AuxillaryMethods.h"
#include "OperationOnDates.h"
#include "FileWithIncomesXML.h"
#include "FileWithExpensesXML.h"

using namespace std;

class BudgetManager
{

    const int ID_OF_LOGGED_USER;
    int idLoggedUser;
    vector <Income> incomes;
    vector <Expense> expenses;
    FileWithIncomesXML fileWithIncomesXML;
    FileWithExpensesXML fileWithExpensesXML;

public:
    BudgetManager(int idLoggedUser) : ID_OF_LOGGED_USER(idLoggedUser)
    {
        incomes = fileWithIncomesXML.loadIncomesFromFile(ID_OF_LOGGED_USER);
    };

    void addIncome(int idLoggedUser);
    void addExpense(int idLoggedUser);
    void showBalanceFromCurrentMonth();
    void showBalanceFromPreviousMonth();
    void showBalanceFromSelectedPeriod();
};


#endif
