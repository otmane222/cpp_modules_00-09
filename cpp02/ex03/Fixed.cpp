#include "Fixed.hpp"


Fixed::Fixed()
{
	fixed_point_value = 0;
}

Fixed::Fixed(const int a)
{
	fixed_point_value = (a << fractional_bits);
}

Fixed::Fixed(const float f)
{
	fixed_point_value = roundf(f * (1 << fractional_bits));
}

int	Fixed::toInt() const
{
	return (fixed_point_value >> fractional_bits);
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(fixed_point_value) / (1 << fractional_bits));
}

Fixed::Fixed(const Fixed& copy)
{
	fixed_point_value = copy.fixed_point_value;
}

Fixed& Fixed::operator=(const Fixed& other)
{
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

bool	Fixed::operator >(const Fixed &other) const
{
	return (this->fixed_point_value > other.fixed_point_value);
}
bool	Fixed::operator <(const Fixed &other) const
{
	return (this->fixed_point_value < other.fixed_point_value);
}
bool	Fixed::operator <=(const Fixed &other) const
{
	return (this->fixed_point_value <= other.fixed_point_value);
}
bool	Fixed::operator >=(const Fixed &other) const
{
	return (this->fixed_point_value >= other.fixed_point_value);
}
bool	Fixed::operator ==(const Fixed &other) const
{
	return (this->fixed_point_value == other.fixed_point_value);
}
bool	Fixed::operator !=(const Fixed &other) const
{
	return (this->fixed_point_value != other.fixed_point_value);
}


Fixed Fixed::operator +(const Fixed &ref)
{
	Fixed a (this->toFloat() + ref.toFloat());
	return (a);
}
Fixed Fixed::operator -(const Fixed &ref)
{
	Fixed a (this->toFloat() - ref.toFloat());
	return (a);
}
Fixed Fixed::operator *(const Fixed &ref)
{
	Fixed a (this->toFloat() * ref.toFloat());
	return (a);
}
Fixed Fixed::operator /(const Fixed &ref)
{
	Fixed a (this->toFloat() / ref.toFloat());
	return (a);
}

Fixed Fixed::operator ++(int)
{
	this->fixed_point_value++;
	return (*this);
}

Fixed &Fixed::operator ++(void)
{
	++fixed_point_value;
	return (*this);
}

Fixed &Fixed::operator --(void)
{
	--fixed_point_value;
	return (*this);
}

Fixed Fixed::operator --(int)
{
	this->fixed_point_value++;
	return (*this);
}

Fixed& Fixed::min (Fixed& a, Fixed& b)
{
	if (a <= b)
		return (a);
	return (b);
}

const Fixed& Fixed::min (const Fixed &a, const Fixed &b)
{
	if (a <= b)
		return (a);
	return (b);
}

Fixed& Fixed::max (Fixed& a, Fixed& b)
{
	if (a <= b)
		return (b);
	return (a);
}

const Fixed& Fixed::max (Fixed const &a, Fixed const &b)
{
	if (a <= b)
		return (b);
	return (a);
}

Fixed::~Fixed()
{
	// std::cout<<"Destructor called"<<std::endl;
}