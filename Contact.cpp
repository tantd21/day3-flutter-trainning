#include "Contact.h"
#include <iostream> // for cout (for demonstration)

using namespace std;

// Implement constructor
Contact::Contact() {}

Contact::Contact(int id, const string& name, const string& phone, const string& email, const string& address) {
    this->id = id;
    this->name = name;
    this->phone = phone;
    this->email = email;
    this->address = address;
}

// Implement getter methods
int Contact::getId() const {
    return id;
}

string Contact::getName() const {
    return name;
}

string Contact::getPhone() const {
    return phone;
}

string Contact::getEmail() const {
    return email;
}

string Contact::getAddress() const {
    return address;
}

// Implement setter methods
void Contact::setId(int id) {
    this->id = id;
}

void Contact::setName(const string& name) {
    this->name = name;
}

void Contact::setPhone(const string& phone) {
    this->phone = phone;
}

void Contact::setEmail(const string& email) {
    this->email = email;
}

void Contact::setAddress(const string& address) {
    this->address = address;
}

// Implement other methods if needed
