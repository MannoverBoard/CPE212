#ifndef MACRO_H
#define MACRO_H


#define EVAL_00(...) __VA_ARGS__
#define EVAL_01(...) EVAL_00(EVAL_00(EVAL_00(__VA_ARGS__)))
#define EVAL_02(...) EVAL_01(EVAL_01(EVAL_01(__VA_ARGS__)))
#define EVAL_03(...) EVAL_02(EVAL_02(EVAL_02(__VA_ARGS__)))
#define EVAL_04(...) EVAL_03(EVAL_03(EVAL_03(__VA_ARGS__)))
#define EVAL_05(...) EVAL_04(EVAL_04(EVAL_04(__VA_ARGS__)))
#define EVAL(...)    EVAL_05(EVAL_05(EVAL_05(__VA_ARGS__)))

#define MACRO_COMMA ,
#define EMPTY()
#define EAT(...)
#define DEFER(...) EMPTY()__VA_ARGS__
#define OBSTRUCT(...) __VA_ARGS__ DEFER(EMPTY)()

#define MACRO_CAT(a, ...) MACRO_PRIMITIVE_CAT(a, __VA_ARGS__)
#define MACRO_PRIMITIVE_CAT(a, ...) a ## __VA_ARGS__

#define IFF_0(true_case,...) __VA_ARGS__
#define IFF_1(true_case,...) true_case
#define IFF(switch_val) MACRO_PRIMITIVE_CAT(IFF_,switch_val)
  /*requires switch_val to be 0 or 1 exclusively */
#define WHEN(switch_val) IFF(EVAL(switch_val))(EVAL,EAT)
  /*usage WHEN( 0 | 1)(statement)*/
#define UNLESS(switch_val) IFF(EVAL(switch_val))(EAT,EVAL)
  /*usage UNLESS is the opposite of WHEN */


#define MACRO_GET_1(first,...) first
#define MACRO_GET_2(first,second,...) second
#define MACRO_GET_3(first,second,third,...) third


#define GET_MACRO_ATTRIBUTES(NAME,...)  MACRO_CAT(MACRO_,MACRO_CAT(NAME,_attributes))
#define GET_MACRO_MEMBERS(NAME,...)     MACRO_CAT(MACRO_,MACRO_CAT(NAME,_members))

#define GET_ENUM_ATTR_SCOPE(EnumName)      EVAL(DEFER(GET_MACRO_ATTRIBUTES(EnumName))(MACRO_GET_2))
#define GET_ENUM_ATTR_HAS_VALUES(EnumName) EVAL(DEFER(GET_MACRO_ATTRIBUTES(EnumName))(MACRO_GET_3))
#define GET_ENUM_SCOPED_NAME(EnumName) GET_ENUM_ATTR_SCOPE(EnumName)::EnumName


//////////////////////////////
#define ENUM_MACRO_DECLARATIONS__CALLBACK(EnumName,name,value,...) \
  IFF(GET_ENUM_ATTR_HAS_VALUES(EnumName))(name=value MACRO_COMMA, name MACRO_COMMA)

#define ENUM_MACRO_DECLARATIONS(EnumName,...) \
namespace GET_ENUM_ATTR_SCOPE(EnumName) { \
enum class EnumName { \
  GET_MACRO_MEMBERS(EnumName)(ENUM_MACRO_DECLARATIONS__CALLBACK,__VA_ARGS__) \
}; } \
std::string toString(const GET_ENUM_SCOPED_NAME(EnumName)& value); \
std::ostream& operator<<(std::ostream& os, const GET_ENUM_SCOPED_NAME(EnumName)& value);

#define ENUM_MACRO_DEFINITIONS__CALLBACK(EnumName,name,...) case GET_ENUM_SCOPED_NAME(EnumName)::name: return #name; break;
#define ENUM_MACRO_DEFINITIONS(EnumName,...) \
std::string toString(const GET_ENUM_SCOPED_NAME(EnumName)& value) { \
  switch(value) {                                               \
    GET_MACRO_MEMBERS(EnumName)(ENUM_MACRO_DEFINITIONS__CALLBACK,__VA_ARGS__) \
  } \
  return "INVALID "#EnumName; } \
std::ostream& operator<<(std::ostream& os, const GET_ENUM_SCOPED_NAME(EnumName)& value) { \
  os << toString(value); return os; }

#endif
