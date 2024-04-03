#include <iostream>
#include <vector>
using namespace std;

class Circle {
private:
    float radius;

public:
    // Phương thức khởi tạo mặc định
    Circle(): radius(0.0) {}

    // Phương thức khởi tạo có tham số
    Circle(float _radius): radius(_radius) {}

    // Phương thức tính chu vi
    float getPerimeter() {
        return 2 * 3.14 * radius;
    }

    // Phương thức tính diện tích
    float getArea() {
        return 3.14 * radius * radius;
    }

    // Phương thức hiển thị thông tin chu vi và diện tích
    void displayCircle() {
        cout << "Chu vi của hình tròn: " << getPerimeter() << endl;
        cout << "Diện tích của hình tròn: " << getArea() << endl;
    }
};

int main() {
    // Tạo danh sách vector của các đối tượng Circle
    vector<Circle> circle_list;

    // Thêm các đối tượng Circle vào danh sách
    circle_list.push_back(Circle());   // Sử dụng khởi tạo mặc định, bán kính là 0.0
    circle_list.push_back(Circle(5.0));   // Thiết lập bán kính là 5.0
    circle_list.push_back(Circle(3.5));   // Thiết lập bán kính là 3.5

    // Hiển thị thông tin chu vi và diện tích của các hình tròn trong danh sách
    for (const auto& circle : circle_list) {
        cout << "Thông tin hình tròn:" << endl;
        circle.displayCircle();
        cout << endl;
    }

    return 0;
}