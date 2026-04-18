#include "User.h"
#include <iostream>
using namespace std;

int User::totalUsers = 0;

User::User(int id, string name, string email,
           string contact, string accType)
    : Person(name, email), portfolio(id) {
    this->userID       = id;
    this->contactNumber = contact;
    this->accountType  = accType;
    this->orderCount    = 0;
    this->complaintCount = 0;

    for (int i = 0; i < MAX_ORDERS; i++)     orders[i]     = NULL;
    for (int i = 0; i < MAX_COMPLAINTS; i++) complaints[i] = NULL;

    totalUsers++;
    cout << "[User] Account created: " << name
         << " [" << accType << "]" << endl;
}

User::~User() {
    totalUsers--;
    cout << "[User] Account closed: " << name << endl;
}

void User::placeOrder(TradeOrder* order) {
    if (orderCount < MAX_ORDERS) {
        orders[orderCount] = order;
        orderCount++;
        cout << "[User] " << name << " placed order #"
             << order->getID() << endl;
    } else {
        cout << "[User] Order limit reached for " << name << endl;
    }
}

void User::viewPortfolio() {
    cout << "[User] " << name << "'s Portfolio:" << endl;
    portfolio.displayInfo();
}

void User::fileComplaint(Complaint* complaint) {
    if (complaintCount < MAX_COMPLAINTS) {
        complaints[complaintCount] = complaint;
        complaintCount++;
        cout << "[User] " << name << " filed complaint #"
             << complaint->getID() << endl;
    }
}

Portfolio* User::getPortfolio() {
    return &portfolio;
}

void User::displayInfo() {
    cout << "-- User --" << endl;
    Person::displayInfo();   // call base class version first
    cout << "Contact: " << contactNumber
         << " | Account: " << accountType << endl;
}
