#include "../Repository/BangSanPham.h"

// Constructors
BangSanPham::BangSanPham()
    : maSP(""), tenSP(""), trongLuong(0), qcDongGoi("") {}

BangSanPham::BangSanPham(std::string _maSP, std::string _tenSP, int _trongLuong, std::string _qcDongGoi)
    : maSP(_maSP), tenSP(_tenSP), trongLuong(_trongLuong), qcDongGoi(_qcDongGoi) {}

// Setter functions
void BangSanPham::setMaSP(const std::string &_maSP) {
    maSP = _maSP;
}

void BangSanPham::setTenSP(const std::string &_tenSP) {
    tenSP = _tenSP;
}

void BangSanPham::setTrongLuong(int _trongLuong) {
    trongLuong = _trongLuong;
}

void BangSanPham::setQCDongGoi(const std::string &_qcDongGoi) {
    qcDongGoi = _qcDongGoi;
}

// Getter functions
std::string BangSanPham::getMaSP() const {
    return maSP;
}

std::string BangSanPham::getTenSP() const {
    return tenSP;
}

int BangSanPham::getTrongLuong() const {
    return trongLuong;
}

std::string BangSanPham::getQCDongGoi() const {
    return qcDongGoi;
}
