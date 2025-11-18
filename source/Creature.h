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

enum CreatureType : uint8_t
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

    enum Abilities : uint8_t // Special abilities that might cast a spell per attack have a fixed chance.
    {
        // living type
        IS_UNDEAD = 1, // all Necropolis units
        IS_BLOODLESS,  // Gagroyles, Golems, Elementals

        // attack type
        IS_FLYING,
        IS_RANGED,

        // attack penalty
        NO_MELEE_PENALTY,    // Mage, Arch Mage, Titan
        NO_OBSTACLE_PENALTY, // Mage, Arch Mage, Zealot
        NO_RANGE_PENALTY,    // Sharpshooter

        // attack style
        STRIKE_AND_RETURN,      // Harpy, Harpy Hag
        CAN_ATTACK_SIEGE_WALLS, // Cyclops, Cyclops King

        // attack bonus
        HAS_FEROCITY,                // Ayssid; Effect : if a unit from the attacked stack dies, a seconda attack follows
        HAS_DOUBLE_ATTACK,           // Marksman, Crusader, Grand Elf
        HAS_JOUSTING,                // Cavalier, Champion
        HAS_REVENGE,                 // Haspid; Effect : attacks deal a bit more damage after stack suffers damage
        HAS_3_HEADED_ATTACK,         // Cerberus
        HAS_FIREBALL_ATTACK,         // Magog
        HAS_CLOUD_ATTACK,            // Lich, Power Lich
        HAS_ATTACK_ADJACENT_ENEMIES, // Hydra, Chaos Hydra
        HAS_ATTACK_ADJACENT_HEXES,   // Magic Elemental, Psychic Elemental
        HAS_BREATH_ATTACK,           // Firebird, Pheonix, Dragons: Green + Gold + Red + Black + Faerie + Rust + Azure
        HATES_EFREETI,               // Genie, Master Genie
        HATES_GENIES,                // Efreet, Efreet Sultan
        HATES_DEVILS,                // Angel, Archangel
        HATES_ANGELS,                // Devil, Arch Devil
        HATES_BLACK_DRAGONS,         // Titan
        HATES_TITANS,                // Black Dragon
        IGNORE_ENEMY_DEFENSE,        // Behemoth, Ancient Behemoth

        // defense bonus
        IGNORE_ENEMY_ATTACK, // Nix, Nix Warrior

        // retaliation
        HAS_TWO_RETALIATIONS,       // Griffin
        HAS_UNLIMITED_RETALIATIONS, // Royal Griffin
        HAS_NO_ENEMY_RETALIATIONS,  // Naga, Naga Queen, Devil, Arch Devil

        // casts per turn
        CASTS_REGENERATION, // Wight, Wraith
        CASTS_MANA_DRAIN,   // Wraith; Effect = enemy hero's spell points are reduced by 2.

        // casts after attack
        CASTS_BINDING,                            // Dendroid Guard, Dendroid Soldier; Effect = snare until Dendroids die or move.
        CASTS_LIFE_DRAIN,                         // Vampire Lord
        CASTS_DISPELL_ON_BUFFS,                   // Serpent Fly, Dragon Fly
        CASTS_WEAKNESS,                           // Sea Witch
        CASTS_ADVANCED_WEAKNESS,                  // Dragon Fly, Sorceress
        CASTS_DISRUPTING_RAY_ON_WEAKEND,          // Sea Witch
        CASTS_ADVANCED_DISRUPTING_RAY_ON_WEAKEND, // Sorceress

        // some chance of cast per attack
        MAY_CAST_DISEASE,          // Zombie
        MAY_CAST_CURSE,            // Black Knigt, Dread Knight
        MAY_CAST_AGING,            // Ghost Dragon
        MAY_CAST_POISON,           // Wyvern Monarch, Sea Serpent, Haspid
        MAY_CAST_PARALYZING_VENOM, // Scorpicore
        MAY_CAST_FEAR,             // Azure Dragon
        MAY_CAST_PETRIFY,          // Medusa, Medusa Queen, Basilisk, Greater Basilisk
        MAY_CAST_BLIND,            // Unicorn, War Unicorn
        MAY_CAST_LIGHTNING_STRIKE, // Thunderbird
        MAY_CAST_DEATH_BLOW,       // Dread Knight
        MAY_CAST_DEATH_STARE,      // Mighty Gorgon
        MAY_CAST_ACCURATE_SHOT,    // Sea Dog
        MAY_CAST_ACID_BREATH,      // Rust Dragon; Effect = additional damage of 25 points per attacking unit.
        MAY_CAST_HYPNOTIZE,        // Fangarm; Effect = like the spell but occurs according to formula

        // casts when attacked
        CASTS_FIRE_SHIELD, // Efreet Sultan

        // some chance of cast upon first death
        MAY_CAST_REBIRTH, // Pheonix

        // can cast spell in battle - player's choice
        CAN_CAST_RESSURECTION,          // Archangel
        CAN_CAST_ADVANCED_FORTUNE,      // Leprechaun
        CAN_CAST_ADVANCED_MIRTH,        // Satyr
        IS_SPELLCASTER,                 // Master Genie, Enchanter, Faerie Dragon
        CAN_CAST_BLOODLUST,             // Ogre Mage
        CAN_CAST_PROTECTION_FROM_AIR,   // Storm Elemental
        CAN_CAST_PROTECTION_FROM_WATER, // Ice Elemental
        CAN_CAST_PROTECTION_FROM_FIRE,  // Energy Elemental
        CAN_CAST_PROTECTION_FROM_EARTH, // Magma Elemental
        CAN_CAST_SUMMON_DEMONS,         // Pit Lord

        // resistances
        HAS_MAGIC_RESIST,      // Dwarf, Battle Dwarf
        HAS_MAGIC_RESIST_AURA, // Battle Dwarf
        HAS_MAGIC_MIRROR,      // Faerie Dragon

        // damage reduciton
        REDUCE_MAGIC_DAMAGE, // Stone, Iron, Steel, Gold & Diamond Golem

        // immunities
        IS_IMMUNE_TO_JOUSTING,         // Pikeman, Halberdier
        IS_IMMUNE_TO_FEAR,             // Azure Dragon
        IS_IMMUNE_TO_BLIND,            // Troglodyte
        IS_IMMUNE_TO_PETRIFY,          // Infernal Troglodyte
        IS_IMMUNE_TO_MAGIC_ARROW,      // Efreet, Efreet Sultan, Fire & Energy Elemental
        IS_IMMUNE_TO_ICE_BOLT,         // Water & Ice Elemental
        IS_IMMUNE_TO_FROST_RING,       // Water & Ice Elemental
        IS_IMMUNE_TO_LIGHTNING_BOLT,   // Earth & Magma Elemental
        IS_IMMUNE_TO_CHAIN_LIGHTNING,  // Earth & Magma Elemental
        IS_IMMUNE_TO_METEOR_SHOWER,    // Air & Storm Elemental
        IS_IMMUNE_TO_ARMAGEDDON,       // Earth & Magma Elemental
        IS_IMMUNE_TO_FIRE_SPELLS,      // Efreet, Efreet Sultan, Fire & Energy Elemental
        IS_IMMUNE_TO_MIND_SPELLS,      // Giant, Titan
        IS_IMMUNE_TO_SPELLS_LEVEL_1_3, // Green Dragon, Red Dragon
        IS_IMMUNE_TO_SPELLS_LEVEL_1_4, // Gold Dragon
        IS_IMMUNE_TO_ALL_SPELLS,       // Black Dragon

        // vulnerabilities
        IS_VULNERABLE_TO_ICE_BOLT,        // Fire & Energy Elemental
        IS_VULNERABLE_TO_FROST_RING,      // Fire & Energy Elemental
        IS_VULNERABLE_TO_LIGHTNING_BOLT,  // Air & Storm Elemental
        IS_VULNERABLE_TO_CHAIN_LIGHTNING, // Air & Storm Elemental
        IS_VULNERABLE_TO_METEOR_SHOWER,   // Earth & Magma Elemental
        IS_VULNERABLE_TO_FIRE_BALL,       // Water & Ice Elemental
        IS_VULNERABLE_TO_INFERNO,         // Water & Ice Elemental
        IS_VULNERABLE_TO_ARMAGEDDON,      // Air & Storm Elemental, Water & Ice Elemental

        // morale modifiers
        MINIMUM_MORALE_1, // Minotaur, Minotaur King
        MINIMUM_LUCK_1,   // Halfling

        // whole army morale and luck modifiers
        INCREASES_ALIAS_MORALE_BY_1, // Angel, Archangel
        DECREASES_ENEMY_MORALE_BY_1, // Bone Dragon, Ghost Dragon
        DECREASES_ENEMY_LUCK_BY_1,   // Devil
        DECREASES_ENEMY_LUCK_BY_2,   // Arch Devil
        DOUBLES_LUCK_CHANCE,         // Leprechaun

        // mana points modifiers
        MAGIC_CHANNEL, // Familiar; Effect = 20% of mana spent from enemy hero is added to hero's mana when familiars are present.
        MAGIC_DAMPER,  // Pegasus, Silver Pegasus; Effect = enemy hero's spells during combat cost 2 mana points more. Effects continues after Pegasi perish.
        MANA_ECONOMY,  // Mage, Arch Mage; Effect = hero's spells during combat cost 2 mana points less.

        // effects on adventure map
        HAS_SPYING,        // Rogue
        IS_SANDWALKER,     // Nomad
        GENERATES_CRYSTALS // Crystal Dragon
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
        Creature( const CreatureType type, const Faction faction, const uint8_t level, const Upgrade_level upgrade, const uint8_t growth, const bool needs_2_tiles_in_battle,
                  const uint8_t att, const uint8_t def, const uint8_t shots, const uint8_t min_dmg, const uint8_t max_dmg, const uint16_t hp, const uint8_t speed, const Morale morale, const Luck luck, const uint16_t fight_value, const uint32_t ai_value,
                  const Resources& resources,
                  const std::string& abilities );

        // Disallow the use of copy constructor by reference.
        Creature( const Creature& creature ) = delete;

        // Disallow the use of move constructor.
        Creature( Creature&& creature ) = delete;

        // Destructor
        ~Creature() = default;

    public:
        // It would be quicker to compare creatures by their faction, level and upgrade, rather than by their names (string).
        bool operator==(const Creature& other) const { return get_type() == other.get_type(); }
        bool operator!=(const Creature& other) const { return get_type() != other.get_type(); }

    private:
        // Straight-forward logical limits that need to be set when constructing.
        void logical_limitations();

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
            CreatureType m_type;
            std::string m_name;
            Faction m_faction;
            Terrain m_native_terrain;
            uint8_t m_level;
            Upgrade_level m_upgrade;
            uint8_t m_growth;
            bool m_needs_2_tiles_in_battle;

            // Set the name of the creature when constructing.
            void set_name_from_enum();

            // Sets the native terrain of a creature, according to its faction.
            void set_native_terrain();

            // Constructs a private structure containing data used for overview
            unit_info( const CreatureType type, const Faction faction, const uint8_t level, const Upgrade_level upgrade, const uint8_t growth, const bool needs_2_tiles_in_battle ) :
                       m_type(type), m_faction(faction), m_level(level), m_upgrade(upgrade), m_growth(growth), m_needs_2_tiles_in_battle(needs_2_tiles_in_battle)
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
            uint32_t m_abilities[4] = {0};
            static constexpr uint8_t bits = 8*sizeof(m_abilities[0]);

            std::string m_abilities_str = "";

            // attack bonus
            uint8_t m_ignore_enemy_defense_by_percent = 0; // Behemoth, Ancient Behemoth

            // defense bonus
            uint8_t m_ignore_enemy_attack_by_percent = 0; // Nix, Nix Warrior

            // resistances
            uint8_t m_has_magic_resist_by_percent = 0; // Dwarf, Battle Dwarf

            // damage reduciton
            uint8_t m_reduce_magic_damage_by_percent = 0; // Stone, Iron, Steel, Gold & Diamond Golem

            // effects on adventure map
            uint8_t m_number_of_casts = 0; // only for Archangel, Leprechaun, Satyr, Master Genie, Enchanter, Faerie Dragon, Ogre Mage
            uint8_t m_spell_power     = 0; // only for Leprechaun, Satyr, Master Genie, Enchanter, Ogre Mage

            inline bool get_ability_bit(Special_abilities::Abilities bit_pos) const { return m_abilities[bit_pos / bits] &   (1 << (bit_pos % bits)); }
            inline void set_ability_bit(Special_abilities::Abilities bit_pos)       {        m_abilities[bit_pos / bits] |=  (1 << (bit_pos % bits)); }
            inline void turn_off_ability_bit(Special_abilities::Abilities bit_pos)  {        m_abilities[bit_pos / bits] &= ~(1 << bit_pos);          }

            // Create a map of all special abilities, refering to the fields in the struct accordingly.
            const std::map< std::string, std::vector<Special_abilities::Abilities> >& create_map_of_all_abilities();

            // Fill the special abilities struct according to the passed special abilities string.
            void set_special_abilities();

            // Fill the string in the field
            special_abilities(const std::string& abilities) : m_abilities_str(abilities) {};
        }special_abilities;

    public:
        CreatureType get_type() const { return unit_info.m_type; }

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

        bool get_is_undead() const    { return special_abilities.get_ability_bit(Special_abilities::Abilities::IS_UNDEAD);    }
        bool get_is_bloodless() const { return special_abilities.get_ability_bit(Special_abilities::Abilities::IS_BLOODLESS); }

        bool get_is_flying() const { return special_abilities.get_ability_bit(Special_abilities::Abilities::IS_FLYING); }
        bool get_is_ranged() const { return special_abilities.get_ability_bit(Special_abilities::Abilities::IS_RANGED); }

        bool get_no_melee_penalty() const    { return special_abilities.get_ability_bit(Special_abilities::Abilities::NO_MELEE_PENALTY);    }
        bool get_no_obstacle_penalty() const { return special_abilities.get_ability_bit(Special_abilities::Abilities::NO_OBSTACLE_PENALTY); }
        bool get_no_range_penalty() const    { return special_abilities.get_ability_bit(Special_abilities::Abilities::NO_RANGE_PENALTY);    }

        bool get_strike_and_return() const      { return special_abilities.get_ability_bit(Special_abilities::Abilities::STRIKE_AND_RETURN);      }
        bool get_can_attack_siege_walls() const { return special_abilities.get_ability_bit(Special_abilities::Abilities::CAN_ATTACK_SIEGE_WALLS); }

        bool get_has_ferocity() const                { return special_abilities.get_ability_bit(Special_abilities::Abilities::HAS_FEROCITY);                }
        bool get_has_double_attack() const           { return special_abilities.get_ability_bit(Special_abilities::Abilities::HAS_DOUBLE_ATTACK);           }
        bool get_has_jousting() const                { return special_abilities.get_ability_bit(Special_abilities::Abilities::HAS_JOUSTING);                }
        bool get_has_revenge() const                 { return special_abilities.get_ability_bit(Special_abilities::Abilities::HAS_REVENGE);                 }
        bool get_has_3_headed_attack() const         { return special_abilities.get_ability_bit(Special_abilities::Abilities::HAS_3_HEADED_ATTACK);         }
        bool get_has_fireball_attack() const         { return special_abilities.get_ability_bit(Special_abilities::Abilities::HAS_FIREBALL_ATTACK);         }
        bool get_has_cloud_attack() const            { return special_abilities.get_ability_bit(Special_abilities::Abilities::HAS_CLOUD_ATTACK);            }
        bool get_has_attack_adjacent_enemies() const { return special_abilities.get_ability_bit(Special_abilities::Abilities::HAS_ATTACK_ADJACENT_ENEMIES); }
        bool get_has_attack_adjacent_hexes() const   { return special_abilities.get_ability_bit(Special_abilities::Abilities::HAS_ATTACK_ADJACENT_HEXES);   }
        bool get_has_breath_attack() const           { return special_abilities.get_ability_bit(Special_abilities::Abilities::HAS_BREATH_ATTACK);           }
        bool get_hates_efreeti() const               { return special_abilities.get_ability_bit(Special_abilities::Abilities::HATES_EFREETI);               }
        bool get_hates_genies() const                { return special_abilities.get_ability_bit(Special_abilities::Abilities::HATES_GENIES);                }
        bool get_hates_devils() const                { return special_abilities.get_ability_bit(Special_abilities::Abilities::HATES_DEVILS);                }
        bool get_hates_angels() const                { return special_abilities.get_ability_bit(Special_abilities::Abilities::HATES_ANGELS);                }
        bool get_hates_black_dragons() const         { return special_abilities.get_ability_bit(Special_abilities::Abilities::HATES_BLACK_DRAGONS);         }
        bool get_hates_titans() const                { return special_abilities.get_ability_bit(Special_abilities::Abilities::HATES_TITANS);                }

        bool    get_ignore_enemy_defense() const            { return special_abilities.get_ability_bit(Special_abilities::Abilities::IGNORE_ENEMY_DEFENSE); }
        uint8_t get_ignore_enemy_defense_by_percent() const { return special_abilities.m_ignore_enemy_defense_by_percent; }

        bool    get_ignore_enemy_attack() const             { return special_abilities.get_ability_bit(Special_abilities::Abilities::IGNORE_ENEMY_ATTACK); }
        uint8_t get_ignore_enemy_attack_by_percent() const  { return special_abilities.m_ignore_enemy_attack_by_percent;  }

        bool get_has_two_retaliations() const       { return special_abilities.get_ability_bit(Special_abilities::Abilities::HAS_TWO_RETALIATIONS);       }
        bool get_has_unlimited_retaliations() const { return special_abilities.get_ability_bit(Special_abilities::Abilities::HAS_UNLIMITED_RETALIATIONS); }
        bool get_has_no_enemy_retaliation() const   { return special_abilities.get_ability_bit(Special_abilities::Abilities::HAS_NO_ENEMY_RETALIATIONS);  }

        bool get_casts_regeneration() const { return special_abilities.get_ability_bit(Special_abilities::Abilities::CASTS_REGENERATION); }
        bool get_casts_mana_drain() const   { return special_abilities.get_ability_bit(Special_abilities::Abilities::CASTS_MANA_DRAIN);   }

        bool get_casts_binding() const                             { return special_abilities.get_ability_bit(Special_abilities::Abilities::CASTS_BINDING);                            }
        bool get_casts_life_drain() const                          { return special_abilities.get_ability_bit(Special_abilities::Abilities::CASTS_LIFE_DRAIN);                         }
        bool get_casts_dispell_on_buffs() const                    { return special_abilities.get_ability_bit(Special_abilities::Abilities::CASTS_DISPELL_ON_BUFFS);                   }
        bool get_casts_weakness() const                            { return special_abilities.get_ability_bit(Special_abilities::Abilities::CASTS_WEAKNESS);                           }
        bool get_casts_advanced_weakness() const                   { return special_abilities.get_ability_bit(Special_abilities::Abilities::CASTS_ADVANCED_WEAKNESS);                  }
        bool get_casts_disrupting_ray_on_weakened() const          { return special_abilities.get_ability_bit(Special_abilities::Abilities::CASTS_DISRUPTING_RAY_ON_WEAKEND);          }
        bool get_casts_advanced_disrupting_ray_on_weakened() const { return special_abilities.get_ability_bit(Special_abilities::Abilities::CASTS_ADVANCED_DISRUPTING_RAY_ON_WEAKEND); }

        bool get_may_cast_disease() const          { return special_abilities.get_ability_bit(Special_abilities::Abilities::MAY_CAST_DISEASE);          }
        bool get_may_cast_curse() const            { return special_abilities.get_ability_bit(Special_abilities::Abilities::MAY_CAST_CURSE);            }
        bool get_may_cast_aging() const            { return special_abilities.get_ability_bit(Special_abilities::Abilities::MAY_CAST_AGING);            }
        bool get_may_cast_poison() const           { return special_abilities.get_ability_bit(Special_abilities::Abilities::MAY_CAST_POISON);           }
        bool get_may_cast_lightning_strike() const { return special_abilities.get_ability_bit(Special_abilities::Abilities::MAY_CAST_LIGHTNING_STRIKE); }
        bool get_may_cast_paralyzing_venom() const { return special_abilities.get_ability_bit(Special_abilities::Abilities::MAY_CAST_PARALYZING_VENOM); }
        bool get_may_cast_fear() const             { return special_abilities.get_ability_bit(Special_abilities::Abilities::MAY_CAST_FEAR);             }
        bool get_may_cast_petrify() const          { return special_abilities.get_ability_bit(Special_abilities::Abilities::MAY_CAST_PETRIFY);          }
        bool get_may_cast_blind() const            { return special_abilities.get_ability_bit(Special_abilities::Abilities::MAY_CAST_BLIND);            }
        bool get_may_cast_death_blow() const       { return special_abilities.get_ability_bit(Special_abilities::Abilities::MAY_CAST_DEATH_BLOW);       }
        bool get_may_cast_death_stare() const      { return special_abilities.get_ability_bit(Special_abilities::Abilities::MAY_CAST_DEATH_STARE);      }
        bool get_may_cast_accurate_shot() const    { return special_abilities.get_ability_bit(Special_abilities::Abilities::MAY_CAST_ACCURATE_SHOT);    }
        bool get_may_cast_acid_breath() const      { return special_abilities.get_ability_bit(Special_abilities::Abilities::MAY_CAST_ACID_BREATH);      }
        bool get_may_cast_hypnotize() const        { return special_abilities.get_ability_bit(Special_abilities::Abilities::MAY_CAST_HYPNOTIZE);        }

        bool get_casts_fire_shield() const { return special_abilities.get_ability_bit(Special_abilities::Abilities::CASTS_FIRE_SHIELD); }

        bool get_may_cast_rebirth() const { return special_abilities.get_ability_bit(Special_abilities::Abilities::MAY_CAST_REBIRTH); }

        bool get_can_cast_ressurection() const          { return special_abilities.get_ability_bit(Special_abilities::Abilities::CAN_CAST_RESSURECTION);          }
        bool get_can_cast_advanced_fortune() const      { return special_abilities.get_ability_bit(Special_abilities::Abilities::CAN_CAST_ADVANCED_FORTUNE);      }
        bool get_can_cast_advanced_mirth() const        { return special_abilities.get_ability_bit(Special_abilities::Abilities::CAN_CAST_ADVANCED_MIRTH);        }
        bool get_is_spellcaster() const                 { return special_abilities.get_ability_bit(Special_abilities::Abilities::IS_SPELLCASTER);                 }
        bool get_can_cast_bloodlust() const             { return special_abilities.get_ability_bit(Special_abilities::Abilities::CAN_CAST_BLOODLUST);             }
        bool get_can_cast_protection_from_air() const   { return special_abilities.get_ability_bit(Special_abilities::Abilities::CAN_CAST_PROTECTION_FROM_AIR);   }
        bool get_can_cast_protection_from_water() const { return special_abilities.get_ability_bit(Special_abilities::Abilities::CAN_CAST_PROTECTION_FROM_WATER); }
        bool get_can_cast_protection_from_fire() const  { return special_abilities.get_ability_bit(Special_abilities::Abilities::CAN_CAST_PROTECTION_FROM_FIRE);  }
        bool get_can_cast_protection_from_earth() const { return special_abilities.get_ability_bit(Special_abilities::Abilities::CAN_CAST_PROTECTION_FROM_EARTH); }
        bool get_can_cast_summon_demons() const         { return special_abilities.get_ability_bit(Special_abilities::Abilities::CAN_CAST_SUMMON_DEMONS);         }

        bool    get_has_magic_resist() const            { return special_abilities.get_ability_bit(Special_abilities::Abilities::HAS_MAGIC_RESIST); }
        uint8_t get_has_magic_resist_by_percent() const { return special_abilities.m_has_magic_resist_by_percent; }

        bool get_has_magic_resist_aura() const { return special_abilities.get_ability_bit(Special_abilities::Abilities::HAS_MAGIC_RESIST_AURA); }
        bool get_has_magic_mirror() const      { return special_abilities.get_ability_bit(Special_abilities::Abilities::HAS_MAGIC_MIRROR);      }

        bool    get_reduce_magic_damage() const            { return special_abilities.get_ability_bit(Special_abilities::Abilities::REDUCE_MAGIC_DAMAGE); }
        uint8_t get_reduce_magic_damage_by_percent() const { return special_abilities.m_reduce_magic_damage_by_percent; }

        bool get_is_immune_to_jousting() const         { return special_abilities.get_ability_bit(Special_abilities::Abilities::IS_IMMUNE_TO_JOUSTING);         }
        bool get_is_immune_to_fear() const             { return special_abilities.get_ability_bit(Special_abilities::Abilities::IS_IMMUNE_TO_FEAR);             }
        bool get_is_immune_to_blind() const            { return special_abilities.get_ability_bit(Special_abilities::Abilities::IS_IMMUNE_TO_BLIND);            }
        bool get_is_immune_to_petrify() const          { return special_abilities.get_ability_bit(Special_abilities::Abilities::IS_IMMUNE_TO_PETRIFY);          }
        bool get_is_immune_to_magic_arrow() const      { return special_abilities.get_ability_bit(Special_abilities::Abilities::IS_IMMUNE_TO_MAGIC_ARROW);      }
        bool get_is_immune_to_ice_bolt() const         { return special_abilities.get_ability_bit(Special_abilities::Abilities::IS_IMMUNE_TO_ICE_BOLT);         }
        bool get_is_immune_to_frost_ring() const       { return special_abilities.get_ability_bit(Special_abilities::Abilities::IS_IMMUNE_TO_FROST_RING);       }
        bool get_is_immune_to_lightning_bolt() const   { return special_abilities.get_ability_bit(Special_abilities::Abilities::IS_IMMUNE_TO_LIGHTNING_BOLT);   }
        bool get_is_immune_to_chain_lightning() const  { return special_abilities.get_ability_bit(Special_abilities::Abilities::IS_IMMUNE_TO_CHAIN_LIGHTNING);  }
        bool get_is_immune_to_meteor_shower() const    { return special_abilities.get_ability_bit(Special_abilities::Abilities::IS_IMMUNE_TO_METEOR_SHOWER);    }
        bool get_is_immune_to_armageddon() const       { return special_abilities.get_ability_bit(Special_abilities::Abilities::IS_IMMUNE_TO_ARMAGEDDON);       }
        bool get_is_immune_to_fire_spells() const      { return special_abilities.get_ability_bit(Special_abilities::Abilities::IS_IMMUNE_TO_FIRE_SPELLS);      }
        bool get_is_immune_to_mind_spells() const      { return special_abilities.get_ability_bit(Special_abilities::Abilities::IS_IMMUNE_TO_MIND_SPELLS);      }
        bool get_is_immune_to_spells_level_1_3() const { return special_abilities.get_ability_bit(Special_abilities::Abilities::IS_IMMUNE_TO_SPELLS_LEVEL_1_3); }
        bool get_is_immune_to_spells_level_1_4() const { return special_abilities.get_ability_bit(Special_abilities::Abilities::IS_IMMUNE_TO_SPELLS_LEVEL_1_4); }
        bool get_is_immune_to_all_spells() const       { return special_abilities.get_ability_bit(Special_abilities::Abilities::IS_IMMUNE_TO_ALL_SPELLS);       }

        bool get_is_vulnerable_to_ice_bolt() const        { return special_abilities.get_ability_bit(Special_abilities::Abilities::IS_VULNERABLE_TO_ICE_BOLT);        }
        bool get_is_vulnerable_to_frost_ring() const      { return special_abilities.get_ability_bit(Special_abilities::Abilities::IS_VULNERABLE_TO_FROST_RING);      }
        bool get_is_vulnerable_to_lightning_bolt() const  { return special_abilities.get_ability_bit(Special_abilities::Abilities::IS_VULNERABLE_TO_LIGHTNING_BOLT);  }
        bool get_is_vulnerable_to_chain_lightning() const { return special_abilities.get_ability_bit(Special_abilities::Abilities::IS_VULNERABLE_TO_CHAIN_LIGHTNING); }
        bool get_is_vulnerable_to_meteor_shower() const   { return special_abilities.get_ability_bit(Special_abilities::Abilities::IS_VULNERABLE_TO_METEOR_SHOWER);   }
        bool get_is_vulnerable_to_fire_ball() const       { return special_abilities.get_ability_bit(Special_abilities::Abilities::IS_VULNERABLE_TO_FIRE_BALL);       }
        bool get_is_vulnerable_to_inferno() const         { return special_abilities.get_ability_bit(Special_abilities::Abilities::IS_VULNERABLE_TO_INFERNO);         }
        bool get_is_vulnerable_to_armageddon() const      { return special_abilities.get_ability_bit(Special_abilities::Abilities::IS_VULNERABLE_TO_ARMAGEDDON);      }

        bool get_minimum_morale_1() const { return special_abilities.get_ability_bit(Special_abilities::Abilities::MINIMUM_MORALE_1); }
        bool get_minimum_luck_1() const   { return special_abilities.get_ability_bit(Special_abilities::Abilities::MINIMUM_LUCK_1);   }

        bool get_increases_alias_morale_by_1() const { return special_abilities.get_ability_bit(Special_abilities::Abilities::INCREASES_ALIAS_MORALE_BY_1); }
        bool get_decreases_enemy_morale_by_1() const { return special_abilities.get_ability_bit(Special_abilities::Abilities::DECREASES_ENEMY_MORALE_BY_1); }
        bool get_decreases_enemy_luck_by_1() const   { return special_abilities.get_ability_bit(Special_abilities::Abilities::DECREASES_ENEMY_LUCK_BY_1);   }
        bool get_decreases_enemy_luck_by_2() const   { return special_abilities.get_ability_bit(Special_abilities::Abilities::DECREASES_ENEMY_LUCK_BY_2);   }
        bool get_doubles_luck_chance() const         { return special_abilities.get_ability_bit(Special_abilities::Abilities::DOUBLES_LUCK_CHANCE);         }

        bool get_magic_channel() const { return special_abilities.get_ability_bit(Special_abilities::Abilities::MAGIC_CHANNEL); }
        bool get_magic_damper() const  { return special_abilities.get_ability_bit(Special_abilities::Abilities::MAGIC_DAMPER);  }
        bool get_mana_economy() const  { return special_abilities.get_ability_bit(Special_abilities::Abilities::MANA_ECONOMY);  }

        bool get_has_spying() const         { return special_abilities.get_ability_bit(Special_abilities::Abilities::HAS_SPYING);         }
        bool get_is_sandwalker() const      { return special_abilities.get_ability_bit(Special_abilities::Abilities::IS_SANDWALKER);      }
        bool get_generates_crystals() const { return special_abilities.get_ability_bit(Special_abilities::Abilities::GENERATES_CRYSTALS); }

        uint8_t get_number_of_casts() const { return special_abilities.m_number_of_casts; }
        uint8_t get_spell_power() const     { return special_abilities.m_spell_power;     }

        // Returns a string with the cost of a creature.
        std::string get_cost() const;

        // Returns a string with the special abilities of a creature.
        std::string get_special_abilities() const { return special_abilities.m_abilities_str; }

        // Prints the full information of a creature.
        void print_full_info() const;
};
#endif