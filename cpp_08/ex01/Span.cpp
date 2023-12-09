#include "Span.hpp"

Span::Span()
{

}

Span::Span(unsigned int N)
{
	this->N = N;
	arr.reserve(N);
}

Span::Span(const Span &c)
{
	*this = c;
}

Span & Span::operator=(const Span &c)
{
	if(this != &c)
	{
		this->N = c.N;
		arr = c.arr;
	}
	return(*this);
}

void	Span::addNumber(int a)
{
	if (arr.size() < N)
		arr.push_back(a);
	else
		throw(std::exception());
}

int	Span::shortestSpan(void)
{
	int min = INT_MAX;
	if (arr.size() < 2)
		throw(std::exception());
	std::vector<int> a = arr;
	std::sort(a.begin(), a.end());
	for (size_t i = 0; i < arr.size() - 1; i++)
	{
		if ((a[i + 1] - a[i]) < min)
			min = a[i + 1] - a[i];
	}
	return (min);
}

int	Span::longestSpan(void)
{
	if (arr.size() < 2)
		throw(std::exception());
	std::vector<int> a = arr;
	std::sort(a.begin(), a.end());
	return (a[N - 1] - a[0]);

}

void	Span::addNums(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	for (; begin != end; begin++)
	{
		addNumber(*begin);
	}
}

Span::~Span()
{

}
