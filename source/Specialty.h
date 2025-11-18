#ifndef SPECIALTY_H
#define SPECIALTY_H

#include <iostream>
#include <cstdint>



struct Specialty
{
    private:
        std::string m_name;
        std::string m_effect;

    public:
        // Disallow the use of default constructor.
        Specialty() = delete;

        // Parametrized constructor.
        Specialty( const std::string& name, const std::string& effect ) : m_name(name), m_effect(effect) {}

        // Copy constructor by reference is used in Hero constructor.
        Specialty( const Specialty& specialty ) : m_name(specialty.m_name), m_effect(specialty.m_effect) {}

        // Disallow the use of move constructor.
        Specialty( Specialty&& specialty ) = delete;

        // Getters.
        std::string get_name()   { return m_name;   }
        std::string get_effect() { return m_effect; }
};

#endif