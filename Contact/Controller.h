#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
#include "Contact.h"
void readData(std::vector<Contact>& contacts);
void showAllContacts(const std::vector<Contact>& contacts);
void addNewContact(std::vector<Contact>& contacts);
void findContactsByName(const std::vector<Contact>& contacts);
void modifyContact(std::vector<Contact>& contacts);
void deleteContact(std::vector<Contact>& contacts);
void statitics(const std::vector<Contact>& contacts);
void backUpAndRestore(std::vector<Contact>& contacts);
void updateContactsFile(const std::vector<Contact>& contacts);
#endif