#ifndef HERO_H
#define HERO_H

#define NOMINMAX

#include <iostream>
#include <algorithm>
#include <array>
#include <cstdint>
#include <map>
#include <memory>

#include "Creature_stack.h"
#include "Faction.h"
#include "Item.h"
#include "Level_Experience.h"
#include "Morale_Luck.h"
#include "Position.h"
#include "Secondary_Skill.h"
#include "Skills_Probability.h"
#include "Specialty.h"
#include "Spellbook.h"
#include "Team.h"

namespace Hero_slots
{
    const uint8_t SECONDARY_SKILL = 10;

    const uint8_t ARMY = 7;

    const uint8_t HAND   = 2;   // one slot on each hand for rings and gloves
    const uint8_t POCKET = 5;   // for orbs, tomes, figurines, badges and others 
    const uint8_t CHEST  = 100; // for storing unequipped items
};

namespace 
{
    const uint8_t KNOWLEDGE_TO_MANA_MULTIPLIER = 10;
};

enum Heroes : uint8_t
{
    Dummy,
    Him,
    Her,

    // Castle
    Orrin,

    // Stronghold
    Crag_Hack,

    // Fortress
    Tazar
};

class Hero
{
    public:
        enum Gender
        {
            Male,  // 0
            Female // 1
        };

        enum Role
        {
            Might, // 0
            Magic  // 1
        };

        enum Class
        {
            Knight,       // Castle
            Cleric,       // Castle
            Ranger,       // Rampart
            Druid,        // Rampart
            Alchemist,    // Tower
            Wizard,       // Tower
            Demoniac,     // Inferno
            Heretic,      // Inferno
            Death_Knight, // Necropolis
            Necromancer,  // Necropolis
            Overlord,     // Dungeon
            Warlock,      // Dungeon
            Barbarian,    // Stronghold
            Battle_Mage,  // Stronghold
            Beastmaster,  // Fortress
            Witch,        // Fortress
            Planeswalker, // Conflux
            Elementalist, // Conflux
            Captain,      // Cove
            Navigator     // Cove
        };

    private:
        Heroes m_hero;
        std::string m_name;
        Gender m_gender;
        Role m_role;
        Class m_class;
        Faction m_faction;
        Team m_team;
        uint8_t m_level;
        uint32_t m_experience;

        struct primary_skills
        {
            uint8_t m_attack;
            uint8_t m_defense;
            uint8_t m_power;
            uint8_t m_knowledge;

            primary_skills( const uint8_t attack, const uint8_t defense, const uint8_t power, const uint8_t knowledge ) : 
                            m_attack(attack), m_defense(defense), m_power(power), m_knowledge(knowledge)
                            {};
        }primary_skills;

        Specialty m_specialty;

        Secondary_Skill* m_secondary_skills[Hero_slots::SECONDARY_SKILL] = {nullptr}; // TO DO : add to constructors

        Morale m_morale;
        Luck m_luck;

        uint16_t m_mana;
        uint16_t m_mana_left;
        
        uint16_t m_movement_points;

        uint8_t m_army_hp_bonus    = 0;
        uint8_t m_army_speed_bonus = 0;

        uint8_t m_reduce_enemy_power_skill;
        uint8_t m_reduce_enemy_morale;
        uint8_t m_reduce_enemy_luck;

        struct war_machines
        {
            bool m_has_first_aid;
            bool m_has_ammo_cart;
            bool m_has_ballista;
            // bool m_has_cannon;
            bool m_has_catapult;

            war_machines( const bool has_first_aid = false, const bool has_ammo_cart = false, const bool has_ballista = false, const bool has_catapult = true ) :
                          m_has_first_aid(has_first_aid), m_has_ammo_cart(has_ammo_cart), m_has_ballista(has_ballista), m_has_catapult(has_catapult)
                          {};
        }war_machines;

        bool m_has_spellbook;

        struct items
        {
            const Item* helmet   = nullptr;
            const Item* cape     = nullptr;
            const Item* necklace = nullptr;
            const Item* weapon   = nullptr;
            const Item* shield   = nullptr;
            const Item* armor    = nullptr;
            const Item* hand[Hero_slots::HAND] = {nullptr};
            const Item* boots = nullptr;
            const Item* pocket[Hero_slots::POCKET] = {nullptr};
        }items;

        const Item* chest[Hero_slots::CHEST] = {nullptr};

        // items - implement a structure with flags for possible effects from items, analogical to special abilities
        bool m_has_equipped_elixir_of_life = false;

        std::array<std::unique_ptr<Stack>, Hero_slots::ARMY> army = {nullptr};

        Position m_position{0, 0};

    private:
        // Disallow the use of default constructor.
        Hero() = delete;

