// #include "../Repository/BangChiTietHD.h"
#include "../Repository/BangChiTietHD.h"
// Constructor
BangChiTietHD::BangChiTietHD() 
    : soHD(""), maSP(""), soLuong(0), giaBan(0.0f) {}

BangChiTietHD::BangChiTietHD(std::string _soHD, std::string _maSP, int _soLuong, float _giaBan) 
    : soHD(_soHD), maSP(_maSP), soLuong(_soLuong), giaBan(_giaBan) {}

// Setter functions
void BangChiTietHD::setSoHD(const std::string& _soHD) {
    soHD = _soHD;
}

void BangChiTietHD::setMaSP(const std::string& _maSP) {
    maSP = _maSP;
}

void BangChiTietHD::setSoLuong(int _soLuong) {
    soLuong = _soLuong;
}

void BangChiTietHD::setGiaBan(float _giaBan) {
    giaBan = _giaBan;
}

// Getter functions
std::string BangChiTietHD::getSoHD() const {
    return soHD;
}

std::string BangChiTietHD::getMaSP() const {
    return maSP;
}

int BangChiTietHD::getSoLuong() const {
    return soLuong;
}

float BangChiTietHD::getGiaBan() const {
    return giaBan;
}

float BangChiTietHD::getTongTien() const {
    return soLuong * giaBan;
}
