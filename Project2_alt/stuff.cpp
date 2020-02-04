#include "stuff.h"
#include <cmath>
#include <sstream>

#define ALL_MACRO_DO_CALLBACK(callback,...) \
  EVAL(callback(RoundingRule ,__VA_ARGS__)) \
  EVAL(callback(RoundingEvent,__VA_ARGS__)) 

#define FOO(NAME,VALUE,ENUM_NAME,...) case ENUM_NAME::NAME: return #NAME; break;
#define ENUM_TO_STRING(NAME,...)          \
std::string toString(const NAME& value) { \
  switch(value) {                         \
    GET_MACRO_MACRO(NAME)(EAT,FOO,NAME)   \
  }                                       \
  return "INVALID #NAME";                 \
}                                         \
std::ostream& operator<<(std::ostream& os, const NAME& value) { \
  os << toString(value); return os;                             \
}

ALL_MACRO_DO_CALLBACK(ENUM_TO_STRING)
#undef FOO
#undef ENUM_TO_STRING

#undef ALL_MACRO_DO_CALLBACK
#undef MACRO_RoundingEvent
#undef MACRO_RoundingRule

std::string toString(const Type& type) {
  switch(type) {
  case POTION   : return "POTION"   ; break;
  case WEAPON   : return "WEAPON"   ; break;
  case ARMOR    : return "ARMOR"    ; break;
  case ACCESSORY: return "ACCESSORY"; break;
  }
  return "INVALID TYPE";
}

std::string toString(const Race race) {
  switch(race) {
  case HUMAN : return "Human" ; break; 
  case ELF   : return "Elf"   ; break;
  case DWARF : return "Dwarf" ; break;
  case GNOME : return "Gnome" ; break;
  case GOBLIN: return "Goblin"; break;
  }
  return "INVALID RACE";
}


Item toItem(const Weapon& weapon) {
	return Item{.name = weapon.name,.value = static_cast<decltype(Item::value)>(weapon.cost), .type = WEAPON };
};

std::string toString(const Item& item) {
  std::ostringstream oss;
  oss << item.name << " Value: " << item.value;
  return oss.str();
}

double rounding(const double value,const RoundingEvent event) {
  //implements game-wide rounding logic
  double out;
  int round_rule = -1;
  switch(event) {
  case RoundingEvent::Unknown:
    round_rule = 0;
    break;
  case RoundingEvent::Player:
    round_rule = 1;
    break;
  case RoundingEvent::Enemy:
    round_rule = -1;
  }
  switch(ROUNDING_RULE) {
  case RoundingRule::AlwaysRoundDown:
    round_rule = -1;
    break;
  case RoundingRule::PlayerFavor:
    break;
  case RoundingRule::EnemyFavor:
    round_rule *= -1;
  }
  switch(round_rule) {
  case -1:out = floor(value);break;
  case  0:out = round(value);break;
  case +1:out =  ceil(value);break;
  }
  return out;
}
