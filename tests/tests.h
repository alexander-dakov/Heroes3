#ifndef TESTS_H
#define TESTS_H

#include "../source/Battle.h"
#include "../source/Creature.h"
#include "../source/Creature_Stack.cpp"
#include "../source/Hero_List.cpp"
#include "../source/Item.h"

// Flushes std::cout and std::cerr and prints a message in order to mark the output of a test.
void print_before_testing_output();

// Prints which of the some of the many special abilities a certain creature has.
void print_some_special_abilities(const Creature* const c);

// Constructs enough different instances of class Stack to fill all of the hero's army slots.
void test_create_creature_stack();

// Checks if hero's stats get hero bonuses when : hero levels up / gets updated morale and luck / equips an item / unequips an item.
void test_hero_item_bonuses();

// Checks if creature stacks' battle stats get hero bonuses when they : become part of the army / are removed from the army / hero levels up / gets updated morale and luck / equips an item / unequips an item.
void test_army_hero_bonuses();

// Constructs an instance of Battle by : creating a field, positioning the armies with their bonuses from their respective heroes on said field and applying terrain bonuses to the stacks. Afterwards the battle begins.
void test_battle();

#endif