#ifndef POSITION_H
#define POSITION_H

#include "types.h"

// coords of point on the adventure map or on the battle field
struct Position
{
       public:
              uint8_t x;
              uint8_t y;
              
              Position(const uint8_t X, const uint8_t Y) : x(X), y(Y) {};
              Position(const Position& c) : x(c.x),  y(c.y)  {};
              Position(const Position* c) : x(c->x), y(c->y) {};
              
              Position& operator=(const Position& other)
              {
                     this->x = other.x;
                     this->y = other.y;
                     return *this;
              }
};

#endif
