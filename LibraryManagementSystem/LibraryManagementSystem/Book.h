// Book.h : This file contains the header file for the 'Book' class

#pragma once // Fix to stop Book being included multiple times

#include <string>
#include <iostream>

using namespace std;

class Borrower;

class Book {
public:
    // Variable Declarations
    static int idCounter;
    int id;
    string name;
    string author;
    string publisher;
    string genre;
    string status;
    string borrowerName;

    // CONSTRUCTOR
    Book() = default;

    // CONSTRUCTOR: Constructs the Book Class
    Book(const string& _name, const string& _author, const string& _publisher, const string& _genre,
        const string& _status, const string& _borrowerName, Borrower* _borrower = nullptr);
    // ABSTRACTION: Member Functions contained within individual classes
    // Function Declarations
    void viewAllBooks();
    void outputBooks();
    void checkOutBook();
    void manageBooks();
    void addBook();
    void deleteBook();
    void editBook();

private:
    int getId();
    string getBookName();
    string getAuthor();
    string getPublisher();
    string getGenre();
    string getStatus();
    string getBorrower();

    // POINTER: Points to the Borrower to access members
    Borrower* borrower;

    // FUNCTIONAL POINTER: Points to the manageBooks function
    using ManageBookFunction = void (Book::*)();
    static Book::ManageBookFunction bookManagerFunction; // Initialise the function
};
