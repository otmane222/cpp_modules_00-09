#include "Data.hpp"

Data::Data()
{
	b = 0;
}

Data::Data(const Data &c)
{
	(void)c;
}

Data & Data::operator=(const Data &c)
{
	(void)c;
	return(*this);
}


Data::~Data()
{
	
}