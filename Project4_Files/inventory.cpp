#include "inventory.hpp"

void Inventory::Add(const Item &i)
{
    /**
     * Add the item to the inventory
     */
}

bool Inventory::Remove(const Item &i)
{
    /**
     * Delete the item from the inventory
     */
}

bool Inventory::isEmpty() const
{
    /**
     * Return if the inventory is empty
     */
}
bool Inventory::isFull() const
{
    /**
     * Return if the inventory is full
     */
}
void Inventory::ShowInventory() const
{
    PrintHeader();  // Leave this here
    /**
     * Print out the contents of the inventory. Use the PrintItem helper function below
     */
    PrintFooter();  // Leave this here
}

Item Inventory::PopFront() {
    /**
     * Pop the first item off of the inventory and return it back to the caller
     */
}

/**
 * DO NOT MODIFY
 * @param i {Item*}
 */
void Inventory::PrintItem(Item *i) const
{
    if(i == nullptr)
    {
        std::cout << "ITEM IS NULL" << std::endl;
        return;
    }
    // Formatting the output into a table
    std::cout << std::left
              << std::setw(10)
              << i->GetType();
    std::cout
              << std::setw(35)
              << i->GetName();
    std::cout
              << std::setw(7)
              << i->GetValue()
              << std::endl;
}
