#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
	int value;
	static const int fractional_bits = 8;

public:
	Fixed();
	Fixed(const int intValue);
	Fixed(const float floatValue);
	Fixed(const Fixed &other);

	// Operateur d'affectation
	Fixed &operator=(const Fixed &other);

	~Fixed();

	// Operateurs de comparaison
	bool operator>(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;

	// Operateurs arithmetiques
	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;

	// Operateurs d'incrementation et decrementation
	Fixed& operator++();
	Fixed& operator--();
	Fixed operator++(int);
	Fixed operator--(int);

	// Methodes pour min et max
	static Fixed& min(Fixed& a, Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed&b);
	static const Fixed& max(const Fixed& a, const Fixed&b);

	// Methodes d'acces
	int getRawBits(void) const;
	void setRawBits(int const raw);

	// Methodes pour convertir en d'autres types
	float toFloat() const;
	int toInt() const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif