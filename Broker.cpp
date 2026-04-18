#include "Broker.h"
#include <iostream>
using namespace std;

int Broker::totalBrokers = 0;

Broker::Broker(int id, string name, string email, int expYears)
    : Person(name, email) {
    this->brokerID       = id;
    this->experienceYears = expYears;
    this->userCount       = 0;

    for (int i = 0; i < MAX_MANAGED_USERS; i++) managedUsers[i] = NULL;

    totalBrokers++;
    cout << "[Broker] Registered: " << name
         << " (" << expYears << " yrs)" << endl;
}

Broker::~Broker() {
    totalBrokers--;
    cout << "[Broker] Removed: " << name << endl;
}

void Broker::addUser(User* user) {
    if (userCount < MAX_MANAGED_USERS) {
        managedUsers[userCount] = user;
        userCount++;
        cout << "[Broker] " << name << " now manages "
             << user->getName() << endl;
    }
}

void Broker::processOrder(TradeOrder* order) {
    cout << "[Broker] " << name << " processing order #"
         << order->getID() << endl;
    order->executeOrder();
}

void Broker::handleComplaint(Complaint* complaint) {
    complaint->updateStatus("UNDER_REVIEW");
    cout << "[Broker] " << name << " is reviewing complaint #"
         << complaint->getID() << endl;
}

void Broker::displayInfo() {
    cout << "-- Broker --" << endl;
    Person::displayInfo();
    cout << "Experience: " << experienceYears << " years"
         << " | Manages: " << userCount << " users" << endl;
}
