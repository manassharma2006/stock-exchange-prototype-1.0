#include "Staff.h"
#include <iostream>
using namespace std;

int Staff::totalStaff = 0;

Staff::Staff(int id, string name, string email, string role)
    : Person(name, email) {
    this->staffID = id;
    this->role    = role;
    totalStaff++;
    cout << "[Staff] Hired: " << name << " as " << role << endl;
}

Staff::~Staff() {
    totalStaff--;
    cout << "[Staff] Left: " << name << endl;
}

void Staff::resolveComplaint(Complaint* complaint) {
    complaint->updateStatus("RESOLVED");
    cout << "[Staff] " << name << " resolved complaint #"
         << complaint->getID() << endl;
}

void Staff::assignComplaint(Complaint* complaint, string assignTo) {
    complaint->updateStatus("ASSIGNED");
    cout << "[Staff] Complaint #" << complaint->getID()
         << " assigned to " << assignTo << " by " << name << endl;
}

void Staff::displayInfo() {
    cout << "-- Staff --" << endl;
    Person::displayInfo();
    cout << "Role: " << role << endl;
}
