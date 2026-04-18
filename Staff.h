#ifndef STAFF_H
#define STAFF_H

#include "Person.h"
#include "Complaint.h"

class Staff : public Person {
private:
    int    staffID;
    string role;

public:
    static int totalStaff;

    Staff(int id, string name, string email, string role);
    ~Staff();

    void resolveComplaint(Complaint* complaint);
    void assignComplaint(Complaint* complaint, string assignTo);

    void displayInfo();  // overrides Person::displayInfo
};

#endif
