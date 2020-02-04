/**
 * warrior.cpp - CPE 212-01, Spring 2020 - Project02 - Class Inheritance
 */
#include "warrior.hpp"

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
Warrior::Warrior(string characterName, Race characterRace) :
Character(characterName, characterRace), Inventory()
{
    
    const Weapon Starter_Weapon{.name = "Starter Longsword", .damage = 10, .cost = 100};
    // Weapon is initialized using an initialization list

    strength = 10;

    SetHealth(150);
    SetWeapon(Starter_Weapon);

    AddToInventory(Item{.name=Starter_Weapon.name,
        .value = static_cast<float>(Starter_Weapon.cost), .type = WEAPON});
}
/**
 * Public method of Warrior that attacks an enemy Character
 * @param enemy Pointer to the enemy Character
 * @attention Follow these instructions:
 *  1. The damage for a Warrior is calculated by the weapon damage + half the strength value
 *  2. The enemy Character must take the damage dealt by the Warrior
 *  3. Please print out the details of the attack in the following format
 *      <Character Name> attacks <Enemy Name> with <Character's Weapon Name> for <damage> points
 */
void Warrior::Attack(Character * target) {
    //if(target==nullptr) {return;};
    const int damage = GetWeapon().damage + strength/2;
    target->TakeDamage(damage);
    cout << GetName() << " attacks " << target->GetName() << " for " <<
        damage << " points!\n";
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
void Warrior::PowerAttack(Character * target) {
    //if(target==nullptr) {return;};  // cool kids check pointers
    const int damage = (*target).GetHealth()/100 * (GetWeapon().damage + strength/2);
    target->TakeDamage(damage);
    cout << GetName() << " Power Attacks " << target->GetName() << " for " <<
        damage << " points!\n";
}
/**
 * Public method Status that prints out the Status of the Warrior
 * @attention You MUST print out the local Warrior variables.
 *  The format for the print must be "PrivateVar: PrivateVal" where the name of the private variable is capitalized
 * @example For the private variable luck which is set to 7 you would print the following
 *      "Luck: 7"
 */

void Warrior::Status() {
    cout << "Name: "      << GetName()                  << '\n';
    cout << "Race: "      << RaceStrings[GetRace()]     << '\n';
    cout << "Weapon: "    << GetWeapon().name           << '\n';
    cout << "Health: "    << GetHealth()                << '\n';
    cout << "Level: "     << GetLevel()                 << '\n';
    cout << "Exp: "       << GetExp()                   << '\n';
    cout << "Strength: "  << strength                   << '\n';
}