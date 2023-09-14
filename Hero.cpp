#include "Hero.h"

Hero::Hero( const std::string name, const Gender gender, const Class class_, const Faction faction, const Team team, const uint8_t level, const uint32_t experience, 
            const uint8_t attack, const uint8_t defence, const uint8_t power, const uint8_t knowledge,
            const Specialty& specialty,
            const Morale morale, const Luck luck,
            // secondary skills
            const bool has_first_aid, const bool has_ammo_cart, const bool has_ballista, const bool has_catapult,
            const bool has_spellbook ) :
            _name(name), _gender(gender), _class(class_), _faction(faction), _team(team), _level(level), _experience(experience), 
            primary_skills(attack, defence, power, knowledge),
            _specialty(specialty),
            _morale(morale), _luck(luck),
            // {"None", ...} write them in some way and change field in Hero.h,
            war_machines(has_first_aid, has_ammo_cart, has_ballista, has_catapult), 
            _has_spellbook(has_spellbook)
{
      _mana = knowledge*10;
      _mana_left = _mana;
      _moving_points = 1560;
};



void Hero::add_level(const uint8_t level)
{
      // use map for these
      // 1	0	
      // 2	1,000
      // 3	2,000
      // 4	3,200
      // 5	4,600
      // 6	6,200
      // 7	8,000
      // 8	10,000
      // 9	12,200
      // 10	14,700
}

void Hero::add_experience(const uint32_t experience)
{
      // according to add_level
}
