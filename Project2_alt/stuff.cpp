#include <sstream>
#include <cmath>

#include "stuff.h"


STUFF_ENUM_MACROS(ENUM_MACRO_DEFINITIONS)

Item toItem(const Weapon& weapon) {
	return Item{.name = weapon.name,.value = static_cast<decltype(Item::value)>(weapon.cost), .type =ItemType::Weapon };
};

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
