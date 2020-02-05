/**
 * goblin.cpp - CPE 212-01, Spring 2020 - Project02 - Class Inheritance
 */
#include "goblin.hpp"
#include "stuff.h"

/**
 * Goblin Class constructor
 * @param characterName The name of the character being created
 * @param characterRace The race of the character being created. This is a enum value.
 * @extends This constructor extends the base Character constructor
 * @attention Follow these instructions:
 *  Goblin starts with 30 health
 *  Assign the starter weapon for the Goblin
 *      Weapon
 *         name : "Pointy Stick"
 *         cost : 1
 *         damage : 3
 *  Add the weapon to the Goblins inventory
 *  Assign a value of 2 for the base Goblin characteristic
 */
const int DEFAULT_HEALTH = 30;
const Weapon STARTER_WEAPON{.name="Pointy Stick", .damage=3, .cost=1 };
const int DEFAULT_CHARACTERISTIC = 2;

Goblin::Goblin(const string& characterName, const Race characterRace) :
	Character(characterName, characterRace, &Goblin::SneakAttack), Inventory{}
{
	const auto& my_weapon = STARTER_WEAPON;
	attack = DEFAULT_CHARACTERISTIC;
	SetHealth(DEFAULT_HEALTH);
	SetWeapon(my_weapon);
	AddToInventory(toItem(my_weapon));
}

/**
 * Attack Function
 * Public method of Goblin that attacks an target Character
 * @param target Pointer to the target Character
 * @attention Follow these instructions:
 *  1. The damage for a Goblin is calculated by the weapon damage + half the attack value
 *  2. The target Character must take the damage dealt by the Goblin
 *  3. Please print out the details of the attack in the following format
 *      <Character Name> attacks <Target Name> with <Character's Weapon Name> for <damage> points
 */
void Goblin::Attack(Character& target) {
	const auto weapon = GetWeapon();
	const int damage = rounding(weapon.damage + (attack/2.),RoundingEvent::Player);
	target.TakeDamage(damage);
	if(verbose>=Verbosity::Info) {
		std::cout<< GetName() << " attacks " << target.GetName() << " with " << weapon.name << " for " << damage << " points" << "\n";
	}
}
/**
 * Sneak Attack Function
 * Public method of Goblin that Sneak Attacks a target Character
 * @param target Pointer to the Character to be healed
 * @attention Follow these instructions:
 *  1. The Sneak Attack damage for a Goblin is calculated by the base damage value 20 + half the attack value plus weapon damage
 *  2. The target Character must take damage the amount dealt by the Goblin
 *  3. Please print out the details of the attack in the following format
 *      <Character Name> Sneak Attacks <Target Name> for <damage amount> points
 */
void Goblin::SneakAttack(Character&  target) {
	const auto weapon = GetWeapon();
	const int damage = rounding(weapon.damage + 20 + (attack/2.),RoundingEvent::Player);
	target.TakeDamage(damage);
	if(verbose>=Verbosity::Info) {
		std::cout<< GetName() << " Sneak Attacks " << target.GetName() << " for " << damage << " points" << "\n";
	}
}

/**
 * Status Function
 * Public method Status that prints out the Status of the Goblin
 * @attention You MUST print out the local Goblin variables.
 *  The format for the print must be "PrivateVar: PrivateVal" where the name of the private variable is capitalized
 * @example For the private variable luck which is set to 7 you would print the following
 *      "Luck: 7"
 */
void Goblin::Status() {
	Character::Status();
	if(verbose>=Verbosity::Info) {
	  std::cout << "Attack: " << attack << "\n";
	}
}
