/**
 * cleric.cpp - CPE 212-01, Spring 2020 - Project02 - Class Inheritance
 */
#include "cleric.hpp"

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


Cleric::Cleric(string characterName, Race characterRace) : 
    Character(characterName, characterRace), Inventory()
{
    // Initializes name and race variables from parent class
    // Parent constructor must be called in Child class constructor

    const Weapon Starter_Weapon{.name = "Simple Wand", .damage = 100, .cost = 5};
    // Weapon is initialized using an initializer list

    willpower = 10;

    AddToInventory(Item{.name=Starter_Weapon.name,
        .value = Starter_Weapon.cost, .type = WEAPON});


}

/**
 * Status Function
 * Public method Status that prints out the Status of the Cleric
 * @attention You MUST print out the local Cleric variables.
 *  The format for the print must be "PrivateVar: PrivateVal" where the name of the private variable is capitalized
 * @example For the private variable luck which is set to 7 you would print the following
 *      "Luck: 7"
 */
void Cleric::Status() {
    Character::Status();
    cout << "Name: "      << GetName();
    cout << "Race: "      << GetRace();
    cout << "Weapon: "    << GetWeapon;
    cout << "Health: "    << GetHealth();
    cout << "Level: "     << GetLevel();
    cout << "Exp: "       << GetExp();
    cout << "Willpower: " << willpower;
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
void Cleric::Attack(Character * target) {
    int damage;
    damage = GetWeapon().damage + willpower/2;
    target.TakeDamage(damage);
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
    if(target==nullptr) { return ; }
    int damage = -(10 + willpower/2);
    (*target).TakeDamage(damage);   
    // Setting damage to negative
    // value allows TakeDamage function
    // to act as a healing action as
    // there is no condition that 
    //damge must be positive.
}