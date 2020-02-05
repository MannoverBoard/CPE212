/**
 * cleric.cpp - CPE 212-01, Spring 2020 - Project02 - Class Inheritance
 */
#include "cleric.hpp"
#include "stuff.h"

using namespace std;
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
const Weapon STARTER_WEAPON{.name="Simple Wand", .damage=5, .cost=100};
const int DEFAULT_CHARACTERISTIC = 10;

// <rant>
// the cleric *has* an inventory, it isn't AN inventory...whatever...
// Also the fact that data is duplicated with the whole weapon inventory thing..
// if weapon is updated how does the inventory get updated!! this is a horrible design
// </rant>
Cleric::Cleric(const string& characterName, const Race characterRace) :
	Character(characterName, characterRace, static_cast<Action>(&Cleric::Heal))
{
	Weapon my_weapon = STARTER_WEAPON;
	willpower = DEFAULT_CHARACTERISTIC;
	SetHealth(DEFAULT_HEALTH);
	SetWeapon(my_weapon);
	AddToInventory(toItem(my_weapon));
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
Character& Cleric::Heal(Character& target) {
	const int points = rounding(10 + (willpower/2.),RoundingEvent::Player);
	if(GetVerbosity()>=Verbosity::Info) {
		cout<< GetName() << " heals " << target.GetName() << " for " << points << " points" << "\n";
	}
	target.TakeDamage(-points);
  return (*this);
}


/**
 * Status Function
 * Public method Status that prints out the Status of the Cleric
 * @attention You MUST print out the local Cleric variables.
 *  The format for the print must be "PrivateVar: PrivateVal" where the name of the private variable is capitalized
 * @example For the private variable luck which is set to 7 you would print the following
 *      "Luck: 7"
 */
void Cleric::Status_() const {
  cout << "Willpower: " << willpower << "\n";
}

/**
 * Attack Function
 * Public method of Cleric that attacks an target Character
 * @param target Pointer to the target Character
 * @attention Follow these instructions:
 *  1. The damage for a Cleric is calculated by the weapon damage + half the willpower value
 *  2. The target Character must take the damage dealt by the Cleric
 *  3. Please print out the details of the attack in the following format
 *      <Character Name> attacks <Target Name> with <Character's Weapon Name> for <damage> points
 */
Character& Cleric::Attack_(Character& target) {
	const auto weapon = GetWeapon();
	const int damage = rounding(weapon.damage + (willpower/2.),RoundingEvent::Player);
	if(GetVerbosity()>=Verbosity::Info) {
		cout<< GetName() << " attacks " << target.GetName() << " with " << weapon.name << " for " << damage << " points" << "\n";
	}
	target.TakeDamage(damage);
  return (*this);
}


