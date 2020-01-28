#ifndef STUFF_H
#define STUFF_H

#include <map>
#include <string>
#include "character.hpp"
#include "inventory.hpp"

template<typename T,size_t N>
constexpr size_t num_elements(const T (&arr)[N]) { return N; } 

std::string toString(const Type type);
std::string toString(const Race race);
std::string toString(const Item& item);

Item toItem(const Weapon& weapon);

#endif