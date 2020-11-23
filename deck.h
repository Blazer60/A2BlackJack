//
// Project: A2BlackJack
// Provides functionality for a deck of cards
// Created by: Ryan Purse
// Date: 23/11/2020
//

#include <iostream>
/* Unicode manipulation for iostream */
#include <io.h>
#include <fcntl.h>


#ifndef A2BLACKJACK_DECK_H
#define A2BLACKJACK_DECK_H

/* Unicode character for each suit */
#define SPADES L"\u2660"
#define HEARTS L"\u2665"
#define DIAMONDS L"\u2666"
#define CLUBS L"\u2663"

struct card {
    char suit[9];
    char name[6];
    int value;
    std::wstring icon;
};

void displayCard(card &card, bool displayIcon=false);

#endif //A2BLACKJACK_DECK_H
