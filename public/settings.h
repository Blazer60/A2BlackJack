//
// Project: A2BlackJack
// Created by: Ryan Purse 
// Date: 02/01/2021
//

#ifndef A2BLACKJACK_SETTINGS_H
#define A2BLACKJACK_SETTINGS_H

/* Globals */
extern bool g_debug;
extern bool g_showIcons;

/* Logic & input */
void setSetting(bool &setting);
void settingsMenu();

/* Render */
void displaySettingsInfo();

#endif //A2BLACKJACK_SETTINGS_H
