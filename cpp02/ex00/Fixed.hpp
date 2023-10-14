#pragma once

#include <iostream>

class Fixed {
	private:
		int	fixed_point_value;
		static int	 fractional_bits;
	public:
		Fixed();
		Fixed(const Fixed& copy);
		Fixed &operator = (const Fixed& src);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

};