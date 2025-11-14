#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

PhoneBook::PhoneBook() : contactCount(0), oldestIndex(0){
}

PhoneBook::~PhoneBook() {
}

std::string PhoneBook::truncate(const std::string &str) const
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}


void PhoneBook::addContact()
{
    std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
    
    std::cout << "Enter first name: ";
    std::getline(std::cin, firstName);
    if (firstName.empty())
    {
        std::cout << "Error: Field cannot be empty!" << std::endl;
        return;
    }
    
    std::cout << "Enter last name: ";
    std::getline(std::cin, lastName);
    if (lastName.empty())
    {
        std::cout << "Error: Field cannot be empty!" << std::endl;
        return;
    }
    
    std::cout << "Enter nickname: ";
    std::getline(std::cin, nickname);
    if (nickname.empty())
    {
        std::cout << "Error: Field cannot be empty!" << std::endl;
        return;
    }
    
    std::cout << "Enter phone number: ";
    std::getline(std::cin, phoneNumber);
    if (phoneNumber.empty())
    {
        std::cout << "Error: Field cannot be empty!" << std::endl;
        return;
    }
    
    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, darkestSecret);
    if (darkestSecret.empty())
    {
        std::cout << "Error: Field cannot be empty!" << std::endl;
        return;
    }
    
    Contact newContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
    contacts[oldestIndex] = newContact;
    oldestIndex = (oldestIndex + 1) % 8;
    if (contactCount < 8)
        contactCount++;
    
    std::cout << "Contact added successfully!" << std::endl;
}


void PhoneBook::displayContactList() const
{
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nickname" << std::endl;
    std::cout << std::string(44, '-') << std::endl;
    
    for (int i = 0; i < contactCount; i++) {
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << truncate(contacts[i].getFirstName()) << "|";
        std::cout << std::setw(10) << truncate(contacts[i].getLastName()) << "|";
        std::cout << std::setw(10) << truncate(contacts[i].getNickname()) << std::endl;
    }
}

void PhoneBook::displayContact(int index) const
{
    std::cout << "First name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
    std::cout << "Phone number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << contacts[index].getDarkestSecret() << std::endl;
}

void PhoneBook::searchContact() const
{
    if (contactCount == 0) {
        std::cout << "PhoneBook is empty!" << std::endl;
        return;
    }
    
    displayContactList();
    
    std::cout << "Enter index to display: ";
    std::string input;
    std::getline(std::cin, input);

    std::stringstream ss(input);
    int index;
    if (!(ss >> index) || index < 0 || index >= contactCount) {
        std::cout << "Error: Invalid index!" << std::endl;
        return;
    }
    
    displayContact(index);
}
