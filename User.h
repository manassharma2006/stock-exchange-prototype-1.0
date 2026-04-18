#ifndef USER_H
#define USER_H

#include "Person.h"
#include "Portfolio.h"
#include "TradeOrder.h"
#include "Complaint.h"

#define MAX_ORDERS     10
#define MAX_COMPLAINTS 10

class User : public Person {
private:
    int       userID;
    string    contactNumber;
    string    accountType;
    Portfolio portfolio;

    TradeOrder* orders[MAX_ORDERS];
    int         orderCount;

    Complaint*  complaints[MAX_COMPLAINTS];
    int         complaintCount;

public:
    static int totalUsers;

    User(int id, string name, string email,
         string contact, string accType);
    ~User();

    void placeOrder(TradeOrder* order);
    void viewPortfolio();
    void fileComplaint(Complaint* complaint);

    Portfolio* getPortfolio();

    void displayInfo();  // overrides Person::displayInfo
};

#endif
