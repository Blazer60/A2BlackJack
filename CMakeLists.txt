cmake_minimum_required(VERSION 3.17)
project(A2BlackJack)

set(CMAKE_CXX_STANDARD 14)

add_executable(A2BlackJack private/main.cpp private/components/deck.cpp public/components/deck.h private/input.cpp public/input.h private/blackjack.cpp public/blackjack.h private/components/hand.cpp public/components/hand.h private/components/playingCard.cpp public/components/playingCard.h private/settings.cpp public/settings.h)