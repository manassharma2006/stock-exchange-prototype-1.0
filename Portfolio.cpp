#include "Portfolio.h"
#include <iostream>
using namespace std;

Portfolio::Portfolio(int id) {
    this->portfolioID = id;
    this->count       = 0;

    // initialise arrays to null / zero
    for (int i = 0; i < MAX_HOLDINGS; i++) {
        holdings[i]  = NULL;
        quantities[i] = 0;
    }
    cout << "[Portfolio] Created #" << id << endl;
}

Portfolio::~Portfolio() {
    cout << "[Portfolio] Destroyed #" << portfolioID << endl;
}

void Portfolio::addStock(Stock* stock, int qty) {
    // if stock already in portfolio, just add quantity
    for (int i = 0; i < count; i++) {
        if (holdings[i]->getTicker() == stock->getTicker()) {
            quantities[i] += qty;
            cout << "[Portfolio] Added " << qty << " more " << stock->getTicker() << endl;
            return;
        }
    }
    // otherwise add new slot
    if (count < MAX_HOLDINGS) {
        holdings[count]   = stock;
        quantities[count] = qty;
        count++;
        cout << "[Portfolio] Added " << qty << " x " << stock->getTicker() << endl;
    } else {
        cout << "[Portfolio] Full — cannot add more stocks." << endl;
    }
}

void Portfolio::removeStock(string ticker, int qty) {
    for (int i = 0; i < count; i++) {
        if (holdings[i]->getTicker() == ticker) {
            quantities[i] -= qty;
            cout << "[Portfolio] Removed " << qty << " x " << ticker << endl;
            if (quantities[i] <= 0) {
                // shift remaining entries left
                for (int j = i; j < count - 1; j++) {
                    holdings[j]   = holdings[j + 1];
                    quantities[j] = quantities[j + 1];
                }
                holdings[count - 1]   = NULL;
                quantities[count - 1] = 0;
                count--;
            }
            return;
        }
    }
    cout << "[Portfolio] " << ticker << " not found." << endl;
}

double Portfolio::calculateValue() {
    double total = 0;
    for (int i = 0; i < count; i++) {
        total += holdings[i]->getPrice() * quantities[i];
    }
    return total;
}

void Portfolio::displayInfo() {
    cout << "  Portfolio #" << portfolioID << endl;
    for (int i = 0; i < count; i++) {
        cout << "    " << holdings[i]->getTicker()
             << " x" << quantities[i]
             << " @ $" << holdings[i]->getPrice()
             << " = $" << holdings[i]->getPrice() * quantities[i]
             << endl;
    }
    cout << "  Total Value: $" << calculateValue() << endl;
}
