#include "../header_files/clothes.h"
#include "../header_files/product.h"
#include <iostream>
using namespace std ;

Clothes::Clothes() : Product() {
    this->size = "";
    this->color = "";
}
Clothes::Clothes(int id_product, string name_product, double price_product, int stock_product, string category, string size, string color) : Product(id_product, name_product, price_product, stock_product, "Clothes") {
    this->size = size;
    this->color = color;
}
Clothes::Clothes(const Clothes& other) : Product(other) {
    this->size = other.size;
    this->color = other.color;
}
string Clothes::getSize() const {
    return this->size;
}
void Clothes::setSize(string size) {
    this->size = size;
}
string Clothes::getColor() const {
    return this->color;
}
void Clothes::setColor(string color) {
    this->color = color;
}
ostream& operator<<(ostream& out , const Clothes& c){
    out << "Clothes Product: " << c.getName_product() << endl;
    out << "Price: $" << c.getPrice() << endl;
    out << "Stock: " << c.getStock() << endl;
    out << "Size: " << c.getSize() << endl;
    out << "Color: " << c.getColor() << endl;
    return out;
}