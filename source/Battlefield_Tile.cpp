#include "Battlefield_Tile.h"

Battlefield_Tile::Battlefield_Tile( const Tile tile, const Team team ) : m_tile(tile)
{
    update_symbol(team);
}

Battlefield_Tile::~Battlefield_Tile()
{
    // printf( "A tile of the battlefield was destroyed!\n" );
}

bool Battlefield_Tile::is_reachable()
{
    auto const t = get_tile();
    return (t == Tile::Normal) + (t == Tile::Fortification) + (t == Tile::Land_Mine) + (t == Tile::Quicksand);
}

void Battlefield_Tile::update_symbol(const Team team, const char ch)
{
    switch( get_tile() )
    {
        case Tile::Normal        : m_symbol = '_'; m_team = Team::Neutral; break;
        case Tile::Unreachable   : m_symbol = 'X'; m_team = Team::Neutral; break;
        case Tile::Tower         : m_symbol = 'T'; m_team = team;          break;
        case Tile::Wall          : m_symbol = 'W'; m_team = team;          break;
        case Tile::Fortification : m_symbol = 'F'; m_team = team;          break;
        case Tile::Obstacle      : m_symbol = 'O'; m_team = Team::Neutral; break;
        case Tile::Land_Mine     : m_symbol = 'M'; m_team = team;          break;
        case Tile::Quicksand     : m_symbol = 'Q'; m_team = team;          break;
        case Tile::Army          : m_symbol =  ch; m_team = team;          break;
    }
}

void Battlefield_Tile::setup_tile(const Tile tile, const Team team, const char ch)
{
    m_tile = tile;
    update_symbol(team, ch);
}

void Battlefield_Tile::reset_tile()
{
    m_tile = Tile::Normal;
    update_symbol();
}