//
// Project: A2BlackJack
// Created by: Ryan Purse 
// Date: 23/11/2020
//

#include "../../public/components/deck.h"



void generateDeck(deck &cards) {
    char suits[4][9] = {"Diamonds", "Hearts", "Spades", "Clubs"};
    char names[13][6] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    std::wstring suitIcon[4] = {DIAMONDS, HEARTS, SPADES, CLUBS};

    for (int i = 0; i < 52; i++) {
        int suitPtr = i % 4;
        int namePtr = i % 13;
        strcpy_s(cards.deck[i].suit, 9, suits[suitPtr]);
        strcpy_s(cards.deck[i].name, 6, names[namePtr]);
        cards.deck[i].value = namePtr == 0? 11 :  std::min(namePtr, 10);
        cards.deck[i].icon = suitIcon[suitPtr];
    }

    shuffleDeck(cards, std::chrono::steady_clock::now().time_since_epoch().count());
}

void shuffleDeck(deck &cards, unsigned int seed) {
    for (int i = 0; i < 52; i++) {
        std::swap(cards.deck[i], cards.deck[seed * i % 52]);
    }
}

playingCard drawCard(deck &cards) {
    playingCard newCard = cards.deck[cards.cardPtr];
    cards.cardPtr = (cards.cardPtr + 1) % 52;
    cards.shuffle = cards.cardPtr > cards.shufflePtr && !cards.shuffle;
    return newCard;
}