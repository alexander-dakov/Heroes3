#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <cstdint>
#include <map>
#include <string>
#include <vector>

#include "Faction.h"
#include "Terrains.h"
#include "Morale_Luck.h"
#include "Resources.h"

// TODO: Disable all constructors but the parametrized. Make it private.
// TODO: Make an enum2str function which will be called in the constructor.
// TODO: Make the operators check the enum field, instead of come parameters.
// TODO: Change the constructor to accept the enum instead of string.
enum CreatureType
{
    // Castle
    Pikeman, Halberdier, Archer, Marksman, Griffin, Royal_Griffin, Swordsman, Crusader, Monk, Zealot, Cavalier, Champion, Angel, Archangel,

    // Rampart
    Centaur, Centaur_Captain, Dwarf, Battle_Dwarf, Wood_Elf, Grand_Elf, Pegasus, Silver_Pegasus, Dendroid_Guard, Dendroid_Soldier, Unicorn, War_Unicorn, Green_Dragon, Gold_Dragon,

    // Tower
    Gremlin, Master_Gremlin, Stone_Gargoyle, Obsidian_Gargoyle, Stone_Golem, Iron_Golem, Mage, Arch_Mage, Genie, Master_Genie, Naga, Naga_Queen, Giant, Titan,

    // Inferno
    Imp, Familiar, Gog, Magog, Hell_Hound, Cerberus, Demon, Horned_Demon, Pit_Fiend, Pit_Lord, Efreet, Efreet_Sultan, Devil, Arch_Devil,

    // Necropolis
    Skeleton, Skeleton_Warrior, Walking_Dead, Zombie, Wight, Wraith, Vampire, Vampire_Lord, Lich, Power_Lich, Black_Knight, Dread_Knight, Bone_Dragon, Ghost_Dragon,

    // Dungeon
    Troglodyte, Infernal_Troglodyte, Harpy, Harpy_Hag, Beholder, Evil_Eye, Medusa, Medusa_Queen, Minotaur, Minotaur_King, Manticore, Scorpicore, Red_Dragon, Black_Dragon,

    // Stronghold
    Goblin, Hobgoblin, Wolf_Rider, Wolf_Raider, Orc, Orc_Chieftain, Ogre, Ogre_Mage, Roc, Thunderbird, Cyclops, Cyclops_King, Behemoth, Ancient_Behemoth,

    // Fortress
    Gnoll, Gnoll_Marauder, Lizardman, Lizard_Warrior, Serpent_Fly, Dragon_Fly, Basilisk, Greater_Basilisk, Gorgon, Mighty_Gorgon, Wyvern, Wyvern_Monarch, Hydra, Chaos_Hydra,

    // Conflux
    Pixie, Sprite, Air_Elemental, Storm_Elemental, Water_Elemental, Ice_Elemental, Fire_Elemental, Energy_Elemental, Earth_Elemental, Magma_Elemental, Psychic_Elemental, Magic_Elemental, Firebird, Phoenix,

    // Cove
    Nymph, Oceanid, Crew_Mate, Seaman, Pirate, Corsair, Sea_Dog, Stormbird, Ayssid, Sea_Witch, Sorceress, Nix, Nix_Warrior, Sea_Serpent, Haspid,

    // Neutral
    Peasant, Halfling, Rogue, Boar, Leprechaun, Nomad, Mummy, Sharpshooter, Satyr, Steel_Golem, Troll, Gold_Golem, Fangarm, Diamond_Golem, Enchanter, Faerie_Dragon, Rust_Dragon, Crystal_Dragon, Azure_Dragon
};

namespace Special_abilities
{
    const uint8_t MAX_NUMBER = 6; // used to catch inaccuracies when constructing objects in Creature_List.cpp

