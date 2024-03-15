#include <iostream>
#include "BangHoaDon.h"
#include "Controller.h"

int main() {
    int choice;
    std::vector<BangHoaDon> hoadons;

    readData(hoadons);

    do {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Show all invoices" << std::endl;
        std::cout << "2. Add a new invoice" << std::endl;
        std::cout << "3. Modify an invoice" << std::endl;
        std::cout << "4. Delete an invoice by SoHD" << std::endl;
        std::cout << "5. Calculate total amount for a specific invoice" << std::endl;
        std::cout << "6. Exit program" << std::endl;
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
                {
                    std::string soHD;
                    std::cout << "Enter the invoice number: ";
                    std::cin >> soHD;
                    calculateTotalForInvoice(hoadons, soHD);
                }
                break;
            case 6:
                std::cout << "Exiting the program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }

        std::cout << std::endl;
    } while (choice != 6);

    return 0;
}
