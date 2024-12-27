#include "PhoneBook.hpp"
#include <cctype>

PhoneBook::PhoneBook() : totalContacts(0) {}

bool isPrintableASCII(const std::string& input) {
	for (size_t i = 0; i < input.length(); ++i) {
		if (input[i] < 32 || input[i] > 126) {
			return false;
		}
	}
	return true;
}

bool isDigitsOnly(const std::string& input) {
	for (size_t i = 0; i < input.length(); i++) {
		if (!std::isdigit(input[i])) {
			return false;
		}
	}
	return true;
}

void PhoneBook::addContact() {
	Contact newContact;
	std::string input;

	std::cout << "Enter first name: ";
	std::getline(std::cin, input);
	while (input.empty() || !isPrintableASCII(input)) {
		std::cout << (input.empty() ? "Error: First name cannot be empty.\n" : "Error: Invalid characters in first name. Only printable ASCII characters are allowed.\n");
		std::cout << "Enter first name: ";
		std::getline(std::cin, input);
	}
	newContact.setFirstName(input);

	std::cout << "Enter last name: ";
	std::getline(std::cin, input);
	while (input.empty() || !isPrintableASCII(input)) {
		std::cout << (input.empty() ? "Error: Last name cannot be empty.\n" : "Error: Invalid characters in last name. Only printable ASCII characters are allowed.\n");
		std::cout << "Enter last name: ";
		std::getline(std::cin, input);
	}
	newContact.setLastName(input);

	std::cout << "Enter nickname: ";
	std::getline(std::cin, input);
	while (input.empty() || !isPrintableASCII(input)) {
		std::cout << (input.empty() ? "Error: Nickname cannot be empty.\n" : "Error: Invalid characters in nickname. Only printable ASCII characters are allowed.\n");
		std::cout << "Enter nickname: ";
		std::getline(std::cin, input);
	}
	newContact.setNickname(input);

	std::cout << "Enter phone number: ";
	std::getline(std::cin, input);
	while (input.empty() || !isDigitsOnly(input)) {
		if (input.empty()) {
			std::cout << "Error: Phone number cannot be empty.\n";
		} else if (!isDigitsOnly(input)) {
			std::cout << "Error: Phone number must contain only digits.\n";
		}
		std::cout << "Enter phone number: ";
		std::getline(std::cin, input);
	}
	newContact.setPhoneNumber(input);

	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, input);
	while (input.empty() || !isPrintableASCII(input)) {
		std::cout << (input.empty() ? "Error: Darkest secret cannot be empty.\n" : "Error: Invalid characters in darkest secret. Only printable ASCII characters are allowed.\n");
		std::cout << "Enter darkest secret: ";
		std::getline(std::cin, input);
	}
	newContact.setDarkestSecret(input);

	if (totalContacts < 8) {
		contacts[totalContacts] = newContact;
		++totalContacts;
	} else {
		contacts[0] = newContact;
	}
}

void PhoneBook::searchContacts() const {
	if (totalContacts == 0) {
		std::cout << "Phonebook is empty.\n";
		return;
	}

	displayContactSummary();

	std::string input;
	int index;
	std::cout << "Enter the index (1-8) of the contact to display: ";
	std::getline(std::cin, input);

	if (isValidIndex(input, index)) {
		displayFullContact(index - 1);
	} else {
		std::cout << "Invalid index!\n";
	}
}

void PhoneBook::displayContactSummary() const {
	std::cout	<< std::setw(10) << "Index" << "|"
				<< std::setw(10) << "First Name" << "|"
				<< std::setw(10) << "Last Name" << "|"
				<< std::setw(10) << "Nickname" << "\n";
	std::cout << "---------------------------------------------\n";

	for (int i = 0; i < totalContacts; ++i) {
		std::cout << std::setw(10) << (i + 1) << "|";
		std::string firstName = contacts[i].getFirstName();
		std::string lastName = contacts[i].getLastName();
		std::string nickname = contacts[i].getNickname();

		std::cout << std::setw(10) << (firstName.length() > 10 ? firstName.substr(0, 9) + "." : firstName) << "|";
		std::cout << std::setw(10) << (lastName.length() > 10 ? lastName.substr(0, 9) + "." : lastName) << "|";
		std::cout << std::setw(10) << (nickname.length() > 10 ? nickname.substr(0, 9) + "." : nickname) << "\n";
    }
}

void PhoneBook::displayFullContact(int index) const {
	const Contact& contact = contacts[index];
	std::cout << "First Name: " << contact.getFirstName() << "\n";
	std::cout << "Last Name: " << contact.getLastName() << "\n";
	std::cout << "Nickname: " << contact.getNickname() << "\n";
	std::cout << "Phone Number: " << contact.getPhoneNumber() << "\n";
	std::cout << "Darkest Secret: " << contact.getDarkestSecret() << "\n";
}

bool PhoneBook::isValidIndex(const std::string& input, int& index) const {
	if (input.length() == 1 && std::isdigit(input[0])) {
		index = input[0] - '0';
		return index >= 1 && index <= totalContacts;
	}
	return false;
}
