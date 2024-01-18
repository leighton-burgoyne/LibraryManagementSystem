// Book.cpp

#include "Book.h"
#include "LibraryManagementSystem.h"
#include "Library.h"
#include "Event.h"

int Book::idCounter = 1;
vector<Book> books; // Books Vector

// CONSTRUCTOR
Book::Book(const string& _name, const string& _author, const string& _publisher, const string& _genre,
    const string& _status, const string& _borrowerName, Borrower* _borrower)
    : id(idCounter++), name(_name), author(_author), publisher(_publisher), genre(_genre),
    status(_status), borrowerName(_borrowerName), borrower(_borrower) {}

// FUNCTIONAL POINTER
Book::ManageBookFunction Book::bookManagerFunction = &Book::manageBooks;

void Book::viewAllBooks() {
	std::cout << "\nBook Database:\n";

	if (books.empty()) // If Books Empty
	{
		std::cout << ERROR_TEXT << "ERROR: No Books have been added! Please create a Book to use this function." << DEFAULT_TEXT << endl; // Display Error Message if no Books exist
	}

	else // If Books Populated
	{
		std::cout << "ID\tName\tAuthor\tPublisher\tGenre\tStatus\tBorrower" << endl; // Display column headers

		// For each book in the Books Vector, output all data
		for (const auto& book : books) {
			std::cout << book.id << "\t" << book.name << "\t" << book.author << "\t" << book.publisher << "\t" << book.genre << "\t" << book.status << "\t" << book.borrowerName << endl;
		}
	}
	LibraryManagementSystem::mainMenu(); // Redirect to Menu
}

void Book::outputBooks() {
	std::cout << "ID\tName\tAuthor\tPublisher\tGenre\tStatus\tBorrower" << std::endl; // Display column headers
	// For each book in the Books Vector, output all data
	for (const auto& book : books) {
		std::cout << book.id << "\t" << book.name << "\t" << book.author << "\t" << book.publisher << "\t" << book.genre << "\t" << book.status << "\t" << book.borrowerName << endl;
	}
}

void Book::checkOutBook() { // Check Out Books Function
	outputBooks(); // Output Books

	int bookId;
	std::cout << "Enter Book ID to check out: ";
	std::cin >> bookId;

	// Find the book with the specified ID
	auto bk = find_if(
		books.begin(),
		books.end(),
		[&](const Book& book) {
			return bookId == const_cast<Book&>(book).getId();
		});

	if (bk != books.end()) // Check if the book with the specified ID exists
	{
		string fullName;
		std::cout << "Enter Borrower Name: ";
		std::cin.ignore(); // Clear Newline Buffer (fix)
		getline(cin, fullName);

		// Update book status and add borrower's name
		bk->status = "On Loan";
		bk->borrowerName = fullName;

		std::cout << "Book ID " << bookId << " has been checked out to " << fullName << "." << std::endl;

		Event::logEvent(1, bookId, "Checkout - " + fullName);

		LibraryManagementSystem::mainMenu(); // Redirect to Menu
	}
	else
	{
		std::cout << "Book ID " << bookId << " not found." << std::endl;
	}
}

void Book::manageBooks() { // Manage Books Function
	std::cout << "\nSelect Task" << std::endl;
	std::cout << "1. Add Book\n2. Delete Book\n3. Edit Book\n4. Back to Main Menu" << std::endl; // Output menu choices

	std::cout << "Enter Menu Option: "; // Get user input for Menu Option
	int bookMenuValue;
	std::cin >> bookMenuValue;

	switch (bookMenuValue) // Switch based on the inputted user value
	{
		// Add Book Option

	case 1:
		std::cout << "\nSelected 1: Add Book" << std::endl; // Output User Message confirming selection
		Book::addBook(); // Invoke addBook Function
		break; // Break Statement

		// Delete Book Option

	case 2:
		std::cout << "\nSelected 2: Delete Book" << std::endl; // Output User Message confirming selection
		Book::deleteBook(); // Invoke deleteBook Function
		break; // Break Statement

		// Edit Book Option

	case 3:
		std::cout << "\nSelected 3: Edit Books" << std::endl; // Output User Message confirming selection
		Book::editBook(); // Invoke editBook Function
		break; // Break Statement

		// Back to Main Menu Option

	case 4:
		std::cout << "\nSelected 4: Back to Main Menu" << std::endl; // Output User Message confirming selection
		LibraryManagementSystem::mainMenu(); // Invoke mainMenu Function
		break; // Break Statement

		// Default Option

	default:
		std::cout << "\nInvalid Option" << std::endl;  // Output Invalid Message
		Book::manageBooks(); // Show menu again
		break; // Break Statement
	}
}

