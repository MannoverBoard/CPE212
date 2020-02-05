/**
 * goblin.hpp - CPE 212-01, Spring 2020 - Project02 - Class Inheritance
 */
#include "character.hpp"
#include "inventory.hpp"
#ifndef GOBLIN_H
#define GOBLIN_H

class Goblin : public Character
{
public:
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
    Goblin(const std::string& characterName, const Race characterRace);
    /**
     * Public method of Goblin that Sneak Attacks a target Character
     * @param target Pointer to the Character to be healed
     * @attention Follow these instructions:
     *  1. The Sneak Attack damage for a Goblin is calculated by the base damage value 20 + half the attack value plus weapon damage
     *  2. The target Character must take damage the amount dealt by the Goblin
     *  3. Please print out the details of the attack in the following format
     *      <Character Name> Sneak Attacks <Target Name> for <damage amount> points
     */
    Character& SneakAttack(Character& target);
protected:
    /**
     * Public method of Goblin that attacks an target Character
     * @param target Pointer to the target Character
     * @attention Follow these instructions:
     *  1. The damage for a Goblin is calculated by the weapon damage + half the attack value
     *  2. The target Character must take the damage dealt by the Goblin
     *  3. Please print out the details of the attack in the following format
     *      <Character Name> attacks <Target Name> with <Character's Weapon Name> for <damage> points
     */
    virtual Character& Attack_(Character& target) override;
    /**
     * Public method Status that prints out the Status of the Goblin
     * @attention You MUST print out the local Goblin variables.
     *  The format for the print must be "PrivateVar: PrivateVal" where the name of the private variable is capitalized
     * @example For the private variable luck which is set to 7 you would print the following
     *      "Luck: 7"
     */
    virtual void Status_() const override;
private:
    int attack;
};

#endif
