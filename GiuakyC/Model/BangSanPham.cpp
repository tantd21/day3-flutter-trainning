    #include "../Repository/BangSanPham.h"

    
// Constructors
BangSanPham::BangSanPham()
    : maSP(""), tenSP(""), trongLuong(""), qcDongGoi("") {}

BangSanPham::BangSanPham(std::string _maSP, std::string _tenSP, std::string _trongLuong, std::string _qcDongGoi)
    : maSP(_maSP), tenSP(_tenSP), trongLuong(_trongLuong), qcDongGoi(_qcDongGoi) {}

// Setter functions
void BangSanPham::setMaSP(const std::string& _maSP) {
    maSP = _maSP;
}

void BangSanPham::setTenSP(const std::string& _tenSP) {
    tenSP = _tenSP;
}

void BangSanPham::setTrongLuong(const std::string& _trongLuong) {
    trongLuong = _trongLuong;
}

void BangSanPham::setQCDongGoi(const std::string& _qcDongGoi) {
    qcDongGoi = _qcDongGoi;
}

// Getter functions
std::string BangSanPham::getMaSP() const {
    return maSP;
}

std::string BangSanPham::getTenSP() const {
    return tenSP;
}

std::string BangSanPham::getTrongLuong() const {
    return trongLuong;
}

std::string BangSanPham::getQCDongGoi() const {
    return qcDongGoi;
}