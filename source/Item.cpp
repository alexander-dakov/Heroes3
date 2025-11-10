#include "Item.h"
#include "../utilities/user_macros.h"

uint8_t Item::created_items = 0;

Item::Item( const std::string& name, const Slot slot, const Type item_type, const Resources resources, const std::string& effect ) :
            m_name(name), m_slot(slot), m_item_type(item_type), cost(resources), effects(effect)
{
      effects.fill_effects();

      switch( get_type() )
      {
        case Type::Treasure : m_ai_value =  2000; break;
        case Type::Minor    : m_ai_value =  5000; break;
        case Type::Major    : m_ai_value = 10000; break;
        case Type::Relic    : m_ai_value = 20000; break;
      }

      created_items++;

      // printf( "Item '%s' created.\n", get_name().c_str() );
}

Item::Item( Spell& spellscroll, const Resources resources ) :
            m_name(spellscroll.get_name().c_str()), m_slot(Slot::Pocket), effects(spellscroll.get_description().c_str()), cost(resources)
{
    ASSERT( get_type() != Type::None, "All spellscrolls must have type 'None'! Check up Item_List.cpp!" );

    if     ( spellscroll.get_name() == "Town portal" )    { m_ai_value = 20000; }
    else if( spellscroll.get_name() == "Water walk" )     { m_ai_value = 20000; }
    else if( spellscroll.get_name() == "Fly" )            { m_ai_value = 20000; }
    else if( spellscroll.get_name() == "Dimension door" ) { m_ai_value = 20000; }
    else {
        switch( spellscroll.get_spell_level() )
        {
            case Spell::Level::None   : m_ai_value =     0; break;
            case Spell::Level::First  : m_ai_value =   500; break;
            case Spell::Level::Second : m_ai_value =  2000; break;
            case Spell::Level::Third  : m_ai_value =  3000; break;
            case Spell::Level::Fourth : m_ai_value =  8000; break;
            case Spell::Level::Fifth  : m_ai_value = 10000; break;
        }
    }

    created_items++;

    // printf( "Item '%s' created.\n", get_name().c_str() );
}

Item::~Item()
{
    // printf( "Item '%s' destroyed!\n", get_name().c_str() );
}

