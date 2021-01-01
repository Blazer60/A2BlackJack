//
// Project: A2BlackJack
// Created by: Ryan Purse 
// Date: 01/01/2021
//

#include "../public/hand.h"

void calculateTotalScore(hand playerHand, bool debug) {
    /*
     * Calculate the total score of a hand.
     * Additionally set's the type of hand to
     * keep track of Blackjack
     */

    playerHand.score = 0;
    int aceCount = 0;
    bool aceFound = false;

    for (int i = 0; i < playerHand.handSize; i++) {
        /* don't add the "hole" card */
        if (i != 0 || !debug) {
            card c = playerHand.cards[i];
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

void increaseHandSize(hand playerHand) {
    /*
     * Increases the amount of cards in the players hand by 1.
     * It will also increase the array size on the heap if needed.
     */

    playerHand.handSize++;

    if (playerHand.handSize > playerHand.arraySize) {
        /* Copy the contents of the old array to the new array */
        card *newCardArray = new card[playerHand.arraySize * 2];
        for (int i = 0; i < playerHand.handSize - 1; i++) {
            newCardArray[i] = playerHand.cards[i];
        }
        /* Free memory and reassign the pointer */
        delete[] playerHand.cards;
        playerHand.cards = newCardArray;
    }
}
