// main.cpp
// This file contains the 'main' function. Program execution begins and ends there.
// Author: ABLALLAH Bouchra , zakry Ibrahim , Jarry saida
// Date: 2026-05-16
// Description: This is the main file for the online store project. It contains the main function and the implementation of the user interface for both clients and admins.
// Note: This project uses the C++17 language standard version.
// Include necessary header files
#include "../header_files/product.h"
#include "../header_files/cart.h"
#include "../header_files/cartItem.h"
#include "../header_files/client.h"
#include "../header_files/order.h"
#include "../header_files/store.h"
#include "../header_files/food.h"
#include "../header_files/electronic.h"
#include "../header_files/clothes.h"
// Include necessary libraries
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std ;

// Function prototypes
void run();
void confirm();
// Create some sample products
//food
Food p1(6,"Apple", 1.99, 50,"Food",true,"2024-12-31");
Food p2(5,"Banana", 0.99, 100,"Food",true,"2024-12-31");
Food p5(1,"Pizza", 10.99, 100 ,"Food" , false , "2024-12-31");
Food p6(2,"Burger", 5.99, 200 ,"Food", true, "2024-12-31");
Food p3(3,"Pasta", 8.99, 150 ,"Food", true, "2024-12-31");
Food p4(4,"Salad", 6.99, 120 ,"Food", true, "2024-12-31");
//electronics
electronic p7(7,"Laptop", 999.99, 20 ,"Electronics", "Apple", "MacBook Pro");
electronic p8(8,"Phone", 699.99, 50 ,"Electronics", "Samsung", "Galaxy S21");
electronic p9(9,"Tablet", 399.99, 30 ,"Electronics", "Apple", "iPad Pro");
electronic p10(10,"Headphones", 199.99, 100 ,"Electronics", "Sony", "WH-1000XM4");
electronic p11(11,"Speaker", 149.99, 80 ,"Electronics", "beats", "studio3");
//clothes
Clothes p12(12,"T-Shirt", 19.99, 200 ,"Clothes", "M", "Red");
Clothes p13(13,"Jeans", 49.99, 150 ,"Clothes", "L", "Blue");
Clothes p14(14,"Jacket", 89.99, 100 ,"Clothes", "XL", "Black");
Clothes p15(15,"Dress", 59.99, 80 ,"Clothes", "S", "Green");
Clothes p16(16,"Skirt", 39.99,50,"Clothes", "M", "Yellow");
// Create a sample cart and client
Cart cart_client; 
Client c;
Client confirmClient;
// Create a sample store and add the products to it
Store S(c.loadClient("clients.txt"), vector<Product>{p1, p2, p3, p4 , p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16}, vector<Cart>());


