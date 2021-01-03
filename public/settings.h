//
// Project: A2BlackJack
// Created by: Ryan Purse 
// Date: 02/01/2021
//

#ifndef A2BLACKJACK_SETTINGS_H
#define A2BLACKJACK_SETTINGS_H

bool g_debug = false;
bool g_showIcons = true;

void displaySettingsInfo(bool &debug, bool showIcons);
void setSetting(bool &setting);
void settingsMenu(bool &debug, bool &showIcons);

#endif //A2BLACKJACK_SETTINGS_H
