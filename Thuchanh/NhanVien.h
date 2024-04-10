#ifndef NHANVIEN_H
#define NHANVIEN_H
#include<string>
class NhanVien
{
private:
    std::string tenNV;
    float Luong;
    float phuCap;
    int *thamNien;   
public:
    NhanVien(/* args */);
    NhanVien(std::string _tenNV,float _Luong,float _phuCap, int _thamNien);
    void settenNV(const std::string _tenNV);
    void setLuong(const float _Luong);
    void setphuCap(const float _phuCap);
    void setthamNien(const float _thamNien);

    std::string gettenNV() const;
    float getLuong() const;
    float getphuCap() const;
    int getthamNien() const;

    NhanVien(const NhanVien& other);

    bool operator==(const NhanVien& other);
};

#endif
