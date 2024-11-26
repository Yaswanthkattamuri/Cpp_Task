/*Task 1: Build a Menu Navigation System
Objective: Implement a basic menu navigation system similar to what is found in automotive HMI clusters (e.g., settings menu, media options).
Requirements:
Create a hierarchical menu structure using classes and data structures.
Example:
Main Menu
Settings
Display Settings
Audio Settings
Media
Radio
Bluetooth Audio
Use a tree structure (std::vector or custom tree data structure) to represent the hierarchy.
Implement the following functionalities:
Navigate through menu levels (up/down/enter/back).
Display the current menu options on the console.
Add keyboard-based interaction (e.g., 1 to navigate down, 2 to navigate up, 3 to enter).
Deliverables:
A C++ program that uses OOP to create the menu structure.
Console output demonstrating navigation and interactions.*/


code:
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class MenuItem {
public:
    string name;
    vector<MenuItem*> subMenu;
    MenuItem* parentMenu;

    MenuItem(string itemName) : name(itemName), parentMenu(nullptr) {}

    void addSubMenu(MenuItem* item) {
        subMenu.push_back(item);
        item->parentMenu = this;  // Set parent menu for submenus
    }
};

class MenuSystem {
private:
    MenuItem* currentMenu;
    int currentSelection;

public:
    MenuSystem(MenuItem* root) : currentMenu(root), currentSelection(0) {}

    void displayMenu() {
        cout << "Current Menu: " << currentMenu->name << "\n";
        for (int i = 0; i < currentMenu->subMenu.size(); i++) {
            cout << (i == currentSelection ? "-> " : "   ") << currentMenu->subMenu[i]->name << "\n";
        }
        cout << "1. Up\n2. Down\n3. Back\n0. Select\n4. Exit\n";
    }

    void navigate(int choice) {
        if (choice == 1) {  // Up
            if (currentSelection > 0) {
                currentSelection--;
            }
        } else if (choice == 2) {  // Down
            if (currentSelection < currentMenu->subMenu.size() - 1) {
                currentSelection++;
            }
        } else if (choice == 3) {  // Back to parent menu
            if (currentMenu->parentMenu != nullptr) {
                currentMenu = currentMenu->parentMenu;
                currentSelection = 0;  // Reset selection when going back
            }
        } else if (choice == 0) {  // Select
            if (!currentMenu->subMenu.empty()) {
                currentMenu = currentMenu->subMenu[currentSelection];
                currentSelection = 0;  // Reset selection when moving into a submenu
            }
        } else if (choice == 4) {  // Exit the program
            cout << "Exiting program...\n";
            exit(0);  // Exit the program immediately
        }
    }
};

int main() {
    // Build Menu Structure
    MenuItem* mainMenu = new MenuItem("Main Menu");
    MenuItem* settingsMenu = new MenuItem("Settings");
    MenuItem* displaySettings = new MenuItem("Display Settings");
    MenuItem* audioSettings = new MenuItem("Audio Settings");
    MenuItem* mediaMenu = new MenuItem("Media");
    MenuItem* radioMenu = new MenuItem("Radio");
    MenuItem* bluetoothAudio = new MenuItem("Bluetooth Audio");

    mainMenu->addSubMenu(settingsMenu);
    mainMenu->addSubMenu(mediaMenu);
    settingsMenu->addSubMenu(displaySettings);
    settingsMenu->addSubMenu(audioSettings);
    mediaMenu->addSubMenu(radioMenu);
    mediaMenu->addSubMenu(bluetoothAudio);

    MenuSystem menuSystem(mainMenu);
    int choice;

    while (true) {
        menuSystem.displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        menuSystem.navigate(choice);
    }

    return 0;
}
