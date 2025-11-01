#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <cstdint>
#include <map>
#include <string>
#include <vector>

// #include "../utilities/types.h"
#include "Resources.h"
#include "Morale_Luck.h"
#include "Spell.h"

namespace
{
      const uint8_t MAX_NUM_OF_EFFECTS = 10; // used to catch inaccuracies when constructing objects in Item_List.cpp
}


struct Item
{
      public:
            enum Slot
            {
                  Helmet = 1, // 1 = crown, hat
                  Cape,       // 2
                  Necklace,   // 3
                  Weapon,     // 4 = mace, trident, club
                  Shield,     // 5
                  Armor,      // 6
                  Hand,       // 7 = ring, gloves
                  Boots,      // 8
                  Pocket      // 9 = orbs, tomes, figurines, badges and others
            };

            enum Type
            {
                  None, // 0 = spell scrolls
                  Treasure,
                  Minor,
                  Major,
                  Relic
            };

      private:
            std::string m_name;
            Slot m_slot;
            Type m_item_type;
            uint16_t m_ai_value;

            struct effects
            {
                  std::string m_effect = "";

                  // primary skill bonuses and penalties
                  bool m_modify_attack = false;
                  int8_t m_attack = 0;

                  bool m_modify_defense = false;
                  int8_t m_defense = 0;

                  bool m_modify_power = false;
                  int8_t m_power = 0;

                  bool m_modify_knowledge = false;
                  int8_t m_knowledge = 0;

                  // morale and luck bonuses and penalties
                  bool m_modify_morale = false;
                  uint8_t m_morale = 0;
                  uint8_t m_decrease_enemy_morale = 0;
                  bool m_disable_positive_morale = false; // Spirit of Oppression

                  bool m_modify_luck = false;
                  uint8_t m_luck = 0;
                  uint8_t m_decrease_enemy_luck = 0;
                  bool m_disable_positive_luck = false; // Hourglass of the Evil Hour
                  
                  // increase hp of all creature stacks in army
                  bool m_increase_hp_1 = false; // Ring of Vitality, Ring of Life
                  bool m_increase_hp_2 = false; // Vial of Lifeblood
                  bool m_increase_hp_quater = false; // Elixir of Life

                  bool m_give_regeneration_ability = false; // Elixir of Life

                  // increase speed of all creature stacks in army
                  bool m_increase_speed_1 = false; // Necklace of Swiftness, Ring of the Wayfarer
                  bool m_increase_speed_2 = false; // Cape of Velocity

                  // increase spells duration
                  bool m_increase_spell_duration_1  = false; // Collar of Conjuring
                  bool m_increase_spell_duration_2  = false; // Ring of Conjuring
                  bool m_increase_spell_duration_3  = false; // Cape of Conjuring
                  bool m_increase_spell_duration_50 = false; // Ring of the Magi
                  
                  // increase chance to resist magic damage
                  bool m_increase_magic_resist_5  = false; // Garniture of Interference
                  bool m_increase_magic_resist_10 = false; // Surcoat of Counterpoise
                  bool m_increase_magic_resist_15 = false; // Boots of Polarity
                  bool m_increase_magic_resist_20 = false; // Pendant of Reflection
                  
                  // reduce enemy spellpower
                  bool m_decrease_enemy_spell_power_10 = false; // Charm of Eclipse, Seal of Sunset
                  bool m_decrease_enemy_spell_power_25 = false; // Plate of Dying Light
                  
                  // immunity bonuses and penalties
                  bool m_immune_to_dispel           = false; // Sphere of Permanence
                  bool m_immune_to_curse            = false; // Pendant of Holiness
                  bool m_immune_to_forgetfulness    = false; // Pendant of Total Recall
                  bool m_immune_to_blind            = false; // Pendant of Second Sight
                  bool m_immune_to_hypnotize        = false; // Pendant of Free Will
                  bool m_immune_to_berserk          = false; // Pendant of Dispassion
                  bool m_immune_to_destroy_undead   = false; // Pendant of Death
                  bool m_immune_to_death_ripple     = false; // Pendant of Life
                  bool m_immune_to_lightning_bolt   = false; // Pendant of Negativity
                  bool m_immune_to_chain_lightning  = false; // Pendant of Negativity
                  bool m_immune_to_armageddon       = false; // Armageddon's Blade
                  bool m_immune_to_spells_level_1_4 = false; // Power of the Dragon Father
                  bool m_no_immunities              = false; // Orb of Vulnerability
                 
                  // adds spells to spellbook
                  bool m_add_all_air_spells        = false; // Tome of Air
                  bool m_add_all_water_spells      = false; // Tome of Water
                  bool m_add_all_earth_spells      = false; // Tome of Earth
                  bool m_add_all_fire_spells       = false; // Tome of Fire
                  bool m_add_all_level_5_spells    = false; // Spellbinder's Hat
                  bool m_add_titans_lightning_bolt = false; // Titan's Thunder
                  // spellscrolls need to be added here
                 
                  // movement points
                  bool m_increase_land_movement_points_200 = false; // Equestrian's Gloves
                  bool m_increase_land_movement_points_400 = false; // Boots of Speed
                  bool m_increase_sea_movement_points_500  = false; // Sea Captain's Hat	
                  bool m_increase_sea_movement_points_1000 = false; // Necklace of Ocean Guidance
                  bool m_no_rough_terrain_penalty          = false; // Wayfarer's Boots

