#include <string>
#include <iostream>
#include "../Header_files/product.h"
#include <iomanip>
using namespace std;
Product::Product() {
    this->id_product = 0;
    this->name_product = "";
    this->price = 0.0;
    this->stock = 0;
    this->category = "";
    
}
Product::Product(int id_product, string name_product , double price , int stock , string category) {
    this->id_product = id_product;
    this->name_product = name_product;
    this->price = price;
    this->stock = stock;
    this->category = category;
}
Product::Product(const Product& other) {
    this->id_product = other.id_product;
    this->name_product = other.name_product;
    this->price = other.price;
    this->stock = other.stock;
    this->category = other.category;
}
// Getters & Setters
int Product::getId_product() const {
    return this->id_product;
}
void Product::setId_product(int id_product) {
    this->id_product = id_product;
}
string Product::getName_product() const {
    return this->name_product;
}
void Product::setName_product(string name_product) {
    this->name_product = name_product;
}
double Product::getPrice() const {
    return this->price;
}
void Product::setPrice(double price) {
    this->price = price;
}
int Product::getStock() const {
    return this->stock;
}
void Product::setStock(int stock) {
    this->stock = stock;
}
string Product::getCategory() const {
    return this->category;
}
void Product::setCategory(string category) {
    this->category = category;
}
// 
void Product::reduceStock(int quantity) {
    if (quantity > this->stock) {
        cout << "Not enough stock available!" << endl;
    } else {
        this->stock -= quantity;
    }
}
// Method to display product information??

ostream &operator<<(ostream& out , const Product& p){
    out << setfill('0')
    << "Product Information:------------------------------" << endl
    << "ID: " << p.getId_product() <<endl
    << "Name: " << p.getName_product() << endl
    << "Price: " << fixed << setprecision(2) << p.getPrice() << endl
    << "Stock: " << p.getStock() << endl
    << "Category: " << p.getCategory() << endl
    << "---------------------------------------------------" << endl;
    return out;

}
istream& operator>>(istream& in , Product& p){
    string id_product_str, price_str, stock_str;
    cout << "Entere les info suivants : "<<endl;
    cout << "ID : " ;
    in >> id_product_str ;
    p.setId_product(stoi(id_product_str));
    cout << "Nom du Produit : " ;
    in >> p.name_product ;
    cout << "Prix (en DH) : " ;
    in >> price_str;
    p.setPrice(stod(price_str));
    cout << "Stock : "; 
    in >> stock_str;
    p.setStock(stoi(stock_str));
    cout << "Category (Food/Clothes/Electronics): " ;
    in >> p.category ;
    return in ;
}
// Destructor
Product::~Product() {
    // No dynamic memory to free

}