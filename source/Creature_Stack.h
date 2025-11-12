#ifndef CREATURE_STACK_H
#define CREATURE_STACK_H

#include <iostream>
#include <cstdint>

#include "Team.h"
#include "Creature.h"
#include "Position.h"

// TO DO :
// get hero's special abilities form creature and place in creature_stack
// allow creature to hold up to 3 buffs/debuffs and reduce their duration on each turn with 1
// fix function new_turn
// add defend to attack function
// make creature a struct to be used as a library (could be added in a namespace) and leave only getters in it. all setters and modifiers should be in creature stack.
// Stack should be constructed with the help of a copy constructor when it comes to creatures

namespace 
{
    const uint8_t MIN_NUM_FOR_GROUP_DMG_CALC = 10;
}


class Stack
{
    public:
        enum Action // Used on every turn of a stack during battle
        {
            Attack, // normal state in which the stack is going to move or attacks
            Defend,
            Wait,
            Skip // perished / negative morale rolled / blinded
        };
        
    private:
        Team m_team = Team::Neutral;
        const Creature* const m_creature; // pointer to a creature struct from Creature_List
        struct battle_stats
        {
            uint8_t m_att;                  // modified by hero's attack skill
            uint8_t m_def;                  // modified by battle and hero's defense skill
            uint8_t m_shots_left;           // modified by battle and ammo cart
            uint16_t m_hp;                  // modified by battle and hero's items
            uint16_t m_hp_left;             // modified by battle and hero's items
            uint8_t m_speed;                // modified by hero's items
            Morale m_morale;                // modified by hero's morale
            Luck m_luck;                    // modified by hero's luck
            uint8_t m_number_of_casts_left; // modified by battle

            // Constructs a private structure containing data used during battles when no hero is leading the army.
            battle_stats(const Creature* const m_creature)
            {
                m_att        = m_creature->get_att();
                m_def        = m_creature->get_def();
                m_shots_left = m_creature->get_shots();
                m_hp         = m_creature->get_hp();
                m_hp_left    = m_hp;
                m_speed      = m_creature->get_speed();
                m_morale     = m_creature->get_morale();
                m_luck       = m_creature->get_luck();
                m_number_of_casts_left = m_creature->get_number_of_casts();
            };
        }battle_stats;

        uint32_t m_number;
        char m_battlefield_symbol = ' ';
        Position m_pos = Position(0, 0);
        uint8_t m_distance_traveled = 0;
        bool m_has_perished = false;
        uint8_t m_retaliations_left = 1; // can be 0,1,2. Not applicable for special ability 'Unlimited retaliations'.
        Action m_action = Action::Attack;

        // Each creature can hold up to 3 spell effects at the same time.
        // std::array< Spell - duration , 3 > m_spell_slots; // Should work as LIFO but also be able to have spells removed regardless of the order - thus normal container with fixed length.

        bool m_has_acquired_regeneration = false;

    public:
        // Disallow the use of default constructor.
        Stack() = delete;

        // Parametrized constructor used during battle.
        Stack(const Creature* const creature, const uint32_t number, const uint8_t pos_x, const uint8_t pos_y, const char battlefield_symbol, const Team team);
        
        // Parametrized constructor used in when purchasing a stack, moving at least part of it from one army to another or seperating it into smaller stacks.
        Stack(const Creature* const creature, const uint32_t number, const Team team);

        // Parametrized constructor used when creating stack, by passing objects directly from Creature_List. Used when creating the initial army of a Hero.s
        Stack(const Creature& creature, const uint32_t number, const Team team);

        // Parametrized constructor, used when moving a stack from one army to another or seperating it into smaller stacks.
        Stack(const Stack& stack, const uint32_t number);

        // Parametrized constructor, used when moving a stack from one army to another or seperating it into smaller stacks.
        Stack(const Stack* stack, const uint32_t number);

        // Disallow the use of copy constructor.
        Stack(const Stack& stack) = delete;
        
        // Disallow the use of move constructor.
        Stack(Stack&& stack) = delete;

