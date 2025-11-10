#include "Team.h"

// Returns the int value of the color coresponding to the given team.
uint8_t get_team_color(const Team team)
{
    uint8_t color = COLORS::WHITE; // default color for printing is white

    switch (team)
    {
        case Team::Neutral : color = COLORS::WHITE;  break; // not used but written for programming purposes
        case Team::Red     : color = COLORS::RED;    break;
        case Team::Blue    : color = COLORS::BLUE;   break;
        case Team::Tan     : color = COLORS::TAN;    break;
        case Team::Green   : color = COLORS::GREEN;  break;
        case Team::Orange  : color = COLORS::ORANGE; break;
        case Team::Purple  : color = COLORS::PURPLE; break;
        case Team::Teal    : color = COLORS::TEAL;   break;
        case Team::Pink    : color = COLORS::PINK;   break;
        default            : color = COLORS::WHITE;  break; // not used but written for programming purposes
    }

    return color;
}

// Prints a given character in the color coresponding to the team it refers.
void print_colored_string(const char ch, const Team team)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // used for coloring output text
    uint8_t color = get_team_color(team);
    SetConsoleTextAttribute(hConsole, color);

    printf("%c", ch);
    SetConsoleTextAttribute(hConsole, COLORS::WHITE); // to make sure the rest of the text is in white
}

// Prints a given string in the color coresponding to the team it refers.
void print_colored_string(const std::string str, const Team team)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // used for coloring output text
    uint8_t color = get_team_color(team);
    SetConsoleTextAttribute(hConsole, color);

    printf("%s", str.c_str());
    SetConsoleTextAttribute(hConsole, COLORS::WHITE); // to make sure the rest of the text is in white
}