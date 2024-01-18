
// | |   ___(_)__ _| |_| |_ ___ _ _   | _ )_  _ _ _ __ _ ___ _  _ _ _  ___ 
// | |__/ -_) / _` | ' \  _/ _ \ ' \  | _ \ || | '_/ _` / _ \ || | ' \/ -_) 
// |____\___|_\__, |_||_\__\___/_||_| |___/\_,_|_| \__, \___/\_, |_||_\___|
//            |___/                                |___/     |__/
//
// Version 3
// LibraryManagementSystem.cpp

#include "LibraryManagementSystem.h"
#include "Library.h"
#include <iostream>
#include "Book.h"
#include "Event.h"
#include "Account.h"

Book book;
Account account;
Event event;
Library library;

bool LibraryManagementSystem::isAuthed = false; // Initialise static member

void LibraryManagementSystem::mainMenu()
{
    cout << TITLE_TEXT << "\nMain Menu" << DEFAULT_TEXT << endl;
    cout << "1. Check Out Book\n2. View All Books\n3. Manage Books\n4. Manage Users\n5. View Event Logs" << endl;

    cout << "Enter Menu Option: "; // Get user input for Menu Option
    int menuValue; // Store input temp
    cin >> menuValue;

    switch (menuValue) // Switch based on the inputted user value
    {
        // Check Out Book Option

    case 1:
        cout << PROMPT_TEXT << "\nSelected 1: Check Out Book" << DEFAULT_TEXT << endl; // Output User Message confirming selection
       book.checkOutBook(); // Invoke viewAllBooks Function
        break; // Break Statement

        // View All Books Option

    case 2:
        cout << PROMPT_TEXT << "\nSelected 2: View All Books" << DEFAULT_TEXT << endl; // Output User Message confirming selection
        book.viewAllBooks(); // Invoke viewAllBooks Function
        break; // Break Statement

        // Manage Books Option

    case 3:
        cout << PROMPT_TEXT << "\nSelected 3: Manage Books" << DEFAULT_TEXT << endl; // Output User Message confirming selection
        book.manageBooks(); // Invoke manageBooks Function
        break; // Break Statement

        // Manage Users Option

    case 4:
        cout << PROMPT_TEXT << "\nSelected 4: Manage Users" << DEFAULT_TEXT << endl; // Output User Message confirming selection
        account.manageUsers(); // Invoke manageUsers Function
        break; // Break Statement

        // View Event Logs Option

    case 5:
        cout << PROMPT_TEXT << "\nSelected 5: View Event Logs" << DEFAULT_TEXT << endl; // Output User Message confirming selection
        event.viewEventLogs(); // Invoke viewEventLogs Function
        break; // Break Statement

        // Default Option

    default:
        cout << ERROR_TEXT "\nInvalid Option" << DEFAULT_TEXT << endl; // Output User Message confirming selection
        mainMenu(); // Invoke mainMenu Function
        break; // Break Statement
    }
}

int main() {

    std::cout << TITLE_TEXT << "Welcome to " << library.Name << DEFAULT_TEXT << std::endl; // Output Library Name
    std::cout << TITLE_TEXT << "Address: " << library.Address << DEFAULT_TEXT << std::endl; // Output Library Address

    account.addUser("user", "password"); // Manually add account

    // Login Function
    while (!LibraryManagementSystem::isAuthed) // While not authed
    {
        std::cout << PROMPT_TEXT << "\nPlease log in to your Account" << DEFAULT_TEXT << std::endl;
        std::cout << "Username: "; // Get user input for Username
        string usernameInput; // Store input temp
        std::cin >> usernameInput;
        std::cout << "Password: "; // Get user input for Password
        string passwordInput; // Store input temp
        std::cin >> passwordInput;

        LibraryManagementSystem::isAuthed = account.login(usernameInput, passwordInput); // Pass the username and password into the login function
    }

    if (LibraryManagementSystem::isAuthed) // If authed
    {
        LibraryManagementSystem::mainMenu(); // Redirect to the Main Menu
    }

    return 0;
}
