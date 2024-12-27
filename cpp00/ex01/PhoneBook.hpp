#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>

class PhoneBook {
public:
	PhoneBook();

	void addContact();
	void searchContacts() const;

private:
	Contact contacts[8];
	int totalContacts;

	void displayContactSummary() const;
	void displayFullContact(int index) const;
	bool isValidIndex(const std::string& input, int& index) const;
};

#endif
