#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac == 1 || av[1][0] == '\0')
		return (std::cerr<<"Error no input"<<std::endl, 0);
	std::string input;

	input = av[1];
	RPN	a;

	Node* root = a.BuildDTree(input);
	std::cout<<a.executeTree(root)<<std::endl;
	a.deleteTree(root);
	return (0);
}
