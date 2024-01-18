// Event.h : This file contains the header file for the 'Event' class

#pragma once // Fix to stop Event being included multiple times

#include <string>
#include <iostream>
#include <vector>

class Event
{
    // ENCAPSULATION: Making these variables public so they can be accessed outside of the Event Classs 
public:
    // STATIC MEMBERS
    static int idCounter;
    static std::vector<Event> eventLog; // Event Log Vector

    // ENCAPSULATION: Making these variables private so they are not accessed outside of the Event Class
private:
    int eventId; // Event ID
    int userId; // User ID relating to the event
    int bookId; // 
    std::string eventType;

public:
    // CONSTRUCTOR: Constructs the Event Class
    Event() = default;
    Event(int userId, int bookId, std::string eventType);

    // ABSTRACTION: Allows viewEventLogs to be accessed outside the class as it is a neccesary function
    void viewEventLogs() const;

    // Log Event Function
    static void logEvent(int userId, int bookId, const std::string& eventType);

    // FRIENDSHIP: Allow LibraryManagementSystem class to access any private members
    friend class LibraryManagementSystem;

    // STATIC MEMBER: Allow the getIdCounter() function to persist globally
    static int getIdCounter();
};