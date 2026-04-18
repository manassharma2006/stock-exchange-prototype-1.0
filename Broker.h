#ifndef BROKER_H
#define BROKER_H

#include "Person.h"
#include "TradeOrder.h"
#include "Complaint.h"
#include "User.h"

#define MAX_MANAGED_USERS 10

class Broker : public Person {
private:
    int    brokerID;
    int    experienceYears;
    User*  managedUsers[MAX_MANAGED_USERS];
    int    userCount;

public:
    static int totalBrokers;

    Broker(int id, string name, string email, int expYears);
    ~Broker();

    void addUser(User* user);
    void processOrder(TradeOrder* order);
    void handleComplaint(Complaint* complaint);

    void displayInfo();  // overrides Person::displayInfo
};

#endif
