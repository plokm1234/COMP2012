#ifndef TOY_H
#define TOY_H

#include <string>
#include "Product.h"
/* ===========================================================================
    TODO: Complete the class definition of Toy
    HINT: Remember to take the structure figure on the lab page as reference
          This class is an extended version of lab4 with modification.
   =========================================================================== */
class Toy : public Product{
    private:
        std::string manufacturer;
        bool is_limited_edition;
    public:
        Toy();

        Toy(double regular_price, const std::string& product_name, 
                const std::string& manufacturer, const bool& is_limited_edition);

        std::string get_manufacturer() const;

        virtual double get_retail_price() const override ;

        virtual void print() const override;
};
#endif