    namespace Chance_to_cast // Special abilities that might cast a spell per attack have a fixed chance.
    {
        const uint8_t DISEASE          = 20;
        const uint8_t CURSE            = 25;
        const uint8_t AGING            = 20;
        const uint8_t POISON           = 30;
        const uint8_t PARALYZING_VENOM = 20;
        const uint8_t FEAR             = 20;
        const uint8_t PETRIFY          = 20;
        const uint8_t BLIND            = 20;
        const uint8_t LIGHTNING_STRIKE = 20;
        const uint8_t DEATH_BLOW       = 20;
        const uint8_t DEATH_STARE      = 10;
        const uint8_t ACCURATE_SHOT    = 10;
        const uint8_t ACID_BREATH      = 20;
    };
};

struct Creature
{
    public:
        enum Upgrade_level
        {
            None = 0,
            First,
            Second
        };

    private:
        // Disallow the use of default constructor.
        Creature() = delete;

        // Parametrized constructor. Calls Logical_Limitations_When_Constructing().
        Creature( const std::string& name, const Faction faction, const uint8_t level, const Upgrade_level upgrade, const uint8_t growth, const bool needs_2_tiles_in_battle,
                const uint8_t att, const uint8_t def, const uint8_t shots, const uint8_t min_dmg, const uint8_t max_dmg, const uint16_t hp, const uint8_t speed, const Morale morale, const Luck luck, const uint16_t fight_value, const uint32_t ai_value,
                const Resources& resources,
                const std::string& abilities );

        // Disallow the use of copy constructor by reference.
        Creature(const Creature& creature) = delete;

        // Disallow the use of move constructor.
        Creature(Creature&& creature) = delete;

        // Destructor
        ~Creature() = default;

    public:
        // It would be quicker to compare creatures by their faction, level and upgrade, rather than by their names (string).
        bool operator==(const Creature& other) const { return ( get_faction() == other.get_faction() ) && ( get_level() == other.get_level() ) && ( get_upgrade() == other.get_upgrade() ); }
        bool operator!=(const Creature& other) const { return ( get_faction() != other.get_faction() ) || ( get_level() != other.get_level() ) || ( get_upgrade() != other.get_upgrade() ); }

    private:
        // Create all creatures in the game, using the private constructor. Add them to a static constant map.
        static const std::map<CreatureType, const Creature*>& create_and_fill_creatures_list();
        // Use a counter to keep track if the map containing all Creature objects is incomplete.
        static uint8_t created_creatures;

    public:
        // Return a pointer to already created Creature object.
        static const Creature* get(const CreatureType creature_type) { return create_and_fill_creatures_list().at(creature_type); }

    private:
        struct unit_info
        {
            std::string m_name;
            Faction m_faction;
            Terrain m_native_terrain;
            uint8_t m_level;
            Upgrade_level m_upgrade;
            uint8_t m_growth;
            bool m_needs_2_tiles_in_battle;

            // Sets the native terrain of a creature, according to its faction.
            void set_native_terrain();

            // Constructs a private structure containing data used for overview
            unit_info( std::string name, Faction faction, uint8_t level, Upgrade_level upgrade, uint8_t growth, bool needs_2_tiles_in_battle ) :
                        m_name(name), m_faction(faction), m_level(level), m_upgrade(upgrade), m_growth(growth), m_needs_2_tiles_in_battle(needs_2_tiles_in_battle)
                        {};
        }unit_info;

        struct battle_stats
        {
            uint8_t m_att;
            uint8_t m_def;
            uint8_t m_shots;
            uint8_t m_min_dmg;
            uint8_t m_max_dmg;
            uint16_t m_hp;
            uint8_t m_speed;
            Morale m_morale;
            Luck m_luck;
            uint16_t m_fight_value;
            uint32_t m_ai_value;

            // Constructs a private structure containing data used during battles
            battle_stats( const uint8_t att, const uint8_t def, const uint8_t shots, const uint8_t min_dmg, const uint8_t max_dmg,
                            const uint16_t hp, const uint8_t speed, Morale morale, Luck luck, const uint16_t fight_value, const uint32_t ai_value ) :
                            m_att(att), m_def(def), m_shots(shots), m_min_dmg(min_dmg), m_max_dmg(max_dmg), m_hp(hp), m_speed(speed),
                            m_morale(morale), m_luck(luck), m_fight_value(fight_value), m_ai_value(ai_value)
                            {};
        }battle_stats;

