//
// Project: A2BlackJack
// Created by: Ryan Purse 
// Date: 02/01/2021
//

#include "../public/settings.h"
#include "../public/input.h"
#include <iostream>


void displaySettingsInfo(bool &debug, bool showIcons) {
    std::cout << "-_-_-_-_-_-_-_- Dr. Greens Casino -_-_-_-_-_-_-" << std::endl;
    std::cout << "-_-_-_-_-_-_-_-_-_-_ Settings -_-_-_-_-_-_-_-_-" << std::endl << std::endl;

    std::cout << "(D)ebug Mode: ";
    if (debug) {
        std::cout << "On";
    }
    else {
        std::cout << "Off";
    }
    std::cout << std::endl;

    std::cout << "(S)how Icons: ";
    if (showIcons) {
        std::cout << "On";
    }
    else {
        std::cout << "Off";
    }
    std::cout << std::endl << "(E)xit settings" << std::endl << std::endl;
}

void setSetting(bool &setting) {
    char input;
    if (setting) {
        input = characterInput("Would you like to turn off this setting? (y/n):", "yn", true);
    }
    else {
        input = characterInput("Would you like to turn on this setting? (y/n):", "yn", true);
    }
    switch (input) {
        case '1':
        case 'y':
            setting = !setting;
        default:
            return;
    }
}

void settingsMenu(bool &debug, bool &showIcons) {
    for (;;) {
        displaySettingsInfo(debug, showIcons);
        char input = characterInput("Select an option to change:", "dsqe", true);
        switch (input) {
            case '1':
            case 'd':
                setSetting(debug);
                break;
            case '2':
            case 's':
                setSetting(showIcons);
                break;
            default:
                return;
        }
    }
}
