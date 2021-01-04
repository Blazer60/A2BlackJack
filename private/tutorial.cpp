//
// Project: A2BlackJack
// Created by: Ryan Purse 
// Date: 04/01/2021
//

#include "../public/tutorial.h"
#include <iostream>

void displayTutorial() {
    system("cls");

    std::cout << "The aim of Blackjack is to get as close to 21 whie not going over.\n"
                 "Any player that goes over 21 is considered bust and has lost \n"
                 "Regardless of their hand.\n"
                 "Additionally any player that has Blackjack (an ace and a ten\n"
                 "Value card) automatically wins unless the dealer also has\n"
                 "Blackjack.\n" << std::endl;

    system("pause");
    std::cout << std::endl;

    std::cout << "This game consists of a single deck of cards that is shuffled before\n"
                 "The game starts. Additionally, it is shuffled at the end or a round \n"
                 "when the number cards dealt overall exceeds 42 cards. You will \n"
                 "be told when the deck is shuffled.\n" << std::endl;

    system("pause");
    std::cout << std::endl;

    std::cout << "Each card has a value assigned to them. 2 through 10 have their\n"
                 "Face value. J, Q, K are all worth 10 points. Ace is worth both 11\n"
                 "And 1. (The game will automatically select the highest possible\n"
                 "Hand for you)\n" << std::endl;

    system("pause");
    std::cout << std::endl;

    std::cout << "Before the game starts you may bet any amount of money in\n"
                 "Your pot. Upon doing so, the dealer will give each player two\n"
                 "cards. \n"
                 "To increase the score of your hand, you can hit. This will give you\n"
                 "An additional card. When you want to stop drawing cards, you\n"
                 "Can choose stand.\n" << std::endl;

    system("pause");
    std::cout << std::endl;

    std::cout << "The dealer will then play after you have gone bust or decided\n"
                 "to stand. They will hit if their hand is below 17.\n" << std::endl;

    system("pause");
    std::cout << std::endl;

    std::cout << "When the dealer has finished their turn. Credits will be rewarded.\n"
                 "Results in order of importance:\n"
                 "Your Bust: 0 Credits\n"
                 "Dealer Bust: 2x Credits\n"
                 "\n"
                 "Both have Blackjack?: 1x Credits\n"
                 "You have Blackjack: 2x Credits + 0.5x Credits\n"
                 "Dealer has Blackjack: 0 Credits\n"
                 "\n"
                 "Both have equal score?: 1x Credits\n"
                 "You have higher Score?: 2x credits\n"
                 "You have lower Score?: 0 Credits\n" << std::endl;

    system("pause");
    std::cout << std::endl;

    std::cout << "If your pot reaches 0 credits at the end of the round, you’ll be forced\n"
                 "To restart the game. Additionally, you can quit at the end of any\n"
                 "Round. This will reset your credits in both instances.\n" << std::endl;

    std::cout << "This is the end of the tutorial" << std::endl;
    system("pause");
    std::cout << std::endl;
}
