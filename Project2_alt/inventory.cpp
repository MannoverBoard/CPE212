#include "inventory.hpp"

#include <string>       // std::string
#include <iostream>     
#include <sstream>

#include "stuff.h"

// <rant>
// This to string crud really should be in the struct definitions..
// </rant>
const auto DEFAULT_TYPE = POTION;
const Item DEFAULT_ITEM{"NO NAME",0.,DEFAULT_TYPE};

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
	const auto is_full = (length>=num_elements(items));
	if(is_full) { return; }
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