#include <string>

#include "Creature.h"
#include "../utilities/user_macros.h"

uint8_t Creature::created_creatures = 0;

Creature::Creature( const CreatureType type, const Faction faction, const uint8_t level, const Upgrade_level upgrade, const uint8_t growth, const bool needs_2_tiles_in_battle,
                    const uint8_t att, const uint8_t def, const uint8_t shots, const uint8_t min_dmg, const uint8_t max_dmg, const uint16_t hp, const uint8_t speed, const Morale morale, const Luck luck, const uint16_t fight_value, const uint32_t ai_value,
                    const Resources& resources,
                    const std::string& abilities ) :
                    unit_info(type, faction, level, upgrade, growth, needs_2_tiles_in_battle),
                    battle_stats(att, def, shots, min_dmg, max_dmg, hp, speed, morale, luck, fight_value, ai_value),
                    cost(resources),
                    special_abilities(abilities)
{
    unit_info.set_name_from_enum();
    unit_info.set_native_terrain();

    special_abilities.set_special_abilities();

    logical_limitations();

    created_creatures++;

    // printf( "Creature %s created.\n", get_name().c_str() );
}

void Creature::unit_info::set_name_from_enum()
{
    switch ( this->m_type )
    {
        // Castle
        case CreatureType::Pikeman       : m_name = "Pikeman";       break;
        case CreatureType::Halberdier    : m_name = "Halberdier";    break;
        case CreatureType::Archer        : m_name = "Archer";        break;
        case CreatureType::Marksman      : m_name = "Marksman";      break;
        case CreatureType::Griffin       : m_name = "Griffin";       break;
        case CreatureType::Royal_Griffin : m_name = "Royal_Griffin"; break;
        case CreatureType::Swordsman     : m_name = "Swordsman";     break;
        case CreatureType::Crusader      : m_name = "Crusader";      break;
        case CreatureType::Monk          : m_name = "Monk";          break;
        case CreatureType::Zealot        : m_name = "Zealot";        break;
        case CreatureType::Cavalier      : m_name = "Cavalier";      break;
        case CreatureType::Champion      : m_name = "Champion";      break;
        case CreatureType::Angel         : m_name = "Angel";         break;
        case CreatureType::Archangel     : m_name = "Archangel";     break;

        // Rampart
        case CreatureType::Centaur          : m_name = "Centaur";          break;
        case CreatureType::Centaur_Captain  : m_name = "Centaur_Captain";  break;
        case CreatureType::Dwarf            : m_name = "Dwarf";            break;
        case CreatureType::Battle_Dwarf     : m_name = "Battle_Dwarf";     break;
        case CreatureType::Wood_Elf         : m_name = "Wood_Elf";         break;
        case CreatureType::Grand_Elf        : m_name = "Grand_Elf";        break;
        case CreatureType::Pegasus          : m_name = "Pegasus";          break;
        case CreatureType::Silver_Pegasus   : m_name = "Silver_Pegasus";   break;
        case CreatureType::Dendroid_Guard   : m_name = "Dendroid_Guard";   break;
        case CreatureType::Dendroid_Soldier : m_name = "Dendroid_Soldier"; break;
        case CreatureType::Unicorn          : m_name = "Unicorn";          break;
        case CreatureType::War_Unicorn      : m_name = "War_Unicorn";      break;
        case CreatureType::Green_Dragon     : m_name = "Green_Dragon";     break;
        case CreatureType::Gold_Dragon      : m_name = "Gold_Dragon";      break;

        // Tower
        case CreatureType::Gremlin           : m_name = "Gremlin";           break;
        case CreatureType::Master_Gremlin    : m_name = "Master_Gremlin";    break;
        case CreatureType::Stone_Gargoyle    : m_name = "Stone_Gargoyle";    break;
        case CreatureType::Obsidian_Gargoyle : m_name = "Obsidian_Gargoyle"; break;
        case CreatureType::Stone_Golem       : m_name = "Stone_Golem";       break;
        case CreatureType::Iron_Golem        : m_name = "Iron_Golem";        break;
        case CreatureType::Mage              : m_name = "Mage";              break;
        case CreatureType::Arch_Mage         : m_name = "Arch_Mage";         break;
        case CreatureType::Genie             : m_name = "Genie";             break;
        case CreatureType::Master_Genie      : m_name = "Master_Genie";      break;
        case CreatureType::Naga              : m_name = "Naga";              break;
        case CreatureType::Naga_Queen        : m_name = "Naga_Queen";        break;
        case CreatureType::Giant             : m_name = "Giant";             break;
        case CreatureType::Titan             : m_name = "Titan";             break;

        // Inferno
        case CreatureType::Imp           : m_name = "Imp";           break;
        case CreatureType::Familiar      : m_name = "Familiar";      break;
        case CreatureType::Gog           : m_name = "Gog";           break;
        case CreatureType::Magog         : m_name = "Magog";         break;
        case CreatureType::Hell_Hound    : m_name = "Hell_Hound";    break;
        case CreatureType::Cerberus      : m_name = "Cerberus";      break;
        case CreatureType::Demon         : m_name = "Demon";         break;
        case CreatureType::Horned_Demon  : m_name = "Horned_Demon";  break;
        case CreatureType::Pit_Fiend     : m_name = "Pit_Fiend";     break;
        case CreatureType::Pit_Lord      : m_name = "Pit_Lord";      break;
        case CreatureType::Efreet        : m_name = "Efreet";        break;
        case CreatureType::Efreet_Sultan : m_name = "Efreet_Sultan"; break;
        case CreatureType::Devil         : m_name = "Devil";         break;
        case CreatureType::Arch_Devil    : m_name = "Arch_Devil";    break;

        // Necropolis
        case CreatureType::Skeleton         : m_name = "Skeleton";         break;
        case CreatureType::Skeleton_Warrior : m_name = "Skeleton_Warrior"; break;
        case CreatureType::Walking_Dead     : m_name = "Walking_Dead";     break;
        case CreatureType::Zombie           : m_name = "Zombie";           break;
        case CreatureType::Wight            : m_name = "Wight";            break;
        case CreatureType::Wraith           : m_name = "Wraith";           break;
        case CreatureType::Vampire          : m_name = "Vampire";          break;
        case CreatureType::Vampire_Lord     : m_name = "Vampire_Lord";     break;
        case CreatureType::Lich             : m_name = "Lich";             break;
        case CreatureType::Power_Lich       : m_name = "Power_Lich";       break;
        case CreatureType::Black_Knight     : m_name = "Black_Knight";     break;
        case CreatureType::Dread_Knight     : m_name = "Dread_Knight";     break;
        case CreatureType::Bone_Dragon      : m_name = "Bone_Dragon";      break;
        case CreatureType::Ghost_Dragon     : m_name = "Ghost_Dragon";     break;

        // Dungeon
        case CreatureType::Troglodyte          : m_name = "Troglodyte";          break;
        case CreatureType::Infernal_Troglodyte : m_name = "Infernal_Troglodyte"; break;
        case CreatureType::Harpy               : m_name = "Harpy";               break;
        case CreatureType::Harpy_Hag           : m_name = "Harpy_Hag";           break;
        case CreatureType::Beholder            : m_name = "Beholder";            break;
        case CreatureType::Evil_Eye            : m_name = "Evil_Eye";            break;
        case CreatureType::Medusa              : m_name = "Medusa";              break;
        case CreatureType::Medusa_Queen        : m_name = "Medusa_Queen";        break;
        case CreatureType::Minotaur            : m_name = "Minotaur";            break;
        case CreatureType::Minotaur_King       : m_name = "Minotaur_King";       break;
        case CreatureType::Manticore           : m_name = "Manticore";           break;
        case CreatureType::Scorpicore          : m_name = "Scorpicore";          break;
        case CreatureType::Red_Dragon          : m_name = "Red_Dragon";          break;
        case CreatureType::Black_Dragon        : m_name = "Black_Dragon";        break;

        // Stronghold
        case CreatureType::Goblin           : m_name = "Goblin";           break;
        case CreatureType::Hobgoblin        : m_name = "Hobgoblin";        break;
        case CreatureType::Wolf_Rider       : m_name = "Wolf_Rider";       break;
        case CreatureType::Wolf_Raider      : m_name = "Wolf_Raider";      break;
        case CreatureType::Orc              : m_name = "Orc";              break;
        case CreatureType::Orc_Chieftain    : m_name = "Orc_Chieftain";    break;
        case CreatureType::Ogre             : m_name = "Ogre";             break;
        case CreatureType::Ogre_Mage        : m_name = "Ogre_Mage";        break;
        case CreatureType::Roc              : m_name = "Roc";              break;
        case CreatureType::Thunderbird      : m_name = "Thunderbird";      break;
        case CreatureType::Cyclops          : m_name = "Cyclops";          break;
        case CreatureType::Cyclops_King     : m_name = "Cyclops_King";     break;
        case CreatureType::Behemoth         : m_name = "Behemoth";         break;
        case CreatureType::Ancient_Behemoth : m_name = "Ancient_Behemoth"; break;

        // Fortress
        case CreatureType::Gnoll            : m_name = "Gnoll";            break;
        case CreatureType::Gnoll_Marauder   : m_name = "Gnoll_Marauder";   break;
        case CreatureType::Lizardman        : m_name = "Lizardman";        break;
        case CreatureType::Lizard_Warrior   : m_name = "Lizard_Warrior";   break;
        case CreatureType::Serpent_Fly      : m_name = "Serpent_Fly";      break;
        case CreatureType::Dragon_Fly       : m_name = "Dragon_Fly";       break;
        case CreatureType::Basilisk         : m_name = "Basilisk";         break;
        case CreatureType::Greater_Basilisk : m_name = "Greater_Basilisk"; break;
        case CreatureType::Gorgon           : m_name = "Gorgon";           break;
        case CreatureType::Mighty_Gorgon    : m_name = "Mighty_Gorgon";    break;
        case CreatureType::Wyvern           : m_name = "Wyvern";           break;
        case CreatureType::Wyvern_Monarch   : m_name = "Wyvern_Monarch";   break;
        case CreatureType::Hydra            : m_name = "Hydra";            break;
        case CreatureType::Chaos_Hydra      : m_name = "Chaos_Hydra";      break;

        // Conflux
        case CreatureType::Pixie             : m_name = "Pixie";             break;
        case CreatureType::Sprite            : m_name = "Sprite";            break;
        case CreatureType::Air_Elemental     : m_name = "Air_Elemental";     break;
        case CreatureType::Storm_Elemental   : m_name = "Storm_Elemental";   break;
        case CreatureType::Water_Elemental   : m_name = "Water_Elemental";   break;
        case CreatureType::Ice_Elemental     : m_name = "Ice_Elemental";     break;
        case CreatureType::Fire_Elemental    : m_name = "Fire_Elemental";    break;
        case CreatureType::Energy_Elemental  : m_name = "Energy_Elemental";  break;
        case CreatureType::Earth_Elemental   : m_name = "Earth_Elemental";   break;
        case CreatureType::Magma_Elemental   : m_name = "Magma_Elemental";   break;
        case CreatureType::Psychic_Elemental : m_name = "Psychic_Elemental"; break;
        case CreatureType::Magic_Elemental   : m_name = "Magic_Elemental";   break;
        case CreatureType::Firebird          : m_name = "Firebird";          break;
        case CreatureType::Phoenix           : m_name = "Phoenix";           break;

        // Cove
        case CreatureType::Nymph       : m_name = "Nymph";       break;
        case CreatureType::Oceanid     : m_name = "Oceanid";     break;
        case CreatureType::Crew_Mate   : m_name = "Crew_Mate";   break;
        case CreatureType::Seaman      : m_name = "Seaman";      break;
        case CreatureType::Pirate      : m_name = "Pirate";      break;
        case CreatureType::Corsair     : m_name = "Corsair";     break;
        case CreatureType::Sea_Dog     : m_name = "Sea_Dog";     break;
        case CreatureType::Stormbird   : m_name = "Stormbird";   break;
        case CreatureType::Ayssid      : m_name = "Ayssid";      break;
        case CreatureType::Sea_Witch   : m_name = "Sea_Witch";   break;
        case CreatureType::Sorceress   : m_name = "Sorceress";   break;
        case CreatureType::Nix         : m_name = "Nix";         break;
        case CreatureType::Nix_Warrior : m_name = "Nix_Warrior"; break;
        case CreatureType::Sea_Serpent : m_name = "Sea_Serpent"; break;
        case CreatureType::Haspid      : m_name = "Haspid";      break;

        // Neutral
        case CreatureType::Peasant        : m_name = "Peasant";        break;
        case CreatureType::Halfling       : m_name = "Halfling";       break;
        case CreatureType::Rogue          : m_name = "Rogue";          break;
        case CreatureType::Boar           : m_name = "Boar";           break;
        case CreatureType::Leprechaun     : m_name = "Leprechaun";     break;
        case CreatureType::Nomad          : m_name = "Nomad";          break;
        case CreatureType::Mummy          : m_name = "Mummy";          break;
        case CreatureType::Sharpshooter   : m_name = "Sharpshooter";   break;
        case CreatureType::Satyr          : m_name = "Satyr";          break;
        case CreatureType::Steel_Golem    : m_name = "Steel_Golem";    break;
        case CreatureType::Troll          : m_name = "Troll";          break;
        case CreatureType::Gold_Golem     : m_name = "Gold_Golem";     break;
        case CreatureType::Fangarm        : m_name = "Fangarm";        break;
        case CreatureType::Diamond_Golem  : m_name = "Diamond_Golem";  break;
        case CreatureType::Enchanter      : m_name = "Enchanter";      break;
        case CreatureType::Faerie_Dragon  : m_name = "Faerie_Dragon";  break;
        case CreatureType::Rust_Dragon    : m_name = "Rust_Dragon";    break;
        case CreatureType::Crystal_Dragon : m_name = "Crystal_Dragon"; break;
        case CreatureType::Azure_Dragon   : m_name = "Azure_Dragon";   break;
    }
}

