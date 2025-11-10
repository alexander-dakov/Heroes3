#ifndef BATTLE_H
#define BATTLE_H

#include <iostream>
#include <cstdint>
#include <limits>
#include <memory>
#include <string>
#include <vector>

#include "Battlefield_Tile.h"
#include "Creature_Stack.h"
#include "Hero.h"
#include "Team.h"
#include "Terrains.h"

class Battle
{
    public:
        enum Format
        {
            Normal,
            Siege,      // like 'Normal' but builds a wall if the town has it
            Surrounded, // Creature bank
            Ships
        };

        // Disallow the use of default constructor.
        Battle() = delete;

        // Parametrized constructor, used upon starting a battle between two armies.
        Battle(Hero& attacker, Hero& defender, const Format format, const Terrain terrain); // constructing the battlefield, managing the event and then destroying the constructed objects

        // Disallow the use of copy constructor.
        Battle(const Battle& battle) = delete;

        // Disallow the use of move constructor.
        Battle(Battle&& battle) = delete;

        ~Battle();

    private:
        Hero& m_attacker; // left side
        Hero& m_defender; // right side

        // Defender may not have a hero. A possible solution is to create a new instance of a dummy/fake hero which will have no army bonuses. He will be there simply to 'carry' the army.

        Battlefield_Tile battlefield[Battlefield::WIDTH][Battlefield::LENGTH];
        Format m_format;
        Terrain m_terrain;

        uint16_t m_round = 0;
        std::vector<Stack*> m_turns;
        std::vector<Stack*> m_wait_turns;

        // A vector of pointers to stacks, to keep the corpses of perished stacks, so they could be resurrected.
        std::vector<Stack*> m_corpses = {nullptr};

        // An array to keep the reachable positions situated next to an army stack which is targeted.
        Position m_positions_around_stack[8];

        // Boolean variable for items which affect the battle
        bool m_spirit_of_oppression_present = false;
        bool m_hourglass_of_evil_hour_present = false;

        // Boolean variable for creatures which affect the battle
        bool m_angel_present        = false;
        bool m_necro_dragon_present = false;
        bool m_devil_present        = false;
        bool m_archdevil_present    = false;
        bool m_leprechaun_present   = false;

        Stack* find_present_stack( bool other_stack_is_on_battlefield, Stack* const my_stack, bool stacks_are_allies );

    public:
        Hero* get_attacker() { return &m_attacker; }
        Hero* get_defender() { return &m_defender; }

        Format get_format()   { return m_format;  }
        Terrain get_terrain() { return m_terrain; }

        uint16_t get_round() { return m_round; }

        std::vector<Stack*>* get_turns()       { return &m_turns;   }
        Stack* get_stack_turn(const uint8_t i) { return m_turns[i]; }

        std::vector<Stack*>* get_wait_turns()       { return &m_wait_turns;   }
        Stack* get_stack_wait_turn(const uint8_t i) { return m_wait_turns[i]; }

        std::vector<Stack*>* get_corpses() { return &m_corpses; }

        bool get_spirit_of_oppression_present()   { return m_spirit_of_oppression_present;  }
        bool get_hourglass_of_evil_hour_present() { return m_hourglass_of_evil_hour_present; }

        bool get_angel_present()        { return m_angel_present;        }
        bool get_necro_dragon_present() { return m_necro_dragon_present; }
        bool get_devil_present()        { return m_devil_present;        }
        bool get_archdevil_present()    { return m_archdevil_present;    }
        bool get_leprechaun_present()   { return m_leprechaun_present;   }

        bool get_ally_has_angel(Stack* const stack);
        bool get_enemy_has_necro_dragon(Stack* const stack);
        bool get_enemy_has_devil(Stack* const stack);
        bool get_enemy_has_archdevil(Stack* const stack);
        bool get_ally_has_leprechaun(Stack* const stack);

        Position enter_battlefield_coordinates();

        void check_valid_battlefield_pos(const uint8_t x, const uint8_t y);

        void set_battlefield_pos(const uint8_t x, const uint8_t y, const Battlefield_Tile::Tile tile = Battlefield_Tile::Tile::Normal, const Team team = Team::Neutral, const char ch = Battlefield::ARMY_CHAR);
        char get_battlefield_pos(const uint8_t x, const uint8_t y);

        void set_battlefield_pos(const Position pos, const Battlefield_Tile::Tile tile = Battlefield_Tile::Tile::Normal, const Team team = Team::Neutral, const char ch = Battlefield::ARMY_CHAR);
        char get_battlefield_pos(const Position pos);

        // Places a stack on the battlefield if the tile is free and reachable and changes the tile's team.
        void place_stack_on_battlefield(Stack* stack, const char ch);

        // Sets stack's position (private member) and copies it to the battlefield.
        void position_armies();

        // Populate the battlefield with tiles, set up the unreachable tiles according to the format of the battle and position the armies.
        void set_up_battlefield();

        // Prints the battlefield with colors according to the team + a legend below.
        void print_battlefield(Stack* const current_stack);

        // Applies terrain bonuses to a stack of creatures.
        void apply_terrain_bonuses_to_stack(Stack* stack); // should be applicable to stacks individually, as new stacks of Air/Water/Fire/Earth Elementals might be summoned on the battle field

