#include "iter.hpp"

class Door
{
	private:
		/* data */
	public:
		Door(/* args */);
		~Door();
};



void	print(int& a)
{
	std::cout<<a<<std::endl;
}
void	print2(std::string& a)
{
	std::cout<<a<<std::endl;
}

int main(void)
{
    int tab[] = {0, 1, 2, 3, 4};
    std::string tab2[] = {"%0", "$1", "#2", "@3", "!4"};
    iter(tab, 5, print);
    iter(tab2, 5, print2);

    return (0);
}