/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboulgh <oaboulgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 09:52:29 by oaboulgh          #+#    #+#             */
/*   Updated: 2023/11/23 10:43:42 by oaboulgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	std::string		name;
	(void)ac;

	if (ac == 1)
		return (1);
	name = av[1];
	try
	{
		ScalarConverter::convert(name);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}