#pragma once

#include <iostream>
#include <vector>
#include <exception>
#include <climits>


class Span
{
	private:
		unsigned int N;
		std::vector <int> arr;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &c);
		Span & operator=(const Span &c);
		~Span();

		void	addNumber(int a);
		int	shortestSpan(void);
		int	longestSpan(void);

		void	addNums(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};
