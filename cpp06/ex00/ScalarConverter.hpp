#pragma once

#include <iostream>
#include <string>
#include <climits>
#include <cfloat>
#include <stdlib.h>

class ScalarConverter
{
	private:
	public:
		ScalarConverter();
		ScalarConverter(int arg);
		ScalarConverter(const ScalarConverter &c);
		static void convert(std::string data);
		ScalarConverter & operator=(const ScalarConverter &c);
		~ScalarConverter();
};
