#ifndef MACRO_H
#define MACRO_H


#define EVAL_00(...) __VA_ARGS__
#define EVAL_01(...) EVAL_00(EVAL_00(EVAL_00(__VA_ARGS__)))
#define EVAL_02(...) EVAL_01(EVAL_01(EVAL_01(__VA_ARGS__)))
#define EVAL_03(...) EVAL_02(EVAL_02(EVAL_02(__VA_ARGS__)))
#define EVAL_04(...) EVAL_03(EVAL_03(EVAL_03(__VA_ARGS__)))
#define EVAL_05(...) EVAL_04(EVAL_04(EVAL_04(__VA_ARGS__)))
#define EVAL(...)    EVAL_05(EVAL_05(EVAL_05(__VA_ARGS__)))

#define EMPTY()
#define EAT(...)

#define IFF_0(true_case,false_case) false_case
#define IFF_1(true_case,false_case) true_case
#define IFF(switch_val, true_case, false_case) IFF_##switch_val(true_case, false_case)
  /*requires switch_val to be 0 or 1 exclusively */
#define WHEN(switch_val) IFF(switch_val,EVAL,EAT)
  /*usage WHEN( 0 | 1)(statement)*/
#define UNLESS(switch_val) IFF(switch_val,EAT,EVAL)
  /*usage UNLESS is the opposite of WHEN */

#define GET_FIRST(first,...) first

#define GET_MACRO_MACRO(NAME,...) MACRO_##NAME
#define GET_MACRO_SCOPE(NAME,...) GET_MACRO_MACRO(NAME)(GET_FIRST,EAT,EMPTY)

//////////////////////////////
#define ENUM_MACRO_DECLARATIONS__CALLBACK_1(NAME,VALUE,...) NAME,
#define ENUM_MACRO_DECLARATIONS(NAME,...)                      \
enum class NAME {                                              \
  ENUM_MACRO_DECLARATIONS__CALLBACK_1(NAME)(EAT,FOO,EMPTY)     \
};                                                             \
std::string toString(const NAME& value);                       \
std::ostream& operator<<(std::ostream& os, const NAME& value);

#define ENUM_MACRO_DEFINITIONS__CALLBACK_1(NAME,VALUE,ENUM_NAME,...) case ENUM_NAME::NAME: return #NAME; break;
#define ENUM_MACRO_DEFINITIONS(NAME,...)                        \
std::string toString(const NAME& value) {                       \
  switch(value) {                                               \
    ENUM_MACRO_DEFINITIONS__CALLBACK_1(NAME)(EAT,FOO,NAME)      \
  }                                                             \
  return "INVALID #NAME";                                       \
}                                                               \
std::ostream& operator<<(std::ostream& os, const NAME& value) { \
  os << toString(value); return os;                             \
}

#endif
