#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <ostream>
#include <vector>
#include "macros.h"

#define MACRO_ItemType_attributes(callback,...) \
  EVAL(callback(ItemType, 0, EMPTY(), 0, __VA_ARGS__))
#define MACRO_ItemType_members(callback,...) \
  EVAL(callback(ItemType,Potion   , EMPTY(), __VA_ARGS__)) \
  EVAL(callback(ItemType,Weapon   , EMPTY(), __VA_ARGS__)) \
  EVAL(callback(ItemType,Armor    , EMPTY(), __VA_ARGS__)) \
  EVAL(callback(ItemType,Accessory, EMPTY(), __VA_ARGS__))

#define INVENTORY_ENUM_MACROS(callback,...) \
  EVAL(callback(ItemType ,__VA_ARGS__))
INVENTORY_ENUM_MACROS(ENUM_MACRO_DECLARATIONS)

struct Item
{
  std::string name;
  float value;
  ItemType type;
  friend std::ostream& operator<<(std::ostream& os,const Item& item);
  std::string toString() const;
  bool operator==(const Item& rhs) const;
  bool operator!=(const Item& rhs) const;
};


class Inventory
{
public:
  void ShowInventory() const;
  Inventory& AddToInventory(const Item& i);
private:
  std::vector<Item> items{};
};

#endif
