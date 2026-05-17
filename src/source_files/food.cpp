
#include <iostream>
#include <ctime>
#include "../header_files/product.h"
#include "../header_files/food.h"
using namespace std ;
void Food::normalise (string date){
    if (date.empty()) {
        cout << "Date cannot be empty.default is today's date " << endl;
        // Set to today's date
        time_t now = time(0);
        tm *ltm = localtime(&now);
        this->expiration_date = to_string(1900 + ltm->tm_year) + "-" + to_string(1 + ltm->tm_mon) + "-" + to_string(ltm->tm_mday);
    }
};
Food::Food() : Product() {
    this->isOrganic = false;
    this->expiration_date = "";
}
Food::Food(int id_product, string name_product , double price , int stock,string type, bool isOrganic , string expiration_date) : Product(id_product, name_product, price, stock, "Food") {
    this->isOrganic = isOrganic;
    this->expiration_date = expiration_date;
    this->normalise(this->expiration_date);
};
Food::Food(const Food& other) : Product(other) {
    this->isOrganic = other.isOrganic;
    this->expiration_date = other.expiration_date;
    this->normalise(this->expiration_date);
};
bool Food::get_is_organic()const{
    return this->isOrganic;
}
void Food::set_is_organic(bool is_organic){
    this->isOrganic = is_organic;
}
string Food::get_expiration_date()const{
    return this->expiration_date;
}
void Food::set_expiration_date(string expiration_date ){
    normalise(expiration_date);
    this->expiration_date = expiration_date;
}
ostream& operator<<(ostream& out , const Food& f){
    out << "Food Product: " << f.getName_product() << endl;
    out << "Price: $" << f.getPrice() << endl;
    out << "Stock: " << f.getStock() << endl;
    out << "Organic: " << (f.get_is_organic() ? "Yes" : "No") << endl;
    out << "Expiration Date: " << f.get_expiration_date() << endl;
    return out;
}