#include "../Repository/BangHoaDon.h"
#include <bits/stdc++.h>
#include <dirent.h>
#include "../Repository/Controller.h"

// void updateHoadonsFile(const std::vector<BangHoaDon>& hoadons)
// {
//     std::ofstream outputFile("BangHoaDon.csv");
//     if (!outputFile.is_open())
//     {
//         std::cout << "Failed to open BangHoaDon file for writing." << std::endl;
//         return;
//     }

//     for (const BangHoaDon& hoadon : hoadons)
//     {
//         outputFile << hoadon.getsoHD() << " | "
//                    << hoadon.getngayBan() << " | "
//                    << hoadon.getmaKH() << "\n";
//     }

//     outputFile.close();
//     std::cout << "BangHoaDon file updated successfully." << std::endl;
// }

void Controller::readData(std::vector<BangHoaDon>& hoadons)
{
    std::ifstream inputFile("Data/BangHoaDon.csv");
    if (!inputFile.is_open())
    {
        std::cout << "Failed to open BangHoaDon file for reading." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inputFile, line))
    {
        std::istringstream iss(line);
        std::string token;
        std::vector<std::string> hoadonData;

        while (std::getline(iss, token, '|'))
        {
            hoadonData.push_back(token);
        }

        if (hoadonData.size() == 3)
        {
            std::string soHD = hoadonData[0];
            std::string ngayBan = hoadonData[1];
            std::string maKH = hoadonData[2];

            std::cout << "SoHD: " << soHD << ", NgayBan: " << ngayBan << ", MaKH: " << maKH << std::endl;

            BangHoaDon hoadon(soHD, ngayBan, maKH);
            hoadons.push_back(hoadon);
        }
    }

    inputFile.close();
}

void Controller::showAllhoadons(const std::vector<BangHoaDon>& hoadons)
{
    std::cout << "All HoaDon:" << std::endl;
    for (const auto &hoadon : hoadons)
    {
        std::cout << "SoHD: " << hoadon.getsoHD() << "|";
        std::cout << "NgayBan: " << hoadon.getngayBan() << "|";
        std::cout << "MaKH: " << hoadon.getmaKH() << std::endl;
    }
}

void Controller::addNewhoadon(std::vector<BangHoaDon>& hoadons)
{
    std::string soHD, ngayBan, maKH;

    std::cout << "Enter new invoice information:" << std::endl;
    std::cout << "SoHD: ";
    std::cin >> soHD;
    std::cout << "NgayBan: ";
    std::cin >> ngayBan;
    std::cout << "MaKH: ";
    std::cin >> maKH;

    BangHoaDon newHoadon(soHD, ngayBan, maKH);
    hoadons.push_back(newHoadon);
    std::cout << "Add new invoice successfully." << std::endl;
}

void Controller::modifyhoadon(std::vector<BangHoaDon>& hoadons)
{
    std::cout << "Enter the SoHD of the invoice to be modified: ";
    std::string soHD;
    std::cin >> soHD;

    for (BangHoaDon &hoadon : hoadons)
    {
        if (hoadon.getsoHD() == soHD)
        {
            std::string newNgayBan, newMaKH;

            std::cout << "Enter new NgayBan: ";
            std::cin >> newNgayBan;

            std::cout << "Enter new MaKH: ";
            std::cin >> newMaKH;

            hoadon.setngayBan(newNgayBan);
            hoadon.setmaKH(newMaKH);

            // Assuming updateContactsFile writes modified hoadons back to the file

            std::cout << "Invoice modified successfully." << std::endl;
            return;
        }
    }
    std::cout << "Can't find invoice with SoHD: " << soHD << "." << std::endl;
}


void Controller::deletehoadon(std::vector<BangHoaDon>& hoadons)
{
    std::cout << "Enter the number of the invoice to be deleted: ";
    std::string soHD;
    std::cin >> soHD;

    for (auto it = hoadons.begin(); it != hoadons.end(); ++it)
    {
        if (it->getsoHD() == soHD)
        {
            it = hoadons.erase(it);
            std::cout << "The invoice deleted successfully." << std::endl;
            return;
        }
    }
    std::cout << "Can't find the invoice with SoHD: " << soHD << "." << std::endl;
}
