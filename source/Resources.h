#ifndef RESOURCES_H
#define RESOURCES_H

#include <cstdint>

// #include "../utilities/types.h"

struct Resources
{
    uint32_t Gold;
    uint32_t Wood;
    uint32_t Ore;
    uint32_t Mercury;
    uint32_t Sulfur;
    uint32_t Crystals;
    uint32_t Gems;

    // Disallow the use of default constructor.
    Resources() = delete;

    // Allow the use of parametrized constructor.
    Resources(uint32_t gold = 0, uint32_t mercury = 0, uint32_t sulfur = 0, uint32_t crystals = 0, uint32_t gems = 0, uint32_t wood = 0, uint32_t ore = 0 ) :
    Gold(gold), Mercury(mercury), Sulfur(sulfur), Crystals(crystals), Gems(gems), Wood(wood), Ore(ore)
    {}

    // Allow the use of a copy constructor by reference.
    Resources(const Resources& resources) :
    Gold(resources.Gold), Mercury(resources.Mercury), Sulfur(resources.Sulfur), Crystals(resources.Crystals), Gems(resources.Gems), Wood(resources.Wood), Ore(resources.Ore)
    {}

    // Disallow the use of a copy constructor by pointer.
    Resources(const Resources* resources) = delete;

    // Disallow the use of move constructor.
    Resources(Resources&& resources) = delete;
};

#endif