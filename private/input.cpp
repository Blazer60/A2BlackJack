//
// Project: A2BlackJack
// Created by: Ryan Purse 
// Date: 01/01/2021
//


#include "../public/input.h"
#include <iostream>
#include <string>

/*
 * Determines if an input character is within the options.
 * It will only test against the first character.
 */
bool contains(char *input, char *options) {
    /* See if the option is in the list */
    for (int i = 0; options[i] != '\0'; i++) {
        if (options[i] == input[0]) {
            return true;
        }
    }

    /* Error message to the user */
    std::cout << std::endl << "Please enter ";
    for (int i = 0; options[i] != '\0'; i++) {
        if (options[i + 1] == '\0') {
            std::cout << "or ";
        }
        std::cout << options[i];
        if (options[i + 1] != '\0') {
            std::cout << ", ";
        }
    }
    std::cout << " to continue: ";
    return false;
}

/*
 * For each character in the input, make sure that it is within 0-9
 * also checks for negatives
 * return true if the input is a number.
 */
bool isInteger(char *input, bool displayError) {
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

/*
 * Returns true if nothing is in the list
 * C++ requires an input and so does this
 * automatically
 */
bool isNull(char *input) {
    if (std::strlen(input) == 0) {
        std::cout << std::endl << "Please enter something: ";
        return true;
    }
    return false;
}

bool inRange(int num, int min, int max, bool displayError) {
    if (min <= num && num <= max) {
        return true;
    }
    if (displayError) {
        std::cout << std::endl << "please enter a number between " << min << " and " << max << ": ";
    }
    return false;
}

/*
 * Converts Ascii to an integer
 */
int charToInt(char *input) {
    int base = 1;
    int intInput = 0;
    for (int i = std::strlen(input) - 1; i >= 0; i--) {
        /* Handle negative */
        if (input[i] == '-') {
            intInput = -intInput;
        }
        else {
            intInput += (input[i] - '0') * base;
            base *= 10;
        }
    }
    return intInput;
}

/*
 * Converts all alphabetical
 * characters to lower case
 */
void toLower(char *input) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            input[i] = input[i] + 'z' - 'Z';
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

        /* Hidden Number check - No errors will be shown */
        if (allowNumbers) {
            if(isInteger(input, false)) {
                if (inRange(charToInt(input), 1, std::strlen(options), false)) {
                    return input[0];
                }
            }
        }

        toLower(input);
        /* Enum Check */
        if (contains(input, options)) {
            return input[0];
        }
    }
}

/*
 * Returns an integer that can
 * be used as an input
 */
int integerInput(char *message, int min, int max) {
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
        if (inRange(intInput, min, max, true)) {
            return intInput;
        }
    }
}
