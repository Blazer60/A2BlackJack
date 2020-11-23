//
// Project: A2BlackJack
// Created by: Ryan Purse 
// Date: 23/11/2020
//

#include "deck.h"

void displayCard(card &card, bool displayIcon) {
    if (displayIcon) {
        std::cout << card.name << " ";
        /* Sets the mode to Unicode */
        _setmode(_fileno(stdout), _O_U16TEXT);
        std::wcout << card.icon;
        /* Resets back to ASCII */
        _setmode(_fileno(stdout), _O_TEXT);
    }
    else {
        std::cout << card.name << " of " << card.suit;
    }
}
