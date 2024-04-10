#ifndef BANGSANPHAM_H
#define BANGSANPHAM_H

#include <string>

class BangSanPham {
private:
    std::string maSP;
    std::string tenSP;
    std::string trongLuong;
    std::string qcDongGoi;

public:
    // Constructors
    BangSanPham(); // Constructor mặc định không đối số
    BangSanPham(std::string _maSP, std::string _tenSP, std::string _trongLuong, std::string _qcDongGoi); // Constructor có đối số

    // Setter functions
    void setMaSP(const std::string& _maSP);
    void setTenSP(const std::string& _tenSP);
    void setTrongLuong(const std::string& _trongLuong);
    void setQCDongGoi(const std::string& _qcDongGoi);

    // Getter functions
    std::string getMaSP() const;
    std::string getTenSP() const;
    std::string getTrongLuong() const;
    std::string getQCDongGoi() const;
};

#endif // BANGSANPHAM_H
