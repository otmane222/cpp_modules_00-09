#include "Point.hpp"

int main()
{
	Point	a(0, 0);
	Point	b(4, 0);
	Point	c(2, 4);
	Point	p(1, 1);

	if (bsp(a, b, c, p))
	{
		std::cout << "Point P is inside the triangle ABC." << std::endl;
	}
	else
	{
		std::cout << "Point P is outside the triangle ABC." << std::endl;
	}

    return 0;
}