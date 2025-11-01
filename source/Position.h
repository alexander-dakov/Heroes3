#ifndef POSITION_H
#define POSITION_H

#include <cstdint>

// #include "../utilities/types.h"

// coords of point on the adventure map or on the battle field
struct Position
{
       uint8_t x;
       uint8_t y;
       
       // Disallow the use of default constructor.
       // Position() = default;// = delete
       Position() : x(-1), y(-1) {} // = delete

       // Parametrized constructor.
       Position(const uint8_t X, const uint8_t Y) : x(X), y(Y) {}

       // Copy constructors.
       Position(const Position& position) : x(position.x),  y(position.y)  {}
       Position(const Position* position) : x(position->x), y(position->y) {}

       // Disallow the use of move constructor.
       Position(Position&& position);// = delete;
       
       Position& operator=(const Position& other)
       {
              this->x = other.x;
              this->y = other.y;
              return *this;
       }

       bool operator==(const Position& other)
       {
              return x == other.x && y == other.y;
       }
};

#endif