        // Destructor
        ~Stack();

        Team get_team() { return m_team; }
        std::string get_team_as_string();

        const Creature* const get_creature() { return m_creature; }

        const CreatureType get_creature_type() { return get_creature()->get_type(); }       // for ease of code writing
        const std::string get_creature_name() { return get_creature()->get_name(); }        // for ease of code writing
        const Faction get_faction() { return get_creature()->get_faction(); }               // for ease of code writing
        const Terrain get_native_terrain() { return get_creature()->get_native_terrain(); } // for ease of code writing

        // Used when stacks are removed from an army or are moved from one army to another;
        void reset_stats();

        void set_att(const uint8_t att) { battle_stats.m_att = att; }
        uint8_t get_att() { return battle_stats.m_att; }

        void set_def(const uint8_t def) { battle_stats.m_def = def; }
        uint8_t get_def() { return battle_stats.m_def; }

        void set_shots_left(const uint8_t shots_left) { battle_stats.m_shots_left = shots_left; }
        uint8_t get_shots_left() { return battle_stats.m_shots_left; }
        
        void set_hp(const uint16_t hp) { battle_stats.m_hp = hp; } // for bonuses from items
        uint16_t get_hp() { return battle_stats.m_hp; }

        void set_hp_left(const uint16_t hp) { battle_stats.m_hp_left = std::min(hp, battle_stats.m_hp); }
        uint16_t get_hp_left() { return battle_stats.m_hp_left; }

        void set_speed(const uint8_t speed) { battle_stats.m_speed = speed; }
        uint8_t get_speed() { return battle_stats.m_speed; }

        void set_morale(const Morale morale);
        void add_morale(const Morale morale);
        Morale get_morale() { return battle_stats.m_morale; }

        void set_luck(const Luck luck)   { battle_stats.m_luck = luck; }
        void add_luck(const Luck luck)   { battle_stats.m_luck = clamp_luck( battle_stats.m_luck + luck ); }
        Luck get_luck() { return battle_stats.m_luck; }

        uint8_t get_number_of_casts_left() { return battle_stats.m_number_of_casts_left; }

        void set_number(const uint32_t number) { m_number = number; m_has_perished = !number; set_action(Action::Skip); } // when recieving damage
        uint32_t get_number() {return m_number; }

        void set_battlefield_symbol(const char ch) { m_battlefield_symbol = ch; }
        char get_battlefield_symbol() { return m_battlefield_symbol; }
        void reset_battlefield_symbol() { m_battlefield_symbol = ' '; }

        void set_position(const Position position) { m_pos = position; }
        void set_position(const uint8_t x, const uint8_t y) { m_pos = {x, y}; }
        Position get_position() { return m_pos; }

        void set_distance_traveled(const uint8_t distance_traveled) { m_distance_traveled = distance_traveled; }
        uint8_t get_distance_traveled() { return m_distance_traveled; }

        void set_has_perished(const bool has_perished) { m_has_perished = has_perished; } // when a stack dies
        bool get_has_perished() { return m_has_perished; } // to skip turns during battle, forbid attacks and reduce retaliation

        void set_retaliations_left(const uint8_t retaliations) { m_retaliations_left = retaliations; }
        uint8_t get_retaliations_left() { return m_retaliations_left; }

        void set_action(const Action action) { m_action = action; }
        Action get_action() { return m_action; }

        void set_has_acquired_regeneration(const bool regenerates) { m_has_acquired_regeneration = regenerates; }
        bool get_has_acquired_regeneration() { return m_has_acquired_regeneration; }

        // Stack's number and/or remaining health of last units get affected.
        void recieve_damage(const uint32_t damage);

        // Prints information of the stack during battle = creature forming the stack + hp left + shots left + stack number, stack position, buffs and defbuffs
        void print_battle_info();

        // Prints information of the stack outide battle = creature forming the stack + hp left + shots left + stack number, stack position, buffs and defbuffs
        void print_full_info();
};

#endif