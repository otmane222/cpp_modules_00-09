#pragma once

#include <iostream>
#include <cmath>
#include <iomanip>

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
		Fixed& operator=(Fixed const &other);
		bool	operator >(Fixed const &other) const;
		bool	operator <(Fixed const &other) const;
		bool	operator <=(Fixed const &other) const;
		bool	operator >=(Fixed const &other) const;
		bool	operator ==(Fixed const &other) const;
		bool	operator !=(Fixed const &other) const;

		Fixed operator +(const Fixed &ref);
		Fixed operator -(const Fixed &ref);
		Fixed operator *(const Fixed &ref);
		Fixed operator /(const Fixed &ref);

		Fixed operator ++(int);
		Fixed &operator ++(void);
		Fixed &operator --(void);
		Fixed operator --(int);

		static Fixed& min (Fixed& a, Fixed& b);
		static const Fixed& min (Fixed const &a, Fixed const &b);
		static Fixed& max (Fixed& a, Fixed& b);
		static const Fixed& max (Fixed const &a, Fixed const &b);

		friend std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
		~Fixed();
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);