std::map< std::string, std::vector<bool*> > Item::effects::create_map_of_all_effects()
{
    std::map< std::string, std::vector<bool*> > all_effects; // all special abilities in existance, refering to their respective boolean

    all_effects["All primary skills +1."] = { &m_modify_attack, &m_modify_defense, &m_modify_power, &m_modify_knowledge };
    all_effects["All primary skills +2."] = { &m_modify_attack, &m_modify_defense, &m_modify_power, &m_modify_knowledge };
    all_effects["All primary skills +3."] = { &m_modify_attack, &m_modify_defense, &m_modify_power, &m_modify_knowledge };
    all_effects["All primary skills +4."] = { &m_modify_attack, &m_modify_defense, &m_modify_power, &m_modify_knowledge };
    all_effects["All primary skills +5."] = { &m_modify_attack, &m_modify_defense, &m_modify_power, &m_modify_knowledge };
    all_effects["All primary skills +6."] = { &m_modify_attack, &m_modify_defense, &m_modify_power, &m_modify_knowledge };

    all_effects["Attack skill -3."]  = { &m_modify_attack };
    all_effects["Attack skill +1."]  = { &m_modify_attack };
    all_effects["Attack skill +2."]  = { &m_modify_attack };
    all_effects["Attack skill +3."]  = { &m_modify_attack };
    all_effects["Attack skill +4."]  = { &m_modify_attack };
    all_effects["Attack skill +5."]  = { &m_modify_attack };
    all_effects["Attack skill +6."]  = { &m_modify_attack };
    all_effects["Attack skill +7."]  = { &m_modify_attack };
    all_effects["Attack skill +12."] = { &m_modify_attack };

    all_effects["Defense skill -3."]  = { &m_modify_defense };
    all_effects["Defense skill +1."]  = { &m_modify_defense };
    all_effects["Defense skill +2."]  = { &m_modify_defense };
    all_effects["Defense skill +3."]  = { &m_modify_defense };
    all_effects["Defense skill +4."]  = { &m_modify_defense };
    all_effects["Defense skill +5."]  = { &m_modify_defense };
    all_effects["Defense skill +6."]  = { &m_modify_defense };
    all_effects["Defense skill +7."]  = { &m_modify_defense };
    all_effects["Defense skill +12."] = { &m_modify_defense };

    all_effects["Power skill -2."]   = { &m_modify_power };
    all_effects["Power skill +1."]   = { &m_modify_power };
    all_effects["Power skill +2."]   = { &m_modify_power };
    all_effects["Power skill +3."]   = { &m_modify_power };
    all_effects["Power skill +4."]   = { &m_modify_power };
    all_effects["Power skill +5."]   = { &m_modify_power };
    all_effects["Power skill +6."]   = { &m_modify_power };
    all_effects["Power skill +10."]  = { &m_modify_power };

    all_effects["Knowledge skill -2."]   = { &m_modify_knowledge };
    all_effects["Knowledge skill +1."]   = { &m_modify_knowledge };
    all_effects["Knowledge skill +2."]   = { &m_modify_knowledge };
    all_effects["Knowledge skill +3."]   = { &m_modify_knowledge };
    all_effects["Knowledge skill +4."]   = { &m_modify_knowledge };
    all_effects["Knowledge skill +5."]   = { &m_modify_knowledge };
    all_effects["Knowledge skill +6."]   = { &m_modify_knowledge };
    all_effects["Knowledge skill +10."]  = { &m_modify_knowledge };

    all_effects["Unit's health points +1."] = { &m_increase_hp_1 };
    all_effects["Unit's health points +2."] = { &m_increase_hp_2 };

    all_effects["Unit's speed +1."] = { &m_increase_speed_1 };
    all_effects["Unit's speed +2."] = { &m_increase_speed_2 };

    all_effects["Morale +1."]       = { &m_modify_morale };
    all_effects["Morale +2."]       = { &m_modify_morale }; // no such item in orginal game
    all_effects["Morale +3."]       = { &m_modify_morale };
    all_effects["Enemy morale -1."] = { &m_modify_morale };
    all_effects["Enemy morale -2."] = { &m_modify_morale };
    all_effects["Negates all positive morale bonuses during combat for both you and your opponent."] = { &m_disable_positive_morale };

    all_effects["Luck +1."]       = { &m_modify_luck };
    all_effects["Luck +2."]       = { &m_modify_luck }; // no such item in orginal game
    all_effects["Luck +3."]       = { &m_modify_luck };
    all_effects["Enemy luck -1."] = { &m_modify_luck };
    all_effects["Enemy luck -2."] = { &m_modify_luck };
    all_effects["Negates all positive luck bonuses during combat for both you and your opponent."] = { &m_disable_positive_luck };

    return all_effects;
}

