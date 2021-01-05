//
// Project: A2BlackJack
// Created by: Ryan Purse 
// Date: 01/01/2021
//

#ifndef A2BLACKJACK_HAND_H
#define A2BLACKJACK_HAND_H

#include "playingCard.h"

enum handType { Blackjack, Soft, Hard, Bust };  // Used to determine if a hand has Blackjack or Bust

struct hand {
    playingCard *cards = new playingCard[3];
    int arraySize{ 3 };
    int handSize{ 0 };
    int score{ 0 };
    handType type = Hard;
};

/* Logic */
void addCard(hand &playerHand, playingCard newCard);
void calculateTotalScore(hand &playerHand, bool countFirstCard = true);
void increaseHandSize(hand &playerHand);

/* Render */
void displayHand(hand &playerHand, char playerName[], bool hideFirstCard = false);

#endif //A2BLACKJACK_HAND_H
