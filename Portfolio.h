#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include "Stock.h"

// Simple fixed-size array to hold up to 10 stocks
#define MAX_HOLDINGS 10

class Portfolio {
private:
    int    portfolioID;
    Stock* holdings[MAX_HOLDINGS];   // array of Stock pointers
    int    quantities[MAX_HOLDINGS]; // how many shares of each
    int    count;                    // how many slots are filled

public:
    Portfolio(int id);
    ~Portfolio();

    void   addStock(Stock* stock, int qty);
    void   removeStock(string ticker, int qty);
    double calculateValue();
    void   displayInfo();
};

#endif
