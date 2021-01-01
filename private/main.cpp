#include <iostream>
#include "../public/blackjack.h"
#include "../public/input.h"

int main() {
    /* Default Settings */
    bool debug = true;
    bool showIcons = true;
    bool quitGame = false;

    /* Main menu for the user. Branches off into separate methods */
    while (!quitGame) {
        char playerChoice = characterInput("(p)lay, (s)ettings, (t)utorial, (q)uit: ", "pstq", true);
        switch (playerChoice) {
            case 'p':
            case '1':
                blackjack();
                break;
            case 's':
            case '2':
                std::cout << "Settings" << std::endl;
                break;
            case 't':
            case '3':
                std::cout << "Tutorial" << std::endl;
                break;
            case 'q':
            case '4':
                quitGame = true;
                break;
            default:
                std::cout << "Please type p, s, t or q to continue" << std::endl;
                break;
        }
    }
    return 0;
}
