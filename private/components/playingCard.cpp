//
// Project: A2BlackJack
// Created by: Ryan Purse 
// Date: 02/01/2021
//

#include "../../public/components/playingCard.h"


void displayCard(playingCard &card, bool displayIcon) {
    if (displayIcon) {
        std::cout << card.name ;

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
