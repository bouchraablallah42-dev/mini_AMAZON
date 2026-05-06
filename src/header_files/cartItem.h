#ifndef CART_ITEM_H
#define CART_ITEM_H

#include <iostream>
#include "product.h"

class CartItem {
    private:
    Product product ;
    int quantity;

    public:
    CartItem();
    CartItem(Product product , int quantity);
    CartItem(const CartItem& other);
    // Getters & Setters
    Product getProduct() const;
    void setProduct(Product product);
    int getQuantity() const;    
    void setQuantity(int quantity);
    // Method to display cart item information
    void display();
    double calculateTotalPrice();
     // Destructor  
    ~CartItem();

};
#endif  