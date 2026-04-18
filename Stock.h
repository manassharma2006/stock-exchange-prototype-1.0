#ifndef STOCK_H
#define STOCK_H

#include <string>
using namespace std;

class Stock {
private:
    int    stockID;
    string ticker;
    double price;
    int    availableShares;

public:
    static int totalStocks;

    Stock(int id, string ticker, double price, int shares);
    ~Stock();

    int    getID();
    string getTicker();
    double getPrice();
    int    getShares();

    void updatePrice(double newPrice);
    bool checkAvailability(int qty);
    void reduceShares(int qty);
    void addShares(int qty);

    void displayInfo();
};

#endif
