//
// Project: A2BlackJack
// Created by: Ryan Purse 
// Date: 04/01/2021
//

#ifndef A2BLACKJACK_UNITTESTS_H
#define A2BLACKJACK_UNITTESTS_H


#include "components/deck.h"

struct unitData {
    double averageHandSize{ 0.f };
    double averageHandScore{ 0.f };
    int blackjacks{ 0 };
    int cardsDrawn{ 0 };
    int shuffles{ 0 };
    int overflows{ 0 };
    int gamesPlayed{ 0 };
};

void runPseudoGame(deck &cards, unitData &data);
void runUnitTest();

#endif //A2BLACKJACK_UNITTESTS_H
