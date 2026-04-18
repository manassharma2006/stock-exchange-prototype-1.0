#ifndef COMPLAINT_H
#define COMPLAINT_H

#include <string>
using namespace std;

class Complaint {
private:
    int    complaintID;
    string type;
    string status;
    string dateFiled;

public:
    static int totalComplaints;

    Complaint(int id, string type, string date);
    ~Complaint();

    int    getID();
    string getStatus();

    void updateStatus(string newStatus);
    void displayInfo();
};

#endif
