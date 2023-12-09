#include "PmergeMe.hpp"



int main(int ac, char **av)
{
	PmergeMe			A;
	std::vector<size_t>	deppo;
	std::deque<size_t>	deque;
	double	time;

	if (ac == 1)
	{
		std::cerr<<"Error | usage:" << av[0] << " positive int numbers to sort" <<std::endl;
		return (1);
	}

	clock_t	start = clock();
	A.fordMergeSortInsertv(deppo, &av[1]);
	clock_t	end = clock();

	time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
	std::cout<<"Time to process a range of "<< deppo.size() <<" elements with std::vector "<< time<< " us"<<std::endl;
	start = clock();
	A.fordMergeSortInsertd(deque, &av[1]);
	end = clock();
	time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
	std::cout<<"Time to process a range of "<< deque.size() <<" elements with std::deque "<< time<< " us"<<std::endl;

}
