#include <iostream>
#include "Toy.h"
using namespace std;

Toy::Toy(): Product(0, ""), manufacturer(""), is_limited_edition(false) {}

Toy::Toy(double regular_price, const string& product_name, 
         const string& manufacturer, const bool& is_limited_edition) 
         : Product(regular_price, product_name), 
           manufacturer(manufacturer), is_limited_edition(is_limited_edition) {}

string Toy::get_manufacturer() const {
    return manufacturer;
}

double Toy::get_retail_price() const {
    return this->is_limited_edition ? get_regular_price() * 2 : get_regular_price();
}

void Toy::print() const {
    cout << "Toy: "<< endl;
    cout << "Product name: " << get_product_name() << ", Manufacturer: " << get_manufacturer()
         << ", Retail Price: " ;
         this->is_limited_edition ? cout << get_retail_price() << endl : cout << get_retail_price() <<endl;
}

/* ===============================================================================
    TODO: Implement all the remaining member functions here
    HINT: Remember to take the structure figure on the lab page as reference
          In get_retail_price fuction, if the toy is a limited edition, the price 
          is 2 times the regular price.
   =============================================================================== */
