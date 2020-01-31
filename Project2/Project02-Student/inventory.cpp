#include "inventory.hpp"

/**
 * Inventory Constructor
 * Add the following item to the inventory
 * Item:
 *  name : "Basic Health Potion"
 *  value: 10
 *  type: POTION
 */
Inventory::Inventory()
{
    Item potion;
    potion.name = "Basic Health Potion";
    potion.value = 10;
    potion.type = POTION;
    
    items[0] = potion;
    
}
/**
 * AddToInventory Function
 * Function that adds items to the inventory
 */ 
void Inventory::AddToInventory(Item i) {
    if (length > 0 && length < MAX_SLOTS) {
        items[length] = i;
        length++;
    }
    else {
        cout << "Inventory full" << endl;
    }
}
/**
 * ShowInventory Function
 * Function that shows all items in the inventory
 * @attention Make sure that you format the output string as follows:
 *  Item - <Item Name> Value: <Item Value>
 */ 
void Inventory::ShowInventory() {
    for (int index = 0; index < MAX_SLOTS; index++) {
        cout << "Item - <" << items[index].name <<
        "> Value: <" << items[index].value << ">\n";
    }

}