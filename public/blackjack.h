//
// Project: A2BlackJack
// Created by: Ryan Purse 
// Date: 01/01/2021
//

#ifndef A2BLACKJACK_BLACKJACK_H
#define A2BLACKJACK_BLACKJACK_H

#include "components/deck.h"
#include "components/hand.h"
#include "input.h"
#include <iostream>

bool playAgain();
int enterCredits(int &credits);
bool dealCard();
void playRound(deck &cards, int &credits);
void blackjack();

#endif //A2BLACKJACK_BLACKJACK_H
