//
// Project: A2BlackJack
// Created by: Ryan Purse 
// Date: 01/01/2021
//

#include "../public/blackjack.h"

void blackjack() {
    deck cards;
    hand player;
    generateDeck(cards);

    addCard(player, drawCard(cards));
    addCard(player, drawCard(cards));

    displayHand(player, "Player");

    std::cout << "this would go to an actual game but it isn't implemented yet" << std::endl;
}
