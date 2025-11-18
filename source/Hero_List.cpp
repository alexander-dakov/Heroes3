#ifndef HERO_LIST_CPP
#define HERO_LIST_CPP

#include "Hero.h"
#include "Specialty_List.cpp"
#include "Secondary_Skill_List.cpp"
#include "../utilities/user_macros.h"

const std::map<Heroes, Hero*>& Hero::create_and_fill_heroes_list()
{
    static Hero Dummy(     Heroes::Dummy,     Hero::Gender::Male,   Hero::Role::Might, Faction::Neutral,    Team::Neutral, 0, 0, { 0, 0, 0, 0 }, Specialty_List::None,    Morale::Neutral,  Luck::Neutral, { false, false, false, false }, false );
    static Hero Him(       Heroes::Him,       Hero::Gender::Male,   Hero::Role::Might, Faction::Neutral,    Team::Red,     0, 0, { 8, 7, 0, 0 }, Specialty_List::None,    Morale::Neutral,  Luck::Neutral, { false, false, false, false }, false );
    static Hero Her(       Heroes::Her,       Hero::Gender::Female, Hero::Role::Might, Faction::Neutral,    Team::Tan,     0, 0, { 2, 3, 0, 0 }, Specialty_List::None,    Morale::Terrible, Luck::Superb,  { false, false, false, false }, false );

    // Castle
    static Hero Orrin(     Heroes::Orrin,     Hero::Gender::Male,   Hero::Role::Might, Faction::Castle,     Team::Neutral, 1, 0, { 2, 2, 1, 1 }, Specialty_List::Archery, Morale::Neutral,  Luck::Neutral, { false, false, false, false }, false );

    // Stronghold
    static Hero Crag_Hack( Heroes::Crag_Hack, Hero::Gender::Male,   Hero::Role::Might, Faction::Stronghold, Team::Neutral, 1, 0, { 4, 0, 1, 1 }, Specialty_List::Offense, Morale::Neutral,  Luck::Neutral, { false, false, false, false }, false );

    // Fortress
    static Hero Tazar(     Heroes::Tazar,     Hero::Gender::Male,   Hero::Role::Might, Faction::Fortress,   Team::Neutral, 1, 0, { 0, 4, 1, 1 }, Specialty_List::Armorer, Morale::Neutral,  Luck::Neutral, { false, false, false, false }, false );

    static const std::map<Heroes, Hero*> Hero_List =
    {
        {Heroes::Dummy, &Dummy},
        {Heroes::Him, &Him},
        {Heroes::Her, &Her},

        // Castle
        {Heroes::Orrin, &Orrin},

        // Stronghold
        {Heroes::Crag_Hack, &Crag_Hack},

        // Fortress
        {Heroes::Tazar, &Tazar},
    };

    ASSERT( created_heroes == Hero_List.size(), "Hero_List map is incomplete!" );

    return Hero_List;
}

#endif