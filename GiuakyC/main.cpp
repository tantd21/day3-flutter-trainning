#include <iostream>
#include "BangHoaDon.h"
#include "Controller.h"
#include "ControllerChiTietHD.h" // Thêm header file cho ControllerChiTietHD

int main() {
    int choice;
    std::vector<BangHoaDon> hoadons;
    std::vector<BangChiTietHD> chiTietHDs; // Thêm vector cho chi tiết hóa đơn

    readData(hoadons);
    readChiTietHDData(chiTietHDs); // Đọc dữ liệu cho chi tiết hóa đơn

    do {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Show all invoices" << std::endl;
        std::cout << "2. Add a new invoice" << std::endl;
        std::cout << "3. Modify an invoice" << std::endl;
        std::cout << "4. Delete an invoice by SoHD" << std::endl;
        std::cout << "5. Show all invoice details" << std::endl; // Thêm chức năng hiển thị chi tiết hóa đơn
        std::cout << "6. Add a new invoice detail" << std::endl; // Thêm chức năng thêm chi tiết hóa đơn
        std::cout << "7. Modify an invoice detail" << std::endl; // Thêm chức năng sửa chi tiết hóa đơn
        std::cout << "8. Delete an invoice detail by SoHD" << std::endl; // Thêm chức năng xóa chi tiết hóa đơn
        std::cout << "9. Calculate total amount for a specific invoice" << std::endl; // Thêm chức năng tính tổng tiền cho một hóa đơn cụ thể
        std::cout << "10. Exit program" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                showAllhoadons(hoadons);
                break;
            case 2:
                addNewhoadon(hoadons);
                break;
            case 3:
                modifyhoadon(hoadons);
                break;
            case 4:
                deletehoadon(hoadons);
                break;
            case 5:
                showAllchitietHD(chiTietHDs); // Hiển thị tất cả chi tiết hóa đơn
                break;
            case 6:
                addNewChiTietHD(chiTietHDs); // Thêm mới chi tiết hóa đơn
                break;
            case 7:
                modifyChiTietHD(chiTietHDs); // Sửa chi tiết hóa đơn
                break;
            case 8:
                deleteChiTietHD(chiTietHDs); // Xóa chi tiết hóa đơn
                break;
       case 9:
{
    std::string soHD;
    std::cout << "Enter the invoice number: ";
    std::cin >> soHD;

    try {
        float total = calculateTotalForInvoice(chiTietHDs, soHD);
        std::cout << "Total amount for invoice " << soHD << ": " << total << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid invoice number. Please try again." << std::endl;
    }
}
break;

            case 10:
                std::cout << "Exiting the program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }

        std::cout << std::endl;
    } while (choice != 10);

    return 0;
}