        struct cost
        {
            uint16_t m_gold     = 0;
            uint16_t m_mercury  = 0;
            uint16_t m_sulfur   = 0;
            uint16_t m_crystals = 0;
            uint16_t m_gems     = 0;

            // Constructs a private structure containing data used when purchasing a unit
            cost( const Resources& resources ) : m_gold(resources.Gold), m_mercury(resources.Mercury), m_sulfur(resources.Sulfur), m_crystals(resources.Crystals), m_gems(resources.Gems)
            {};
        }cost;

        // All special abilities placed into booleans.
        struct special_abilities
        {
            std::string m_abilities = "";

            // living type
            bool m_is_undead    = false; // all Necropolis units
            bool m_is_bloodless = false; // Gagroyles, Golems, Elementals

            // attack type
            bool m_is_flying = false;
            bool m_is_ranged = false;

            // attack penalty
            bool m_no_melee_penalty    = false; // Mage, Arch Mage, Titan
            bool m_no_obstacle_penalty = false; // Mage, Arch Mage, Zealot
            bool m_no_range_penalty    = false; // Sharpshooter

            // attack style
            bool m_strike_and_return      = false; // Harpy, Harpy Hag
            bool m_can_attack_siege_walls = false; // Cyclops, Cyclops King

            // attack bonus
            bool m_has_ferocity                = false; // Ayssid; Effect : if a unit from the attacked stack dies, a seconda attack follows
            bool m_has_double_attack           = false; // Marksman, Crusader, Grand Elf
            bool m_has_jousting                = false; // Cavalier, Champion
            bool m_has_revenge                 = false; // Haspid; Effect : attacks deal a bit more damage after stack suffers damage
            bool m_has_3_headed_attack         = false; // Cerberus
            bool m_has_fireball_attack         = false; // Magog
            bool m_has_cloud_attack            = false; // Lich, Power Lich
            bool m_has_attack_adjacent_enemies = false; // Hydra, Chaos Hydra
            bool m_has_attack_adjacent_hexes   = false; // Magic Elemental, Psychic Elemental
            bool m_has_breath_attack           = false; // Firebird, Pheonix, Dragons: Green + Gold + Red + Black + Faerie + Rust + Azure
            bool m_hates_efreeti               = false; // Genie, Master Genie
            bool m_hates_genies                = false; // Efreet, Efreet Sultan
            bool m_hates_devils                = false; // Angel, Archangel
            bool m_hates_angels                = false; // Devil, Arch Devil
            bool m_hates_black_dragons         = false; // Titan
            bool m_hates_titans                = false; // Black Dragon

            bool    m_ignore_enemy_defense = false;        // Behemoth, Ancient Behemoth
            uint8_t m_ignore_enemy_defense_by_percent = 0; // Behemoth, Ancient Behemoth

            // defense bonus
            bool    m_ignore_enemy_attack = false;        // Nix, Nix Warrior
            uint8_t m_ignore_enemy_attack_by_percent = 0; // Nix, Nix Warrior

            // retaliation
            bool m_has_two_retaliations       = false; // Griffin
            bool m_has_unlimited_retaliations = false; // Royal Griffin
            bool m_no_enemy_retaliation       = false; // Naga, Naga Queen, Devil, Arch Devil

            // casts per turn
            bool m_casts_regeneration = false;
            bool m_casts_mana_drain   = false; // Wraith; Effect = enemy hero's spell points are reduced by 2.

            // casts after attack
            bool m_casts_binding                             = false; // Dendroid Guard, Dendroid Soldier; Effect = snare until Dendroids die or move.
            bool m_casts_life_drain                          = false; // Vampire Lord
            bool m_casts_dispell_on_buffs                    = false; // Serpent Fly, Dragon Fly
            bool m_casts_weakness                            = false; // Sea Witch
            bool m_casts_advanced_weakness                   = false; // Dragon Fly, Sorceress
            bool m_casts_disrupting_ray_on_weakened          = false; // Sea Witch
            bool m_casts_advanced_disrupting_ray_on_weakened = false; // Sorceress

