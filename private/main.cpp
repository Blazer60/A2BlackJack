#include <iostream>
#include "../public/deck.h"
#include "../public/input.h"

void blackJack() {
    card deck[52];
    generateDeck(deck);
    std::cout << "this would go to an actual game but it isn't implemented yet" << std::endl;
}

int main() {
    /* Default Settings */
    bool debug = true;
    bool showIcons = true;
    bool quitGame = false;

    /* int not working */
    std::cout << integerInput("Enter a number between 1-10", 1, 10);

    /* Main menu for the user. Branches off into separate methods */
//    while (!quitGame) {
//        char playerChoice = characterInput("(p)lay, (s)ettings, (t)utorial, (q)uit", "pstq");
//        switch (playerChoice) {
//            case 'p':
//                blackJack();
//                break;
//            case 's':
//                std::cout << "Settings" << std::endl;
//                break;
//            case 't':
//                std::cout << "Tutorial" << std::endl;
//                break;
//            case 'q':
//                quitGame = true;
//                break;
//            default:
//                std::cout << "Please type p, s, t or q to continue" << std::endl;
//                break;
//        }
//    }
    return 0;
}
