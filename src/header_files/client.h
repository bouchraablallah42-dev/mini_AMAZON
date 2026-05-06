#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string.h>
#include <vector>
#include "cart.h"

using namespace std;

class Client {
    private:
    int id_client;
    string name_client;
    string email_client;
    string password_client;
    Cart cart_client ;
    vector<string> purchase_history;
    public:
    Client();
    Client(int id_client, string name_client, string email_client , string password_client , Cart cart_client , vector<string> purchase_history);
    Client(const Client& other);
    // Getters & Setters
    int getIdClient() const;
    void setIdClient(int id_client);
    string getNameClient() const;
    void setNameClient(string name_client);
    string getEmailClient() const;
    void setEmailClient(string email_client);
    string getPasswordClient() const;
    void setPasswordClient(string password_client);
    Cart getCartClient() const;
    void setCartClient(Cart cart_client);
    vector<string> getPurchaseHistory() const;
    void setPurchaseHistory(vector<string> purchase_history);
    // Method to register a new client
    void registerClient();
    // Method to load clients from a file
    vector<Client> loadClient() ;
    // methode to confirm the client identity by checking the email and password
    bool confirmIdentity();
    // Method to display client information
    void display();
    // Method to add a purchase to the purchase history
    void addPurchase(string purchase);
    // Method to clear the purchase history
    void clearPurchaseHistory();



};
#endif 