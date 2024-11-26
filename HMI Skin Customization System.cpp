/*HMI Skin Customization System
Objective: Implement a system to manage different themes or skins for an HMI display.
Requirements:
Create a Theme class:
Attributes: backgroundColor, fontColor, fontSize, and iconStyle.
Implement methods to apply and display the theme.
Store multiple themes using std::map:
Example themes: Classic, Sport, and Eco.
Create a simple user interface to switch between themes:
Use console input to select a theme.
Display a preview of the selected theme on the console (e.g., "Sport Theme: Red Background, White Font").
Deliverables:
A C++ program that demonstrates theme switching.
Output displaying applied themes.*/


code:
#include <iostream>
#include <map>
#include <string>

using namespace std;

class Theme {
public:
    string backgroundColor;
    string fontColor;
    int fontSize;
    string iconStyle;

    Theme(string bgColor, string fontColor, int fontSize, string iconStyle)
        : backgroundColor(bgColor), fontColor(fontColor), fontSize(fontSize), iconStyle(iconStyle) {}

    void displayTheme() {
        cout << "Background Color: " << backgroundColor << "\n"
             << "Font Color: " << fontColor << "\n"
             << "Font Size: " << fontSize << "\n"
             << "Icon Style: " << iconStyle << "\n";
    }
};

int main() {
    map<string, Theme> themes;
    themes["Classic"] = Theme("White", "Black", 12, "Simple");
    themes["Sport"] = Theme("Red", "White", 14, "Bold");
    themes["Eco"] = Theme("Green", "Black", 10, "Minimal");

    string choice;
    cout << "Available Themes:\n";
    cout << "1. Classic\n2. Sport\n3. Eco\n";
    cout << "Choose a theme: ";
    cin >> choice;

    if (themes.find(choice) != themes.end()) {
        cout << choice << " Theme:\n";
        themes[choice].displayTheme();
    } else {
        cout << "Invalid theme choice.\n";
    }

    return 0;
}
