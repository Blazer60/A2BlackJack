//
// Project: A2BlackJack
// Created by: Ryan Purse 
// Date: 01/01/2021
//

#ifndef A2BLACKJACK_BLACKJACK_H
#define A2BLACKJACK_BLACKJACK_H

#include "components/deck.h"
#include "components/hand.h"
#include <iostream>
#include <iomanip>

bool playAgain();
int enterCredits(int &credits);
bool dealCard();
void displayBetInfo(int &credits, int &bet);
void displayInfo(hand &player, hand &dealer, deck &cards, int &credits, int &bet, bool hideHoleCard = true);
void playRound(deck &cards, int &credits);
void blackjack();

#endif //A2BLACKJACK_BLACKJACK_H