void Book::addBook() { // Add Book Function
	string name, author, publisher, genre, status, borrowerName; // Define the temporary string variables for input

	cout << "Enter Book Name: "; // Input Book Name
	cin.ignore(); // Clear Newline Buffer (fix)
	getline(cin, name); // Get full line of the input

	cout << "Enter Author Name: "; // Input Author Name
	getline(cin, author);  // Get full line of the input

	cout << "Enter Publisher: "; // Input Publisher
	getline(cin, publisher); // Get full line of the input

	cout << "Enter Genre: "; // Input Genre
	getline(cin, genre); // Get full line of the input

	status = "Available"; // Automatically set status as Available
	borrowerName = ""; // Null the borrowerName as book is not loaned currently

	Book newBook(name, author, publisher, genre, status, borrowerName); // Construct newBook instance and populate the input values

	books.push_back(newBook); // Push back newBook instance to books vector

	cout << "Book " << name << " has been created."; // Delete Confirmation

	Event::logEvent(1, 0, "New Book - " + name); // Log the Event

	LibraryManagementSystem::mainMenu(); // Redirect to Menu
}

void Book::deleteBook() { // Delete Book Function
	outputBooks(); // Output Books so user can see the ID
	cout << "Enter Book ID to delete: ";
	int deleteBookIdInput; // Temp Input Variable
	cin >> deleteBookIdInput; // User Input

	books.erase( // Erase from books vector if deleteBookIdInput matches the ID of a book
		remove_if(
			books.begin(),
			books.end(),
			[&](const Book& book) {
				return deleteBookIdInput == const_cast<Book&>(book).getId();
			}),
		books.end());

	cout << "Book ID " << deleteBookIdInput << " has been deleted from the system."; // Delete Confirmation

	Event::logEvent(1, 0, "Delete Book - ");

	LibraryManagementSystem::mainMenu(); // Redirect to Menu
}

void Book::editBook() { // Edit Books Function
	outputBooks(); // Output Books so user can see the ID
	cout << "Enter Book ID to edit: ";
	int editBookIdInput; // Temp Input Variable
	cin >> editBookIdInput; // User Input

	auto bk = find_if( // Find the book in the books vector if editBookIdInput matches the ID of a book
		books.begin(),
		books.end(),
		[&](const Book& book) {
			return editBookIdInput == const_cast<Book&>(book).getId();
		});

	// Update Book Attributes
	if (bk != books.end()) { // If the find search has ended
		cout << "Enter new Book Name: "; // Input Book Name
		cin.ignore(); // Clear Newline Buffer (fix)
		getline(cin, bk->name); // Get full line of the input

		cout << "Enter new Author Name: "; // Input Author Name
		getline(cin, bk->author);  // Get full line of the input

		cout << "Enter new Publisher: "; // Input Publisher
		getline(cin, bk->publisher); // Get full line of the input

		cout << "Enter new Genre: "; // Input Genre
		getline(cin, bk->genre); // Get full line of the input
	}

	cout << "Book ID " << editBookIdInput << " has been edited."; // Edit Confirmation

	Event::logEvent(1, 0, "Edit Book - " + name); // Log the Event

	LibraryManagementSystem::mainMenu(); // Redirect to Menu
}

int Book::getId() // Getter Function for Id
{
	return id;
}

string Book::getBookName() // Getter Function for Book Name
{
	return name;
}

string Book::getAuthor() // Getter Function for Author Name
{
	return author;
}

string Book::getPublisher() //Getter Function for Publisher
{
	return publisher;
}

string Book::getGenre() // Getter Function for Genre
{
	return genre;
}

string Book::getStatus() // Getter Function for Status

{
	return status;
}

string Book::getBorrower()  // Getter Function for Borrower Name
{
	return borrowerName;
}
