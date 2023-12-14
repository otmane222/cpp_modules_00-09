#pragma once

#include <iostream>
#include <vector>
#include <stack>
#include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack: public std::stack<T, Container>
{
	public:
		MutantStack();
		MutantStack(int arg);
		MutantStack(const MutantStack &c);
		MutantStack & operator=(const MutantStack &c);
		class iterator
		{
			typename Container::iterator current;
			public:
				iterator(typename Container::iterator it);
				iterator(const iterator &c);
				iterator & operator=(const iterator &c);

				T&	operator *() const
				{
					return (*current);
				}

				iterator operator ++ ()
				{
					++current;
					return (current);
				}
				
				iterator operator -- ()
				{
					--current;
					return (current);
				}

				bool operator != (const iterator& c) const
				{
					return (current != c.current);
				}

		};
		iterator begin()
		{
			return (this->c.begin());
		}
		
		iterator end()
		{
			return (this->c.end());
		}
};

#include "MutantStack.tpp"