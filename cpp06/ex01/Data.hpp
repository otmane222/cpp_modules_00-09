#pragma once

#include <iostream>

class Data
{
	public:
		std::string s1;
		std::string s2;
		int			b;
		Data();
		Data(const Data &c);
		Data & operator=(const Data &c);
		~Data();
};
