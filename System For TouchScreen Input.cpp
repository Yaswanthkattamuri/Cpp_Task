/*Task 3: Event Handling System for Touchscreen Input
Objective: Simulate an event-driven system for processing touchscreen inputs on an HMI.
Requirements:
Create an Event class to represent user interactions:
Attributes: eventType (e.g., Tap, Swipe), x and y coordinates, and timestamp.
Implement an event queue using std::queue:
Store multiple events.
Process events one by one.
Handle specific events:
Tap: Display a message showing the tapped position.
Swipe: Calculate the swipe direction (up/down/left/right) and display it.
Simulate event generation:
Populate the queue with random events.
Deliverables:
A program simulating event processing.
Example output demonstrating event handling..*/


code:
#include <iostream>
#include <queue>
#include <string>
#include <cstdlib>
#include <ctime>
#include <thread>  // Include for std::this_thread
#include <chrono>  // Include for std::chrono

using namespace std;

class Event {
public:
    enum EventType { TAP, SWIPE };
    EventType eventType;
    int x, y;
    string timestamp;

    Event(EventType type, int xCoord, int yCoord, const string& time)
        : eventType(type), x(xCoord), y(yCoord), timestamp(time) {}
};

class EventProcessor {
private:
    queue<Event> eventQueue;

public:
    void generateRandomEvent() {
        int eventType = rand() % 2; // Randomly select event type
        int x = rand() % 100;
        int y = rand() % 100;
        string timestamp = "2024-11-26 12:34:56";  // Static for simplicity

        if (eventType == 0) {
            eventQueue.push(Event(Event::TAP, x, y, timestamp));
        } else {
            eventQueue.push(Event(Event::SWIPE, x, y, timestamp));
        }
    }

    void processEvent() {
        if (!eventQueue.empty()) {
            Event event = eventQueue.front();
            eventQueue.pop();
            if (event.eventType == Event::TAP) {
                cout << "Tap event at (" << event.x << ", " << event.y << ")\n";
            } else {
                cout << "Swipe event at (" << event.x << ", " << event.y << ")\n";
            }
        }
    }
};

int main() {
    srand(time(0));
    EventProcessor processor;

    // Simulate random events every second
    for (int i = 0; i < 10; ++i) {
        processor.generateRandomEvent();
        processor.processEvent();
        this_thread::sleep_for(chrono::seconds(1));  // Sleep for 1 second
    }

    return 0;
}