#include "industry.h"
#include "player.h"

//// TODO: Complete primary and secondary industries

PrimaryIndustry::PrimaryIndustry(IndustryType industry_type, IndustryProperties properties,
                ResourceType resource_type):IndustryImpl(industry_type, properties, resource_type){};

  // This can overbuild the `other` industry if this is more technologically advanced,
  // and they are of the same industry type. Usually the owner of this industry must
  // also own the industry that he overbuilds on. However, if the game board has
  // exhausted all the resources, or the `other` industry is not yet built
  // (i.e. representing an empty slot), any player can overbuild the given industry
  // but is subject to the same constraints.
  // Hint: As we alway overbuild through an industry proxy, an an industry proxy always
  //       has a resource observer attached, we can assume `other` is assoicated
  //       to a valid resource observer.
bool PrimaryIndustry::CanOverbuild(Industry* other) const{
  if(this->properties_.tech_level > other->properties().tech_level  && other->industry_type() == this->industry_type()) {
    if(other->player() == nullptr){
      return true;
      }else{
        if(this->player_name() == other->player_name()){
          return true;
        }else{
          if(this->available_units() == 0 && static_cast<PrimaryIndustry*>(other)->resource_observer_->HasResource(this->resource_type_) == false ){
            return true;
          }
        }
      }
    }
  return false;
}

// Returns true if all of its resource units are consumed.
bool PrimaryIndustry::IsEligibleForVp() const{
  return this->available_units()==0;
}

// Produces the number of output units specified by its properties,
// and notifies the resource observers of the change.
void PrimaryIndustry::ProduceResources() {
  this->resource_observer_->UpdateResourceCount(this->resource_type_, this->properties_.output_units);
  this->available_units_ += this->properties_.output_units;
  this->industry_observer_->UpdateIndustry(this);
}

// Removes all the resource units available and notifies the
// resource and industry observers of the change.
void PrimaryIndustry::RemoveResources() {
  this->resource_observer_->UpdateResourceCount(this->resource_type_, -this->available_units_);
  this->available_units_ = 0;
  this->industry_observer_->UpdateIndustry(this);
}

// Provides the given nubmer of resource units if possible.
// Notifies the resource and industry observes of the change.
bool PrimaryIndustry::ProvideResources(int units) {
  if(available_units() >= units){
    this->resource_observer_->UpdateResourceCount(this->resource_type_, -units);
    this->available_units_ -= units;
    this->industry_observer_->UpdateIndustry(this);
    if(this->available_units() == 0 ) this->player_->IncreaseExp(this->properties_.exp_increase);
    return true;
  }
  return false;
}

// An accessor
int PrimaryIndustry::available_units() const{
  return available_units_;
}

// A setter

void PrimaryIndustry::set_resource_observer(ResourceObserver* rsrc_observer){
  this->resource_observer_ = rsrc_observer;
  this->resource_observer_->UpdateResourceCount(this->resource_type_, this->available_units_);
}

SecondaryIndustry::SecondaryIndustry(IndustryType industry_type, IndustryProperties properties):IndustryImpl(industry_type, properties){};

// This is similar to the function you solved for PrimaryIndustry.
// Just that we do not allow other players who do not own the `other`
// industry to build on it, if it is already built.
bool SecondaryIndustry::CanOverbuild(Industry* other) const{
  if(this->properties_.tech_level > other->properties().tech_level  && other->industry_type() == this->industry_type()) {
     if(other->player() == nullptr){
       return true;
      }else{
        if(this->player_name() == other->player_name()){
          return true;
        }
      }
    }
  return false;
}

// Returns true if the industry is sold.
bool SecondaryIndustry::IsEligibleForVp() const{
  return this->sold() == true;
}

// Sells the industry, and increase the players income sublevels by a number
// specified in the industry's properties.
bool SecondaryIndustry::Sell(){
  if(this->sold() == false){
    this->player_->IncreaseExp(this->properties_.exp_increase);
    this->sold_ = true;
    this->industry_observer_->Notify();
    return true;
  }
  return false;
}

// An accessor.
bool SecondaryIndustry::sold() const{
  return sold_;
}

// Ignores the resource observer as a secondary industry does not produce
// consumerable resources for players.
void SecondaryIndustry::set_resource_observer(ResourceObserver* rsrc_observer) {}

//// TODO ends
