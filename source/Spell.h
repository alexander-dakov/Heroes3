#ifndef SPELL_H
#define SPELL_H

#include <iostream>
#include <cstdint>

#include "Skill_level.h"


class Spell
{
    public:
        enum School_of_magic
        {
            Air = 1, // 1
            Water,   // 2
            Earth,   // 3
            Fire     // 4
        };

        enum Level
        {
            None,   // 0 - for coding purposes
            First,  // 1
            Second, // 2
            Third,  // 3
            Fourth, // 4
            Fifth   // 5
        };

        enum Effect
        {
            Defensive = 1, // 1
            Offensive,     // 2
            Deal_damage    // 3
        };

    private:
        std::string m_name;
        School_of_magic m_school_of_magic;
        Level m_spell_level;
        Skill_level m_skill_level;
        std::string m_mana_cost;
        Effect m_effect;
        std::string m_description;
        uint8_t m_duration;

    private:
        // Default constructor.
        Spell() = delete;

        // Disallow the use of copy constructor.
        Spell(const Spell& spell) = delete;

        // Disallow the use of move constructor.
        Spell(Spell&& spell) = delete;

        // Destructor.
        ~Spell() {}
        
    public:
        // Getters.
        std::string get_name() const { return m_name; }

        School_of_magic get_school_of_magic() const { return m_school_of_magic; }

        Level get_spell_level() const { return m_spell_level; }

        Skill_level get_skill_level() const { return m_skill_level; }

        std::string get_mana_cost() const { return m_mana_cost; }

        Effect get_effect() const { return m_effect; } 

        std::string get_description() const { return m_description; }

        uint8_t get_duration() const { return m_duration; }
};


#endif