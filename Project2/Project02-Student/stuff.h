#ifndef STUFF_H
#define STUFF_H

#include <map>
#include <string>
#include <ostream>
#include "character.hpp"
#include "inventory.hpp"
#include "macro.h"

#define MACRO_RoundingRule(getParametersCallback,getMemberCallback,...) \
  EVAL(getParametersCallback(EMPTY, __VA_ARGS__)) \
  EVAL(getMemberCallback(AlwaysRoundDown,EMPTY, __VA_ARGS__)) \
  EVAL(getMemberCallback(PlayerFavor    ,EMPTY, __VA_ARGS__)) \
  EVAL(getMemberCallback(EnemyFavor     ,EMPTY, __VA_ARGS__)) 

#define MACRO_RoundingEvent(getParametersCallback,getMemberCallback,...) \
  EVAL(getParametersCallback(EMPTY, __VA_ARGS__)) \
  EVAL(getMemberCallback(Unknown ,EMPTY, __VA_ARGS__)) \
  EVAL(getMemberCallback(Player  ,EMPTY, __VA_ARGS__)) \
  EVAL(getMemberCallback(Enemy   ,EMPTY, __VA_ARGS__)) 

#define ALL_MACRO_DO_CALLBACK(callback,...) \
  EVAL(callback(RoundingRule ,__VA_ARGS__)) \
  EVAL(callback(RoundingEvent,__VA_ARGS__)) 

#define FOO(NAME,VALUE,...) NAME,
#define ENUM_DEFINE(NAME,...)                 \
enum class NAME {                             \
  GET_MACRO_MACRO(NAME)(EAT,FOO,EMPTY)  \
};

ALL_MACRO_DO_CALLBACK(ENUM_DEFINE)
#undef ENUM_DEFINE
#undef FOO

#define ENUM_TO_STRING(NAME,...)          \
std::string toString(const NAME& value);  \
std::ostream& operator<<(std::ostream& os, const NAME& value);

ALL_MACRO_DO_CALLBACK(ENUM_TO_STRING)
#undef ENUM_TO_STRING

#undef ALL_MACRO_DO_CALLBACK
  
template<typename T,size_t N>
constexpr size_t num_elements(const T (&arr)[N]) { return N; } 

std::string toString(const Type type);
std::string toString(const Race race);
std::string toString(const Item& item);

Item toItem(const Weapon& weapon);
double rounding(const double value,const RoundingEvent event=RoundingEvent::Unknown);//implements game-wide rounding logic

const auto ROUNDING_RULE = RoundingRule::PlayerFavor;

#endif
