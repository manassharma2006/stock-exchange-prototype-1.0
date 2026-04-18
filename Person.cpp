#include "Person.h"
#include <iostream>
using namespace std;

int Person::totalPersons = 0;

Person::Person(string name, string email) {
    this->name  = name;
    this->email = email;
    totalPersons++;
    cout << "[Person] Created: " << name << endl;
}

Person::~Person() {
    totalPersons--;
    cout << "[Person] Destroyed: " << name << endl;
}

string Person::getName()  { return name; }
string Person::getEmail() { return email; }

void Person::login() {
    cout << name << " logged in." << endl;
}

void Person::logout() {
    cout << name << " logged out." << endl;
}

void Person::displayInfo() {
    cout << "Name : " << name << endl;
    cout << "Email: " << email << endl;
}
