/**
 * rogue.cpp - CPE 212-01, Spring 2020 - Project02 - Class Inheritance
 */
#include "rogue.hpp"
#include "stuff.h"

using namespace std;
/**
 * Rogue Class constructor
 * @param characterName The name of the character being created
 * @param characterRace The race of the character being created. This is a enum value.
 * @extends This constructor extends the base Character constructor
 * @attention Follow these instructions:
 *  ROGUE starts with 100 health
 *  Assign the starter weapon for the Rogue
 *      Weapon
 *         name : "Starter Daggers"
 *         cost : 100
 *         damage : 5
 *  Add the weapon to the Rogues inventory
 *  Assign a value of 10 for the base Rogue characteristic
 */

const int DEFAULT_HEALTH = 100;
const Weapon STARTER_WEAPON{.name="Starter Daggers", .damage=5, .cost=100 };
const int DEFAULT_CHARACTERISTIC = 10;

Rogue::Rogue(const string& characterName, const Race characterRace):
	Character(characterName, characterRace, static_cast<Action>(&Rogue::BackStab))
{
	Weapon my_weapon = STARTER_WEAPON;
	dexterity = DEFAULT_CHARACTERISTIC;
	SetHealth(DEFAULT_HEALTH);
	SetWeapon(my_weapon);
	AddToInventory(toItem(my_weapon));
}

/**
 * Public method of Rogue that Back Stabs a target Character
 * @param target Pointer to the Character to be healed
 * @attention Follow these instructions:
 *  1. The Back Stab damage for a Rogue is calculated by the weapon damage + base damage value 50 + half the dexterity value
 *  2. The target Character must take damage the amount dealt by the Rogue
 *  3. Please print out the details of the attack in the following format
 *      <Character Name> Back Stabs <Target Name> for <damage amount> points
 */
Character& Rogue::BackStab(Character& target) {
	const auto weapon = GetWeapon();
	const int damage = rounding(weapon.damage + 50 + (dexterity/2.),RoundingEvent::Player);
	if(GetVerbosity()>=Verbosity::Info) {
		cout<< GetName() << " Back Stabs " << target.GetName() << " for " << damage << " points" << "\n";
	}
	target.TakeDamage(damage);
  return (*this);
}

/**
 * Public method of Rogue that attacks an target Character
 * @param target Pointer to the target Character
 * @attention Follow these instructions:
 *  1. The damage for a Rogue is calculated by the weapon damage + half the dexterity value
 *  2. The target Character must take the damage dealt by the Rogue
 *  3. Please print out the details of the attack in the following format
 *      <Character Name> attacks <Target Name> with <Character's Weapon Name> for <damage> points
 */
Character& Rogue::Attack_(Character& target) {
	const auto weapon = GetWeapon();
	const int damage = rounding(weapon.damage + (dexterity/2.),RoundingEvent::Player);
	if(GetVerbosity()>=Verbosity::Info) {
    cout<< GetName() << " attacks " << target.GetName() << " with " << weapon.name << " for " << damage << " points" << "\n";
	}
	target.TakeDamage(damage);
  return (*this);
}

/**
 * Public method Status that prints out the Status of the Rogue
 * @attention You MUST print out the local Rogue variables.
 *  The format for the print must be "PrivateVar: PrivateVal" where the name of the private variable is capitalized
 * @example For the private variable luck which is set to 7 you would print the following
 *      "Luck: 7"
 */
void Rogue::Status_() const {
  cout << "Dexterity: " << dexterity << "\n";
}
