// Account.h : This file contains the header file for the 'Account' class

#pragma once // Fix to stop Account being included multiple times

#include <string>
#include <vector>

class User {
public:
    // POLYMORPHISM: Virtual Login Function to allow for overriding
    virtual bool login(const std::string& username, const std::string& password) = 0; // Virtual Login Function
};
// INHERITANCE: Account inherits from the User base class
class Account : public User {
public:
    struct AccountInfo { // Structure for storing the Username and Password together
        std::string username;
        std::string password;
    };

    static std::vector<AccountInfo> accountList; // STATIC MEMBER: Vector to store AccountInfo structs

    // CONSTRUCTOR: Constructs the Account Class
    Account() = default;
    Account(const std::string& username, const std::string& password);

    // POLYMORPHISM: Override Login Function
    bool login(const std::string& username, const std::string& password) override;

    static void outputAccounts();
    static void addUser(const std::string& username, const std::string& password);
    static void manageUsers();
};
