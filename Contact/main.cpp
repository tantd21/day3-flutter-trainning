#include <bits/stdc++.h>
#include "Contact.h"
#include "Controller.h"
// #include "Controller.cpp"
// #include "Contact.cpp"

using namespace std;

int main()
{
    int choice;
    
    std::vector<Contact> contacts;

    readData(contacts);
    do
    {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Show all contacts" << std::endl;
        std::cout << "2. Add a new contact" << std::endl;
        std::cout << "3. Find contacts by name" << std::endl;
        std::cout << "4. Modify a contact" << std::endl;
        std::cout << "5. Delete a contact by NO" << std::endl;
        std::cout << "6. Statitics" << std::endl;
        std::cout << "7. Back-up and restore data" << std::endl;
        std::cout << "0. Exit program!" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            showAllContacts(contacts);
            break;
        case 2:
            addNewContact(contacts);
            break;
        case 3:
            findContactsByName(contacts);
            break;
        case 4:
            modifyContact(contacts);
            break;
        case 5:
            deleteContact(contacts);
            break;
        case 6:
            statitics(contacts);
            break;
        case 7:
            backUpAndRestore(contacts);
            break;
        case 0:
            // Exit the program
            cout << "Exiting the program." << endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }

        std::cout << std::endl;

    } while (choice != 0);

    return 0;
}