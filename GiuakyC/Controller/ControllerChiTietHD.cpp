#include "../Repository/BangChiTietHD.h"
#include "../Repository/ControllerChiTietHD.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <algorithm>


void ControllerChiTietHD::readChiTietHDData(std::vector<BangChiTietHD>& chiTietHDs) {
    std::ifstream inputFile("BangChiTietHD.csv");
    if (!inputFile.is_open()) {
        std::cout << "Failed to open BangChiTietHD file for reading." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string token;
        std::vector<std::string> chiTietHDData;

        while (std::getline(iss, token, '|')) {
            chiTietHDData.push_back(token);
        }

        if (chiTietHDData.size() == 4) {
            std::string soHD = chiTietHDData[0];
            std::string maSP = chiTietHDData[1];

            int soLuong;
            float giaBan;

            // Kiểm tra nếu có thể chuyển đổi giá trị thành số nguyên và số thực
            if (!(std::istringstream(chiTietHDData[2]) >> soLuong) ||
                !(std::istringstream(chiTietHDData[3]) >> giaBan)) {
                std::cout << "Invalid data format in BangChiTietHD.csv. Skipping this line." << std::endl;
                continue;
            }

            float tongTien = soLuong * giaBan;

            BangChiTietHD chiTietHD(soHD, maSP, soLuong, giaBan);
            chiTietHDs.push_back(chiTietHD);
        }
    }

    inputFile.close();
}

void ControllerChiTietHD::showAllchitietHD(const std::vector<BangChiTietHD>& chiTietHDs) {
    std::cout << "All ChiTietHD:" << std::endl;
    for (const auto& chiTietHD : chiTietHDs) {
        std::cout << "SoHD: " << chiTietHD.getSoHD() << "|";
        std::cout << "MaSP: " << chiTietHD.getMaSP() << "|";
        std::cout << "SoLuong: " << chiTietHD.getSoLuong() << "|";
        std::cout << "GiaBan: " << chiTietHD.getGiaBan() << "|";
        std::cout << "TongTien: " << chiTietHD.getTongTien() << std::endl;
    }
}

void ControllerChiTietHD::addNewChiTietHD(std::vector<BangChiTietHD>& chiTietHDs) {
    std::string soHD, maSP;
    int soLuong;
    float giaBan;

    std::cout << "Enter new invoice detail information:" << std::endl;
    std::cout << "SoHD: ";
    std::cin >> soHD;
    std::cout << "MaSP: ";
    std::cin >> maSP;
    std::cout << "SoLuong: ";
    std::cin >> soLuong;
    std::cout << "GiaBan: ";
    std::cin >> giaBan;

    // Tính tổng tiền từ số lượng và giá bán
    float tongTien = soLuong * giaBan;

    BangChiTietHD newChiTietHD(soHD, maSP, soLuong, giaBan);
    chiTietHDs.push_back(newChiTietHD);
    std::cout << "Add new invoice detail successfully." << std::endl;
}

void ControllerChiTietHD::modifyChiTietHD(std::vector<BangChiTietHD>& chiTietHDs) {
    std::cout << "Enter the SoHD of the invoice detail to be modified: ";
    std::string soHD;
    std::cin >> soHD;

    for (BangChiTietHD& chiTietHD : chiTietHDs) {
        if (chiTietHD.getSoHD() == soHD) {
            std::string newMaSP;
            int newSoLuong;
            float newGiaBan;

            std::cout << "Enter new MaSP: ";
            std::cin >> newMaSP;
            std::cout << "Enter new SoLuong: ";
            std::cin >> newSoLuong;
            std::cout << "Enter new GiaBan: ";
            std::cin >> newGiaBan;

            // Tính tổng tiền từ số lượng và giá bán
            float newTongTien = newSoLuong * newGiaBan;

            chiTietHD.setMaSP(newMaSP);
            chiTietHD.setSoLuong(newSoLuong);
            chiTietHD.setGiaBan(newGiaBan);

            std::cout << "Invoice detail modified successfully." << std::endl;
            return;
        }
    }
    std::cout << "Can't find invoice detail with SoHD: " << soHD << "." << std::endl;
}

void ControllerChiTietHD::deleteChiTietHD(std::vector<BangChiTietHD>& chiTietHDs) {
    std::cout << "Enter the SoHD of the invoice detail to be deleted: ";
    std::string soHD;
    std::cin >> soHD;

    for (auto it = chiTietHDs.begin(); it != chiTietHDs.end(); ++it) {
        if (it->getSoHD() == soHD) {
            it = chiTietHDs.erase(it);
            std::cout << "The invoice detail deleted successfully." << std::endl;
            return;
        }
    }
    std::cout << "Can't find the invoice detail with SoHD: " << soHD << "." << std::endl;
}

float ControllerChiTietHD::calculateTotalForInvoice(const std::vector<BangChiTietHD>& chiTietHDs, const std::string& soHD) {
    float total = 0.0f;

    for (const auto& chiTietHD : chiTietHDs) {
        if (chiTietHD.getSoHD() == soHD) {
            total += chiTietHD.getSoLuong() * chiTietHD.getGiaBan();
        }
    }

    return total;
}

void ControllerChiTietHD::calculateTopNProductsBySales(const std::vector<BangChiTietHD>& chiTietHDs, int N) {
    // Tạo một unordered_map để lưu số lượng bán của từng sản phẩm
    std::unordered_map<std::string, int> productSalesMap;

    // Tính tổng số lượng bán của từng sản phẩm
    for (const auto& chiTietHD : chiTietHDs) {
        const std::string& maSP = chiTietHD.getMaSP();
        int soLuong = chiTietHD.getSoLuong();
        productSalesMap[maSP] += soLuong;
    }

    // Chuyển đổi map sang vector để sắp xếp
    std::vector<std::pair<std::string, int>> productSalesVec(productSalesMap.begin(), productSalesMap.end());

    // Sắp xếp vector theo số lượng bán giảm dần
    std::sort(productSalesVec.begin(), productSalesVec.end(), 
              [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
                  return a.second > b.second;
              });

    // Hiển thị top N sản phẩm có số lượng bán nhiều nhất
    std::cout << "Top " << N << " products by sales quantity:" << std::endl;
    for (int i = 0; i < std::min(N, static_cast<int>(productSalesVec.size())); ++i) {
        const auto& product = productSalesVec[i];
        std::cout << "MaSP: " << product.first << " | SoLuong: " << product.second << std::endl;
    }
}
