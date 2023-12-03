#include "RPN.hpp"

void	lk(void)
{
	system("leaks RPN");
}

int main(int ac, char **av)
{
	atexit(lk);
	if (ac == 1)
		return (std::cerr<<"Error no input"<<std::endl, 0);
	std::string input;

	input = av[1];
	RPN	a;

	Node* root = a.BuildDTree(input);
	(void)root;
	std::cout<<a.executeTree(root)<<std::endl;
	a.deleteTree(root);
	return (0);
}
