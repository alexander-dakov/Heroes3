#ifndef ITEM_LIST_CPP
#define ITEM_LIST_CPP

#include "Item.h"
#include "../utilities/user_macros.h"

const std::map<Artifact, const Item*>& Item::create_and_fill_items_list()
{
    //                                    name,                            slot,           type,           {  gold, m, s, c, g },  effect
    // Helmet
    static const Item Helm_of_Heavenly_Enlightenment( "Helm of Heavenly Enlightenment", Item::Slot::Helmet,   Item::Type::Relic,    { 24000, 0, 0, 0, 0 }, "All primary skills +6." );

    // Cape
    static const Item Cape_of_Velocity(               "Cape of Velocity",               Item::Slot::Cape,     Item::Type::Major,    { 10000, 0, 0, 0, 0 }, "Unit's speed +2." );

    // Necklace
    static const Item Celestial_Necklace_of_Bliss(    "Celestial Necklace of Bliss",    Item::Slot::Necklace, Item::Type::Relic,    { 12000, 0, 0, 0, 0 }, "All primary skills +3." );
    static const Item Necklace_of_Swiftness(          "Necklace of Swiftness",          Item::Slot::Necklace, Item::Type::Treasure, {  5000, 0, 0, 0, 0 }, "Unit's speed +1." );
    static const Item Pendant_of_Courage(             "Pendant of Courage",             Item::Slot::Necklace, Item::Type::Major,    {  7000, 0, 0, 0, 0 }, "Morale +3. Luck +3." );

    // Weapon
    static const Item Sword_of_Judgement(             "Sword of Judgement",             Item::Slot::Weapon,   Item::Type::Relic,    { 20000, 0, 0, 0, 0 }, "All primary skills +5." );
    // static const Item Angelic_Alliance(               "Angelic Alliance",               Item::Slot::Weapon,   Item::Type::Relic,    { 84000, 0, 0, 0, 0 }, "All primary skills +21. Allows Rampart, Tower, Fortress, Stronghold and Castle creatures to be mixed without a morale penalty. Casts expert Prayer at the start of combat." );
    static const Item Centaurs_Axe(                    "Centaur's Axe",                 Item::Slot::Weapon,   Item::Type::Treasure, {  2000, 0, 0, 0, 0 }, "Attack skill +2." );
    static const Item Red_Dragon_Flame_Tongue(         "Red Dragon Flame Tongue",       Item::Slot::Weapon,   Item::Type::Minor,    {  4000, 0, 0, 0, 0 }, "Attack skill +2. Defense skill +2." );
    static const Item Blackshard_of_the_Dead_Knight(   "Blackshard of the Dead Knight", Item::Slot::Weapon,   Item::Type::Minor,    {  3000, 0, 0, 0, 0 }, "Attack skill +3." );
    // static const Item Armageddons_Blade(               "Armageddon's Blade",            Item::Slot::Weapon,   Item::Type::Relic,    { 50000, 0, 0, 0, 0 }, "Attack skill +3. Defense skill +3. Power skill +6. Knowledge skill +6. Adds Expert Armageddon spell to spellbook. Immune to Armageddon." );
    static const Item Greater_Gnolls_Flail(             "Greater Gnoll's Flail",        Item::Slot::Weapon,   Item::Type::Minor,    {  4000, 0, 0, 0, 0 }, "Attack skill +4." );
    static const Item Ogres_Club_of_Havoc(              "Ogre's Club of Havoc",         Item::Slot::Weapon,   Item::Type::Major,    {  5000, 0, 0, 0, 0 }, "Attack skill +5." );
    static const Item Sword_of_Hellfire(                "Sword of Hellfire",            Item::Slot::Weapon,   Item::Type::Major,    {  6000, 0, 0, 0, 0 }, "Attack skill +6." );
    static const Item Trident_of_Dominion(              "Trident of Dominion",          Item::Slot::Weapon,   Item::Type::Major,    {  7000, 0, 0, 0, 0 }, "Attack skill +7." );
    static const Item Titans_Gladius(                   "Titan's Gladius",              Item::Slot::Weapon,   Item::Type::Relic,    { 10000, 0, 0, 0, 0 }, "Attack skill +12. Defense skill -3." );

    // Shield
    static const Item Lions_Shield_of_Courage(        "Lion's Shield of Courage",       Item::Slot::Shield,   Item::Type::Relic,    { 16000, 0, 0, 0, 0 }, "All primary skills +4." );
    static const Item Dragon_Scale_Shield(            "Dragon Scale Shield",            Item::Slot::Shield,   Item::Type::Major,    {  6000, 0, 0, 0, 0 }, "Attack skill +3. Defense skill +3." );
    static const Item Shield_of_the_Dwarven_Lords(    "Shield of the Dwarven Lords",    Item::Slot::Shield,   Item::Type::Treasure, {  2000, 0, 0, 0, 0 }, "Defense skill +2." );
    static const Item Shield_of_the_Yawning_Dead(     "Shield of the Yawning Dead",     Item::Slot::Shield,   Item::Type::Minor,    {  3000, 0, 0, 0, 0 }, "Defense skill +3." );
    static const Item Buckler_of_the_Gnoll_King(      "Buckler of the Gnoll King",      Item::Slot::Shield,   Item::Type::Minor,    {  4000, 0, 0, 0, 0 }, "Defense skill +4." );
    static const Item Targ_of_the_Rampaging_Ogre(     "Targ of the Rampaging Ogre",     Item::Slot::Shield,   Item::Type::Major,    {  5000, 0, 0, 0, 0 }, "Defense skill +5." );
    static const Item Shield_of_the_Damned(           "Shield of the Damned",           Item::Slot::Shield,   Item::Type::Major,    {  6000, 0, 0, 0, 0 }, "Defense skill +6." );
    static const Item Shield_of_Naval_Glory(          "Shield of Naval Glory",          Item::Slot::Shield,   Item::Type::Major,    {  7000, 0, 0, 0, 0 }, "Defense skill +7." );
    static const Item Sentinels_Shield(               "Sentinel's Shield",              Item::Slot::Shield,   Item::Type::Relic,    { 10000, 0, 0, 0, 0 }, "Defense skill +12. Attack skill -3." );

    // Armor
    static const Item Armor_of_Wonder(                "Armor of Wonder",                Item::Slot::Armor,    Item::Type::Minor,    {  4000, 0, 0, 0, 0 }, "All primary skills +1." );
    static const Item Dragon_Scale_Armor(             "Dragon Scale Armor",             Item::Slot::Armor,    Item::Type::Relic,    {  8000, 0, 0, 0, 0 }, "Attack skill +4. Defense skill +4." );
    // static const Item Plate_of_Dying_Light(           "Plate of Dying Light",           Item::Slot::Armor,    Item::Type::Relic,    { 10000, 0, 0, 0, 0 }, "Enemy's Power skill -25%." );
    static const Item Breastplate_of_Petrified_Wood(  "Breastplate of Petrified Wood",  Item::Slot::Armor,    Item::Type::Treasure, {  1000, 0, 0, 0, 0 }, "Power skill +1." );
    static const Item Rib_Cage(                       "Rib Cage",                       Item::Slot::Armor,    Item::Type::Minor,    {  3000, 0, 0, 0, 0 }, "Power skill +2." );
    static const Item Scales_of_the_Greater_Basilisk( "Scales of the Greater Basilisk", Item::Slot::Armor,    Item::Type::Minor,    {  4000, 0, 0, 0, 0 }, "Power skill +3." );
    static const Item Tunic_of_the_Cyclops_King(      "Tunic of the Cyclops King",      Item::Slot::Armor,    Item::Type::Major,    {  5000, 0, 0, 0, 0 }, "Power skill +4." );
    static const Item Breastplate_of_Brimstone(       "Breastplate of Brimstone",       Item::Slot::Armor,    Item::Type::Major,    {  6000, 0, 0, 0, 0 }, "Power skill +5." );
    static const Item Royal_Armor_of_Nix(             "Royal Armor of Nix",             Item::Slot::Armor,    Item::Type::Major,    {  7000, 0, 0, 0, 0 }, "Power skill +6." );
    static const Item Titans_Cuirass(                 "Titan's Cuirass",                Item::Slot::Armor,    Item::Type::Relic,    { 10000, 0, 0, 0, 0 }, "Power skill +10. Knowledge skill -2." );

    // Hand
    static const Item Quiet_Eye_of_the_Dragon(        "Quiet Eye of the Dragon",        Item::Slot::Hand,     Item::Type::Treasure, {  2000, 0, 0, 0, 0 }, "Attack skill +1. Defense skill +1." );
    static const Item Ring_of_Vitality(               "Ring of Vitality",               Item::Slot::Hand,     Item::Type::Treasure, {  5000, 0, 0, 0, 0 }, "Unit's health points +1." );
    static const Item Ring_of_Life(                   "Ring of Life",                   Item::Slot::Hand,     Item::Type::Minor,    {  5000, 0, 0, 0, 0 }, "Unit's health points +1." );
    static const Item Ring_of_Wayfarer(               "Ring of Wayfarer",               Item::Slot::Hand,     Item::Type::Major,    {  5000, 0, 0, 0, 0 }, "Unit's speed +1." );
    static const Item Still_Eye_of_the_Dragon(        "Still Eye of the Dragon",        Item::Slot::Hand,     Item::Type::Treasure, {  2000, 0, 0, 0, 0 }, "Morale +1. Luck +1." );
    static const Item Ring_of_Suppression(            "Ring of Suppression",            Item::Slot::Hand,     Item::Type::Treasure, {  4000, 0, 0, 0, 0 }, "Enemy morale -1." );

    // Boots
    static const Item Sandals_of_the_Saint(           "Sandals of the Saint",           Item::Slot::Boots,    Item::Type::Relic,    {  8000, 0, 0, 0, 0 }, "All primary skills +2." );

    // Pocket
    static const Item Vial_of_Lifeblood(              "Vial of Lifeblood",              Item::Slot::Pocket,   Item::Type::Major,    { 10000, 0, 0, 0, 0 }, "Unit's health points +2." );
    // static const Item Elixir_of_Life(                 "Elixir of Life",                 Item::Slot::Pocket, Item::Type::Relic,    { 20000, 0, 0, 0, 0 }, "All creatures get a 25% health bonus and gain the regeneration ability. Does not work on Undead or unliving creatures." );
    static const Item Badge_of_Courage(               "Badge of Courage",               Item::Slot::Pocket,   Item::Type::Treasure, {  1000, 0, 0, 0, 0 }, "Morale +1." );
    static const Item Crest_of_Valor(                 "Crest of Valor",                 Item::Slot::Pocket,   Item::Type::Treasure, {  1000, 0, 0, 0, 0 }, "Morale +1." );
    static const Item Glyph_of_Gallantry(             "Glyph of Gallantry",             Item::Slot::Pocket,   Item::Type::Treasure, {  1000, 0, 0, 0, 0 }, "Morale +1." );
    static const Item Hideous_Mask(                   "Hideous Mask",                   Item::Slot::Pocket,   Item::Type::Minor,    {  4000, 0, 0, 0, 0 }, "Enemy morale -1." );
    static const Item Pendant_of_Downfall(            "Pendant of Downfall",            Item::Slot::Pocket,   Item::Type::Major,    {  7000, 0, 0, 0, 0 }, "Enemy morale -2." );
    static const Item Spirit_of_Oppression(           "Spirit of Oppression",           Item::Slot::Pocket,   Item::Type::Treasure, {  2000, 0, 0, 0, 0 }, "Negates all positive morale bonuses during combat for both you and your opponent." );
    static const Item Cards_of_Prophecy(              "Cards of Prophecy",              Item::Slot::Pocket,   Item::Type::Treasure, {  1000, 0, 0, 0, 0 }, "Luck +1." );
    static const Item Clover_of_Fortune(              "Clover of Fortune",              Item::Slot::Pocket,   Item::Type::Treasure, {  1000, 0, 0, 0, 0 }, "Luck +1." );
    static const Item Ladybird_of_Luck(               "Ladybird of Luck",               Item::Slot::Pocket,   Item::Type::Treasure, {  1000, 0, 0, 0, 0 }, "Luck +1." );
    static const Item Runes_of_Imminency(             "Runes of Imminency",             Item::Slot::Pocket,   Item::Type::Treasure, {  2000, 0, 0, 0, 0 }, "Enemy luck -1." );
    static const Item Demons_Horseshoe(               "Demon's Horseshoe",              Item::Slot::Pocket,   Item::Type::Treasure, {  2000, 0, 0, 0, 0 }, "Enemy luck -1." );
    static const Item Shamans_Puppet(                 "Shaman's Puppet",                Item::Slot::Pocket,   Item::Type::Minor,    {  4000, 0, 0, 0, 0 }, "Enemy luck -2." );
    static const Item Hourglass_of_the_Evil_Hour(     "Hourglass of the Evil Hour",     Item::Slot::Pocket,   Item::Type::Treasure, {  2000, 0, 0, 0, 0 }, "Negates all positive luck bonuses during combat for both you and your opponent." );

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