#include "Fixed.hpp"
#include <cmath>

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _fixedPointValue(0) {
}

Fixed::Fixed(const Fixed& other) : _fixedPointValue(other._fixedPointValue) {
}

Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other) {
		this->_fixedPointValue = other._fixedPointValue;
	}
	return *this;
}

Fixed::~Fixed() {
}

Fixed::Fixed(const int value) {
	this->_fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
	this->_fixedPointValue = roundf(value * (1 << _fractionalBits));
}


float Fixed::toFloat(void) const {
	return (float)this->_fixedPointValue / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
	return this->_fixedPointValue >> _fractionalBits;
}


int Fixed::getRawBits(void) const {
	return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
	this->_fixedPointValue = raw;
}

bool Fixed::operator>(const Fixed& other) const {
	return this->_fixedPointValue > other._fixedPointValue;
}

bool Fixed::operator<(const Fixed& other) const {
	return this->_fixedPointValue < other._fixedPointValue;
}

bool Fixed::operator>=(const Fixed& other) const {
	return this->_fixedPointValue >= other._fixedPointValue;
}

bool Fixed::operator<=(const Fixed& other) const {
	return this->_fixedPointValue <= other._fixedPointValue;
}

bool Fixed::operator==(const Fixed& other) const {
	return this->_fixedPointValue == other._fixedPointValue;
}

bool Fixed::operator!=(const Fixed& other) const {
	return this->_fixedPointValue != other._fixedPointValue;
}


Fixed Fixed::operator+(const Fixed& other) const {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
	if(other.toFloat() == 0) {
        std::cerr << "Error: Division by zero" << std::endl;
    }
    return Fixed(this->toFloat() / other.toFloat());
}


Fixed& Fixed::operator++() {
	this->_fixedPointValue++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	this->_fixedPointValue++;
	return temp;
}

Fixed& Fixed::operator--() {
	this->_fixedPointValue--;
	return *this;
}


Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	this->_fixedPointValue--;
	return temp;
}


Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
}


std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;
}
