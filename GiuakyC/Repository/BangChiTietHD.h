#ifndef BANG_CHI_TIET_HOA_DON_H
#define BANG_CHI_TIET_HOA_DON_H

#include <string>

class BangChiTietHD {
private:
    std::string soHD;
    std::string maSP;
    int soLuong;
    float giaBan;

public:
    BangChiTietHD(); // Hàm tạo mặc định
    BangChiTietHD(std::string _soHD, std::string _maSP, int _soLuong, float _giaBan); // Hàm tạo với tham số

    // Setter functions
    void setSoHD(const std::string& _soHD);
    void setMaSP(const std::string& _maSP);
    void setSoLuong(int _soLuong);
    void setGiaBan(float _giaBan);

    // Getter functions
    std::string getSoHD() const;
    std::string getMaSP() const;
    int getSoLuong() const;
    float getGiaBan() const;
    float getTongTien() const;
};

#endif
