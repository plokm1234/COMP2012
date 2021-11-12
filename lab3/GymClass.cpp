#include "GymClass.h"
#include <iostream>

using namespace std;

// TODO: complete the constructor of GymClass
GymClass::GymClass(const string& period, const string& area, const string& name, const string& sports_type) : GymSession(period, area){
    this->name = name;
    this->sports_type = sports_type;
}

// TODO: complete GymClass::get_name
string GymClass::get_name() const {
    return this->name;
}

// TODO: complete GymClass::get_sports_type
string GymClass::get_sports_type() const {
    return this->sports_type;
}
void GymClass::print() const {
    cout << "GymClass: " << endl;
    cout << "Name: " << get_name() << ", Sports Type: " << get_sports_type() << ", Period: " << get_period() << ", Area: " << get_area() << endl;
}