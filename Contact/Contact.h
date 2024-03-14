#ifndef Contact_H
#define Contact_H
#include <iostream>
class Contact
{
private:
    int no;
    std::string name;
    std::string phone;
    std::string email;
    std::string address;

public:
    Contact();
    Contact(int _no, std::string _name, std::string _phone, std::string _email, std::string _address);
    // Setter functions
    void setNo(int _no);
    void setName(const std::string &_name);
    void setPhone(const std::string &_phone);
    void setEmail(const std::string &_email);
    void setAddress(const std::string &_address);

    // Getter functions
    int getNo() const;
    std::string getName() const;
    std::string getPhone() const;
    std::string getEmail() const;
    std::string getAddress() const;
};
#endif