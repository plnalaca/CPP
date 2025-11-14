#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
    Contact contacts[8];        // 8 contact'lık sabit array (dinamik allocation yasak)
    int contactCount;           // Şu anki contact sayısı (max 8)
    int oldestIndex;            // 9. contact eklendiğinde hangi index'i değiştirecek
    
    std::string truncate(const std::string &str) const;
    void displayContactList() const;
    void displayContact(int index) const;

public:
    PhoneBook();
    ~PhoneBook();
    
    void addContact();
    void searchContact() const;
};

#endif
