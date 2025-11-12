#ifndef CREATURE_LIST_CPP
#define CREATURE_LIST_CPP

#include "Creature.h"
#include "../utilities/user_macros.h"

const std::map<CreatureType, const Creature*>& Creature::create_and_fill_creatures_list()
{
    //                                     type,                                             faction,      level,   upgrade level,   growth, 2_hex,  A,  D,  S, mD, MD, hp, speed,  morale,           luck,       fight, ai, { gold, m, s, c, g }, special abilities
    // Castle
    static const Creature Pikeman (             CreatureType::Pikeman,             Faction::Castle,     1, Creature::Upgrade_level::None,   14, false,  4,  5,  0,  1,  3,  10,  4, Morale::Good,    Luck::Neutral,  100,   80, {   60, 0, 0, 0, 0 }, "Immune to jousting.");
    static const Creature Halberdier (          CreatureType::Halberdier,          Faction::Castle,     1, Creature::Upgrade_level::First,  14, false,  6,  5,  0,  2,  3,  10,  5, Morale::Good,    Luck::Neutral,  115,  115, {   75, 0, 0, 0, 0 }, "Immune to jousting.");
    static const Creature Archer (              CreatureType::Archer,              Faction::Castle,     2, Creature::Upgrade_level::None,    9, false,  6,  3, 12,  2,  3,  10,  4, Morale::Good,    Luck::Neutral,  115,  126, {  100, 0, 0, 0, 0 }, "Ranged attack.");
    static const Creature Marksman (            CreatureType::Marksman,            Faction::Castle,     2, Creature::Upgrade_level::First,   9, false,  6,  3, 24,  2,  3,  10,  6, Morale::Good,    Luck::Neutral,  115,  184, {  150, 0, 0, 0, 0 }, "Ranged attack. Double attack.");
    static const Creature Griffin (             CreatureType::Griffin,             Faction::Castle,     3, Creature::Upgrade_level::None,    7, true,   8,  8,  0,  3,  6,  25,  6, Morale::Good,    Luck::Neutral,  324,  351, {  200, 0, 0, 0, 0 }, "Flying. Two retaliations.");
    static const Creature Royal_Griffin (       CreatureType::Royal_Griffin,       Faction::Castle,     3, Creature::Upgrade_level::First,   7, true,   9,  9,  0,  3,  6,  25,  9, Morale::Good,    Luck::Neutral,  364,  448, {  240, 0, 0, 0, 0 }, "Flying. Unlimited retaliations.");
    static const Creature Swordsman (           CreatureType::Swordsman,           Faction::Castle,     4, Creature::Upgrade_level::None,    4, false, 10, 12,  0,  6,  9,  35,  5, Morale::Good,    Luck::Neutral,  445,  445, {  300, 0, 0, 0, 0 }, "");
    static const Creature Crusader (            CreatureType::Crusader,            Faction::Castle,     4, Creature::Upgrade_level::First,   4, false, 12, 12,  0,  7, 10,  35,  6, Morale::Good,    Luck::Neutral,  588,  588, {  400, 0, 0, 0, 0 }, "Double attack.");
    static const Creature Monk (                CreatureType::Monk,                Faction::Castle,     5, Creature::Upgrade_level::None,    3, false, 12,  7, 12, 10, 12,  30,  5, Morale::Good,    Luck::Neutral,  582,  485, {  400, 0, 0, 0, 0 }, "Ranged attack.");
    static const Creature Zealot (              CreatureType::Zealot,              Faction::Castle,     5, Creature::Upgrade_level::First,   3, false, 12, 10, 24, 10, 12,  30,  7, Morale::Good,    Luck::Neutral,  500,  750, {  450, 0, 0, 0, 0 }, "Ranged attack. No melee penalty.");
    static const Creature Cavalier (            CreatureType::Cavalier,            Faction::Castle,     6, Creature::Upgrade_level::None,    2, true,  15, 15,  0, 15, 25, 100,  7, Morale::Good,    Luck::Neutral, 1668, 1946, { 1000, 0, 0, 0, 0 }, "Jousting bonus.");
    static const Creature Champion (            CreatureType::Champion,            Faction::Castle,     6, Creature::Upgrade_level::First,   2, true,  16, 16,  0, 20, 25, 100,  9, Morale::Good,    Luck::Neutral, 1800, 2100, { 1200, 0, 0, 0, 0 }, "Jousting bonus.");
    static const Creature Angel (               CreatureType::Angel,               Faction::Castle,     7, Creature::Upgrade_level::None,    1, true,  20, 20,  0, 50, 50, 200, 12, Morale::Good,    Luck::Neutral, 3585, 5019, { 3000, 0, 0, 0, 1 }, "Flying. Hates Devils and Arch Devils. +1 morale to alias troops.");
    static const Creature Archangel (           CreatureType::Archangel,           Faction::Castle,     7, Creature::Upgrade_level::First,   1, true,  30, 30,  0, 50, 50, 250, 18, Morale::Good,    Luck::Neutral, 6033, 8776, { 5000, 0, 0, 0, 3 }, "Flying. Hates Devils and Arch Devils. +1 morale to alias troops. Can cast Ressurection once per battle.");

    // Rampart
    static const Creature Centaur (             CreatureType::Centaur,             Faction::Rampart,    1, Creature::Upgrade_level::None,   14, true,   5,  3,  0,  2,  3,   8,  6, Morale::Good,    Luck::Neutral,  100,  100, {   70, 0, 0, 0, 0 }, "");
    static const Creature Centaur_Captain (     CreatureType::Centaur_Captain,     Faction::Rampart,    1, Creature::Upgrade_level::First,  14, true,   6,  3,  0,  2,  3,  10,  8, Morale::Good,    Luck::Neutral,  138,  138, {   90, 0, 0, 0, 0 }, "");
    static const Creature Dwarf (               CreatureType::Dwarf,               Faction::Rampart,    2, Creature::Upgrade_level::None,    8, false,  6,  7,  0,  2,  4,  20,  3, Morale::Good,    Luck::Neutral,  138,  138, {  120, 0, 0, 0, 0 }, "Magic resistance 20%.");
    static const Creature Battle_Dwarf (        CreatureType::Battle_Dwarf,        Faction::Rampart,    2, Creature::Upgrade_level::First,   8, false,  7,  7,  0,  2,  4,  20,  5, Morale::Good,    Luck::Neutral,  209,  209, {  150, 0, 0, 0, 0 }, "Magic resistance 40%.");
    static const Creature Wood_Elf (            CreatureType::Wood_Elf,            Faction::Rampart,    3, Creature::Upgrade_level::None,    7, false,  9,  5, 12,  3,  5,  15,  6, Morale::Good,    Luck::Neutral,  234,  234, {  200, 0, 0, 0, 0 }, "Ranged attack.");
    static const Creature Grand_Elf (           CreatureType::Grand_Elf,           Faction::Rampart,    3, Creature::Upgrade_level::First,   7, false,  9,  5, 24,  3,  5,  15,  7, Morale::Good,    Luck::Neutral,  331,  331, {  225, 0, 0, 0, 0 }, "Ranged attack. Double attack.");
    static const Creature Pegasus (             CreatureType::Pegasus,             Faction::Rampart,    4, Creature::Upgrade_level::None,    5, true,   9,  8,  0,  5,  9,  30,  8, Morale::Good,    Luck::Neutral,  518,  518, {  250, 0, 0, 0, 0 }, "Magic damper.");
    static const Creature Silver_Pegasus (      CreatureType::Silver_Pegasus,      Faction::Rampart,    4, Creature::Upgrade_level::First,   5, true,   9, 10,  0,  5,  9,  30, 12, Morale::Good,    Luck::Neutral,  532,  532, {  275, 0, 0, 0, 0 }, "Magic damper.");
    static const Creature Dendroid_Guard (      CreatureType::Dendroid_Guard,      Faction::Rampart,    5, Creature::Upgrade_level::None,    3, false,  9, 12,  0, 10, 14,  55,  3, Morale::Good,    Luck::Neutral,  517,  517, {  350, 0, 0, 0, 0 }, "Binding attack.");
    static const Creature Dendroid_Soldier (    CreatureType::Dendroid_Soldier,    Faction::Rampart,    5, Creature::Upgrade_level::First,   3, false,  9, 12,  0, 10, 14,  65,  4, Morale::Good,    Luck::Neutral,  765,  803, {  425, 0, 0, 0, 0 }, "Binding attack.");
    static const Creature Unicorn (             CreatureType::Unicorn,             Faction::Rampart,    6, Creature::Upgrade_level::None,    2, true,  15, 14,  0, 18, 22,  90,  7, Morale::Good,    Luck::Neutral, 1548, 1806, {  850, 0, 0, 0, 0 }, "20% chance to cast Blind per attack. Aura of magic resistance 20%.");
    static const Creature War_Unicorn (         CreatureType::War_Unicorn,         Faction::Rampart,    6, Creature::Upgrade_level::First,   2, true,  15, 14,  0, 18, 22, 110,  9, Morale::Good,    Luck::Neutral, 2030, 2030, {  950, 0, 0, 0, 0 }, "20% chance to cast Blind per attack. Aura of magic resistance 20%.");
    static const Creature Green_Dragon (        CreatureType::Green_Dragon,        Faction::Rampart,    7, Creature::Upgrade_level::None,    1, true,  18, 18,  0, 40, 50, 180, 10, Morale::Good,    Luck::Neutral, 3654, 4872, { 2400, 0, 0, 1, 0 }, "Breath attack. Immune to spells level 1-3.");
    static const Creature Gold_Dragon (         CreatureType::Gold_Dragon,         Faction::Rampart,    7, Creature::Upgrade_level::First,   1, true,  27, 27,  0, 40, 50, 250, 16, Morale::Good,    Luck::Neutral, 6220, 8613, { 4000, 0, 0, 2, 0 }, "Breath attack. Immune to spells level 1-4.");

    // Tower
    static const Creature Gremlin (             CreatureType::Gremlin,             Faction::Tower,      1, Creature::Upgrade_level::None,   16, false,  3,  3,  0,  1,  2,   4,  4, Morale::Good,    Luck::Neutral,   55,   44, {   30, 0, 0, 0, 0 }, "");
    static const Creature Master_Gremlin (      CreatureType::Master_Gremlin,      Faction::Tower,      1, Creature::Upgrade_level::First,  16, false,  4,  4,  8,  1,  2,   4,  5, Morale::Good,    Luck::Neutral,   55,   66, {   40, 0, 0, 0, 0 }, "Ranged attack.");
    static const Creature Stone_Gargoyle (      CreatureType::Stone_Gargoyle,      Faction::Tower,      2, Creature::Upgrade_level::None,    9, false,  6,  6,  0,  2,  3,  16,  6, Morale::Good,    Luck::Neutral,  150,  165, {  130, 0, 0, 0, 0 }, "Non-living.");
    static const Creature Obsidian_Gargoyle (   CreatureType::Obsidian_Gargoyle,   Faction::Tower,      2, Creature::Upgrade_level::First,   9, false,  7,  7,  0,  2,  3,  16,  9, Morale::Good,    Luck::Neutral,  155,  201, {  160, 0, 0, 0, 0 }, "Non-living.");
    static const Creature Stone_Golem (         CreatureType::Stone_Golem,         Faction::Tower,      3, Creature::Upgrade_level::None,    6, false,  7, 10,  0,  4,  5,  30,  3, Morale::Neutral, Luck::Neutral,  339,  250, {  150, 0, 0, 0, 0 }, "Non-living. Spell damage reduction 50%.");
    static const Creature Iron_Golem (          CreatureType::Iron_Golem,          Faction::Tower,      3, Creature::Upgrade_level::First,   6, false,  9, 10,  0,  4,  5,  35,  5, Morale::Neutral, Luck::Neutral,  412,  412, {  200, 0, 0, 0, 0 }, "Non-living. Spell damage reduction 75%.");
    static const Creature Mage (                CreatureType::Mage,                Faction::Tower,      4, Creature::Upgrade_level::None,    4, false, 11,  8, 24,  7,  9,  25,  5, Morale::Good,    Luck::Neutral,  418,  570, {  350, 0, 0, 0, 0 }, "Ranged attack. No melee penalty. No obstacle penalty. Hero's combat spells cost 2 less mana.");
    static const Creature Arch_Mage (           CreatureType::Arch_Mage,           Faction::Tower,      4, Creature::Upgrade_level::First,   4, false, 12,  9, 24,  7,  9,  30,  7, Morale::Good,    Luck::Neutral,  467,  680, {  450, 0, 0, 0, 0 }, "Ranged attack. No melee penalty. No obstacle penalty. Hero's combat spells cost 2 less mana.");
    static const Creature Genie (               CreatureType::Genie,               Faction::Tower,      5, Creature::Upgrade_level::None,    3, false, 12, 12,  0, 13, 16,  40,  7, Morale::Good,    Luck::Neutral,  680,  884, {  550, 0, 0, 0, 0 }, "Hates Efreeti and Efreet Sultans.");
    static const Creature Master_Genie (        CreatureType::Master_Genie,        Faction::Tower,      5, Creature::Upgrade_level::First,   3, false, 12, 12,  0, 13, 16,  40, 11, Morale::Good,    Luck::Neutral,  748,  942, {  600, 0, 0, 0, 0 }, "Hates Efreeti and Efreet Sultans. Spellcaster.");
    static const Creature Naga (                CreatureType::Naga,                Faction::Tower,      6, Creature::Upgrade_level::None,    2, true,  16, 13,  0, 20, 20, 110,  5, Morale::Good,    Luck::Neutral, 2016, 2016, { 1100, 0, 0, 0, 0 }, "No enemy retaliation.");
    static const Creature Naga_Queen (          CreatureType::Naga_Queen,          Faction::Tower,      6, Creature::Upgrade_level::First,   2, true,  16, 13,  0, 30, 30, 110,  7, Morale::Good,    Luck::Neutral, 2840, 2840, { 1600, 0, 0, 0, 0 }, "No enemy retaliation.");
    static const Creature Giant (               CreatureType::Giant,               Faction::Tower,      7, Creature::Upgrade_level::None,    1, false, 19, 16,  0, 40, 60, 150,  7, Morale::Good,    Luck::Neutral, 3146, 3718, { 2000, 0, 0, 0, 1 }, "Immune to mind spells.");
    static const Creature Titan (               CreatureType::Titan,               Faction::Tower,      7, Creature::Upgrade_level::First,   1, false, 24, 24, 24, 40, 60, 300, 11, Morale::Good,    Luck::Neutral, 5000, 7500, { 5000, 0, 0, 0, 2 }, "Ranged attack. No melee penalty. Immune to mind spells. Hates Black Dragons.");

    // Inferno
    static const Creature Imp (                 CreatureType::Imp,                 Faction::Inferno,    1, Creature::Upgrade_level::None,   15, false,  2,  3,  0,  1,  2,   4,  5, Morale::Good,    Luck::Neutral,   50,   50, {   50, 0, 0, 0, 0 }, "");
    static const Creature Familiar (            CreatureType::Familiar,            Faction::Inferno,    1, Creature::Upgrade_level::First,  15, false,  4,  4,  0,  1,  2,   4,  7, Morale::Good,    Luck::Neutral,   60,   60, {   60, 0, 0, 0, 0 }, "Magic channel.");
    static const Creature Gog (                 CreatureType::Gog,                 Faction::Inferno,    2, Creature::Upgrade_level::None,    8, false,  6,  4, 12,  2,  4,  13,  4, Morale::Good,    Luck::Neutral,  145,  159, {  125, 0, 0, 0, 0 }, "Ranged attack.");
    static const Creature Magog (               CreatureType::Magog,               Faction::Inferno,    2, Creature::Upgrade_level::First,   8, false,  7,  4, 24,  2,  4,  13,  6, Morale::Good,    Luck::Neutral,  210,  240, {  175, 0, 0, 0, 0 }, "Ranged attack. Fireball attack.");
    static const Creature Hell_Hound (          CreatureType::Hell_Hound,          Faction::Inferno,    3, Creature::Upgrade_level::None,    5, true,  10,  6,  0,  2,  7,  25,  7, Morale::Good,    Luck::Neutral,  275,  357, {  200, 0, 0, 0, 0 }, "");
    static const Creature Cerberus (            CreatureType::Cerberus,            Faction::Inferno,    3, Creature::Upgrade_level::First,   5, true,  10,  8,  0,  2,  7,  25,  8, Morale::Good,    Luck::Neutral,  308,  392, {  250, 0, 0, 0, 0 }, "3-headed attack. No enemy retaliation.");
    static const Creature Demon (               CreatureType::Demon,               Faction::Inferno,    4, Creature::Upgrade_level::None,    4, false, 10, 10,  0,  7,  9,  35,  5, Morale::Good,    Luck::Neutral,  445,  445, {  250, 0, 0, 0, 0 }, "");
    static const Creature Horned_Demon (        CreatureType::Horned_Demon,        Faction::Inferno,    4, Creature::Upgrade_level::First,   4, false, 10, 10,  0,  7,  9,  40,  6, Morale::Good,    Luck::Neutral,  480,  480, {  270, 0, 0, 0, 0 }, "");
    static const Creature Pit_Fiend (           CreatureType::Pit_Fiend,           Faction::Inferno,    5, Creature::Upgrade_level::None,    3, false, 13, 13,  0, 13, 17,  45,  6, Morale::Good,    Luck::Neutral,  765,  765, {  500, 0, 0, 0, 0 }, "");
    static const Creature Pit_Lord (            CreatureType::Pit_Lord,            Faction::Inferno,    5, Creature::Upgrade_level::First,   3, false, 13, 13,  0, 13, 17,  45,  7, Morale::Good,    Luck::Neutral, 1071, 1224, {  700, 0, 0, 0, 0 }, "Summon Demons.");
    static const Creature Efreet (              CreatureType::Efreet,              Faction::Inferno,    6, Creature::Upgrade_level::None,    2, false, 16, 12,  0, 16, 24,  90,  9, Morale::Good,    Luck::Neutral, 1413, 1670, {  900, 0, 0, 0, 0 }, "Immune to fire spells (Magic Arrow included). Hates Genies and Master Genies.");
    static const Creature Efreet_Sultan (       CreatureType::Efreet_Sultan,       Faction::Inferno,    6, Creature::Upgrade_level::First,   2, false, 16, 14,  0, 16, 24,  90, 13, Morale::Good,    Luck::Neutral, 1802, 2343, { 1100, 0, 0, 0, 0 }, "Immune to fire spells (Magic Arrow included). Hates Genies and Master Genies. Fire Shield.");
    static const Creature Devil (               CreatureType::Devil,               Faction::Inferno,    7, Creature::Upgrade_level::None,    1, false, 19, 21,  0, 30, 40, 160, 11, Morale::Good,    Luck::Neutral, 3759, 5101, { 2700, 1, 0, 0, 0 }, "-1 luck to enemy troops. No enemy retaliation. Hates Angels and Archangels.");
    static const Creature Arch_Devil (          CreatureType::Arch_Devil,          Faction::Inferno,    7, Creature::Upgrade_level::First,   1, false, 26, 28,  0, 30, 40, 200, 17, Morale::Good,    Luck::Neutral, 5243, 7115, { 4500, 2, 0, 0, 0 }, "-2 luck to enemy troops. No enemy retaliation. Hates Angels and Archangels.");

    // Necropolis
    static const Creature Skeleton (            CreatureType::Skeleton,            Faction::Necropolis, 1, Creature::Upgrade_level::None,   12, false,  5,  4,  0,  1,  3,   6,  4, Morale::Neutral, Luck::Neutral,   75,   60, {   60, 0, 0, 0, 0 }, "Undead.");
    static const Creature Skeleton_Warrior (    CreatureType::Skeleton_Warrior,    Faction::Necropolis, 1, Creature::Upgrade_level::First,  12, false,  6,  6,  0,  1,  3,   6,  5, Morale::Neutral, Luck::Neutral,   85,   85, {   70, 0, 0, 0, 0 }, "Undead.");
    static const Creature Walking_Dead (        CreatureType::Walking_Dead,        Faction::Necropolis, 2, Creature::Upgrade_level::None,    8, false,  5,  5,  0,  2,  3,  15,  3, Morale::Neutral, Luck::Neutral,  140,   98, {  100, 0, 0, 0, 0 }, "Undead.");
    static const Creature Zombie (              CreatureType::Zombie,              Faction::Necropolis, 2, Creature::Upgrade_level::First,   8, false,  5,  5,  0,  2,  3,  20,  4, Morale::Neutral, Luck::Neutral,  160,  128, {  125, 0, 0, 0, 0 }, "Undead. 20% chance to cast Disease per attack.");
    static const Creature Wight (               CreatureType::Wight,               Faction::Necropolis, 3, Creature::Upgrade_level::None,    7, false,  7,  7,  0,  3,  5,  18,  5, Morale::Neutral, Luck::Neutral,  231,  252, {  200, 0, 0, 0, 0 }, "Undead. Regeneration.");
    static const Creature Wraith (              CreatureType::Wraith,              Faction::Necropolis, 3, Creature::Upgrade_level::First,   7, false,  7,  7,  0,  3,  5,  18,  7, Morale::Neutral, Luck::Neutral,  252,  315, {  230, 0, 0, 0, 0 }, "Undead. Regeneration. Mana drain.");
    static const Creature Vampire (             CreatureType::Vampire,             Faction::Necropolis, 4, Creature::Upgrade_level::None,    4, false, 10,  9,  0,  5,  8,  30,  6, Morale::Neutral, Luck::Neutral,  518,  555, {  360, 0, 0, 0, 0 }, "Undead. No enemy retaliation.");
    static const Creature Vampire_Lord (        CreatureType::Vampire_Lord,        Faction::Necropolis, 4, Creature::Upgrade_level::First,   4, false, 10, 10,  0,  5,  8,  40,  9, Morale::Neutral, Luck::Neutral,  652,  783, {  500, 0, 0, 0, 0 }, "Undead. No enemy retaliation. Life drain.");
    static const Creature Lich (                CreatureType::Lich,                Faction::Necropolis, 5, Creature::Upgrade_level::None,    3, false, 13, 10, 12, 11, 13,  30,  6, Morale::Neutral, Luck::Neutral,  742,  848, {  550, 0, 0, 0, 0 }, "Undead. Ranged attack. Death cloud.");
    static const Creature Power_Lich (          CreatureType::Power_Lich,          Faction::Necropolis, 5, Creature::Upgrade_level::First,   3, false, 13, 10, 24, 11, 15,  40,  7, Morale::Neutral, Luck::Neutral,  889, 1079, {  600, 0, 0, 0, 0 }, "Undead. Ranged attack. Death cloud.");
    static const Creature Black_Knight (        CreatureType::Black_Knight,        Faction::Necropolis, 6, Creature::Upgrade_level::None,    2, true,  16, 16,  0, 15, 30, 120,  7, Morale::Neutral, Luck::Neutral, 1753, 2087, { 1200, 0, 0, 0, 0 }, "Undead. 25% chance to cast Curse per attack.");
    static const Creature Dread_Knight (        CreatureType::Dread_Knight,        Faction::Necropolis, 6, Creature::Upgrade_level::First,   2, true,  18, 18,  0, 15, 30, 120,  9, Morale::Neutral, Luck::Neutral, 2029, 2382, { 1500, 0, 0, 0, 0 }, "Undead. 25% chance to cast Curse per attack. 20% chance to cast Death Blow per attack.");
    static const Creature Bone_Dragon (         CreatureType::Bone_Dragon,         Faction::Necropolis, 7, Creature::Upgrade_level::None,    1, true,  17, 15,  0, 25, 50, 150,  9, Morale::Neutral, Luck::Neutral, 2420, 3388, { 1800, 0, 0, 0, 0 }, "Undead. -1 morale to enemy troops.");
    static const Creature Ghost_Dragon (        CreatureType::Ghost_Dragon,        Faction::Necropolis, 7, Creature::Upgrade_level::First,   1, true,  19, 17,  0, 25, 50, 200, 14, Morale::Neutral, Luck::Neutral, 3228, 4696, { 3000, 1, 0, 0, 0 }, "Undead. -1 morale to enemy troops. 20% chance to cast Aging per attack.");

    // Dungeon
    static const Creature Troglodyte (          CreatureType::Troglodyte,          Faction::Dungeon,    1, Creature::Upgrade_level::None,   14, false,  4,  3,  0,  1,  3,   5,  4, Morale::Good,    Luck::Neutral,   73,   59, {   50, 0, 0, 0, 0 }, "Immune to Blind. Immune to Petrify.");
    static const Creature Infernal_Troglodyte ( CreatureType::Infernal_Troglodyte, Faction::Dungeon,    1, Creature::Upgrade_level::First,  14, false,  5,  4,  0,  1,  3,   6,  5, Morale::Good,    Luck::Neutral,   84,   84, {   65, 0, 0, 0, 0 }, "Immune to Blind. Immune to Petrify.");
    static const Creature Harpy (               CreatureType::Harpy,               Faction::Dungeon,    2, Creature::Upgrade_level::None,    8, false,  6,  5,  0,  1,  4,  14,  6, Morale::Good,    Luck::Neutral,  140,  154, {  130, 0, 0, 0, 0 }, "Strike and return.");
    static const Creature Harpy_Hag (           CreatureType::Harpy_Hag,           Faction::Dungeon,    2, Creature::Upgrade_level::First,   8, false,  6,  6,  0,  1,  4,  14,  9, Morale::Good,    Luck::Neutral,  196,  238, {  170, 0, 0, 0, 0 }, "Strike and return. No enemy retaliation.");
    static const Creature Beholder (            CreatureType::Beholder,            Faction::Dungeon,    3, Creature::Upgrade_level::None,    7, false,  9,  7, 12,  3,  5,  22,  5, Morale::Good,    Luck::Neutral,  240,  336, {  250, 0, 0, 0, 0 }, "Ranged attack. No melee penalty.");
    static const Creature Evil_Eye (            CreatureType::Evil_Eye,            Faction::Dungeon,    3, Creature::Upgrade_level::First,   7, false, 10,  8, 24,  3,  5,  22,  7, Morale::Good,    Luck::Neutral,  245,  367, {  280, 0, 0, 0, 0 }, "Ranged attack. No melee penalty.");
    static const Creature Medusa (              CreatureType::Medusa,              Faction::Dungeon,    4, Creature::Upgrade_level::None,    4, true,   9,  9,  4,  6,  8,  25,  5, Morale::Good,    Luck::Neutral,  379,  517, {  300, 0, 0, 0, 0 }, "Ranged attack. No melee penalty. 20% chance to cast Petrify per melee attack.");
    static const Creature Medusa_Queen (        CreatureType::Medusa_Queen,        Faction::Dungeon,    4, Creature::Upgrade_level::First,   4, true,  10, 10,  8,  6,  8,  30,  6, Morale::Good,    Luck::Neutral,  423,  577, {  330, 0, 0, 0, 0 }, "Ranged attack. No melee penalty. 20% chance to cast Petrify per melee attack.");
    static const Creature Minotaur (            CreatureType::Minotaur,            Faction::Dungeon,    5, Creature::Upgrade_level::None,    3, false, 14, 12,  0, 12, 20,  50,  6, Morale::Good,    Luck::Neutral,  835,  835, {  500, 0, 0, 0, 0 }, "Minimum morale is +1.");
    static const Creature Minotaur_King (       CreatureType::Minotaur_King,       Faction::Dungeon,    5, Creature::Upgrade_level::First,   3, false, 15, 15,  0, 12, 20,  50,  8, Morale::Good,    Luck::Neutral,  890, 1068, {  575, 0, 0, 0, 0 }, "Minimum morale is +1.");
    static const Creature Manticore (           CreatureType::Manticore,           Faction::Dungeon,    6, Creature::Upgrade_level::None,    2, true,  15, 13,  0, 14, 20,  80,  7, Morale::Good,    Luck::Neutral, 1215, 1547, {  850, 0, 0, 0, 0 }, "");
    static const Creature Scorpicore (          CreatureType::Scorpicore,          Faction::Dungeon,    6, Creature::Upgrade_level::First,   2, true,  16, 14,  0, 14, 20,  80, 11, Morale::Good,    Luck::Neutral, 1248, 1589, { 1050, 0, 0, 0, 0 }, "20% chance to cast Paralyzing Venom per attack.");
    static const Creature Red_Dragon (          CreatureType::Red_Dragon,          Faction::Dungeon,    7, Creature::Upgrade_level::None,    1, true,  19, 19,  0, 40, 50, 180, 11, Morale::Good,    Luck::Neutral, 3762, 4702, { 2500, 0, 1, 0, 0 }, "Breath attack. Immune to spells level 1-3.");
    static const Creature Black_Dragon (        CreatureType::Black_Dragon,        Faction::Dungeon,    7, Creature::Upgrade_level::First,   1, true,  25, 25,  0, 40, 50, 300, 15, Morale::Good,    Luck::Neutral, 6783, 8721, { 4000, 0, 2, 0, 0 }, "Breath attack. Immune to all spells. Hates Titans.");

    // Stronghold
    static const Creature Goblin (              CreatureType::Goblin,              Faction::Stronghold, 1, Creature::Upgrade_level::None,   15, false,  4,  2,  0,  1,  2,   5,  5, Morale::Good,    Luck::Neutral,   60,   60, {   40, 0, 0, 0, 0 }, "");
    static const Creature Hobgoblin (           CreatureType::Hobgoblin,           Faction::Stronghold, 1, Creature::Upgrade_level::First,  15, false,  5,  3,  0,  1,  2,   5,  7, Morale::Good,    Luck::Neutral,   65,   78, {   50, 0, 0, 0, 0 }, "");
    static const Creature Wolf_Rider (          CreatureType::Wolf_Rider,          Faction::Stronghold, 2, Creature::Upgrade_level::None,    9, true,   7,  5,  0,  2,  4,  10,  6, Morale::Good,    Luck::Neutral,  130,  130, {  100, 0, 0, 0, 0 }, "");
    static const Creature Wolf_Raider (         CreatureType::Wolf_Raider,         Faction::Stronghold, 2, Creature::Upgrade_level::First,   9, true,   8,  5,  0,  3,  4,  10,  8, Morale::Good,    Luck::Neutral,  174,  203, {  140, 0, 0, 0, 0 }, "Double attack.");
    static const Creature Orc (                 CreatureType::Orc,                 Faction::Stronghold, 3, Creature::Upgrade_level::None,    7, false,  8,  4, 12,  2,  5,  15,  4, Morale::Good,    Luck::Neutral,  175,  192, {  150, 0, 0, 0, 0 }, "Ranged attack.");
    static const Creature Orc_Chieftain (       CreatureType::Orc_Chieftain,       Faction::Stronghold, 3, Creature::Upgrade_level::First,   7, false,  8,  4, 24,  2,  5,  20,  5, Morale::Good,    Luck::Neutral,  200,  240, {  165, 0, 0, 0, 0 }, "Ranged attack.");
    static const Creature Ogre (                CreatureType::Ogre,                Faction::Stronghold, 4, Creature::Upgrade_level::None,    4, false, 13,  7,  4,  6, 12,  40,  4, Morale::Good,    Luck::Neutral,  520,  416, {  300, 0, 0, 0, 0 }, "");
    static const Creature Ogre_Mage (           CreatureType::Ogre_Mage,           Faction::Stronghold, 4, Creature::Upgrade_level::First,   4, false, 13,  7,  8,  6, 12,  60,  5, Morale::Good,    Luck::Neutral,  672,  672, {  400, 0, 0, 0, 0 }, "Spellcaster (Bloodlust).");
    static const Creature Roc (                 CreatureType::Roc,                 Faction::Stronghold, 5, Creature::Upgrade_level::None,    3, true,  13, 11,  0, 11, 15,  60,  7, Morale::Good,    Luck::Neutral,  790, 1027, {  600, 0, 0, 0, 0 }, "");
    static const Creature Thunderbird (         CreatureType::Thunderbird,         Faction::Stronghold, 5, Creature::Upgrade_level::First,   3, true,  13, 11,  0, 11, 15,  60, 11, Morale::Good,    Luck::Neutral,  869, 1106, {  700, 0, 0, 0, 0 }, "20% chance to cast Lightning Strike per attack.");
    static const Creature Cyclops (             CreatureType::Cyclops,             Faction::Stronghold, 6, Creature::Upgrade_level::None,    2, false, 15, 12, 16, 16, 20,  70,  6, Morale::Good,    Luck::Neutral, 1055, 1266, {  750, 0, 0, 0, 0 }, "Ranged attack. Can attack siege walls.");
    static const Creature Cyclops_King (        CreatureType::Cyclops_King,        Faction::Stronghold, 6, Creature::Upgrade_level::First,   2, false, 17, 13, 24, 16, 20,  70,  8, Morale::Good,    Luck::Neutral, 1110, 1443, { 1100, 0, 0, 0, 0 }, "Ranged attack. Can attack siege walls.");
    static const Creature Behemoth (            CreatureType::Behemoth,            Faction::Stronghold, 7, Creature::Upgrade_level::None,    1, true,  17, 17,  0, 30, 50, 160,  6, Morale::Good,    Luck::Neutral, 3162, 3162, { 1500, 0, 0, 0, 0 }, "Ignores 40% of enemy's defense skill.");
    static const Creature Ancient_Behemoth (    CreatureType::Ancient_Behemoth,    Faction::Stronghold, 7, Creature::Upgrade_level::First,   1, true,  19, 19,  0, 30, 50, 300,  9, Morale::Good,    Luck::Neutral, 5397, 6168, { 3000, 0, 0, 1, 0 }, "Ignores 80% of enemy's defense skill.");

    // Fortress
    static const Creature Gnoll (               CreatureType::Gnoll,               Faction::Fortress,   1, Creature::Upgrade_level::None,   12, false,  3,  5,  0,  2,  3,   6,  4, Morale::Good,    Luck::Neutral,   70,   56, {   50, 0, 0, 0, 0 }, "");
    static const Creature Gnoll_Marauder (      CreatureType::Gnoll_Marauder,      Faction::Fortress,   1, Creature::Upgrade_level::First,  12, false,  4,  6,  0,  2,  3,   6,  5, Morale::Good,    Luck::Neutral,   90,   90, {   70, 0, 0, 0, 0 }, "");
    static const Creature Lizardman (           CreatureType::Lizardman,           Faction::Fortress,   2, Creature::Upgrade_level::None,    9, false,  5,  6, 12,  2,  3,  14,  4, Morale::Good,    Luck::Neutral,  115,  126, {  110, 0, 0, 0, 0 }, "Ranged attack.");
    static const Creature Lizard_Warrior (      CreatureType::Lizard_Warrior,      Faction::Fortress,   2, Creature::Upgrade_level::First,   9, false,  6,  8, 24,  2,  5,  15,  5, Morale::Good,    Luck::Neutral,  130,  156, {  140, 0, 0, 0, 0 }, "Ranged attack.");
    static const Creature Serpent_Fly (         CreatureType::Serpent_Fly,         Faction::Fortress,   3, Creature::Upgrade_level::None,    8, false,  7,  9,  0,  2,  5,  20,  9, Morale::Good,    Luck::Neutral,  215,  268, {  220, 0, 0, 0, 0 }, "Casts Dispel to benefical spells per attack.");
    static const Creature Dragon_Fly (          CreatureType::Dragon_Fly,          Faction::Fortress,   3, Creature::Upgrade_level::First,   8, false,  8, 10,  0,  2,  5,  20, 13, Morale::Good,    Luck::Neutral,  250,  312, {  240, 0, 0, 0, 0 }, "Casts Dispel to benefical spells per attack. Casts Advanced Weakness per attack.");
    static const Creature Basilisk (            CreatureType::Basilisk,            Faction::Fortress,   4, Creature::Upgrade_level::None,    4, true,  11, 11,  4,  6, 10,  35,  5, Morale::Good,    Luck::Neutral,  506,  552, {  325, 0, 0, 0, 0 }, "20% chance to cast Petrify per attack.");
    static const Creature Greater_Basilisk (    CreatureType::Greater_Basilisk,    Faction::Fortress,   4, Creature::Upgrade_level::First,   4, true,  12, 12,  8,  6, 10,  40,  7, Morale::Good,    Luck::Neutral,  561,  714, {  400, 0, 0, 0, 0 }, "20% chance to cast Petrify per attack.");
    static const Creature Gorgon (              CreatureType::Gorgon,              Faction::Fortress,   5, Creature::Upgrade_level::None,    3, true,  10, 14,  0, 12, 16,  70,  5, Morale::Good,    Luck::Neutral,  890,  890, {  525, 0, 0, 0, 0 }, "");
    static const Creature Mighty_Gorgon (       CreatureType::Mighty_Gorgon,       Faction::Fortress,   5, Creature::Upgrade_level::First,   3, true,  11, 16,  0, 12, 16,  70,  6, Morale::Good,    Luck::Neutral, 1028, 1028, {  600, 0, 0, 0, 0 }, "10% chance to cast Death Stare per melee attack.");
    static const Creature Wyvern (              CreatureType::Wyvern,              Faction::Fortress,   6, Creature::Upgrade_level::None,    2, true,  14, 14,  0, 14, 18,  70,  7, Morale::Good,    Luck::Neutral, 1050, 1350, {  800, 0, 0, 0, 0 }, "");
    static const Creature Wyvern_Monarch (      CreatureType::Wyvern_Monarch,      Faction::Fortress,   6, Creature::Upgrade_level::First,   2, true,  14, 14,  0, 18, 22,  70, 11, Morale::Good,    Luck::Neutral, 1518, 1518, { 1100, 0, 0, 0, 0 }, "30% chance to cast Poison per attack.");
    static const Creature Hydra (               CreatureType::Hydra,               Faction::Fortress,   7, Creature::Upgrade_level::None,    1, true,  16, 18,  0, 25, 45, 175,  5, Morale::Good,    Luck::Neutral, 4120, 4120, { 2200, 0, 0, 0, 0 }, "Attack all adjacent enemies. No enemy retaliation.");
    static const Creature Chaos_Hydra (         CreatureType::Chaos_Hydra,         Faction::Fortress,   7, Creature::Upgrade_level::First,   1, true,  18, 20,  0, 25, 45, 250,  7, Morale::Good,    Luck::Neutral, 5272, 5931, { 3500, 0, 1, 0, 0 }, "Attack all adjacent enemies. No enemy retaliation.");

    // Conflux
    static const Creature Pixie (               CreatureType::Pixie,               Faction::Conflux,    1, Creature::Upgrade_level::None,   20, false,  2,  2,  0,  1,  2,   3,  7, Morale::Good,    Luck::Neutral,   40,   55, {   25, 0, 0, 0, 0 }, "");
    static const Creature Sprite (              CreatureType::Sprite,              Faction::Conflux,    1, Creature::Upgrade_level::First,  20, false,  2,  2,  0,  1,  3,   3,  9, Morale::Good,    Luck::Neutral,   70,   95, {   30, 0, 0, 0, 0 }, "No enemy retaliation.");
    static const Creature Air_Elemental (       CreatureType::Air_Elemental,       Faction::Conflux,    2, Creature::Upgrade_level::None,    6, false,  9,  9,  0,  2,  8,  25,  7, Morale::Good,    Luck::Neutral,  324,  356, {  250, 0, 0, 0, 0 }, "Non-living. Immune to Meteor Shower. Vulnerable to Lightning Bolt, Chain Lightning and Armageddon.");
    static const Creature Storm_Elemental (     CreatureType::Storm_Elemental,     Faction::Conflux,    2, Creature::Upgrade_level::First,   6, false,  9,  9, 24,  2,  8,  25,  8, Morale::Good,    Luck::Neutral,  324,  486, {  275, 0, 0, 0, 0 }, "Non-living. Ranged attack. Immune to Meteor Shower. Vulnerable to Lightning Bolt, Chain Lightning and Armageddon. Spellcaster (Protection from Air).");
    static const Creature Water_Elemental (     CreatureType::Water_Elemental,     Faction::Conflux,    3, Creature::Upgrade_level::None,    6, true,   8, 10,  0,  3,  7,  30,  5, Morale::Good,    Luck::Neutral,  315,  315, {  300, 0, 0, 0, 0 }, "Non-living. Immune to Ice Bolt and Frost Ring. Vulnerable to Armageddon, Fireball, Inferno.");
    static const Creature Ice_Elemental (       CreatureType::Ice_Elemental,       Faction::Conflux,    3, Creature::Upgrade_level::First,   6, true,   8, 10, 24,  3,  7,  30,  6, Morale::Good,    Luck::Neutral,  315,  380, {  375, 0, 0, 0, 0 }, "Non-living. Ranged attack. Immune to Ice Bolt and Frost Ring. Vulnerable to Armageddon, Fireball, Inferno. Spellcaster (Protection from Water).");
    static const Creature Fire_Elemental (      CreatureType::Fire_Elemental,      Faction::Conflux,    4, Creature::Upgrade_level::None,    5, false, 10,  8,  0,  4,  6,  35,  6, Morale::Good,    Luck::Neutral,  345,  345, {  350, 0, 0, 0, 0 }, "Non-living. Immune to fire spells (Magic Arrow included). Vulnerable to Ice Bolt and Frost Ring.");
    static const Creature Energy_Elemental (    CreatureType::Energy_Elemental,    Faction::Conflux,    4, Creature::Upgrade_level::First,   5, false, 12,  8,  0,  4,  6,  35,  8, Morale::Good,    Luck::Neutral,  360,  470, {  400, 0, 0, 0, 0 }, "Non-living. Immune to fire spells (Magic Arrow included). Vulnerable to Ice Bolt and Frost Ring. Spellcaster (Protection from Fire).");
    static const Creature Earth_Elemental (     CreatureType::Earth_Elemental,     Faction::Conflux,    5, Creature::Upgrade_level::None,    4, false, 10, 10,  0,  4,  8,  40,  4, Morale::Good,    Luck::Neutral,  415,  330, {  400, 0, 0, 0, 0 }, "Non-living. Immune to Lightning Bolt, Chain Lightning and Armageddon. Vulnerable to Meteor Shower.");
    static const Creature Magma_Elemental (     CreatureType::Magma_Elemental,     Faction::Conflux,    5, Creature::Upgrade_level::First,   4, false, 11, 11,  0,  6, 10,  40,  6, Morale::Good,    Luck::Neutral,  490,  490, {  500, 0, 0, 0, 0 }, "Non-living. Immune to Lightning Bolt, Chain Lightning and Armageddon. Vulnerable to Meteor Shower. Spellcaster (Protection from Earth).");
    static const Creature Psychic_Elemental (   CreatureType::Psychic_Elemental,   Faction::Conflux,    6, Creature::Upgrade_level::None,    2, false, 15, 13,  0, 10, 20,  75,  7, Morale::Good,    Luck::Neutral, 1431, 1669, {  750, 0, 0, 0, 0 }, "Non-living. No enemy retaliation. Attack all adjacent hexes. Immune to mind spells.");
    static const Creature Magic_Elemental (     CreatureType::Magic_Elemental,     Faction::Conflux,    6, Creature::Upgrade_level::First,   2, false, 15, 13,  0, 15, 25,  80,  9, Morale::Good,    Luck::Neutral, 1724, 2012, {  800, 0, 0, 0, 0 }, "Non-living. No enemy retaliation. Attack all adjacent hexes. Immune to all spells.");
    static const Creature Firebird (            CreatureType::Firebird,            Faction::Conflux,    7, Creature::Upgrade_level::None,    2, true,  18, 18,  0, 30, 40, 150, 15, Morale::Good,    Luck::Neutral, 3248, 4547, { 1500, 0, 0, 0, 0 }, "Breath attack. Immune to fire spells (Magic Arrow included).");
    static const Creature Phoenix (             CreatureType::Phoenix,             Faction::Conflux,    7, Creature::Upgrade_level::First,   2, true,  21, 18,  0, 30, 40, 200, 21, Morale::Good,    Luck::Neutral, 4929, 6721, { 2000, 1, 0, 0, 0 }, "Breath attack. Rebirth. Immune to fire spells (Magic Arrow included).");

    // Cove
    static const Creature Nymph (               CreatureType::Nymph,               Faction::Cove,       1, Creature::Upgrade_level::None,   16, false,  5,  2,  0,  1,  2,   4,  6, Morale::Good,    Luck::Neutral,   52,   57, {   35, 0, 0, 0, 0 }, "Teleporting. Immune to Ice Bolt and Frost Ring.");
    static const Creature Oceanid (             CreatureType::Oceanid,             Faction::Cove,       1, Creature::Upgrade_level::First,  16, false,  6,  2,  0,  1,  3,   4,  8, Morale::Good,    Luck::Neutral,   60,   75, {   45, 0, 0, 0, 0 }, "Teleporting. Immune to Ice Bolt and Frost Ring.");
    static const Creature Crew_Mate (           CreatureType::Crew_Mate,           Faction::Cove,       2, Creature::Upgrade_level::None,    9, false,  7,  4,  0,  2,  4,  15,  5, Morale::Good,    Luck::Neutral,  155,  155, {  110, 0, 0, 0, 0 }, "");
    static const Creature Seaman (              CreatureType::Seaman,              Faction::Cove,       2, Creature::Upgrade_level::First,   9, false,  8,  6,  0,  3,  4,  15,  6, Morale::Good,    Luck::Neutral,  174,  174, {  140, 0, 0, 0, 0 }, "");
    static const Creature Pirate (              CreatureType::Pirate,              Faction::Cove,       3, Creature::Upgrade_level::None,    7, false,  8,  6,  4,  3,  7,  15,  6, Morale::Good,    Luck::Neutral,  208,  312, {  225, 0, 0, 0, 0 }, "Ranged attack. No melee penalty.");
    static const Creature Corsair (             CreatureType::Corsair,             Faction::Cove,       3, Creature::Upgrade_level::First,   7, false, 10,  8,  4,  3,  7,  15,  7, Morale::Good,    Luck::Neutral,  311,  407, {  275, 0, 0, 0, 0 }, "Ranged attack. No melee penalty. No enemy retaliation.");
    static const Creature Sea_Dog (             CreatureType::Sea_Dog,             Faction::Cove,       3, Creature::Upgrade_level::Second,  7, false, 12, 11, 12,  3,  7,  15,  8, Morale::Good,    Luck::Neutral,  376,  602, {  375, 0, 0, 0, 0 }, "Ranged attack. No melee penalty. No enemy retaliation. 10% chance to cast Accurate Shot per ranged attack.");
    static const Creature Stormbird (           CreatureType::Stormbird,           Faction::Cove,       4, Creature::Upgrade_level::None,    4, true,  10,  8,  0,  6,  9,  30,  9, Morale::Good,    Luck::Neutral,  386,  502, {  275, 0, 0, 0, 0 }, "");
    static const Creature Ayssid (              CreatureType::Ayssid,              Faction::Cove,       4, Creature::Upgrade_level::First,   4, true,  11,  8,  0,  6, 10,  30, 11, Morale::Good,    Luck::Neutral,  478,  645, {  325, 0, 0, 0, 0 }, "Ferocity.");
    static const Creature Sea_Witch (           CreatureType::Sea_Witch,           Faction::Cove,       5, Creature::Upgrade_level::None,    3, false, 12,  7, 12, 10, 14,  35,  6, Morale::Good,    Luck::Neutral,  608,  790, {  515, 0, 0, 0, 0 }, "Ranged attack. Casts Weakness per attack. Casts Disrupting Ray on weakened enemies.");
    static const Creature Sorceress (           CreatureType::Sorceress,           Faction::Cove,       5, Creature::Upgrade_level::First,   3, false, 12,  9, 12, 10, 16,  35,  7, Morale::Good,    Luck::Neutral,  665,  852, {  565, 0, 0, 0, 0 }, "Ranged attack. Casts Advanced Weakness per attack. Casts Advanced Disrupting Ray on weakened enemies.");
    static const Creature Nix (                 CreatureType::Nix,                 Faction::Cove,       6, Creature::Upgrade_level::None,    2, false, 13, 16,  0, 18, 22,  80,  6, Morale::Good,    Luck::Neutral, 1415, 1415, { 1000, 0, 0, 0, 0 }, "Ignores 30% of enemy's attack skill.");
    static const Creature Nix_Warrior (         CreatureType::Nix_Warrior,         Faction::Cove,       6, Creature::Upgrade_level::First,   2, false, 14, 17,  0, 18, 22,  90,  7, Morale::Good,    Luck::Neutral, 1763, 2116, { 1300, 0, 0, 0, 0 }, "Ignores 60% of enemy's attack skill.");
    static const Creature Sea_Serpent (         CreatureType::Sea_Serpent,         Faction::Cove,       7, Creature::Upgrade_level::None,    1, true,  22, 16,  0, 30, 55, 180,  9, Morale::Good,    Luck::Neutral, 3162, 3953, { 2200, 0, 1, 0, 0 }, "30% chance to cast Poison per attack.");
    static const Creature Haspid (              CreatureType::Haspid,              Faction::Cove,       7, Creature::Upgrade_level::First,   1, true,  29, 20,  0, 30, 55, 300, 12, Morale::Good,    Luck::Neutral, 5554, 7220, { 4000, 0, 2, 0, 0 }, "30% chance to cast Poison per attack. Revenge.");

    // Neutral
    static const Creature Peasant (             CreatureType::Peasant,             Faction::Neutral,    1, Creature::Upgrade_level::None,   25, false,  1,  1,  0,  1,  1,   1,  3, Morale::Good,    Luck::Neutral,   15,   15, {   10, 0, 0, 0, 0 }, "");
    static const Creature Halfling (            CreatureType::Halfling,            Faction::Neutral,    1, Creature::Upgrade_level::None,   15, false,  4,  2, 24,  1,  3,   4,  5, Morale::Good,    Luck::Good,      60,   75, {   40, 0, 0, 0, 0 }, "Ranged attack. Minimum luck is +1.");
    static const Creature Rogue (               CreatureType::Rogue,               Faction::Neutral,    2, Creature::Upgrade_level::None,    8, false,  8,  3,  0,  2,  4,  10,  6, Morale::Good,    Luck::Neutral,  135,  135, {  100, 0, 0, 0, 0 }, "Spying.");
    static const Creature Boar (                CreatureType::Boar,                Faction::Neutral,    2, Creature::Upgrade_level::None,    8, true,   6,  5,  0,  2,  3,  15,  6, Morale::Good,    Luck::Neutral,  145,  145, {  150, 0, 0, 0, 0 }, "");
    static const Creature Leprechaun (          CreatureType::Leprechaun,          Faction::Neutral,    2, Creature::Upgrade_level::None,    9, false,  8,  5,  0,  3,  5,  15,  5, Morale::Good,    Luck::Good,     208,  208, {  100, 0, 0, 0, 0 }, "Doubles friendly unit Luck chance. Can cast Advanced Fortune 3 times per battle.");
    static const Creature Nomad (               CreatureType::Nomad,               Faction::Neutral,    3, Creature::Upgrade_level::None,    7, true,   9,  8,  0,  2,  6,  30,  7, Morale::Good,    Luck::Neutral,  415,  345, {  200, 0, 0, 0, 0 }, "Sandwalker.");
    static const Creature Mummy (               CreatureType::Mummy,               Faction::Neutral,    3, Creature::Upgrade_level::None,    7, false,  7,  7,  0,  3,  5,  30,  5, Morale::Neutral, Luck::Neutral,  270,  270, {  350, 0, 0, 0, 0 }, "Undead. 25% chance to cast Curse per attack.");
    static const Creature Sharpshooter (        CreatureType::Sharpshooter,        Faction::Neutral,    4, Creature::Upgrade_level::None,    4, false, 12, 10, 32,  8, 10,  15,  9, Morale::Good,    Luck::Neutral,  415,  585, {  400, 0, 0, 0, 0 }, "Ranged attack. No range penalty. No obstacle penalty.");
    static const Creature Satyr (               CreatureType::Satyr,               Faction::Neutral,    4, Creature::Upgrade_level::None,    4, false, 10, 11,  0,  6, 10,  35,  7, Morale::Good,    Luck::Neutral,  471,  518, {  350, 0, 0, 0, 0 }, "Can cast Advanced Mirth 3 times per battle.");
    static const Creature Steel_Golem (         CreatureType::Steel_Golem,         Faction::Neutral,    4, Creature::Upgrade_level::None,    4, false, 10, 11,  0,  6,  8,  45,  6, Morale::Neutral, Luck::Neutral,  597,  597, {  400, 0, 0, 0, 0 }, "Non-living. Spell damage reduction 80%.");
    static const Creature Troll (               CreatureType::Troll,               Faction::Neutral,    5, Creature::Upgrade_level::None,    3, false, 14,  7,  0, 10, 15,  40,  7, Morale::Good,    Luck::Neutral, 1024, 1024, {  500, 0, 0, 0, 0 }, "Regeneration.");
    static const Creature Gold_Golem (          CreatureType::Gold_Golem,          Faction::Neutral,    5, Creature::Upgrade_level::None,    3, false, 11, 12,  0,  8, 10,  50,  5, Morale::Neutral, Luck::Neutral,  600,  600, {  500, 0, 0, 0, 0 }, "Non-living. Spell damage reduction 85%.");
    static const Creature Fangarm (             CreatureType::Fangarm,             Faction::Neutral,    5, Creature::Upgrade_level::None,    3, false, 12, 12,  0,  8, 12,  50,  6, Morale::Good,    Luck::Neutral,  929,  929, {  600, 0, 0, 0, 0 }, "Immune to mind spells. Unlimited retaliations. Can cast Hypnotize per attack.");
    static const Creature Diamond_Golem (       CreatureType::Diamond_Golem,       Faction::Neutral,    6, Creature::Upgrade_level::None,    2, false, 13, 12,  0, 10, 14,  60,  5, Morale::Neutral, Luck::Neutral,  775,  775, {  750, 0, 0, 0, 0 }, "Non-living. Spell damage reduction 95%.");
    static const Creature Enchanter (           CreatureType::Enchanter,           Faction::Neutral,    6, Creature::Upgrade_level::None,    2, false, 17, 12, 32, 14, 14,  30,  9, Morale::Good,    Luck::Neutral,  805, 1210, {  750, 0, 0, 0, 0 }, "Ranged attack. No melee penalty. No obstacle penalty. Spellcaster.");
    static const Creature Faerie_Dragon (       CreatureType::Faerie_Dragon,       Faction::Neutral,    7, Creature::Upgrade_level::None,    1, true,  20, 20,  0, 20, 30, 500, 15, Morale::Good,    Luck::Neutral,16317,30501, {10000, 0, 0, 0, 8 }, "Spellcaster. Naturally has Magic Mirror.");
    static const Creature Rust_Dragon (         CreatureType::Rust_Dragon,         Faction::Neutral,    7, Creature::Upgrade_level::None,    1, true,  30, 30,  0, 50, 50, 750, 17, Morale::Good,    Luck::Neutral,24030,26433, {15000, 0,14, 0, 0 }, "Breath attack. Casts Weakness per attack. 20% chance to cast Acid Breath per attack.");
    static const Creature Crystal_Dragon (      CreatureType::Crystal_Dragon,      Faction::Neutral,    7, Creature::Upgrade_level::None,    1, true,  40, 40,  0, 60, 75, 800, 16, Morale::Good,    Luck::Neutral,30260,39338, {20000, 0, 0,10, 0 }, "Generates crystals. Magic resistance 20%.");
    static const Creature Azure_Dragon (        CreatureType::Azure_Dragon,        Faction::Neutral,    7, Creature::Upgrade_level::None,    1, true,  50, 50,  0, 70, 80,1000, 19, Morale::Good,    Luck::Neutral,56315,78845, {30000,20, 0, 0, 0 }, "Breath attack. 20% chance to cast Fear to adjacent enemies before they act. Immune to spells level 1-3. Immune to Fear.");

    static const std::map<CreatureType, const Creature*> Creature_List =
    {
        // Castle
        {CreatureType::Pikeman,             &Pikeman},
        {CreatureType::Halberdier,          &Halberdier},
        {CreatureType::Archer,              &Archer},
        {CreatureType::Marksman,            &Marksman},
        {CreatureType::Griffin,             &Griffin},
        {CreatureType::Royal_Griffin,       &Royal_Griffin},
        {CreatureType::Swordsman,           &Swordsman},
        {CreatureType::Crusader,            &Crusader},
        {CreatureType::Monk,                &Monk},
        {CreatureType::Zealot,              &Zealot},
        {CreatureType::Cavalier,            &Cavalier},
        {CreatureType::Champion,            &Champion},
        {CreatureType::Angel,               &Angel},
        {CreatureType::Archangel,           &Archangel},

        // Rampart
        {CreatureType::Centaur,             &Centaur},
        {CreatureType::Centaur_Captain,     &Centaur_Captain},
        {CreatureType::Dwarf,               &Dwarf},
        {CreatureType::Battle_Dwarf,        &Battle_Dwarf},
        {CreatureType::Wood_Elf,            &Wood_Elf},
        {CreatureType::Grand_Elf,           &Grand_Elf},
        {CreatureType::Pegasus,             &Pegasus},
        {CreatureType::Silver_Pegasus,      &Silver_Pegasus},
        {CreatureType::Dendroid_Guard,      &Dendroid_Guard},
        {CreatureType::Dendroid_Soldier,    &Dendroid_Soldier},
        {CreatureType::Unicorn,             &Unicorn},
        {CreatureType::War_Unicorn,         &War_Unicorn},
        {CreatureType::Green_Dragon,        &Green_Dragon},
        {CreatureType::Gold_Dragon,         &Gold_Dragon},

        // Tower
        {CreatureType::Gremlin,             &Gremlin},
        {CreatureType::Master_Gremlin,      &Master_Gremlin},
        {CreatureType::Stone_Gargoyle,      &Stone_Gargoyle},
        {CreatureType::Obsidian_Gargoyle,   &Obsidian_Gargoyle},
        {CreatureType::Stone_Golem,         &Stone_Golem},
        {CreatureType::Iron_Golem,          &Iron_Golem},
        {CreatureType::Mage,                &Mage},
        {CreatureType::Arch_Mage,           &Arch_Mage},
        {CreatureType::Genie,               &Genie},
        {CreatureType::Master_Genie,        &Master_Genie},
        {CreatureType::Naga,                &Naga},
        {CreatureType::Naga_Queen,          &Naga_Queen},
        {CreatureType::Giant,               &Giant},
        {CreatureType::Titan,               &Titan},

        //Inferno
        {CreatureType::Imp,                 &Imp},
        {CreatureType::Familiar,            &Familiar},
        {CreatureType::Gog,                 &Gog},
        {CreatureType::Magog,               &Magog},
        {CreatureType::Hell_Hound,          &Hell_Hound},
        {CreatureType::Cerberus,            &Cerberus},
        {CreatureType::Demon,               &Demon},
        {CreatureType::Horned_Demon,        &Horned_Demon},
        {CreatureType::Pit_Fiend,           &Pit_Fiend},
        {CreatureType::Pit_Lord,            &Pit_Lord},
        {CreatureType::Efreet,              &Efreet},
        {CreatureType::Efreet_Sultan,       &Efreet_Sultan},
        {CreatureType::Devil,               &Devil},
        {CreatureType::Arch_Devil,          &Arch_Devil},

        // Necropolis
        {CreatureType::Skeleton,            &Skeleton},
        {CreatureType::Skeleton_Warrior,    &Skeleton_Warrior},
        {CreatureType::Walking_Dead,        &Walking_Dead},
        {CreatureType::Zombie,              &Zombie},
        {CreatureType::Wight,               &Wight},
        {CreatureType::Wraith,              &Wraith},
        {CreatureType::Vampire,             &Vampire},
        {CreatureType::Vampire_Lord,        &Vampire_Lord},
        {CreatureType::Lich,                &Lich},
        {CreatureType::Power_Lich,          &Power_Lich},
        {CreatureType::Black_Knight,        &Black_Knight},
        {CreatureType::Dread_Knight,        &Dread_Knight},
        {CreatureType::Bone_Dragon,         &Bone_Dragon},
        {CreatureType::Ghost_Dragon,        &Ghost_Dragon},

        // Dungeon
        {CreatureType::Troglodyte,          &Troglodyte},
        {CreatureType::Infernal_Troglodyte, &Infernal_Troglodyte},
        {CreatureType::Harpy,               &Harpy},
        {CreatureType::Harpy_Hag,           &Harpy_Hag},
        {CreatureType::Beholder,            &Beholder},
        {CreatureType::Evil_Eye,            &Evil_Eye},
        {CreatureType::Medusa,              &Medusa},
        {CreatureType::Medusa_Queen,        &Medusa_Queen},
        {CreatureType::Minotaur,            &Minotaur},
        {CreatureType::Minotaur_King,       &Minotaur_King},
        {CreatureType::Manticore,           &Manticore},
        {CreatureType::Scorpicore,          &Scorpicore},
        {CreatureType::Red_Dragon,          &Red_Dragon},
        {CreatureType::Black_Dragon,        &Black_Dragon},

        // Stronghold
        {CreatureType::Goblin,              &Goblin},
        {CreatureType::Hobgoblin,           &Hobgoblin},
        {CreatureType::Wolf_Rider,          &Wolf_Rider},
        {CreatureType::Wolf_Raider,         &Wolf_Raider},
        {CreatureType::Orc,                 &Orc},
        {CreatureType::Orc_Chieftain,       &Orc_Chieftain},
        {CreatureType::Ogre,                &Ogre},
        {CreatureType::Ogre_Mage,           &Ogre_Mage},
        {CreatureType::Roc,                 &Roc},
        {CreatureType::Thunderbird,         &Thunderbird},
        {CreatureType::Cyclops,             &Cyclops},
        {CreatureType::Cyclops_King,        &Cyclops_King},
        {CreatureType::Behemoth,            &Behemoth},
        {CreatureType::Ancient_Behemoth,    &Ancient_Behemoth},

        // Fortress
        {CreatureType::Gnoll,               &Gnoll},
        {CreatureType::Gnoll_Marauder,      &Gnoll_Marauder},
        {CreatureType::Lizardman,           &Lizardman},
        {CreatureType::Lizard_Warrior,      &Lizard_Warrior},
        {CreatureType::Serpent_Fly,         &Serpent_Fly},
        {CreatureType::Dragon_Fly,          &Dragon_Fly},
        {CreatureType::Basilisk,            &Basilisk},
        {CreatureType::Greater_Basilisk,    &Greater_Basilisk},
        {CreatureType::Gorgon,              &Gorgon},
        {CreatureType::Mighty_Gorgon,       &Mighty_Gorgon},
        {CreatureType::Wyvern,              &Wyvern},
        {CreatureType::Wyvern_Monarch,      &Wyvern_Monarch},
        {CreatureType::Hydra,               &Hydra},
        {CreatureType::Chaos_Hydra,         &Chaos_Hydra},

        // Conflux
        {CreatureType::Pixie,               &Pixie},
        {CreatureType::Sprite,              &Sprite},
        {CreatureType::Air_Elemental,       &Air_Elemental},
        {CreatureType::Storm_Elemental,     &Storm_Elemental},
        {CreatureType::Water_Elemental,     &Water_Elemental},
        {CreatureType::Ice_Elemental,       &Ice_Elemental},
        {CreatureType::Fire_Elemental,      &Fire_Elemental},
        {CreatureType::Energy_Elemental,    &Energy_Elemental},
        {CreatureType::Earth_Elemental,     &Earth_Elemental},
        {CreatureType::Magma_Elemental,     &Magma_Elemental},
        {CreatureType::Psychic_Elemental,   &Psychic_Elemental},
        {CreatureType::Magic_Elemental,     &Magic_Elemental},
        {CreatureType::Firebird,            &Firebird},
        {CreatureType::Phoenix,             &Phoenix},

        // Cove
        {CreatureType::Nymph,               &Nymph},
        {CreatureType::Oceanid,             &Oceanid},
        {CreatureType::Crew_Mate,           &Crew_Mate},
        {CreatureType::Seaman,              &Seaman},
        {CreatureType::Pirate,              &Pirate},
        {CreatureType::Corsair,             &Corsair},
        {CreatureType::Sea_Dog,             &Sea_Dog},
        {CreatureType::Stormbird,           &Stormbird},
        {CreatureType::Ayssid,              &Ayssid},
        {CreatureType::Sea_Witch,           &Sea_Witch},
        {CreatureType::Sorceress,           &Sorceress},
        {CreatureType::Nix,                 &Nix},
        {CreatureType::Nix_Warrior,         &Nix_Warrior},
        {CreatureType::Sea_Serpent,         &Sea_Serpent},
        {CreatureType::Haspid,              &Haspid},

        // Neutral
        {CreatureType::Peasant,             &Peasant},
        {CreatureType::Halfling,            &Halfling},
        {CreatureType::Rogue,               &Rogue},
        {CreatureType::Boar,                &Boar},
        {CreatureType::Leprechaun,          &Leprechaun},
        {CreatureType::Nomad,               &Nomad},
        {CreatureType::Mummy,               &Mummy},
        {CreatureType::Sharpshooter,        &Sharpshooter},
        {CreatureType::Satyr,               &Satyr},
        {CreatureType::Steel_Golem,         &Steel_Golem},
        {CreatureType::Troll,               &Troll},
        {CreatureType::Gold_Golem,          &Gold_Golem},
        {CreatureType::Fangarm,             &Fangarm},
        {CreatureType::Diamond_Golem,       &Diamond_Golem},
        {CreatureType::Enchanter,           &Enchanter},
        {CreatureType::Faerie_Dragon,       &Faerie_Dragon},
        {CreatureType::Rust_Dragon,         &Rust_Dragon},
        {CreatureType::Crystal_Dragon,      &Crystal_Dragon},
        {CreatureType::Azure_Dragon,        &Azure_Dragon}
    };

    ASSERT( created_creatures == Creature_List.size(), "Creature_List map is incomplete!" );

    return Creature_List;
}

#endif