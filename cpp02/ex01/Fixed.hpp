#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int	fixed_point_value;
		static const int	fractional_bits = 8;
	public:
		Fixed();
		Fixed(const int a);
		Fixed(const float f);
		Fixed(const Fixed& copy);
		float 	toFloat(void) const;
		int		toInt(void) const;
		Fixed& operator=(const Fixed& other);
		friend std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
		~Fixed();
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);