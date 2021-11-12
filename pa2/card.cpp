#include "card.h"
#include "util-common.h"

//// TODO: Complete the member function defintion of the cardd classes

//// TODO: Define the member functions of `Card` and those of its subclasses below.

Card::Card(const std::string& name):name_(name){};

Card::~Card(){};

std::string Card::name() const{
    return this->name_;
}

//// TODO: Define the subclasses of `Card` below.

LocationCard::LocationCard(Location* location):Card(location->name()), location_(location){};

LocationCard::~LocationCard(){}

bool LocationCard::IsWildCard() const{
   return false;
}

// Returns true if the given `industry` can be overbuilt by just considering
// the card's specification, i.e., assume we are going to build a valid industry
// on it, does the card permit us to do so?
// This does not really build any industry.
bool LocationCard::CanIndustryBeOverbuilt(const PlayerNetwork* network, const Industry* industry) const{
    return this->location_->name() == industry->location()->name();
}

// Some accessor-like functions
CardType LocationCard::card_type() const{
    return CardType::kLocationCard;
}

IndustryCard::IndustryCard(IndustryType industry_type):Card(ToString(industry_type)), industry_type_(industry_type){};
IndustryCard::~IndustryCard(){};

bool IndustryCard::IsWildCard() const{
   return false;
}

// Returns true if the given `industry` can be overbuilt by just considering
// the card's specification, i.e., assume we are going to build a valid industry
// on it, does the card permit us to do so?
// This does not really build any industry.
bool IndustryCard::CanIndustryBeOverbuilt(const PlayerNetwork* network, const Industry* industry) const{
    return industry->industry_type() == this->industry_type_;
}

// Some accessor-like functions
CardType IndustryCard::card_type() const{
    return CardType::kIndustryCard;
}

WildIndustryCard::WildIndustryCard():Card("Wild Industry"){};
WildIndustryCard::~WildIndustryCard(){};

bool WildIndustryCard::IsWildCard() const{
   return true;
}

// Returns true if the given `industry` can be overbuilt by just considering
// the card's specification, i.e., assume we are going to build a valid industry
// on it, does the card permit us to do so?
// This does not really build any industry.
bool WildIndustryCard::CanIndustryBeOverbuilt(const PlayerNetwork* network, const Industry* industry) const{
    return network->HasEstablished();
}

// Some accessor-like functions
CardType WildIndustryCard::card_type() const{
    return CardType::kWildIndustryCard;
}

WildLocationCard::WildLocationCard():Card("Wild Location"){};
WildLocationCard::~WildLocationCard(){};

bool WildLocationCard::IsWildCard() const{
   return true;
}

// Returns true if the given `industry` can be overbuilt by just considering
// the card's specification, i.e., assume we are going to build a valid industry
// on it, does the card permit us to do so?
// This does not really build any industry.
bool WildLocationCard::CanIndustryBeOverbuilt(const PlayerNetwork* network, const Industry* industry) const{
    return true;
}

// Some accessor-like functions
CardType WildLocationCard::card_type() const{
    return CardType::kWildLocationCard;
}

//// TODO ends
