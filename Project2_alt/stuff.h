#ifndef STUFF_H
#define STUFF_H

#include <map>
#include <string>
#include <ostream>
#include "character.hpp"
#include "inventory.hpp"
#include "macros.h"

#define MACRO_RoundingRule_attributes(callback,...)\
  EVAL(callback(RoundingRule, 0, EMPTY(), 0, __VA_ARGS__))
#define MACRO_RoundingRule_members(callback,...)\
  EVAL(callback(RoundingRule,AlwaysRoundDown, EMPTY(), __VA_ARGS__)) \
  EVAL(callback(RoundingRule,PlayerFavor    , EMPTY(), __VA_ARGS__)) \
  EVAL(callback(RoundingRule,EnemyFavor     , EMPTY(), __VA_ARGS__))

#define MACRO_RoundingEvent_attributes(callback,...)\
  EVAL(callback(RoundingEvent, 0, EMPTY(), 0, __VA_ARGS__))
#define MACRO_RoundingEvent_members(callback,...)\
  EVAL(callback(RoundingEvent,Unknown , EMPTY(), __VA_ARGS__)) \
  EVAL(callback(RoundingEvent,Player  , EMPTY(), __VA_ARGS__)) \
  EVAL(callback(RoundingEvent,Enemy   , EMPTY(), __VA_ARGS__))

#define STUFF_ENUM_MACROS(callback,...) \
  EVAL(callback(RoundingRule ,__VA_ARGS__)) \
  EVAL(callback(RoundingEvent,__VA_ARGS__))
STUFF_ENUM_MACROS(ENUM_MACRO_DECLARATIONS)

std::string toString(const Type type);

Item toItem(const Weapon& weapon);
double rounding(const double value,const RoundingEvent event=RoundingEvent::Unknown);//implements game-wide rounding logic

const auto ROUNDING_RULE{RoundingRule::PlayerFavor};

#endif