void Item::effects::fill_effects()
{
    std::string helper = m_effect; // a copy of the original creature ablities to cut from
    std::string::size_type pos; // position of found substring from map in "helper" string

    auto all_effects = create_map_of_all_effects();

    uint8_t counter = 0;
    while( helper.length() > 1) // no need to enter helper when an empty space remains
    {
        counter ++;
        if( counter > MAX_NUM_OF_EFFECTS )
        {
            std::cerr << "An items effect is not recognized by the algorithm. Make sure that the string in create_map_of_all_effects() is the same as in Item_List." << std::endl;
            std::cerr << "Problematic string : " << helper << std::endl;
            std::cerr << "Full string : " << m_effect << std::endl;
            abort();
        }

        if( helper[0] == ' ' ) // if the first character is whitespace - delete it
        {
            helper.erase(0, 1);
            break;
        }
        else
        {
            for(auto effects : all_effects) // key-value pair
            {
                pos = helper.find(effects.first);
                if( pos != std::string::npos )
                {
                    for(auto effect : effects.second)
                        *effect = true;
                    helper.erase(pos, effects.first.length());
                    if( helper[pos] == ' ' ) // if the new character on the same place is whitespace - delete it
                        helper.erase(pos, 1);
                    break;
                }
            }
        }
    }

    if( m_modify_attack )
        m_attack =  1*(m_effect.find("All primary skills +1.") != std::string::npos)
                 +  2*(m_effect.find("All primary skills +2.") != std::string::npos)
                 +  3*(m_effect.find("All primary skills +3.") != std::string::npos)
                 +  4*(m_effect.find("All primary skills +4.") != std::string::npos)
                 +  5*(m_effect.find("All primary skills +5.") != std::string::npos)
                 +  6*(m_effect.find("All primary skills +6.") != std::string::npos)
                 -  3*(m_effect.find("Attack skill -3.")       != std::string::npos)
                 +  1*(m_effect.find("Attack skill +1.")       != std::string::npos)
                 +  2*(m_effect.find("Attack skill +2.")       != std::string::npos)
                 +  3*(m_effect.find("Attack skill +3.")       != std::string::npos)
                 +  4*(m_effect.find("Attack skill +4.")       != std::string::npos)
                 +  5*(m_effect.find("Attack skill +5.")       != std::string::npos)
                 +  6*(m_effect.find("Attack skill +6.")       != std::string::npos)
                 +  7*(m_effect.find("Attack skill +7.")       != std::string::npos)
                 + 12*(m_effect.find("Attack skill +12.")      != std::string::npos);

    if( m_modify_defense )
        m_defense =  1*(m_effect.find("All primary skills +1.") != std::string::npos)
                  +  2*(m_effect.find("All primary skills +2.") != std::string::npos)
                  +  3*(m_effect.find("All primary skills +3.") != std::string::npos)
                  +  4*(m_effect.find("All primary skills +4.") != std::string::npos)
                  +  5*(m_effect.find("All primary skills +5.") != std::string::npos)
                  +  6*(m_effect.find("All primary skills +6.") != std::string::npos)
                  -  3*(m_effect.find("Defense skill -3.")      != std::string::npos)
                  +  1*(m_effect.find("Defense skill +1.")      != std::string::npos)
                  +  2*(m_effect.find("Defense skill +2.")      != std::string::npos)
                  +  3*(m_effect.find("Defense skill +3.")      != std::string::npos)
                  +  4*(m_effect.find("Defense skill +4.")      != std::string::npos)
                  +  5*(m_effect.find("Defense skill +5.")      != std::string::npos)
                  +  6*(m_effect.find("Defense skill +6.")      != std::string::npos)
                  +  7*(m_effect.find("Defense skill +7.")      != std::string::npos)
                  + 12*(m_effect.find("Defense skill +12.")     != std::string::npos);

    if( m_modify_power )
        m_power =  1*(m_effect.find("All primary skills +1.") != std::string::npos)
                +  2*(m_effect.find("All primary skills +2.") != std::string::npos)
                +  3*(m_effect.find("All primary skills +3.") != std::string::npos)
                +  4*(m_effect.find("All primary skills +4.") != std::string::npos)
                +  5*(m_effect.find("All primary skills +5.") != std::string::npos)
                +  6*(m_effect.find("All primary skills +6.") != std::string::npos)
                -  2*(m_effect.find("Power skill -2.")        != std::string::npos)
                +  1*(m_effect.find("Power skill +1.")        != std::string::npos)
                +  2*(m_effect.find("Power skill +2.")        != std::string::npos)
                +  3*(m_effect.find("Power skill +3.")        != std::string::npos)
                +  4*(m_effect.find("Power skill +4.")        != std::string::npos)
                +  5*(m_effect.find("Power skill +5.")        != std::string::npos)
                +  6*(m_effect.find("Power skill +6.")        != std::string::npos)
                + 10*(m_effect.find("Power skill +10.")       != std::string::npos);

    if( m_modify_knowledge )
        m_knowledge =  1*(m_effect.find("All primary skills +1.") != std::string::npos)
                    +  2*(m_effect.find("All primary skills +2.") != std::string::npos)
                    +  3*(m_effect.find("All primary skills +3.") != std::string::npos)
                    +  4*(m_effect.find("All primary skills +4.") != std::string::npos)
                    +  5*(m_effect.find("All primary skills +5.") != std::string::npos)
                    +  6*(m_effect.find("All primary skills +6.") != std::string::npos)
                    -  2*(m_effect.find("Knowledge skill -2.")     != std::string::npos)
                    +  1*(m_effect.find("Knowledge skill +1.")     != std::string::npos)
                    +  2*(m_effect.find("Knowledge skill +2.")     != std::string::npos)
                    +  3*(m_effect.find("Knowledge skill +3.")     != std::string::npos)
                    +  4*(m_effect.find("Knowledge skill +4.")     != std::string::npos)
                    +  5*(m_effect.find("Knowledge skill +5.")     != std::string::npos)
                    +  6*(m_effect.find("Knowledge skill +6.")     != std::string::npos)
                    + 10*(m_effect.find("Knowledge skill +10.")    != std::string::npos);

    if( m_modify_morale )
    {
        m_morale = 1*(m_effect.find("Morale +1.") != std::string::npos)
                 + 2*(m_effect.find("Morale +2.") != std::string::npos)
                 + 3*(m_effect.find("Morale +3.") != std::string::npos);

        m_decrease_enemy_morale = 1*(m_effect.find("Enemy morale -1.") != std::string::npos)
                                + 2*(m_effect.find("Enemy morale -2.") != std::string::npos);
    }


    if( m_modify_luck )
    {
        m_luck = 1*(m_effect.find("Luck +1.") != std::string::npos)
               + 2*(m_effect.find("Luck +2.") != std::string::npos)
               + 3*(m_effect.find("Luck +3.") != std::string::npos);

        m_decrease_enemy_luck = 1*(m_effect.find("Enemy luck -1.") != std::string::npos)
                              + 2*(m_effect.find("Enemy luck -2.") != std::string::npos);
    }

}

