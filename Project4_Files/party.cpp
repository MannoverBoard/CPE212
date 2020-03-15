#include "party.hpp"

Party::Party(const std::string & n) 
{
    name = n;
}

Party::Party()
{
    name = "Lazy Party";
}

std::string Party::GetName() const
{
    /**
     * Returns the parties name
     */
}

void Party::AddMember(Character *c)
{
    /**
     * Add a member to this party. Make sure it is in order
     */
}

bool Party::RemoveMember(Character *c)
{
    /**
     * Remove a character from the party
     */
}


void Party::ShowParty() const
{
    PrintHeader(); // Leave this here
    /**
     * Print out the characters in the party. Make sure to use the helper method PrintMemberData below
     */
    PrintFooter(); // Leave this here
}

Character* Party::FindMember(int id)
{
    /**
     * Return the Character in the party that has the id that is being passed into this function.
     * Return NULL if one isn't found
     */
}


void Party::Attack(Party* targetGroup, int attackerUID, int targetUID)
{
    /**
     * Given the party, attackerUID and targetUID the attacker will attack the target. Make sure you handle the case
     *  where the target dies, you don't want to forget to get your loot.
     */
}


int Party::GetSize() const
{
    /**
     * Returns the party size
     */
}

/**
 * DO NOT MODIFY
 * @param m {Character*}
 */
void Party::PrintMemberData(Character *m) const
{
    // Formatting the output into a table
    std::cout << std::left
              << std::setw(5)
              << m->GetUid()
              << std::setw(20)
              << m->GetName()
              << std::setw(7)
              << m->GetLevel()
              << std::setw(8)
              << m->GetHealth()
              << std::setw(8)
              << m->GetRace()
              << std::setw(4)
              << m->GetJob()
              << std::endl;
}