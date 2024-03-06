#include "Contact.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream> // Include the sstream library
#include <algorithm> // Thêm thư viện algorithm vào đây


using namespace std;

vector<Contact> readContactsFromFile(const string& filename) {
    vector<Contact> contacts;
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            // Split the line into individual information components of the contact
            stringstream ss(line);
            string idStr, name, phone, email, address;
            getline(ss, idStr, '|');
            int id = stoi(idStr);
            getline(ss, name, '|');
            getline(ss, phone, '|');
            getline(ss, email, '|');
            getline(ss, address, '|');
            
            // Create a Contact object from the parsed information and add to vector
            Contact contact(id, name, phone, email, address);
            contacts.push_back(contact);
        }
        file.close();
    } else {
        cout << "Khong the mo file " << filename << endl;
    }
    return contacts;
}

// Function to display all contacts information
void displayContacts(const vector<Contact>& contacts) {
    cout << "Danh ba cua ban:\n";
    for (const auto& contact : contacts) {
        cout << "ID: " << contact.getId() << "\n";
        cout << "Name: " << contact.getName() << "\n";
        cout << "Phone: " << contact.getPhone() << "\n";
        cout << "Email: " << contact.getEmail() << "\n";
        cout << "Address: " << contact.getAddress() << "\n\n";
    }
}

// Function to add a new contact to the address book
void addContact(vector<Contact>& contacts) {
    Contact newContact;
    int id;
    string name, phone, email, address;

    cout << "Nhap thong tin cho contact moi:\n";
    cout << "ID: ";
    cin >> id;
    newContact.setId(id);
    
    cin.ignore(); // Clear buffer to avoid skipping input
    
    cout << "Name: ";
    getline(cin, name);
    newContact.setName(name);

    cout << "Phone: ";
    getline(cin, phone);
    newContact.setPhone(phone);

    cout << "Email: ";
    getline(cin, email);
    newContact.setEmail(email);

    cout << "Address: ";
    getline(cin, address);
    newContact.setAddress(address);

    // Add the new contact to the list
    contacts.push_back(newContact);
    cout << "Contact da duoc them vao danh ba.\n";
    
    // Open the file to append to the end
    ofstream file("danhba.data", ios::app);
    if (file.is_open()) {
        file << id << "|" << name << "|" << phone << "|" << email << "|" << address << "\n";
        file.close();
        cout << "Contact da duoc them vao file danhba.data.\n";
    } else {
        cout << "Khong the mo file danhba.data de ghi.\n";
    }   
}

// Function to search for contacts by name, phone, or email
vector<Contact> searchContacts(const vector<Contact>& contacts, const string& searchQuery) {
    vector<Contact> results;
    for (const auto& contact : contacts) {
        // Search by name, phone, or email
        if (contact.getName().find(searchQuery) != string::npos ||
            contact.getPhone().find(searchQuery) != string::npos ||
            contact.getEmail().find(searchQuery) != string::npos) {
            results.push_back(contact);
        }
    }
    return results;
}

// Cập nhật thông tin của một contact trong danh bạ
void updateContact(vector<Contact>& contacts, int id) {
    // Tìm kiếm contact có id tương ứng
    auto it = find_if(contacts.begin(), contacts.end(), [id](const Contact& contact) {
        return contact.getId() == id;
    });

    if (it != contacts.end()) {
        cout << "Nhap thong tin moi cho contact:\n";
        cout << "Name: ";
        string name;
        cin.ignore();
        getline(cin, name);
        it->setName(name);

        cout << "Phone: ";
        string phone;
        getline(cin, phone);
        it->setPhone(phone);

        cout << "Email: ";
        string email;
        getline(cin, email);
        it->setEmail(email);

        cout << "Address: ";
        string address;
        getline(cin, address);
        it->setAddress(address);

        cout << "Contact da duoc cap nhat.\n";

        // Ghi lại vào file danhba.data
        ofstream file("danhba.data");
        if (file.is_open()) {
            for (const auto& contact : contacts) {
                file << contact.getId() << "|" << contact.getName() << "|" << contact.getPhone() << "|" << contact.getEmail() << "|" << contact.getAddress() << "\n";
            }
            file.close();
        } else {
            cout << "Khong the mo file danhba.data de ghi.\n";
        }
    } else {
        cout << "Khong tim thay contact co ID: " << id << endl;
    }
}

// Xóa một contact khỏi danh bạ
void deleteContact(vector<Contact>& contacts, int id) {
    auto it = find_if(contacts.begin(), contacts.end(), [id](const Contact& contact) {
        return contact.getId() == id;
    });

    if (it != contacts.end()) {
        contacts.erase(it);
        cout << "Contact co ID " << id << " da duoc xoa.\n";

        // Ghi lại vào file danhba.data
        ofstream file("danhba.data");
        if (file.is_open()) {
            for (const auto& contact : contacts) {
                file << contact.getId() << "|" << contact.getName() << "|" << contact.getPhone() << "|" << contact.getEmail() << "|" << contact.getAddress() << "\n";
            }
            file.close();
        } else {
            cout << "Khong the mo file danhba.data de ghi.\n";
        }
    } else {
        cout << "Khong tim thay contact co ID: " << id << endl;
    }
}

// Thống kê số lượng contacts trong danh bạ
void statistics(const vector<Contact>& contacts) {
    cout << "Tong so contacts: " << contacts.size() << endl;
}
