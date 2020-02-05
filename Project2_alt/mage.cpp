/**
 * mage.cpp - CPE 212-01, Spring 2020 - Project02 - Class Inheritance
 */
#include "mage.hpp"
#include "stuff.h"

using namespace std;
/**
 * Mage Class constructor
 * @param characterName The name of the character being created
 * @param characterRace The race of the character being created. This is a enum value.
 * @extends This constructor extends the base Character constructor
 * @attention Follow these instructions:
 *  Mage starts with 50 health
 *  Assign the starter weapon for the Mage
 *      Weapon
 *         name : "Simple Staff"
 *         cost : 100
 *         damage : 5
 *  Add the weapon to the Mage inventory
 *  Assign a value of 10 for the base Mage characteristic
 */
const int DEFAULT_HEALTH = 50;
const Weapon STARTER_WEAPON{.name="Simple Staff", .damage=5, .cost=100 };
const int DEFAULT_CHARACTERISTIC = 10;

Mage::Mage(const string& characterName, const Race characterRace) :
	Character(characterName, characterRace, static_cast<Action>(&Mage::Fireball))
{
	const auto& my_weapon = STARTER_WEAPON;
	intelligence = DEFAULT_CHARACTERISTIC;
	SetHealth(DEFAULT_HEALTH);
	SetWeapon(my_weapon);
	AddToInventory(toItem(my_weapon));
}

/**
 * Public method of Mage that sends a Fireball at an target Character
 * @param target Pointer to the target Character
 * @attention Follow these instructions:
 *  1. The damage for a Fireball is calculated by the base damage 10 + weapon damage + half the intelligence value
 *  2. The target Character must take the damage dealt by the Mage
 *  3. Please print out the details of the attack in the following format
 *      <Character Name> attacks <Target Name> with a Fireball for <damage> points
 */
Character& Mage::Fireball(Character& target) {
	const auto weapon = GetWeapon();
	const int damage = rounding(10 + weapon.damage + (intelligence/2.),RoundingEvent::Player);
	if(GetVerbosity()>=Verbosity::Info) {
		cout<< GetName() << " attacks " << target.GetName() << " with a Fireball for " << damage << " points" << "\n";
	}
	target.TakeDamage(damage);
  return (*this);
}


/**
 * Public method of Mage that attacks an target Character
 * @param target Pointer to the target Character
 * @attention Follow these instructions:
 *  1. The damage for a Mage is calculated by the weapon damage + half the intelligence value
 *  2. The target Character must take the damage dealt by the Mage
 *  3. Please print out the details of the attack in the following format
 *      <Character Name> attacks <Target Name> with <Character's Weapon Name> for <damage> points
 */
Character& Mage::Attack_(Character& target) {
	const auto weapon = GetWeapon();
	const int damage = rounding(weapon.damage + (intelligence/2.),RoundingEvent::Player);
	if(GetVerbosity()>=Verbosity::Info) {
		cout<< GetName() << " attacks " << target.GetName() << " with " << weapon.name << " for " << damage << " points" << "\n";
	}
	target.TakeDamage(damage);
  return (*this);
}

/**
 * Public method Status that prints out the Status of the Character
 * @attention You MUST print out the local Character variables.
 *  The format for the print must be "PrivateVar: PrivateVal" where the name of the private variable is capitalized
 * @example For the private variable luck which is set to 7 you would print the following
 *      "Luck: 7"
 */
void Mage::Status_() const {
  cout << "Intelligence: " << intelligence << "\n";
}
