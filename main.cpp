#include "Contact.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

// Khai báo các hàm từ function.cpp
vector<Contact> readContactsFromFile(const string& filename);
void displayContacts(const vector<Contact>& contacts);
void addContact(vector<Contact>& contacts);
vector<Contact> searchContacts(const vector<Contact>& contacts, const string& searchQuery);
void updateContact(vector<Contact>& contacts, int id);
void deleteContact(vector<Contact>& contacts, int id);
void statistics(const vector<Contact>& contacts); // Thêm hàm thống kê

int main() {
    vector<Contact> contacts = readContactsFromFile("danhba.data");
    int choice;
    string searchQuery;

    do {
        cout << "Menu:\n";
        cout << "1. Hiển thị toàn bộ thông tin\n";
        cout << "2. Thêm một contact vào danh bạ\n";
        cout << "3. Tìm kiếm contact\n";
        cout << "4. Cập nhật contact\n";
        cout << "5. Xóa contact\n";
        cout << "6. Thống kê\n"; // Thêm tùy chọn thống kê
        cout << "0. Thoát\n";
        cout << "Nhập lựa chọn của bạn: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayContacts(contacts);
                break;
            case 2:
                addContact(contacts);
                break;
            case 3:
                cout << "Nhập thông tin cần tìm kiếm (tên, số điện thoại hoặc email): ";
                cin.ignore();
                getline(cin, searchQuery);
                displayContacts(searchContacts(contacts, searchQuery)); // Hiển thị kết quả tìm kiếm
                break;
            case 4:
                int updateId;
                cout << "Nhập ID của contact bạn muốn cập nhật: ";
                cin >> updateId;
                updateContact(contacts, updateId);
                break;
            case 5:
                int deleteId;
                cout << "Nhập ID của contact bạn muốn xóa: ";
                cin >> deleteId;
                deleteContact(contacts, deleteId);
                break;
            case 6:
                statistics(contacts); // Gọi hàm thống kê
                break;
            case 0:
                cout << "Kết thúc chương trình.\n";
                break;
            default:
                cout << "Lựa chọn không hợp lệ. Vui lòng nhập lại.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}
