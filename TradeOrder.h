#ifndef TRADEORDER_H
#define TRADEORDER_H

#include "Stock.h"

class TradeOrder {
private:
    int    orderID;
    int    quantity;
    string orderType;  // "BUY" or "SELL"
    string status;     // "PENDING", "EXECUTED", "CANCELLED"
    Stock* stock;

public:
    static int totalOrders;

    TradeOrder(int id, int qty, string type, Stock* stock);
    ~TradeOrder();

    int    getID();
    string getStatus();
    string getType();

    void executeOrder();
    void cancelOrder();
    void displayInfo();
};

#endif
