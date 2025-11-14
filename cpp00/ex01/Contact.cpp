#include "Contact.hpp"

Contact::Contact() {
}

Contact::Contact(const std::string &first, const std::string &last, 
                 const std::string &nick, const std::string &phone, 
                 const std::string &secret) {
    firstName = first;
    lastName = last;
    nickname = nick;
    phoneNumber = phone;
    darkestSecret = secret;
}

Contact::~Contact() {
}

std::string Contact::getFirstName() const {
    return firstName;
}

std::string Contact::getLastName() const {
    return lastName;
}

std::string Contact::getNickname() const {
    return nickname;
}

std::string Contact::getPhoneNumber() const {
    return phoneNumber;
}

std::string Contact::getDarkestSecret() const {
    return darkestSecret;
}

bool Contact::isEmpty() const {
    return firstName.empty();
}
