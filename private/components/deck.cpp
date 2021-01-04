//
// Project: A2BlackJack
// Created by: Ryan Purse 
// Date: 23/11/2020
//

#include <iomanip>
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
        cards.deck[i].value = namePtr == 0? 11 :  std::min(namePtr + 1, 10);
        cards.deck[i].icon = suitIcon[suitPtr];
    }

    shuffleDeck(cards, std::chrono::steady_clock::now().time_since_epoch().count());
}

void shuffleDeck(deck &cards, unsigned int seed) {
    for (int i = 0; i < 52; i++) {
        std::swap(cards.deck[i], cards.deck[seed * i % 52]);
    }
    /* Reset deck stats */
    cards.shuffle = false;
    cards.cardPtr = 0;
}

void displayDeckInfo(deck &cards, int cardsOnField) {
    int deckSize, discardSize;

    if (cards.shuffle) {
        discardSize = 52 - cardsOnField;
        deckSize = 0;
    }
    else {
        discardSize = cards.cardPtr - cardsOnField;
        deckSize = 52 - cards.cardPtr;
    }

    /* Display info */
    int offSet = deckSize > 0 ? 40 - (int)log10((double)deckSize) : 40;
    offSet -= discardSize > 0 ? (int)log10((double)discardSize) + 1 : 1;
    std::cout << "Deck: " << deckSize << std::setw(offSet) << "Discard Pile: " << discardSize << std::endl;
}

playingCard drawCard(deck &cards) {
    playingCard newCard = cards.deck[cards.cardPtr];
    cards.cardPtr = (cards.cardPtr + 1) % 52;
    if (!cards.shuffle) {
        cards.shuffle = cards.cardPtr > cards.shufflePtr;
    }
    return newCard;
}