        // Updates the round counter, the action and buffs/debuffs on each stack, and then reorders the turns of all stacks according to the fastest units on the battlefield.
        void set_up_next_round();

        // Populate the turns with pointers to army stacks and order them according to the fastest units on the battlefield. It is used only before the first round.
        void set_up_initial_turns();

        // Orders the stacks that allready exist in the turn vector. It is used before the begining of every round after the first one.
        void set_up_normal_turns();

        // Orders the stacks that decided to wait during their own turn.
        void set_up_wait_turns();

        // Prints the normal and then the wait turns, as a chain, in which every stack is represented with the same symbol used to on the battlefield.
        void print_turns();

        // Updates attributes, buffs and debuffs in the beggning of each new turn.
        void new_turn(); // should be called simultaiously for every creature on the battlefield

        // On stack's turn:
        // 1. Roll for negative morale - if negative => skip
        // 2. Wait / Defend / Move / Attack (roll for luck, target = able to reach / shoot) / Cast creature spell
        // 3. Roll for positive morale - if positive => do 2 again
        void on_stack_turn(Stack* stack, bool morale_rolled = false); // do any of the following functions

        // Decides if stack will act upon its turn during battle.
        bool roll_negative_morale(Stack* const stack); // before initial action in turn

        // Decides if stack will act again in the end its turn during battle.
        bool roll_positive_morale(Stack* const stack); // after initial action in turn

        // Returns -1/0/1, refering to the type of attack (unlucky/non-lucky/lucky strike) a stack will perform on its turn.
        int8_t roll_luck(Stack* const stack);

        std::string select_action_for_stack(const bool stack_can_wait);

        // Checks if heroes have equipped items which debuff the moral and luck of every stack.
        void set_global_buffs_and_debuffs();

        // Returns 'true' if the tile can be occupied by the stack and is located within the stack's reach.
        bool tile_is_reachable(const uint8_t x, const uint8_t y, Stack* const stack);

        // Returns 'true' if a tile next to an enemy can be occupied by the stack and is located within the stack's reach.
        bool enemy_is_reachable(Stack* const stack, Stack* const enemy_stack);

        uint8_t get_distance_between_stacks(Stack* const stack, Stack* const enemy_stack);

        // Shows the coordinates of all surrounding tiles from which the defending stack can be attack, and the player picks one.
        void select_location_around_enemy_stack(Position& pos, Stack* const stack, Stack* const enemy_stack);

        Stack* find_existing_enemy_stack_via_symbol(const char ch, const Team team);

        Stack* find_existing_stack_via_position(const Position pos);

        // Checks if there is an adjacent enemy stack.
        bool has_adjacent_enemy(Stack* const stack);

        // Returns all stacks adjecent to the given stack.
        std::vector<Stack*> adjacent_stacks(Stack* const stack);
        // Returns all stacks adjecent to the given position.
        std::vector<Stack*> adjacent_stacks_to_pos(Position pos, bool include_position = true);

        // Returns 'true' if the stacks are adjacent and 'false', if not.
        bool stacks_are_adjacent(Stack* const stack, Stack* const enemy_stack);
        // Returns 'true' if the stacks are adjacent to the given position and 'false', if not.
        bool stack_is_adjacent_to_pos(Position pos, Stack* const enemy_stack, bool include_position = true); // used for projectile attacks to positions - Magogs and Power Liches.

        // Checks if the attacking stack will suffer obstacle penalty when shooting at the defending stack.
        bool stack_has_obstacle_penalty(Stack* const attacking_stack, Stack* const defending_stack, const bool attacker_has_ranged_penalty);

        // Moves stack according to type of traveling (walking, flying, teleporting) and updates the battlefield.
        void move_stack(Stack* stack, const uint8_t x, const uint8_t y);

        // Moves the stack if needed and attacks the enemy stack.
        void attack_stack(Stack* attacking_stack, Stack* defending_stack);

        // Stack does nothing, but gains bonus defense skill during the battle turn (this bonus is taken into account in inflict_damage() ).
        void defend_stack(Stack* stack);

        // Skip stack's action and update 'wait_turns' so the stack can act later during the same battle turn.
        void wait_stack(Stack* stack);

        // Calls inflict damage on single stack or multuple stacks, depending on the attacking stack's special abilities.
        void target_and_inflict_damage(Stack* attacking_stack, Stack* defending_stack, bool const attack_is_retaliation = false);

        // Calculates the damage which will be dealt according to all factors.
        void inflict_damage(Stack* const attacking_stack, Stack* defending_stack, bool const defender_is_targeted = true, bool const attack_is_retaliation = false, bool const attack_is_second_attack = false);

        // Calls inflict_damage() if stack can retaliate.
        void retaliate(Stack* const attacking_stack, Stack* defending_stack);

        // Adds the stack to the corpses vector and removes it from the battlefield.
        void upon_stack_death(Stack* stack);

        // Checks if a ranged stack can shoot = has ammo + if stack has no melee penalty when there is adjacent enemy.
        bool stack_can_shoot(Stack* const attacking_stack, Stack* const defending_stack = nullptr);

        // Returns a pointer to the hero, to whose army the stack belongs.
        Hero* get_hero_of_stack(Stack* const stack);

        // Checks if the battle has finished. Used before the beginning of every turn during a battle.
        bool check_battle_finished();
};

#endif