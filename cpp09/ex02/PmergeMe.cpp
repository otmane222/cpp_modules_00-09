#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	
}

PmergeMe::~PmergeMe()
{
	
}

PmergeMe::PmergeMe(const PmergeMe &c)
{
	(void)c;
}

PmergeMe & PmergeMe::operator=(const PmergeMe &c)
{
	(void)c;
	return(*this);
}

void	checkDav(char **av)
{
	for (size_t i = 0; av[i]; i++)
	{
		if (std::strlen(av[i]) > 10 || av[i][0] == '\0')
		{
			std::cerr<<"Error"<<std::endl;
			exit (1);
		}
		for (size_t j = 0; av[i][j]; j++)
		{
			if (!std::isdigit(av[i][j]))
			{
				std::cerr<<"Error"<<std::endl;
				exit (1);
			}
		}
	}
	
}

template<typename T>
int	exist(T& mainChain, size_t value)
{
	typename T::iterator	it;

	it = mainChain.begin();
	for (; it != mainChain.end(); it++)
	{
		if (*it == value)
			return (1);
	}
	return (0);
}


template <typename T>
T fullData(char **av)
{
	T			deppo;
	long		val;
	char		*error;

	checkDav(av);
	for (size_t i = 0; av[i]; i++)
	{
		val = std::strtol(av[i], &error, 10);
		if (val > 2147483647)
		{
			std::cerr<<"Error"<<std::endl;
			exit (1);
		}
		if (exist(deppo, val))
		{
			std::cout<<"Error duplicated numbers"<<std::endl;
			exit(1);
		}
		deppo.push_back(val);
	}
	return (deppo);
}

template <typename T>
void	binarySearchSort(T& mainChain, size_t value, size_t index, size_t m)
{
	typename T::iterator	it;

	if (index > mainChain.size())
		index = mainChain.size();
	if (exist(mainChain, value))
		return ;
	it = mainChain.begin();


	if (m == 0)
		m = 1;
	if (value < mainChain[index])
	{
		if (index > 0)
		{
			if (value > mainChain[index - 1])
			{
				mainChain.insert(it + index, value);
				return ;
			}
		}
		if (index == 0)
		{
			mainChain.insert(it, value);
			return ;
		}
		binarySearchSort(mainChain, value, index - m, m / 2);
	}
	else if (value > mainChain[index])
	{
		if (index == mainChain.size())
		{
			mainChain.insert(it + index, value);
			return ;
		}
		if (index < mainChain.size())
		{
			if (value < mainChain[index + 1])
			{
				mainChain.insert(it + index + 1, value);
				return ;
			}
		}
		binarySearchSort(mainChain, value, index + m, m / 2);
	}
}

template<typename T>
void	merge(T& deppo, size_t l, size_t m, size_t r)
{
	size_t	il, ir, k;

	il = l;
	ir = m + 1;
	k = l;

	T	tmp;

	while (il <= m && ir <= r)
	{
		if (deppo[il] <= deppo[ir])
		{
			tmp.push_back(deppo[il]);
			il++;
		}
		else
		{
			tmp.push_back(deppo[ir]);
			ir++;
		}
		k++;
	}
	while (il <= m)
	{
		tmp.push_back(deppo[il]);
		il++;
		k++;
	}
	while (ir <= r)
	{
		tmp.push_back(deppo[ir]);
		ir++;
		k++;
	}
	size_t f = 0;
	for (size_t i = l; i <= r; i++)
	{
		deppo[i] = tmp[f++];
	}
	

}

template<typename T>
void	mergeSort(T& deppo, size_t l, size_t r)
{
	if (l < r)
	{
		size_t	m = (r + l) / 2;
		mergeSort(deppo, l, m);
		mergeSort(deppo, m + 1, r);
		merge(deppo, l, m, r);
	}
}