void Creature::unit_info::set_native_terrain()
{
    switch(this->m_faction)
    {
        case Faction::Neutral    : m_native_terrain = Terrain::None;         break;
        case Faction::Castle     : m_native_terrain = Terrain::Grass;        break;
        case Faction::Rampart    : m_native_terrain = Terrain::Grass;        break;
        case Faction::Tower      : m_native_terrain = Terrain::Snow;         break;
        case Faction::Inferno    : m_native_terrain = Terrain::Lava;         break;
        case Faction::Necropolis : m_native_terrain = Terrain::Dirt;         break;
        case Faction::Dungeon    : m_native_terrain = Terrain::Subterranean; break;
        case Faction::Stronghold : m_native_terrain = Terrain::Rough;        break;
        case Faction::Fortress   : m_native_terrain = Terrain::Swamp;        break;
        case Faction::Conflux    : m_native_terrain = Terrain::Highlands;    break;
        case Faction::Cove       : m_native_terrain = Terrain::Swamp;        break;
    }
}

void Creature::logical_limitations()
{
    ASSERT( unit_info.m_level >= 1 && unit_info.m_level <= 7, "Creature level must be in the interval [1;7]!" );

    ASSERT( unit_info.m_growth > 0, "Creature must have positive growth per week!" );

    ASSERT( battle_stats.m_att > 0, "Creature must have positive attack skill!" );

    ASSERT( battle_stats.m_def > 0, "Creature must have positive defense skill!" );

    ASSERT( battle_stats.m_max_dmg >= battle_stats.m_min_dmg, "Creature's min damage mustn't be bigger than its max value!" );

    ASSERT( battle_stats.m_hp > 0, "Creature must have positive hp!" );

    ASSERT( battle_stats.m_speed > 0, "Creature must have positive speed!" );

    ASSERT( battle_stats.m_fight_value > 0, "Creature must have positive fight value!" );

    ASSERT( battle_stats.m_ai_value > 0, "Creature must have positive ai value!" );

    ASSERT( cost.m_gold > 0, "Creature must have a price including gold!" );

    if( unit_info.m_faction == Faction::Necropolis )
    {
        special_abilities.set_ability_bit(Special_abilities::Abilities::IS_UNDEAD);
        special_abilities.turn_off_ability_bit(Special_abilities::Abilities::IS_BLOODLESS);
    }
    else if( get_is_undead() )
        special_abilities.turn_off_ability_bit(Special_abilities::Abilities::IS_BLOODLESS);

    if( get_is_bloodless() )
        special_abilities.turn_off_ability_bit(Special_abilities::Abilities::IS_BLOODLESS);

    if( !get_is_ranged() )
        battle_stats.m_shots = 0;

    if( get_is_undead() || get_is_bloodless() ) // all undead, golems and elementals
        special_abilities.set_ability_bit(Special_abilities::Abilities::IS_IMMUNE_TO_MIND_SPELLS);
}