            // some chance of cast per attack
            bool m_may_cast_disease          = false; // Zombie
            bool m_may_cast_curse            = false; // Black Knigt, Dread Knight
            bool m_may_cast_aging            = false; // Ghost Dragon
            bool m_may_cast_poison           = false; // Wyvern Monarch, Sea Serpent, Haspid
            bool m_may_cast_paralyzing_venom = false; // Scorpicore
            bool m_may_cast_fear             = false; // Azure Dragon
            bool m_may_cast_petrify          = false; // Medusa, Medusa Queen, Basilisk, Greater Basilisk
            bool m_may_cast_blind            = false; // Unicorn, War Unicorn
            bool m_may_cast_lightning_strike = false; // Thunderbird
            bool m_may_cast_death_blow       = false; // Dread Knight
            bool m_may_cast_death_stare      = false; // Mighty Gorgon
            bool m_may_cast_accurate_shot    = false; // Sea Dog
            bool m_may_cast_acid_breath      = false; // Rust Dragon; Effect = additional damage of 25 points per attacking unit.
            bool m_may_cast_hypnotize        = false; // Fangarm; Effect = like the spell but occurs according to formula

            // casts when attacked
            bool m_casts_fire_shield = false; // Efreet Sultan

            // some chance of cast upon first death
            bool m_may_cast_rebirth = false; // Pheonix

            // can cast spell in battle - player's choice
            bool m_can_cast_ressurection          = false; // Archangel
            bool m_can_cast_advanced_fortune      = false; // Leprechaun
            bool m_can_cast_advanced_mirth        = false; // Satyr
            bool m_is_spellcaster                 = false; // Master Genie, Enchanter, Faerie Dragon
            bool m_can_cast_bloodlust             = false; // Ogre Mage
            bool m_can_cast_protection_from_air   = false; // Storm Elemental
            bool m_can_cast_protection_from_water = false; // Ice Elemental
            bool m_can_cast_protection_from_fire  = false; // Energy Elemental
            bool m_can_cast_protection_from_earth = false; // Magma Elemental
            bool m_can_cast_summon_demons         = false; // Pit Lord

            // resistances
            bool    m_has_magic_resist = false;        // Dwarf, Battle Dwarf
            uint8_t m_has_magic_resist_by_percent = 0; // Dwarf, Battle Dwarf

            bool m_has_magic_resist_aura = false; // Battle Dwarf
            bool m_has_magic_mirror      = false; // Faerie Dragon

            // damage reduciton
            bool    m_reduce_magic_damage = false;        // Stone, Iron, Steel, Gold & Diamond Golem
            uint8_t m_reduce_magic_damage_by_percent = 0; // Stone, Iron, Steel, Gold & Diamond Golem

            // immunities
            bool m_is_immune_to_jousting         = false; // Pikeman, Halberdier
            bool m_is_immune_to_fear             = false; // Azure Dragon
            bool m_is_immune_to_blind            = false; // Troglodyte
            bool m_is_immune_to_petrify          = false; // Infernal Troglodyte
            bool m_is_immune_to_magic_arrow      = false; // Efreet, Efreet Sultan, Fire & Energy Elemental
            bool m_is_immune_to_ice_bolt         = false; // Water & Ice Elemental
            bool m_is_immune_to_frost_ring       = false; // Water & Ice Elemental
            bool m_is_immune_to_lightning_bolt   = false; // Earth & Magma Elemental
            bool m_is_immune_to_chain_lightning  = false; // Earth & Magma Elemental
            bool m_is_immune_to_meteor_shower    = false; // Air & Storm Elemental
            bool m_is_immune_to_armageddon       = false; // Earth & Magma Elemental
            bool m_is_immune_to_fire_spells      = false; // Efreet, Efreet Sultan, Fire & Energy Elemental
            bool m_is_immune_to_mind_spells      = false; // Giant, Titan
            bool m_is_immune_to_spells_level_1_3 = false; // Green Dragon, Red Dragon
            bool m_is_immune_to_spells_level_1_4 = false; // Gold Dragon
            bool m_is_immune_to_all_spells       = false; // Black Dragon

