
#include <iostream>
#include <vector>
#include "../header_files/client.h"
#include "../header_files/product.h"
#include "../header_files/cart.h"
#include "../header_files/store.h"

using namespace std;

Store::Store(){};
Store::Store(vector <Client> c,vector <Product> p,vector <Cart> cart){
    this->c = c;
    this->p = p;
    this->cart = cart;
};
Store::Store(const Store& S){
    this->c = S.c;
    this->p = S.p;
    this->cart = S.cart;

}
vector<Client> Store::get_c ()const{
    return this->c;

};
void Store::set_c(vector<Client> c){
    this->c = c;
};
vector <Product> Store::get_p ()const{
    return this->p;
};
void Store::set_p(vector<Product> p){
    this->p = p;
};
vector <Cart> Store::get_cart ()const{
    return this->cart;
};
void Store::set_cart(vector<Cart> cart){
    this->cart = cart;
};
vector <Food> Store::get_foodF() const {
    return this->foodF;
}
void Store::set_foodF(const vector<Food>& foodF) {
    this->foodF = foodF;
}
vector <electronic> Store::get_electronicF() const {
    return this->electronicF;
}
void Store::set_electronicF(const vector<electronic>& electronicF) {
    this->electronicF = electronicF;
}
vector <Clothes> Store::get_clothesF() const {
    return this->clothesF;
}
void Store::set_clothesF(const vector<Clothes>& clothesF) {
    this->clothesF = clothesF;
};

//
void Store::add_pd(Product p){
    this->p.push_back(p);
};
void Store::del_pd(Product p){
    for (int i = 0; i < this->p.size(); i++) {
        if (this->p[i].getId_product() == p.getId_product()) {
            this->p.erase(this->p.begin() + i);
            break;
        }
    }
};
void Store::add_cl(Client cl){
    this->c.push_back(cl);
};
void Store::del_cl(Client cl){
    for (int i = 0; i < this->c.size(); i++) {
        if (this->c[i].getIdClient() == cl.getIdClient()) {
            this->c.erase(this->c.begin() + i);
            break;
        }
    }
};
void Store::add_cart(Cart c){
    this->cart.push_back(c);
};
void Store::del_cart(Cart c){

};

//
ostream& operator<<(ostream& out , const Store& s){
    out << "Clients: " << endl;
    for (const auto& client : s.c) {
        out << client.getNameClient() << " (ID: " << client.getIdClient() << ")" << endl;
    }
    out << "Products: " << endl;
    for (const auto& product : s.p) {
        out << product.getName_product() << " (ID: " << product.getId_product() << ")" << endl;
    }
    return out;
};