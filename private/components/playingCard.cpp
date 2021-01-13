//
// Project: A2BlackJack
// Created by: Ryan Purse 
// Date: 02/01/2021
//

#include "../../public/components/playingCard.h"
#include "../../public/settings.h"


void displayCard(playingCard &card) {
    if (g_showIcons) {
        std::cout << card.name ;
        _setmode(_fileno(stdout), _O_U16TEXT);  // Sets the mode to Unicode
        std::wcout << card.icon;
        _setmode(_fileno(stdout), _O_TEXT);     // Resets back to ASCII
    }
    else {
        std::cout << card.name << " of " << card.suit;
    }
}
