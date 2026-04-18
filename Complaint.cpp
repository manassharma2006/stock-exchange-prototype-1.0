#include "Complaint.h"
#include <iostream>
using namespace std;

int Complaint::totalComplaints = 0;

Complaint::Complaint(int id, string type, string date) {
    this->complaintID = id;
    this->type        = type;
    this->status      = "OPEN";
    this->dateFiled   = date;
    totalComplaints++;
    cout << "[Complaint] Filed #" << id << " [" << type << "]" << endl;
}

Complaint::~Complaint() {
    totalComplaints--;
    cout << "[Complaint] Removed #" << complaintID << endl;
}

int    Complaint::getID()     { return complaintID; }
string Complaint::getStatus() { return status; }

void Complaint::updateStatus(string newStatus) {
    status = newStatus;
    cout << "[Complaint] #" << complaintID
         << " status -> " << newStatus << endl;
}

void Complaint::displayInfo() {
    cout << "  Complaint #" << complaintID
         << " | Type: "   << type
         << " | Status: " << status
         << " | Filed: "  << dateFiled << endl;
}
