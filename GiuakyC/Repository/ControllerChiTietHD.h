#ifndef CONTROLLERCHITIETHD_H
#define CONTROLLERCHITIETHD_H

#include "BangChiTietHD.h"
#include "BangSanPham.h"
#include <vector>
class ControllerChiTietHD
{

public:

     void readChiTietHDData(std::vector<BangChiTietHD>& chiTietHDs);
     void showAllchitietHD(const std::vector<BangChiTietHD>& chiTietHDs);
     void addNewChiTietHD(std::vector<BangChiTietHD>& chiTietHDs);
     void modifyChiTietHD(std::vector<BangChiTietHD>& chiTietHDs);
     void deleteChiTietHD(std::vector<BangChiTietHD>& chiTietHDs);
     float calculateTotalForInvoice(const std::vector<BangChiTietHD>& chiTietHDs, const std::string& soHD);
     void calculateTopNProductsBySales(const std::vector<BangChiTietHD>& chiTietHDs, const std::vector<BangSanPham>& sanPham, int N);
     void readSanPhamData(std::vector<BangSanPham>& sanPham);

};


#endif // CONTROLLERCHITIETHD_H
