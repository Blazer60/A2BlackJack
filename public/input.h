//
// Project: A2BlackJack
// Created by: Ryan Purse 
// Date: 01/01/2021
//

#ifndef A2BLACKJACK_INPUT_H
#define A2BLACKJACK_INPUT_H

bool isNull(char input[]);
bool isInteger(char input[], bool displayError);
bool inRange(int num, int min, int max);
bool contains(char *input, char *options);
int charToInt(char input[]);
void toLower(char input[]);
int integerInput(char message[], int min, int max);
char characterInput(char message[], char options[], bool allowNumbers = false);

#endif //A2BLACKJACK_INPUT_H