        // Parametrized constructor.
        Hero( const Heroes m_hero, const Gender gender, const Role hero_role, const Faction faction, const Team team, const uint8_t level, const uint32_t experience, 
              const struct primary_skills& p_skills,
              const Specialty& specialty,
              const Morale morale, const Luck luck,
              // secondary skills
              const struct war_machines& war_machinery,
              const bool has_spellbook );

        // Disallow the use of copy constructor.
        Hero( const Hero& hero ) = delete;

        // Disallow the use of move constructor.
        Hero( Hero&& hero ) = delete;

        // Destructor.
        ~Hero();

    private:
        // Set the name of the item when constructing.
        void set_name_from_enum();

        // Create all heroes in the game, using the private constructor. Add them to a static map.
        static const std::map<Heroes, Hero*>& create_and_fill_heroes_list();
        // Use a counter to keep track if the map containing all Hero objects is incomplete.
        static uint16_t created_heroes;

    public:
        // Return a pointer to already created Hero object.
        static Hero* get(const Heroes hero) { return create_and_fill_heroes_list().at(hero); }

        Heroes get_hero_as_enum(){ return m_hero; }
        std::string get_name(){ return m_name; }

        Gender get_gender(){ return m_gender; }
        std::string get_gender_as_string();

        Role get_role(){ return m_role; }
        std::string get_role_as_string();

        Class get_class(){ return m_class; }
        std::string get_class_as_string();

        Faction get_faction(){ return m_faction; }
        std::string get_faction_as_string();

        Team get_team(){ return m_team; }
        std::string get_team_as_string();

        void set_level(const uint8_t level) { m_level = level; }
        void add_level(const uint8_t level);
        uint8_t get_level(){ return m_level; }

        void add_to_primary_on_level_up(uint8_t probability, const uint8_t* array);

        void set_experience(const uint32_t experience) { m_experience = experience; }
        void add_experience(const uint32_t experience);
        uint32_t get_experience(){ return m_experience; }

        void add_attack(const  int8_t attack) { primary_skills.m_attack = std::max(0, primary_skills.m_attack + attack); } // bug prone
        uint8_t get_attack() {return primary_skills.m_attack; }

        void add_defense(const  int8_t defense) { primary_skills.m_defense = std::max(0, primary_skills.m_defense + defense); } // bug prone
        uint8_t get_defense() {return primary_skills.m_defense; }

        void add_power(const  int8_t power) { primary_skills.m_power = std::max(0, primary_skills.m_power + power); } // bug prone
        uint8_t get_power() {return primary_skills.m_power; }

        void add_knowledge(const  int8_t knowledge) { primary_skills.m_knowledge = std::max(0, primary_skills.m_knowledge + knowledge); } // bug prone
        uint8_t get_knowledge() {return primary_skills.m_knowledge; }

        Specialty get_specialty() { return m_specialty; }

        void set_secondary_skill(const uint8_t i, Secondary_Skill skill) { m_secondary_skills[i] = &skill; }
        Secondary_Skill* get_secondary_skill(uint8_t i) { return m_secondary_skills[i]; }
        std::string get_secondary_skill_name(uint8_t i) { return m_secondary_skills[i]->get_name(); }
        Skill_level get_secondary_skill_level(const std::string skill_name);

        void set_morale(const Morale morale) { m_morale = morale; }
        void set_morale(const int8_t morale) { set_morale( clamp_morale( morale ) ); }
        void add_morale(const Morale morale) { m_morale = clamp_morale( m_morale + morale ); }
        void add_morale(const int8_t morale) { m_morale = clamp_morale( m_morale + morale ); }
        Morale get_morale() { return m_morale; }

        void set_luck(const Luck luck)   { m_luck = luck; }
        void set_luck(const int8_t luck) { set_luck( clamp_luck( luck ) ); }
        void add_luck(const Luck luck)   { m_luck = clamp_luck( m_luck + luck ); }
        void add_luck(const int8_t luck) { m_luck = clamp_luck( m_luck + luck ); }
        Luck get_luck() { return m_luck; }

        void reset_mana() { m_mana = KNOWLEDGE_TO_MANA_MULTIPLIER * primary_skills.m_knowledge; }
        uint16_t get_mana() { return m_mana; }

        void add_mana_left(const uint16_t mana) { m_mana_left += mana; }
        void reduce_mana_left(const uint16_t mana) { m_mana_left -= mana; } // before casting a spell, the available mana should be checked, otherwise this might overflow
        void reset_mana_left() { reset_mana(); m_mana_left = m_mana; }
        uint16_t get_mana_left() { return m_mana_left; }

