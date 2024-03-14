#include "Contact.h"
#include <bits/stdc++.h>
#include <dirent.h>

void printVectorWithIndex(const std::vector<std::string> &vec)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << (i + 1) << ": " << vec[i] << std::endl;
    }
}

std::string getStringAtIndex(const std::vector<std::string> &vec, size_t index)
{
    if (index >= 0 && index < vec.size())
    {
        return vec[index];
    }
    else
    {
        return ""; // Trả về chuỗi rỗng nếu chỉ mục không hợp lệ
    }
}
std::vector<std::string> listCSVFilesInDirectory(const std::string &directory)
{
    std::vector<std::string> csvFiles;
    DIR *dir;
    struct dirent *entry;

    if ((dir = opendir(directory.c_str())) != nullptr)
    {
        while ((entry = readdir(dir)) != nullptr)
        {
            std::string filename = entry->d_name;
            if (filename.length() >= 4 && filename.substr(filename.length() - 4) == ".csv")
            {
                csvFiles.push_back(filename);
            }
        }
        closedir(dir);
    }
    else
    {
        std::cerr << "Cannot open directory: " << directory << std::endl;
    }

    // Sắp xếp vector chứa tên file theo thứ tự index
    std::sort(csvFiles.begin(), csvFiles.end());

    return csvFiles;
}
void updateContactsFile(const std::vector<Contact> &contacts)
{
    std::ofstream outputFile("contacts.csv");
    if (!outputFile.is_open())
    {
        std::cout << "Failed to open contacts file for writing.\n";
        return;
    }

    for (const Contact &contact : contacts)
    {
        outputFile << contact.getNo() << " | "
                   << contact.getName() << " | "
                   << contact.getPhone() << " | "
                   << contact.getEmail() << " | "
                   << contact.getAddress() << "\n";
    }

    outputFile.close();
    std::cout << "Contacts file updated successfully.\n";
}
void readData(std::vector<Contact> &contacts)
{
    std::ifstream inputFile("contacts.csv");
    std::string line;

    while (std::getline(inputFile, line))
    {
        std::istringstream iss(line);
        std::string token;
        std::vector<std::string> contactData;

        while (std::getline(iss, token, '|'))
        {
            contactData.push_back(token);
        }

        if (contactData.size() == 5)
        {
            int id = std::stoi(contactData[0]);
            std::string name = contactData[1];
            std::string phone = contactData[2];
            std::string email = contactData[3];
            std::string address = contactData[4];

            Contact contact(id, name, phone, email, address);
            contacts.push_back(contact);
        }
    }

    inputFile.close();
}
// Function to show all contacts
void showAllContacts(const std::vector<Contact> &contacts)
{
    std::cout << "All Contacts:" << std::endl;
    for (const auto &contact : contacts)
    {
        std::cout << "No: " << contact.getNo() << " | ";
        std::cout << "Name: " << contact.getName() << " | ";
        std::cout << "Phone: " << contact.getPhone() << " | ";
        std::cout << "Email: " << contact.getEmail() << " | ";
        std::cout << "Address: " << contact.getAddress() << std::endl;
    }
}
void addNewContact(std::vector<Contact> &contacts)
{
    int no;
    std::string name, phone, email, address;

    std::cout << "Enter new contact information:" << std::endl;
    std::cout << "NO: ";
    std::cin >> no;
    std::cout << "Name: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "Phone: ";
    std::getline(std::cin, phone);
    std::cout << "Email: ";
    std::getline(std::cin, email);
    std::cout << "Address: ";
    std::getline(std::cin, address);

    Contact newContact(no, name, phone, email, address);
    contacts.push_back(newContact);
    updateContactsFile(contacts);
    std::cout << "Add new contact successfully." << std::endl;
}
void findContactsByName(const std::vector<Contact> &contacts)
{
    std::string name;
    std::cout << "Enter name to search: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    bool found = false;
    for (const auto &contact : contacts)
    {
        if (contact.getName().find(name) != std::string::npos)
        {
            std::cout << "NO: " << contact.getNo() << " | ";
            std::cout << "Name: " << contact.getName() << " | ";
            std::cout << "Phone: " << contact.getPhone() << " | ";
            std::cout << "Email: " << contact.getEmail() << " | ";
            std::cout << "Address: " << contact.getAddress() << std::endl;
            found = true;
        }
    }

    if (!found)
    {
        std::cout << "No contact found with the given name." << std::endl;
    }
}
void modifyContact(std::vector<Contact> &contacts)
{
    std::cout << "Enter the number of the contact to be modified: ";
    int contactID;
    std::cin >> contactID;

    for (Contact &contact : contacts)
    {
        if (contact.getNo() == contactID)
        {
            std::string newName, newPhone, newEmail, newAddress;

            std::cout << "Enter new name: ";
            std::cin.ignore();
            std::getline(std::cin, newName);

            std::cout << "Enter new phone: ";
            std::getline(std::cin, newPhone);

            std::cout << "Enter new email: ";
            std::getline(std::cin, newEmail);

            std::cout << "Enter new address: ";
            std::getline(std::cin, newAddress);

            contact.setName(newName);
            contact.setPhone(newPhone);
            contact.setEmail(newEmail);
            contact.setAddress(newAddress);

            updateContactsFile(contacts);

            std::cout << "Contact modified successfully." << std::endl;
            return;
        }
    }
    std::cout << "Can't find contact with NO: " << contactID << "." << std::endl;
}