            // vulnerabilities
            bool m_is_vulnerable_to_ice_bolt        = false; // Fire & Energy Elemental
            bool m_is_vulnerable_to_frost_ring      = false; // Fire & Energy Elemental
            bool m_is_vulnerable_to_lightning_bolt  = false; // Air & Storm Elemental
            bool m_is_vulnerable_to_chain_lightning = false; // Air & Storm Elemental
            bool m_is_vulnerable_to_meteor_shower   = false; // Earth & Magma Elemental
            bool m_is_vulnerable_to_fire_ball       = false; // Water & Ice Elemental
            bool m_is_vulnerable_to_inferno         = false; // Water & Ice Elemental
            bool m_is_vulnerable_to_armageddon      = false; // Air & Storm Elemental, Water & Ice Elemental

            // morale modifiers
            bool m_minimum_morale_1 = false; // Minotaur, Minotaur King
            bool m_minimum_luck_1   = false; // Halfling

            // whole army morale and luck modifiers
            bool m_increases_alias_morale_by_1 = false; // Angel, Archangel
            bool m_decreases_enemy_morale_by_1 = false; // Bone Dragon, Ghost Dragon
            bool m_decreases_enemy_luck_by_1   = false; // Devil
            bool m_decreases_enemy_luck_by_2   = false; // Arch Devil
            bool m_doubles_luck_chance         = false; // Leprechaun

            // mana points modifiers
            bool m_magic_channel = false; // Familiar; Effect = 20% of mana spent from enemy hero is added to hero's mana when familiars are present.
            bool m_magic_damper  = false; // Pegasus, Silver Pegasus; Effect = enemy hero's spells during combat cost 2 mana points more. Effects continues after Pegasi perish.
            bool m_mana_economy  = false; // Mage, Arch Mage; Effect = hero's spells during combat cost 2 mana points less.

            // effects on adventure map
            bool m_has_spying         = false; // Rogue
            bool m_is_sandwalker      = false; // Nomad
            bool m_generates_crystals = false; // Crystal Dragon

            uint8_t m_number_of_casts = 0; // only for Archangel, Leprechaun, Satyr, Master Genie, Enchanter, Faerie Dragon, Ogre Mage
            uint8_t m_spell_power     = 0; // only for Leprechaun, Satyr, Master Genie, Enchanter, Ogre Mage

            // Create a map of all special abilities, refering to the fields in the struct accordingly.
            std::map< std::string, std::vector<bool*> > create_map_of_all_abilities();

            // Fill the special abilities struct according to the passed special abilities string.
            void fill_special_abilities();

            // Sets the special abilities for each creature by calling fill_special_abilities() and then sets the number of casts and spell power.
            void set_special_abilities();

            // Fill the string in the field
            special_abilities(std::string abilities) : m_abilities(abilities) {};
        }special_abilities;

    public:
        // Straight-forward logical limits that need to be set when constructing.
        void logical_limitations();

        std::string get_name() const { return unit_info.m_name; }

        Faction get_faction() const { return unit_info.m_faction; }
        std::string get_faction_as_string() const;

        Terrain get_native_terrain() const {return unit_info.m_native_terrain; }

        uint8_t get_level() const { return unit_info.m_level; }

        Upgrade_level get_upgrade() const { return unit_info.m_upgrade; }

        uint8_t get_growth() const { return unit_info.m_growth; }

        bool get_needs_2_tiles_in_battle() const { return unit_info.m_needs_2_tiles_in_battle; }

        uint8_t get_att() const { return battle_stats.m_att; }

        uint8_t get_def() const { return battle_stats.m_def; }

        uint8_t get_shots() const { return battle_stats.m_shots; }

        uint8_t get_min_dmg() const { return battle_stats.m_min_dmg; }

        uint8_t get_max_dmg() const { return battle_stats.m_max_dmg; }

        uint16_t get_hp() const { return battle_stats.m_hp; }

        uint8_t get_speed() const { return battle_stats.m_speed; }

        Morale get_morale() const { return battle_stats.m_morale; }

        Luck get_luck() const { return battle_stats.m_luck; }

        uint16_t get_fight_value() const { return battle_stats.m_fight_value; }

