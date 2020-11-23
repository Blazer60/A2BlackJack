#include <iostream>
#include "deck.h"

int main() {
    /* Default Settings */
    bool debug = true;
    bool showIcons = true;
    bool quitGame = false;

    /* Main menu for the user. Branches off into separate methods */
    while (!quitGame) {
        char playerChoice;
        std::cout << "(p)lay, (s)ettings, (t)utorial, (q)uit" << std::endl;
        std::cin >> playerChoice;
        switch (playerChoice) {
            case 'p':
                std::cout << "this would go to an actual game but it isn't implemented yet" << std::endl;
                break;
            case 's':
                std::cout << "Settings" << std::endl;
                break;
            case 't':
                std::cout << "Tutorial" << std::endl;
                break;
            case 'q':
                quitGame = true;
                break;
            default:
                std::cout << "Please type p, s, t or q to continue" << std::endl;
                break;
        }
    }
    return 0;
}
