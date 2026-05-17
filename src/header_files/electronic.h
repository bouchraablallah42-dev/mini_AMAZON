#ifndef ELECTRONIC_H
#define ELECTRONIC_H
#include <iostream>
#include <string>
#include "product.h"

using namespace std ;
class electronic : public Product {
    private :
        string brand ;
        string model ;
    public:
        electronic();
        electronic(int id_product, string name_product, double price_product, int stock_product,string type, string brand, string model);
        electronic(const electronic& other);
        string getBrand() const;
        void setBrand(string brand);
        string getModel() const;
        void setModel(string model);
        friend ostream& operator<<(ostream& out , const electronic& e);
};
#endif // ELECTRONIC_H