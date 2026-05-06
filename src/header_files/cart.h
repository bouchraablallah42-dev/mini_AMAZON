#ifndef CART_H
#define CART_H

#include <iostream>
#include <vector>
#include "cartItem.h"
#include "product.h"

class Cart {
    private:
    vector <CartItem> items;

    public:
    Cart();
    Cart(vector<CartItem> items);
    Cart(const Cart& other) ;
    // Getters & Setters
    vector<CartItem> getItems() const;
    void setItems(vector<CartItem> items);
    // Method to add an item to the cart
    void addItem(Product p , int quantity);
    // Method to remove an item from the cart
    void removeItem(int index);
    // Method to calculate the total price of the cart
    double calculateTotal();
    // Method to display cart information
    void display();
    // Method to clear the cart
    void clear();
};

#endif