//
// Project: A2BlackJack
// Created by: Ryan Purse 
// Date: 01/01/2021
//

#ifndef A2BLACKJACK_HAND_H
#define A2BLACKJACK_HAND_H

#include "deck.h"

enum handType { Blackjack, Soft, Hard, Bust };

struct hand {
    card *cards = new card[3];
    int arraySize{ 3 };
    int handSize{ 0 };
    int score{ 0 };
    handType type = Hard;
};

void calculateTotalScore(hand playerHand, bool debug = false);
void increaseHandSize(hand playerHand);

#endif //A2BLACKJACK_HAND_H
