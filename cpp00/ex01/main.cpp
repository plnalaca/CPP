#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main()
{
    PhoneBook phoneBook;
    std::string command;
    
    std::cout << "Welcome to PhoneBook!" << std::endl;
    std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
    
    while (true)
    {
        std::cout << "\nEnter command: ";
        std::getline(std::cin, command);
        
        if (std::cin.eof())
        {
            std::cout << "\nEOF detected. Exiting..." << std::endl;
            break;
        }
        
        if (command == "ADD")
        {
            phoneBook.addContact();
        }
        else if (command == "SEARCH")
        {
            phoneBook.searchContact();
        }
        else if (command == "EXIT")
        {
            std::cout << "Goodbye!" << std::endl;
            break;
        }
        else
        {
            std::cout << "Error: Invalid command! Use ADD, SEARCH, or EXIT." << std::endl;
        }
    }
    
    return 0;
}
