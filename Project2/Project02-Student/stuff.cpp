#include "stuff.h"

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

const std::string MISSING_RACE_NAME = "MISSING_NAME";
const std::map<Race,std::string> race2sring{
	{Race::HUMAN , RaceStrings[0]},
	{Race::HUMAN , RaceStrings[1]},
	{Race::HUMAN , RaceStrings[2]},
	{Race::HUMAN , RaceStrings[3]},
	{Race::HUMAN , RaceStrings[4]}
};

std::string toString(const Race race) {
	const auto it = race2sring.find(race);
	if(it==race2sring.end()) {
		return MISSING_RACE_NAME;
	} else {
		return it->second;
	}
}

std::string toString(const Item& item) {
	std::ostringstream oss;
	oss << item.name << " Value: " << item.value;
	return oss.str();
}


Item toItem(const Weapon& weapon) {
	return Item{.name = weapon.name,.value = weapon.value,.type = TYPE::WEAPON };
};

