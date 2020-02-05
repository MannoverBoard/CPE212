/**
 * mage.hpp - CPE 212-01, Spring 2020 - Project02 - Class Inheritance
 */
#ifndef MAGE_H
#define MAGE_H

#include "character.hpp"

class Mage : public Character
{
public:
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
    Mage(const std::string& characterName, const Race characterRace);
    /**
     * Public method of Mage that sends a Fireball at an target Character
     * @param target Pointer to the target Character
     * @attention Follow these instructions:
     *  1. The damage for a Fireball is calculated by the base damage 10 + weapon damage + half the intelligence value
     *  2. The target Character must take the damage dealt by the Mage
     *  3. Please print out the details of the attack in the following format
     *      <Character Name> attacks <Target Name> with a Fireball for <damage> points
     */
    Character& Fireball(Character& target);
protected:
    /**
     * Public method of Mage that attacks an target Character
     * @param target Pointer to the target Character
     * @attention Follow these instructions:
     *  1. The damage for a Mage is calculated by the weapon damage + half the intelligence value
     *  2. The target Character must take the damage dealt by the Mage
     *  3. Please print out the details of the attack in the following format
     *      <Character Name> attacks <Target Name> with <Character's Weapon Name> for <damage> points
     */
    virtual Character& Attack_(Character& target) override;
    /**
     * Public method Status that prints out the Status of the Mage
     * @attention You MUST print out the local Mage variables.
     *  The format for the print must be "PrivateVar: PrivateVal" where the name of the private variable is capitalized
     * @example For the private variable luck which is set to 7 you would print the following
     *      "Luck: 7"
     */
    virtual void Status_() const override;
private:
    int intelligence;
};

#endif //MAGE_H
