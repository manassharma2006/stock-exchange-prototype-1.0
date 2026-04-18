#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
protected:
    string name;
    string email;

public:
    // Static variable to count total persons created
    static int totalPersons;

    Person(string name, string email);
    virtual ~Person();

    string getName();
    string getEmail();

    virtual void login();
    virtual void logout();
    virtual void displayInfo();  // overridden by each subclass
};

#endif
