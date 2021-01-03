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
    return integerInput((char*)"How many Credits would you like to bet?:", 0, credits);
}

bool dealCard() {
    char input = characterInput((char*)"Would you like to (h)it or (s)tand?:", (char*)"hs", true);
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
    displayHand(dealer, (char*)"Dealer", hideHoleCard);
    displayHand(player, (char*)"Player", false);
    /* Last turn info */

    std::cout << std::endl;
}

void playerTurn(hand &player, hand &dealer, deck &cards, int credits, int bet) {
    bool initialHand = true;
    for (;;) {
        displayInfo(player, dealer, cards, credits, bet, true);

        if (player.score == 21) {
            std::cout << "Your hand has a score of 21. Standing by default." << std::endl;
            system("pause");
            return;
        }
        else if (player.score > 21) {
            std::cout << "Your hand has gone bust" << std::endl;
            system("pause");
            return;
        }
        else {
            std::cout << "You drew ";
            if (initialHand) {
                displayCard(player.cards[0]);
                std::cout << " and ";
                initialHand = false;
            }
            displayCard(player.cards[player.handSize - 1]);
            std::cout << std::endl;
        }

        if (!dealCard()) {
            return;
        }
        addCard(player, drawCard(cards));
        calculateTotalScore(player);
    }
}

void dealerTurn(hand &dealer, deck &cards) {
    calculateTotalScore(dealer);
    while (dealer.score < 17) {
        addCard(dealer, drawCard(cards));
        calculateTotalScore(dealer);
    }
}

void calculateWinner(hand &player, hand &dealer, deck &cards, int &credits, int &bet) {
    /* Determine winner */
    displayInfo(player, dealer, cards, credits, bet, false);
    std::cout << "-_-_- Results -_-_-" << std::endl;

    /* Your Bust */
    if (player.type == Bust) {
        std::cout << "Bust Hand" << std::endl;
        std::cout << "Zero Credits awarded" << std::endl;
        return;
    }

    /* Dealer Bust */
    if (dealer.type == Bust) {
        std::cout << "You win. The Dealer went Bust" << std::endl;
        credits += bet * 2;
        std::cout << bet * 2 << "c awarded" << std::endl;
        return;
    }

    /* Blackjack */
    if (player.type == Blackjack || dealer.type == Blackjack && !(player.type == Blackjack && dealer.type == Blackjack)) {
        if (player.type == Blackjack) {
            std::cout << "You win. You have Blackjack" << std::endl;
            credits += bet * 2;
            std::cout << bet * 2 << "c awarded" << std::endl;
        }
        else {
            std::cout << "You loose. Dealers has Blackjack" << std::endl;
        }
        return;
    }

    if (player.score > dealer.score) {
        std::cout << "You win. You have a higher score than the dealer." << std::endl;
        credits += bet * 2;
        std::cout << bet * 2 << "c awarded" << std::endl;
    }
    else if (dealer.score > player.score) {
        std::cout << "You loose. The dealer has a higher score than you." << std::endl;
        std::cout << "Zero Credits awarded" << std::endl;
    }
    else {
        std::cout << "Draw. Both players have the same score" << std::endl;
        credits += bet;
        std::cout << bet << "c awarded" << std::endl;
    }
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

    playerTurn(playerHand, dealerHand, cards, credits, bet);

    /* Dealers Turn */
    displayInfo(playerHand, dealerHand, cards, credits, bet, false);
    std::cout << "The Dealer will now play" << std::endl;
    system("pause");
    dealerTurn(dealerHand, cards);

    calculateWinner(playerHand, dealerHand, cards, credits, bet);
    system("pause");

    /* Check to see if deck has looped */
    if (cards.shuffle) {
        std::cout << "The Deck will now be reshuffled" << std::endl;
        shuffleDeck(cards, std::chrono::steady_clock::now().time_since_epoch().count());
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

        /* Check credits */
        if (credits > 0) {
            /* Ask for another round */
            option = playAgain();
        }
        else {
            std::cout << "You have no more credits. Exiting to main menu" << std::endl;
            system("pause");
            option = false;
        }
    }
}
