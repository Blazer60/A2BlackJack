//
// Project: A2BlackJack
// Created by: Ryan Purse 
// Date: 23/11/2020
//

#include "deck.h"

void displayCard(card &card, bool displayIcon) {
    if (displayIcon) {
        /* Sets the mode to Unicode */
        _setmode(_fileno(stdout), _O_U16TEXT);
        std::wcout << card.icon;
        /* Resets back to ASCII */
        _setmode(_fileno(stdout), _O_TEXT);
        std::cout << card.name ;
    }
    else {
        std::cout << card.name << " of " << card.suit;
    }
}

/*
 * Generates a shuffled deck of cards
 */
void generateDeck(card *deck) {
    char suits[4][9] = {"Diamonds", "Hearts", "Spades", "Clubs"};
    char names[13][6] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    std::wstring suitIcon[4] = {DIAMONDS, HEARTS, SPADES, CLUBS};

    for (int i = 0; i < 52; i++) {
        int suitPtr = i % 4;
        int namePtr = i % 13;
        strcpy_s(deck[i].suit, 9, suits[suitPtr]);
        strcpy_s(deck[i].name, 6, names[namePtr]);
        deck[i].value = std::min(namePtr, 10);
        deck[i].icon = suitIcon[suitPtr];
    }

    shuffleDeck(deck, std::chrono::steady_clock::now().time_since_epoch().count());
}

void shuffleDeck(card *deck, unsigned int seed) {
    for (int i = 0; i < 52; i++) {
        std::swap(deck[i], deck[seed * i % 52]);
    }
}
