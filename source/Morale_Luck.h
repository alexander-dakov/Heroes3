#ifndef MORALE_LUCK_H
#define MORALE_LUCK_H

// #define NOMINMAX
#include <cstdint>
#ifdef _WIN32
#include <windows.h>
#endif
#undef min
#undef max
#include <algorithm> // for std::min() and std::max()

// #include "../utilities/types.h"

// Morale and Luck in the game are used in similar ways and hold similar values, but are used for different purposes. To segregate them from one another, lets use separate enums and methods.
// How likely is for stack of troops to take initiative during its turn in battle
enum class Morale
{
    Terrible = -3,
    Awful,
    Bad,
    Neutral,
    Good,
    Great,
    Superb
};

// How lucky a stack of troops is when attacking
enum class Luck
{
    Terrible = -3,
    Awful,
    Bad,
    Neutral,
    Good,
    Great,
    Superb
};

// Clamp a given int to a Morale range value. Used when the Morale of a Stack/Hero is modified by an int value. Also used when summing Morale and int values.
inline Morale clamp_morale(int8_t morale)
{
    return (Morale) std::min( std::max( morale, (int8_t)Morale::Terrible ), (int8_t)Morale::Superb );
}

// Clamp a given int to a Luck range value. Used when the Luck of a Stack/Hero is modified by an int value. Also used when summing Luck and int values.
inline Luck clamp_luck(int8_t luck)
{
    return (Luck) std::min( std::max( luck, (int8_t)Luck::Terrible ), (int8_t)Luck::Superb );
}

// Since more than 2 Morale/Luck values might need to get added, lets define the needed operators.

// Allow the use of addition for Morale values with int value, which must return an int, in order to avoid addition with saturation.
// The result of this addition forces the use of clamp functions, when casting back to Morale.
inline int8_t operator+( Morale first, Morale second) { return (int8_t)first + (int8_t)second; }
inline int8_t operator+( Morale first, int8_t second) { return (int8_t)first +         second; }
inline int8_t operator+( int8_t first, Morale second) { return         first + (int8_t)second; }

// Allow the use of addition for Luck values with int value, which must return an int, in order to avoid addition with saturation.
// The result of this addition forces the use of clamp functions, when casting back to Luck.
inline int8_t operator+( Luck   first, Luck   second) { return (int8_t)first + (int8_t)second; }
inline int8_t operator+( Luck   first, int8_t second) { return (int8_t)first +         second; }
inline int8_t operator+( int8_t first, Luck   second) { return         first + (int8_t)second; }

// Allow the use of multiplication between Morale/Luck value and a boolean, to support branchless approach. Return int, to avoid double casts, as it would be used only during addition with other Morale/Luck values, which would then get clamped.
inline int8_t operator*( Morale first, bool   second) { return (int8_t)first * second; }
inline int8_t operator*( bool   first, Morale second) { return first * (int8_t)second; }
inline int8_t operator*( Luck   first, bool   second) { return (int8_t)first * second; }
inline int8_t operator*( bool   first, Luck   second) { return first * (int8_t)second; }

#endif