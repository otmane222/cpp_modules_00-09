#include "easyfind.hpp"

template <typename T>
int	easyfind(T container, int val)
{
	typename T::iterator it = std::find(container.begin(), container.end(), val);
	if (it == container.end())
		throw (std::exception());
	return (*it);
}
