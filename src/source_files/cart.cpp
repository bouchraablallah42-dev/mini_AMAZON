#include <iostream>
#include <vector>
#include "../Header_files/cart.h"
#include "../Header_files/cartItem.h"
#include "../Header_files/product.h"
Cart::Cart() {
    this->items = vector<CartItem>();
}
Cart::Cart(vector<CartItem> items) {
    this->items = items;
}
Cart::Cart(const Cart& other) {
    this->items = other.items;
}
// Getters & Setters
vector<CartItem> Cart::getItems() const {
    return this->items;
}
void Cart::setItems(vector<CartItem> items) {
    this->items = items;
}
// Method to add an item to the cart
void Cart::addItem( Product p, int quantity) {
    if (p.getStock() < quantity) {
        cout << "Insufficient stock for item " << p.getName_product() << ". Item not added to cart." << endl;
        return;
    }

    CartItem item(p, quantity);
    this->items.push_back(item);
    p.reduceStock(quantity);
}
// Method to remove an item from the cart
void Cart::removeItem(int index) {
    if (index >= 0 && index < this->items.size()) {
        this->items.erase(this->items.begin() + index);
    }
    else {
        cout << "Invalid index. Cannot remove item from cart." << endl;
    }
}
// Method to calculate the total price of the cart
double Cart::calculateTotal() {
    double total = 0.0;
    for (CartItem item : this->items) {
        total += item.calculateTotalPrice();
    }
    return total;
}
// Method to display cart information
void Cart::display() {
    cout << "======== Cart Information:=========" << endl;
    if(this->items.empty()) {
        cout << "Your cart is empty." << endl;
        return;
    }
    for (CartItem item : this->items) {
        item.display();
    }
    cout << "==================================" << endl;
    cout << "Total Price: " << this->calculateTotal() << endl;
    cout << "==================================" << endl;
}
// Method to clear the cart
void Cart::clear() {
    this->items.clear();
}
