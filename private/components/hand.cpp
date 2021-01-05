//
// Project: A2BlackJack
// Created by: Ryan Purse 
// Date: 01/01/2021
//

#include "../../public/components/hand.h"
#include "../../public/settings.h"

void addCard(hand &playerHand, playingCard newCard) {
    playerHand.cards[playerHand.handSize] = newCard;
    increaseHandSize(playerHand);
}

/*
 * Calculate the total score of a hand.
 * Additionally set's the type of hand to
 * keep track of Blackjack
 */
void calculateTotalScore(hand &playerHand, bool countFirstCard) {
    playerHand.score = 0;
    int aceCount = 0;
    bool aceFound = false;

    for (int i = 0; i < playerHand.handSize; i++) {
        /* don't add the "hole" playingCard */
        if (i != 0 || countFirstCard) {
            playingCard c = playerHand.cards[i];
            playerHand.score += c.value;
            /* Increase Ace count when one is found */
            if (c.value == 11) {
                aceCount++;
                aceFound = true;
            }
        }
    }

    /* Apply Ace's to hand */
    while (playerHand.score > 21 && aceCount > 0) {
        playerHand.score -= 10;
        aceCount--;
    }

    /* Determine the type of hand */
    if (aceFound) {
        playerHand.type = (playerHand.handSize == 2 && playerHand.score == 21)? Blackjack : Soft;
    }
    else {
        playerHand.type = Hard;
    }

    /* Check if the hand has gone bust */
    if (playerHand.score > 21) {
        playerHand.type = Bust;
    }
}

/*
 * Increases the amount of cards in the players hand by 1.
 * It will also increase the array size on the heap if needed.
 */
void increaseHandSize(hand &playerHand) {
    playerHand.handSize++;

    if (playerHand.handSize >= playerHand.arraySize) {
        /* Copy the contents of the old array to the new array */
        playerHand.arraySize *= 2;
        auto *newCardArray = new playingCard[playerHand.arraySize];
        for (int i = 0; i < playerHand.handSize; i++) {
            newCardArray[i] = playerHand.cards[i];
        }
        /* Free memory and reassign the pointer */
        delete[] playerHand.cards;
        playerHand.cards = newCardArray;
    }
}

void displayHand(hand &playerHand, char playerName[], bool hideFirstCard) {
    std::cout << playerName << ": ";

    for (int i = 0; i < playerHand.handSize; i++) {
        if (hideFirstCard && i == 0) {
            /* Debug Cards shown in []*/
            if (g_debug) {
                std::cout << "[";
                displayCard(playerHand.cards[i]);
                std::cout << "] ";
            }
            /* Show ? if the card is hidden */
            else {
                g_showIcons? std::cout << "?? " : std::cout << "?? of ?????? ";
            }
        }
        /* Display the card */
        else {
            displayCard(playerHand.cards[i]);
            std::cout << " ";
        }
    }

    /* Show the score of the hand next to the cards */
    calculateTotalScore(playerHand, g_debug || !hideFirstCard);
    if (playerHand.score > 21) {
        std::cout << "(BUST)" << std::endl;
    }
    else {
        std::cout << "(" << playerHand.score << ")" << std::endl;
    }
}
