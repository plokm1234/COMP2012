#ifndef BOOK_H
#define BOOK_H

#include <string>
#include "Product.h"
/* ==========================================================================
    TODO: Complete the class declaration of Book
    HINT: Remember to take the structure figure on the lab page as reference
          This class is an extended version of lab4 with modification.
   ========================================================================== */
class Book : public Product{
    private:
        std::string genre;
        std::string publisher;
        double discount;
    public:
        Book();

        Book(double regular_price, const std::string& product_name,
                const std::string& genre, const std::string& publisher,
                double discount);

        std::string get_genre() const;

        std::string get_publisher() const;

        double get_discount() const;

        virtual double get_retail_price() const override;

        virtual void print() const override;
};
#endif
