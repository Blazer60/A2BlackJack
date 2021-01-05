//
// Main menu for Blackjack
// Project: A2BlackJack
// Created by: Ryan Purse
// Date: 23/11/2020
//

#include <iostream>
#include "../public/blackjack.h"
#include "../public/input.h"
#include "../public/settings.h"
#include "../public/tutorial.h"


void menuInfo() {
    system("CLS");
    std::cout << "-_-_-_-_-_-_-_- Dr. Greens Casino -_-_-_-_-_-_-" << std::endl;
    std::cout << "Welcome to Dr. Greens Casino.\n"
                 "Select an option below:\n"
                 "\n"
                 "(P)lay Blackjack\n"
                 "(S)ettings\n"
                 "(H)ow to play?\n"
                 "(Q)uit\n"
                 << std::endl;
}


/*
 * Main menu for: Blackjack, settings and tutorial.
 * Quits the program upon user request.
 */
int main() {
    /* Main menu for the user. Branches off into separate methods */
    for (;;) {
        menuInfo();
        char playerChoice = characterInput((char*)"Option:", (char*)"pshq", true);
        switch (playerChoice) {
            case 'p':
            case '1':
                blackjack();
                break;
            case 's':
            case '2':
                settingsMenu();
                break;
            case 'h':
            case '3':
                displayTutorial();
                break;
            case 'q':
            case '4':
                return 0;
            default:
                std::cout << "Please type p, s, h or q to continue" << std::endl;
                break;
        }
    }
}
