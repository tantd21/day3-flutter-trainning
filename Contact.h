#ifndef CONTACT_H
#define CONTACT_H

#include <string>

using namespace std;

class Contact {
private:
    int id;
    string name;
    string phone;
    string email;
    string address;

public:
    // Constructors
    Contact();
    Contact(int id, const string& name, const string& phone, const string& email, const string& address);

    // Getter methods
    int getId() const;
    string getName() const;
    string getPhone() const;
    string getEmail() const;
    string getAddress() const;

    // Setter methods
    void setId(int id);
    void setName(const string& name);
    void setPhone(const string& phone);
    void setEmail(const string& email);
    void setAddress(const string& address);

    // Other methods if needed
};

#endif // CONTACT_H