        uint32_t get_ai_value() const { return battle_stats.m_ai_value; }

        uint16_t get_gold() const { return cost.m_gold; }

        uint16_t get_mercury() const { return cost.m_mercury; }

        uint16_t get_sulfur() const { return cost.m_sulfur; }

        uint16_t get_crystals() const { return cost.m_crystals; }

        uint16_t get_gems() const { return cost.m_gems; }

        bool get_is_undead() const    { return special_abilities.m_is_undead;    }
        bool get_is_bloodless() const { return special_abilities.m_is_bloodless; }

        bool get_is_flying() const { return special_abilities.m_is_flying; }
        bool get_is_ranged() const { return special_abilities.m_is_ranged; }

        bool get_no_melee_penalty() const    { return special_abilities.m_no_melee_penalty;    }
        bool get_no_obstacle_penalty() const { return special_abilities.m_no_obstacle_penalty; }
        bool get_no_range_penalty() const    { return special_abilities.m_no_range_penalty;    }

        bool get_strike_and_return() const      { return special_abilities.m_strike_and_return;      }
        bool get_can_attack_siege_walls() const { return special_abilities.m_can_attack_siege_walls; }

        bool get_has_ferocity() const                { return special_abilities.m_has_ferocity;                }
        bool get_has_double_attack() const           { return special_abilities.m_has_double_attack;           }
        bool get_has_jousting() const                { return special_abilities.m_has_jousting;                }
        bool get_has_revenge() const                 { return special_abilities.m_has_revenge;                 }
        bool get_has_3_headed_attack() const         { return special_abilities.m_has_3_headed_attack;         }
        bool get_has_fireball_attack() const         { return special_abilities.m_has_fireball_attack;         }
        bool get_has_cloud_attack() const            { return special_abilities.m_has_cloud_attack;            }
        bool get_has_attack_adjacent_enemies() const { return special_abilities.m_has_attack_adjacent_enemies; }
        bool get_has_attack_adjacent_hexes() const   { return special_abilities.m_has_attack_adjacent_hexes;   }
        bool get_has_breath_attack() const           { return special_abilities.m_has_breath_attack;           }
        bool get_hates_efreeti() const               { return special_abilities.m_hates_efreeti;               }
        bool get_hates_genies() const                { return special_abilities.m_hates_genies;                }
        bool get_hates_devils() const                { return special_abilities.m_hates_devils;                }
        bool get_hates_angels() const                { return special_abilities.m_hates_angels;                }
        bool get_hates_black_dragons() const         { return special_abilities.m_hates_black_dragons;         }
        bool get_hates_titans() const                { return special_abilities.m_hates_titans;                }

        bool    get_ignore_enemy_defense() const            { return special_abilities.m_ignore_enemy_defense;            }
        uint8_t get_ignore_enemy_defense_by_percent() const { return special_abilities.m_ignore_enemy_defense_by_percent; }

        bool    get_ignore_enemy_attack() const             { return special_abilities.m_ignore_enemy_attack;             }
        uint8_t get_ignore_enemy_attack_by_percent() const  { return special_abilities.m_ignore_enemy_attack_by_percent;  }

        bool get_has_two_retaliations() const       { return special_abilities.m_has_two_retaliations;       }
        bool get_has_unlimited_retaliations() const { return special_abilities.m_has_unlimited_retaliations; }
        bool get_no_enemy_retaliation() const       { return special_abilities.m_no_enemy_retaliation;       }

        bool get_casts_regeneration() const { return special_abilities.m_casts_regeneration; }
        bool get_casts_mana_drain() const   { return special_abilities.m_casts_mana_drain;   }

        bool get_minimum_morale_1() const { return special_abilities.m_minimum_morale_1; }
        bool get_minimum_luck_1() const   { return special_abilities.m_minimum_luck_1;   }

