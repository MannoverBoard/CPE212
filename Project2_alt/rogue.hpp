/**
 * rogue.hpp - CPE 212-01, Spring 2020 - Project02 - Class Inheritance
 */
#include "character.hpp"
#include "inventory.hpp"
#ifndef ROGUE_H
#define ROGUE_H

class Rogue : public Character
{
public:
    /**
     * Rogue Class constructor
     * @param characterName The name of the character being created
     * @param characterRace The race of the character being created. This is a enum value.
     * @extends This constructor extends the base Character constructor
     * @attention Follow these instructions:
     *  Rogue starts with 100 health
     *  Assign the starter weapon for the Rogue
     *      Weapon
     *         name : "Starter Daggers"
     *         cost : 100
     *         damage : 5
     *  Add the weapon to the Rogues inventory
     *  Assign a value of 10 for the base Rogue characteristic
     */
    Rogue(const std::string& characterName, const Race characterRace);
    /**
     * Public method of Rogue that Back Stabs a target Character
     * @param target Pointer to the Character to be healed
     * @attention Follow these instructions:
     *  1. The Back Stab damage for a Rogue is calculated by the weapon damage + base damage value 50 + half the dexterity value
     *  2. The target Character must take damage the amount dealt by the Rogue
     *  3. Please print out the details of the attack in the following format
     *      <Character Name> Back Stabs <Target Name> for <damage amount> points
     */
    Character& BackStab(Character& target);
protected:
    /**
     * Public method of Rogue that attacks an target Character
     * @param target Pointer to the target Character
     * @attention Follow these instructions:
     *  1. The damage for a Rogue is calculated by the weapon damage + half the dexterity value
     *  2. The target Character must take the damage dealt by the Rogue
     *  3. Please print out the details of the attack in the following format
     *      <Character Name> attacks <Target Name> with <Character's Weapon Name> for <damage> points
     */
    virtual Character& Attack_(Character& target) override;
    /**
     * Public method Status that prints out the Status of the Rogue
     * @attention You MUST print out the local Rogue variables.
     *  The format for the print must be "PrivateVar: PrivateVal" where the name of the private variable is capitalized
     * @example For the private variable luck which is set to 7 you would print the following
     *      "Luck: 7"
     */
    virtual void Status_() const override;
private:
    int dexterity;
};

#endif //ROGUE_H
