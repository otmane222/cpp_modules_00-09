#pragma once

#include <iostream>

class Base
{
	public:
		Base();
		virtual ~Base();
};

Base	*generate(void);
void	identify(Base* p);
void	identify(Base& p);
