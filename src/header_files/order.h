#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include "client.h"
#include "cartItem.h"
#include <vector>
#include <string>

class Order {
    private :
    int id_order;
    vector<CartItem> items_order;
    double total_price;
    int status; // 0: pending, 1: completed, 2: cancelled
    string date ;
    void normaliseStatus(int status);
    void normaliseDate(string date);
    
    public:
    Order();
    Order(int id_order, vector<CartItem> items_order, double total_price, int status, string date);
    Order(const Order& other);
    
    // Getters & Setters
    int getIdOrder() const;
    void setIdOrder(int id_order);
    vector<CartItem> getItemsOrder() const;
    void setItemsOrder(vector<CartItem> items_order);
    double getTotalPrice() const;
    void setTotalPrice(double total_price);
    int getStatus() const;
    void setStatus(int status);
    string getDate() const;
    void setDate(string date);
    // Method to display order information
    void display();
    // Method to calculate the total price of the order
    void calculateTotalPrice();
    // Method to calculate the total number of items in the order
    int calculateTotalItems();
    //tva method to calculate the total price of the order with tva
    double calculateTotalPriceWithTva(double tva);
    // Method to calculate the total price of the order with discount
    double calculateTotalPriceWithDiscount(double discount);
    // Method to add a cart item to the order
    void addCartItem(CartItem cart_item);
    // Method to remove a cart item from the order
    void removeCartItem(int id_product);
    // Method to clear all cart items from the order
    void clearCartItems();

};
#endif