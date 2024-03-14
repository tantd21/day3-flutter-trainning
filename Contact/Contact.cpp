#include "Contact.h"
// Constructor
Contact::Contact()
{
    // Initialize member variables with default values
    no = 0;
    name = "";
    phone = "";
    email = "";
    address = "";
}

Contact::Contact(int _no, std::string _name, std::string _phone, std::string _email, std::string _address)
{
    // Initialize member variables with provided values
    no = _no;
    name = _name;
    phone = _phone;
    email = _email;
    address = _address;
}

// Setter functions
void Contact::setNo(int _no)
{
    no = _no;
}

void Contact::setName(const std::string &_name)
{
    name = _name;
}

void Contact::setPhone(const std::string &_phone)
{
    phone = _phone;
}

void Contact::setEmail(const std::string &_email)
{
    email = _email;
}

void Contact::setAddress(const std::string &_address)
{
    address = _address;
}

// Getter functions
int Contact::getNo() const
{
    return no;
}

std::string Contact::getName() const
{
    return name;
}

std::string Contact::getPhone() const
{
    return phone;
}

std::string Contact::getEmail() const
{
    return email;
}

std::string Contact::getAddress() const
{
    return address;
}