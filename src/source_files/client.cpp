#include <iostream>
#include <string.h>
#include <vector>
#include <iomanip>
#include <fstream>
#include "../Header_files/client.h"
#include "../Header_files/cart.h"

Client::Client() {
    this->id_client = 0;
    this->name_client = "";
    this->email_client = "";
    this->password_client = "";
    this->cart_client = Cart();
    this->purchase_history = vector<string>();
}
Client::Client(int id_client, string name_client, string email_client , string password_client , Cart cart_client , vector<string> purchase_history) {
    this->id_client = id_client;
    this->name_client = name_client;
    this->email_client = email_client;
    this->password_client = password_client;
    this->cart_client = cart_client;
    this->purchase_history = purchase_history;
}
Client::Client(const Client& other) {
    this->id_client = other.id_client;
    this->name_client = other.name_client;
    this->email_client = other.email_client;
    this->password_client = other.password_client;
    this->cart_client = other.cart_client;
    this->purchase_history = other.purchase_history;
}
// Getters & Setters
int Client::getIdClient() const { return this->id_client;}
void Client::setIdClient(int id_client) {
    this->id_client = id_client;
}
string Client::getNameClient() const {return this->name_client;}
void Client::setNameClient(string name_client) {
    this->name_client = name_client;
}
string Client::getEmailClient() const { return this->email_client;}
void Client::setEmailClient(string email_client) {
    this->email_client = email_client;
}
string Client::getPasswordClient() const {return this->password_client;}
void Client::setPasswordClient(string password_client) {
    this->password_client = password_client;
}
Cart Client::getCartClient() const {return this->cart_client;}
void Client::setCartClient(Cart cart_client) {
    this->cart_client = cart_client;
}
void Client::registerClient() {
    this->id_client += 1; // Generate a random ID for the client
    cout << "Enter client name: ";
    cin >> this->name_client;
    cout << "Enter client email: ";
    cin >> this->email_client;
    cout << "Enter client password: ";
    cin >> this->password_client;
    if ("clients.txt" == ""){
        this->id_client = 1 ;
    } else {
        ifstream file("clients.txt");
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                int id;
                string name, email, password;
                istringstream iss(line);
                if (!(iss >> id >> name >> email >> password)) { break; }
                this->id_client = id + 1; // Increment the ID for the new client
            }
            file.close();
        } else {
            cout << "Unable to open file." << endl;
        }
    }
    ofstream file("clients.txt", ios::app);

    if (file.is_open()) {
        file << this->id_client << " " << this->name_client << " " << this->email_client << " " << this->password_client << endl;
        file.close();
        cout << "Client registered successfully!" << endl;
    } else {
        cout << "Unable to open file." << endl;
    }
}
// Method to load clients from a file
vector<Client> Client::loadClient(string filename){
    vector<Client> clients;
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        int id_client;
        string name_client,  email_client, password_client;
        while (file >>id_client>>name_client>>email_client >> password_client) {
            clients.push_back(Client(id_client, name_client, email_client, password_client, Cart(), vector<string>()));
        }
        file.close();
    } else {
        cout << "Unable to open file." << endl;
    }
    return clients;
}
vector<string> Client::getPurchaseHistory() const {
    return this->purchase_history;
}
void Client::setPurchaseHistory(vector<string> purchase_history) {
    this->purchase_history = purchase_history;
}
// methode to confirm the client identity by checking the email and password
bool Client::confirmIdentity() {
    vector<Client> client_data = loadClient("clients.txt");
    string email, password;
    int i =0;
    do{
        cout << "Confirming identity for email: ";
        cin >> email;
        cout << "Confirming identity for password: ";
        cin >> password;
        for (const auto& client : client_data) {
        if (client.getEmailClient() == email && client.getPasswordClient() == password) {
            cout << "Identity confirmed successfully!" << endl; 
            this->id_client = client.getIdClient();
            this->name_client = client.getNameClient(); 
            this->email_client = client.getEmailClient();
            this->password_client = client.getPasswordClient();
            this->cart_client = client.getCartClient();
            this->purchase_history = client.getPurchaseHistory();
            return true;
        } 
    }
    cout << "Identity confirmation failed. Incorrect email or password." << endl;
    i++;
    }while (i < 3);
    cout << "Too many failed attempts. Identity confirmation failed." << endl;
    return false; 
}
// Method to display client information
void Client::display() {
     if(confirmIdentity()){
    cout << "Client ID: " << this->getIdClient() << endl;
    cout << "Client Name: " << this->getNameClient() << endl;
    cout << "Client Email: " << this->getEmailClient() << endl;
    cout << "Client Cart: " << endl;
    this->cart_client.display();
    cout << "Client Purchase History: " << endl;
    for (string purchase : this->getPurchaseHistory()) {
        cout << purchase << endl;
    }}
}

// Method to add a purchase to the purchase history
void Client::addPurchase(string purchase) {
    this->purchase_history.push_back(purchase);
}
// Method to clear the purchase history
void Client::clearPurchaseHistory() {
    this->purchase_history.clear();
}