        bool get_increases_alias_morale_by_1() const { return special_abilities.m_increases_alias_morale_by_1; }
        bool get_decreases_enemy_morale_by_1() const { return special_abilities.m_decreases_enemy_morale_by_1; }
        bool get_decreases_enemy_luck_by_1() const   { return special_abilities.m_decreases_enemy_luck_by_1;   }
        bool get_decreases_enemy_luck_by_2() const   { return special_abilities.m_decreases_enemy_luck_by_2;   }
        bool get_doubles_luck_chance() const         { return special_abilities.m_doubles_luck_chance;         }

        bool get_casts_binding() const                             { return special_abilities.m_casts_binding;                             }
        bool get_casts_life_drain() const                          { return special_abilities.m_casts_life_drain;                          }
        bool get_casts_dispell_on_buffs() const                    { return special_abilities.m_casts_dispell_on_buffs;                    }
        bool get_casts_weakness() const                            { return special_abilities.m_casts_weakness;                            }
        bool get_casts_advanced_weakness() const                   { return special_abilities.m_casts_advanced_weakness;                   }
        bool get_casts_disrupting_ray_on_weakened() const          { return special_abilities.m_casts_disrupting_ray_on_weakened;          }
        bool get_casts_advanced_disrupting_ray_on_weakened() const { return special_abilities.m_casts_advanced_disrupting_ray_on_weakened; }

        bool get_may_cast_disease() const          { return special_abilities.m_may_cast_disease;          }
        bool get_may_cast_curse() const            { return special_abilities.m_may_cast_curse;            }
        bool get_may_cast_aging() const            { return special_abilities.m_may_cast_aging;            }
        bool get_may_cast_poison() const           { return special_abilities.m_may_cast_poison;           }
        bool get_may_cast_lightning_strike() const { return special_abilities.m_may_cast_lightning_strike; }
        bool get_may_cast_paralyzing_venom() const { return special_abilities.m_may_cast_paralyzing_venom; }
        bool get_may_cast_fear() const             { return special_abilities.m_may_cast_fear;             }
        bool get_may_cast_petrify() const          { return special_abilities.m_may_cast_petrify;          }
        bool get_may_cast_blind() const            { return special_abilities.m_may_cast_blind;            }
        bool get_may_cast_death_blow() const       { return special_abilities.m_may_cast_death_blow;       }
        bool get_may_cast_death_stare() const      { return special_abilities.m_may_cast_death_stare;      }
        bool get_may_cast_accurate_shot() const    { return special_abilities.m_may_cast_accurate_shot;    }
        bool get_may_cast_acid_breath() const      { return special_abilities.m_may_cast_acid_breath;      }
        bool get_may_cast_hypnotize() const        { return special_abilities.m_may_cast_hypnotize;        }

        bool get_casts_fire_shield() const { return special_abilities.m_casts_fire_shield; }

        bool get_may_cast_rebirth() const { return special_abilities.m_may_cast_rebirth; }

        bool get_can_cast_ressurection() const          { return special_abilities.m_can_cast_ressurection;          }
        bool get_can_cast_advanced_fortune() const      { return special_abilities.m_can_cast_advanced_fortune;      }
        bool get_can_cast_advanced_mirth() const        { return special_abilities.m_can_cast_advanced_mirth;        }
        bool get_is_spellcaster() const                 { return special_abilities.m_is_spellcaster;                 }
        bool get_can_cast_bloodlust() const             { return special_abilities.m_can_cast_bloodlust;             }
        bool get_can_cast_protection_from_air() const   { return special_abilities.m_can_cast_protection_from_air;   }
        bool get_can_cast_protection_from_water() const { return special_abilities.m_can_cast_protection_from_water; }
        bool get_can_cast_protection_from_fire() const  { return special_abilities.m_can_cast_protection_from_fire;  }
        bool get_can_cast_protection_from_earth() const { return special_abilities.m_can_cast_protection_from_earth; }
        bool get_can_cast_summon_demons() const         { return special_abilities.m_can_cast_summon_demons;         }

        bool    get_has_magic_resist() const            { return special_abilities.m_has_magic_resist;            }
        uint8_t get_has_magic_resist_by_percent() const { return special_abilities.m_has_magic_resist_by_percent; }

        bool get_has_magic_resist_aura() const { return special_abilities.m_has_magic_resist_aura; }
        bool get_has_magic_mirror() const      { return special_abilities.m_has_magic_mirror;      }

