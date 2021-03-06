/**
 * character.hpp - CPE 212-01, Spring 2020 - Project02 - Class Inheritance
 */
#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>
#include <fstream>
#include <limits>
#include <ostream>
#include <memory>
#include <functional>
#include "macros.h"
#include "utilities.h"
#include "inventory.hpp"

/**
 * Enum that defines the available races of the game
 */

#define MACRO_Race_attributes(callback,...) \
  EVAL(callback(Race, 0, EMPTY(), 0, __VA_ARGS__))
#define MACRO_Race_members(callback,...) \
  EVAL(callback(Race,Human , EMPTY(), __VA_ARGS__)) \
  EVAL(callback(Race,Elf   , EMPTY(), __VA_ARGS__)) \
  EVAL(callback(Race,Dwarf , EMPTY(), __VA_ARGS__)) \
  EVAL(callback(Race,Gnome , EMPTY(), __VA_ARGS__)) \
  EVAL(callback(Race,Goblin, EMPTY(), __VA_ARGS__))

#define MACRO_Verbosity_attributes(callback,...) \
  EVAL(callback(Verbosity, 0, EMPTY(), 1, __VA_ARGS__))
#define MACRO_Verbosity_members(callback,...) \
  EVAL(callback(Verbosity,Off  ,  0, __VA_ARGS__)) \
  EVAL(callback(Verbosity,Fatal,100, __VA_ARGS__)) \
  EVAL(callback(Verbosity,Error,200, __VA_ARGS__)) \
  EVAL(callback(Verbosity,Warn ,300, __VA_ARGS__)) \
  EVAL(callback(Verbosity,Info ,400, __VA_ARGS__)) \
  EVAL(callback(Verbosity,Debug,500, __VA_ARGS__)) \
  EVAL(callback(Verbosity,Trace,600, __VA_ARGS__)) \
  EVAL(callback(Verbosity,All  ,999, __VA_ARGS__))

#define PROJECT_02_ENUM_MACROS(callback,...) \
  EVAL(callback(Race     ,__VA_ARGS__)) \
  EVAL(callback(Verbosity,__VA_ARGS__))
PROJECT_02_ENUM_MACROS(ENUM_MACRO_DECLARATIONS)


/**
 * Weapon structure that defines the name, damage an cost of the weapon
 */
struct Weapon {
    std::string name;
    int damage;
    int cost;
    friend std::ostream& operator<<(std::ostream& os, const Weapon& self);
    std::string toString() const;
    bool operator==(const Weapon&rhs) const;
    bool operator!=(const Weapon&rhs) const;
};

class Character
{
public:
  // Observers
  std::string GetName() const;
  Race GetRace() const;
  int GetLevel() const;
  Weapon GetWeapon() const;
  int GetExp() const;
  std::string GetJob() const;
  int GetHealth() const;
  Verbosity GetVerbosity() const;

  // Transformers
  Character& AddExp      (const int amount    );
  Character& SetHealth   (const int h         );
  Character& SetJob      (const std::string& j);
  Character& TakeDamage  (const int h         );
  Character& SetVerbosity(const Verbosity verb);
  Character& SetWeapon   (const Weapon& w     );

  Character& AddToInventory(const Item& item);

  //Show-ers
  void ShowInventory() const;
  void Status() const;
  
  //Actions
  Character& Attack       (Character& target);
  Character& Attack       (std::shared_ptr<Character>& target);
  Character& SpecialAttack(Character& target);
  Character& SpecialAttack(std::shared_ptr<Character>& target);
protected:
  using Action = Character& (Character::*)(Character&);
  
  // Constructors
  Character(const std::string& characterName, const Race characterRace,
    Action action);

  // Pure Virtual Methods
  virtual Character& Attack_(Character& target) = 0;
  virtual void Status_() const = 0;

private:
  std::string name{};    // Name of the character
  std::string job{};     // Job of the character: Valid jobs are: "Warrior", "Mage", "Rogue" and "Cleric"
  Race race{Race::Human};      // Race is defined in the above enum
  Weapon weapon{};  // The weapon of the Character
  int health{0};     // Amount of health the Character has available. This is different for each job.
  int level{0};      // The level of the Character
  int exp{0};        // Experience of the Character. As this increases so does the Character's level
  Inventory inv{};
  Action special_attack;
  Verbosity verbose{Verbosity::Info};
};


#endif // End of CHARACTER_H
