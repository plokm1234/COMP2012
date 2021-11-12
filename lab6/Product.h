#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <sstream>
#include <string>

class Product
{
    private: 
        double regular_price;
        std::string product_name;
    public: 
        Product() : regular_price(0), product_name("") {}
        Product(double regular_price, const std::string& product_name)
          : regular_price(regular_price), product_name(product_name) {}
        std::string get_product_name() const { return product_name; }
        double get_regular_price() const { return regular_price; }

        virtual double get_retail_price() const = 0; 
        virtual void print() const = 0;

    /* ===================================================================
        TODO: operator overloading
              Refer to the main.cpp.
       =================================================================== */

    // TODO: Overload `operator>` to compare the get_retail_price(), when the parameter is Prodouct.
    // Compare_price function template in ProductVector.h will be replaced by this operator.
    bool operator>(const Product& p){
       return this->get_retail_price() > p.get_retail_price();
    }
    // TODO: Overload `operator>` to compare the get_retail_price(), when the parameter is int.
    // Compare_price function template in ProductVector.h will be replaced by this operator.
    bool operator>(const int v){
       return this->get_retail_price() > v;
    }
    // TODO: Overload `operator<<` to print get_product_name()
    // Hint: Using the "friend" keyword, declare stream insertion operator function `operator<<`
    // cout << product; -> output is product.get_product_name()
    friend std::ostream& operator<<(std::ostream& os, const Product& p){
        return os<< p.get_product_name();
    };
    // TODO: Overload `operator==` to compare get_product_name(), when the parameter is string.
    // Hint: If they are equal, return ture or opposite.
    // The member function isExist of ProductVector will use this operator.
    bool operator==(const std::string& name){
        return this->get_product_name() == name;
    };
    // TODO: Overload `operator==` to compare get_product_name(), when the parameter is Product.
    // Hint: If they are equal, return ture or opposite.
    // The member function isExist of ProductVector will use this operator.
    bool operator==(const Product& p){
        return this->get_product_name() == p.get_product_name();
    };
};

#endif
