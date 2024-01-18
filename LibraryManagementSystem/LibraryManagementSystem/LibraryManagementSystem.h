// LibraryManagementSystem.h : This file contains the header file for the 'LibraryManagementSystem' main class

#pragma once // Fix to stop LibraryManagementSystem being included multiple times

// ANSI Text Colours
#define TITLE_TEXT "\033[34m"    // Blue Text Colour
#define ERROR_TEXT "\033[31m"    // Red Text Colour
#define PROMPT_TEXT "\033[33m"   // Yellow Text Colour
#define SUCCESS_TEXT "\033[32m"  // Green Text Colour
#define DEFAULT_TEXT "\033[0m"   // Default Terminal Colour

class LibraryManagementSystem {

public:
    static bool isAuthed; // STATIC MEMBER: isAuthed Boolean for determining if a user has logged into the session

    static void mainMenu(); // STATIC MEMBER: mainMenu() function used for displaying the main menu

    // FRIENDSHIP: Allows these classes to access private members in this class
    friend class Account;
    friend class Book;
    friend class Event;
};
