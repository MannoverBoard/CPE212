#include "inventory.hpp"

#include <string>       // std::string
#include <iostream>     
#include <sstream>

template<typename T,size_t N>
constexpr size_t length(const (T&)arr[N]) { return N; } 

const auto DEFAULT_TYPE = POTION;
const std::string MISSING_TYPE_NAME = "Type";
const std::map<Race,std::string> type2string{
	{Race::POTION    , "POTION"   },
	{Race::WEAPON    , "WEAPON"   },
	{Race::ARMOR     , "ARMOR"    },
	{Race::ACCESSORY , "ACCESSORY"}
};
std::string toString(const Type type) {
	const auto it = type2string.find(type);
	if(it==type2string.end()) {
		return MISSING_TYPE_NAME;
	} else {
		return it->second;
	}
}

const Item DEFAULT_ITEM{"NO NAME",0.,DEFAULT_TYPE};

// <rant>
// This to string crud really should be in the struct definitions..
// </rant>
std::string toString(const Item& item) {
	std::ostringstream oss;
	oss << item.name << " Value: " << item.value;
	return oss.str();
}

/**
 * Inventory Constructor
 * Add the following item to the inventory
 * Item:
 *  name : "Basic Health Potion"
 *  value: 10
 *  type: POTION
 */
Inventory::Inventory() {
	length = 0;
	std::fill(std::begin(items),std::end(items),DEFAULT_ITEM);
	AddToInventory(Item{"Basic Health Potion",10.,Type::POTION});
}

/**
 * AddToInventory Function
 * Function that adds items to the inventory
 */ 
// <rant>
// AGH! why is there no return value, what if there are too many items....
// how is the caller supposed to know..
// </rant>
void Inventory::AddToInventory(Item i) {
	const auto is_full = (length>=length(items));
	if(full) { return; }
	items[length] = i;
	length++;
}


/**
 * ShowInventory Function
 * Function that shows all items in the inventory
 * @attention Make sure that you format the output string as follows:
 *  Item - <Item Name> Value: <Item Value>
 */ 
void Inventory::ShowInventory() {
	for(size_t i=0; i<length;++i) {
		std::cout<<toString(items[i])<<"\n";
	}
	//TODO PRINTING: should this print a trailing newline?
}