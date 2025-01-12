#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intValue) {
	std::cout << "Int constructor called" << std::endl;
	value = intValue << fractional_bits;
}

Fixed::Fixed(const float floatValue) {
	std::cout << "Float constructor called" << std::endl;
	value = roundf(floatValue * (1 << fractional_bits));
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->setRawBits(other.getRawBits());
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return this->value;
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float Fixed::toFloat() const {
	return (float)this->value / (1 << fractional_bits);
}

int Fixed::toInt(void) const
{
	return value >> fractional_bits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;
}

bool Fixed::operator>(const Fixed& other) const{
	return this->value > other.getRawBits();
}

bool Fixed::operator<(const Fixed& other) const{
	return this->value < other.getRawBits();
}

bool Fixed::operator>=(const Fixed& other) const{
	return this->value >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed& other) const{
	return this->value <= other.getRawBits();
}

bool Fixed::operator==(const Fixed& other) const{
	return this->value == other.getRawBits();
}

bool Fixed::operator!=(const Fixed& other) const{
	return this->value != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed& other) const{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const{
	if (other.value == 0) {
		std::cerr << "Division by zero" << std::endl;
		return Fixed();
	}
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++() {
	this->value += 1;
	return *this;
}

Fixed& Fixed::operator--() {
	this->value -= 1;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	this->value += 1;
	return temp;
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	this->value -= 1;
	return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	if (a.getRawBits() < b.getRawBits())
		return a;
	else
		return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	if (a.getRawBits() > b.getRawBits())
		return a;
	else
		return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	if (a.getRawBits() < b.getRawBits())
		return a;
	else
		return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	if (a.getRawBits() > b.getRawBits())
		return a;
	else
		return b;
}