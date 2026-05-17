#ifndef CLOTHES_H
#define CLOTHES_H
#include <iostream>
#include <string>
#include "product.h"

using namespace std ;
class Clothes : public Product {
    private :
        string size ;
        string color ;
    public:
        Clothes();
        Clothes(int id_product, string name_product, double price_product, int stock_product , string type, string size, string color);
        Clothes(const Clothes& other);
        string getSize() const;
        void setSize(string size);
        string getColor() const;
        void setColor(string color);
        friend ostream& operator<<(ostream& out , const Clothes& c);
};
#endif // CLOTHES_H