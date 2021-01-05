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

/* Input */
bool dealCard();
int enterCredits(int &credits);
bool playAgain();

/* Logic (In order of execution) */
void blackjack();
void playRound(deck &cards, int &credits);
void playerTurn(hand &player, hand &dealer, deck &cards, int credits, int bet);
void dealerTurn(hand &dealer, deck &cards);
void calculateWinner(hand &player, hand &dealer, deck &cards, int &credits, int &bet);

/* Render */
void displayBetInfo(int &credits, int &bet);
void displayInfo(hand &player, hand &dealer, deck &cards, int &credits, int &bet, bool hideHoleCard = true);

#endif //A2BLACKJACK_BLACKJACK_H
