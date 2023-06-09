#ifndef FILEWITHINCOMESXML_H
#define FILEWITHINCOMESXML_H

#include <iostream>
#include <vector>

#include "Income.h"
#include "Markup.h"
#include "AuxillaryMethods.h"

using namespace std;

class FileWithIncomesXML
{


public:
    void addIncomeToFile(Income income);
    vector <Income> loadIncomesFromFile(int idLoggedUser);
    int establishNewIncomeIdFromFile();


};


#endif
