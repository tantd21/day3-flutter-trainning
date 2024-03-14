#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Employee {
private:
    string name;
    int idNumber;
    string department;
    string position;

public:
    // Constructors
    Employee() {
        name = " ";
        idNumber = 0;
        department = "";
        position = "";
    }

    Employee(string n, int id, string depart, string pos) {
        name = n;
        idNumber = id;
        department = depart;
        position = pos;
    }

    // Getter methods
    string getName() const {
        return name;
    }

    int getIdNumber() const {
        return idNumber;
    }

    string getDepartment() const {
        return department;
    }

    string getPosition() const {
        return position;
    }
};

int main() {
    // Dữ liệu nhân viên được cung cấp
    vector<Employee> employees = {
        Employee("Susan Meyers", 47899, "Accounting", "Vice President"),
        Employee("Mark Jones", 39119, "IT", "Programmer"),
        Employee("Joy Rogers", 81774, "Manufacturing", "Engineer")
    };

    // Hiển thị thông tin của từng nhân viên
    cout << "Employee Details:" << endl;
    cout << "Name\t\tID Number\tDepartment\tPosition" << endl;
    for (const auto& emp : employees) {
        cout << emp.getName() << "\t" << emp.getIdNumber() << "\t\t"
             << emp.getDepartment() << "\t\t" << emp.getPosition() << endl;
    }

    return 0;
}
