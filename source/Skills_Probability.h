#ifndef SKILLS_PROBABILITY_H
#define SKILLS_PROBABILITY_H

#include <iostream>
#include <cstdint>

// #include "../utilities/types.h"

namespace
{
    const uint8_t NUM_GROUPS = 2;
    const uint8_t NUM_PRIMARY_SKILLS = 4;
}

// Whenever a hero levels up, he/she gains a Primary Skill bonus depending on the class
// Primary Skills for each class ordered in 2 groups - before and after hero reaches level 10
// Primary Skills ordered                                      = { {  a,  d,  p,  k,}, { a10,d10,p10,k10 } }
const uint8_t p_s_knight[NUM_GROUPS][NUM_PRIMARY_SKILLS]       = { { 35, 45, 10, 10 }, { 30, 30, 20, 20 } };
const uint8_t p_s_cleric[NUM_GROUPS][NUM_PRIMARY_SKILLS]       = { { 20, 15, 30, 35 }, { 20, 20, 30, 30 } };
const uint8_t p_s_ranger[NUM_GROUPS][NUM_PRIMARY_SKILLS]       = { { 35, 45, 10, 10 }, { 30, 30, 20, 20 } };
const uint8_t p_s_druid[NUM_GROUPS][NUM_PRIMARY_SKILLS]        = { { 10, 20, 35, 35 }, { 20, 20, 30, 30 } };
const uint8_t p_s_alchemist[NUM_GROUPS][NUM_PRIMARY_SKILLS]    = { { 30, 30, 20, 20 }, { 30, 30, 20, 20 } };
const uint8_t p_s_wizard[NUM_GROUPS][NUM_PRIMARY_SKILLS]       = { { 10, 10, 40, 40 }, { 30, 20, 20, 30 } };
const uint8_t p_s_demoniac[NUM_GROUPS][NUM_PRIMARY_SKILLS]     = { { 35, 35, 15, 15 }, { 30, 30, 20, 20 } };
const uint8_t p_s_heretic[NUM_GROUPS][NUM_PRIMARY_SKILLS]      = { { 15, 15, 35, 35 }, { 20, 20, 30, 30 } };
const uint8_t p_s_death_knight[NUM_GROUPS][NUM_PRIMARY_SKILLS] = { { 30, 25, 20, 25 }, { 25, 25, 25, 25 } };
const uint8_t p_s_necromancer[NUM_GROUPS][NUM_PRIMARY_SKILLS]  = { { 15, 15, 35, 35 }, { 25, 25, 25, 25 } };
const uint8_t p_s_overlord[NUM_GROUPS][NUM_PRIMARY_SKILLS]     = { { 35, 35, 15, 15 }, { 30, 30, 20, 20 } };
const uint8_t p_s_warlock[NUM_GROUPS][NUM_PRIMARY_SKILLS]      = { { 10, 10, 50, 30 }, { 20, 20, 30, 30 } };
const uint8_t p_s_barbarian[NUM_GROUPS][NUM_PRIMARY_SKILLS]    = { { 55, 35,  5,  5 }, { 30, 30, 20, 20 } };
const uint8_t p_s_battle_mage[NUM_GROUPS][NUM_PRIMARY_SKILLS]  = { { 30, 20, 25, 25 }, { 25, 25, 25, 25 } };
const uint8_t p_s_beastmaster[NUM_GROUPS][NUM_PRIMARY_SKILLS]  = { { 30, 50, 10, 10 }, { 30, 30, 20, 20 } };
const uint8_t p_s_witch[NUM_GROUPS][NUM_PRIMARY_SKILLS]        = { {  5, 15, 40, 40 }, { 20, 20, 30, 30 } };
const uint8_t p_s_planeswalker[NUM_GROUPS][NUM_PRIMARY_SKILLS] = { { 45, 25, 15, 15 }, { 30, 30, 20, 20 } };
const uint8_t p_s_elementalist[NUM_GROUPS][NUM_PRIMARY_SKILLS] = { { 15, 15, 35, 35 }, { 25, 25, 25, 25 } };
const uint8_t p_s_captain[NUM_GROUPS][NUM_PRIMARY_SKILLS]      = { { 45, 25, 20, 10 }, { 30, 30, 20, 20 } };
const uint8_t p_s_navigator[NUM_GROUPS][NUM_PRIMARY_SKILLS]    = { { 15, 10, 40, 35 }, { 30, 20, 20, 30 } };

#endif