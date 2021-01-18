//
// Project: A2BlackJack
// Created by: Ryan Purse 
// Date: 01/01/2021
//

#ifndef A2BLACKJACK_INPUT_H
#define A2BLACKJACK_INPUT_H


/* Input Checks */
bool contains(char *input, char *options);                  // enum Check
bool isInteger(char *input, bool displayError);             // Type Check
bool isNull(char *input);                                   // Null Check
bool inRange(int num, int min, int max, bool displayError); // Range Check
bool inLength(char *input, int maxLength);                  // Length Check

/* Conversions */
int charToInt(char *input);
void toLower(char *input);

/* Input Validation */
char characterInput(char *message, char *options, bool allowNumbers = false);
int integerInput(char *message, int min, int max);

#endif //A2BLACKJACK_INPUT_H
