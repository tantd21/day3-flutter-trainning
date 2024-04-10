#include <iostream>
#include "Repository/BangHoaDon.h"
#include "Repository/BangChiTietHD.h"
#include "Repository/ControllerChiTietHD.h"
#include "Repository/Controller.h"
#include "Repository/BangSanPham.h"

int main() {
    Controller controller;
    ControllerChiTietHD controllerchitiethoadon;
    int choice;
    std::vector<BangHoaDon> hoadons;
    std::vector<BangChiTietHD> chiTietHDs;
    std::vector<BangSanPham> sanPham; // Khai báo vector cho sản phẩm

    controller.readData(hoadons);
    
    controllerchitiethoadon.readChiTietHDData(chiTietHDs);

    controllerchitiethoadon.readSanPhamData(sanPham);
    

    do {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Show all invoices" << std::endl;
        std::cout << "2. Add a new invoice" << std::endl;
        std::cout << "3. Modify an invoice" << std::endl;
        std::cout << "4. Delete an invoice by SoHD" << std::endl;
        std::cout << "5. Show all invoice details" << std::endl;
        std::cout << "6. Add a new invoice detail" << std::endl;
        std::cout << "7. Modify an invoice detail" << std::endl;
        std::cout << "8. Delete an invoice detail by SoHD" << std::endl;
        std::cout << "9. Calculate total amount for a specific invoice" << std::endl;
        std::cout << "10. Exit program" << std::endl;
        std::cout << "11. Top N products by sales quantity" << std::endl; // Thêm lựa chọn mới
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                controller.showAllhoadons(hoadons);
                break;
            case 2:
                controller.addNewhoadon(hoadons);
                break;
            case 3:
                controller.modifyhoadon(hoadons);
                break;
            case 4:
                controller.deletehoadon(hoadons);
                break;
            case 5:
                controllerchitiethoadon.showAllchitietHD(chiTietHDs);
                break;
            case 6:
                controllerchitiethoadon.addNewChiTietHD(chiTietHDs);
                break;
            case 7:
                controllerchitiethoadon.modifyChiTietHD(chiTietHDs);
                break;
            case 8:
                controllerchitiethoadon.deleteChiTietHD(chiTietHDs);
                break;
            case 9: {
                std::string soHD;
                std::cout << "Enter the invoice number: ";
                std::cin >> soHD;
                try {
                    float total = controllerchitiethoadon.calculateTotalForInvoice(chiTietHDs, soHD);
                    std::cout << "Total amount for invoice " << soHD << ": " << total << std::endl;
                } catch (const std::invalid_argument& e) {
                    std::cerr << "Invalid invoice number. Please try again." << std::endl;
                }
                break;
            }
            case 11: {
                int N;
                std::cout << "Enter the number of top products to display: ";
                std::cin >> N;
                 controllerchitiethoadon.calculateTopNProductsBySales(chiTietHDs, sanPham, N); // Thêm tham số N vào hàm gọi
                break;
            }
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