void deleteContact(std::vector<Contact> &contacts)
{
    std::cout << "Enter the number of the contact to be delete: ";
    int contactID;
    std::cin >> contactID;

    for (auto it = contacts.begin(); it != contacts.end(); ++it)
    {
        if (it->getNo() == contactID)
        {
            contacts.erase(it);
            updateContactsFile(contacts);

            std::cout << "The contact deleted successfully." << std::endl;
            return;
        }
    }
    std::cout << "Can't find the contact with NO: " << contactID << "." << std::endl;
}
void statitics(const std::vector<Contact> &contacts)
{
    std::cout << "Number of contacts in contact list: " << contacts.size();
}
void backUpAndRestore(std::vector<Contact> &contacts)
{
    std::cout << "1. Backup data\n";
    std::cout << "2. Restore data\n";
    std::cout << "Choose an option (1-2): ";
    int choice;
    std::cin >> choice;

    if (choice == 1)
    {
        // Backup data
        std::time_t now = std::time(nullptr);
        std::tm *timeInfo = std::localtime(&now);

        std::string backupFileName = "backup/backup_" +
                                     std::to_string(timeInfo->tm_year + 1900) + "-" +
                                     std::to_string(timeInfo->tm_mon + 1) + "-" +
                                     std::to_string(timeInfo->tm_mday) + "_" +
                                     std::to_string(timeInfo->tm_hour) + "-" +
                                     std::to_string(timeInfo->tm_min) + "-" +
                                     std::to_string(timeInfo->tm_sec) + ".csv";

        std::ofstream backupFile(backupFileName);

        if (!backupFile.is_open())
        {
            std::cout << "Failed to create backup file." << std::endl;
            return;
        }

        for (const Contact &contact : contacts)
        {
            backupFile << contact.getNo() << " | "
                       << contact.getName() << " | "
                       << contact.getPhone() << " | "
                       << contact.getEmail() << " | "
                       << contact.getAddress() << "\n";
        }

        backupFile.close();
        std::cout << "Data has been backed up to file " << backupFileName << "." << std::endl;
    }
    else if (choice == 2)
    {
        std::string directory = "./backup";
        std::vector<std::string> list = listCSVFilesInDirectory(directory);
        printVectorWithIndex(list);
        // Restore data
        std::cout << "Enter index: ";
        size_t restoreFileIndex;
        std::cin >> restoreFileIndex;
        // giảm đi 1 vì vector đánh index đầu tiên = 0
        restoreFileIndex--;
        std::string restoreFileName = getStringAtIndex(list, restoreFileIndex);
        std::ifstream restoreFile("backup/" + restoreFileName);

        if (!restoreFile.is_open())
        {
            std::cout << "Failed to open restore file." << std::endl;
            return;
        }

        contacts.clear();
        std::string line;

        while (std::getline(restoreFile, line))
        {
            std::istringstream iss(line);
            std::string token;
            std::vector<std::string> contactData;

            while (std::getline(iss, token, '|'))
            {
                contactData.push_back(token);
            }

            if (contactData.size() == 5)
            {
                int id = std::stoi(contactData[0]);
                std::string name = contactData[1];
                std::string phone = contactData[2];
                std::string email = contactData[3];
                std::string address = contactData[4];

                Contact contact(id, name, phone, email, address);
                contacts.push_back(contact);
            }
        }

        restoreFile.close();
        updateContactsFile(contacts);
        std::cout << "Data has been restored from file " << restoreFileName << "." << std::endl;
    }
    else
    {
        std::cout << "Invalid choice." << std::endl;
    }
}