#ifndef PRODUCT_H
#define PRODUCT_H


#include <string>
using namespace std;
class Product {
    protected:
        int id_product;
        string name_product;
        double price;
        int stock;
    public:
        Product();
        Product(int id_product, string name_product , double price , int stock );
        Product(const Product& other);
        // Getters & Setters 
        int getId_product() const;
        void setId_product(int id_product);
        string getName_product() const;
        void setName_product(string name_product);
        double getPrice() const;
        void setPrice(double price);
        int getStock() const;
        void setStock(int stock);
        // Method to display product information
        void display();
        void reduceStock(int quantity);
        // Destructor       
        ~Product();

};




#endif // PRODUCT_H