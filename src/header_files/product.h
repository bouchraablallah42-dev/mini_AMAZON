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
        string category;
    public:
        Product();
        Product(int id_product, string name_product , double price , int stock , string category);
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
        string getCategory() const;
        void setCategory(string category);
        // Method to reduce stock when a product is added to the cart
        void reduceStock(int quantity);
        // Overloading operators
        friend ostream& operator<<(ostream& out , const Product& p);
        friend istream& operator>>(istream& in ,Product& p);
        // Destructor       
        ~Product();

};




#endif // PRODUCT_H