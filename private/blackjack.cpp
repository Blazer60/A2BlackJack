//
// Project: A2BlackJack
// Created by: Ryan Purse 
// Date: 01/01/2021
//

#include "../public/blackjack.h"

bool playAgain() {
    char input = characterInput("Would you like to play another round of Blackjack? (y/n):", "yn", true);
    switch (input) {
        case 'y':
        case '1':
            return true;
        case 'n':
        case '2':
            return false;
        default:
            std::cout << "Some went wrong. Exiting Blackjack";
            return false;
    }
}

int enterCredits(int &credits) {
    return integerInput("How many Credits would you like to bet?:", 0, credits);
}

bool dealCard() {
    char input = characterInput("Would you like to (h)it or (s)tand?:", "hs", true);
    switch (input) {
        case 'h':
        case '1':
            return true;
        case 's':
        case '2':
            return false;
        default:
            std::cout << "Some went wrong. Standing";
            return false;
    }
}

void playRound(deck &cards, int &credits) {
    /* Pre round setup */
    int bet = enterCredits(credits);
    credits -= bet;
    hand playerHand;
    hand dealerHand;

    addCard(playerHand, drawCard(cards));
    addCard(dealerHand, drawCard(cards));
    addCard(playerHand, drawCard(cards));
    addCard(dealerHand, drawCard(cards));

    bool endTurn = false;
    /* Players Turn */
    while (!endTurn) {
        /* display info */
        displayHand(dealerHand, "Dealer", true, true, true);
        displayHand(playerHand, "Player", true, false, false);
        /* display previous State */
        std::cout << "This section will display the state of the game." << std::endl;
        /* Ask if they want to hit or stand */
        endTurn = !dealCard();

        /* Draw Card for hit */
        if (!endTurn) {
            addCard(playerHand, drawCard(cards));
            calculateTotalScore(playerHand);
            endTurn = playerHand.score > 21;
        }
    }

    /* Dealers Turn */
    while (dealerHand.score < 17) {
        addCard(dealerHand, drawCard(cards));
        calculateTotalScore(dealerHand);
    }

    /* Determine winner */
    displayHand(dealerHand, "Dealer", true, false, true);
    displayHand(playerHand, "Player", true, false, false);

    /* Check to see if deck has looped */
    if (cards.shuffle) {
        shuffleDeck(cards, std::chrono::steady_clock::now().time_since_epoch().count());
    }


    /* Your Bust */
    if (playerHand.type == Bust) {
        std::cout << "No Credits Awarded. Bust Hand" << std::endl;
        return;
    }

    /* Dealer Bust */
    if (dealerHand.type == Bust) {
        std::cout << "You win. Dealer Bust" << std::endl;
        credits += bet * 2;
        return;
    }

    /* Blackjack */
    if (playerHand.type == Blackjack || dealerHand.type == Blackjack) {
        if (playerHand.type == Blackjack) {
            std::cout << "You win. You have Blackjack" << std::endl;
            credits += bet * 2;
        }
        else {
            std::cout << "You loose. Dealers has Blackjack" << std::endl;
        }

    }
    else {
       if (playerHand.score > dealerHand.score) {
           std::cout << "You win. You have a higher score than the dealer." << std::endl;
           credits += bet * 2;
       }
       else if (dealerHand.score > playerHand.score) {
           std::cout << "You loose. The dealer has a higher score than you." << std::endl;
       }
       else {
           std::cout << "Draw. Both players have the same score" << std::endl;
           credits += bet;
       }
    }
}

void blackjack() {
    /* Initial Setup */
    deck cards;
    generateDeck(cards);
    int credits = 100;

    bool option = true;
    while (option) {
        /* Play a round */
        playRound(cards, credits);

        /* Ask for another round */
        option = playAgain();
    }

}
