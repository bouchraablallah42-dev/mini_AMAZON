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
    
}
Product::Product(int id_product, string name_product , double price , int stock) {
    this->id_product = id_product;
    this->name_product = name_product;
    this->price = price;
    this->stock = stock;
}
Product::Product(const Product& other) {
    this->id_product = other.id_product;
    this->name_product = other.name_product;
    this->price = other.price;
    this->stock = other.stock;
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
// Method to display product information
void Product::display() {
    cout << "Product Information:" << endl;
    cout << "ID: " << this->id_product << endl;
    cout << "Name: " << this->name_product << endl;
    cout << "Price: " << fixed << setprecision(2) << this->price << endl;
    cout << "Stock: " << this->stock << endl;
    cout << "-----------------------------" << endl;
}
void Product::reduceStock(int quantity) {
    if (quantity > this->stock) {
        cout << "Not enough stock available!" << endl;
    } else {
        this->stock -= quantity;
    }
}
// Destructor
Product::~Product() {
    // No dynamic memory to free

}