        bool    get_reduce_magic_damage() const            { return special_abilities.m_reduce_magic_damage;            }
        uint8_t get_reduce_magic_damage_by_percent() const { return special_abilities.m_reduce_magic_damage_by_percent; }

        bool get_is_immune_to_jousting() const         { return special_abilities.m_is_immune_to_jousting;         }
        bool get_is_immune_to_fear() const             { return special_abilities.m_is_immune_to_fear;             }
        bool get_is_immune_to_blind() const            { return special_abilities.m_is_immune_to_blind;            }
        bool get_is_immune_to_petrify() const          { return special_abilities.m_is_immune_to_petrify;          }
        bool get_is_immune_to_magic_arrow() const      { return special_abilities.m_is_immune_to_magic_arrow;      }
        bool get_is_immune_to_ice_bolt() const         { return special_abilities.m_is_immune_to_ice_bolt;         }
        bool get_is_immune_to_frost_ring() const       { return special_abilities.m_is_immune_to_frost_ring;       }
        bool get_is_immune_to_lightning_bolt() const   { return special_abilities.m_is_immune_to_lightning_bolt;   }
        bool get_is_immune_to_chain_lightning() const  { return special_abilities.m_is_immune_to_chain_lightning;  }
        bool get_is_immune_to_meteor_shower() const    { return special_abilities.m_is_immune_to_meteor_shower;    }
        bool get_is_immune_to_armageddon() const       { return special_abilities.m_is_immune_to_armageddon;       }
        bool get_is_immune_to_fire_spells() const      { return special_abilities.m_is_immune_to_fire_spells;      }
        bool get_is_immune_to_mind_spells() const      { return special_abilities.m_is_immune_to_mind_spells;      }
        bool get_is_immune_to_spells_level_1_3() const { return special_abilities.m_is_immune_to_spells_level_1_3; }
        bool get_is_immune_to_spells_level_1_4() const { return special_abilities.m_is_immune_to_spells_level_1_4; }
        bool get_is_immune_to_all_spells() const       { return special_abilities.m_is_immune_to_all_spells;       }

        bool get_is_vulnerable_to_ice_bolt() const        { return special_abilities.m_is_vulnerable_to_ice_bolt;        }
        bool get_is_vulnerable_to_frost_ring() const      { return special_abilities.m_is_vulnerable_to_frost_ring;      }
        bool get_is_vulnerable_to_lightning_bolt() const  { return special_abilities.m_is_vulnerable_to_lightning_bolt;  }
        bool get_is_vulnerable_to_chain_lightning() const { return special_abilities.m_is_vulnerable_to_chain_lightning; }
        bool get_is_vulnerable_to_meteor_shower() const   { return special_abilities.m_is_vulnerable_to_meteor_shower;   }
        bool get_is_vulnerable_to_fire_ball() const       { return special_abilities.m_is_vulnerable_to_fire_ball;       }
        bool get_is_vulnerable_to_inferno() const         { return special_abilities.m_is_vulnerable_to_inferno;         }
        bool get_is_vulnerable_to_armageddon() const      { return special_abilities.m_is_vulnerable_to_armageddon;      }

        bool get_magic_channel() const { return special_abilities.m_magic_channel; }
        bool get_magic_damper() const  { return special_abilities.m_magic_damper;  }
        bool get_mana_economy() const  { return special_abilities.m_mana_economy;  }

        bool get_has_spying() const         { return special_abilities.m_has_spying;         }
        bool get_is_sandwalker() const      { return special_abilities.m_is_sandwalker;      }
        bool get_generates_crystals() const { return special_abilities.m_generates_crystals; }

        uint8_t get_number_of_casts() const { return special_abilities.m_number_of_casts; }
        uint8_t get_spell_power() const     { return special_abilities.m_spell_power;     }

        // Returns a string with the cost of a creature.
        std::string get_cost() const;

        // Returns a string with the special abilities of a creature.
        std::string get_special_abilities() const { return special_abilities.m_abilities; }

        // Prints the full information of a creature.
        void print_full_info() const;
};
#endif