const std::map< std::string, std::vector<Special_abilities::Abilities> >& Creature::special_abilities::create_map_of_all_abilities()
{
    static std::map< std::string, std::vector<Special_abilities::Abilities> > all_abilities; // all special abilities in existance, refering to their respective boolean

    all_abilities["Undead."]        = { Special_abilities::Abilities::IS_UNDEAD    };
    all_abilities["Non-living."]    = { Special_abilities::Abilities::IS_BLOODLESS };

    all_abilities["Flying."]        = { Special_abilities::Abilities::IS_FLYING };
    all_abilities["Teleporting."]   = { Special_abilities::Abilities::IS_FLYING };
    all_abilities["Ranged attack."] = { Special_abilities::Abilities::IS_RANGED };

    all_abilities["No melee penalty."]    = { Special_abilities::Abilities::NO_MELEE_PENALTY    };
    all_abilities["No obstacle penalty."] = { Special_abilities::Abilities::NO_OBSTACLE_PENALTY };
    all_abilities["No range penalty."]    = { Special_abilities::Abilities::NO_RANGE_PENALTY    };

    all_abilities["Strike and return."]      = { Special_abilities::Abilities::STRIKE_AND_RETURN       };
    all_abilities["Strike and return."]      = { Special_abilities::Abilities::STRIKE_AND_RETURN       };
    all_abilities["Can attack siege walls."] = { Special_abilities::Abilities::CAN_ATTACK_SIEGE_WALLS  };

    all_abilities["Ferocity."]                             = { Special_abilities::Abilities::HAS_FEROCITY                };
    all_abilities["Double attack."]                        = { Special_abilities::Abilities::HAS_DOUBLE_ATTACK           };
    all_abilities["Jousting bonus."]                       = { Special_abilities::Abilities::HAS_JOUSTING                };
    all_abilities["Revenge."]                              = { Special_abilities::Abilities::HAS_REVENGE                 };
    all_abilities["3-headed attack."]                      = { Special_abilities::Abilities::HAS_3_HEADED_ATTACK         };
    all_abilities["Fireball attack."]                      = { Special_abilities::Abilities::HAS_FIREBALL_ATTACK         };
    all_abilities["Death cloud."]                          = { Special_abilities::Abilities::HAS_CLOUD_ATTACK            };
    all_abilities["Attack all adjacent enemies."]          = { Special_abilities::Abilities::HAS_ATTACK_ADJACENT_ENEMIES };
    all_abilities["Attack all adjacent hexes."]            = { Special_abilities::Abilities::HAS_ATTACK_ADJACENT_HEXES   };
    all_abilities["Breath attack."]                        = { Special_abilities::Abilities::HAS_BREATH_ATTACK           };
    all_abilities["Hates Efreeti and Efreet Sultans."]     = { Special_abilities::Abilities::HATES_EFREETI               };
    all_abilities["Hates Genies and Master Genies."]       = { Special_abilities::Abilities::HATES_GENIES                };
    all_abilities["Hates Devils and Arch Devils."]         = { Special_abilities::Abilities::HATES_DEVILS                };
    all_abilities["Hates Angels and Archangels."]          = { Special_abilities::Abilities::HATES_ANGELS                };
    all_abilities["Hates Black Dragons."]                  = { Special_abilities::Abilities::HATES_BLACK_DRAGONS         };
    all_abilities["Hates Titans."]                         = { Special_abilities::Abilities::HATES_TITANS                };
    all_abilities["Ignores 40% of enemy's defense skill."] = { Special_abilities::Abilities::IGNORE_ENEMY_DEFENSE        };
    all_abilities["Ignores 80% of enemy's defense skill."] = { Special_abilities::Abilities::IGNORE_ENEMY_DEFENSE        };

    all_abilities["Ignores 30% of enemy's attack skill."] = { Special_abilities::Abilities::IGNORE_ENEMY_ATTACK };
    all_abilities["Ignores 60% of enemy's attack skill."] = { Special_abilities::Abilities::IGNORE_ENEMY_ATTACK };

    all_abilities["Two retaliations."]       = { Special_abilities::Abilities::HAS_TWO_RETALIATIONS       };
    all_abilities["Unlimited retaliations."] = { Special_abilities::Abilities::HAS_UNLIMITED_RETALIATIONS };
    all_abilities["No enemy retaliation."]   = { Special_abilities::Abilities::HAS_NO_ENEMY_RETALIATIONS  };

    all_abilities["Regeneration."] = { Special_abilities::Abilities::CASTS_REGENERATION };
    all_abilities["Mana drain."]   = { Special_abilities::Abilities::CASTS_MANA_DRAIN   };

    all_abilities["Binding attack."]                                    = { Special_abilities::Abilities::CASTS_BINDING                             };
    all_abilities["Life drain."]                                        = { Special_abilities::Abilities::CASTS_LIFE_DRAIN                          };
    all_abilities["Casts Dispel to benefical spells per attack."]       = { Special_abilities::Abilities::CASTS_DISPELL_ON_BUFFS                    };
    all_abilities["Casts Weakness per attack."]                         = { Special_abilities::Abilities::CASTS_WEAKNESS                            };
    all_abilities["Casts Advanced Weakness per attack."]                = { Special_abilities::Abilities::CASTS_ADVANCED_WEAKNESS                   };
    all_abilities["Casts Disrupting Ray on weakened enemies."]          = { Special_abilities::Abilities::CASTS_DISRUPTING_RAY_ON_WEAKEND          };
    all_abilities["Casts Advanced Disrupting Ray on weakened enemies."] = { Special_abilities::Abilities::CASTS_ADVANCED_DISRUPTING_RAY_ON_WEAKEND };

    all_abilities["20% chance to cast Disease per attack."]                       = { Special_abilities::Abilities::MAY_CAST_DISEASE          };
    all_abilities["25% chance to cast Curse per attack."]                         = { Special_abilities::Abilities::MAY_CAST_CURSE            };
    all_abilities["20% chance to cast Aging per attack."]                         = { Special_abilities::Abilities::MAY_CAST_AGING            };
    all_abilities["30% chance to cast Poison per attack."]                        = { Special_abilities::Abilities::MAY_CAST_POISON           };
    all_abilities["20% chance to cast Paralyzing Venom per attack."]              = { Special_abilities::Abilities::MAY_CAST_PARALYZING_VENOM };
    all_abilities["20% chance to cast Fear to adjacent enemies before they act."] = { Special_abilities::Abilities::MAY_CAST_FEAR             };
    all_abilities["20% chance to cast Petrify per melee attack."]                 = { Special_abilities::Abilities::MAY_CAST_PETRIFY          };
    all_abilities["20% chance to cast Petrify per attack."]                       = { Special_abilities::Abilities::MAY_CAST_PETRIFY          };
    all_abilities["20% chance to cast Blind per attack."]                         = { Special_abilities::Abilities::MAY_CAST_BLIND            };
    all_abilities["20% chance to cast Lightning Strike per attack."]              = { Special_abilities::Abilities::MAY_CAST_LIGHTNING_STRIKE };
    all_abilities["20% chance to cast Death Blow per attack."]                    = { Special_abilities::Abilities::MAY_CAST_DEATH_BLOW       };
    all_abilities["10% chance to cast Death Stare per melee attack."]             = { Special_abilities::Abilities::MAY_CAST_DEATH_STARE      };
    all_abilities["10% chance to cast Accurate Shot per ranged attack."]          = { Special_abilities::Abilities::MAY_CAST_ACCURATE_SHOT    };
    all_abilities["20% chance to cast Acid Breath per attack."]                   = { Special_abilities::Abilities::MAY_CAST_ACID_BREATH      };
    all_abilities["Can cast Hypnotize per attack."]                               = { Special_abilities::Abilities::MAY_CAST_HYPNOTIZE        };

    all_abilities["Fire Shield."] = { Special_abilities::Abilities::CASTS_FIRE_SHIELD };

    all_abilities["Rebirth."] = { Special_abilities::Abilities::MAY_CAST_REBIRTH };

    all_abilities["Can cast Ressurection once per battle."]        = { Special_abilities::Abilities::CAN_CAST_RESSURECTION          };
    all_abilities["Can cast Advanced Fortune 3 times per battle."] = { Special_abilities::Abilities::CAN_CAST_ADVANCED_FORTUNE      };
    all_abilities["Can cast Advanced Mirth 3 times per battle."]   = { Special_abilities::Abilities::CAN_CAST_ADVANCED_MIRTH        };
    all_abilities["Spellcaster."]                                  = { Special_abilities::Abilities::IS_SPELLCASTER                 };
    all_abilities["Spellcaster (Bloodlust)."]                      = { Special_abilities::Abilities::CAN_CAST_BLOODLUST             };
    all_abilities["Spellcaster (Protection from Air)."]            = { Special_abilities::Abilities::CAN_CAST_PROTECTION_FROM_AIR   };
    all_abilities["Spellcaster (Protection from Water)."]          = { Special_abilities::Abilities::CAN_CAST_PROTECTION_FROM_WATER };
    all_abilities["Spellcaster (Protection from Fire)."]           = { Special_abilities::Abilities::CAN_CAST_PROTECTION_FROM_FIRE  };
    all_abilities["Spellcaster (Protection from Earth)."]          = { Special_abilities::Abilities::CAN_CAST_PROTECTION_FROM_EARTH };
    all_abilities["Summon Demons."]                                = { Special_abilities::Abilities::CAN_CAST_SUMMON_DEMONS         };

    all_abilities["Magic resistance 20%."]         = { Special_abilities::Abilities::HAS_MAGIC_RESIST      };
    all_abilities["Magic resistance 40%."]         = { Special_abilities::Abilities::HAS_MAGIC_RESIST      };
    all_abilities["Aura of magic resistance 20%."] = { Special_abilities::Abilities::HAS_MAGIC_RESIST_AURA };
    all_abilities["Naturally has Magic Mirror."]   = { Special_abilities::Abilities::HAS_MAGIC_MIRROR      };

    all_abilities["Spell damage reduction 50%."] = { Special_abilities::Abilities::REDUCE_MAGIC_DAMAGE };
    all_abilities["Spell damage reduction 75%."] = { Special_abilities::Abilities::REDUCE_MAGIC_DAMAGE };
    all_abilities["Spell damage reduction 80%."] = { Special_abilities::Abilities::REDUCE_MAGIC_DAMAGE };
    all_abilities["Spell damage reduction 85%."] = { Special_abilities::Abilities::REDUCE_MAGIC_DAMAGE };
    all_abilities["Spell damage reduction 95%."] = { Special_abilities::Abilities::REDUCE_MAGIC_DAMAGE };

    all_abilities["Immune to jousting."]                    = { Special_abilities::Abilities::IS_IMMUNE_TO_JOUSTING };
    all_abilities["Immune to Fear."]                        = { Special_abilities::Abilities::IS_IMMUNE_TO_FEAR     };
    all_abilities["Immune to Blind."]                       = { Special_abilities::Abilities::IS_IMMUNE_TO_BLIND    };
    all_abilities["Immune to Petrify."]                     = { Special_abilities::Abilities::IS_IMMUNE_TO_PETRIFY  };
    all_abilities["Immune to Ice Bolt and Frost Ring."]     = { Special_abilities::Abilities::IS_IMMUNE_TO_ICE_BOLT, Special_abilities::Abilities::IS_IMMUNE_TO_FROST_RING };
    all_abilities["Immune to Meteor Shower."]               = { Special_abilities::Abilities::IS_IMMUNE_TO_METEOR_SHOWER };
    all_abilities["Immune to Lightning Bolt, Chain Lightning and Armageddon."] = { Special_abilities::Abilities::IS_IMMUNE_TO_LIGHTNING_BOLT, Special_abilities::Abilities::IS_IMMUNE_TO_CHAIN_LIGHTNING, Special_abilities::Abilities::IS_IMMUNE_TO_ARMAGEDDON };
    all_abilities["Immune to fire spells (Magic Arrow included)."] = { Special_abilities::Abilities::IS_IMMUNE_TO_FIRE_SPELLS, Special_abilities::Abilities::IS_IMMUNE_TO_MAGIC_ARROW };
    all_abilities["Immune to mind spells."]                 = { Special_abilities::Abilities::IS_IMMUNE_TO_MIND_SPELLS      };
    all_abilities["Immune to spells level 1-3."]            = { Special_abilities::Abilities::IS_IMMUNE_TO_SPELLS_LEVEL_1_3 };
    all_abilities["Immune to spells level 1-4."]            = { Special_abilities::Abilities::IS_IMMUNE_TO_SPELLS_LEVEL_1_4 };
    all_abilities["Immune to all spells."]                  = { Special_abilities::Abilities::IS_IMMUNE_TO_ALL_SPELLS       };

    all_abilities["Vulnerable to Ice Bolt and Frost Ring."]                        = { Special_abilities::Abilities::IS_VULNERABLE_TO_ICE_BOLT, Special_abilities::Abilities::IS_VULNERABLE_TO_FROST_RING };
    all_abilities["Vulnerable to Lightning Bolt, Chain Lightning and Armageddon."] = { Special_abilities::Abilities::IS_VULNERABLE_TO_LIGHTNING_BOLT, Special_abilities::Abilities::IS_VULNERABLE_TO_CHAIN_LIGHTNING, Special_abilities::Abilities::IS_VULNERABLE_TO_ARMAGEDDON };
    all_abilities["Vulnerable to Armageddon, Fireball, Inferno."]                  = { Special_abilities::Abilities::IS_VULNERABLE_TO_ARMAGEDDON, Special_abilities::Abilities::IS_VULNERABLE_TO_FIRE_BALL, Special_abilities::Abilities::IS_VULNERABLE_TO_INFERNO };
    all_abilities["Vulnerable to Meteor Shower."]                                  = { Special_abilities::Abilities::IS_VULNERABLE_TO_METEOR_SHOWER };

    all_abilities["Minimum morale is +1."] = { Special_abilities::Abilities::MINIMUM_MORALE_1 };
    all_abilities["Minimum luck is +1."]   = { Special_abilities::Abilities::MINIMUM_LUCK_1   };

    all_abilities["+1 morale to alias troops."]         = { Special_abilities::Abilities::INCREASES_ALIAS_MORALE_BY_1 };
    all_abilities["-1 morale to enemy troops."]         = { Special_abilities::Abilities::DECREASES_ENEMY_MORALE_BY_1 };
    all_abilities["-1 luck to enemy troops."]           = { Special_abilities::Abilities::DECREASES_ENEMY_LUCK_BY_1   };
    all_abilities["-2 luck to enemy troops."]           = { Special_abilities::Abilities::DECREASES_ENEMY_LUCK_BY_2   };
    all_abilities["Doubles friendly unit Luck chance."] = { Special_abilities::Abilities::DOUBLES_LUCK_CHANCE      };

    all_abilities["Magic channel."]                         = { Special_abilities::Abilities::MAGIC_CHANNEL };
    all_abilities["Magic damper."]                          = { Special_abilities::Abilities::MAGIC_DAMPER  };
    all_abilities["Hero's combat spells cost 2 less mana."] = { Special_abilities::Abilities::MANA_ECONOMY  };

    all_abilities["Spying."]             = { Special_abilities::Abilities::HAS_SPYING         };
    all_abilities["Sandwalker."]         = { Special_abilities::Abilities::IS_SANDWALKER      };
    all_abilities["Generates crystals."] = { Special_abilities::Abilities::GENERATES_CRYSTALS };

    return all_abilities;
}

