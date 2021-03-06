//
// Project: A2BlackJack
// Created by: Ryan Purse 
// Date: 02/01/2021
//

#include "../public/settings.h"
#include "../public/input.h"
#include "../public/unitTests.h"
#include <iostream>

bool g_debug = false;
bool g_showIcons = true;

void setSetting(bool &setting) {
    char input;
    if (setting) {
        input = characterInput((char*)"Would you like to turn off this setting? (y/n):", (char*)"yn", true);
    }
    else {
        input = characterInput((char*)"Would you like to turn on this setting? (y/n):", (char*)"yn", true);
    }
    switch (input) {
        case '1':
        case 'y':
            setting = !setting;
        default:
            return;
    }
}

void settingsMenu() {
    for (;;) {
        displaySettingsInfo();
        if (!g_debug) {
            char input = characterInput((char*)"Select an option to change:", (char*)"dsqe", true);
            switch (input) {
                case '1':
                case 'd':
                    setSetting(g_debug);
                    break;
                case '2':
                case 's':
                    setSetting(g_showIcons);
                default:
                    return;
            }
        }
        else {
            char input = characterInput((char*)"Select an option to change:", (char*)"dsqrie", true);
            switch (input) {
                case '1':
                case 'd':
                    setSetting(g_debug);
                    break;
                case '2':
                case 's':
                    setSetting(g_showIcons);
                    break;
                case '3':
                case 'r':
                    runUnitTest();
                    break;
                case '4':
                case 'i':
                    runInputTest();
                    break;
                default:
                    return;
            }
        }
    }
}

void displaySettingsInfo() {
    system("cls");
    std::cout << "-_-_-_-_-_-_-_- Dr. Greens Casino -_-_-_-_-_-_-" << std::endl;
    std::cout << "-_-_-_-_-_-_-_-_-_-_ Settings -_-_-_-_-_-_-_-_-" << std::endl << std::endl;

    std::cout << "(D)ebug Mode: ";
    if (g_debug) {
        std::cout << "On";
    }
    else {
        std::cout << "Off";
    }
    std::cout << std::endl;

    std::cout << "(S)how Icons: ";
    if (g_showIcons) {
        std::cout << "On";
    }
    else {
        std::cout << "Off";
    }
    /* Unit Tests */
    if (g_debug) {
        std::cout << std::endl;
        std::cout << "(R)un Unit Test" << std::endl << "Run (I)nput Test";
    }
    std::cout << std::endl << "(E)xit settings" << std::endl << std::endl;
}
