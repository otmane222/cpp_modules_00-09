#pragma once

#include <iostream>

template <typename T>
void	iter(T *a, int lenght, void (*f) (T& b))
{
	for (size_t i = 0; i < lenght; i++)
	{
		f(a[i]);
	}
}
