#pragma once

# include <iostream>
# include <vector>
# include <deque>
# include <string>
# include <limits>
# include <algorithm>
# include <ctime>
# include <iomanip>
# include <chrono>

class PmergeMe
{
	private:
	public:
		PmergeMe();
		void					fordMergeSortInsertv(std::vector<size_t>& deppo, char **av);
		
		void					fordMergeSortInsertd(std::deque<size_t>& deppo, char **av);
		
		PmergeMe(const PmergeMe &c);
		PmergeMe & operator=(const PmergeMe &c);
};
