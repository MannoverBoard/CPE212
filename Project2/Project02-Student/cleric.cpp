/**
 * cleric.cpp - CPE 212-01, Spring 2020 - Project02 - Class Inheritance
 */
#include "cleric.hpp"
#include "stuff.h"

/**
 * Cleric Class constructor
 * @param characterName The name of the character being created
 * @param characterRace The race of the character being created. This is a enum value.
 * @extends This constructor extends the base Character constructor
 * @attention Follow these instructions:
 *  Cleric starts with 50 health
 *  Assign the starter weapon for the Cleric
 *      Weapon
 *         name : "Simple Wand"
 *         cost : 100
 *         damage : 5
 *  Add the weapon to the Clerics inventory
 *  Assign a value of 10 for the base Cleric characteristic
 */
const int DEFAULT_HEALTH = 50;
const Weapon STARTER_WEAPON{.name="Simple Wand",.damage=5,.cost=100};
const int DEFAULT_CHARACTERISTIC = 10;

// <rant>
// the cleric *has* an inventory, it isn't AN inventory...whatever...
// Also the fact that data is duplicated with the whole weapon inventory thing.. 
// if weapon is updated how does the inventory get updated!! this is a horrible design
// </rant>
Cleric::Cleric(string characterName, Race characterRace): Character(characterName,characterRace), Inventory{}
{
	Weapon my_weapon = STARTER_WEAPON;
	willpower = DEFAULT_CHARACTERISTIC;
	SetHealth(DEFAULT_HEALTH);
	SetWeapon(my_weapon);
	AddToInventory(toItem(my_weapon));
}

// <rant>
// Why are these .cpp comments in a different order than the .h file? Where is the consistency? Not that it matters really
// </rant>

/**
 * Status Function
 * Public method Status that prints out the Status of the Cleric
 * @attention You MUST print out the local Cleric variables.
 *  The format for the print must be "PrivateVar: PrivateVal" where the name of the private variable is capitalized
 * @example For the private variable luck which is set to 7 you would print the following
 *      "Luck: 7"
 */
void Cleric::Status() {
	std::cout << "TODO" << "\n";
}

/** 
 * Attack Function
 * Public method of Cleric that attacks an enemy Character
 * @param enemy Pointer to the enemy Character
 * @attention Follow these instructions:
 *  1. The damage for a Cleric is calculated by the weapon damage + half the willpower value
 *  2. The enemy Character must take the damage dealt by the Cleric
 *  3. Please print out the details of the attack in the following format
 *      <Character Name> attacks <Enemy Name> with <Character's Weapon Name> for <damage> points
 */
void Cleric::Attack(Character * enemy) {
	if(enemy==nullptr) { return; } //TODO ERROR: Should an error be logged here?
	const auto weapon = GetWeapon();
	const int damage = (weapon.damage + (willpower/2));//TODO LOGIC: Is default value in D&D to round down fractions..
	enemy->TakeDamage(damage);
	std::cout<< GetName() << " attacks " << enemy->GetName() << " with " << weapon.name << " for " << damage << " points" << "\n";
	//TODO PRINTING: what is the convention here for trailing newlines.
}




/** 
 * Heal Function
 * Public method of Cleric that heals a target Character
 * @param target Pointer to the Character to be healed
 * @attention Follow these instructions:
 *  1. The heal amount for a Cleric is calculated by the base heal value 10 + half the willpower value
 *  2. The target Character must heal the amount dealt by the Cleric
 *  3. Please print out the details of the attack in the following format
 *      <Character Name> heals <Target Name> for <heal amount> points
 */
void Cleric::Heal(Character * target) {
	if(target==nullptr) { return; } //TODO ERROR: Should an error be logged here?
	const int points = (10+(willpower/2));
	//TODO LOGIC: Is default value in D&D to round down fractions..
	target->TakeDamage(points);
	std::cout<< GetName() << " heals " << target->GetName() << " for " << points << " points" << "\n";
	//TODO PRINTING: what is the convention here for trailing newlines.
}	
