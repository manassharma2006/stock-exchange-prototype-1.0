#include "TradeOrder.h"
#include <iostream>
using namespace std;

int TradeOrder::totalOrders = 0;

TradeOrder::TradeOrder(int id, int qty, string type, Stock* stock) {
    this->orderID   = id;
    this->quantity  = qty;
    this->orderType = type;
    this->status    = "PENDING";
    this->stock     = stock;
    totalOrders++;
    cout << "[TradeOrder] Created #" << id
         << " [" << type << "] x" << qty
         << " of " << stock->getTicker() << endl;
}

TradeOrder::~TradeOrder() {
    totalOrders--;
    cout << "[TradeOrder] Closed #" << orderID << endl;
}

int    TradeOrder::getID()     { return orderID; }
string TradeOrder::getStatus() { return status; }
string TradeOrder::getType()   { return orderType; }

void TradeOrder::executeOrder() {
    if (status != "PENDING") {
        cout << "[TradeOrder] #" << orderID
             << " is already " << status << endl;
        return;
    }
    if (orderType == "BUY") {
        if (!stock->checkAvailability(quantity)) {
            cout << "[TradeOrder] Not enough shares. Cancelling #"
                 << orderID << endl;
            status = "CANCELLED";
            return;
        }
        stock->reduceShares(quantity);
    } else {
        stock->addShares(quantity);
    }
    status = "EXECUTED";
    double total = stock->getPrice() * quantity;
    cout << "[TradeOrder] Executed #" << orderID
         << " | Total: $" << total << endl;
}

void TradeOrder::cancelOrder() {
    if (status == "EXECUTED") {
        cout << "[TradeOrder] Cannot cancel executed order #"
             << orderID << endl;
        return;
    }
    status = "CANCELLED";
    cout << "[TradeOrder] Cancelled #" << orderID << endl;
}

void TradeOrder::displayInfo() {
    cout << "  Order #" << orderID
         << " [" << orderType << "]"
         << " x" << quantity
         << " of " << stock->getTicker()
         << " | Status: " << status << endl;
}
