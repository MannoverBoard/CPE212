/**
 * character.cpp - CPE 212-01, Spring 2020 - Project02 - Class Inheritance
 */
#include "character.hpp"
#include "macros.h"

#include <sstream>

using namespace std;

PROJECT_02_ENUM_MACROS(ENUM_MACRO_DEFINITIONS)

ostream& operator<<(ostream& os, const Weapon& self) {
	os << "{name:" << quoted11(self.name) << ", damage:" << self.damage << ", cost:" << self.cost << "}";
	return os;
}

std::string Weapon::toString() const {
	std::ostringstream oss;
	oss<<(*this);
	return oss.str();
}

bool Weapon::operator==(const Weapon&rhs) const{
	return ((this->name  ==rhs.name  ) &&
          (this->damage==rhs.damage) &&
				  (this->cost  ==rhs.cost  ));
}

bool Weapon::operator!=(const Weapon&rhs) const {
	return !((*this)==rhs);
}

Character::Character(const std::string& characterName, const Race characterRace,
  Action act) :
	name(characterName), race(characterRace), special_attack(act)
{ }


// These are const getters, these really could be given in the .h  file :/
// also what the heck, why are the observer getters given in a different order
// than the private members...
// Implement the Observers here
std::string Character::GetName     () const { return name   ; }
std::string Character::GetJob      () const { return job    ; }
Race        Character::GetRace     () const { return race   ; }
Weapon      Character::GetWeapon   () const { return weapon ; }
int         Character::GetHealth   () const { return health ; }
int         Character::GetLevel    () const { return level  ; }
int         Character::GetExp      () const { return exp    ; }
Verbosity   Character::GetVerbosity() const { return verbose; }

// Implement the Transformers here
Character& Character::AddExp(const int amount) {
	//TODO QUESTION: Can experience be negative? I will assume not for now
	exp += std::max(amount,0);
  return (*this);
}

Character& Character::SetHealth(const int h) {
	//TODO QUESTION: Can health be negative? If given an invalid value should an exception be thrown?
	health = std::max(h,0);
  return (*this);
}

Character& Character::SetJob(const string& j) {
	job = j;
  return (*this);
}

// Virtual Methods
Character& Character::SetWeapon(const Weapon& w) {
	weapon = w;
  return (*this);
}

Character& Character::SetVerbosity(const Verbosity verb) {
  verbose = verb;
  return (*this);
}

Character& Character::AddToInventory(const Item& item) {
  inv.AddToInventory(item);
  return (*this);
}

/**
 * Public method TakeDamage
 * @param damage The amount of damage taken by the Character
 * @attention DO NOT MODIFY
 */
Character& Character::TakeDamage(const int damage) {
  SetHealth(health-damage);
  if(verbose>=Verbosity::Info) {
    cout << name << " takes " << damage << " points of damage." << endl;
    if (health<=0) {
      //TODO this may be an error is <0 dead or <=0 dead?
      cout << name << " has died." << endl;
    }
  }
  return (*this);
}

void Character::ShowInventory() const {
	this->inv.ShowInventory();
}

Character& Character::Attack(std::shared_ptr<Character>& target) {
	if(target==nullptr) { return (*this); }
	return Attack(*target.get());
}

Character& Character::Attack(Character& target) {
  return Attack_(target);
}

Character& Character::SpecialAttack(std::shared_ptr<Character>& target) {
	if(target==nullptr) { return (*this); }
	return SpecialAttack(*target.get());
}

Character& Character::SpecialAttack(Character& target) {
	return (this->*special_attack)(target);
}

/**
 * Public method to print the base Character's Status
 * @attention DO NOT MODIFY
 */
void Character::Status() const {
  cout << job << " Status" << endl;
  cout << "Name: " << name << endl;
  cout << "Race: " << race << endl;
  cout << "Level: " << level << endl;
  cout << "Exp: " << exp << endl;
  cout << "Health: " << health << endl;
  Status_();
}