void Creature::special_abilities::set_special_abilities()
{
    std::string helper = m_abilities_str; // a copy of the original creature ablities to cut from
    std::string::size_type pos; // position of found substring from map in "helper" string

    const auto all_abilities = create_map_of_all_abilities();

    uint8_t counter = 0;

    while( helper.length() > 1) // no need to enter helper when an empty space remains
    {
        counter ++;
        if( counter > Special_abilities::MAX_NUMBER )
        {
            std::cerr << "A creature's special ability is not recognized by the algorithm. Make sure that the string in create_map_of_all_abilities() is the same as in Creature_List." << std::endl;
            std::cerr << "Problematic string : " << helper << std::endl;
            std::cerr << "Full string : " << m_abilities_str << std::endl;
            abort();
        }

        if( helper[0] == ' ' ) // if the first character is whitespace - delete it
        {
            helper.erase(0, 1);
            break;
        }
        else
        {
            for(const auto abilities : all_abilities) // key-value pair
            {
                pos = helper.find(abilities.first);
                if( pos != std::string::npos )
                {
                    for(auto ability : abilities.second)
                        set_ability_bit(ability);
                    helper.erase(pos, abilities.first.length());
                    if( helper[pos] == ' ' ) // if the new character on the same place is whitespace - delete it
                        helper.erase(pos, 1);
                    break;
                }
            }
        }
    }

    if( get_ability_bit(Special_abilities::Abilities::IGNORE_ENEMY_DEFENSE) )
        m_ignore_enemy_defense_by_percent = 40*(m_abilities_str.find("Ignores 40% of enemy's defense skill.") != std::string::npos)
                                          + 80*(m_abilities_str.find("Ignores 80% of enemy's defense skill.") != std::string::npos);

    if( get_ability_bit(Special_abilities::Abilities::IGNORE_ENEMY_ATTACK) )
        m_ignore_enemy_attack_by_percent = 30*(m_abilities_str.find("Ignores 30% of enemy's attack skill.") != std::string::npos)
                                         + 60*(m_abilities_str.find("Ignores 60% of enemy's attack skill.") != std::string::npos);

    if( get_ability_bit(Special_abilities::Abilities::REDUCE_MAGIC_DAMAGE) )
        m_reduce_magic_damage_by_percent = 50*(m_abilities_str.find("Spell damage reduction 50%.") != std::string::npos)
                                         + 75*(m_abilities_str.find("Spell damage reduction 75%.") != std::string::npos)
                                         + 80*(m_abilities_str.find("Spell damage reduction 80%.") != std::string::npos)
                                         + 85*(m_abilities_str.find("Spell damage reduction 85%.") != std::string::npos)
                                         + 95*(m_abilities_str.find("Spell damage reduction 95%.") != std::string::npos);

    if( get_ability_bit(Special_abilities::Abilities::HAS_MAGIC_RESIST) )
        m_has_magic_resist_by_percent = 20*(m_abilities_str.find("Magic resistance 20%.") != std::string::npos)
                                      + 40*(m_abilities_str.find("Magic resistance 40%.") != std::string::npos);

    if( get_ability_bit(Special_abilities::Abilities::CAN_CAST_RESSURECTION) )     { m_number_of_casts = 1; return;                    } // Archangel
    if( get_ability_bit(Special_abilities::Abilities::CAN_CAST_ADVANCED_FORTUNE) ) { m_number_of_casts = 3; m_spell_power = 6; return; } // Leprechaun
    if( get_ability_bit(Special_abilities::Abilities::CAN_CAST_ADVANCED_MIRTH) )   { m_number_of_casts = 3; m_spell_power = 6; return; } // Satyr

    if( get_ability_bit(Special_abilities::Abilities::IS_SPELLCASTER) )
    {
        if     ( get_ability_bit(Special_abilities::Abilities::HATES_EFREETI) )    { m_number_of_casts = 3; m_spell_power = 6; return; } // Master Genie
        else if( get_ability_bit(Special_abilities::Abilities::HAS_MAGIC_MIRROR) ) { m_number_of_casts = 5; return;                    } // Faerie Dragon
        else                          { m_number_of_casts = 3; m_spell_power = 3; return; } // Enchanter
    }

    if( get_ability_bit(Special_abilities::Abilities::CAN_CAST_BLOODLUST) )        { m_number_of_casts = 3; m_spell_power = 3; return; } // Orge Mage
}

