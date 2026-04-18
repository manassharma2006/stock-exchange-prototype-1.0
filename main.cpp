#include <iostream>
#include "Stock.h"
#include "Portfolio.h"
#include "Complaint.h"
#include "TradeOrder.h"
#include "User.h"
#include "Staff.h"
#include "Broker.h"

using namespace std;

// helper to print a section heading
void heading(string title) {
    cout << "\n========================================" << endl;
    cout << "  " << title << endl;
    cout << "========================================" << endl;
}

// demonstrates polymorphism — takes a base class pointer
// calls the correct overridden displayInfo() at runtime
void showPersonInfo(Person* p) {
    p->displayInfo();
}

int main() {

    // ── 1. Create stocks ─────────────────────────────────────────────────────
    heading("1. Stocks");
    Stock s1(101, "TECH", 150.00, 500);
    Stock s2(102, "ENRG",  75.00, 800);
    s1.displayInfo();
    s2.displayInfo();

    // ── 2. Create users (Inheritance: User → Person) ──────────────────────────
    heading("2. Users  [Inheritance]");
    User alice(1, "Alice", "alice@mail.com", "9876543210", "Premium");
    User bob  (2, "Bob",   "bob@mail.com",   "9123456780", "Standard");

    // ── 3. Create staff (Inheritance: Staff → Person) ─────────────────────────
    heading("3. Staff  [Inheritance]");
    Staff mike(1, "Mike", "mike@firm.com", "Support");

    // ── 4. Create broker (Inheritance: Broker → Person) ───────────────────────
    heading("4. Broker  [Inheritance]");
    Broker james(1, "James", "james@firm.com", 10);
    james.addUser(&alice);
    james.addUser(&bob);

    // ── 5. Polymorphism ────────────────────────────────────────────────────────
    heading("5. Polymorphism  [virtual displayInfo]");

    // Array of base class pointers pointing to different subclass objects.
    // At runtime C++ looks up the vtable and calls the correct version.
    Person* people[3];
    people[0] = &alice;
    people[1] = &mike;
    people[2] = &james;

    for (int i = 0; i < 3; i++) {
        showPersonInfo(people[i]);  // correct subclass version fires each time
        cout << endl;
    }

    // ── 6. Place and execute trade orders ─────────────────────────────────────
    heading("6. Trade Orders");

    // Alice buys 10 TECH shares
    TradeOrder o1(1, 10, "BUY", &s1);
    alice.placeOrder(&o1);
    james.processOrder(&o1);             // broker executes it
    alice.getPortfolio()->addStock(&s1, 10);

    // Alice buys 20 ENRG shares
    TradeOrder o2(2, 20, "BUY", &s2);
    alice.placeOrder(&o2);
    james.processOrder(&o2);
    alice.getPortfolio()->addStock(&s2, 20);

    // Bob buys 5 TECH shares
    TradeOrder o3(3, 5, "BUY", &s1);
    bob.placeOrder(&o3);
    james.processOrder(&o3);
    bob.getPortfolio()->addStock(&s1, 5);

    // ── 7. View portfolios ────────────────────────────────────────────────────
    heading("7. Portfolio View");
    alice.viewPortfolio();
    bob.viewPortfolio();

    // ── 8. Price update — portfolio value changes automatically ───────────────
    heading("8. Price Update");
    s1.updatePrice(165.00);
    s2.updatePrice(80.00);
    cout << "\nAfter price update:" << endl;
    alice.viewPortfolio();

    // ── 9. Sell order ─────────────────────────────────────────────────────────
    heading("9. Sell Order");
    TradeOrder o4(4, 5, "SELL", &s1);
    alice.placeOrder(&o4);
    james.processOrder(&o4);
    alice.getPortfolio()->removeStock("TECH", 5);
    alice.viewPortfolio();

    // ── 10. Cancel order ──────────────────────────────────────────────────────
    heading("10. Cancel Order");
    TradeOrder o5(5, 999, "BUY", &s2);
    bob.placeOrder(&o5);
    o5.cancelOrder();
    o5.displayInfo();

    // ── 11. Complaint lifecycle ────────────────────────────────────────────────
    heading("11. Complaint Lifecycle");
    Complaint c1(501, "Order Delay",       "2025-04-11");
    Complaint c2(502, "Wrong Statement",   "2025-04-11");

    alice.fileComplaint(&c1);
    bob.fileComplaint(&c2);

    james.handleComplaint(&c1);         // broker reviews
    mike.resolveComplaint(&c1);         // staff resolves
    mike.assignComplaint(&c2, "Back Office");

    c1.displayInfo();
    c2.displayInfo();

    // ── 12. Login / logout (virtual methods via base pointer) ─────────────────
    heading("12. Login / Logout  [virtual methods]");
    for (int i = 0; i < 3; i++) {
        people[i]->login();
        people[i]->logout();
    }

    // ── 13. Static variable summary ───────────────────────────────────────────
    heading("13. Static Variable Summary");
    cout << "Total Person instances : " << Person::totalPersons   << endl;
    cout << "Total Users            : " << User::totalUsers        << endl;
    cout << "Total Staff            : " << Staff::totalStaff       << endl;
    cout << "Total Brokers          : " << Broker::totalBrokers    << endl;
    cout << "Total Stocks           : " << Stock::totalStocks      << endl;
    cout << "Total TradeOrders      : " << TradeOrder::totalOrders << endl;
    cout << "Total Complaints       : " << Complaint::totalComplaints << endl;

    heading("14. Program ends — destructors fire automatically");
    // All local objects go out of scope here → destructors called in reverse order
    return 0;
}
