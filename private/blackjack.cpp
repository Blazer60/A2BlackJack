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

    std::cout << "Player Hand" << std::endl;
    displayHand(player, "Player", true, false, false);

    std::cout << "Dealer Hand" << std::endl;
    displayHand(player, "Dealer", true, true, false);

    std::cout << "Dealer Hand w/ debug" << std::endl;
    displayHand(player, "Dealer", true, true, true);

    std::cout << "this would go to an actual game but it isn't implemented yet" << std::endl;
}
