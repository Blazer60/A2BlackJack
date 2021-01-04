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

int main() {
    /* Default Settings */
    bool quitGame = false;

    /* Main menu for the user. Branches off into separate methods */
    while (!quitGame) {
        menuInfo();
        char playerChoice = characterInput("Option:", "pshq", true);
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
                quitGame = true;
                break;
            default:
                std::cout << "Please type p, s, h or q to continue" << std::endl;
                break;
        }
    }
    return 0;
}
