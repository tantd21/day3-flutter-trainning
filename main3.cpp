#include <iostream>
#include "Product.h"

using namespace std;

int main() {
    string name;
    float price;
    int quantity;

    // Nhập thông tin từ người dùng
    cout << "Enter product name: ";
    getline(cin, name);

    cout << "Enter product price: ";
    cin >> price;

    cout << "Enter product quantity: ";
    cin >> quantity;

    // Tạo sản phẩm từ thông tin đã nhập
    Product product(name, price, quantity);

    // Hiển thị thông tin sản phẩm
    cout << "\nProduct information:" << endl;
    product.displayProduct();

    return 0;
}
