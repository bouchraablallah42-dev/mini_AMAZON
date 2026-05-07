#include <iostream>
#include "../Header_files/product.h"
#include "../Header_files/cartItem.h"
CartItem::CartItem() {
    this->product = Product();
    this->quantity = 0;
}
CartItem::CartItem(Product product , int quantity) {
    this->product = product;
    this->quantity = quantity;
}
CartItem::CartItem(const CartItem& other) {
    this->product = other.product;
    this->quantity = other.quantity;
}
// Getters & Setters
Product CartItem::getProduct() const {
    return this->product;
}
void CartItem::setProduct(Product product) {
    this->product = product;
}
int CartItem::getQuantity() const {
    return this->quantity;
}
void CartItem::setQuantity(int quantity) {
    this->quantity = quantity;
}
// Method to display cart item information
void CartItem::display() {
    cout << "Product: " << this->product.getName_product() << endl;
    cout << "Price: " << this->product.getPrice() << endl;
    cout << "Quantity: " << this->quantity << endl;
}
double CartItem::calculateTotalPrice() {
    return this->product.getPrice() * this->quantity;
}
// Destructor
CartItem::~CartItem() {
    // No dynamic memory to free
}
