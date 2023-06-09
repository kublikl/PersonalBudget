#include <iostream>
#include <windows.h>
#include "UserManager.h"

using namespace std;

void UserManager::registrationOfUser()
{
    User user = typeDataOfNewUser();

    users.push_back(user);

    fileWithUsersXML.addUserToFile(user);

    cout << endl << "Your account is created successfully!" << endl << endl;
    Sleep(500);
}


User UserManager::typeDataOfNewUser()
{
    User user;

    user.setId(establishNewUserID());

    string login;
    do
    {
        cout << endl << "Enter login: ";
        login = AuxillaryMethods::loadLine();
        user.setLogin(login);
    }
    while (isLoginExist(user.getLogin()) == true);

    string name;
    cout << "Enter your name: ";
    name = AuxillaryMethods::loadLine();
    name = AuxillaryMethods::changeFirstLetterToCapitalAndOthersToLower(name);


    string lastName;
    cout << "Enter your last name: ";
    lastName = AuxillaryMethods::loadLine();
    lastName = AuxillaryMethods::changeFirstLetterToCapitalAndOthersToLower(lastName);

    string password;
    cout << "Enter password: ";
    cin >> password;


    user.setName(name);
    user.setLastName(lastName);
    user.setPassword(password);

    return user;

}

int UserManager::establishNewUserID()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::isLoginExist(string login)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            cout << endl << "User with this login already exist." << endl;
            return true;
        }
    }
    return false;
}

char UserManager::chooseFromMainMenu()
{
    char choice;

    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Registration" << endl;
    cout << "2. Login" << endl;
    cout << "9. End of work" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxillaryMethods::loadCharacter();

    return choice;
}

char UserManager::chooseFromUserMenu()
{
    char choice;

    system("cls");
    cout << "    >>> PERSONAL BUDGET <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Balance from current month" << endl;
    cout << "4. Balance from previous month" << endl;
    cout << "5. Balance from selected time period" << endl;
    cout << "6. Change password" << endl;
    cout << "7. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxillaryMethods::loadCharacter();

    return choice;
}

int UserManager::logIn()
{
    User user;
    string login = "", password = "";

    cout << endl << "Type your login: ";
    login = AuxillaryMethods::loadLine();

    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            for (int attempts = 3; attempts > 0; attempts--)
            {
                cout << "Enter password. Attempts left: " << attempts << ": ";
                password = AuxillaryMethods::loadLine();

                if (users[i].getPassword() == password)
                {
                    cout << endl << "You are logged in." << endl << endl;
                    Sleep(800);
                    idLoggedUser = users[i].getId();
                    return idLoggedUser;
                }
            }
            cout << "Password was entered incorrecty 3 times!" << endl;
            system("pause");

            return 0;
        }
    }
    cout << "User with this login doesn't exist" << endl << endl;
    system("pause");
    return 0;
}

bool UserManager::isUserLoggedIn()
{
    if (idLoggedUser > 0)
        return true;
    else
        return false;
}

void UserManager::changePassword()
{
    string newPassword = "";
    cout << endl << "Enter new password: ";
    cin >> newPassword;

    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getId() == idLoggedUser)
        {
            users[i].setPassword(newPassword);
            fileWithUsersXML.updatePasswordInFile(users[i]);
            cout << endl << "Password has been changed." << endl << endl;
            system("pause");
        }
    }
}

void UserManager::logOut()
{
    idLoggedUser = 0;
}








