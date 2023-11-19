#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::Base()
{
	
}

Base::~Base()
{
	
}


Base	*generate(void)
{
	long long b = (time(nullptr) % 3);

	if (b == 0)
		return (new A());
	else if (b == 1)
		return (new B());
	else
		return (new C());
}

void	identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout<<"type is: A"<<std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout<<"type is: B"<<std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout<<"type is: C"<<std::endl;
}

void	identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		std::cout<<"type is: A"<<std::endl;
		(void)a;
		return ;
	}
	catch(const std::exception& e)
	{
		try
		{
			B &b = dynamic_cast<B &>(p);
			std::cout<<"type is: B"<<std::endl;
			(void)b;
			return ;
		}
		catch(const std::exception& e)
		{
			try
			{
				C &c = dynamic_cast<C &>(p);
				std::cout<<"type is: C"<<std::endl;
				(void)c;
				return ;
			}
			catch(const std::exception& e)
			{
				
			}
		}
		
	}
	
}
