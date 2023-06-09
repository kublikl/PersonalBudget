#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

using namespace std;

class Expense
{
    float amount;
    int dateInt;
    string date;
    string typeOfExpense;
    int expenseId;
    int userId;
public:
    Expense ()
    {

    }
    void setAmount(float newAmount);
    void setDate(string newDate);
    void setTypeOfExpense(string newTypeOfExpense);
    void setExpenseId(int newExpenseId);
    void setUserId(int newUserId);
    void setDateInt(int newDateInt);

    float getAmount();
    string getDate();
    string getTypeOfExpense();
    int getExpenseId();
    int getUserId();
    int getDateInt();
};

#endif
