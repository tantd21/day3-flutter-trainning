#ifndef BangHoaDon_H
#define BangHoaDon_H
#include <iostream>
class BangHoaDon
{
private:
    std::string soHD;
    std::string ngayBan;
    std::string maKH;

public:
    BangHoaDon();
    BangHoaDon(std::string _soHD, std::string _ngayBan, std::string _maKH);
    void setsoHD(const std::string &_soHD);
    void setngayBan(const std::string &_ngayBan);
    void setmaKH(const std::string &_maKH);


    std::string getsoHD() const;
    std::string getngayBan() const;
    std::string getmaKH() const;

};

#endif