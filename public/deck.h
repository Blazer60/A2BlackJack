//
// Project: A2BlackJack
// Provides functionality for a deck of cards
// Created by: Ryan Purse
// Date: 23/11/2020
//



#ifndef A2BLACKJACK_DECK_H
#define A2BLACKJACK_DECK_H

#include <iostream>
#include <algorithm>
/* Random function */
#include <random>
#include <chrono>
/* Unicode manipulation for iostream */
#include <io.h>
#include <fcntl.h>


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

struct deck {
    card deck[52];
    int cardPtr{ 0 };
    bool displayIcons{ false };
    int shufflePtr{ 44 };
    bool shuffle{ false };
};

void displayCard(card &card, bool displayIcon=false);
void generateDeck(deck cards);
void shuffleDeck(deck cards, unsigned seed);
card* drawCard(deck cards);

#endif //A2BLACKJACK_DECK_H
