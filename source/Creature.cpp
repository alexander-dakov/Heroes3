#include <string>

#include "Creature.h"
#include "../utilities/user_macros.h"

uint8_t Creature::created_creatures = 0;

Creature::Creature( const std::string& name, const Faction faction, const uint8_t level, const Upgrade_level upgrade, const uint8_t growth, const bool needs_2_tiles_in_battle,
                    const uint8_t att, const uint8_t def, const uint8_t shots, const uint8_t min_dmg, const uint8_t max_dmg, const uint16_t hp, const uint8_t speed, const Morale morale, const Luck luck, const uint16_t fight_value, const uint32_t ai_value,
                    const Resources& resources,
                    const std::string& abilities ) :
                    unit_info(name, faction, level, upgrade, growth, needs_2_tiles_in_battle),
                    battle_stats(att, def, shots, min_dmg, max_dmg, hp, speed, morale, luck, fight_value, ai_value),
                    cost(resources),
                    special_abilities(abilities)
{
    unit_info.set_native_terrain();

    special_abilities.set_special_abilities();

    logical_limitations();

    created_creatures++;

    // printf( "Creature %s created.\n", get_name().c_str() );
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

void Creature::special_abilities::set_special_abilities()
{
    // Keep that order, because the abilities map should be filled and then the number of casts and spell power should be set.
    fill_special_abilities();

    m_number_of_casts = 0;
    m_spell_power     = 0;

    if( m_can_cast_ressurection )     { m_number_of_casts = 1; return;                    } // Archangel
    if( m_can_cast_advanced_fortune ) { m_number_of_casts = 3; m_spell_power = 6; return; } // Leprechaun
    if( m_can_cast_advanced_mirth )   { m_number_of_casts = 3; m_spell_power = 6; return; } // Satyr

    if( m_is_spellcaster )
    {
        if     ( m_hates_efreeti )    { m_number_of_casts = 3; m_spell_power = 6; return; } // Master Genie
        else if( m_has_magic_mirror ) { m_number_of_casts = 5; return;                    } // Faerie Dragon
        else                          { m_number_of_casts = 3; m_spell_power = 3; return; } // Enchanter
    }

    if( m_can_cast_bloodlust )        { m_number_of_casts = 3; m_spell_power = 3; return; } // Orge Mage
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
        special_abilities.m_is_undead = true;
        special_abilities.m_is_bloodless = false;
    }
    else if( special_abilities.m_is_undead == true )
        special_abilities.m_is_bloodless = false;

    if( special_abilities.m_is_bloodless == true )
        special_abilities.m_is_undead = false;

    if( !special_abilities.m_is_ranged )
        battle_stats.m_shots = 0;

    if( special_abilities.m_is_undead == true || special_abilities.m_is_bloodless == true ) // all undead, golems and elementals
        special_abilities.m_is_immune_to_mind_spells = true;
}

