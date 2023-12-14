#include "MutantStack.hpp"

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack()
{

}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(int arg)
{
	(void)arg;
}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack &c)
{
	*this = c;
}

template <typename T, typename Container>
MutantStack<T, Container> & MutantStack<T, Container>::operator=(const MutantStack &c)
{
	(void)c;
	return (*this);
}


template <typename T, typename Container>
MutantStack<T, Container>::iterator::iterator(typename Container::iterator it) : current(it) {}

template <typename T, typename Container>
MutantStack<T, Container>::iterator::iterator(const iterator &c)
{
	*this = c;
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator &  MutantStack<T, Container>::iterator::operator=(const iterator &c)
{
	current = c.current;
	return (*this);
}
