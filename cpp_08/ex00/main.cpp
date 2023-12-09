#include "easyfind.hpp"

int main()
{
	try
	{
		std::vector<int> numbers;
		numbers.push_back(1);
		numbers.push_back(2);
		numbers.push_back(3);
		numbers.push_back(11);
		numbers.push_back(5);
		std::cout<<easyfind(numbers, 11)<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}
