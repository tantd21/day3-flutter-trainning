#include "NhanVien.h"
#include <iostream>

// Constructor mặc định
NhanVien::NhanVien() : tenNV(""), Luong(0.0f), phuCap(0.0f), thamNien(nullptr) {}

// Constructor có đối số
NhanVien::NhanVien(std::string _tenNV, float _Luong, float _phuCap, int _thamNien)
    : tenNV(_tenNV), Luong(_Luong), phuCap(_phuCap) {
    thamNien = new int(_thamNien);
}

// Destructor
NhanVien::~NhanVien() {
    delete thamNien;
}

// Setter cho tenNV
void NhanVien::settenNV(const std::string _tenNV) {
    tenNV = _tenNV;
}

// Setter cho Luong
void NhanVien::setLuong(const float _Luong) {
    Luong = _Luong;
}

// Setter cho phuCap
void NhanVien::setphuCap(const float _phuCap) {
    phuCap = _phuCap;
}

// Setter cho thamNien
void NhanVien::setthamNien(const float _thamNien) {
    *thamNien = _thamNien;
}

// Getter cho tenNV
std::string NhanVien::gettenNV() const {
    return tenNV;
}

// Getter cho Luong
float NhanVien::getLuong() const {
    return Luong;
}

// Getter cho phuCap
float NhanVien::getphuCap() const {
    return phuCap;
}

// Getter cho thamNien
int NhanVien::getthamNien() const {
    if (thamNien != nullptr) {
        return *thamNien;
    } else {
        return 0; // Trả về giá trị mặc định nếu con trỏ là nullptr
    }
}

// Constructor sao chép
NhanVien::NhanVien(const NhanVien& other)
    : tenNV(other.tenNV), Luong(other.Luong), phuCap(other.phuCap) {
    thamNien = new int(*other.thamNien);
}

// Toán tử so sánh ==
bool NhanVien::operator==(const NhanVien& other) {
    return (tenNV == other.tenNV && Luong == other.Luong && phuCap == other.phuCap);
}
template<typename T>
T sumAttributes(const NhanVien& nv) {
    return nv.getLuong() + nv.getphuCap() + nv.getthamNien();
}
