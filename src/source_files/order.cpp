#include <iostream>
#include "../Header_files/cartItem.h"
#include <vector>
#include <string>
#include "../Header_files/order.h"
#include <ctime>
#include <iomanip>
using namespace std;
Order::Order() {
    this->id_order = 0;
    this->items_order = vector<CartItem>();
    this->total_price = 0.0;
    this->status = 0;
    this->date = "";
}
Order::Order(int id_order, vector<CartItem> items_order, double total_price, int status, string date) {
    this->id_order = id_order;
    this->items_order = items_order;
    this->total_price = total_price;
    this->status = status;
    this->date = date;
}
Order::Order(const Order& other) {
    this->id_order = other.id_order;
    
    this->items_order = other.items_order;
    this->total_price = other.total_price;
    this->status = other.status;
    this->date = other.date;
}
void Order::normaliseStatus(int status) {
    if (status < 0 || status > 2) {
        cout << "Invalid status value. Setting to default (0: pending)." << endl;
        this->status = 0;
    } else {
        this->status = status;
    }
    
}
void Order::normaliseDate(string date) {
    if (date.empty()) {
        cout << "Date cannot be empty.default is today's date " << endl;
        // Set to today's date
        time_t now = time(0);
        tm *ltm = localtime(&now);
        this->date = to_string(1900 + ltm->tm_year) + "-" + to_string(1 + ltm->tm_mon) + "-" + to_string(ltm->tm_mday);
    }
}
// Getters & Setters
int Order::getIdOrder() const {
    return this->id_order;
}
void Order::setIdOrder(int id_order) {
    this->id_order = id_order;
}
vector<CartItem> Order::getItemsOrder() const {
    return this->items_order;
}
void Order::setItemsOrder(vector<CartItem> items_order) {
    this->items_order = items_order;
}
double Order::getTotalPrice() const {
    return this->total_price;
}
void Order::setTotalPrice(double total_price) {
    this->total_price = total_price;
}
int Order::getStatus() const {
    return this->status;
}
void Order::setStatus(int status) {
    normaliseStatus(status); // Ensure status is valid before setting
    this->status = status;
}
string Order::getDate() const {
    return this->date;
}
void Order::setDate(string date) {
    normaliseDate(date); // Ensure date is valid before setting
    this->date = date;
}
// Method to display order information
void Order::display() {
    cout << "Order ID: " << this->id_order << endl;
    cout << "Total Price: " << this->total_price << endl;
    cout << "total items: " << calculateTotalItems() << endl;
    cout << "total price with tva: " << calculateTotalPriceWithTva(0.2) << endl;
    cout << "total price with discount: " << calculateTotalPriceWithDiscount(0.1) << endl;
    cout << "Status: " << this->status << endl;
    cout << "Date: " << this->date << endl;
    cout << "Items: " << endl;
    for (CartItem item : this->items_order) {
        item.display();
    }
}
// Method to calculate the total price of the order
void Order::calculateTotalPrice() {
    double total = 0.0;
    for (CartItem item : this->items_order) {
        total += item.getProduct().getPrice() * item.getQuantity();
    }
    this->total_price = total;
}
// Method to calculate the total number of items in the order
int Order::calculateTotalItems() {
    int total = 0;
    for (CartItem item : this->items_order) {
        total += item.getQuantity();
    }
    return total;
}
//tva method to calculate the total price of the order with tva
double Order::calculateTotalPriceWithTva(double tva) {
    return this->total_price * (1 + tva);
}
// Method to calculate the total price of the order with discount
double Order::calculateTotalPriceWithDiscount(double discount) {
    return this->total_price * (1 - discount);
}
// Method to add a cart item to the order
void Order::addCartItem(CartItem cart_item) {
    this->items_order.push_back(cart_item);
    this->calculateTotalPrice();
}
// Method to remove a cart item from the order
void Order::removeCartItem(int id_product) {
    for (int i = 0; i < this->items_order.size(); i++) {
        if (this->items_order[i].getProduct().getId_product() == id_product) {
            this->items_order.erase(this->items_order.begin() + i);
            this->calculateTotalPrice();
            return;
        }
    }
}
// Method to clear all cart items from the order
void Order::clearCartItems() {
    this->items_order.clear();
    this->calculateTotalPrice();
}


