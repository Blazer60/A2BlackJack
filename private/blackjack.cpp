//
// Project: A2BlackJack
// Created by: Ryan Purse 
// Date: 01/01/2021
//

#include "../public/blackjack.h"

#include "../public/input.h"
#include "../public/settings.h"

bool playAgain() {
    char input = characterInput((char*)"Would you like to play another round of Blackjack? (y/n):", (char*)"yn", true);
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

void displayBetInfo(int &credits, int &bet) {
    int offSet = bet > 0 ? 31 - (int)log10((double)bet): 31;
    offSet -= credits > 0 ? (int)log10((double)credits) + 1: 1;
    std::cout << "Current Bet: " << bet << "c" << std::setw(offSet) << "Pot: " << credits << "c" << std::endl;
}

void displayInfo(hand &player, hand &dealer, deck &cards, int &credits, int &bet, bool hideHoleCard) {
    /* Banner */
    system("cls");
    std::cout << "-_-_-_-_-_-_-_- Dr. Greens Casino -_-_-_-_-_-_-" << std::endl;
    if (g_debug) {
        std::cout << "____|____|____|____|____|____|____|____|____|__" << std::endl;
    }
    /* Display Bet and Pot */
    displayBetInfo(credits, bet);

    /* Display Deck and Discard pile */
    displayDeckInfo(cards, player.handSize + dealer.handSize);
    std::cout << std::endl;
    /* Display both hands */
    displayHand(dealer, "Dealer", hideHoleCard);
    displayHand(player, "Player", false);
    /* Last turn info */

    std::cout << std::endl;
}

void playRound(deck &cards, int &credits) {
    /* Pre round setup */

    hand playerHand;
    hand dealerHand;
    int bet = 0;
    displayInfo(playerHand, dealerHand, cards, credits, bet, true);
    bet = enterCredits(credits);
    credits -= bet;

    addCard(playerHand, drawCard(cards));
    addCard(dealerHand, drawCard(cards));
    addCard(playerHand, drawCard(cards));
    addCard(dealerHand, drawCard(cards));

    bool endTurn = false;
    /* Players Turn */
    while (!endTurn) {
        /* display info */
        displayInfo(playerHand, dealerHand, cards, credits, bet, true);
        /* Ask if they want to hit or stand */
        endTurn = !dealCard();

        /* Draw Card for hit */
        if (!endTurn) {
            addCard(playerHand, drawCard(cards));
            calculateTotalScore(playerHand);
            if (playerHand.score > 21) {
                endTurn = true;
                displayInfo(playerHand, dealerHand, cards, credits, bet, true);
                std::cout << "Your hand has gone bust" << std::endl;
                system("pause");
            }

        }
    }

    displayInfo(playerHand, dealerHand, cards, credits, bet, false);
    std::cout << "The Dealer will now play" << std::endl;
    system("pause");

    /* Dealers Turn */
    calculateTotalScore(dealerHand);
    while (dealerHand.score < 17) {
        addCard(dealerHand, drawCard(cards));
        calculateTotalScore(dealerHand);
    }

    /* Determine winner */
    displayInfo(playerHand, dealerHand, cards, credits, bet, false);

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
