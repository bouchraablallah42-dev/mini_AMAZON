#include "../header_files/electronic.h"
#include "../header_files/product.h"
#include <iostream>
#include <string>
using namespace std ;
electronic::electronic() : Product() {
    this->brand = "";
    this->model = "";
}
electronic::electronic(int id_product, string name_product, double price_product, int stock_product,string type, string brand, string model) : Product(id_product, name_product, price_product, stock_product , "Electronics") {
    this->brand = brand;
    this->model = model;
}
electronic::electronic(const electronic& other) : Product(other) {
    this->brand = other.brand;
    this->model = other.model;
}
string electronic::getBrand() const {
    return this->brand;
}
string electronic::getModel() const {
    return this->model;
}
void electronic::setBrand(string brand) {
    this->brand = brand;
}
void electronic::setModel(string model) {
    this->model = model;
}
ostream& operator<<(ostream& out , const electronic& e){
    out << "Electronic Product: " << e.getName_product() << endl;
    out << "Price: $" << e.getPrice() << endl;
    out << "Stock: " << e.getStock() << endl;
    out << "Brand: " << e.getBrand() << endl;
    out << "Model: " << e.getModel() << endl;
    return out;
}
