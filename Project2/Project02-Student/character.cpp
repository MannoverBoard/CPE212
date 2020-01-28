/**
 * character.cpp - CPE 212-01, Spring 2020 - Project02 - Class Inheritance
 */
#include "character.hpp"
#include "stuff.h"

// THIS is dumb, this stuff *SHOULD* be in the .h file, but since I can't
// modify that file, it goes here. >:(
const std::string DEFAULT_NAME = "NO NAME";
const std::string DEFAULT_JOB = "NO JOB";
const Race        DEFAULT_RACE = Race::HUMAN;
const Weapon      DEFAULT_WEAPON{DEFAULT_NAME,0,0};
const int         DEFAULT_HEALTH{0};
const int         DEFAULT_LEVEL{0};
const int         DEFAULT_EXPERIENCE{0};

// Implement the Constructors here
Character::Character() :
	name(DEFAULT_NAME),
	job(DEFAULT_JOB),
	race(DEFAULT_RACE),
	weapon(DEFAULT_WEAPON),
	health(DEFAULT_HEALTH),
	level(DEFAULT_LEVEL),
	exp(DEFAULT_EXPERIENCE)
{}

Character::Character(string characterName, Race characterRace) :
	Character{}
{
	name = characterName;
	race = characterRace;
}

// These are const getters, these really could be given in the .h  file :/
// also what the heck, why are the observer getters given in a different order
// than the private members...
// Implement the Observers here
std::string Character::GetName  () const { return name  ; }
std::string Character::Character::GetJob   () const { return job   ; }
Race        Character::Character::GetRace  () const { return race  ; }
Weapon      Character::Character::GetWeapon() const { return weapon; }
int         Character::Character::GetHealth() const { return health; }
int         Character::Character::GetLevel () const { return level ; }
int         Character::Character::GetExp   () const { return exp   ; }

// Implement the Transformers here
void Character::AddExp(int amount) {
	//TODO QUESTION: Can experience be negative? I will assume not for now
	exp += (amount>0)?amount:0;
}
void Character::SetHealth(int h) {
	//TODO QUESTION: Can health be negative? If given an invalid value should an exception be thrown?
	health = (h>=0)?h:0;
}
void Character::SetJob(string j) {
	job = j;
}

// Virtual Methods
void Character::SetWeapon(Weapon w) {
	weapon = w;
}

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
    cout << "Race: " << toString(race) << endl;
    cout << "Level: " << level << endl;
    cout << "Exp: " << exp << endl;
    cout << "Health: " << health << endl;
}