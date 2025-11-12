#ifndef ITEM_LIST_CPP
#define ITEM_LIST_CPP

#include "Item.h"
#include "../utilities/user_macros.h"

const std::map<Artifact, const Item*>& Item::create_and_fill_items_list()
{
    //                                                artifact,                                     slot,           type,           {  gold, m, s, c, g },  effect
    // Helmet
    static const Item Helm_of_Heavenly_Enlightenment( Artifact::Helm_of_Heavenly_Enlightenment, Item::Slot::Helmet,   Item::Type::Relic,    { 24000, 0, 0, 0, 0 }, "All primary skills +6." );

    // Cape
    static const Item Cape_of_Velocity(               Artifact::Cape_of_Velocity,               Item::Slot::Cape,     Item::Type::Major,    { 10000, 0, 0, 0, 0 }, "Unit's speed +2." );

    // Necklace
    static const Item Celestial_Necklace_of_Bliss(    Artifact::Celestial_Necklace_of_Bliss,    Item::Slot::Necklace, Item::Type::Relic,    { 12000, 0, 0, 0, 0 }, "All primary skills +3." );
    static const Item Necklace_of_Swiftness(          Artifact::Necklace_of_Swiftness,          Item::Slot::Necklace, Item::Type::Treasure, {  5000, 0, 0, 0, 0 }, "Unit's speed +1." );
    static const Item Pendant_of_Courage(             Artifact::Pendant_of_Courage,             Item::Slot::Necklace, Item::Type::Major,    {  7000, 0, 0, 0, 0 }, "Morale +3. Luck +3." );

    // Weapon
    static const Item Sword_of_Judgement(             Artifact::Sword_of_Judgement,             Item::Slot::Weapon,   Item::Type::Relic,    { 20000, 0, 0, 0, 0 }, "All primary skills +5." );
    // static const Item Angelic_Alliance(               Artifact::Angelic_Alliance,               Item::Slot::Weapon,   Item::Type::Relic,    { 84000, 0, 0, 0, 0 }, "All primary skills +21. Allows Rampart, Tower, Fortress, Stronghold and Castle creatures to be mixed without a morale penalty. Casts expert Prayer at the start of combat." );
    static const Item Centaurs_Axe(                    Artifact::Centaurs_Axe,                 Item::Slot::Weapon,   Item::Type::Treasure, {  2000, 0, 0, 0, 0 }, "Attack skill +2." );
    static const Item Red_Dragon_Flame_Tongue(         Artifact::Red_Dragon_Flame_Tongue,       Item::Slot::Weapon,   Item::Type::Minor,    {  4000, 0, 0, 0, 0 }, "Attack skill +2. Defense skill +2." );
    static const Item Blackshard_of_the_Dead_Knight(   Artifact::Blackshard_of_the_Dead_Knight, Item::Slot::Weapon,   Item::Type::Minor,    {  3000, 0, 0, 0, 0 }, "Attack skill +3." );
    // static const Item Armageddons_Blade(               Artifact::Armageddons_Blade,            Item::Slot::Weapon,   Item::Type::Relic,    { 50000, 0, 0, 0, 0 }, "Attack skill +3. Defense skill +3. Power skill +6. Knowledge skill +6. Adds Expert Armageddon spell to spellbook. Immune to Armageddon." );
    static const Item Greater_Gnolls_Flail(             Artifact::Greater_Gnolls_Flail,        Item::Slot::Weapon,   Item::Type::Minor,    {  4000, 0, 0, 0, 0 }, "Attack skill +4." );
    static const Item Ogres_Club_of_Havoc(              Artifact::Ogres_Club_of_Havoc,         Item::Slot::Weapon,   Item::Type::Major,    {  5000, 0, 0, 0, 0 }, "Attack skill +5." );
    static const Item Sword_of_Hellfire(                Artifact::Sword_of_Hellfire,            Item::Slot::Weapon,   Item::Type::Major,    {  6000, 0, 0, 0, 0 }, "Attack skill +6." );
    static const Item Trident_of_Dominion(              Artifact::Trident_of_Dominion,          Item::Slot::Weapon,   Item::Type::Major,    {  7000, 0, 0, 0, 0 }, "Attack skill +7." );
    static const Item Titans_Gladius(                   Artifact::Titans_Gladius,              Item::Slot::Weapon,   Item::Type::Relic,    { 10000, 0, 0, 0, 0 }, "Attack skill +12. Defense skill -3." );

    // Shield
    static const Item Lions_Shield_of_Courage(        Artifact::Lions_Shield_of_Courage,       Item::Slot::Shield,   Item::Type::Relic,    { 16000, 0, 0, 0, 0 }, "All primary skills +4." );
    static const Item Dragon_Scale_Shield(            Artifact::Dragon_Scale_Shield,            Item::Slot::Shield,   Item::Type::Major,    {  6000, 0, 0, 0, 0 }, "Attack skill +3. Defense skill +3." );
    static const Item Shield_of_the_Dwarven_Lords(    Artifact::Shield_of_the_Dwarven_Lords,    Item::Slot::Shield,   Item::Type::Treasure, {  2000, 0, 0, 0, 0 }, "Defense skill +2." );
    static const Item Shield_of_the_Yawning_Dead(     Artifact::Shield_of_the_Yawning_Dead,     Item::Slot::Shield,   Item::Type::Minor,    {  3000, 0, 0, 0, 0 }, "Defense skill +3." );
    static const Item Buckler_of_the_Gnoll_King(      Artifact::Buckler_of_the_Gnoll_King,      Item::Slot::Shield,   Item::Type::Minor,    {  4000, 0, 0, 0, 0 }, "Defense skill +4." );
    static const Item Targ_of_the_Rampaging_Ogre(     Artifact::Targ_of_the_Rampaging_Ogre,     Item::Slot::Shield,   Item::Type::Major,    {  5000, 0, 0, 0, 0 }, "Defense skill +5." );
    static const Item Shield_of_the_Damned(           Artifact::Shield_of_the_Damned,           Item::Slot::Shield,   Item::Type::Major,    {  6000, 0, 0, 0, 0 }, "Defense skill +6." );
    static const Item Shield_of_Naval_Glory(          Artifact::Shield_of_Naval_Glory,          Item::Slot::Shield,   Item::Type::Major,    {  7000, 0, 0, 0, 0 }, "Defense skill +7." );
    static const Item Sentinels_Shield(               Artifact::Sentinels_Shield,              Item::Slot::Shield,   Item::Type::Relic,    { 10000, 0, 0, 0, 0 }, "Defense skill +12. Attack skill -3." );

    // Armor
    static const Item Armor_of_Wonder(                Artifact::Armor_of_Wonder,                Item::Slot::Armor,    Item::Type::Minor,    {  4000, 0, 0, 0, 0 }, "All primary skills +1." );
    static const Item Dragon_Scale_Armor(             Artifact::Dragon_Scale_Armor,             Item::Slot::Armor,    Item::Type::Relic,    {  8000, 0, 0, 0, 0 }, "Attack skill +4. Defense skill +4." );
    // static const Item Plate_of_Dying_Light(           Artifact::Plate_of_Dying_Light,           Item::Slot::Armor,    Item::Type::Relic,    { 10000, 0, 0, 0, 0 }, "Enemy's Power skill -25%." );
    static const Item Breastplate_of_Petrified_Wood(  Artifact::Breastplate_of_Petrified_Wood,  Item::Slot::Armor,    Item::Type::Treasure, {  1000, 0, 0, 0, 0 }, "Power skill +1." );
    static const Item Rib_Cage(                       Artifact::Rib_Cage,                       Item::Slot::Armor,    Item::Type::Minor,    {  3000, 0, 0, 0, 0 }, "Power skill +2." );
    static const Item Scales_of_the_Greater_Basilisk( Artifact::Scales_of_the_Greater_Basilisk, Item::Slot::Armor,    Item::Type::Minor,    {  4000, 0, 0, 0, 0 }, "Power skill +3." );
    static const Item Tunic_of_the_Cyclops_King(      Artifact::Tunic_of_the_Cyclops_King,      Item::Slot::Armor,    Item::Type::Major,    {  5000, 0, 0, 0, 0 }, "Power skill +4." );
    static const Item Breastplate_of_Brimstone(       Artifact::Breastplate_of_Brimstone,       Item::Slot::Armor,    Item::Type::Major,    {  6000, 0, 0, 0, 0 }, "Power skill +5." );
    static const Item Royal_Armor_of_Nix(             Artifact::Royal_Armor_of_Nix,             Item::Slot::Armor,    Item::Type::Major,    {  7000, 0, 0, 0, 0 }, "Power skill +6." );
    static const Item Titans_Cuirass(                 Artifact::Titans_Cuirass,                Item::Slot::Armor,    Item::Type::Relic,    { 10000, 0, 0, 0, 0 }, "Power skill +10. Knowledge skill -2." );

    // Hand
    static const Item Quiet_Eye_of_the_Dragon(        Artifact::Quiet_Eye_of_the_Dragon,        Item::Slot::Hand,     Item::Type::Treasure, {  2000, 0, 0, 0, 0 }, "Attack skill +1. Defense skill +1." );
    static const Item Ring_of_Vitality(               Artifact::Ring_of_Vitality,               Item::Slot::Hand,     Item::Type::Treasure, {  5000, 0, 0, 0, 0 }, "Unit's health points +1." );
    static const Item Ring_of_Life(                   Artifact::Ring_of_Life,                   Item::Slot::Hand,     Item::Type::Minor,    {  5000, 0, 0, 0, 0 }, "Unit's health points +1." );
    static const Item Ring_of_Wayfarer(               Artifact::Ring_of_Wayfarer,               Item::Slot::Hand,     Item::Type::Major,    {  5000, 0, 0, 0, 0 }, "Unit's speed +1." );
    static const Item Still_Eye_of_the_Dragon(        Artifact::Still_Eye_of_the_Dragon,        Item::Slot::Hand,     Item::Type::Treasure, {  2000, 0, 0, 0, 0 }, "Morale +1. Luck +1." );
    static const Item Ring_of_Suppression(            Artifact::Ring_of_Suppression,            Item::Slot::Hand,     Item::Type::Treasure, {  4000, 0, 0, 0, 0 }, "Enemy morale -1." );

    // Boots
    static const Item Sandals_of_the_Saint(           Artifact::Sandals_of_the_Saint,           Item::Slot::Boots,    Item::Type::Relic,    {  8000, 0, 0, 0, 0 }, "All primary skills +2." );

    // Pocket
    static const Item Vial_of_Lifeblood(              Artifact::Vial_of_Lifeblood,              Item::Slot::Pocket,   Item::Type::Major,    { 10000, 0, 0, 0, 0 }, "Unit's health points +2." );
    // static const Item Elixir_of_Life(                 Artifact::Elixir_of_Life,                 Item::Slot::Pocket, Item::Type::Relic,    { 20000, 0, 0, 0, 0 }, "All creatures get a 25% health bonus and gain the regeneration ability. Does not work on Undead or unliving creatures." );
    static const Item Badge_of_Courage(               Artifact::Badge_of_Courage,               Item::Slot::Pocket,   Item::Type::Treasure, {  1000, 0, 0, 0, 0 }, "Morale +1." );
    static const Item Crest_of_Valor(                 Artifact::Crest_of_Valor,                 Item::Slot::Pocket,   Item::Type::Treasure, {  1000, 0, 0, 0, 0 }, "Morale +1." );
    static const Item Glyph_of_Gallantry(             Artifact::Glyph_of_Gallantry,             Item::Slot::Pocket,   Item::Type::Treasure, {  1000, 0, 0, 0, 0 }, "Morale +1." );
    static const Item Hideous_Mask(                   Artifact::Hideous_Mask,                   Item::Slot::Pocket,   Item::Type::Minor,    {  4000, 0, 0, 0, 0 }, "Enemy morale -1." );
    static const Item Pendant_of_Downfall(            Artifact::Pendant_of_Downfall,            Item::Slot::Pocket,   Item::Type::Major,    {  7000, 0, 0, 0, 0 }, "Enemy morale -2." );
    static const Item Spirit_of_Oppression(           Artifact::Spirit_of_Oppression,           Item::Slot::Pocket,   Item::Type::Treasure, {  2000, 0, 0, 0, 0 }, "Negates all positive morale bonuses during combat for both you and your opponent." );
    static const Item Cards_of_Prophecy(              Artifact::Cards_of_Prophecy,              Item::Slot::Pocket,   Item::Type::Treasure, {  1000, 0, 0, 0, 0 }, "Luck +1." );
    static const Item Clover_of_Fortune(              Artifact::Clover_of_Fortune,              Item::Slot::Pocket,   Item::Type::Treasure, {  1000, 0, 0, 0, 0 }, "Luck +1." );
    static const Item Ladybird_of_Luck(               Artifact::Ladybird_of_Luck,               Item::Slot::Pocket,   Item::Type::Treasure, {  1000, 0, 0, 0, 0 }, "Luck +1." );
    static const Item Runes_of_Imminency(             Artifact::Runes_of_Imminency,             Item::Slot::Pocket,   Item::Type::Treasure, {  2000, 0, 0, 0, 0 }, "Enemy luck -1." );
    static const Item Demons_Horseshoe(               Artifact::Demons_Horseshoe,              Item::Slot::Pocket,   Item::Type::Treasure, {  2000, 0, 0, 0, 0 }, "Enemy luck -1." );
    static const Item Shamans_Puppet(                 Artifact::Shamans_Puppet,                Item::Slot::Pocket,   Item::Type::Minor,    {  4000, 0, 0, 0, 0 }, "Enemy luck -2." );
    static const Item Hourglass_of_the_Evil_Hour(     Artifact::Hourglass_of_the_Evil_Hour,     Item::Slot::Pocket,   Item::Type::Treasure, {  2000, 0, 0, 0, 0 }, "Negates all positive luck bonuses during combat for both you and your opponent." );

    // TO DO : add all items

    static const std::map<Artifact, const Item*> Item_List =
    {
        // Helmet
        {Artifact::Helm_of_Heavenly_Enlightenment, &Helm_of_Heavenly_Enlightenment},

        // Cape
        {Artifact::Cape_of_Velocity, &Cape_of_Velocity},

        // Necklace
        {Artifact::Celestial_Necklace_of_Bliss, &Celestial_Necklace_of_Bliss},
        {Artifact::Necklace_of_Swiftness,       &Necklace_of_Swiftness},
        {Artifact::Pendant_of_Courage,          &Pendant_of_Courage},

        // Weapon
        {Artifact::Sword_of_Judgement,            &Sword_of_Judgement},
        // {Artifact::Angelic_Alliance,              &Angelic_Alliance},
        {Artifact::Centaurs_Axe,                  &Centaurs_Axe},
        {Artifact::Red_Dragon_Flame_Tongue,       &Red_Dragon_Flame_Tongue},
        {Artifact::Blackshard_of_the_Dead_Knight, &Blackshard_of_the_Dead_Knight},
        // {Artifact::Armageddons_Blade,             &Armageddons_Blade},
        {Artifact::Greater_Gnolls_Flail,          &Greater_Gnolls_Flail},
        {Artifact::Ogres_Club_of_Havoc,           &Ogres_Club_of_Havoc},
        {Artifact::Sword_of_Hellfire,             &Sword_of_Hellfire},
        {Artifact::Trident_of_Dominion,           &Trident_of_Dominion},
        {Artifact::Titans_Gladius,                &Titans_Gladius},

        // Shield
        {Artifact::Lions_Shield_of_Courage,     &Lions_Shield_of_Courage},
        {Artifact::Dragon_Scale_Shield,         &Dragon_Scale_Shield},
        {Artifact::Shield_of_the_Dwarven_Lords, &Shield_of_the_Dwarven_Lords},
        {Artifact::Shield_of_the_Yawning_Dead,  &Shield_of_the_Yawning_Dead},
        {Artifact::Buckler_of_the_Gnoll_King,   &Buckler_of_the_Gnoll_King},
        {Artifact::Targ_of_the_Rampaging_Ogre,  &Targ_of_the_Rampaging_Ogre},
        {Artifact::Shield_of_the_Damned,        &Shield_of_the_Damned},
        {Artifact::Shield_of_Naval_Glory,       &Shield_of_Naval_Glory},
        {Artifact::Sentinels_Shield,            &Sentinels_Shield},

        // Armor
        {Artifact::Armor_of_Wonder,                &Armor_of_Wonder},
        {Artifact::Dragon_Scale_Armor,             &Dragon_Scale_Armor},
        // {Artifact::Plate_of_Dying_Light,           &Plate_of_Dying_Light},
        {Artifact::Breastplate_of_Petrified_Wood,  &Breastplate_of_Petrified_Wood},
        {Artifact::Rib_Cage,                       &Rib_Cage},
        {Artifact::Scales_of_the_Greater_Basilisk, &Scales_of_the_Greater_Basilisk},
        {Artifact::Tunic_of_the_Cyclops_King,      &Tunic_of_the_Cyclops_King},
        {Artifact::Breastplate_of_Brimstone,       &Breastplate_of_Brimstone},
        {Artifact::Royal_Armor_of_Nix,             &Royal_Armor_of_Nix},
        {Artifact::Titans_Cuirass,                 &Titans_Cuirass},

        // Hand
        {Artifact::Quiet_Eye_of_the_Dragon, &Quiet_Eye_of_the_Dragon},
        {Artifact::Ring_of_Vitality,        &Ring_of_Vitality},
        {Artifact::Ring_of_Life,            &Ring_of_Life},
        {Artifact::Ring_of_Wayfarer,        &Ring_of_Wayfarer},
        {Artifact::Still_Eye_of_the_Dragon, &Still_Eye_of_the_Dragon},
        {Artifact::Ring_of_Suppression,     &Ring_of_Suppression},

        // Boots
        {Artifact::Sandals_of_the_Saint, &Sandals_of_the_Saint},

        // Pocket
        {Artifact::Vial_of_Lifeblood,          &Vial_of_Lifeblood},
        // {Artifact::Elixir_of_Life,             &Elixir_of_Life},
        {Artifact::Badge_of_Courage,           &Badge_of_Courage},
        {Artifact::Crest_of_Valor,             &Crest_of_Valor},
        {Artifact::Glyph_of_Gallantry,         &Glyph_of_Gallantry},
        {Artifact::Hideous_Mask,               &Hideous_Mask},
        {Artifact::Pendant_of_Downfall,        &Pendant_of_Downfall},
        {Artifact::Spirit_of_Oppression,       &Spirit_of_Oppression},
        {Artifact::Cards_of_Prophecy,          &Cards_of_Prophecy},
        {Artifact::Clover_of_Fortune,          &Clover_of_Fortune},
        {Artifact::Ladybird_of_Luck,           &Ladybird_of_Luck},
        {Artifact::Runes_of_Imminency,         &Runes_of_Imminency},
        {Artifact::Demons_Horseshoe,           &Demons_Horseshoe},
        {Artifact::Shamans_Puppet,             &Shamans_Puppet},
        {Artifact::Hourglass_of_the_Evil_Hour, &Hourglass_of_the_Evil_Hour}
    };

    ASSERT( created_items == Item_List.size(), "Item_List map is incomplete!" );

    return Item_List;
}

#endif