#ifndef TEAM_H
#define TEAM_H

#include <cstdint>
#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif

// #include "../utilities/types.h"

namespace COLORS
{
    const uint8_t WHITE  =  7;
    const uint8_t RED    = 12;
    const uint8_t BLUE   =  9;
    const uint8_t TAN    =  6;
    const uint8_t GREEN  = 10;
    const uint8_t ORANGE =  8;
    const uint8_t PURPLE =  5;
    const uint8_t TEAL   = 11;
    const uint8_t PINK   = 13;
}

enum class Team // might be called Loyalty
{
    Neutral = 0, // available for map object (buildings and creatures). Neutral is not an option for players, but it is the only option for some map objects (obelisks, portals, huts, etc.)
    Red,
    Blue,
    Tan,
    Green,
    Orange,
    Purple,
    Teal,
    Pink,
};

uint8_t get_team_color(const Team team);
void print_colored_string(const char ch, const Team team);
void print_colored_string(const std::string str, const Team team);

#endif