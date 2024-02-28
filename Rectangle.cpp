#include <iostream>
#include <string>

using namespace std;


class Rectangle
{
private:
    float width;
    float height;
    string color;
public:
    Rectangle(/* args */){
        width = 0.0;
        height = 0.0;
        color = "";
    };
    Rectangle(float w, float h, string col) {
        if (w > 0.0 && h > 0.0) {
            width = w;
            height = h;
            color = col;
        } else {
            cout << "Invalid width or height. Setting default values.\n";
            width = 0.0;
            height = 0.0;
            color = "red";
        }
    }
    float getWidth() const{
        return width;
    }
    float getHeight() const{
        return height;
    }
    string getColor() const{
        return color;
    }
    float getArea() const {
        return width * height;
    }

    // Phương thức tính chu vi
    float getPerimeter() const {
        return 2 * (width + height);
    }

    // Phương thức hiển thị thông tin hình chữ nhật
    void displayRectangle() const {
        cout << "Area: " << getArea() << ", Perimeter: " << getPerimeter() << endl;
    }
    void inputRectangle() {
        cout << "Enter width: ";
        cin >> width;
        cout << "Enter height: ";
        cin >> height;
        cout << "Enter color: ";
        cin >> color;
    }
};
int main(){
    Rectangle rect;
        cout << "Rectangle 1 - Enter values: ";
        rect.inputRectangle();
        cout << "Rectangle 1 - Entered values: ";
        rect.displayRectangle();

    return 0;
}

