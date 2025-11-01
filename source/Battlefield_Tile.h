#ifndef BATTLEFIELD_TILE_H
#define BATTLEFIELD_TILE_H

#include <iostream>
#include <cstdint>
#include <vector>

// #include "../utilities/types.h"
#include "Team.h"
#include "Creature_Stack.h"


namespace Battlefield
{
    const uint8_t LENGTH = 15;
    const uint8_t WIDTH  = 11;
    const char ARMY_CHAR = '+'; // used for default army character in function arguments
};


struct Battlefield_Tile
{
    public:
        enum Tile
        {
            Normal,
            Unreachable,   // according to objects and Format
            Tower,         // can be destroyed by catapults, Cyclopses and Cyclops Kings
            Wall,          // can be destroyed by catapults, Cyclopses and Cyclops Kings
            Fortification, // river, lava, etc.
            Obstacle,      // removable with magic
            Land_Mine,     // can be casted TO DO : add visibility
            Quicksand,     // can be casted TO DO : add visibility
            Army
        };
        
    private:
        char m_symbol = '_';
        Tile m_tile = Tile::Normal;
        Team m_team = Team::Neutral; // for representation purposes
    
    public:
        // Default and parametrized constructors, used upon starting a battle, to build the battlefield.
        Battlefield_Tile( const Tile tile = Tile::Normal, const Team team = Team::Neutral );

        // Allow the use of copy constructor by reference.
        Battlefield_Tile( const Battlefield_Tile& battlefield_tile ) : m_symbol(battlefield_tile.m_symbol), m_tile(battlefield_tile.m_tile), m_team(battlefield_tile.m_team) {}

        // Disallow the use of copy constructor by pointer.
        Battlefield_Tile( const Battlefield_Tile* battlefield_tile ) = delete;

        // // Disallow the use of move constructor.
        // Battlefield_Tile(Battlefield_Tile&& battlefield_tile) = delete;

        // Destructor
        ~Battlefield_Tile();
        
        char get_symbol() { return m_symbol; }

        Tile get_tile() { return m_tile; }

        Team get_team() { return m_team; }

        // Returns 'true' if the tile can be reached by a creature stack.
        bool is_reachable();

        // Used to update the symbol and team of a tile accordingly.
        void update_symbol(const Team team = Team::Neutral, const char ch = Battlefield::ARMY_CHAR);

        // Sets the tile, symbol and team accordingly.
        void setup_tile(const Tile tile = Tile::Normal, const Team team = Team::Neutral, const char ch = Battlefield::ARMY_CHAR);

        // Set tile to 'Normal' and team to 'Neutral'. Used when a creature stack moves from a tile / dies or a structure/obstacle gets destroyed.
        void reset_tile();
};

#endif