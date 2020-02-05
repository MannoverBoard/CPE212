/**
 * warrior.cpp - CPE 212-01, Spring 2020 - Project02 - Class Inheritance
 */
#include "warrior.hpp"
#include "stuff.h"

/**
 * Warrior Class constructor
 * @param characterName The name of the character being created
 * @param characterRace The race of the character being created. This is a enum value.
 * @extends This constructor extends the base Character constructor
 * @attention Follow these instructions:
 *  Warrior starts with 150 health
 *  Assign the starter weapon for the Warrior
 *      Weapon
 *         name : "Starter Longsword"
 *         cost : 100
 *         damage : 10
 *  Add the weapon to the Warriors inventory
 *  Assign a value of 10 for the base Warrior characteristic
 */
const int DEFAULT_HEALTH = 150;
const Weapon STARTER_WEAPON{.name="Starter Longsword", .damage=10, .cost=100 };
const int DEFAULT_CHARACTERISTIC = 10;

Warrior::Warrior(const string& characterName, const Race characterRace):
	Character(characterName, characterRace, &Warrior::PowerAttack), Inventory{}
{
	const auto& my_weapon = STARTER_WEAPON;
	strength = DEFAULT_CHARACTERISTIC;
	SetHealth(DEFAULT_HEALTH);
	SetWeapon(my_weapon);
	AddToInventory(toItem(my_weapon));
}

/**
 * Public method of Warrior that attacks an target Character
 * @param target Pointer to the target Character
 * @attention Follow these instructions:
 *  1. The damage for a Warrior is calculated by the weapon damage + half the strength value
 *  2. The target Character must take the damage dealt by the Warrior
 *  3. Please print out the details of the attack in the following format
 *      <Character Name> attacks <Target Name> with <Character's Weapon Name> for <damage> points
 */
void Warrior::Attack(Character& target) {
	const auto weapon = GetWeapon();
	const int damage = rounding(weapon.damage + (strength/2.),RoundingEvent::Player);
	target.TakeDamage(damage);
	if(verbose>=Verbosity::Info) {
		std::cout<< GetName() << " attacks " << target.GetName() << " with " << weapon.name << " for " << damage << " points" << "\n";
	}
}

/**
 * Public method of Warrior that deals a Power Attack to a target Character
 * @param target Pointer to the Character to be attacked
 * @attention Follow these instructions:
 *  1. The damage for a Power Attack is calculated by the health / 100 * (weapon damage + half the strength value)
 *  2. The target Character must take damage the amount dealt by the Warrior
 *  3. Please print out the details of the attack in the following format
 *      <Character Name> Power Attacks <Target Name> for <damage amount> points
 */
void Warrior::PowerAttack(Character& target) {
	const auto weapon = GetWeapon();
	const int damage = rounding(GetHealth()/100.*(weapon.damage + (strength/2.)),RoundingEvent::Player);
	target.TakeDamage(damage);
	if(verbose>=Verbosity::Info) {
		std::cout<< GetName() << " Power Attacks " << target.GetName() << " for " << damage << " points" << "\n";
	}
}

/**
 * Public method Status that prints out the Status of the Warrior
 * @attention You MUST print out the local Warrior variables.
 *  The format for the print must be "PrivateVar: PrivateVal" where the name of the private variable is capitalized
 * @example For the private variable luck which is set to 7 you would print the following
 *      "Luck: 7"
 */
void Warrior::Status() {
	Character::Status();
  if(verbose>=Verbosity::Info) {
		std::cout << "Strength: " << strength << "\n";
	}
}
