#pragma once

#include <iostream>
#include <exception>

template <typename T>
class Array
{
	private:
		T		*a;
		unsigned int	lenght;
	public:
		Array() : a(new T[0]), lenght(0) {}
		Array(unsigned int n)
		{
			try
			{
				a = new T[n];
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << std::endl;
				exit (1);
			}
			lenght = n;
		}
		Array(const Array &c)
		{
			this->lenght = c.size();
			try
			{
				this->a = new T[lenght];
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << std::endl;
				exit (1);
			}
			for (size_t i = 0; i < lenght; i++)
			{
				this->a[i] = c.a[i];
			}
		}
		unsigned int	size() const
		{
			return (lenght);
		}
		Array & operator=(const Array &c)
		{
			if (this != &c)
			{
				delete [] this->a;
				this->lenght = c.size();
				try
				{
					this->a = new T[lenght];
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << std::endl;
					exit (1);
				}
				for (size_t i = 0; i < lenght; i++)
				{
					this->a[i] = c.a[i];
				}
			}
			return (*this);
		}
		T&	operator [](const unsigned int i) const
		{
			if (i > lenght)
				throw(std::exception());
			return (a[i]);
		}
		~Array()
		{
			delete[] a;
		}
};