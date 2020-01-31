/**
 * mage.cpp - CPE 212-01, Spring 2020 - Project02 - Class Inheritance
 */
#include "mage.hpp"

/**
 * Mage Class constructor
 * @param characterName The name of the character being created
 * @param characterRace The race of the character being created. This is a enum value.
 * @extends This constructor extends the base Character constructor
 * @attention Follow these instructions:
 *  Mage starts with 50 health
 *  Assign the starter weapon for the Cleric
 *      Weapon
 *         name : "Simple Staff"
 *         cost : 100
 *         damage : 5
 *  Add the weapon to the Mage inventory
 *  Assign a value of 10 for the base Mage characteristic
 */
Mage::Mage(string characterName, Race characterRace) :
Character(characterName, characterRace), Inventory()
{
    intelligence = 10;
    const Weapon Starter_Weapon{.name = "Simple Staff", .damage = 5, .cost = 100};
    // Weapon is initialized using an initializer list
    
    SetHealth(50);
    SetWeapon(Starter_Weapon);

    AddToInventory(Item{.name=Starter_Weapon.name,
        .value = Starter_Weapon.cost, .type = WEAPON});
}
/**
 * Public method of Mage that attacks an enemy Character
 * @param enemy Pointer to the enemy Character
 * @attention Follow these instructions:
 *  1. The damage for a Mage is calculated by the weapon damage + half the intelligence value
 *  2. The enemy Character must take the damage dealt by the Mage
 *  3. Please print out the details of the attack in the following format
 *      <Character Name> attacks <Enemy Name> with <Character's Weapon Name> for <damage> points
 */
void Mage::Attack(Character * target) {
    if(target==nullptr) {return;};
    const int damage = GetWeapon().damage + intelligence/2;
    target.TakeDamage(damage);
    cout << GetName(Character) << " attacks " << GetName(*target) << " for " <<
        damage << " points!";
}
/**
 * Public method of Mage that sends a Fireball at an enemy Character
 * @param enemy Pointer to the enemy Character
 * @attention Follow these instructions:
 *  1. The damage for a Fireball is calculated by the base damage 10 + weapon damage + half the intelligence value
 *  2. The enemy Character must take the damage dealt by the Mage
 *  3. Please print out the details of the attack in the following format
 *      <Character Name> attacks <Enemy Name> with a Fireball for <damage> points
 */
void Mage::Fireball(Character * target) {
    if(target==nullptr) {return;};   // cool kids check pointers
    const int damage = 10 + GetWeapon().damage + intelligence/2;
    target->TakeDamage(damage);
    cout << GetName(Character) << " attacks " << GetName(*target) << " with a Fireball for " <<
        damage << " points!";
    
}
/**
 * Public method Status that prints out the Status of the Cleric
 * @attention You MUST print out the local Cleric variables.
 *  The format for the print must be "PrivateVar: PrivateVal" where the name of the private variable is capitalized
 * @example For the private variable luck which is set to 7 you would print the following
 *      "Luck: 7"
 */
void Mage::Status() {
    cout << "Name: "         << GetName();
    cout << "Race: "         << GetRace();
    cout << "Weapon: "       << GetWeapon;
    cout << "Health: "       << GetHealth();
    cout << "Level: "        << GetLevel();
    cout << "Exp: "          << GetExp();
    cout << "Intelligence: " << intelligence;
}
}