#include <iostream>
#include <string>
using namespace std;

class SinhVien
{
private:
    string hoten;
    int tinchi;
    float diemTB;
public:
    SinhVien(std::string ten, int tchi, float diem) : hoten(ten), tinchi(tchi), diemTB(diem) {}

    string getHoten(){
        return hoten;
    }
    int getTinchi(){
        return tinchi;
    }
    float getDiemTB(){
        return diemTB;
    }
    void setHoten(string ten){
        ten = hoten;
    }
    void floatDiemTB(float diem){
        diem = diemTB;
    }
    void intTinchi(int tchi){
        tchi = tinchi;
    }
    bool operator==(const SinhVien& other) const {
        return (diemTB == other.diemTB && tinchi == other.tinchi);
    }
};
int main() {
    string hoten1, hoten2;
    int tinchi1, tinchi2;
    float diemTB1, diemTB2;

    cout << "Enter student 1 name: ";
    getline(cin, hoten1);
    cout << "Enter student 1 score: ";
    cin >> diemTB1;
    cout << "Enter student 1 tinchi: ";
    cin >> tinchi1;
    cin.ignore(); // Ignore newline character left in the input buffer

    cout << "Enter student 2 name: ";
    getline(cin, hoten2);
    cout << "Enter student 2 score: ";
    cin >> diemTB2;
    cout << "Enter student 2 tinchi: ";
    cin >> tinchi2;

    // Create two SinhVien objects
    SinhVien sv1(hoten1, tinchi1, diemTB1);
    SinhVien sv2(hoten2, tinchi2, diemTB2);

    // Compare two SinhVien objects using ==
    if (sv1 == sv2) {
        cout << "Two students are identical.\n";
    } else {
        cout << "Two students are different.\n";
    }

    return 0;
}

