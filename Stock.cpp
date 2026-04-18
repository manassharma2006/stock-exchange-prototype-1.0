#include "Stock.h"
#include <iostream>
using namespace std;

int Stock::totalStocks = 0;

Stock::Stock(int id, string ticker, double price, int shares) {
    this->stockID         = id;
    this->ticker          = ticker;
    this->price           = price;
    this->availableShares = shares;
    totalStocks++;
    cout << "[Stock] Listed: " << ticker << " @ $" << price << endl;
}

Stock::~Stock() {
    totalStocks--;
    cout << "[Stock] Delisted: " << ticker << endl;
}

int    Stock::getID()     { return stockID; }
string Stock::getTicker() { return ticker; }
double Stock::getPrice()  { return price; }
int    Stock::getShares() { return availableShares; }

void Stock::updatePrice(double newPrice) {
    cout << "[Stock] " << ticker << " price: $" << price
         << " -> $" << newPrice << endl;
    price = newPrice;
}

bool Stock::checkAvailability(int qty) {
    return availableShares >= qty;
}

void Stock::reduceShares(int qty) {
    availableShares -= qty;
}

void Stock::addShares(int qty) {
    availableShares += qty;
}

void Stock::displayInfo() {
    cout << "  [" << ticker << "] Price: $" << price
         << " | Shares: " << availableShares << endl;
}