        void add_movement_points(const uint16_t movement_points) { m_movement_points += movement_points; }
        uint16_t get_movement_points() { return m_movement_points; }
        
        void set_army_hp_bonus(const uint8_t bonus) { m_army_hp_bonus = bonus; }
        uint8_t get_army_hp_bonus()                 { return m_army_hp_bonus;  }

        void set_army_speed_bonus(const uint8_t bonus) { m_army_speed_bonus = bonus; }
        uint8_t get_army_speed_bonus()                 { return m_army_speed_bonus;  }

        void set_reduce_enemy_power_skill(const uint8_t reduce_power_skill) { m_reduce_enemy_power_skill  = reduce_power_skill; }
        void add_reduce_enemy_power_skill(const uint8_t reduce_power_skill) { m_reduce_enemy_power_skill += reduce_power_skill; }
        uint8_t get_reduce_enemy_power_skill() { return m_reduce_enemy_power_skill; }

        void set_reduce_enemy_morale(const uint8_t reduce_morale) { m_reduce_enemy_morale  = reduce_morale; }
        void add_reduce_enemy_morale(const uint8_t reduce_morale) { m_reduce_enemy_morale += reduce_morale; }
        uint8_t get_reduce_enemy_morale() { return m_reduce_enemy_morale; }

        void set_reduce_enemy_luck(const uint8_t reduce_luck) { m_reduce_enemy_luck  = reduce_luck; }
        void add_reduce_enemy_luck(const uint8_t reduce_luck) { m_reduce_enemy_luck += reduce_luck; }
        uint8_t get_reduce_enemy_luck() { return m_reduce_enemy_luck; }

        bool get_has_first_aid() { return war_machines.m_has_first_aid; }
        bool get_has_ammo_cart() { return war_machines.m_has_ammo_cart; }
        bool get_has_ballista()  { return war_machines.m_has_ballista;  }
        // bool get_has_cannon()    { return war_machines.m_has_cannon;    }
        bool get_has_catapult()  { return war_machines.m_has_catapult;  }

        bool get_has_spellbook() { return m_has_spellbook; }

        // Checks if slot is taken - if yes - tries to send the item to chest. If not - places it in slot.
        void pick_up_item(const Item* item);

        // Checks if item is in treasure chest and if yes, checks if the item slot is empty. If empty - calls equip_item(), if not empty - calls unequip_item() on the artifact in the slot and than calls equip_item() on the parsed one.
        void equip_item_from_chest(const Item* item);

        // Assigns the item to the correct slot and allows hero to gain the item's bonuses.
        void equip_item(const Item* item);

        // Checks if item is equiped, places it in the treasure chest and hero losses the item's bonuses.
        void unequip_item(const Item* item);

        // Checks if chest has a free slot. If yes - places the item there. If not - prints a message.
        bool add_item_to_chest(const Item* item);

        // Prints the names and effects of all equipped items.
        void print_equipped_items();
        
        // Prints the names and effects of all equipped items.
        void print_unequipped_items();
        
        // Returns true or false based on whether the item is equipped by the hero on the given slot.
        bool check_eqipped_item(std::string item_name, Item::Slot slot);

        // Adds a stack to the first empty slot in army.
        void add_stack_to_army(std::unique_ptr<Stack> & stack_ptr); // unique_ptr because this functionality in the game will be used in dynamic state
        
        // Adds a stack to a specific slot in army.
        void add_stack_to_slot(std::unique_ptr<Stack> & stack_ptr, const uint8_t slot); // unique_ptr because this functionality in the game will be used in dynamic state

        // Removes a stack from army.
        void remove_stack(std::unique_ptr<Stack> & stack_ptr); // unique_ptr in case there are other slots with the same stacks

        // Removes a stack from specific slot in army.
        void remove_stack_from_position(const uint8_t slot);
        
        // Swaps positions of two stacks in the same army. ALso used when one of the slots is empty.
        void swap_stack_positions(uint8_t i, uint8_t j);

        // Swaps the entire armies of two heroes of the same team.
        void swap_entire_armies(Hero& hero);
        
        // Update battle stats of each stack according to current hero attributes. Called every time hero adds or removes creature from army, gets a new level, gets a morale/luck bonus, equips/unequips an item.
        void update_army_stats();

        // Return a pointer to a stack in the army.
        Stack* get_army_stack(uint8_t i);

        // Return a unique_ptr to a stack in the army.
        std::unique_ptr<Stack> & get_army_stack_ptr(uint8_t i);

        void set_position(const Position position) { m_position = position; }
        Position get_position() { return m_position; }

        void move(const uint8_t x, const uint8_t y); // if map object - interact = take resources item, flag mine, fight monster/hero, enter castle
        
        void print_full_info();
};

#endif