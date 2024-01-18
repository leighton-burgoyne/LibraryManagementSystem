#include "Event.h"
#include "LibraryManagementSystem.h"

// STATIC MEMBERS
int Event::idCounter = 0;
std::vector<Event> Event::eventLog;

// CONSTRUCTOR
Event::Event(int userId, int bookId, std::string eventType)
    : eventId(idCounter++), userId(userId), bookId(bookId), eventType(eventType) {}

// Log Event Function
void Event::logEvent(int userId, int bookId, const std::string& eventType) {
    Event event(userId, bookId, eventType);
    eventLog.push_back(event);
}

// View Event Logs Function
void Event::viewEventLogs() const {
    std::cout << "\nEvent Logs:\n";

    if (eventLog.empty()) {
        std::cout << "ERROR: No Events have been logged yet." << std::endl;
    }
    else {
        std::cout << "Event ID\tUser ID\tBook ID\tEvent" << std::endl;

        for (const auto& event : eventLog) {
            std::cout << event.eventId << "\t" << event.userId << "\t" << event.bookId << "\t" << event.eventType << std::endl;
        }
    }
    LibraryManagementSystem::mainMenu();
}

// STATIC MEMBERS
int Event::getIdCounter() {
    return idCounter;
}