std::map< std::string, std::vector<bool*> > Creature::special_abilities::create_map_of_all_abilities()
{
    std::map< std::string, std::vector<bool*> > all_abilities; // all special abilities in existance, refering to their respective boolean

    all_abilities["Undead."]        = { &m_is_undead    };
    all_abilities["Non-living."]    = { &m_is_bloodless };

    all_abilities["Flying."]        = { &m_is_flying };
    all_abilities["Teleporting."]   = { &m_is_flying };
    all_abilities["Ranged attack."] = { &m_is_ranged };

    all_abilities["No melee penalty."]    = { &m_no_melee_penalty    };
    all_abilities["No obstacle penalty."] = { &m_no_obstacle_penalty };
    all_abilities["No range penalty."]    = { &m_no_range_penalty    };

    all_abilities["Strike and return."]      = { &m_strike_and_return       };
    all_abilities["Strike and return."]      = { &m_strike_and_return       };
    all_abilities["Can attack siege walls."] = { &m_can_attack_siege_walls  };

    all_abilities["Ferocity."]                             = { &m_has_ferocity                };
    all_abilities["Double attack."]                        = { &m_has_double_attack           };
    all_abilities["Jousting bonus."]                       = { &m_has_jousting                };
    all_abilities["Revenge."]                              = { &m_has_revenge                 };
    all_abilities["3-headed attack."]                      = { &m_has_3_headed_attack         };
    all_abilities["Fireball attack."]                      = { &m_has_fireball_attack         };
    all_abilities["Death cloud."]                          = { &m_has_cloud_attack            };
    all_abilities["Attack all adjacent enemies."]          = { &m_has_attack_adjacent_enemies };
    all_abilities["Attack all adjacent hexes."]            = { &m_has_attack_adjacent_hexes   };
    all_abilities["Breath attack."]                        = { &m_has_breath_attack           };
    all_abilities["Hates Efreeti and Efreet Sultans."]     = { &m_hates_efreeti               };
    all_abilities["Hates Genies and Master Genies."]       = { &m_hates_genies                };
    all_abilities["Hates Devils and Arch Devils."]         = { &m_hates_devils                };
    all_abilities["Hates Angels and Archangels."]          = { &m_hates_angels                };
    all_abilities["Hates Black Dragons."]                  = { &m_hates_black_dragons         };
    all_abilities["Hates Titans."]                         = { &m_hates_titans                };
    all_abilities["Ignores 40% of enemy's defense skill."] = { &m_ignore_enemy_defense        };
    all_abilities["Ignores 80% of enemy's defense skill."] = { &m_ignore_enemy_defense        };

    all_abilities["Ignores 30% of enemy's attack skill."] = { &m_ignore_enemy_attack };
    all_abilities["Ignores 60% of enemy's attack skill."] = { &m_ignore_enemy_attack };

    all_abilities["Two retaliations."]       = { &m_has_two_retaliations       };
    all_abilities["Unlimited retaliations."] = { &m_has_unlimited_retaliations };
    all_abilities["No enemy retaliation."]   = { &m_no_enemy_retaliation       };

    all_abilities["Regeneration."] = { &m_casts_regeneration };
    all_abilities["Mana drain."]   = { &m_casts_mana_drain   };

    all_abilities["Binding attack."]                                    = { &m_casts_binding                             };
    all_abilities["Life drain."]                                        = { &m_casts_life_drain                          };
    all_abilities["Casts Dispel to benefical spells per attack."]       = { &m_casts_dispell_on_buffs                    };
    all_abilities["Casts Weakness per attack."]                         = { &m_casts_weakness                            };
    all_abilities["Casts Advanced Weakness per attack."]                = { &m_casts_advanced_weakness                   };
    all_abilities["Casts Disrupting Ray on weakened enemies."]          = { &m_casts_disrupting_ray_on_weakened          };
    all_abilities["Casts Advanced Disrupting Ray on weakened enemies."] = { &m_casts_advanced_disrupting_ray_on_weakened };

    all_abilities["20% chance to cast Disease per attack."]                       = { &m_may_cast_disease          };
    all_abilities["25% chance to cast Curse per attack."]                         = { &m_may_cast_curse            };
    all_abilities["20% chance to cast Aging per attack."]                         = { &m_may_cast_aging            };
    all_abilities["30% chance to cast Poison per attack."]                        = { &m_may_cast_poison           };
    all_abilities["20% chance to cast Paralyzing Venom per attack."]              = { &m_may_cast_paralyzing_venom };
    all_abilities["20% chance to cast Fear to adjacent enemies before they act."] = { &m_may_cast_fear             };
    all_abilities["20% chance to cast Petrify per melee attack."]                 = { &m_may_cast_petrify          };
    all_abilities["20% chance to cast Petrify per attack."]                       = { &m_may_cast_petrify          };
    all_abilities["20% chance to cast Blind per attack."]                         = { &m_may_cast_blind            };
    all_abilities["20% chance to cast Lightning Strike per attack."]              = { &m_may_cast_lightning_strike };
    all_abilities["20% chance to cast Death Blow per attack."]                    = { &m_may_cast_death_blow       };
    all_abilities["10% chance to cast Death Stare per melee attack."]             = { &m_may_cast_death_stare      };
    all_abilities["10% chance to cast Accurate Shot per ranged attack."]          = { &m_may_cast_accurate_shot    };
    all_abilities["20% chance to cast Acid Breath per attack."]                   = { &m_may_cast_acid_breath      };
    all_abilities["Can cast Hypnotize per attack."]                               = { &m_may_cast_hypnotize        };

    all_abilities["Fire Shield."] = { &m_casts_fire_shield };

    all_abilities["Rebirth."] = { &m_may_cast_rebirth };

    all_abilities["Can cast Ressurection once per battle."]        = { &m_can_cast_ressurection          };
    all_abilities["Can cast Advanced Fortune 3 times per battle."] = { &m_can_cast_advanced_fortune      };
    all_abilities["Can cast Advanced Mirth 3 times per battle."]   = { &m_can_cast_advanced_mirth        };
    all_abilities["Spellcaster."]                                  = { &m_is_spellcaster                 };
    all_abilities["Spellcaster (Bloodlust)."]                      = { &m_can_cast_bloodlust             };
    all_abilities["Spellcaster (Protection from Air)."]            = { &m_can_cast_protection_from_air   };
    all_abilities["Spellcaster (Protection from Water)."]          = { &m_can_cast_protection_from_water };
    all_abilities["Spellcaster (Protection from Fire)."]           = { &m_can_cast_protection_from_fire  };
    all_abilities["Spellcaster (Protection from Earth)."]          = { &m_can_cast_protection_from_earth };
    all_abilities["Summon Demons."]                                = { &m_can_cast_summon_demons         };

    all_abilities["Magic resistance 20%."]         = { &m_has_magic_resist      };
    all_abilities["Magic resistance 40%."]         = { &m_has_magic_resist      };
    all_abilities["Aura of magic resistance 20%."] = { &m_has_magic_resist_aura };
    all_abilities["Naturally has Magic Mirror."]   = { &m_has_magic_mirror      };

    all_abilities["Spell damage reduction 50%."] = { &m_reduce_magic_damage };
    all_abilities["Spell damage reduction 75%."] = { &m_reduce_magic_damage };
    all_abilities["Spell damage reduction 80%."] = { &m_reduce_magic_damage };
    all_abilities["Spell damage reduction 85%."] = { &m_reduce_magic_damage };
    all_abilities["Spell damage reduction 95%."] = { &m_reduce_magic_damage };

    all_abilities["Immune to jousting."]                    = { &m_is_immune_to_jousting };
    all_abilities["Immune to Fear."]                        = { &m_is_immune_to_fear     };
    all_abilities["Immune to Blind."]                       = { &m_is_immune_to_blind    };
    all_abilities["Immune to Petrify."]                     = { &m_is_immune_to_petrify  };
    all_abilities["Immune to Ice Bolt and Frost Ring."]     = { &m_is_immune_to_ice_bolt, &m_is_immune_to_frost_ring };
    all_abilities["Immune to Meteor Shower."]               = { &m_is_immune_to_meteor_shower };
    all_abilities["Immune to Lightning Bolt, Chain Lightning and Armageddon."] = { &m_is_immune_to_lightning_bolt, &m_is_immune_to_chain_lightning, &m_is_immune_to_armageddon };
    all_abilities["Immune to fire spells (Magic Arrow included)."] = { &m_is_immune_to_fire_spells, &m_is_immune_to_magic_arrow };
    all_abilities["Immune to mind spells."]                 = { &m_is_immune_to_mind_spells      };
    all_abilities["Immune to spells level 1-3."]            = { &m_is_immune_to_spells_level_1_3 };
    all_abilities["Immune to spells level 1-4."]            = { &m_is_immune_to_spells_level_1_4 };
    all_abilities["Immune to all spells."]                  = { &m_is_immune_to_all_spells       };

    all_abilities["Vulnerable to Ice Bolt and Frost Ring."]                        = { &m_is_vulnerable_to_ice_bolt, &m_is_vulnerable_to_frost_ring };
    all_abilities["Vulnerable to Lightning Bolt, Chain Lightning and Armageddon."] = { &m_is_vulnerable_to_lightning_bolt, &m_is_vulnerable_to_chain_lightning, &m_is_vulnerable_to_armageddon };
    all_abilities["Vulnerable to Armageddon, Fireball, Inferno."]                  = { &m_is_vulnerable_to_armageddon, &m_is_vulnerable_to_fire_ball, &m_is_vulnerable_to_inferno };
    all_abilities["Vulnerable to Meteor Shower."]                                  = { &m_is_vulnerable_to_meteor_shower };

    all_abilities["Minimum morale is +1."] = { &m_minimum_morale_1 };
    all_abilities["Minimum luck is +1."]   = { &m_minimum_luck_1   };

    all_abilities["+1 morale to alias troops."]         = { &m_increases_alias_morale_by_1 };
    all_abilities["-1 morale to enemy troops."]         = { &m_decreases_enemy_morale_by_1 };
    all_abilities["-1 luck to enemy troops."]           = { &m_decreases_enemy_luck_by_1   };
    all_abilities["-2 luck to enemy troops."]           = { &m_decreases_enemy_luck_by_2   };
    all_abilities["Doubles friendly unit Luck chance."] = { &m_doubles_luck_chance      };

    all_abilities["Magic channel."]                         = { &m_magic_channel };
    all_abilities["Magic damper."]                          = { &m_magic_damper  };
    all_abilities["Hero's combat spells cost 2 less mana."] = { &m_mana_economy  };

    all_abilities["Spying."]             = { &m_has_spying         };
    all_abilities["Sandwalker."]         = { &m_is_sandwalker      };
    all_abilities["Generates crystals."] = { &m_generates_crystals };

    return all_abilities;
}

