#ifndef CONTROLLERCHITIETHD_H
#define CONTROLLERCHITIETHD_H

#include "BangChiTietHD.h"
#include <vector>


     void readChiTietHDData(std::vector<BangChiTietHD>& chiTietHDs);
     void showAllchitietHD(const std::vector<BangChiTietHD>& chiTietHDs);
     void addNewChiTietHD(std::vector<BangChiTietHD>& chiTietHDs);
     void modifyChiTietHD(std::vector<BangChiTietHD>& chiTietHDs);
     void deleteChiTietHD(std::vector<BangChiTietHD>& chiTietHDs);
     float calculateTotalForInvoice(const std::vector<BangChiTietHD>& chiTietHDs, const std::string& soHD);



#endif // CONTROLLERCHITIETHD_H