std::string Creature::get_faction_as_string() const
{
    std::string faction;

    switch(get_faction())
    {
        case Faction::Neutral    : faction = "Neutral";    break;
        case Faction::Castle     : faction = "Castle";     break;
        case Faction::Rampart    : faction = "Rampart";    break;
        case Faction::Tower      : faction = "Tower";      break;
        case Faction::Inferno    : faction = "Inferno";    break;
        case Faction::Necropolis : faction = "Necropolis"; break;
        case Faction::Dungeon    : faction = "Dungeon";    break;
        case Faction::Stronghold : faction = "Stronghold"; break;
        case Faction::Fortress   : faction = "Fortress";   break;
        case Faction::Conflux    : faction = "Conflux";    break;
        case Faction::Cove       : faction = "Cove";       break;
    }

    return faction;
}

std::string Creature::get_cost() const
{
    std::string str;

    if( cost.m_gold     ) str += "Gold : "     + std::to_string(cost.m_gold)     + '\n';
    if( cost.m_mercury  ) str += "Mercury : "  + std::to_string(cost.m_mercury)  + '\n';
    if( cost.m_sulfur   ) str += "Sulfur : "   + std::to_string(cost.m_sulfur)   + '\n';
    if( cost.m_crystals ) str += "Crystals : " + std::to_string(cost.m_crystals) + '\n';
    if( cost.m_gems     ) str += "Gems : "     + std::to_string(cost.m_gems)     + '\n';

    return str;
}

void Creature::print_full_info() const
{
    printf( "\n" );
    printf( "Name : %s\n",    get_name().c_str() );
    printf( "Faction : %s\n", get_faction_as_string().c_str() );
    printf( "Level : %d\n",   get_level() );
    printf( "Level of upgrade : %d\n", get_upgrade() );
    printf( "Growth per week : %d\n",  get_growth()  );
    printf( "Attack : %d\n",  get_att() );
    printf( "Defense : %d\n", get_def() );

    if( get_is_ranged() )
        printf( "Shots : %d\n", get_shots() );

    if( get_min_dmg() != get_max_dmg() )
        printf( "Damage : %d - %d\n", get_min_dmg(), get_max_dmg() );
    else
        printf( "Damage : %d\n", get_min_dmg() );

    printf( "Health : %d\n", get_hp()     );
    printf( "Speed : %d\n",  get_speed()  );
    printf( "Morale : %d\n", get_morale() );
    printf( "Luck : %d\n",   get_luck()   );
    printf( "Fight value : %d\n", get_fight_value() );
    printf( "AI value : %d\n",    get_ai_value()    );
    printf( "%s", get_cost().c_str() );

    if( get_special_abilities().length() != 0 )
        printf( "Special abilities : %s\n", get_special_abilities().c_str() );
}