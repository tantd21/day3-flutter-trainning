#include "Product.h"
#include <iostream>

using namespace std;

// Phương thức khởi tạo mặc định
Product::Product() {
    name = ""; // Thiết lập tên về rỗng
    price = new float(0.0); // Thiết lập giá về 0.0
    quantity = 0; // Thiết lập số lượng về 0
}

// Phương thức khởi tạo có tham số
Product::Product(string _name, float _price, int _quantity) {
    name = _name; // Thiết lập tên
    price = new float(_price); // Thiết lập giá
    quantity = _quantity; // Thiết lập số lượng
}

// Phương thức thiết lập đơn giá
void Product::setPrice(float _price) {
    *price = _price;
}

// Phương thức trả về đơn giá
float Product::getPrice() {
    return *price;
}

// Phương thức hiển thị thông tin sản phẩm
void Product::displayProduct() {
    cout << "Product Name: " << name << endl;
    cout << "Price: " << *price << endl;
    cout << "Quantity: " << quantity << endl;
}
