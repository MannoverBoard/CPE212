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

/**
 * Public method of Warrior that attacks an enemy Character
 * @param enemy Pointer to the enemy Character
 * @attention Follow these instructions:
 *  1. The damage for a Warrior is calculated by the weapon damage + half the strength value
 *  2. The enemy Character must take the damage dealt by the Warrior
 *  3. Please print out the details of the attack in the following format
 *      <Character Name> attacks <Enemy Name> with <Character's Weapon Name> for <damage> points
 */

/**
 * Public method of Warrior that deals a Power Attack to a target Character
 * @param target Pointer to the Character to be attacked
 * @attention Follow these instructions:
 *  1. The damage for a Power Attack is calculated by the health / 100 * (weapon damage + half the strength value)
 *  2. The target Character must take damage the amount dealt by the Warrior
 *  3. Please print out the details of the attack in the following format
 *      <Character Name> Power Attacks <Target Name> for <damage amount> points
 */

/**
 * Public method Status that prints out the Status of the Warrior
 * @attention You MUST print out the local Warrior variables.
 *  The format for the print must be "PrivateVar: PrivateVal" where the name of the private variable is capitalized
 * @example For the private variable luck which is set to 7 you would print the following
 *      "Luck: 7"
 */