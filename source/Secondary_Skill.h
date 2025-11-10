#ifndef SECONDARY_SKILL_H
#define SECONDARY_SKILL_H

#include <iostream>
#include <cstdint>

#include "Skill_level.h"


struct Secondary_Skill
{
    private:
        Skill_level m_level;
        std::string m_name;
        std::string m_effect;

    public:
        // Disallow the use of default constructor.
        Secondary_Skill() = delete;

        // Parametrized constructor.
        Secondary_Skill(Skill_level level, std::string name, std::string effect) : m_level(level), m_name(name), m_effect(effect) {}

        // Disallow the use of copy constructor.
        Secondary_Skill(const Secondary_Skill& secondary_skill) = delete;

        // Disallow the use of move constructor.
        Secondary_Skill(Secondary_Skill&& secondary_skill) = delete;

        // Getters.
        Skill_level get_level()  { return m_level;  }
        std::string get_name()   { return m_name;   }
        std::string get_effect() { return m_effect; }
};

#endif