                  // increase mana points regeneration per day
                  bool m_mana_regeneration_1    = false; // Charm of Mana
                  bool m_mana_regeneration_2    = false; // Talisman of Mana
                  bool m_mana_regeneration_3    = false; // Mystic Orb of Mana
                  bool m_mana_regeneration_full = false; // Wizard's Well

                  // generate resources per day
                  bool m_generates_gold_500    = false; // Endless Purse of Gold	
                  bool m_generates_gold_750    = false; // Endless Bag of Gold	
                  bool m_generates_gold_1000   = false; // Endless Sack of Gold	
                  bool m_generates_gold_4750   = false; // Golden Goose
                  bool m_generates_wood        = false; // Inexhaustible Cart of Lumber
                  bool m_generates_ore         = false; // Inexhaustible Cart of Ore
                  bool m_generates_mercury     = false; // Everpouring Vial of Mercury
                  bool m_generates_sulfur      = false; // Eversmoking Ring of Sulfur
                  bool m_generates_crystal     = false; // Everflowing Crystal Cloak
                  bool m_generates_gem         = false; // Ring of Infinite Gems
                  bool m_generates_resources_4 = false; // Cornucopia
                  
                  // Create a map of all special abilities, refering to the fields in the struct accordingly.
                  std::map< std::string, std::vector<bool*> > create_map_of_all_effects();

                  // Fill the effects struct according to the passed effect string.
                  void fill_effects();

                  // Fill the string in the field
                  effects(std::string effect) : m_effect(effect) {};
            }effects;

            struct cost
            {
                  uint16_t m_gold     = 0;
                  uint16_t m_mercury  = 0;
                  uint16_t m_sulfur   = 0; 
                  uint16_t m_crystals = 0;
                  uint16_t m_gems     = 0;

                  // Constructs a private structure containing data used when purchasing an item
                  cost( const Resources resources ) : m_gold(resources.Gold), m_mercury(resources.Mercury), m_sulfur(resources.Sulfur), m_crystals(resources.Crystals), m_gems(resources.Gems)
                  {};
            }cost;

      public:
            // Disallow the use of default constructor.
            Item() = delete;

            // Parametrized constructor (no default constructor allowed) for every item besides spellscrolls.
            Item( const std::string name, const Slot slot, const Type item_type, const Resources resources, const std::string effect );

            // Constructor for spellscrolls.
            Item( Spell& spellscroll, const Resources resources );

            // Disallow the use of copy constructors.
            Item(const Item& item) = delete;
            Item(const Item* item) = delete;

            // Disallow the use of move constructor.
            Item(Item&& item) = delete;

            ~Item();

            std::string get_name() const { return m_name; }

            Slot get_slot() const { return m_slot; }
            std::string get_slot_as_string() const;

            Type get_type() const { return m_item_type; }
            std::string get_type_as_string() const;

            uint16_t get_ai_value() const { return m_ai_value; }

            std::string get_effect() const { return effects.m_effect; }

            int8_t get_attack_bonus() const    { return effects.m_modify_attack    * effects.m_attack;    }
            int8_t get_defense_bonus() const   { return effects.m_modify_defense   * effects.m_defense;   }
            int8_t get_power_bonus() const     { return effects.m_modify_power     * effects.m_power;     }
            int8_t get_knowledge_bonus() const { return effects.m_modify_knowledge * effects.m_knowledge; }

            uint8_t get_morale_bonus() const { return effects.m_modify_morale * effects.m_morale; }
            uint8_t get_luck_bonus() const   { return effects.m_modify_luck   * effects.m_luck;   }

            uint8_t get_decrease_enemy_morale_bonus() const { return -effects.m_modify_morale * effects.m_decrease_enemy_morale; }
            uint8_t get_decrease_enemy_luck_bonus() const   { return -effects.m_modify_luck   * effects.m_decrease_enemy_luck;   }

            bool get_disable_positive_morale() const { return effects.m_disable_positive_morale; }
            bool get_disable_positive_luck() const   { return effects.m_disable_positive_luck;   }

            bool get_increase_hp_1() const { return effects.m_increase_hp_1; }
            bool get_increase_hp_2() const { return effects.m_increase_hp_1; }

            bool get_increase_speed_1() const { return effects.m_increase_speed_1; }
            bool get_increase_speed_2() const { return effects.m_increase_speed_2; }

            uint8_t get_decrease_enemy_spell_power_10() const { return -effects.m_decrease_enemy_spell_power_10; }
            uint8_t get_decrease_enemy_spell_power_25() const { return -effects.m_decrease_enemy_spell_power_25; }

            uint16_t get_gold() const { return cost.m_gold; }

            uint16_t get_mercury() const { return cost.m_mercury; }

            uint16_t get_sulfur() const { return cost.m_sulfur; }

            uint16_t get_crystals() const { return cost.m_crystals; }

            uint16_t get_gems() const { return cost.m_gems; }
            
            std::string get_cost() const;

            void print_full_info() const;
};


#endif