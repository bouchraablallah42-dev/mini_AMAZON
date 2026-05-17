#ifndef FOOD_H
#define FOOD_H

#include <iostream>
#include "product.h"
using namespace std ;
class Food : public Product{
    private:
        bool isOrganic;
        string expiration_date ;
        void normalise (string date);
    public:
        Food() ;
        Food (int id_product, string name_product , double price , int stock,string type, bool isOrganic , string expiration_date);
        Food (const Food& other);

        //
        bool get_is_organic ()const;
        void set_is_organic (bool is_organic);
        string get_expiration_date ()const;
        void set_expiration_date(string expiration_date);
        //
        friend ostream& operator<<(ostream& out , const Food& f);

};
#endif // FOOD_H
