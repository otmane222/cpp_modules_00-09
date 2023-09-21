#include <iostream>

int main(int ac, char **av)
{
	int 	i = 1;
	int 	j = 0;
	char	c;

	if (ac == 1)
		return (0);
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			c = av[i][j];
			if (c >= 'a' && c <= 'z')
				c -= 32;
			std::cout<<c;
			j++;
		}
		i++;
		std::cout<<" ";
	}
	std::cout<<"\n";
}