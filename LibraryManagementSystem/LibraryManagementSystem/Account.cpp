// Account.cpp

#include "Account.h"
#include <iostream>
#include "LibraryManagementSystem.h"

int manageValue;
int deleteIdInput;
int editIdInput;
Account accountManager;
std::string usrinput;
std::string pwdinput;

std::vector<Account::AccountInfo> Account::accountList; // Account List Vector

// CONSTRUCTOR: Constructs the Account Class
Account::Account(const std::string& username, const std::string& password)
    : User() {
    accountList.push_back({ username, password }); // Add the new username and password to the vector
}

bool Account::login(const std::string& inputUsername, const std::string& inputPassword) { // Login Function

	// For each Account in the accountList vector, check if the inputted username and password matches any entries
    for (const auto& account : accountList) {
        if (account.username == inputUsername && account.password == inputPassword) { // Successful Login
            std::cout << "Authentication Successful" << std::endl;
            return true;
        }
    }
	// Unsuccessful Login
    std::cout << "Authentication Failed: Check Username and/or Password" << std::endl;
    return false;
}

void Account::outputAccounts() // Output Accounts Function
{
	std::cout << "Username\tPassword" << std::endl; // Display column headers

	// For each Account in the accountList vector, output the username and password
	for (const auto& account : accountList) {
		std::cout << account.username << "\t" << account.password << std::endl;
	}
	LibraryManagementSystem::mainMenu(); // Show main menu
}

void Account::addUser(const std::string& username, const std::string& password) { // Add User Function
	accountList.push_back({ username, password }); // Push back the username and password parameters to the accountList
}

void Account::manageUsers() // Manage Users Function
{
	std::cout << "\nSelect Task" << std::endl;
	std::cout << "1. Add User\n2. View Users\n3. Back to Main Menu" << std::endl;

	std::cout << "Enter Menu Option: " << std::endl;
	std::cin >> manageValue;

	switch (manageValue) // Switch and Case to handle selection
	{
		// Add User Option
	case 1:
		std::cout << "\nSelected 1: Add User" << std::endl; // Output User Message confirming selection
		std::cout << "Enter Username: " << std::endl;
		std::cin >> usrinput;
		std::cout << "Enter Password: " << std::endl;
		std::cin >> pwdinput;
		accountManager.addUser(usrinput, pwdinput);
		LibraryManagementSystem::mainMenu(); // Show main menu
		break; // Break Statement

		// Delete User Option
	case 2:
		std::cout << "\nSelected 2: View User" << std::endl; // Output User Message confirming selection
		Account::outputAccounts(); // Invoke editUser Function
		break; // Break Statement

		// Back to Main Menu Option
	case 3:
		std::cout << "\nSelected 3: Back to Main Menu" << std::endl; // Output User Message confirming selection
		LibraryManagementSystem::mainMenu(); // Invoke mainMenu Function
		break; // Break Statement

		// Default Option
	default:
		std::cout << "\nInvalid Option" << std::endl; // Output Invalid Message
		Account::manageUsers(); // Show menu again
		break; // Break Statement
	}
}
