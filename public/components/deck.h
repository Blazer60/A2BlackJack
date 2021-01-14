//
// Provides functionality for a deck of cards
// Project: A2BlackJack
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

#include "playingCard.h"

/* Unicode character for each suit */
#define SPADES L'\u2660'
#define HEARTS L'\u2665'
#define DIAMONDS L'\u2666'
#define CLUBS L'\u2663'

struct deck {
    playingCard deck[52];
    int cardPtr = 0;
    int shufflePtr = 42;
    bool shuffle = false;
};

/* Logic */
playingCard drawCard(deck &cards);
void generateDeck(deck &cards);
void shuffleDeck(deck &cards, unsigned seed);

/* Render */
void displayDeckInfo(deck &cards, int cardsOnField);

#endif //A2BLACKJACK_DECK_H
