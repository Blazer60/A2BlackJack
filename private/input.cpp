//
// Project: A2BlackJack
// Created by: Ryan Purse 
// Date: 01/01/2021
//

#include "../public/input.h"
#include <iostream>
#include <string>

bool isNull(char *input) {
    if (std::strlen(input) == 0) {
        std::cout << std::endl << "Please enter something: ";
        return true;
    }
    return false;
}

bool isInteger(char *input) {
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
            std::cout << std::endl << "please enter a number: ";
            return false;
        }
    }
    return true;
}

bool inRange(int num, int min, int max) {
    if (min <= num && num <= max) {
        return true;
    }
    std::cout << std::endl << "please enter a number between " << min << " and " << max << ": ";
    return false;
}

bool contains(char *input, char *options) {
    for (int i = 0; options[i] != '\0'; i++) {
        if (options[i] == input[0]) {
            return true;
        }
    }
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
    /* Convert the Ascii to an integer */
    int base = 1;
    int intInput = 0;
    for (int i = std::strlen(input); i > 0; i--) {
        if (input[i] == '-') {
            /* Handle negative */
            intInput = -intInput;
        }
        else {
            intInput += (input[i] - '0') * base;
            base *= 10;
        }
    }
    return 0;
}

void toLower(char *input) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] > 'A' && input[i] < 'Z') {
            input[i] = input[i] - 'Z' - 'z';
        }
    }
}

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
        if (!isInteger(input)) {
            continue;
        }

        /* Range Check */
        int intInput = charToInt(input);
        if (inRange(intInput, min, max)) {
            return intInput;
        }
    }
}

char characterInput(char *message, char *options) {
    char input[60];
    std::cout << message;
    for (;;) {
        std::cin >> message;

        /* Null Check */
        if (isNull(input)) {
            continue;
        }

        toLower(input);
        /* Enum Check */
        if (contains(input, options)) {
            return input[0];
        }
    }
}
