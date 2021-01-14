//
// Project: A2BlackJack
// Created by: Ryan Purse 
// Date: 02/01/2021
//

#ifndef A2BLACKJACK_PLAYINGCARD_H
#define A2BLACKJACK_PLAYINGCARD_H

#include <iostream>
/* Unicode manipulation for iostream */
#include <io.h>
#include <fcntl.h>


struct playingCard {
    char suit[9];
    char name[6];
    int value;
    wchar_t icon;   // UTF-16 Playing Card Icons
};

void displayCard(playingCard &card);

#endif //A2BLACKJACK_PLAYINGCARD_H
