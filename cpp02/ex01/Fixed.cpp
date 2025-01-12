#include "Fixed.hpp"

Fixed::Fixed() : _fixedValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intValue) {
	std::cout << "Int constructor called" << std::endl;
	_fixedValue = intValue << _fractionalBits;
}

Fixed::Fixed(const float floatValue) {
	std::cout << "Float constructor called" << std::endl;
	_fixedValue = roundf(floatValue * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this ->_fixedValue = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	return _fixedValue;
}

void Fixed::setRawBits(int const raw) {
	_fixedValue = raw;
}

float Fixed::toFloat(void) const {
	return (float)_fixedValue / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
	return _fixedValue >> _fractionalBits;
}

std::ostream& operator <<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}