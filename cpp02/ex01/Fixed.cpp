#include "Fixed.hpp"


Fixed::Fixed()
{
	std::cout<<"Default constructor called"<<std::endl;
	fixed_point_value = 0;
}

Fixed::Fixed(const int a)
{
	std::cout<<"Int constructor called"<<std::endl;
	fixed_point_value = (a << fractional_bits);
}

Fixed::Fixed(const float f)
{
	std::cout<<"Float constructor called"<<std::endl;
	fixed_point_value = roundf(f * (1 << fractional_bits));
}

int	Fixed::toInt() const
{
	return (fixed_point_value >> fractional_bits);
}
#include <iomanip>

float Fixed::toFloat(void) const
{
	return (static_cast<float>(fixed_point_value) / (1 << fractional_bits));
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout<<"Copy constructor called"<<std::endl;
	fixed_point_value = copy.fixed_point_value;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout<<"Copy assignment operator called"<<std::endl;
	if (this != &other)
	{
		fixed_point_value = other.fixed_point_value;
	}
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

Fixed::~Fixed()
{
	std::cout<<"Destructor called"<<std::endl;
}