void Creature::special_abilities::fill_special_abilities()
{
    std::string helper = m_abilities; // a copy of the original creature ablities to cut from
    std::string::size_type pos; // position of found substring from map in "helper" string

    auto all_abilities = create_map_of_all_abilities();

    uint8_t counter = 0;

    while( helper.length() > 1) // no need to enter helper when an empty space remains
    {
        counter ++;
        if( counter > Special_abilities::MAX_NUMBER )
        {
            std::cerr << "A creature's special ability is not recognized by the algorithm. Make sure that the string in create_map_of_all_abilities() is the same as in Creature_List." << std::endl;
            std::cerr << "Problematic string : " << helper << std::endl;
            std::cerr << "Full string : " << m_abilities << std::endl;
            abort();
        }

        if( helper[0] == ' ' ) // if the first character is whitespace - delete it
        {
            helper.erase(0, 1);
            break;
        }
        else
        {
            for(auto abilities : all_abilities) // key-value pair
            {
                pos = helper.find(abilities.first);
                if( pos != std::string::npos )
                {
                    for(auto ability : abilities.second)
                        *ability = true;
                    helper.erase(pos, abilities.first.length());
                    if( helper[pos] == ' ' ) // if the new character on the same place is whitespace - delete it
                        helper.erase(pos, 1);
                    break;
                }
            }
        }
    }

    if( m_ignore_enemy_defense )
        m_ignore_enemy_defense_by_percent = 40*(m_abilities.find("Ignores 40% of enemy's defense skill.") != std::string::npos)
                                          + 80*(m_abilities.find("Ignores 80% of enemy's defense skill.") != std::string::npos);

    if( m_ignore_enemy_attack )
        m_ignore_enemy_attack_by_percent = 30*(m_abilities.find("Ignores 30% of enemy's attack skill.") != std::string::npos)
                                         + 60*(m_abilities.find("Ignores 60% of enemy's attack skill.") != std::string::npos);

    if( m_reduce_magic_damage )
        m_reduce_magic_damage_by_percent = 50*(m_abilities.find("Spell damage reduction 50%.") != std::string::npos)
                                         + 75*(m_abilities.find("Spell damage reduction 75%.") != std::string::npos)
                                         + 80*(m_abilities.find("Spell damage reduction 80%.") != std::string::npos)
                                         + 85*(m_abilities.find("Spell damage reduction 85%.") != std::string::npos)
                                         + 95*(m_abilities.find("Spell damage reduction 95%.") != std::string::npos);

    if( m_has_magic_resist )
        m_has_magic_resist_by_percent = 20*(m_abilities.find("Magic resistance 20%.") != std::string::npos)
                                      + 40*(m_abilities.find("Magic resistance 40%.") != std::string::npos);
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