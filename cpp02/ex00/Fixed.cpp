#include "Fixed.hpp"

int Fixed::fractional_bits = 8;

Fixed::Fixed()
{
	fixed_point_value = 0;
	std::cout<<"Default constructor called"<<std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
	fixed_point_value = copy.fixed_point_value;
	std::cout<<"Copy constructor called"<<std::endl;
}

Fixed &Fixed::operator=(const Fixed& src)
{
	std::cout<<"Copy assignment operator called"<<std::endl;
	if (this != &src)
	{
		fixed_point_value = getRawBits();
	}
	return (*this);
}

int Fixed::getRawBits() const
{
	std::cout<<"getRawBits member function called"<<std::endl;
	return (fixed_point_value);
}

void	Fixed::setRawBits(int const num)
{
	fixed_point_value = num;
}

Fixed::~Fixed()
{
	std::cout<<"Destructor called"<<std::endl;
}