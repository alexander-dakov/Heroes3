#include "Item.h"
#include "../utilities/user_macros.h"

uint8_t Item::created_items = 0;

Item::Item( const Artifact artifact, const Slot slot, const Type item_type, const Resources& resources, const std::string& effect ) :
            m_artifact(artifact), m_slot(slot), m_item_type(item_type), cost(resources), effects(effect)
{
    set_name_from_enum();

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

Item::Item( const Spell& spellscroll, const Resources& resources ) :
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

void Item::set_name_from_enum()
{
    switch( this->m_artifact )
    {
        // Helmet
        case Artifact::Helm_of_Heavenly_Enlightenment : m_name = "Helm_of_Heavenly_Enlightenment"; break;

        // Cape
        case Artifact::Cape_of_Velocity : m_name = "Cape_of_Velocity"; break;

        // Necklace
        case Artifact::Celestial_Necklace_of_Bliss : m_name = "Celestial_Necklace_of_Bliss"; break;
        case Artifact::Necklace_of_Swiftness       : m_name = "Necklace_of_Swiftness";       break;
        case Artifact::Pendant_of_Courage          : m_name = "Pendant_of_Courage";          break;

        // Weapon
        case Artifact::Sword_of_Judgement            : m_name = "Sword_of_Judgement";            break;
        case Artifact::Angelic_Alliance              : m_name = "Angelic_Alliance";              break;
        case Artifact::Centaurs_Axe                  : m_name = "Centaurs_Axe";                  break;
        case Artifact::Red_Dragon_Flame_Tongue       : m_name = "Red_Dragon_Flame_Tongue";       break;
        case Artifact::Blackshard_of_the_Dead_Knight : m_name = "Blackshard_of_the_Dead_Knight"; break;
        case Artifact::Armageddons_Blade             : m_name = "Armageddons_Blade";             break;
        case Artifact::Greater_Gnolls_Flail          : m_name = "Greater_Gnolls_Flail";          break;
        case Artifact::Ogres_Club_of_Havoc           : m_name = "Ogres_Club_of_Havoc";           break;
        case Artifact::Sword_of_Hellfire             : m_name = "Sword_of_Hellfire";             break;
        case Artifact::Trident_of_Dominion           : m_name = "Trident_of_Dominion";           break;
        case Artifact::Titans_Gladius                : m_name = "Titans_Gladius";                break;

        // Shield
        case Artifact::Lions_Shield_of_Courage     : m_name = "Lions_Shield_of_Courage";     break;
        case Artifact::Dragon_Scale_Shield         : m_name = "Dragon_Scale_Shield";         break;
        case Artifact::Shield_of_the_Dwarven_Lords : m_name = "Shield_of_the_Dwarven_Lords"; break;
        case Artifact::Shield_of_the_Yawning_Dead  : m_name = "Shield_of_the_Yawning_Dead";  break;
        case Artifact::Buckler_of_the_Gnoll_King   : m_name = "Buckler_of_the_Gnoll_King";   break;
        case Artifact::Targ_of_the_Rampaging_Ogre  : m_name = "Targ_of_the_Rampaging_Ogre";  break;
        case Artifact::Shield_of_the_Damned        : m_name = "Shield_of_the_Damned";        break;
        case Artifact::Shield_of_Naval_Glory       : m_name = "Shield_of_Naval_Glory";       break;
        case Artifact::Sentinels_Shield            : m_name = "Sentinels_Shield";            break;

        // Armor
        case Artifact::Armor_of_Wonder                : m_name = "Armor_of_Wonder";                break;
        case Artifact::Dragon_Scale_Armor             : m_name = "Dragon_Scale_Armor";             break;
        case Artifact::Plate_of_Dying_Light           : m_name = "Plate_of_Dying_Light";           break;
        case Artifact::Breastplate_of_Petrified_Wood  : m_name = "Breastplate_of_Petrified_Wood";  break;
        case Artifact::Rib_Cage                       : m_name = "Rib_Cage";                       break;
        case Artifact::Scales_of_the_Greater_Basilisk : m_name = "Scales_of_the_Greater_Basilisk"; break;
        case Artifact::Tunic_of_the_Cyclops_King      : m_name = "Tunic_of_the_Cyclops_King";      break;
        case Artifact::Breastplate_of_Brimstone       : m_name = "Breastplate_of_Brimstone";       break;
        case Artifact::Royal_Armor_of_Nix             : m_name = "Royal_Armor_of_Nix";             break;
        case Artifact::Titans_Cuirass                 : m_name = "Titans_Cuirass";                 break;

        // Hand
        case Artifact::Quiet_Eye_of_the_Dragon : m_name = "Quiet_Eye_of_the_Dragon"; break;
        case Artifact::Ring_of_Vitality        : m_name = "Ring_of_Vitality";        break;
        case Artifact::Ring_of_Life            : m_name = "Ring_of_Life";            break;
        case Artifact::Ring_of_Wayfarer        : m_name = "Ring_of_Wayfarer";        break;
        case Artifact::Still_Eye_of_the_Dragon : m_name = "Still_Eye_of_the_Dragon"; break;
        case Artifact::Ring_of_Suppression     : m_name = "Ring_of_Suppression";     break;

        // Boots
        case Artifact::Sandals_of_the_Saint : m_name = "Sandals_of_the_Saint"; break;

        // Pocket
        case Artifact::Vial_of_Lifeblood          : m_name = "Vial_of_Lifeblood";          break;
        case Artifact::Elixir_of_Life             : m_name = "Elixir_of_Life";             break;
        case Artifact::Badge_of_Courage           : m_name = "Badge_of_Courage";           break;
        case Artifact::Crest_of_Valor             : m_name = "Crest_of_Valor";             break;
        case Artifact::Glyph_of_Gallantry         : m_name = "Glyph_of_Gallantry";         break;
        case Artifact::Hideous_Mask               : m_name = "Hideous_Mask";               break;
        case Artifact::Pendant_of_Downfall        : m_name = "Pendant_of_Downfall";        break;
        case Artifact::Spirit_of_Oppression       : m_name = "Spirit_of_Oppression";       break;
        case Artifact::Cards_of_Prophecy          : m_name = "Cards_of_Prophecy";          break;
        case Artifact::Clover_of_Fortune          : m_name = "Clover_of_Fortune";          break;
        case Artifact::Ladybird_of_Luck           : m_name = "Ladybird_of_Luck";           break;
        case Artifact::Runes_of_Imminency         : m_name = "Runes_of_Imminency";         break;
        case Artifact::Demons_Horseshoe           : m_name = "Demons_Horseshoe";           break;
        case Artifact::Shamans_Puppet             : m_name = "Shamans_Puppet";             break;
        case Artifact::Hourglass_of_the_Evil_Hour : m_name = "Hourglass_of_the_Evil_Hour"; break;
    }
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