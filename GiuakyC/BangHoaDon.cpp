#include "BangHoaDon.h"

// Constructor
BangHoaDon::BangHoaDon()
{
    // Initialize member variables with default values
    soHD = "";
    ngayBan = "";
    maKH = "";
    tongTien = 0.0f; // Initialize total amount to 0
}

BangHoaDon::BangHoaDon(std::string _soHD, std::string _ngayBan, std::string _maKH)
{
    // Initialize member variables with provided values
    soHD = _soHD;
    ngayBan = _ngayBan;
    maKH = _maKH;
    tongTien = 0.0f; // Initialize total amount to 0
}

// Setter functions
void BangHoaDon::setsoHD(const std::string &_soHD)
{
    soHD = _soHD;
}

void BangHoaDon::setngayBan(const std::string &_ngayBan)
{
    ngayBan = _ngayBan;
}

void BangHoaDon::setmaKH(const std::string &_maKH)
{
    maKH = _maKH;
}

void BangHoaDon::setTongTien(float _tongTien)
{
    tongTien = _tongTien;
}

// Getter functions
std::string BangHoaDon::getsoHD() const
{
    return soHD;
}

std::string BangHoaDon::getngayBan() const
{
    return ngayBan;
}

std::string BangHoaDon::getmaKH() const
{
    return maKH;
}

float BangHoaDon::getTongTien() const
{
    return tongTien;
}
