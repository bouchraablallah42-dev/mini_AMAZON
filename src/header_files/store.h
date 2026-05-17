#ifndef STORE_H
#define STORE_H

#include <iostream>
#include <vector>
#include "client.h"
#include "product.h"
#include "cart.h"
#include "food.h"
#include "electronic.h"
#include "clothes.h"
using namespace std ;
class Store {
    protected : 
    vector <Client> c ;
    vector <Product> p ;
    vector <Food> foodF ;
    vector <electronic> electronicF ;
    vector <Clothes> clothesF ;
    vector <Cart> cart ;
    public:
        Store();
        Store(vector <Client> c,vector <Product> p,vector <Cart> cart);
        Store(const Store& S);
        vector <Client> get_c ()const;
        void set_c(vector<Client> c);
        vector <Product> get_p ()const;
        void set_p(vector<Product> p);
        vector <Cart> get_cart ()const;
        void set_cart(vector<Cart> cartm);
        vector <Food> get_foodF() const;
        void set_foodF(const vector<Food>& foodF);
        vector <electronic> get_electronicF() const;
        void set_electronicF(const vector<electronic>& electronicF);
        vector <Clothes> get_clothesF() const;
        void set_clothesF(const vector<Clothes>& clothesF);
        

        //
        void add_pd(Product p);
        void del_pd(Product p);
        void add_cl(Client cl);
        void del_cl(Client cl);
        void add_cart(Cart c);
        void del_cart(Cart c);

        //
        friend ostream& operator<<(ostream& out , const Store& s);

};
#endif // STORE_H
