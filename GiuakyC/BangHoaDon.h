#ifndef BangHoaDon_H
#define BangHoaDon_H
#include <iostream>
class BangHoaDon
{
private:
    std::string soHD;
    std::string ngayBan;
    std::string maKH;
    float tongTien; // Thêm một biến để lưu tổng tiền

public:
    BangHoaDon();
    BangHoaDon(std::string _soHD, std::string _ngayBan, std::string _maKH);
    void setsoHD(const std::string &_soHD);
    void setngayBan(const std::string &_ngayBan);
    void setmaKH(const std::string &_maKH);
    void setTongTien(float _tongTien); // Phương thức để thiết lập giá trị của tổng tiền


    std::string getsoHD() const;
    std::string getngayBan() const;
    std::string getmaKH() const;
    float getTongTien() const; // Phương thức để truy xuất giá trị của tổng tiền

};

#endif