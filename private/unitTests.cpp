//
// Project: A2BlackJack
// Created by: Ryan Purse 
// Date: 04/01/2021
//

#include "../public/unitTests.h"
#include "../public/blackjack.h"
#include "../public/components/deck.h"
#include "../public/components/hand.h"
#include "../public/input.h"

void runInputTest() {
    /* Character input. no integers allowed */
    for (;;) {
        char input = characterInput(
                (char*)"--Unit Test: Character Input--\nEnter p, s, h or q:",
                (char*)"pshq");
        switch (input) {
            case 'p':
            case 's':
            case 'h':
                std::cout << "Valid Input" << std::endl;
                continue;
            case 'q':
            default:
                break;
        }
        break;
    }
    system("cls");

    /* Character input. integers allowed */
    for (;;) {
        char input = characterInput(
                (char*)"--Unit Test: Character Input w/ integers--\nEnter a, b or c:",
                (char*)"abc",
                true);
        switch (input) {
            case 'a':
            case 'b':
            case '1':
            case '2':
                std::cout << "Valid Input" << std::endl;
                continue;
            case 'c':
            case '3':
            default:
                break;
        }
        break;
    }
    system("cls");

    /* integer input */
    int input = -1;
    while (input != 10) {
        input = integerInput(
                (char*)"--Unit Test: Integer Input--\nEnter a number between 0-300:",
                0,
                300);
        std::cout << "Valid Input" << std::endl;
    }
    system("pause");
}

/*
 * Runs a game between two dealers and records the result
 */
void runPseudoGame(deck &cards, unitData &data) {
    hand playerOne;
    hand playerTwo;

    addCard(playerOne, drawCard(cards));
    addCard(playerTwo, drawCard(cards));
    addCard(playerOne, drawCard(cards));
    addCard(playerTwo, drawCard(cards));

    dealerTurn(playerOne, cards);
    dealerTurn(playerTwo, cards);

    /* Average hand size */
    data.averageHandSize = ((double)playerOne.handSize + (double)playerTwo.handSize + data.averageHandSize) / 3;
    /* Average hand score */
    data.averageHandScore = ((double)playerOne.score + (double)playerTwo.score + data.averageHandScore) / 3;
    /* Number of Blackjacks */
    data.blackjacks += (int)(playerOne.type == Blackjack) + (int)(playerTwo.type == Blackjack);
    /* Cards drawn */
    data.cardsDrawn += playerOne.handSize + playerTwo.handSize;

    /* Games played */
    data.gamesPlayed += 1;

    /* Shuffle the cards */
    if (cards.shuffle) {
        /* Check if it has looped back to the start */
        if (cards.cardPtr < cards.shufflePtr) {
            data.overflows += 1;
        }
        data.shuffles += 1;
        shuffleDeck(cards, std::chrono::steady_clock::now().time_since_epoch().count());
    }

    delete [] playerOne.cards;
    delete [] playerTwo.cards;
}

void runUnitTest() {
    system("cls");
    deck cards;
    generateDeck(cards);
    unitData data;
    int gamesToPlay{ 10000 };
    std::cout << "Games Completed 0%";
    for (int i = 0; i < gamesToPlay; i++) {
        runPseudoGame(cards, data);
        std::cout << "\rGames Completed " << ((i + 1) * 100 / gamesToPlay) << "%";
    }
    std::cout << "\nStats\n"
                 "                  Games Ran: " << data.gamesPlayed << std::endl <<
                 "          Average Hand Size: " << data.averageHandSize << std::endl <<
                 "         Average Hand Score: " << data.averageHandScore << std::endl <<
                 "       Number of Blackjacks: " << data.blackjacks << std::endl <<
                 "      Number of Cards Drawn: " << data.cardsDrawn << std::endl <<
                 "         Number of shuffles: " << data.shuffles << std::endl <<
                 "number of Over-flowed Decks: " << data.overflows << std::endl;
    system("pause");
}
