#include <iostream>
#include <sstream>
#include "inventory.hpp"
#include "utilities.h"


INVENTORY_ENUM_MACROS(ENUM_MACRO_DEFINITIONS)

using namespace std;

std::ostream& operator<<(std::ostream& os,const Item& item) {
  os << "{name: " << quoted11(item.name) <<", value: "<<item.value <<", type:"<<item.type<<"}";
  return os;
}

bool Item::operator==(const Item& rhs) const {
  return ((this->name ==rhs.name ) &&
          (this->value==rhs.value) &&
          (this->type ==rhs.type ) );
}

bool Item::operator!=(const Item& rhs) const {
  return !((*this)==rhs);
}

std::string Item::toString() const {
  std::ostringstream oss;
  oss<<(*this);
  return oss.str();
}


void Inventory::ShowInventory(void) const {
  for(const auto& it: items) { 
    cout<<it<<"\n";
  }
}

Inventory& Inventory::AddToInventory(const Item& it) {
  items.push_back(it);
  return (*this);
}