void run (){
    bool isAdmin = false ;
    bool isClient = false ;
    bool logout= false;
    int num = -1 ;
    while(isAdmin == isClient ){
        char choice;
        cout << "++++++ Are you an Admin or a Client(A-a/C-c) ? ++++++++"<<endl;
        cin >> choice;
        if( confirmClient.getEmailClient() == "admin@domain.com" && confirmClient.getPasswordClient() == "admin" && (choice == 'A' || choice == 'a')){
            isAdmin = true;
        } else if (choice == 'C' || choice == 'c'){
            isAdmin = false ;
            isClient = true ;
        }else{
            cout << "Erreur dans le choix !";
        }
    }
    //Admin panel needs more work to be done but the client panel is fully functional and tested
    while (isAdmin == true && logout == false){
        cout <<"==== Bonjour, Admin dans le panel de controle du magasin ====="<<endl;
        cout << "Choisire une option : ========================================"<<endl;
        cout << "1 . Gerer le catalogue des produits "<<endl;
        cout << "2 . Gerer le stock des produits"<< endl ;
        cout << "3 . purches history & clients"<< endl;
        cout << "4 . sign out "<< endl ;
        cin >> num;
        cout << "=============================================================="<<endl;
    
    if (num == 1){
        int ch ;
        cout<< "===== Gerer le catalogue des produits ========================="<<endl;
        cout<< "1 . Ajouter un produit "<<endl;
        cout<< "2 . supprimer un produit "<<endl;
        cout << "3 . Afficher tous les categories et leurs produits"<<endl;
        cout << "4 . Afficher tous les Produits et leurs infos "<<endl;
        cout << "0 . retourn a l'ariere "<<endl;
        cin >> ch;
        cout << "=============================================================="<<endl;
        if (ch == 1){
            Product p;
            cout <<"==== Ajouter un produit ========"<<endl;
            cin >> p ;
            cout << "=============================================================="<<endl;
            cout << p;
            S.add_pd(p);
        }
        if(ch == 2){
            int id ;
            cout <<"==== supprimer un produit ========"<<endl;
            cout << "Enter le ID du produit a supprimer : "<<endl;
            cin >> id ;
                for (const auto& product : S.get_p()) {
                    if (product.getId_product() == id) {
                        S.del_pd(product);
                        cout << "Produit avec ID " << id << " a ete supprime." << endl;
                        break;
                    }
                }
            cout << "=============================================================="<<endl;
        }
        if (ch == 3){
            int id ;
            cout <<"====  Afficher les categories et leurs produits ========"<<endl;
            cout << "Enter la categorie (Food/Clothes/Electronics): "<<endl;
            string category ;
            cin >> category ;
            cout << "========================================================"<<endl;
            cout << "Produits dans la categorie " << category << ":" << endl;
            for (const auto& product : S.get_p()) {
                if (product.getCategory() == category) {
                    cout << product.getName_product() << " (ID: " << product.getId_product() << ")" << endl;
                }
             }
            
            cout << ""<<endl;
        }
        if(ch ==4){
            cout <<"==== Afficher tous les produits et leurs infos ========"<<endl;
            for (const auto& product : S.get_p()) {
                cout << product << endl;
            }
            cout << "========================================================"<<endl;
        }
        if (ch == 0){
            cout << "Returning to the main menu..." << endl;
            cout << "========================================================"<<endl;
            num = -1 ;
        }
    }
    if (num == 2){//needs more work ; it doesn't change the stock.
        cout <<"==== Gerer le stock des produits ========"<<endl;
        for (const auto& product : S.get_p()) {
            cout << product.getName_product() << " (ID: " << product.getId_product() << ") - Stock: " << product.getStock() << endl;
        }
        cout << "========================================================"<<endl;
        cout << "Enter le ID du produit a mettre a jour : " << endl;
        int id ;
        cin >> id ;
        for (auto& product : S.get_p()) {
            if (product.getId_product() == id) {
                cout << "Enter le nouveau stock pour " << product.getName_product() << ": " << endl;
                int newStock ;
                cin >> newStock ;
                
                (&product)->setStock(product.getStock() + newStock);
                cout << "Stock mis a jour pour " << product.getName_product() << ". Nouveau stock: " << product.getStock() << endl;
                break;
            }
        }
    }
    if (num == 3){
        cout <<"==== purches history & clients ========"<<endl;
        cout << "Clients: " << endl;
        for (const auto& client : S.get_c()) {
            cout << client.getNameClient() << " (ID: " << client.getIdClient() << ")" << endl;
            cout << "Purchase History: " << endl;
            for (const auto& purchase : client.getPurchaseHistory()) {
                cout << "- " << purchase << endl;
            }
        }
        cout << "========================================================"<<endl;
    }

    if (num == 4){
        cout << "Signing out..." << endl;
        logout = true ;
    }
    }
    while (isClient == true && logout == false){
        cout <<"==== Bonjour, Client dans le panneau de controle du magasin ====="<<endl;
        cout << "Choisir une option : ========================================"<<endl;
        cout << "1 . Afficher le catalogue des produits "<<endl;
        cout << "2 . Ajouter un produit au panier "<< endl ;
        cout << "3 . Afficher le panier "<< endl;
        cout << "4 . Passer la commande "<< endl ;
        cout << "5 . sign out "<< endl ;
        cin >> num;
        cout << "========================================================"<<endl;
        if(num == 1){
            cout <<"==== Afficher le catalogue des produits ========"<<endl;
            for (const auto& product : S.get_p()) {
                cout << product << endl;
            }
            cout << "========================================================"<<endl;
        }
        if(num == 2){
            int id ;
            cout <<"==== Ajouter un produit au panier ========"<<endl;
            cout << "Enter le ID du produit que vous voulez ajouter au panier: " << endl;
            cin >> id ;
            for ( auto& product : S.get_p()) {
                if (product.getId_product() == id) {
                    // quantity of the product to add to the cart
                    cout <<"Quantity: "<<endl;
                    int quantity ;
                    cin >> quantity ;
        
                    cart_client.addItem(product, quantity);
                    c.setCartClient(cart_client);
                    S.add_cart(c.getCartClient());
                    cout << product.getName_product() << " a ete ajoute au panier." << endl;
                    break;
                }
            }
            cout << "========================================================"<<endl;
        }
        if (num ==3){
            cout <<"==== Afficher le panier ========"<<endl;
            c.getCartClient().display();
            cout << "========================================================"<<endl;
        }
        if(num == 4){
            cout <<"==== Passer la commande ========"<<endl;
            Order order;

            for (CartItem item : c.getCartClient().getItems()) {
                order.addCartItem(item);
            }
            
            order.display();
            cout << "========================================================"<<endl;
            cout << "Merci pour votre commande!" << endl;
            c.addPurchase("Le total de la commande: " + to_string(order.getTotalPrice()));
            c.getCartClient().clear();
            cout << "========================================================"<<endl;
        }
        if (num == 5){
            cout << "Signing out..." << endl;
            logout = true ;
        }
    }
}
// to log in or register a client before accessing the client panel or the admin panel.
void confirm() {
    bool whantLOgin = true ;
    while (whantLOgin){
        char choice;
        cout << "++++++ Welcome to the online store! ++++++++"<<endl;
        cout << "1 . register"<<endl;
        cout << "2 . login"<<endl;
        cout << "3 . exit "<<endl;
        cout << " Enter your choice: " ;
        cin >> choice;
        cout << "========================================================"<<endl;
        if (choice == '1'){
            c.registerClient();
        }
        if (choice == '2'){
            
            if(confirmClient.confirmIdentity()){
                cout << "Login successful!" << endl;
                run();
                break;
            }else{
                cout << "Login failed. Please try again." << endl;
            }
        }
        if (choice == '3'){
            cout << "Exiting the program..." << endl;
            whantLOgin = false ;
            exit(0);
        }
        if(choice != '1' && choice != '2' && choice != '3'){
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    
}

int main() {
    
    confirm();

    return 0;
}