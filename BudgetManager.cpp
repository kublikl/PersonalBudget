#include "BudgetManager.h"



using namespace std;

void BudgetManager::addIncome(int idLoggedUser)
{
    Income income;

    income.setIncomeId(fileWithIncomesXML.establishNewIncomeIdFromFile());
    income.setUserId(idLoggedUser);

    string date = "";

    bool flag = true;
    while (flag)
    {
        cout << "Income from today? y / n" << endl;
        char choice = AuxillaryMethods::loadCharacter();
        switch(choice)
        {
        case 'y':
            flag = false;
            date = OperationOnDates::getTodaysDate();
            income.setDate(date);
            break;
        case 'n':
            flag = false;
            date = OperationOnDates::loadAndCheckDate();
            income.setDate(date);
            break;
        default:
            cout << endl << "There is no option like this." << endl << endl;
            system("pause");
            break;
        }
    }

    string typeOfIncome = "";
    cout<< "What kind of income is this?" << endl;

    typeOfIncome = AuxillaryMethods::loadLine();
    income.setTypeOfIncome(typeOfIncome);

    string amountString = "";
    cout<< "How many is that?" << endl;

    cin >> amountString;
    amountString = AuxillaryMethods::checkComma(amountString);
    float amount = stof(amountString);
    income.setAmount(amount);

    incomes.push_back(income);
    fileWithIncomesXML.addIncomeToFile(income);

    cout << endl << "Your income is added successfully!" << endl << endl;
    system("pause");
}

void BudgetManager::addExpense(int idLoggedUser)
{
    Expense expense;

    expense.setExpenseId(fileWithExpensesXML.establishNewExpenseIdFromFile());
    expense.setUserId(idLoggedUser);

    string date = "";
    bool flag = true;

    while (flag)
    {
        cout << "Expense from today? y / n" << endl;
        char choice = AuxillaryMethods::loadCharacter();
        switch(choice)
        {
        case 'y':
            flag = false;
            date = OperationOnDates::getTodaysDate();
            expense.setDate(date);
            break;
        case 'n':
            flag = false;
            date = OperationOnDates::loadAndCheckDate();
            expense.setDate(date);
            break;
        default:
            cout << endl << "There is no option like this." << endl << endl;
            system("pause");
            break;
        }
    }

    string typeOfExpense = "";
    cout<< "What kind of expense is this?" << endl;

    typeOfExpense = AuxillaryMethods::loadLine();
    expense.setTypeOfExpense(typeOfExpense);

    string amountString = "";
    cout<< "How many is that?" << endl;

    amountString = AuxillaryMethods::loadLine();

    amountString = AuxillaryMethods::checkComma(amountString);
    float amount = stof(amountString);
    expense.setAmount(amount);

    fileWithExpensesXML.addExpenseToFile(expense);
    expenses.push_back(expense);

    cout << endl << "Your expense is added successfully!" << endl << endl;
    system("pause");


}


bool compareIncomes(Income date1, Income date2)
{

}

bool compareExpenses(Expense date1, Expense date2)
{

}

void BudgetManager::showBalanceFromCurrentMonth()
{

}

void BudgetManager::showBalanceFromPreviousMonth()
{

}

void BudgetManager::showBalanceFromSelectedPeriod()
{

}
