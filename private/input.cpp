//
// Project: A2BlackJack
// Created by: Ryan Purse 
// Date: 01/01/2021
//

#include "../public/input.h"
#include <iostream>
#include <string>

bool isNull(char *input) {
    /*
     * Check if a string is empty
     * return true if it is
     */
    if (std::strlen(input) == 0) {
        std::cout << std::endl << "Please enter something: ";
        return true;
    }
    return false;
}

bool isInteger(char input[], bool displayError) {
    /*
     * For each character in the input, make sure that it is within 0-9
     * also checks for negatives
     * return true if the input is a number.
     */
    for (int i = 0; input[i] != '\0'; i++) {
        if (i == 0 && input[i] == '-') {
            continue;
        }
        else if (input[i] < '0' || input[i] > '9') {
            if (displayError) {
                std::cout << std::endl << "please enter a number: ";
            }
            return false;
        }
    }
    return true;
}

bool inRange(int num, int min, int max) {
    /*
     * Test the number against the specified range
     * min and max are included
     */
    if (min <= num && num <= max) {
        return true;
    }
    std::cout << std::endl << "please enter a number between " << min << " and " << max << ": ";
    return false;
}

bool contains(char *input, char *options) {
    /*
     * Determines if an input character
     * is within a string
     */

    /* See if the option is in the list */
    for (int i = 0; options[i] != '\0'; i++) {
        if (options[i] == input[0]) {
            return true;
        }
    }

    /* Error message to the user */
    std::cout << std::endl << "Please enter ";
    for (int i = 0; options[i] != '\0'; i++) {
        std::cout << options[i];
        if (options[i + 1] != '\0') {
            std::cout << ", ";
        }
    }
    std::cout << " to continue: ";
    return false;
}

int charToInt(char *input) {
    /*
     * Convert the Ascii to an integer
     */
    int base = 1;
    int intInput = 0;
    for (int i = std::strlen(input) - 1; i >= 0; i--) {
        if (input[i] == '-') {
            /* Handle negative */
            intInput = -intInput;
        }
        else {
            intInput += (input[i] - '0') * base;
            base *= 10;
        }
    }
    return intInput;
}

void toLower(char *input) {
    /*
     * Converts all alphabetical
     * character to lower case
     */
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] > 'A' && input[i] < 'Z') {
            input[i] = input[i] - 'Z' - 'z';
        }
    }
}

int integerInput(char *message, int min, int max) {
    /*
     * Returns an integer that can
     * be used as an input
     */
    char input[60];
    std::cout << message;
    for (;;) {
        std::cin >> input;

        /* Null Check */
        if (isNull(input)) {
            continue;
        }

        /* Type Check */
        if (!isInteger(input, true)) {
            continue;
        }

        /* Range Check */
        int intInput = charToInt(input);
        if (inRange(intInput, min, max)) {
            return intInput;
        }
    }
}

char characterInput(char *message, char *options, bool allowNumbers) {
    char input[60];
    std::cout << message;
    for (;;) {
        std::cin >> input;

        /* Null Check */
        if (isNull(input)) {
            continue;
        }

        /* Hidden Number check */
        if (allowNumbers) {
            if(isInteger(input, false)) {
                return input[0];
            }
        }

        toLower(input);
        /* Enum Check */
        if (contains(input, options)) {
            return input[0];
        }
    }
}
