/**
 * character.cpp - CPE 212-01, Spring 2020 - Project02 - Class Inheritance
 */
#include "character.hpp"

// Implement the Constructors here

// Implement the Observers here


// Implement the Transformers here

/**
 * Public method TakeDamage
 * @param damage The amount of damage taken by the Character
 * @attention DO NOT MODIFY
 */
void Character::TakeDamage(int damage) {
    cout << name << " takes " << damage << " points of damage." << endl;
    if ((health - damage) < 0)
    {
        cout << name << " has died." << endl;
        health = 0;
    }
    else 
    {
        health -= damage;
    }
}

/**
 * Public method to print the base Character's Status
 * @attention DO NOT MODIFY
 */
void Character::Status() {
    cout << job << " Status" << endl;
    cout << "Name: " << name << endl;
    cout << "Race: " << RaceStrings[race] << endl;
    cout << "Level: " << level << endl;
    cout << "Exp: " << exp << endl;
    cout << "Health: " << health << endl;
}