#ifndef BANGSANPHAM_H
#define BANGSANPHAM_H

#include <string>

class BangSanPham {
private:
    std::string maSP;
    std::string tenSP;
    int trongLuong;
    std::string qcDongGoi;

public:
    // Constructors
    BangSanPham();
    BangSanPham(std::string _maSP, std::string _tenSP, int _trongLuong, std::string _qcDongGoi);

    // Setter functions
    void setMaSP(const std::string &_maSP);
    void setTenSP(const std::string &_tenSP);
    void setTrongLuong(int _trongLuong);
    void setQCDongGoi(const std::string &_qcDongGoi);

    // Getter functions
    std::string getMaSP() const;
    std::string getTenSP() const;
    int getTrongLuong() const;
    std::string getQCDongGoi() const;
};

#endif // BANGSANPHAM_H
