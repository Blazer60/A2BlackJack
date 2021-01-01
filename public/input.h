//
// Project: A2BlackJack
// Created by: Ryan Purse 
// Date: 01/01/2021
//

#ifndef A2BLACKJACK_INPUT_H
#define A2BLACKJACK_INPUT_H

bool isNull(char input[]);
bool isInteger(char input[]);
bool inRange(int num, int min, int max);
bool enumCheck(char input[], enum options);
int charToInt(char input[]);
int integerInput(char message[], int min, int max);
char characterInput(char message[], enum options);

#endif //A2BLACKJACK_INPUT_H