std::string Item::get_slot_as_string() const
{
    std::string slot;

    switch( get_slot() )
    {
        case Slot::Helmet   : slot = "Helmet";   break;
        case Slot::Cape     : slot = "Cape";     break;
        case Slot::Necklace : slot = "Necklace"; break;
        case Slot::Weapon   : slot = "Weapon";   break;
        case Slot::Shield   : slot = "Shield";   break;
        case Slot::Armor    : slot = "Armor";    break;
        case Slot::Hand     : slot = "Hand";     break;
        case Slot::Boots    : slot = "Boots";    break;
        case Slot::Pocket   : slot = "Pocket";   break;
    }
    return slot;
}

std::string Item::get_type_as_string() const
{
    std::string item_type;

    switch( get_type() )
    {
        case Type::None     : item_type = "None";     break;
        case Type::Treasure : item_type = "Treasure"; break;
        case Type::Minor    : item_type = "Minor";    break;
        case Type::Major    : item_type = "Major";    break;
        case Type::Relic    : item_type = "Relic";    break;
    }
    return item_type;
}

std::string Item::get_cost() const
{
    std::string str;

    if( cost.m_gold     )    str += "Gold : "     + std::to_string(cost.m_gold)     + '\n';
    if( cost.m_mercury  )    str += "Mercury : "  + std::to_string(cost.m_mercury)  + '\n';
    if( cost.m_sulfur   )    str += "Sulfur : "   + std::to_string(cost.m_sulfur)   + '\n';
    if( cost.m_crystals )    str += "Crystals : " + std::to_string(cost.m_crystals) + '\n';
    if( cost.m_gems     )    str += "Gems : "     + std::to_string(cost.m_gems)     + '\n';

    return str;
}

void Item::print_full_info() const
{
    printf( "\n" );
    printf( "Name : %s\n",     get_name().c_str() );
    printf( "Slot : %s\n",     get_slot_as_string().c_str() );
    printf( "Type : %s\n",     get_type_as_string().c_str() );
    printf( "AI Value : %d\n", get_ai_value() );
    printf( "Effect : %s\n",   get_effect().c_str() );
    printf( "Cost : %s\n",     get_cost().c_str()   );
}