void PmergeMe::fordMergeSortInsertd (std::deque<size_t>& deppo, char **av)
{
	deppo = fullData<std::deque<size_t> >(av);

	size_t	n = deppo.size();
	if (n <= 1)
		return ;
	
	std::deque<std::pair<size_t, size_t> >	vp;
	
	for (size_t i = 0; i < deppo.size(); i += 2) {
		if (i + 1 <= deppo.size()) {
			if (deppo[i] < deppo[i + 1]) {
				std::swap(deppo[i + 1], deppo[i]);
			}
			vp.push_back(std::make_pair(deppo[i], deppo[i + 1]));
		}
	}

	std::deque<size_t> mainChain, pendElements;

    mergeSort(vp, 0 , (deppo.size() / 2) - 1);  // Recursively sort the main chain

	std::deque<std::pair<size_t, size_t> >::iterator ito = vp.begin();
	for (; ito != vp.end(); ito++)
	{
		mainChain.push_back(ito->first);
		pendElements.push_back(ito->second);
	}
	if(deppo.size() % 2)
	{
		mainChain.pop_back();
		pendElements.pop_back();
	}

	std::deque<size_t>::iterator ity = pendElements.begin();
	size_t	m;

	for (size_t i = 0; ity != pendElements.end(); ity++, i++) // insert each element of pendelement into main chain using binary search
	{
		m = mainChain.size();
		binarySearchSort(mainChain, pendElements[i], m / 2, m / 4);
	}
	if (deppo.size() % 2)
	{
		m = mainChain.size();
		binarySearchSort(mainChain, deppo[deppo.size() - 1], m / 2, m / 4);
	}

	std::deque<size_t>::iterator it;
	it = mainChain.begin();
	for (size_t i = 0; it != mainChain.end(); it++, i++)
		deppo[i] = mainChain[i];

	mainChain.clear();
	pendElements.clear();
	vp.clear();
}

void PmergeMe::fordMergeSortInsertv (std::vector<size_t>& deppo, char **av)
{
	deppo = fullData<std::vector<size_t> >(av);
	std::vector<size_t>::iterator iterr = deppo.begin();
	std::cout<<"Before:	"<<std::endl;
	for (; iterr != deppo.end(); iterr++)
		std::cout<<*iterr<<" ";
	std::cout<<std::endl;

	size_t	n = deppo.size();
	if (n <= 1)
		return ;
	
	std::vector<std::pair<size_t, size_t> >	vp;
	
	for (size_t i = 0; i < deppo.size(); i += 2) {
		if (i + 1 <= deppo.size()) {
			if (deppo[i] < deppo[i + 1]) {
				std::swap(deppo[i + 1], deppo[i]);
			}
			vp.push_back(std::make_pair(deppo[i], deppo[i + 1]));
		}
	}

	std::vector<size_t> mainChain, pendElements;

    mergeSort(vp, 0 , (deppo.size() / 2) - 1);  // Recursively sort the main chain

	std::vector<std::pair<size_t, size_t> >::iterator ito = vp.begin();
	for (; ito != vp.end(); ito++)
	{
		mainChain.push_back(ito->first);
		pendElements.push_back(ito->second);
	}
	if(deppo.size() % 2)
	{
		mainChain.pop_back();
		pendElements.pop_back();
	}

	std::vector<size_t>::iterator ity = pendElements.begin();
	size_t	m;

	std::vector<size_t>::iterator it;
	for (size_t i = 0; ity != pendElements.end(); ity++, i++) // insert each element of pendelement into main chain using binary search
	{
		m = mainChain.size();
		binarySearchSort(mainChain, pendElements[i], m / 2, m / 4);
	}
	if (deppo.size() % 2)
	{
		m = mainChain.size();
		binarySearchSort(mainChain, deppo[deppo.size() - 1], m / 2, m / 4);
	}

	it = mainChain.begin();
	for (size_t i = 0; it != mainChain.end(); it++, i++)
		deppo[i] = mainChain[i];

	mainChain.clear();
	pendElements.clear();
	vp.clear();

	iterr = deppo.begin();
	std::cout<<"After:	"<<std::endl;
	for (; iterr != deppo.end(); iterr++)
		std::cout<<*iterr<<" ";
	std::cout<<std::endl<<std::endl;
}
